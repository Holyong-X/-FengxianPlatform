#include "Data/Vector2d.h"

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{
			Vector2d::Vector2d()
			{
				X = Y = 0;
			}

			Vector2d::Vector2d(FVector2D other)
			{
				X = other.X;
				Y = other.Y;
			}

			Vector2d::Vector2d(double nX, double nY)
			{
				X = nX;
				Y = nY;
			}

			FVector2D Vector2d::ToFVector()
			{
				return FVector2D(X, Y);
			}

			Vector2d Vector2d::operator - (const Vector2d& other) const
			{
				return Vector2d(X - other.X, Y - other.Y);
			}
		}
	}
}