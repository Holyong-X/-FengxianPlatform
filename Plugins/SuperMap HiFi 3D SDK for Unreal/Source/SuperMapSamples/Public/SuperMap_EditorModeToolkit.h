#pragma once

#include "CoreMinimal.h"
#if WITH_EDITOR
#include "Toolkits/BaseToolkit.h"

class FSuperMap_EditorModeToolkit : public FModeToolkit
{
public:

	FSuperMap_EditorModeToolkit();

	/** FModeToolkit interface */
	virtual void Init(const TSharedPtr<IToolkitHost>& InitToolkitHost) override;

	/** IToolkit interface */
	virtual FName GetToolkitFName() const override;
	virtual FText GetBaseToolkitName() const override;
	virtual class FEdMode* GetEditorMode() const override;
	virtual TSharedPtr<class SWidget> GetInlineContent() const override { return ToolkitWidget; }

private:

	TSharedPtr<SWidget> ToolkitWidget;
};
#endif