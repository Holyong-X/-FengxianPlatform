#pragma once

#include "CoreMinimal.h"
#include "SceneType.h"
#include "Data/Vector3d.h"
#include "Data/Matrix4d.h"

using namespace SuperMapSDK::UnrealEngine::Data;
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			class SUPERMAP_API Georeference
			{
			public:
				Georeference();
				~Georeference();
			public:
				// 设置地理参考原点
				static void SetGeoreferenceOrigin(double dLongitude, double dLatitude, double dAltitude);

				// 设置世界对象
				static void SetWorld(UWorld* pWorld);

				static const Matrix4d& GetGeoreferenceToECEF();
				static const Matrix4d& GetECEFtoGeoreference();

				static const Matrix4d& GetUeAbsToECEF();
				static const Matrix4d& GetECEFtoUeAbs();

				// 将UE的模型ECEF变换矩阵，转换为模型到UE的渲染坐标系的矩阵
				static Matrix4d TransformECEFToUERelative(const Matrix4d& localToECEF);

				// 将UE的模型ECEF变换矩阵，转换为模型到UE的渲染坐标系的矩阵
				static void TransformECEFToUERelative(const Matrix4d& localToECEF, FTransform& transform);

				// 将UE相对坐标转换到UE绝对坐标
				static Vector3d TransformUERelativeToUEAbs(Vector3d vUEPos);

				// 将UE绝对坐标转换到UE相对坐标
				static Vector3d TransformUEAbsToUERelative(Vector3d vUEAbsPos);

				// 将UE的渲染坐标系点变换到球心为(0,0,0) ECEF的坐标点(输出单位为米)
				static Vector3d TransformUERelativeToOriginECEF(Vector3d vUEPos);
				static void TransformUERelativeToOriginECEF(Vector3d &vUEPos, FRotator &rRotate);

				// 将球心为(0,0,0) ECEF的坐标点 转换到UE的渲染坐标系点
				static Vector3d TransformOriginECEFToUEReative(Vector3d vECEF);

				// 将UE的渲染坐标系点变换到球心为地理原点 ECEF的坐标点(输入为厘米，输出单位为米)
				static Vector3d TransformUERelativeToGeorefenceECEF(Vector3d vUEPos);

				// 将UE的绝对坐标变换到地理原点ECEF 的坐标点(输入为厘米，输出单位为米)
				static Vector3d TransformUEAbsToGeorefenceECEF(Vector3d vUEAbsPos);

				// 将地理原点 ECEF坐标转换为UE的渲染坐标系点（输入为米，输出为厘米）
				static Vector3d TransformGeorefenceECEFToUERelative(Vector3d vGeoECEF);

				// 将UE ECEF 坐标系点变换到UGC ECEF坐标系
				static Vector3d TransformUEECEFToUGCECEF(Vector3d vUEPos);

				static void Reset();
			public:
				static double m_dLongitude;
				static double m_dLatitude;
				static double m_dAltitude;
			private:
				static Matrix4d m_georeferenceToECEF;
				static Matrix4d m_ECEFtoGeoreference;
				static Matrix4d m_ueAbsToECEF;
				static Matrix4d m_ECEFtoUeAbs;

				//! \brief 世界场景对象
				static UWorld* m_pWorld;
			};
		}
	}
}