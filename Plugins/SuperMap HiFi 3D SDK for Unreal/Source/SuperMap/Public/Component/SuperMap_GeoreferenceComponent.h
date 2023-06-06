#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Data/Vector3d.h"
#include "Data/Matrix4d.h"
#include "Core/RealspaceDLL.h"
#include "SuperMap_GeoreferenceComponent.generated.h"

using namespace SuperMapSDK::UnrealEngine::Data;

/**
* 这个组件用来挂接到actor上，可以使这个actor与场景中加载的其他地理数据相对位置正确。
* 当这个组件的所有者actor使用UE的机制进行位置变换后，这个组件对应的地理坐标也会相应的改变。
* 通过修改组件的地理坐标也可以把对应的actor变换到指定的地理位置上。
*/
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SUPERMAP_API USuperMap_GeoreferenceComponent : public USceneComponent
{
	GENERATED_BODY()
public:
	USuperMap_GeoreferenceComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(Gamefloat DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//! \breif 经度
	UPROPERTY(EditAnywhere, Category = "SuperMap_GeoreferenceComponent")
	double Longitude = 0.0;

	//! \breif 纬度
	UPROPERTY(EditAnywhere, Category = "SuperMap_GeoreferenceComponent")
	double Latitude = 0.0;

	//! \breif 高度
	UPROPERTY(EditAnywhere, Category = "SuperMap_GeoreferenceComponent")
	double Height = 0.0;

private:
	Gamedouble m_dOriginLongitude;
	Gamedouble m_dOriginLatitude;
	Gamedouble m_dOriginHeight;
	Vector3d m_vLastGeoreferenceOrigin;

	Gamevoid LongitudeLatitudeToUE();
};