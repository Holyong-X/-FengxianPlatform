#include "Component/SuperMap_LineMeshSceneProxy.h"

#include "Engine.h"
#include "Materials/Material.h"
//#include "Core/RealspaceDLL.h"
#include "RayTracingDefinitions.h"
#include "RayTracingInstance.h"


FSuperMapLineMeshSceneProxy::FSuperMapLineMeshSceneProxy(const USuperMap_LineMeshComponent* InComponent, FSMMesh& smMesh)
	: FPrimitiveSceneProxy(InComponent),
	m_MaterialRelevance(InComponent->GetMaterialRelevance(GetScene().GetFeatureLevel())),
	m_pVertexFactory(nullptr)
{
	m_bVisible = InComponent->GetInternalVisibility();
	m_bVisibleLayer = true;
	m_bVisibleInViewport[0] = true;
	m_bVisibleInViewport[1] = true;
	m_bRender = true;

	m_pMaterialInterface = InComponent->GetMaterial(0);

	if (m_pMaterialInterface == nullptr)
	{
		m_pMaterialInterface = UMaterial::GetDefaultMaterial(MD_Surface);
	}

	FString strName = m_pMaterialInterface->GetBaseMaterial()->GetName();

	m_pVertexBuffer = new FSuperMapLineVertexBuffer();
	if(smMesh.isValid())
	{
		m_pVertexBuffer->SetMesh(smMesh);
	}

#if RHI_RAYTRACING
	InitRayTracingGeometry();
#endif

	const auto FeatureLevel = GetScene().GetFeatureLevel();
	bVFRequiresPrimitiveUniformBuffer = true;
	bStaticElementsAlwaysUseProxyPrimitiveUniformBuffer = true;
}

FSuperMapLineMeshSceneProxy::~FSuperMapLineMeshSceneProxy()
{
	if (m_pVertexBuffer != nullptr)
	{
		delete m_pVertexBuffer;
		m_pVertexBuffer = nullptr;
	}

	if (m_pVertexFactory != nullptr)
	{
		m_pVertexFactory->ReleaseResource();
		delete m_pVertexFactory;
		m_pVertexFactory = nullptr;
	}

#if RHI_RAYTRACING
	if (IsRayTracingEnabled())
	{
		m_RayTracingGeometry.ReleaseResource();
	}
#endif
}

Gamevoid FSuperMapLineMeshSceneProxy::UpdateMesh(const TArray<SM_Vertex>& arrVertex, const TArray<SM_SubMesh>& arrSubMesh)
{
	m_arrVertex = arrVertex;
	m_arrSubMesh = arrSubMesh;
}

Gamebool FSuperMapLineMeshSceneProxy::CanBeOccluded() const
{
	return !m_MaterialRelevance.bDisableDepthTest;
}

Gamevoid FSuperMapLineMeshSceneProxy::DrawStaticElements(FStaticPrimitiveDrawInterface* PDI)
{
}

Gameuint FSuperMapLineMeshSceneProxy::GetAllocatedSize(Gamevoid) const
{
	return (FPrimitiveSceneProxy::GetAllocatedSize());
}

#if RHI_RAYTRACING
Gamevoid FSuperMapLineMeshSceneProxy::InitRayTracingGeometry()
{
}

Gamevoid FSuperMapLineMeshSceneProxy::GetDynamicRayTracingInstances(FRayTracingMaterialGatheringContext& Context, TArray<FRayTracingInstance>& OutRayTracingInstances)
{
}
#endif
Gamevoid FSuperMapLineMeshSceneProxy::GetDynamicMeshElements(const TArray<const FSceneView*>& Views,
												   const FSceneViewFamily& ViewFamily,
												   Gameuint VisibilityMap,
												   FMeshElementCollector& Collector) const
{

	// Set up wireframe material (if needed)
	const Gamebool bWireframe = AllowDebugViewmodes() && ViewFamily.EngineShowFlags.Wireframe;

	FColoredMaterialRenderProxy* WireframeMaterialInstance = NULL;

	if (bWireframe)
	{
		WireframeMaterialInstance = new FColoredMaterialRenderProxy(GEngine->WireframeMaterial ? GEngine->WireframeMaterial->GetRenderProxy() : NULL,
			FLinearColor(0, 0.5f, 1.f));
		Collector.RegisterOneFrameMaterialProxy(WireframeMaterialInstance);
	}

	if (!m_bVisible || !m_bVisibleLayer || !m_bRender)
	{
		return;
	}

	FMaterialRenderProxy* CustomMaterialProxy = m_pMaterialInterface->GetRenderProxy();
	FMaterialRenderProxy* MaterialProxy = bWireframe ? WireframeMaterialInstance : CustomMaterialProxy;

	for (int32 ViewIndex = 0; ViewIndex < Views.Num(); ViewIndex++)
	{

		if ((VisibilityMap & (1 << ViewIndex)))
		{
			if (ViewIndex == 0)
			{
				if (!m_bVisibleInViewport[0])
				{
					continue;
				}
			}
			else if (ViewIndex == 1)
			{
				if (!m_bVisibleInViewport[1])
				{
					continue;
				}
			}
			const FSceneView* View = Views[ViewIndex];

			if (!IsInsideFrustum(View) || MaterialProxy == nullptr)
			{
				continue;
			}

			if (m_arrSubMesh.Num() > 0)
			{
				FPrimitiveDrawInterface* PDI = Collector.GetPDI(ViewIndex);
				for (int meshIndex = 0; meshIndex < m_arrSubMesh.Num(); meshIndex++)
				{
					int32 n = m_arrSubMesh[meshIndex].IndexBuffer.Num();
					int32 nLineCount = n / 2;
					for (int nLineIndex = 0; nLineIndex < nLineCount; nLineIndex++)
					{
						int32 nStartIndex = m_arrSubMesh[meshIndex].IndexBuffer[nLineIndex * 2];
						int32 nEndIndex = m_arrSubMesh[meshIndex].IndexBuffer[nLineIndex * 2 + 1];
						FVector vStart = m_arrVertex[nStartIndex].Position;
						FVector vEnd = m_arrVertex[nEndIndex].Position;
						PDI->DrawLine(vStart, vEnd, m_arrVertex[nStartIndex].Color, SDPG_World, 1.f, 0.0, true);
					}
				}
			}
			else
			{
				FMeshBatch& MeshBatch = Collector.AllocateMesh();

				SetupMeshBatch(MeshBatch, MaterialProxy, bWireframe);
				SetupMeshBatchElement(MeshBatch.Elements[0], Collector);

				Collector.AddMesh(ViewIndex, MeshBatch);
			}
		}
	}
}

