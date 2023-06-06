// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/SuperMap_ProceduralMeshComponent.h"
#include "PrimitiveViewRelevance.h"
#include "PrimitiveSceneProxy.h"
#include "PhysicsEngine/BodySetup.h"
#include "Containers/ResourceArray.h"
#include "LocalVertexFactory.h"
#include "EngineGlobals.h"
#include "VertexFactory.h"
#include "MaterialShared.h"
#include "Materials/Material.h"
#include "Engine/Engine.h"
#include "SceneManagement.h"
#include "RayTracingDefinitions.h"
#include "RayTracingInstance.h"
#include "StaticMeshResources.h"
#include "Core/ROCacheManager.h"
#include "Core/RealspaceDLL.h"
#include "Base3D/CommonDefine.h"
using namespace SuperMapSDK;

//DECLARE_CYCLE_STAT(TEXT("Create My ProcMesh Proxy"), STAT_MyProcMesh_CreateSceneProxy, STATGROUP_MyProceduralMesh);
//DECLARE_CYCLE_STAT(TEXT("Create My Mesh Section"), STAT_MyProcMesh_CreateMeshSection, STATGROUP_MyProceduralMesh);
//DECLARE_CYCLE_STAT(TEXT("My UpdateSection GT"), STAT_MyProcMesh_UpdateSectionGT, STATGROUP_MyProceduralMesh);
//DECLARE_CYCLE_STAT(TEXT("My UpdateSection RT"), STAT_MyProcMesh_UpdateSectionRT, STATGROUP_MyProceduralMesh);
//DECLARE_CYCLE_STAT(TEXT("My Get ProcMesh Elements"), STAT_MyProcMesh_GetMeshElements, STATGROUP_MyProceduralMesh);
//DECLARE_CYCLE_STAT(TEXT("My Update Collision"), STAT_MyProcMesh_UpdateCollision, STATGROUP_MyProceduralMesh);

//DEFINE_LOG_CATEGORY_STATIC(LogProceduralComponent, Log, All);

/** Class representing a single section of the proc mesh */
class FMyProcMeshProxySection
{
public:
	/** Material applied to this section */
	UMaterialInterface* Material;
	/** Vertex buffer for this section */
	FStaticMeshVertexBuffers VertexBuffers;
	/** Index buffer for this section */
	FDynamicMeshIndexBuffer32 IndexBuffer;
	/** Vertex factory for this section */
	FLocalVertexFactory VertexFactory;
	/** Whether this section is currently visible */
	Gamebool bSectionVisible;

#if RHI_RAYTRACING
	FRayTracingGeometry RayTracingGeometry;
#endif

	FMyProcMeshProxySection(ERHIFeatureLevel::Type InFeatureLevel)
		: Material(NULL)
		, VertexFactory(InFeatureLevel, "FMyProcMeshProxySection")
		, bSectionVisible(true)
	{}

	Gamevoid ReleaseVertexFactory()
	{
		VertexFactory.ReleaseResource();
	}
};

/**
 *	Struct used to send update to mesh data
 *	Arrays may be empty, in which case no update is performed.
 */
class FProcMeshSectionUpdateData
{
public:
	/** Section to update */
	Gameint TargetSection;
	/** New vertex information */
	TArray<FProcMeshVertex> NewVertexBuffer;
};

static Gamevoid ConvertProcMeshToDynMeshVertex(FDynamicMeshVertex& Vert, const FProcMeshVertex& ProcVert)
{
	Vert.Position = GameVector3(ProcVert.Position);
	Vert.Color = ProcVert.Color;
	Vert.TextureCoordinate[0] = GameVector2(ProcVert.UV0);
	Vert.TextureCoordinate[1] = GameVector2(ProcVert.UV1);
	Vert.TextureCoordinate[2] = GameVector2(ProcVert.UV2);
	Vert.TextureCoordinate[3] = GameVector2(ProcVert.UV3);
	Vert.TangentX = ProcVert.Tangent.TangentX;
	Vert.TangentZ = ProcVert.Normal;
	Vert.TangentZ.Vector.W = ProcVert.Tangent.bFlipTangentY ? -127 : 127;
}

/** Procedural mesh scene proxy */
class FMyProceduralMeshSceneProxy final : public FPrimitiveSceneProxy
{
public:
	SIZE_T GetTypeHash() const override
	{
		static size_t UniquePointer;
		return reinterpret_cast<size_t>(&UniquePointer);
	}

