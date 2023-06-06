#pragma once

#include <memory>

#include "Component/SuperMap_PolyLineMeshComponent.h"
#include "Components/MeshComponent.h"
#include "CoreMinimal.h"
#include "Materials/MaterialInterface.h"
#include "PrimitiveSceneProxy.h"
#include "Component/SuperMap_VertexBuffer.h"
#include "Component/SuperMap_CustomVertexBuffer.h"
#include "Component/SuperMap_CustomVertexFactory.h"
#include "Core/RealspaceDLL.h"

class FSuperMapPolyLineMeshSceneProxy final : public FPrimitiveSceneProxy
{
public:
	FSuperMapPolyLineMeshSceneProxy(const USuperMap_PolyLineMeshComponent* InComponent, FSMMesh& smMesh, const TArray<FSuperMapMaterialInterfaceCollection>& arrMaterialCollection);
	virtual ~FSuperMapPolyLineMeshSceneProxy();

	Gameuint GetAllocatedSize(Gamevoid) const;
	Gamevoid SetUseMaterialFlag_RenderThread(UseMaterialFlag enUseMaterialFlag);
	Gamevoid SetInternalVisibility_RenderThread(Gamebool visible);
	Gamevoid SetVisibleLayer_RenderThread(Gamebool visible);
	Gamevoid SetVisibleInViewport_RenderThread(Gameint nIndex, Gamebool visible);
	Gamevoid SetRender_RenderThread(Gamebool render);
	Gamevoid UpdateMesh_RenderThread(const FSMMesh& smMesh);
	Gamevoid UpdateVertexColor_RenderThread(const FSMMesh& smMesh);
	Gamevoid UpdateInstanceVertexColor_RenderThread(Gameuint nColor, TArray<Gameuint> arrIds);
	Gamevoid UpdateUsedMaterial_RenderThread(TArray <UMaterialInterface*> arrUsedMaterials);
	Gamevoid UpdateSubMesh_RenderThread(TArray<DataIndice*> arrIndices, TArray<FSuperMapMaterialInterfaceCollection> arrMaterialCollection);
	Gamevoid SetReverseCulling_RenderThread(Gamebool bReverseCulling);
#if RHI_RAYTRACING
	Gamevoid InitRayTracingGeometry();
	virtual Gamebool IsRayTracingRelevant() const override { return true; }
	virtual Gamevoid GetDynamicRayTracingInstances(FRayTracingMaterialGatheringContext& Context, TArray<FRayTracingInstance>& OutRayTracingInstances) override final;
#endif
	// FPrimitiveSceneProxy
	Gamebool CanBeOccluded() const override;
	Gamevoid DrawStaticElements(FStaticPrimitiveDrawInterface* PDI) override;
	virtual Gamevoid GetDynamicMeshElements(const TArray<const FSceneView*>& Views,
		const FSceneViewFamily& ViewFamily,
		Gameuint VisibilityMap,
		FMeshElementCollector& Collector) const override;
	Gameuint GetMemoryFootprint(Gamevoid) const override;
	virtual SIZE_T GetTypeHash() const override;
	FPrimitiveViewRelevance GetViewRelevance(const FSceneView* View) const override;

	/**
	 *	Called when the rendering thread adds the proxy to the scene.
	 *	This function allows for generating renderer-side resources.
	 *	Called in the rendering thread.
	 */
	virtual Gamevoid CreateRenderThreadResources() override;

private:
	Gamebool IsInsideFrustum(const FSceneView* View) const;
	FMaterialRenderProxy* GetMaterialForSection(const FSuperMapRenderSection& section, int32 viewIndex) const;
	Gamevoid SetupMeshBatch(FMeshBatch& meshBatch, const FSuperMapRenderSection& section, FMaterialRenderProxy* pMaterialRenderProxy, Gamebool bWireframe) const;
	Gamevoid SetupMeshBatchElement(FMeshBatchElement& BatchElement, FMeshElementCollector& Collector) const;

	Gamebool m_bManualOcclusion;
	Gamebool m_bUseDynamicPath;
	Gamebool m_bVisible;
	Gamebool m_bVisibleLayer;
	Gamebool m_bVisibleInViewport[2];
	Gamebool m_bRender;
	Gamebool m_bReverseCulling;
	UseMaterialFlag m_enUseMaterialFlag;

	FMaterialRelevance  m_MaterialRelevance;

	FSuperMapCustomVertexBuffer* m_pCustomVertexBuffer;
	FSuperMapCustomVertexFactory* m_pVertexFactory;

	TArray<FSuperMapRenderSection> m_arrBatchedSections;

#if RHI_RAYTRACING
	FRayTracingGeometry m_RayTracingGeometry;
#endif
};
