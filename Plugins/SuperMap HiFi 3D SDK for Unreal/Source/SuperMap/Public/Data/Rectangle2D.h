#pragma once
#include "CoreMinimal.h"
#include "Data/Vector2d.h"

using namespace SuperMapSDK::UnrealEngine::Data;
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{
			class SUPERMAP_API Rectangle2D
			{
			public:
				Rectangle2D();
				Rectangle2D(double left, double top, double right, double bottom);

				Data::Vector2d Center();

				Data::Vector2d LeftBottom();

				Data::Vector2d RightTop();

				double Width();

				double Height();

			public:
				double Left;
				double Right;
				double Top;
				double Bottom;
			};
		}
	}
}