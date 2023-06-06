#pragma once
#include "CoreMinimal.h"
#include "Core/SceneType.h"
#include "Core/Scene.h"
#include "ControlUE/CameraControl.h"
#include "Data/Vector3d.h"
#include "Core/RealspaceDLL.h"
#include "Component/SuperMap_ROEntityActor.h"

class UWorld;
class ASuperMap_ROEntityActor;
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Render
		{
			class SUPERMAP_API DrawBox
			{
			public:
				//! \brief ¹¹Ôìº¯Êý
				DrawBox();
				~DrawBox();

				static void GetBoundsVector(Vector3d start, Vector3d end, Vector3d& v1, Vector3d& v2, Vector3d& v3, Vector3d& v4,
					Vector3d& v5, Vector3d& v6, Vector3d& v7, Vector3d& v8);
			};
		}
	}
}