	FMyProceduralMeshSceneProxy(USuperMap_ProceduralMeshComponent* Component)
		: FPrimitiveSceneProxy(Component)
		, BodySetup(Component->GetBodySetup())
		, MaterialRelevance(Component->GetMaterialRelevance(GetScene().GetFeatureLevel()))
	{

		m_bVisible = Component->m_bVisible;
		m_bVisibleLayer = Component->m_bVisibleLayer;
		switch (Component->m_nDrawType)
		{
		case 0:
			m_eDrawType = PT_TriangleList;
			break;
		case 1:
			m_eDrawType = PT_QuadList;
			break;
		case 2:
			m_eDrawType = PT_LineList;
			break;
		case 4:
			m_eDrawType = PT_PointList;
			break;
		case 3:
		default:
			m_eDrawType = PT_TriangleList;
			break;
		}

		// Copy each section
		const Gameint NumSections = Component->GetNumSections();
		Sections.AddZeroed(NumSections);
		for (Gameint SectionIdx = 0; SectionIdx < NumSections; SectionIdx++)
		{
			FProcMeshSection& SrcSection = *(Component->GetProcMeshSection(SectionIdx));
			if (SrcSection.ProcIndexBuffer.Num() > 0 && SrcSection.ProcVertexBuffer.Num() > 0)
			{
				FMyProcMeshProxySection* NewSection = new FMyProcMeshProxySection(GetScene().GetFeatureLevel());

				// Copy data from vertex buffer
				const Gameint NumVerts = SrcSection.ProcVertexBuffer.Num();

				// Allocate verts

				TArray<FDynamicMeshVertex> Vertices;
				Vertices.SetNumUninitialized(NumVerts);
				// Copy verts
				for (Gameint VertIdx = 0; VertIdx < NumVerts; VertIdx++)
				{
					const FProcMeshVertex& ProcVert = SrcSection.ProcVertexBuffer[VertIdx];
					FDynamicMeshVertex& Vert = Vertices[VertIdx];
					ConvertProcMeshToDynMeshVertex(Vert, ProcVert);
				}

				FLocalVertexFactory* pVertexFactory = 0;
				pVertexFactory = &NewSection->VertexFactory;

				// Copy index buffer
				NewSection->IndexBuffer.Indices = SrcSection.ProcIndexBuffer;
				NewSection->VertexBuffers.StaticMeshVertexBuffer.SetUseFullPrecisionUVs(true);
				NewSection->VertexBuffers.InitFromDynamicVertex(pVertexFactory, Vertices, 4);

				// Enqueue initialization of render resource
				BeginInitResource(&NewSection->VertexBuffers.PositionVertexBuffer);
				BeginInitResource(&NewSection->VertexBuffers.StaticMeshVertexBuffer);
				BeginInitResource(&NewSection->VertexBuffers.ColorVertexBuffer);
				BeginInitResource(&NewSection->IndexBuffer);
				BeginInitResource(pVertexFactory);
				

				// Grab material
				NewSection->Material = Component->GetMaterial(SectionIdx);
				if (NewSection->Material == NULL)
				{
					NewSection->Material = UMaterial::GetDefaultMaterial(MD_Surface);
				}

				// Copy visibility info
				NewSection->bSectionVisible = SrcSection.bSectionVisible;

				// Save ref to new section
				Sections[SectionIdx] = NewSection;

#if RHI_RAYTRACING
				if (IsRayTracingEnabled() && m_eDrawType == PT_TriangleList)
				{
					ENQUEUE_RENDER_COMMAND(InitProceduralMeshRayTracingGeometry)(
						[this, NewSection/*, VertexBufferRHI, IndexBufferRHI, VertexBufferStride, TrianglesCount, RenderSections*/](FRHICommandListImmediate& RHICmdList)
					{
						FRayTracingGeometryInitializer Initializer;
						Initializer.IndexBuffer = nullptr;
						Initializer.TotalPrimitiveCount = 0;
						Initializer.GeometryType = RTGT_Triangles;
						Initializer.bFastBuild = true;
						Initializer.bAllowUpdate = false;

						NewSection->RayTracingGeometry.SetInitializer(Initializer);
						NewSection->RayTracingGeometry.InitResource();

						NewSection->RayTracingGeometry.Initializer.IndexBuffer = NewSection->IndexBuffer.IndexBufferRHI;
						NewSection->RayTracingGeometry.Initializer.TotalPrimitiveCount = NewSection->IndexBuffer.Indices.Num() / 3;

						FRayTracingGeometrySegment Segment;
						Segment.VertexBuffer = NewSection->VertexBuffers.PositionVertexBuffer.VertexBufferRHI;
						Segment.NumPrimitives = NewSection->RayTracingGeometry.Initializer.TotalPrimitiveCount;
#if SM_FOR_UE_FIVE
						Segment.MaxVertices = NewSection->VertexBuffers.PositionVertexBuffer.GetNumVertices();
#endif
						NewSection->RayTracingGeometry.Initializer.Segments.Add(Segment);

						//#dxr_todo: add support for segments?

						NewSection->RayTracingGeometry.UpdateRHI();
					});
				}
#endif
			}
		}
	}

