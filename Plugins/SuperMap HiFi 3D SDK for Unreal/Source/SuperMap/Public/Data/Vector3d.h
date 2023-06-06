#pragma once
#include "CoreMinimal.h"
#include "Base3D/CommonDefine.h"
class UWorld;

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{
			class Matrix4d;
			class SUPERMAP_API Vector3d
			{
			public:
				Vector3d();
				Vector3d(FVector other);
				Vector3d(double nx, double ny, double nz);
				Vector3d(FIntVector other);
				//! \brief 平方
				double sqrMagnitude();

				//! \brief 平方根
				double Magnitude();

				//! \brief 单位向量
				Vector3d Normalize();

				//! \brief 长度为0
				bool IsZeroLength();

				//! \brief 矩阵
				Vector3d& MultiplyMatrix(const Matrix4d& m);

				//! \brief 
				Vector3d Perpendicular(Vector3d other);

				//! \brief UGC向量
				Vector3d ToUGCVector();

				//! \brief 两点距离
				Gamedouble Distance(Vector3d other);

				static double Dot(Vector3d lhs, Vector3d rhs);

				static double Angle(Vector3d from, Vector3d to);

				static Vector3d Cross(Vector3d from, Vector3d to);

				bool operator == (const Vector3d& other) const;

				bool operator != (const Vector3d& other) const;

				Vector3d operator - (const Vector3d& other) const;

				Vector3d& operator -= (const Vector3d& other);

				Vector3d operator + (const Vector3d& other) const;

				Vector3d& operator += (const Vector3d& other);

				Vector3d operator * (double other) const;

				Vector3d& operator *= (double other);

				Vector3d operator / (double other) const;

				Gamebool operator >(const Vector3d& other);

				FVector ToFVector();
			public:
				Gamedouble X;
				Gamedouble Y;
				Gamedouble Z;
			};
		}
	}
}