Gameuint FSuperMapLineMeshSceneProxy::GetMemoryFootprint(Gamevoid) const
{
	return (sizeof(*this) + GetAllocatedSize());
}

SIZE_T FSuperMapLineMeshSceneProxy::GetTypeHash() const
{
	static size_t UniquePointer;

	return reinterpret_cast<size_t>(&UniquePointer);
}

FPrimitiveViewRelevance FSuperMapLineMeshSceneProxy::GetViewRelevance(const FSceneView* View) const
{
	FPrimitiveViewRelevance Result;
	Result.bDrawRelevance = IsShown(View);
	Result.bShadowRelevance = false;
	Result.bDynamicRelevance = true;
	Result.bRenderInMainPass = ShouldRenderInMainPass();
	Result.bUsesLightingChannels = GetLightingChannelMask() != GetDefaultLightingChannelMask();
	Result.bRenderCustomDepth = ShouldRenderCustomDepth();
	Result.bTranslucentSelfShadow = bCastVolumetricTranslucentShadow;
	m_MaterialRelevance.SetPrimitiveViewRelevance(Result);
	Result.bVelocityRelevance = 0;
	return Result;
}


Gamevoid FSuperMapLineMeshSceneProxy::CreateRenderThreadResources()
{
	if (m_arrSubMesh.Num() > 0)
	{
		return;
	}

	m_pVertexBuffer->CreateRenderResources_RenderThread();

	if (m_pVertexFactory == nullptr)
	{
		m_pVertexFactory = new FSuperMapEdgeLineVertexFactory(GetScene().GetFeatureLevel());
	}

	m_pVertexFactory->SetVertexBuffer(m_pVertexBuffer);
	m_pVertexFactory->InitResource();
}

Gamebool FSuperMapLineMeshSceneProxy::IsInsideFrustum(const FSceneView* View) const
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

Gamevoid FSuperMapLineMeshSceneProxy::SetInternalVisibility_RenderThread(Gamebool visible)
{
	check(IsInRenderingThread());

	m_bVisible = visible;
}

Gamevoid FSuperMapLineMeshSceneProxy::SetVisibleLayer_RenderThread(Gamebool visible)
{
	check(IsInRenderingThread());

	m_bVisibleLayer = visible;
}

Gamevoid FSuperMapLineMeshSceneProxy::SetVisibleInViewport_RenderThread(int nIndex, Gamebool visible)
{
	m_bVisibleInViewport[nIndex] = visible;
}

Gamevoid FSuperMapLineMeshSceneProxy::SetupMeshBatch(FMeshBatch& meshBatch, FMaterialRenderProxy* material, Gamebool bWireframe) const
{
	meshBatch.VertexFactory = m_pVertexFactory;

	FMeshBatchElement& BatchElement = meshBatch.Elements[0];
	m_pVertexBuffer->SetupMeshBatch(meshBatch);
	meshBatch.Type = EPrimitiveType::PT_TriangleList;
	meshBatch.bCanApplyViewModeOverrides = false;
	meshBatch.bWireframe = bWireframe;

	meshBatch.DepthPriorityGroup = SDPG_World;
	meshBatch.MaterialRenderProxy = material;
	meshBatch.ReverseCulling = IsLocalToWorldDeterminantNegative();
}

Gamevoid FSuperMapLineMeshSceneProxy::SetupMeshBatchElement(FMeshBatchElement& BatchElement, FMeshElementCollector& Collector) const
{
	BatchElement.PrimitiveUniformBuffer = GetUniformBuffer();
}

