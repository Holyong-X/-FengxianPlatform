#include "Data/Rectangle2D.h"

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{
			Rectangle2D::Rectangle2D()
			{
				Left   = 0.0;
				Right  = 0.0;
				Top    = 0.0;
				Bottom = 0.0;
			}

			Rectangle2D::Rectangle2D(double left, double top, double right, double bottom)
			{
				Left = left;
				Right = right;
				Top = top;
				Bottom = bottom;
			}

			Vector2d Rectangle2D::Center()
			{
				return Vector2d(Left + Width() / 2.0, Bottom + Height() / 2.0);
			}

			Vector2d Rectangle2D::LeftBottom()
			{
				return Vector2d(Left, Bottom);
			}

			Vector2d Rectangle2D::RightTop()
			{
				return Vector2d(Right, Top);
			}

			double Rectangle2D::Width()
			{
				return Right - Left;
			}

			double Rectangle2D::Height()
			{
				return Top - Bottom;
			}
		}
	}
}