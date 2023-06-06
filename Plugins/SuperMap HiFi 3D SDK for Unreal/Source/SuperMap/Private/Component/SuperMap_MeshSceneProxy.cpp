#include "Component/SuperMap_MeshSceneProxy.h"

#include "Engine.h"
#include "Materials/Material.h"
#include "Core/RealspaceDLL.h"
#include "RayTracingDefinitions.h"
#include "RayTracingInstance.h"
#include "Graphics3D/GameConvertor.h"
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif

using namespace SuperMapSDK;

UseMaterialFlag FSuperMapMeshSceneProxy::m_enSceneUseMaterialFlag = UseMaterialFlag::UMF_NORMAL;

FSuperMapMeshSceneProxy::FSuperMapMeshSceneProxy(const USuperMap_MeshComponent* InComponent, FSMMesh& smMesh, const TArray<FSuperMapMaterialInterfaceCollection>& arrMaterialCollection)
	: FPrimitiveSceneProxy(InComponent),
	m_enUseMaterialFlag(UMF_NORMAL),
	m_MaterialRelevance(InComponent->GetMaterialRelevance(GetScene().GetFeatureLevel())),
	m_pVertexFactory(nullptr)
{
	m_bUseDynamicPath     = true;
	m_bVisible            = InComponent->GetInternalVisibility();
	m_bVisibleLayer       = InComponent->GetLayerVisibility();
	m_bVisibleInViewport[0] = true;
	m_bVisibleInViewport[1] = true;
	m_bRender				= true;
	m_bReverseCulling		= InComponent->GetReverseCulling();

	m_pCustomVertexBuffer = new FSuperMapCustomVertexBuffer();
	m_pCustomVertexBuffer->SetMesh(smMesh);


	//超过一个的材质为空间索引裁剪的材质
	//check(smMesh.m_arrDataIndex.Num() == arrMaterialCollection.Num());
	if (arrMaterialCollection.Num() > smMesh.m_arrDataIndex.Num())
	{
		for (Gameint i = smMesh.m_arrDataIndex.Num(); i < arrMaterialCollection.Num(); i++)
		{
			UMaterialInterface* pMaterialInterface = arrMaterialCollection[i].GetMaterialByUseFlag(UseMaterialFlag::UMF_NORMAL);

			if (pMaterialInterface != nullptr)
			{
				m_arrMaterialInterface.Add(pMaterialInterface);
			}
			
		}
	}

	m_arrBatchedSections.SetNum(smMesh.m_arrDataIndex.Num());
	for (Gameint i = 0; i < m_arrBatchedSections.Num(); i++)
	{
		m_arrBatchedSections[i].SetMesh(smMesh.m_arrDataIndex[i]);
		m_arrBatchedSections[i].m_MaterialCollection = arrMaterialCollection[i];
	}
	smMesh.m_arrDataIndex.Empty();

#if RHI_RAYTRACING
	InitRayTracingGeometry();
#endif

	const auto FeatureLevel = GetScene().GetFeatureLevel();

	bVFRequiresPrimitiveUniformBuffer = true;
	bStaticElementsAlwaysUseProxyPrimitiveUniformBuffer = true;
}