	virtual ~FMyProceduralMeshSceneProxy()
	{
		for (FMyProcMeshProxySection* Section : Sections)
		{
			if (Section != nullptr)
			{
				Section->VertexBuffers.PositionVertexBuffer.ReleaseResource();
				Section->VertexBuffers.StaticMeshVertexBuffer.ReleaseResource();
				Section->VertexBuffers.ColorVertexBuffer.ReleaseResource();
				Section->IndexBuffer.ReleaseResource();
				Section->ReleaseVertexFactory();

#if RHI_RAYTRACING
				if (IsRayTracingEnabled() && m_eDrawType == PT_TriangleList)
				{
					Section->RayTracingGeometry.ReleaseResource();
				}
#endif

				delete Section;
			}
		}
	}

	Gamevoid SetVisibleLayer_RenderThread(Gamebool visible)
	{
		check(IsInRenderingThread());

		m_bVisibleLayer = visible;

		for (Gameint i = 0; i < Sections.Num(); i++)
		{
			Sections[i]->bSectionVisible = visible;
		}
	}

	Gamevoid SetVisible_RenderThread(Gamebool visible)
	{
		check(IsInRenderingThread());

		m_bVisible = visible;

	}

	/** Called on render thread to assign new dynamic data */
	Gamevoid UpdateSection_RenderThread(FProcMeshSectionUpdateData* SectionData)
	{
		//SCOPE_CYCLE_COUNTER(STAT_MyProcMesh_UpdateSectionRT);

		check(IsInRenderingThread());

		// Check we have data 
		if (SectionData != nullptr)
		{
			// Check it references a valid section
			if (SectionData->TargetSection < Sections.Num() &&
				Sections[SectionData->TargetSection] != nullptr)
			{
				FMyProcMeshProxySection* Section = Sections[SectionData->TargetSection];

				// Lock vertex buffer
				const Gameint NumVerts = SectionData->NewVertexBuffer.Num();

				// Iterate through vertex data, copying in new info
				for (Gameint i = 0; i < NumVerts; i++)
				{
					const FProcMeshVertex& ProcVert = SectionData->NewVertexBuffer[i];
					FDynamicMeshVertex Vertex;
					ConvertProcMeshToDynMeshVertex(Vertex, ProcVert);

					Section->VertexBuffers.PositionVertexBuffer.VertexPosition(i) = Vertex.Position;
					Section->VertexBuffers.StaticMeshVertexBuffer.SetVertexTangents(i, GameVector3(Vertex.TangentX.ToFVector()), Vertex.GetTangentY(), GameVector3(Vertex.TangentZ.ToFVector()));
					Section->VertexBuffers.StaticMeshVertexBuffer.SetVertexUV(i, 0, Vertex.TextureCoordinate[0]);
					Section->VertexBuffers.StaticMeshVertexBuffer.SetVertexUV(i, 1, Vertex.TextureCoordinate[1]);
					Section->VertexBuffers.StaticMeshVertexBuffer.SetVertexUV(i, 2, Vertex.TextureCoordinate[2]);
					Section->VertexBuffers.StaticMeshVertexBuffer.SetVertexUV(i, 3, Vertex.TextureCoordinate[3]);
					Section->VertexBuffers.ColorVertexBuffer.VertexColor(i) = Vertex.Color;
				}

				{
					auto& VertexBuffer = Section->VertexBuffers.PositionVertexBuffer;
					Gamevoid* VertexBufferData = RHILockVertexBuffer(VertexBuffer.VertexBufferRHI, 0, VertexBuffer.GetNumVertices() * VertexBuffer.GetStride(), RLM_WriteOnly);
					FMemory::Memcpy(VertexBufferData, VertexBuffer.GetVertexData(), VertexBuffer.GetNumVertices() * VertexBuffer.GetStride());
					RHIUnlockVertexBuffer(VertexBuffer.VertexBufferRHI);
				}

				{
					auto& VertexBuffer = Section->VertexBuffers.ColorVertexBuffer;
					Gamevoid* VertexBufferData = RHILockVertexBuffer(VertexBuffer.VertexBufferRHI, 0, VertexBuffer.GetNumVertices() * VertexBuffer.GetStride(), RLM_WriteOnly);
					FMemory::Memcpy(VertexBufferData, VertexBuffer.GetVertexData(), VertexBuffer.GetNumVertices() * VertexBuffer.GetStride());
					RHIUnlockVertexBuffer(VertexBuffer.VertexBufferRHI);
				}

				{
					auto& VertexBuffer = Section->VertexBuffers.StaticMeshVertexBuffer;
					Gamevoid* VertexBufferData = RHILockVertexBuffer(VertexBuffer.TangentsVertexBuffer.VertexBufferRHI, 0, VertexBuffer.GetTangentSize(), RLM_WriteOnly);
					FMemory::Memcpy(VertexBufferData, VertexBuffer.GetTangentData(), VertexBuffer.GetTangentSize());
					RHIUnlockVertexBuffer(VertexBuffer.TangentsVertexBuffer.VertexBufferRHI);
				}

				{
					auto& VertexBuffer = Section->VertexBuffers.StaticMeshVertexBuffer;
					Gamevoid* VertexBufferData = RHILockVertexBuffer(VertexBuffer.TexCoordVertexBuffer.VertexBufferRHI, 0, VertexBuffer.GetTexCoordSize(), RLM_WriteOnly);
					FMemory::Memcpy(VertexBufferData, VertexBuffer.GetTexCoordData(), VertexBuffer.GetTexCoordSize());
					RHIUnlockVertexBuffer(VertexBuffer.TexCoordVertexBuffer.VertexBufferRHI);
				}
			}

			// Free data sent from game thread
			delete SectionData;
		}
	}

