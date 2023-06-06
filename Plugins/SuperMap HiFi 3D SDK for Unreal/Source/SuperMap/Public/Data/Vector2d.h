#pragma once
#include "CoreMinimal.h"

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{
			class SUPERMAP_API Vector2d
			{
			public:
				Vector2d();

				Vector2d(FVector2D other);

				Vector2d(double nX, double nY);

				FVector2D ToFVector();

				Vector2d operator -(const Vector2d& other) const;
			public:
				double X;
				double Y;
			};
		}
	}
}