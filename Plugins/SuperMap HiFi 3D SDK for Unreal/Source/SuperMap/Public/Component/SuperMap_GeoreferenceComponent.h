#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Data/Vector3d.h"
#include "Data/Matrix4d.h"
#include "Core/RealspaceDLL.h"
#include "SuperMap_GeoreferenceComponent.generated.h"

using namespace SuperMapSDK::UnrealEngine::Data;

/**
* �����������ҽӵ�actor�ϣ�����ʹ���actor�볡���м��ص����������������λ����ȷ��
* ����������������actorʹ��UE�Ļ��ƽ���λ�ñ任����������Ӧ�ĵ�������Ҳ����Ӧ�ĸı䡣
* ͨ���޸�����ĵ�������Ҳ���԰Ѷ�Ӧ��actor�任��ָ���ĵ���λ���ϡ�
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

	//! \breif ����
	UPROPERTY(EditAnywhere, Category = "SuperMap_GeoreferenceComponent")
	double Longitude = 0.0;

	//! \breif γ��
	UPROPERTY(EditAnywhere, Category = "SuperMap_GeoreferenceComponent")
	double Latitude = 0.0;

	//! \breif �߶�
	UPROPERTY(EditAnywhere, Category = "SuperMap_GeoreferenceComponent")
	double Height = 0.0;

private:
	Gamedouble m_dOriginLongitude;
	Gamedouble m_dOriginLatitude;
	Gamedouble m_dOriginHeight;
	Vector3d m_vLastGeoreferenceOrigin;

	Gamevoid LongitudeLatitudeToUE();
};