	Gamevoid SetSectionVisibility_RenderThread(Gameint SectionIndex, Gamebool bNewVisibility)
	{
		check(IsInRenderingThread());

		if (SectionIndex < Sections.Num() &&
			Sections[SectionIndex] != nullptr)
		{
			Sections[SectionIndex]->bSectionVisible = bNewVisibility;
		}
	}

	virtual Gamevoid GetDynamicMeshElements(const TArray<const FSceneView*>& Views, const FSceneViewFamily& ViewFamily, Gameuint VisibilityMap, FMeshElementCollector& Collector) const override
	{
		//SCOPE_CYCLE_COUNTER(STAT_MyProcMesh_GetMeshElements);

		// Set up wireframe material (if needed)
		const Gamebool bWireframe = AllowDebugViewmodes() && ViewFamily.EngineShowFlags.Wireframe;

		FColoredMaterialRenderProxy* WireframeMaterialInstance = NULL;
		if (bWireframe)
		{
			WireframeMaterialInstance = new FColoredMaterialRenderProxy(
				GEngine->WireframeMaterial ? GEngine->WireframeMaterial->GetRenderProxy() : NULL,
				FLinearColor(0, 0.5f, 1.f)
			);

			Collector.RegisterOneFrameMaterialProxy(WireframeMaterialInstance);
		}

		if (!m_bVisible || !m_bVisibleLayer)
		{
			return;
		}

		// Iterate over sections
		for (const FMyProcMeshProxySection* Section : Sections)
		{
			if (Section != nullptr && Section->bSectionVisible)
			{
				FMaterialRenderProxy* MaterialProxy = bWireframe ? WireframeMaterialInstance : Section->Material->GetRenderProxy();

				// For each view..
				for (Gameint ViewIndex = 0; ViewIndex < Views.Num(); ViewIndex++)
				{
					if (VisibilityMap & (1 << ViewIndex))
					{
						if (ViewIndex == 1 && Section->Material->GetBaseMaterial()->GetName() == "CommonLine")
						{
							continue;
						}

						const FSceneView* View = Views[ViewIndex];

						if (!IsInsideFrustum(View))
						{
							continue;
						}

						// Draw the mesh.
						FMeshBatch& Mesh = Collector.AllocateMesh();
						FMeshBatchElement& BatchElement = Mesh.Elements[0];
						BatchElement.IndexBuffer = &Section->IndexBuffer;
						Mesh.bWireframe = bWireframe;
						Mesh.VertexFactory = &Section->VertexFactory;
						Mesh.MaterialRenderProxy = MaterialProxy;

						Gamebool bHasPrecomputedVolumetricLightmap;
						FMatrix PreviousLocalToWorld;
						Gameint SingleCaptureIndex;
						Gamebool bOutputVelocity;
						GetScene().GetPrimitiveUniformShaderParameters_RenderThread(GetPrimitiveSceneInfo(), bHasPrecomputedVolumetricLightmap, PreviousLocalToWorld, SingleCaptureIndex, bOutputVelocity);


						FDynamicPrimitiveUniformBuffer& DynamicPrimitiveUniformBuffer = Collector.AllocateOneFrameResource<FDynamicPrimitiveUniformBuffer>();
						DynamicPrimitiveUniformBuffer.Set(GetLocalToWorld(), PreviousLocalToWorld, GetBounds(), GetLocalBounds(), true, bHasPrecomputedVolumetricLightmap, DrawsVelocity(), bOutputVelocity);
						BatchElement.PrimitiveUniformBufferResource = &DynamicPrimitiveUniformBuffer.UniformBuffer;

						BatchElement.FirstIndex = 0;
						if (m_eDrawType == PT_PointList)
						{
							BatchElement.NumPrimitives = Section->IndexBuffer.Indices.Num();
						}
						else if (m_eDrawType == PT_LineList)
						{
							BatchElement.NumPrimitives = Section->IndexBuffer.Indices.Num() / 2;
						}
						else
						{
							BatchElement.NumPrimitives = Section->IndexBuffer.Indices.Num() / 3;
						}
						BatchElement.MinVertexIndex = 0;
						BatchElement.MaxVertexIndex = Section->VertexBuffers.PositionVertexBuffer.GetNumVertices() - 1;
						Mesh.ReverseCulling = IsLocalToWorldDeterminantNegative();
						Mesh.Type = m_eDrawType;
						Mesh.DepthPriorityGroup = SDPG_World;
						Mesh.bCanApplyViewModeOverrides = false;
						Collector.AddMesh(ViewIndex, Mesh);
					}
				}
			}
		}

		// Draw bounds
#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)
		//for (Gameint ViewIndex = 0; ViewIndex < Views.Num(); ViewIndex++)
		//{
		//	if (VisibilityMap & (1 << ViewIndex))
		//	{
		//		// Draw simple collision as wireframe if 'show collision', and collision is enabled, and we are not using the complex as the simple
		//		if (ViewFamily.EngineShowFlags.Collision && IsCollisionEnabled() && BodySetup->GetCollisionTraceFlag() != ECollisionTraceFlag::CTF_UseComplexAsSimple)
		//		{
		//			FTransform GeomTransform(/*m_matLocalToWorld*/GetLocalToWorld());
		//			BodySetup->AggGeom.GetAggGeom(GeomTransform, GetSelectionColor(FColor(157, 149, 223, 255), IsSelected(), IsHovered()).ToFColor(true), NULL, false, false, DrawsVelocity(), ViewIndex, Collector);
		//		}
		//
		//		// Render bounds
		//		RenderBounds(Collector.GetPDI(ViewIndex), ViewFamily.EngineShowFlags, GetBounds(), IsSelected());
		//	}
		//}
#endif
	}

