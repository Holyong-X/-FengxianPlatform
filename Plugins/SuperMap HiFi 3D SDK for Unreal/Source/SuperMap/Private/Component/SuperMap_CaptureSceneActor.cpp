#include "Component/SuperMap_CaptureSceneActor.h"

ASuperMap_CaptureSceneActor::ASuperMap_CaptureSceneActor()
{
	PrimaryActorTick.bCanEverTick = false;
	// 创建一个场景捕捉器
	m_pSceneCaptureCom = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("CaptureAna2D"));
	m_pSceneCaptureCom->SetupAttachment(RootComponent);
	m_pSceneCaptureCom->FOVAngle = 60.0;
	m_pSceneCaptureCom->bCaptureEveryFrame = 0;
	m_pSceneCaptureCom->bCaptureOnMovement = 0;
	m_pSceneCaptureCom->ShowFlags.SetFog(false);
	m_pSceneCaptureCom->ShowFlags.SetAtmosphere(false);
	m_pSceneCaptureCom->ShowFlags.SetAmbientOcclusion(false);
	m_pSceneCaptureCom->CompositeMode = ESceneCaptureCompositeMode::SCCM_Overwrite;
}

ASuperMap_CaptureSceneActor::~ASuperMap_CaptureSceneActor()
{

}

Gamevoid ASuperMap_CaptureSceneActor::SetRenderMode(ESceneCapturePrimitiveRenderMode eRenderMode)
{
	m_pSceneCaptureCom->PrimitiveRenderMode = eRenderMode;
}

Gamevoid ASuperMap_CaptureSceneActor::SetHidderActors(TArray<AActor*> & arrActors)
{
	m_pSceneCaptureCom->HiddenActors = arrActors;
}

Gamevoid ASuperMap_CaptureSceneActor::SetShowOnlyComponentList(TArray<UPrimitiveComponent*> & arrComponents)
{
	Gameint nCount = arrComponents.Num();
	for (Gameint i = 0; i < nCount; i++)
	{
		m_pSceneCaptureCom->ShowOnlyComponent(arrComponents[i]);
	}
}

Gamevoid ASuperMap_CaptureSceneActor::SetCaptureSource(ESceneCaptureSource source)
{
	m_pSceneCaptureCom->CaptureSource = source;
}

Gamevoid ASuperMap_CaptureSceneActor::SetOrthWidth(Gamefloat fWidth)
{
	m_pSceneCaptureCom->OrthoWidth = fWidth;
}

Gamevoid ASuperMap_CaptureSceneActor::SetProjectionType(TEnumAsByte<ECameraProjectionMode::Type> eProjectionType)
{
	m_pSceneCaptureCom->ProjectionType = eProjectionType;
}

Gamevoid ASuperMap_CaptureSceneActor::SetProjectionMatrix(FMatrix matrix)
{
	m_pSceneCaptureCom->bUseCustomProjectionMatrix = true;
	m_pSceneCaptureCom->CustomProjectionMatrix = matrix;
}

Gamevoid ASuperMap_CaptureSceneActor::SetRenderTarget(UTextureRenderTarget2D* pRenderTarget)
{
	m_pSceneCaptureCom->TextureTarget = pRenderTarget;
}

Gamevoid ASuperMap_CaptureSceneActor::CaptureScene()
{
	m_pSceneCaptureCom->CaptureScene();
}