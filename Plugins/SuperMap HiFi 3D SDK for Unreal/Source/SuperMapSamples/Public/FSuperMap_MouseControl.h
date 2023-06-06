#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

class SUPERMAPSAMPLES_API FSuperMap_MouseControl
{
public:

	FSuperMap_MouseControl();

	virtual ~FSuperMap_MouseControl();

	virtual void MouseLeftButtonDown() = 0;

	virtual void MouseRealTimeAnchor() = 0;

	virtual void MouseRightButtonDown() = 0;
};