#pragma once
#include "CoreMinimal.h"
#include "Data/Matrix4d.h"

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{
			class SUPERMAP_API Vector4d
			{
			public:
				Vector4d();
				Vector4d(const Vector4d & vector4d);
				Vector4d(FVector4 other);
				Vector4d(double dX, double dY, double dZ, double dW);

				//! \brief ���صĳ˷�������������һ������Ľ��
				Vector4d operator * (const Matrix4d& m);

				FVector  ToFVector();
				FVector4 ToFVector4();
			public:
				double X;
				double Y;
				double Z;
				double W;
			};
		}
	}
}