FSuperMapMeshSceneProxy::~FSuperMapMeshSceneProxy()
{
	if (m_pCustomVertexBuffer != nullptr)
	{
		delete m_pCustomVertexBuffer;
		m_pCustomVertexBuffer = nullptr;
	}

	for (Gameint i = 0; i < m_arrBatchedSections.Num(); i++)
	{
		m_arrBatchedSections[i].ReleaseResource();
	}
	m_arrBatchedSections.Empty();

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

Gamebool FSuperMapMeshSceneProxy::CanBeOccluded() const
{
	return !m_MaterialRelevance.bDisableDepthTest;
}

Gamevoid FSuperMapMeshSceneProxy::DrawStaticElements(FStaticPrimitiveDrawInterface* PDI)
{
	if (m_bUseDynamicPath)
	{
		return;
	}
	for (Gameint i = 0; i < m_arrBatchedSections.Num(); i++)
	{
		FMeshBatch MeshBatch;
		// TODO 多视口
		auto pMaterialRenderProxy = GetMaterialForSection(m_arrBatchedSections[i], 0);
		if (pMaterialRenderProxy == nullptr)
		{
			continue;
		}
		SetupMeshBatch(MeshBatch, m_arrBatchedSections[i], pMaterialRenderProxy, false);
		PDI->DrawMesh(MeshBatch, FLT_MAX);
	}
}

Gameuint FSuperMapMeshSceneProxy::GetAllocatedSize(Gamevoid) const
{
	return (FPrimitiveSceneProxy::GetAllocatedSize());
}

#if RHI_RAYTRACING
Gamevoid FSuperMapMeshSceneProxy::InitRayTracingGeometry()
{
}

Gamevoid FSuperMapMeshSceneProxy::GetDynamicRayTracingInstances(FRayTracingMaterialGatheringContext& Context, TArray<FRayTracingInstance>& OutRayTracingInstances)
{
}
#endif

Gamevoid FSuperMapMeshSceneProxy::UpdateSubMesh_RenderThread(TArray<DataIndice*> arrIndices, TArray<FSuperMapMaterialInterfaceCollection> arrMaterialCollection)
{
	check(IsInRenderingThread());
	
	// 删除旧的索引，创建新的
	Gameint nSectionCount = m_arrBatchedSections.Num();
	for (Gameint i = 0; i < nSectionCount; i++)
	{
		FSuperMapRenderSection& section = m_arrBatchedSections[i];
		if (section.m_pDataIndex)
		{
			delete section.m_pDataIndex;
			section.m_pDataIndex = nullptr;
		}

		if (section.m_pIndexBuffer != nullptr)
		{
			section.m_pIndexBuffer->ReleaseResource();
			delete section.m_pIndexBuffer;
			section.m_pIndexBuffer = nullptr;
		}
	}

	m_arrBatchedSections.RemoveAt(0, nSectionCount);

	// 添加索引
	Gameint nCount = arrIndices.Num();
	m_arrBatchedSections.SetNum(nCount);
	for (Gameint i = 0; i < nCount; i++)
	{
		FSuperMapRenderSection& section = m_arrBatchedSections[i];
		section.SetMesh(arrIndices[i]);
		section.m_MaterialCollection = arrMaterialCollection[i];
		section.CreateRenderResources_RenderThread();
	}
}

Gamevoid FSuperMapMeshSceneProxy::SetReverseCulling_RenderThread(Gamebool bReverseCulling)
{
	check(IsInRenderingThread());

	m_bReverseCulling = bReverseCulling;
}

Gamevoid FSuperMapMeshSceneProxy::GetDynamicMeshElements(const TArray<const FSceneView*>& Views,
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

	for (Gameint ViewIndex = 0; ViewIndex < Views.Num(); ViewIndex++)
	{
		
		if ((VisibilityMap & (1 << ViewIndex)))
		{
			if (!m_bVisibleInViewport[ViewIndex])
			{
				continue;
			}
			const FSceneView* View = Views[ViewIndex];

			if (!IsInsideFrustum(View))
			{
				continue;
			}

			for (Gameint sectionIndex = 0; sectionIndex < m_arrBatchedSections.Num(); sectionIndex++)
			{
				FMeshBatch& MeshBatch = Collector.AllocateMesh();
				FMaterialRenderProxy* pMaterialRenderProxy = bWireframe ? WireframeMaterialInstance : GetMaterialForSection(m_arrBatchedSections[sectionIndex], ViewIndex);
				if (pMaterialRenderProxy == nullptr || m_arrBatchedSections[sectionIndex].m_pIndexBuffer == nullptr)
				{
					continue;
				}
				SetupMeshBatch(MeshBatch, m_arrBatchedSections[sectionIndex], pMaterialRenderProxy, bWireframe);
				SetupMeshBatchElement(MeshBatch.Elements[0], Collector);
				Collector.AddMesh(ViewIndex, MeshBatch);

				
				for (Gameint materialIndex = 0; materialIndex < m_arrMaterialInterface.Num(); materialIndex++)
				{
					FMeshBatch& MeshBatchMaterial = Collector.AllocateMesh();
					pMaterialRenderProxy = m_arrMaterialInterface[materialIndex]->GetRenderProxy();//GetMaterialForSection(m_arrBatchedSections[sectionIndex], ViewIndex);//
					if (pMaterialRenderProxy == nullptr || m_arrBatchedSections[sectionIndex].m_pIndexBuffer == nullptr)
					{
						continue;
					}
					SetupMeshBatch(MeshBatchMaterial, m_arrBatchedSections[sectionIndex], pMaterialRenderProxy, false);
					SetupMeshBatchElement(MeshBatchMaterial.Elements[0], Collector);

					Collector.AddMesh(ViewIndex, MeshBatchMaterial);
				}
				
			}
		}
	}
}

Gameuint FSuperMapMeshSceneProxy::GetMemoryFootprint(Gamevoid) const
{
	return (sizeof(*this) + GetAllocatedSize());
}

SIZE_T FSuperMapMeshSceneProxy::GetTypeHash() const
{
	static size_t UniquePointer;

	return reinterpret_cast<size_t>(&UniquePointer);
}

FPrimitiveViewRelevance FSuperMapMeshSceneProxy::GetViewRelevance(const FSceneView* View) const
{
	FPrimitiveViewRelevance Result;
	Result.bDrawRelevance = IsShown(View);
	Result.bShadowRelevance = IsShadowCast(View);
	Result.bDynamicRelevance = true;
	Result.bRenderInMainPass = ShouldRenderInMainPass();
	Result.bUsesLightingChannels = GetLightingChannelMask() != GetDefaultLightingChannelMask();
	Result.bRenderCustomDepth = ShouldRenderCustomDepth();
	Result.bTranslucentSelfShadow = bCastVolumetricTranslucentShadow;
	m_MaterialRelevance.SetPrimitiveViewRelevance(Result);
	Result.bVelocityRelevance = 0;
	return Result;
}
Gamevoid FSuperMapMeshSceneProxy::SetSceneUseMaterialFlag_RenderThread(UseMaterialFlag enUseMaterialFlag)
{
	check(IsInRenderingThread());
	m_enSceneUseMaterialFlag = enUseMaterialFlag;
}
Gamevoid FSuperMapMeshSceneProxy::CreateRenderThreadResources()
{
	m_pCustomVertexBuffer->CreateRenderResources_RenderThread();

	for (Gameint sectionIndex = 0; sectionIndex < m_arrBatchedSections.Num(); sectionIndex++)
	{
		m_arrBatchedSections[sectionIndex].CreateRenderResources_RenderThread();
	}

	if (m_pVertexFactory == nullptr)
	{
		// TODO 这里只没考虑draco压缩，只考虑meshopt
		Gameint nCompressType = m_pCustomVertexBuffer->GetCompressType();
		if (nCompressType > 0)
		{
			if (!GameConvertor::HasCompressOptions(nCompressType, VertexCompressOptions::SVC_TexutreCoord))
			{
				m_pVertexFactory = new FSuperMapMeshOptNoTextureCompressVertexFactory(GetScene().GetFeatureLevel());
			}
			else
			{
				m_pVertexFactory = new FSuperMapMeshOptVertexFactory(GetScene().GetFeatureLevel());
			}
		}
		else if (m_pCustomVertexBuffer->GetInstanceType() == InstanceTpye::IT_MODEL)
		{
			m_pVertexFactory = new FSuperMapModelInstanceVertexFactory(GetScene().GetFeatureLevel());
		}
		else if (m_pCustomVertexBuffer->GetInstanceType() == InstanceTpye::IT_PIPE)
		{
			m_pVertexFactory = new FSuperMapPipeInstanceVertexFactory(GetScene().GetFeatureLevel());
		}
		else
		{
			m_pVertexFactory = new FSuperMapCustomVertexFactory(GetScene().GetFeatureLevel());
		}
	}

	if (m_arrBatchedSections.Num() > 0)
	{
		FSuperMapCustomVertexFactory::CustomMacro ueMacro;
		FSuperMapMaterialMacro& smMacro = m_arrBatchedSections[0].m_MaterialCollection.GetMacros();
		ueMacro.m_nHasMultiTemporalWeight = smMacro.m_bMultiTemporalWeight;
		m_pVertexFactory->SetCustomMacros(ueMacro);
	}

	m_pVertexFactory->SetCustomVertexBuffer(m_pCustomVertexBuffer);
	m_pVertexFactory->InitResource();
}

Gamebool FSuperMapMeshSceneProxy::IsInsideFrustum(const FSceneView* View) const
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

Gamevoid FSuperMapMeshSceneProxy::UpdateUsedMaterial_RenderThread(TArray <UMaterialInterface*> arrUsedMaterials)
{
	check(IsInRenderingThread());

#if WITH_EDITOR
	SetUsedMaterialForVerification(arrUsedMaterials);
#endif
	FMaterialRelevance Result;
	for (Gameint i = 0; i < arrUsedMaterials.Num(); i++)
	{
		UMaterialInterface* MaterialInterface = arrUsedMaterials[i];
		if (!MaterialInterface)
		{
			MaterialInterface = UMaterial::GetDefaultMaterial(MD_Surface);
		}
		Result |= MaterialInterface->GetRelevance_Concurrent(GetScene().GetFeatureLevel());
	}

	m_MaterialRelevance = Result;
}

Gamevoid FSuperMapMeshSceneProxy::SetUseMaterialFlag_RenderThread(UseMaterialFlag enUseMaterialFlag)
{
	check(IsInRenderingThread());
	m_enUseMaterialFlag = enUseMaterialFlag;
}

Gamevoid FSuperMapMeshSceneProxy::SetInternalVisibility_RenderThread(Gamebool visible)
{
	check(IsInRenderingThread());

	m_bVisible = visible;
}

Gamevoid FSuperMapMeshSceneProxy::SetVisibleLayer_RenderThread(Gamebool visible)
{
	check(IsInRenderingThread());

	m_bVisibleLayer = visible;
}

Gamevoid FSuperMapMeshSceneProxy::SetVisibleInViewport_RenderThread(Gameint nIndex, Gamebool visible)
{
	m_bVisibleInViewport[nIndex] = visible;
}

Gamevoid FSuperMapMeshSceneProxy::SetRender_RenderThread(Gamebool render)
{
	check(IsInRenderingThread());

	m_bRender = render;
}

FMaterialRenderProxy* FSuperMapMeshSceneProxy::GetMaterialForSection(const FSuperMapRenderSection& section, Gameint viewIndex) const
{
	UMaterialInterface* pMaterialInterface = nullptr;
	if (viewIndex > 0)
	{
		pMaterialInterface = section.m_MaterialCollection.GetMaterialByUseFlag(UseMaterialFlag::UMF_VIEWPORT);
		//VR才会出现pMaterialInterface == nullptr
		if (pMaterialInterface == nullptr)
		{
			pMaterialInterface = section.m_MaterialCollection.GetMaterialByUseFlag(UseMaterialFlag::UMF_NORMAL);
		}
		// 这个判断是为了让分析结果的对象不在分屏时重复绘制
		if (pMaterialInterface != nullptr && pMaterialInterface->GetMaterial()->GetBaseMaterial()->GetName() == "CommonNoTexture")
		{
			return nullptr;
		}
	}
	else
	{
		if (m_enSceneUseMaterialFlag != UMF_NORMAL)
		{
			pMaterialInterface = section.m_MaterialCollection.GetMaterialByUseFlag(m_enSceneUseMaterialFlag);
		}
		else
		{
			pMaterialInterface = section.m_MaterialCollection.GetMaterialByUseFlag(m_enUseMaterialFlag);
		}
	}
	if (pMaterialInterface != nullptr)
	{
		return pMaterialInterface->GetRenderProxy();
	}
	return nullptr;
}



Gamevoid FSuperMapMeshSceneProxy::AddMaterialInterface(UMaterialInterface* materialInterface)
{
	m_arrMaterialInterface.Add(materialInterface);
}



Gamevoid FSuperMapMeshSceneProxy::RemoveMaterialInterface(UMaterialInterface* materialInterface)
{
	for (Gameint materialIndex = 0; materialIndex < m_arrMaterialInterface.Num(); materialIndex++)
	{

		if (m_arrMaterialInterface[materialIndex] == materialInterface)
		{
			m_arrMaterialInterface.RemoveAt(materialIndex);
			break;
		}

	}
}

Gamevoid FSuperMapMeshSceneProxy::SetupMeshBatch(FMeshBatch& meshBatch, const FSuperMapRenderSection& section, FMaterialRenderProxy* pMaterialRenderProxy, Gamebool bWireframe) const
{
	meshBatch.VertexFactory = m_pVertexFactory;

	FMeshBatchElement& BatchElement = meshBatch.Elements[0];
	BatchElement.FirstIndex = 0;
	BatchElement.MaxVertexIndex = m_pCustomVertexBuffer->m_nVerticesNum - 1;
	BatchElement.MinVertexIndex = 0;
	BatchElement.NumPrimitives = section.m_nPrimitivesNum;
	BatchElement.IndexBuffer = section.m_pIndexBuffer;
	BatchElement.NumInstances = m_pCustomVertexBuffer->m_nInstanceSize;

	meshBatch.Type = section.m_eDrawType;
	meshBatch.bCanApplyViewModeOverrides = false;
	meshBatch.bWireframe = bWireframe;

	meshBatch.DepthPriorityGroup = SDPG_World;
	meshBatch.MaterialRenderProxy = pMaterialRenderProxy;
	meshBatch.ReverseCulling = (IsLocalToWorldDeterminantNegative() || m_bReverseCulling);
}

Gamevoid FSuperMapMeshSceneProxy::SetupMeshBatchElement(FMeshBatchElement& BatchElement, FMeshElementCollector& Collector) const
{
	/*Gamebool bHasPrecomputedVolumetricLightmap;
	FMatrix PreviousLocalToWorld;
	Gameint SingleCaptureIndex;
	Gamebool bOutputVelocity;
	GetScene().GetPrimitiveUniformShaderParameters_RenderThread(GetPrimitiveSceneInfo(), bHasPrecomputedVolumetricLightmap, PreviousLocalToWorld,
																SingleCaptureIndex, bOutputVelocity);

	FDynamicPrimitiveUniformBuffer& DynamicPrimitiveUniformBuffer = Collector.AllocateOneFrameResource<FDynamicPrimitiveUniformBuffer>();

	DynamicPrimitiveUniformBuffer.Set(GetLocalToWorld(), PreviousLocalToWorld, GetBounds(), GetLocalBounds(), true, bHasPrecomputedVolumetricLightmap,
									  DrawsVelocity(), bOutputVelocity);
	BatchElement.PrimitiveUniformBufferResource = &DynamicPrimitiveUniformBuffer.UniformBuffer;*/
	BatchElement.PrimitiveUniformBuffer = GetUniformBuffer();
}

Gamevoid FSuperMapMeshSceneProxy::UpdateMesh_RenderThread(const FSMMesh & smMesh)
{
	check(IsInRenderingThread());
}

Gamevoid FSuperMapMeshSceneProxy::UpdateCustomVertexAttribute0_RenderThread(const FSMMesh& smMesh)
{
	check(IsInRenderingThread());
	if (m_pCustomVertexBuffer != nullptr)
	{
		m_pCustomVertexBuffer->UpdateCustomVertexAttribute0_RenderThread(smMesh);
	}

	delete smMesh.m_pDataVertex;
}

Gamevoid FSuperMapMeshSceneProxy::UpdateVertexColor_RenderThread(const FSMMesh & smMesh)
{
	check(IsInRenderingThread());
	if (m_pCustomVertexBuffer != nullptr)
	{
		m_pCustomVertexBuffer->UpdateVertexColor_RenderThread(smMesh);
	}

	delete smMesh.m_pDataVertex;
}
void FSuperMapMeshSceneProxy::UpdateVertex_RenderThread(const FSMMesh& smMesh)
{
	check(IsInRenderingThread());
	if (m_pCustomVertexBuffer != nullptr)
	{
		m_pCustomVertexBuffer->UpdateVertex_RenderThread(smMesh);
	}

	delete smMesh.m_pDataVertex;
}

Gamevoid FSuperMapMeshSceneProxy::UpdateInstanceVertexColor_RenderThread(Gameuint nColor, TArray<Gameuint> arrIds)
{
	check(IsInRenderingThread());
	if (m_pCustomVertexBuffer != nullptr)
	{
		m_pCustomVertexBuffer->UpdateInstanceVertexColor_RenderThread(nColor, arrIds);
	}
}

#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif
