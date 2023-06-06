#include "Component/SuperMap_OcclusionVolumeComponent.h"

class FOcclusionVolumeSceneProxy : public FPrimitiveSceneProxy {
public:
    FOcclusionVolumeSceneProxy(USuperMap_OcclusionVolumeComponent* pComponent)
        : FPrimitiveSceneProxy(pComponent /*, name?*/) 
    {
        pComm = pComponent;
        m_bOcclusion = false;
    }
    SIZE_T GetTypeHash() const override {
        static size_t UniquePointer;
        return reinterpret_cast<size_t>(&UniquePointer);
    }

    Gamebool CanBeOccluded() const
    {
        return !m_MaterialRelevance.bDisableDepthTest;
    }

    Gamevoid GetDynamicMeshElements(const TArray<const FSceneView*>& Views,
        const FSceneViewFamily& ViewFamily,
        Gameuint VisibilityMap,
        FMeshElementCollector& Collector) const
    {
        for (Gameint ViewIndex = 0; ViewIndex < Views.Num(); ViewIndex++)
        {
            if ((VisibilityMap & (1 << ViewIndex)))
            {
                //m_bOcclusion = true;
                pComm->SetOcclusionResult(false);
                return;
            }
        }
        pComm->SetOcclusionResult(true);
    }

    Gamebool GetOcclusionResult() { return m_bOcclusion; }

    FPrimitiveViewRelevance GetViewRelevance(const FSceneView* View) const
    {
        FPrimitiveViewRelevance Result;
        Result.bDrawRelevance = IsShown(View);
        Result.bShadowRelevance = IsShadowCast(View);
        Result.bDynamicRelevance = true;
        Result.bStaticRelevance = false;
        Result.bRenderInMainPass = ShouldRenderInMainPass();
        Result.bUsesLightingChannels = GetLightingChannelMask() != GetDefaultLightingChannelMask();
        Result.bRenderCustomDepth = ShouldRenderCustomDepth();
        Result.bTranslucentSelfShadow = bCastVolumetricTranslucentShadow;
        m_MaterialRelevance.SetPrimitiveViewRelevance(Result);
        Result.bVelocityRelevance = 0;
        return Result;
    }

    Gameuint GetMemoryFootprint(Gamevoid) const override {
        return sizeof(FOcclusionVolumeSceneProxy) + GetAllocatedSize();
    }

private:
    // 是否已经执行遮挡剔除
    Gamebool m_bOcclusion;

    FMaterialRelevance  m_MaterialRelevance;

    USuperMap_OcclusionVolumeComponent* pComm;
};

USuperMap_OcclusionVolumeComponent::USuperMap_OcclusionVolumeComponent()
{
    m_pSceneProxy = nullptr;
    m_bOcculsionResilt = true;
}

Gamevoid USuperMap_OcclusionVolumeComponent::SetOcclusionResult(Gamebool result)
{
    m_bOcculsionResilt = result;
}

USuperMap_OcclusionVolumeComponent::~USuperMap_OcclusionVolumeComponent()
{

}

FPrimitiveSceneProxy* USuperMap_OcclusionVolumeComponent::CreateSceneProxy()
{
    m_pSceneProxy = new FOcclusionVolumeSceneProxy(this);
    return m_pSceneProxy;
}

Gamebool USuperMap_OcclusionVolumeComponent::GetOcclusionResult()
{
    if (m_pSceneProxy && !IsRenderStateDirty())
    {
        return ((FOcclusionVolumeSceneProxy*)m_pSceneProxy)->GetOcclusionResult();
    }

    return false;
}

FBoxSphereBounds USuperMap_OcclusionVolumeComponent::CalcBounds(const FTransform& LocalToWorld) const
{
    FBoxSphereBounds Ret = m_LocalBounds.TransformBy(LocalToWorld);

    Ret.BoxExtent *= BoundsScale;
    Ret.SphereRadius *= BoundsScale;

    return Ret;
}

Gamevoid USuperMap_OcclusionVolumeComponent::SetBoundingBox(FBox& box)
{
    m_LocalBounds = FBoxSphereBounds(box);
}
