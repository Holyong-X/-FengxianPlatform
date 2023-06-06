#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "Camera/CameraTypes.h"
#include "Base3D/CommonDefine.h"
#include "Components/SceneCaptureComponent2D.h"
#include "SuperMap_CaptureSceneActor.generated.h"
using namespace SuperMapSDK;
UCLASS(BlueprintType, Blueprintable)
class  ASuperMap_CaptureSceneActor : public ACameraActor
{
	GENERATED_BODY()
public:
	ASuperMap_CaptureSceneActor();
	~ASuperMap_CaptureSceneActor();
public:
	Gamevoid SetRenderMode(ESceneCapturePrimitiveRenderMode eRenderMode);
	Gamevoid SetShowOnlyComponentList(TArray<UPrimitiveComponent*> & arrComponents);
	Gamevoid SetHidderActors(TArray<AActor*> & arrActors);
	Gamevoid SetOrthWidth(Gamefloat fWidth);
	Gamevoid SetProjectionType(TEnumAsByte<ECameraProjectionMode::Type> eProjectionType);
	Gamevoid SetProjectionMatrix(FMatrix matrix);
	Gamevoid SetCaptureSource(ESceneCaptureSource source);
	Gamevoid SetRenderTarget(UTextureRenderTarget2D* pRenderTarget);
	Gamevoid CaptureScene();
private:
	USceneCaptureComponent2D* m_pSceneCaptureCom;
};