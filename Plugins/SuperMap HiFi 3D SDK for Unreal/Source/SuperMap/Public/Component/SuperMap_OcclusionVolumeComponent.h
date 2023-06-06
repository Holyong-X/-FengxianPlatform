#pragma once

#include "CoreMinimal.h"
#include "PrimitiveSceneProxy.h"
#include "Components/PrimitiveComponent.h"
#include "Components/SceneComponent.h"
#include "Base3D/CommonDefine.h"
#include "SuperMap_OcclusionVolumeComponent.generated.h"

using namespace SuperMapSDK;

UCLASS()
class SUPERMAP_API USuperMap_OcclusionVolumeComponent : public UPrimitiveComponent
{
	GENERATED_BODY()

public:
	USuperMap_OcclusionVolumeComponent();
	~USuperMap_OcclusionVolumeComponent();


	FPrimitiveSceneProxy* CreateSceneProxy() override;
	virtual FBoxSphereBounds CalcBounds(const FTransform& LocalToWorld) const override;
	
	//! \brief 获取遮挡查询结果
	Gamebool GetOcclusionResult();

	Gamevoid SetOcclusionResult(Gamebool result);
	
	//! \brief 设置包围盒
	Gamevoid SetBoundingBox(FBox & box);

private:
	FBoxSphereBounds m_LocalBounds;

	FPrimitiveSceneProxy* m_pSceneProxy;

	Gamebool m_bOcculsionResilt;
};