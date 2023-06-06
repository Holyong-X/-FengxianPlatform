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
	//! \brief 是否视屏投放
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ProjectionImageInstance")
	void SetIsProjectionImage(bool bViewShed);

	//! \brief 传入XML
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ProjectionImageInstance")
	void SetProjectionImageInfos(FString strFileName);

	//! \brief 放置视屏位置
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ProjectionImageInstance")
	void BuildProjectionImage();

	//! \brief 设置视点位置
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ProjectionImageInstance")
	void SetViewerPosition(FVector vPos);

	//! \brief 设置视线方向
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ProjectionImageInstance")
	void SetHeading(float dDir);

	//! \brief 设置倾斜角度
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ProjectionImageInstance")
	void SetPitch(float dPitch);

	//! \brief 设置视距
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ProjectionImageInstance")
	void SetHintLineLength(float dLength);

	//! \brief 投放图片
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ProjectionImageInstance")
	UTexture2D* GetTexture2DFromDiskFile(FString FilePath);
private:
	void SetCurrentCameraAttribute(ProjectionImage* pProjection);

private:
	//! \brief 分析名字
	FName m_strAnalyst3DName;

	//! \brief 是否进行分析
	Gamebool m_bProjectionImage;

	//! \brief 鼠标左键按键次数
	Gameint m_nMouseLeftDown;

	Gamefloat m_fHintLineLength;

	Gamebool m_bCustom;
};
