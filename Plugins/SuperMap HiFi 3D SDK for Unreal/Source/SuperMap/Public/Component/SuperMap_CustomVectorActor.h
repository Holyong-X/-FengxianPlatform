#pragma once

#include "CoreMinimal.h"
#include "Components/LineBatchComponent.h"
#include "Base3D/CommonDefine.h"
#include "Data/Vector3d.h"
#include "Data/GeoPoint3D.h"
#include "Data/GeoLine3D.h"
#include "Data/GeoRegion3D.h"
#include "SuperMap_CustomVectorActor.generated.h"

using namespace SuperMapSDK;
using namespace SuperMapSDK::UnrealEngine::Core;
using namespace SuperMapSDK::UnrealEngine::Data;
using namespace SuperMapSDK::UnrealEngine::ControlUE;
UCLASS()
class SUPERMAP_API ASuperMap_CustomVectorActor : public AActor
{
	GENERATED_BODY()

public:
	ASuperMap_CustomVectorActor();
	virtual ~ASuperMap_CustomVectorActor();

	//! \brief 绘制点
	Gamevoid DrawPoints(TArray<GeoPoint3D*> arrPoints, Gamebool bReplaceOldPoints = true);
	
	//! \brief 绘制线
	Gamevoid DrawLines(TArray<GeoLine3D*> arrLines, Gamebool bReplaceOldPoints = true);
	
	//! \brief 绘制面
	Gamevoid DrawRegions(TArray<GeoRegion3D*> arrRegions, Gamebool bReplaceOldPoints = true);

	//! \brief 清楚所有矢量对象
	Gamevoid Flush();
private:
	//! \brief 绘制矢量
	ULineBatchComponent* m_pLineBatchComponent;

	//! \brief 点
	TArray<GeoPoint3D*> m_vPoints;

	//! \brief 线
	TArray<GeoLine3D*> m_vLines;

	//! \brief 面
	TArray<GeoRegion3D*> m_vRegions;

public:
	//! \brief 更新世界原点
	Gamevoid UpdateWorldOrigin();

protected:
	//! \brief 世界坐标的偏移
	virtual Gamevoid ApplyWorldOffset(const FVector& InOffset, Gamebool bWorldShift);
};