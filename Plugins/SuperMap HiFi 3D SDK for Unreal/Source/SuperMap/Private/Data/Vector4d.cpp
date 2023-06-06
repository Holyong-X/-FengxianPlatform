#include "Data/Vector4d.h"

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{
			Vector4d::Vector4d()
			{

			}

			Vector4d::Vector4d(const Vector4d & vector4d)
			{
				X = vector4d.X;
				Y = vector4d.Y;
				Z = vector4d.Z;
				W = vector4d.W;
			}

			Vector4d::Vector4d(FVector4 other)
			{
				X = other.X;
				Y = other.Y;
				Z = other.Z;
				W = other.W;
			}

			Vector4d::Vector4d(double dX, double dY, double dZ, double dW)
			{
				X = dX;
				Y = dY;
				Z = dZ;
				W = dW;
			}

			Vector4d Vector4d::operator * (const Matrix4d& m)
			{
				double m11 = 0, m12 = 0, m13 = 0, m14 = 0;
				m11 = X * m[0][0] + Y * m[1][0] + Z * m[2][0] + W * m[3][0];
				m12 = X * m[0][1] + Y * m[1][1] + Z * m[2][1] + W * m[3][1];
				m13 = X * m[0][2] + Y * m[1][2] + Z * m[2][2] + W * m[3][2];
				m14 = X * m[0][3] + Y * m[1][3] + Z * m[2][3] + W * m[3][3];
				return Vector4d(m11, m12, m13, m14);
			}

			FVector Vector4d::ToFVector()
			{
				return FVector(X, Y, Z);
			}

			FVector4 Vector4d::ToFVector4()
			{
				return FVector4(X, Y, Z, W);
			}
		}
	}
}