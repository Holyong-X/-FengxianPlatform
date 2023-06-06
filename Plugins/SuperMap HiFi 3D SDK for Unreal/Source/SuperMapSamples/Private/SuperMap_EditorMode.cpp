#if WITH_EDITOR
#include "SuperMap_EditorMode.h"
#include "SuperMap_EditorModeToolkit.h"
#include "ControlUE/RealspaceView.h"
#include "Toolkits/ToolkitManager.h"
#include "EditorModeManager.h"

const FEditorModeID FSuperMap_EditorMode::EM_SuperMapEdModeID = TEXT("EM_SuperMapEdMode");

FSuperMap_EditorMode::FSuperMap_EditorMode()
{

}

FSuperMap_EditorMode::~FSuperMap_EditorMode()
{

}

void FSuperMap_EditorMode::Enter()
{
	FEdMode::Enter();

	if (!Toolkit.IsValid() && UsesToolkits())
	{
		Toolkit = MakeShareable(new FSuperMap_EditorModeToolkit);
		Toolkit->Init(Owner->GetToolkitHost());
	}
}

void FSuperMap_EditorMode::Exit()
{
	if (Toolkit.IsValid())
	{
		FToolkitManager::Get().CloseToolkit(Toolkit.ToSharedRef());
		Toolkit.Reset();
	}
	FEdMode::Exit();
}

bool FSuperMap_EditorMode::UsesToolkits() const
{
	return true;
}

bool FSuperMap_EditorMode::InputKey(FEditorViewportClient* ViewportClient, FViewport* Viewport, FKey Key, EInputEvent Event)
{
	// 鼠标左键按下
	if (Key.GetFName() == EKeys::LeftMouseButton && Event == IE_Pressed)
	{
		SuperMapSDK::UnrealEngine::ControlUE::RealspaceView::GetSingleton()->MouseLeftButtonDown();
	}

	// 鼠标左键抬起
	if (Key.GetFName() == EKeys::LeftMouseButton && Event == IE_Released)
	{
		SuperMapSDK::UnrealEngine::ControlUE::RealspaceView::GetSingleton()->MouseLeftButtonUp();
	}
	
	// 鼠标中键按下
	if (Key.GetFName() == EKeys::MiddleMouseButton && Event == IE_Pressed)
	{
		SuperMapSDK::UnrealEngine::ControlUE::RealspaceView::GetSingleton()->MouseMiddleButtonDown();
	}

	// 鼠标中键抬起
	if (Key.GetFName() == EKeys::MiddleMouseButton && Event == IE_Released)
	{
		SuperMapSDK::UnrealEngine::ControlUE::RealspaceView::GetSingleton()->MouseMiddleButtonUp();
	}

	return true;
}

bool FSuperMap_EditorMode::InputAxis(FEditorViewportClient* InViewportClient, FViewport* Viewport, int32 ControllerId, FKey Key, float Delta, float DeltaTime)
{
	if (Key.GetFName() == EKeys::MouseWheelAxis)
	{
		RealspaceView::GetSingleton()->MouseMiddleButtonMove(Delta);
	}

	return true;
}
#endif