	virtual FPrimitiveViewRelevance GetViewRelevance(const FSceneView* View) const
	{
		FPrimitiveViewRelevance Result;
		Result.bDrawRelevance = IsShown(View);
		Result.bShadowRelevance = IsShadowCast(View);
		Result.bDynamicRelevance = true;
		Result.bRenderInMainPass = ShouldRenderInMainPass();
		Result.bUsesLightingChannels = GetLightingChannelMask() != GetDefaultLightingChannelMask();
		Result.bRenderCustomDepth = ShouldRenderCustomDepth();
		Result.bTranslucentSelfShadow = bCastVolumetricTranslucentShadow;
		MaterialRelevance.SetPrimitiveViewRelevance(Result);
		Result.bVelocityRelevance = IsMovable() && Result.bOpaque && Result.bRenderInMainPass;
		return Result;
	}

	Gamebool IsInsideFrustum(const FSceneView* View) const
	{
		auto bounds = GetBounds();
		Gamefloat radius = bounds.SphereRadius;

		auto shadowFrustum = View->GetDynamicMeshElementsShadowCullFrustum();

		if (shadowFrustum)
		{
			return shadowFrustum->IntersectSphere(bounds.Origin, radius);
		}
		else
		{
			return View->ViewFrustum.IntersectSphere(bounds.Origin, radius);
		}

	}

	virtual Gamebool CanBeOccluded() const override
	{
		return !MaterialRelevance.bDisableDepthTest;
	}

	virtual Gameuint GetMemoryFootprint(Gamevoid) const
	{
		return(sizeof(*this) + GetAllocatedSize());
	}

	Gameuint GetAllocatedSize(Gamevoid) const
	{
		return(FPrimitiveSceneProxy::GetAllocatedSize());
	}


#if RHI_RAYTRACING
	virtual Gamebool IsRayTracingRelevant() const override { return true; }

