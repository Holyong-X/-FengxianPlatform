#pragma once

#include <memory>

#include "Component/SuperMap_LineMeshComponent.h"
#include "CoreMinimal.h"
#include "Materials/MaterialInterface.h"
#include "PrimitiveSceneProxy.h"
#include "Component/SuperMap_LineVertexBuffer.h"
#include "Component/SuperMap_LineVertexFactory.h"
//#include "Core/RealspaceDLL.h"
#include "Graphics3D/GameStruct.h"


class FSuperMapLineMeshSceneProxy final : public FPrimitiveSceneProxy
{
public:
	FSuperMapLineMeshSceneProxy(const USuperMap_LineMeshComponent* InComponent, FSMMesh& smMesh);
	virtual ~FSuperMapLineMeshSceneProxy();

	Gamevoid UpdateMesh(const TArray<SM_Vertex>& arrVertex, const TArray<SM_SubMesh>& arrSubMesh);

	Gameuint GetAllocatedSize(Gamevoid) const;
	Gamevoid SetInternalVisibility_RenderThread(Gamebool visible);
	Gamevoid SetVisibleLayer_RenderThread(Gamebool visible);
	Gamevoid SetVisibleInViewport_RenderThread(int nIndex, Gamebool visible);
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
	Gamevoid SetupMeshBatch(FMeshBatch& meshBatch, FMaterialRenderProxy* material, Gamebool bWireframe) const;
	Gamevoid SetupMeshBatchElement(FMeshBatchElement& BatchElement, FMeshElementCollector& Collector) const;

	Gamebool m_bUseDynamicPath;
	Gamebool m_bVisible;
	Gamebool m_bVisibleLayer;
	Gamebool m_bVisibleInViewport[2];
	Gamebool m_bRender;

	UMaterialInterface* m_pMaterialInterface;
	FMaterialRelevance  m_MaterialRelevance;

	TArray<SM_Vertex> m_arrVertex;
	TArray<SM_SubMesh> m_arrSubMesh;

	FSuperMapLineVertexBuffer* m_pVertexBuffer;
	FSuperMapEdgeLineVertexFactory* m_pVertexFactory;

#if RHI_RAYTRACING
	FRayTracingGeometry m_RayTracingGeometry;
#endif
};
