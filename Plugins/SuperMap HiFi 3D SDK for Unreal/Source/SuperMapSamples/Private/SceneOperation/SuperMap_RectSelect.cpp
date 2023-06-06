// Fill out your copyright notice in the Description page of Project Settings.


#include "SceneOperation/SuperMap_RectSelect.h"
#include "ControlUE/RealspaceView.h"

using namespace SuperMapSDK::UnrealEngine::ControlUE;
// Sets default values
ASuperMap_RectSelect::ASuperMap_RectSelect()
{
	PrimaryActorTick.bCanEverTick = true;
}

ASuperMap_RectSelect::~ASuperMap_RectSelect()
{

}

void ASuperMap_RectSelect::BuildRectSelect(bool bRectSelect)
{
	if (bRectSelect)
	{
		RealspaceView::GetSingleton()->GetSceneControl()->GetSceneEditorWnd()->SetAction(RectSelect);
	}
	else
	{
		RealspaceView::GetSingleton()->GetSceneControl()->GetSceneEditorWnd()->SetAction(PanSelect);
	}
}

void ASuperMap_RectSelect::BeginPlay()
{
	Super::BeginPlay();
}

void ASuperMap_RectSelect::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

