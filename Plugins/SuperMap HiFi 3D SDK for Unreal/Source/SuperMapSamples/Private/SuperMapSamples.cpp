// Copyright Epic Games, Inc. All Rights Reserved.

#include "SuperMapSamples.h"
#include "ControlUE/RealspaceView.h"
#if WITH_EDITOR
#include "SuperMap_EditorMode.h"
#include "UnrealEd/Public/EditorModeRegistry.h"
#endif
#define LOCTEXT_NAMESPACE "FSuperMapSamplesModule"

using namespace SuperMapSDK::UnrealEngine::ControlUE;

void FSuperMapSamplesModule::StartupModule()
{
#if WITH_EDITOR
	FEditorModeRegistry::Get().RegisterMode<FSuperMap_EditorMode>(FSuperMap_EditorMode::EM_SuperMapEdModeID, LOCTEXT("SuperMapEdModelName", "SuperMapEdMode"), FSlateIcon(), true);
#endif
}

void FSuperMapSamplesModule::ShutdownModule()
{
	RealspaceView::GetSingleton()->DestroySingleton();
#if WITH_EDITOR
	FEditorModeRegistry::Get().UnregisterMode(FSuperMap_EditorMode::EM_SuperMapEdModeID);
#endif
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FSuperMapSamplesModule, SuperMapSamples)
