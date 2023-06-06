#include "Data/Vector3d.h"
#include "Data/Matrix4d.h"
#include "Base3D/CommonDefine.h"

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{
			Vector3d::Vector3d()
			{
				X = Y = Z = 0;
			}

			Vector3d::Vector3d(FVector other)
			{
				X = other.X;
				Y = other.Y;
				Z = other.Z;
			}

			Vector3d::Vector3d(double nx, double ny, double nz)
			{
				X = nx;
				Y = ny;
				Z = nz;
			}

			Vector3d::Vector3d(FIntVector other)
			{
				X = other.X;
				Y = other.Y;
				Z = other.Z;
			}
			double Vector3d::sqrMagnitude()
			{
				return X * X + Y * Y + Z * Z;
			}

			double Vector3d::Magnitude()
			{
				return sqrt(X * X + Y * Y + Z * Z);
			}

			Vector3d Vector3d::Normalize()
			{
				double dLength = sqrt(X * X + Y * Y + Z * Z);
				return Vector3d(X / dLength, Y / dLength, Z / dLength);
			}

			bool Vector3d::IsZeroLength()
			{
				return ((X * X + Y * Y + Z * Z) < 1e-20);
			}

			Vector3d& Vector3d::MultiplyMatrix(const Matrix4d& m)
			{
				double dW = 1;
				double dM11 = 0, dM12 = 0, dM13 = 0, dM14 = 0;

				dM11 = X * m[0][0] + Y * m[1][0] + Z * m[2][0] + dW * m[3][0];
				dM12 = X * m[0][1] + Y * m[1][1] + Z * m[2][1] + dW * m[3][1];
				dM13 = X * m[0][2] + Y * m[1][2] + Z * m[2][2] + dW * m[3][2];
				dM14 = X * m[0][3] + Y * m[1][3] + Z * m[2][3] + dW * m[3][3];

				X = dM11;
				Y = dM12;
				Z = dM13;

				return *this;
			}

			Vector3d Vector3d::Perpendicular(Vector3d other)
			{
				Vector3d TempVector = Vector3d(X,Y,Z);
				Vector3d perp = Cross(TempVector, other);
				if (perp.IsZeroLength())
				{
					perp = Cross(TempVector, Vector3d(0.0, 0.0, 1.0));
					if (perp.IsZeroLength())
					{
						perp = Cross(TempVector, Vector3d(0.0, 1.0, 0.0));
					}
				}

				perp.Normalize();
				return perp;
			}

			Vector3d Vector3d::ToUGCVector()
			{
				Vector3d vTempVector = Vector3d();
				vTempVector.X = Y * CM_TO_M;
				vTempVector.Y = X * CM_TO_M;
				vTempVector.Z = Z * CM_TO_M;

				return vTempVector;
			}

			Vector3d Vector3d::Cross(Vector3d from, Vector3d to)
			{
				Vector3d TempVector = Vector3d();
				TempVector.X = from.Y * to.Z - from.Z * to.Y;
				TempVector.Y = from.Z * to.X - from.X * to.Z;
				TempVector.Z = from.X * to.Y - from.Y * to.X;
				
				return TempVector;
			}

			bool Vector3d::operator == (const Vector3d& other) const
			{
				return (X == other.X && Y == other.Y && Z == other.Z);
			}

			bool Vector3d::operator != (const Vector3d& other) const
			{
				return (X != other.X || Y != other.Y || Z != other.Z);
			}

			Vector3d Vector3d::operator - (const Vector3d& other) const
			{
				Vector3d result = Vector3d();
				result.X = X - other.X;
				result.Y = Y - other.Y;
				result.Z = Z - other.Z;
				return result;
			}

			Vector3d& Vector3d::operator -= (const Vector3d& other)
			{
				X = X - other.X;
				Y = Y - other.Y;
				Z = Z - other.Z;
				return *this;
			}

			Vector3d Vector3d::operator + (const Vector3d& other) const
			{
				return Vector3d(X+ other.X, Y+ other.Y, Z+ other.Z);
			}

			Vector3d& Vector3d::operator+=(const Vector3d & other)
			{
				X = X + other.X;
				Y = Y + other.Y;
				Z = Z + other.Z;
				return *this;
			}

			Vector3d Vector3d::operator * (double other) const
			{
				return Vector3d(X*other,Y*other,Z*other);
			}

			Vector3d& Vector3d::operator *= (double other)
			{
				X = X * other;
				Y = Y * other;
				Z = Z * other;
				return *this;
			}

			Vector3d Vector3d::operator / (double other) const
			{
				return Vector3d(X / other, Y / other, Z / other);
			}

			double Vector3d::Dot(Vector3d lhs, Vector3d rhs)
			{
				return lhs.X * rhs.X + lhs.Y * rhs.Y + lhs.Z * rhs.Z;
			}

			double Vector3d::Angle(Vector3d from, Vector3d to)
			{
				double angle = 0.0;
				double dLen0 = from.Magnitude();
				double dLen1 = to.Magnitude();
				//下面是通用方法, 但有时计算误差特别大
				double dLenProduct = dLen0 * dLen1;
				double dCos = Dot(from, to) / dLenProduct;
				double max = 1, min = -1;
				dCos = FMath::Max(FMath::Min(dCos, max), min);
				angle = FMath::RadiansToDegrees(cos(dCos));
				return angle;
			}

			FVector Vector3d::ToFVector()
			{
				return FVector(X,Y,Z);
			}

			Gamebool Vector3d::operator >(const Vector3d& other)
			{
				if (FMath::Abs(X) > other.X || FMath::Abs(Y) > other.Y || FMath::Abs(Z) > other.Z)
				{
					return true;
				}

				return false;
			}

			Gamedouble Vector3d::Distance(Vector3d other)
			{
				Gamedouble result = sqrt((X - other.X)*(X - other.X) + (Y - other.Y)*(Y - other.Y) + (Z - other.Z)*(Z - other.Z));
				return result;
			}
		}
	}
}