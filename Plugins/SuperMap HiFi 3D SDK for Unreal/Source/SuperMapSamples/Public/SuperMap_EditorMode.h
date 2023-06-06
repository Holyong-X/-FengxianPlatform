#pragma once
#include "CoreMinimal.h"
#if WITH_EDITOR
#include "UnrealEd/Public/EdMode.h"

class FSuperMap_EditorMode : public FEdMode
{
public:
	const static FEditorModeID EM_SuperMapEdModeID;

public:
	FSuperMap_EditorMode();
	virtual ~FSuperMap_EditorMode();

	// FEdMode Interface
	virtual void Enter() override;
	virtual void Exit() override;
	bool UsesToolkits() const override;
	// End of FEdMode Interface

	virtual bool InputKey(FEditorViewportClient* ViewportClient, FViewport* Viewport, FKey Key, EInputEvent Event);
	virtual bool InputAxis(FEditorViewportClient* InViewportClient, FViewport* Viewport, int32 ControllerId, FKey Key, float Delta, float DeltaTime);
};
#endif