	virtual Gamevoid GetDynamicRayTracingInstances(FRayTracingMaterialGatheringContext& Context, TArray<FRayTracingInstance>& OutRayTracingInstances) override final
	{
		if (m_eDrawType != PT_TriangleList) return;
		for (const FMyProcMeshProxySection* Section : Sections)
		{
			if (Section != nullptr && Section->bSectionVisible)
			{
				FMaterialRenderProxy* MaterialProxy = Section->Material->GetRenderProxy();

				if (Section->RayTracingGeometry.RayTracingGeometryRHI.IsValid())
				{
					check(Section->RayTracingGeometry.Initializer.IndexBuffer.IsValid());

					FRayTracingInstance RayTracingInstance;
					RayTracingInstance.Geometry = &Section->RayTracingGeometry;
					RayTracingInstance.InstanceTransforms.Add(/*m_matLocalToWorld*/GetLocalToWorld());

					Gameuint SectionIdx = 0;
					FMeshBatch MeshBatch;
					MeshBatch.VertexFactory = &Section->VertexFactory;
					
					MeshBatch.SegmentIndex = 0;
					MeshBatch.MaterialRenderProxy = Section->Material->GetRenderProxy();
					MeshBatch.ReverseCulling = IsLocalToWorldDeterminantNegative();
					MeshBatch.Type = m_eDrawType;
					MeshBatch.DepthPriorityGroup = SDPG_World;
					MeshBatch.bCanApplyViewModeOverrides = false;
					MeshBatch.CastRayTracedShadow = IsShadowCast(Context.ReferenceView);

					FMeshBatchElement& BatchElement = MeshBatch.Elements[0];
					BatchElement.IndexBuffer = &Section->IndexBuffer;

					Gamebool bHasPrecomputedVolumetricLightmap;
					FMatrix PreviousLocalToWorld;
					Gameint SingleCaptureIndex;
					Gamebool bOutputVelocity;
					GetScene().GetPrimitiveUniformShaderParameters_RenderThread(GetPrimitiveSceneInfo(), bHasPrecomputedVolumetricLightmap, PreviousLocalToWorld, SingleCaptureIndex, bOutputVelocity);

					FDynamicPrimitiveUniformBuffer& DynamicPrimitiveUniformBuffer = Context.RayTracingMeshResourceCollector.AllocateOneFrameResource<FDynamicPrimitiveUniformBuffer>();
					DynamicPrimitiveUniformBuffer.Set(/*m_matLocalToWorld*/GetLocalToWorld(), PreviousLocalToWorld, GetBounds(), GetLocalBounds(), true, bHasPrecomputedVolumetricLightmap, DrawsVelocity(), bOutputVelocity);
					BatchElement.PrimitiveUniformBufferResource = &DynamicPrimitiveUniformBuffer.UniformBuffer;

					BatchElement.FirstIndex = 0;

					if (m_eDrawType == PT_PointList)
					{
						BatchElement.NumPrimitives = Section->IndexBuffer.Indices.Num();
					}
					else if (m_eDrawType == PT_LineList)
					{
						BatchElement.NumPrimitives = Section->IndexBuffer.Indices.Num() / 2;
					}
					else
					{
						BatchElement.NumPrimitives = Section->IndexBuffer.Indices.Num() / 3;
					}

					BatchElement.MinVertexIndex = 0;
					BatchElement.MaxVertexIndex = Section->VertexBuffers.PositionVertexBuffer.GetNumVertices() - 1;

					RayTracingInstance.Materials.Add(MeshBatch);

					//RayTracingInstance.BuildInstanceMaskAndFlags();
					OutRayTracingInstances.Add(RayTracingInstance);
				}
			}
		}
	}

#endif

private:
	//! \brief 绘制方式
	EPrimitiveType m_eDrawType;

	/** Array of sections */
	TArray<FMyProcMeshProxySection*> Sections;

	UBodySetup* BodySetup;

	FMaterialRelevance MaterialRelevance;

	Gamebool m_bVisible;

	//! \brief 
	Gamebool m_bVisibleLayer;
public:
	FMatrix m_matLocalToWorld;
};

//////////////////////////////////////////////////////////////////////////

USuperMap_ProceduralMeshComponent::USuperMap_ProceduralMeshComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bUseComplexAsSimpleCollision = true;
	m_nDrawType = 0;
	m_bVisible = true;
	m_bVisibleLayer = true;
	m_pSceneProxy = nullptr;
	m_bCollision = true;
	m_pMaterial = nullptr;
}

FPrimitiveSceneProxy* USuperMap_ProceduralMeshComponent::CreateSceneProxy()
{
	m_pSceneProxy = new FMyProceduralMeshSceneProxy(this);
	return m_pSceneProxy;
}

Gamevoid USuperMap_ProceduralMeshComponent::UpdateComponentCollision(Gamebool bEnable)
{
	Gameint num = GetNumSections();
	if (num ==0)
	{
		return;
	}

	GetProcMeshSection(0)->bEnableCollision = bEnable;
}

