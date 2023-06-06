#include "Component/SuperMap_PolyLineMeshSceneProxy.h"

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

FSuperMapPolyLineMeshSceneProxy::FSuperMapPolyLineMeshSceneProxy(const USuperMap_PolyLineMeshComponent* InComponent, FSMMesh& smMesh, const TArray<FSuperMapMaterialInterfaceCollection>& arrMaterialCollection)
	: FPrimitiveSceneProxy(InComponent),
	m_enUseMaterialFlag(UMF_NORMAL),
	m_MaterialRelevance(InComponent->GetMaterialRelevance(GetScene().GetFeatureLevel())),
	m_pVertexFactory(nullptr)
{
	m_bUseDynamicPath = true;
	m_bVisible = InComponent->GetInternalVisibility();
	m_bVisibleLayer = InComponent->GetLayerVisibility();
	m_bVisibleInViewport[0] = true;
	m_bVisibleInViewport[1] = true;
	m_bRender = true;
	m_bReverseCulling = InComponent->GetReverseCulling();

	m_pCustomVertexBuffer = new FSuperMapCustomVertexBuffer();
	m_pCustomVertexBuffer->SetMesh(smMesh);

	check(smMesh.m_arrDataIndex.Num() == arrMaterialCollection.Num());

	m_arrBatchedSections.SetNum(smMesh.m_arrDataIndex.Num());
	for (int i = 0; i < m_arrBatchedSections.Num(); i++)
	{
		int x = smMesh.m_arrDataIndex[i]->m_nOperationType;
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

FSuperMapPolyLineMeshSceneProxy::~FSuperMapPolyLineMeshSceneProxy()
{
	if (m_pCustomVertexBuffer != nullptr)
	{
		delete m_pCustomVertexBuffer;
		m_pCustomVertexBuffer = nullptr;
	}

	for (int i = 0; i < m_arrBatchedSections.Num(); i++)
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

bool FSuperMapPolyLineMeshSceneProxy::CanBeOccluded() const
{
	return !m_MaterialRelevance.bDisableDepthTest;
}

void FSuperMapPolyLineMeshSceneProxy::DrawStaticElements(FStaticPrimitiveDrawInterface* PDI)
{
	if (m_bUseDynamicPath)
	{
		return;
	}
	for (int i = 0; i < m_arrBatchedSections.Num(); i++)
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

uint32 FSuperMapPolyLineMeshSceneProxy::GetAllocatedSize(void) const
{
	return (FPrimitiveSceneProxy::GetAllocatedSize());
}

#if RHI_RAYTRACING
void FSuperMapPolyLineMeshSceneProxy::InitRayTracingGeometry()
{
}

void FSuperMapPolyLineMeshSceneProxy::GetDynamicRayTracingInstances(FRayTracingMaterialGatheringContext& Context, TArray<FRayTracingInstance>& OutRayTracingInstances)
{
}
#endif

void FSuperMapPolyLineMeshSceneProxy::UpdateSubMesh_RenderThread(TArray<DataIndice*> arrIndices, TArray<FSuperMapMaterialInterfaceCollection> arrMaterialCollection)
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

void FSuperMapPolyLineMeshSceneProxy::SetReverseCulling_RenderThread(Gamebool bReverseCulling)
{
	check(IsInRenderingThread());

	m_bReverseCulling = bReverseCulling;
}

void FSuperMapPolyLineMeshSceneProxy::GetDynamicMeshElements(const TArray<const FSceneView*>& Views,
	const FSceneViewFamily& ViewFamily,
	uint32 VisibilityMap,
	FMeshElementCollector& Collector) const
{
	// Set up wireframe material (if needed)
	const bool bWireframe = AllowDebugViewmodes() && ViewFamily.EngineShowFlags.Wireframe;

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

	for (int32 ViewIndex = 0; ViewIndex < Views.Num(); ViewIndex++)
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

			for (int sectionIndex = 0; sectionIndex < m_arrBatchedSections.Num(); sectionIndex++)
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
			}
		}
	}
}

uint32 FSuperMapPolyLineMeshSceneProxy::GetMemoryFootprint(void) const
{
	return (sizeof(*this) + GetAllocatedSize());
}

SIZE_T FSuperMapPolyLineMeshSceneProxy::GetTypeHash() const
{
	static size_t UniquePointer;

	return reinterpret_cast<size_t>(&UniquePointer);
}

FPrimitiveViewRelevance FSuperMapPolyLineMeshSceneProxy::GetViewRelevance(const FSceneView* View) const
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

void FSuperMapPolyLineMeshSceneProxy::CreateRenderThreadResources()
{
	m_pCustomVertexBuffer->CreateRenderResources_RenderThread();

	for (int sectionIndex = 0; sectionIndex < m_arrBatchedSections.Num(); sectionIndex++)
	{
		m_arrBatchedSections[sectionIndex].CreateRenderResources_RenderThread();
	}

	if (m_pVertexFactory == nullptr)
	{
		m_pVertexFactory = new FSuperMapPloyLineVertexFactory(GetScene().GetFeatureLevel());
	}

	m_pVertexFactory->SetCustomVertexBuffer(m_pCustomVertexBuffer);
	m_pVertexFactory->InitResource();
}

bool FSuperMapPolyLineMeshSceneProxy::IsInsideFrustum(const FSceneView* View) const
{
	auto bounds = GetBounds();
	float radius = bounds.SphereRadius;

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

void FSuperMapPolyLineMeshSceneProxy::UpdateUsedMaterial_RenderThread(TArray <UMaterialInterface*> arrUsedMaterials)
{
	check(IsInRenderingThread());

#if WITH_EDITOR
	SetUsedMaterialForVerification(arrUsedMaterials);
#endif
	FMaterialRelevance Result;
	for (int32 i = 0; i < arrUsedMaterials.Num(); i++)
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

void FSuperMapPolyLineMeshSceneProxy::SetUseMaterialFlag_RenderThread(UseMaterialFlag enUseMaterialFlag)
{
	check(IsInRenderingThread());
	m_enUseMaterialFlag = enUseMaterialFlag;
}

void FSuperMapPolyLineMeshSceneProxy::SetInternalVisibility_RenderThread(bool visible)
{
	check(IsInRenderingThread());

	m_bVisible = visible;
}

void FSuperMapPolyLineMeshSceneProxy::SetVisibleLayer_RenderThread(bool visible)
{
	check(IsInRenderingThread());

	m_bVisibleLayer = visible;
}

void FSuperMapPolyLineMeshSceneProxy::SetVisibleInViewport_RenderThread(int nIndex, bool visible)
{
	m_bVisibleInViewport[nIndex] = visible;
}

void FSuperMapPolyLineMeshSceneProxy::SetRender_RenderThread(bool render)
{
	check(IsInRenderingThread());

	m_bRender = render;
}

FMaterialRenderProxy* FSuperMapPolyLineMeshSceneProxy::GetMaterialForSection(const FSuperMapRenderSection& section, int32 viewIndex) const
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
		pMaterialInterface = section.m_MaterialCollection.GetMaterialByUseFlag(m_enUseMaterialFlag);
	}
	if (pMaterialInterface != nullptr)
	{
		return pMaterialInterface->GetRenderProxy();
	}
	return nullptr;
}

void FSuperMapPolyLineMeshSceneProxy::SetupMeshBatch(FMeshBatch& meshBatch, const FSuperMapRenderSection& section, FMaterialRenderProxy* pMaterialRenderProxy, bool bWireframe) const
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

void FSuperMapPolyLineMeshSceneProxy::SetupMeshBatchElement(FMeshBatchElement& BatchElement, FMeshElementCollector& Collector) const
{
	/*bool bHasPrecomputedVolumetricLightmap;
	FMatrix PreviousLocalToWorld;
	int32 SingleCaptureIndex;
	bool bOutputVelocity;
	GetScene().GetPrimitiveUniformShaderParameters_RenderThread(GetPrimitiveSceneInfo(), bHasPrecomputedVolumetricLightmap, PreviousLocalToWorld,
																SingleCaptureIndex, bOutputVelocity);

	FDynamicPrimitiveUniformBuffer& DynamicPrimitiveUniformBuffer = Collector.AllocateOneFrameResource<FDynamicPrimitiveUniformBuffer>();

	DynamicPrimitiveUniformBuffer.Set(GetLocalToWorld(), PreviousLocalToWorld, GetBounds(), GetLocalBounds(), true, bHasPrecomputedVolumetricLightmap,
									  DrawsVelocity(), bOutputVelocity);
	BatchElement.PrimitiveUniformBufferResource = &DynamicPrimitiveUniformBuffer.UniformBuffer;*/
	BatchElement.PrimitiveUniformBuffer = GetUniformBuffer();
}

void FSuperMapPolyLineMeshSceneProxy::UpdateMesh_RenderThread(const FSMMesh& smMesh)
{
	check(IsInRenderingThread());
}

void FSuperMapPolyLineMeshSceneProxy::UpdateVertexColor_RenderThread(const FSMMesh& smMesh)
{
	check(IsInRenderingThread());
	if (m_pCustomVertexBuffer != nullptr)
	{
		m_pCustomVertexBuffer->UpdateVertexColor_RenderThread(smMesh);
	}

	delete smMesh.m_pDataVertex;
}

void FSuperMapPolyLineMeshSceneProxy::UpdateInstanceVertexColor_RenderThread(Gameuint nColor, TArray<uint32> arrIds)
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
