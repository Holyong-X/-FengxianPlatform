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

	//! \brief ���Ƶ�
	Gamevoid DrawPoints(TArray<GeoPoint3D*> arrPoints, Gamebool bReplaceOldPoints = true);
	
	//! \brief ������
	Gamevoid DrawLines(TArray<GeoLine3D*> arrLines, Gamebool bReplaceOldPoints = true);
	
	//! \brief ������
	Gamevoid DrawRegions(TArray<GeoRegion3D*> arrRegions, Gamebool bReplaceOldPoints = true);

	//! \brief �������ʸ������
	Gamevoid Flush();
private:
	//! \brief ����ʸ��
	ULineBatchComponent* m_pLineBatchComponent;

	//! \brief ��
	TArray<GeoPoint3D*> m_vPoints;

	//! \brief ��
	TArray<GeoLine3D*> m_vLines;

	//! \brief ��
	TArray<GeoRegion3D*> m_vRegions;

public:
	//! \brief ��������ԭ��
	Gamevoid UpdateWorldOrigin();

protected:
	//! \brief ���������ƫ��
	virtual Gamevoid ApplyWorldOffset(const FVector& InOffset, Gamebool bWorldShift);
};