Gamevoid USuperMap_ProceduralMeshComponent::SetLayerVisibity(Gamebool visible)
{
	m_bVisibleLayer = visible;

	if (m_pSceneProxy && !IsRenderStateDirty())
	{
		Gamebool isVisble = visible;
		FMyProceduralMeshSceneProxy* pSceneProxy = (FMyProceduralMeshSceneProxy *)m_pSceneProxy;
		ENQUEUE_RENDER_COMMAND(FRenderMeshSetLayerVisibity)
			([pSceneProxy, isVisble](FRHICommandListImmediate & RHICmdList)
		{
			pSceneProxy->SetVisibleLayer_RenderThread(isVisble);
		});
	}
}

Gamebool USuperMap_ProceduralMeshComponent::GetLayerVisibity()
{
	return m_bVisibleLayer;
}

Gamevoid USuperMap_ProceduralMeshComponent::SetInternalVisibity(Gamebool visible)
{
	m_bVisible = visible;

	if (m_pSceneProxy && !IsRenderStateDirty())
	{
		Gamebool isVisble = visible;
		FMyProceduralMeshSceneProxy* pSceneProxy = (FMyProceduralMeshSceneProxy *) m_pSceneProxy;
		ENQUEUE_RENDER_COMMAND(FRenderMeshSetInternalVisiblity)
		([pSceneProxy, isVisble](FRHICommandListImmediate & RHICmdList)
		{
			pSceneProxy->SetVisible_RenderThread(isVisble);
		});
	}
}

Gamevoid USuperMap_ProceduralMeshComponent::SetDrawType(Gameint nType)
{
	m_nDrawType = nType;
}

Gamevoid USuperMap_ProceduralMeshComponent::Clear()
{
	ClearAllMeshSections();
}

Gamevoid USuperMap_ProceduralMeshComponent::SetName(FName strName)
{
	m_strName = strName;
}

FName USuperMap_ProceduralMeshComponent::GetName()
{
	return m_strName;
}

Gamevoid USuperMap_ProceduralMeshComponent::SetCollision(Gamebool bCollision)
{
	m_bCollision = bCollision;
}

