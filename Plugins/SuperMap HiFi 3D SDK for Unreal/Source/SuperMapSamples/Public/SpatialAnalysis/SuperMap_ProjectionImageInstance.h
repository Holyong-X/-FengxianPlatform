#pragma once

#include "SuperMap_MainActor.h"
#include "ControlUE/RealspaceView.h"
#include "SpatialAnalyst3D/ProjectionImage.h"
#include "Algorithm3D/MathEngine.h"
#include "Base3D/CommonDefine.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SuperMap_ProjectionImageInstance.generated.h"

using namespace SuperMapSDK::UnrealEngine::SpatialAnalyst3D;
using namespace SuperMapSDK::UnrealEngine::Core;
using namespace SuperMapSDK::UnrealEngine::ControlUE;
using namespace SuperMapSDK::UnrealEngine::Algorithm3D;

UCLASS()
class SUPERMAPSAMPLES_API ASuperMap_ProjectionImageInstance : public AActor, public FSuperMap_MouseControl
{
	GENERATED_BODY()

public:

	ASuperMap_ProjectionImageInstance();
	~ASuperMap_ProjectionImageInstance();
private:
	void MouseLeftButtonDown();

	void MouseRightButtonDown();

	void MouseRealTimeAnchor();

public:
	//! \brief �Ƿ�����Ͷ��
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ProjectionImageInstance")
	void SetIsProjectionImage(bool bViewShed);

	//! \brief ����XML
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ProjectionImageInstance")
	void SetProjectionImageInfos(FString strFileName);

	//! \brief ��������λ��
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ProjectionImageInstance")
	void BuildProjectionImage();

	//! \brief �����ӵ�λ��
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ProjectionImageInstance")
	void SetViewerPosition(FVector vPos);

	//! \brief �������߷���
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ProjectionImageInstance")
	void SetHeading(float dDir);

	//! \brief ������б�Ƕ�
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ProjectionImageInstance")
	void SetPitch(float dPitch);

	//! \brief �����Ӿ�
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ProjectionImageInstance")
	void SetHintLineLength(float dLength);

	//! \brief Ͷ��ͼƬ
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ProjectionImageInstance")
	UTexture2D* GetTexture2DFromDiskFile(FString FilePath);
private:
	void SetCurrentCameraAttribute(ProjectionImage* pProjection);

private:
	//! \brief ��������
	FName m_strAnalyst3DName;

	//! \brief �Ƿ���з���
	Gamebool m_bProjectionImage;

	//! \brief ��������������
	Gameint m_nMouseLeftDown;

	Gamefloat m_fHintLineLength;

	Gamebool m_bCustom;
};