Gamevoid USuperMap_ProceduralMeshComponent::CreateProceduralMesh(
	SuperMapSDK::DataVertex* pDataVertex,
	SuperMapSDK::DataIndice* pDataIndice,
	UMaterialInterface* pMat)
{
	Gamebool bGlobeMesh = false;
	Gamedouble* pDMat = pDataVertex->m_doubleObjectMat;
	Matrix4d doubleObjectMatrix(pDMat);
	if (pMat != nullptr)
	{
		FString strName = pMat->GetBaseMaterial()->GetName();
		if (strName == "Global") {
			bGlobeMesh = true;
		}
	}

	// 顶点
	TArray<FVector> arrVertices;
	// 纹理坐标
	TArray<FVector2D> arrTextureCoords1;
	TArray<FVector2D> arrTextureCoords2;

	// secondColor
	TArray<FVector2D> arrTextureCoords3;
	TArray<FVector2D> arrTextureCoords4;

	// 法线坐标
	TArray<FVector> arrNormals;

	// 顶点颜色
	TArray<FColor> arrColor;

	// 顶点
	Gameint nVtxDim = pDataVertex->m_nPosDim;
	for (Gameint i = 0; i < pDataVertex->m_nPosCount; i++)
	{
		//==================================================
		FVector pos;
		pos.Y = pDataVertex->m_Pos[nVtxDim * i + 0];
		pos.X = pDataVertex->m_Pos[nVtxDim * i + 1];
		pos.Z = pDataVertex->m_Pos[nVtxDim * i + 2];
		arrVertices.Add(pos);
		if (nVtxDim == 4 && bGlobeMesh) {
			FVector2D wValue;
			wValue.X = pDataVertex->m_Pos[nVtxDim * i + 3];
			wValue.Y = pDataVertex->m_Pos[nVtxDim * i + 3];
			arrTextureCoords3.Add(wValue);
		}

		//===================================================
		Gamebool bNewModel = false;
		if (pDataVertex->m_nBlendWeightsCount > 0 && pDataVertex->m_pBlendWeights != nullptr)
		{
			FVector2D weights;
			weights.X = pDataVertex->m_pBlendWeights[i];
			weights.Y = 0;

			bNewModel = true;
			arrTextureCoords2.Add(weights);
		}
		//===================================================
		if (pDataVertex->m_nTexCoordCount == pDataVertex->m_nPosCount && pDataVertex->m_TexCoord != nullptr)
		{
			FVector2D UV0;
			FVector2D UV1;
			Gameint nTexDim = pDataVertex->m_nTexCoordDim;
			if (nTexDim == 2)
			{
				UV0.X = pDataVertex->m_TexCoord[nTexDim * i + 0];
				UV0.Y = pDataVertex->m_TexCoord[nTexDim * i + 1];
				arrTextureCoords1.Add(UV0);
			}
			else if (nTexDim == 3)
			{
				UV1.X = pDataVertex->m_TexCoord[nTexDim * i + 0];
				UV1.Y = pDataVertex->m_TexCoord[nTexDim * i + 1];
				UV0.X = pDataVertex->m_TexCoord[nTexDim * i + 2];

				if (!bNewModel)
				{
					arrTextureCoords1.Add(UV0);
					arrTextureCoords2.Add(UV1);
				}
				else
				{
					arrTextureCoords1.Add(UV1);
				}
				
			}
		}

		//======================================================
		if (pDataVertex->m_nNormalCount == pDataVertex->m_nPosCount && pDataVertex->m_Normal != nullptr)
		{
			Gameuint nNormalCount = pDataVertex->m_nNormalCount;
			Gameuint nNormalDim = pDataVertex->m_nNormalDim;

			FVector Normal;
			// 这里XY需要反一下，因为UE的轴和组件的不一样
			Normal.Y = pDataVertex->m_Normal[i * nNormalDim + 0];
			Normal.X = pDataVertex->m_Normal[i * nNormalDim + 1];
			Normal.Z = pDataVertex->m_Normal[i * nNormalDim + 2];
			arrNormals.Add(Normal);
		}

		//=======================================================
		if (pDataVertex->m_nColorCount == pDataVertex->m_nPosCount && pDataVertex->m_PosColor != nullptr)
		{
			Gameuint nColor = pDataVertex->m_PosColor[i];

			Gamefloat fR, fG, fB, fA;
			SuperMapSDK::UnrealEngine::Core::_IDRGBA(nColor, fR, fG, fB, fA);

			uint8 r = fR * 255;
			uint8 g = fG * 255;
			uint8 b = fB * 255;
			uint8 a = fA * 255;

			FColor color(r, g, b, a);
			arrColor.Add(color);
		}
		//========================================================
		if (pDataVertex->m_nSecondColorCount == pDataVertex->m_nPosCount && pDataVertex->m_PosSceondColor != nullptr)
		{
			Gameuint nColor = pDataVertex->m_PosSceondColor[i];

			Gamefloat fR, fG, fB, fA;
			SuperMapSDK::UnrealEngine::Core::_IDRGBA(nColor, fR, fG, fB, fA);

			FVector4 fColor(fR, fG, fB, fA);
			arrTextureCoords3.Add(FVector2D(fColor.X, fColor.Y));
			arrTextureCoords4.Add(FVector2D(fColor.Z, fColor.W));
		}

	}

	if (pDataIndice != nullptr)
	{
		TArray<FVector>    EmptyVectorArray;
		TArray<FColor>     EmptyColorArray;
		TArray<FVector2D>  EmptyTexCoordArray;
		TArray<FProcMeshTangent> EmptyTangentArray;

		TArray<Gameint> arrIndices;
		for (Gameint j = 0; j < 1; j++)
		{
			for (Gameint i = 0; i < pDataIndice->m_nIndexCount; i++)
			{
				if (pDataIndice->m_Index != nullptr)
				{
					arrIndices.Add(pDataIndice->m_Index[i]);
				}
				else
				{
					arrIndices.Add(pDataIndice->m_shortIndex[i]);
				}
			}

			m_nDrawType = pDataIndice->m_nOperationType;

			if (pMat != nullptr)
			{
				SetCustomMaterial(pMat);
			}
			CreateMeshSection(0, arrVertices, arrIndices, arrNormals, arrTextureCoords1, arrTextureCoords2, arrTextureCoords3, arrTextureCoords4, arrColor, EmptyTangentArray, m_bCollision);
		}
	}
	m_matDoubleLocalToWorld = doubleObjectMatrix;
}


Gamevoid USuperMap_ProceduralMeshComponent::SetCustomMaterial(UMaterialInterface* pMat)
{
	if (pMat == nullptr)
	{
		return;
	}

	SetMaterial(0 , pMat);

	m_pMaterial = pMat;
}

UMaterialInterface* USuperMap_ProceduralMeshComponent::GetCustomMaterial()
{
	return m_pMaterial;
}

Matrix4d USuperMap_ProceduralMeshComponent::GetLocalToWorld()
{
	return m_matDoubleLocalToWorld;
}