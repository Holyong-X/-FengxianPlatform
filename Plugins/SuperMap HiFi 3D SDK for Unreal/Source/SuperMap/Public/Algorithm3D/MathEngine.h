#pragma once

#include "CoreMinimal.h"
#include "Data/Matrix4d.h"
#include "Core/ROCache.h"
#include "Graphics3D/GameEnum.h"
#include "Core/RealspaceDLL.h"
#include "Base3D/CommonDefine.h"
#include "Core/SceneType.h"
using namespace SuperMapSDK::UnrealEngine::Data;
using namespace SuperMapSDK::UnrealEngine::Core;

class UMaterialInstanceDynamic;
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Algorithm3D
		{
			class SUPERMAP_API MathEngine
			{
			public:
				MathEngine();
				~MathEngine();

				//! \brief 地理坐标到笛卡尔坐标
				static FVector SphericalToCartesian(Gamedouble dLongitude, Gamedouble dLatitude, Gamedouble dHeight);
				static Vector3d SphericalToCartesian2(Gamedouble dLongitude, Gamedouble dLatitude, Gamedouble dHeight);

				//! \brief 迪卡儿坐标求地理坐标
				static Vector3d CartesianToSpherical(Gamedouble dX, Gamedouble dY, Gamedouble dZ);

				//! \brief 计算旋转矩阵
				static Matrix4d CalRotation(Gamedouble dLongitude, Gamedouble dLatitude, Gamedouble dAltitude);

				//! \brief 三角剖分
				static Gamebool Triangulate(Gamefloat*& pPoint3Ds, Gameint nPointCount, Gameint nSubCount, Gameint* nPolyCounts, Gameint*& arrIntIndex, Gameint& nCount);

				//! \brief 释放Int
				static Gamevoid FreeUGInt(Gameint*& pIndex);

				//! \brief 释放Gamefloat
				static Gamevoid FreeUGFloat(Gamefloat*& pData);

				//! \brief 释放Gamedouble
				static Gamevoid FreeUGDouble(Gamedouble*& pData);

				//! \brief 水平视场角与垂直视场角转换
				static Gamedouble HorizontalToVerticalFOV(Gamedouble dHFov, Gamedouble dAspect);
				static Gamedouble VerticalToHorizontalFOV(Gamedouble dVFov, Gamedouble dAspect);

				//! \brief UGC视图矩阵转换为UE视图矩阵
				static Gamevoid UGCViewMatrixToUEViewMatrix(Matrix4d &ugcViewMatrix, Matrix4d &ueViewMatrix);
				//! \brief 更新Location和Rotator
				static Gamevoid UpdateRotationAndLocation(FVector &vLocation, FRotator &vRotator, Matrix4d mat4d);
				//! \brief UGC视图矩阵转换为UE坐标及旋转角
				static Gamevoid UGCViewMatrixToUERotationAndLocation(Matrix4d ugcViewMatrix, Vector3d &vLocation, FRotator &vRotator);
				//! \brief 设置Shader矩阵
				static Gamevoid SetShaderMatrixParamter(UMaterialInstanceDynamic* pMID, Matrix4d mat, FString strName);

				//! \brief 场景类型
				static SceneManagerType ConvertToSceneManagerType(int32 nType);
			
				//! \brief 计算Heading和Pitch
				static Gamevoid CalHeadingAndPitch(Gamebool bIsSphere, 
					Gamedouble dPosX, Gamedouble dPosY, Gamedouble dPosZ,
					Gamedouble dDirectionX, Gamedouble dDirectionY, Gamedouble dDirectionZ,
					Gamedouble &dHeading, Gamedouble &dPitch);

				//! \brief 将UGC的矩阵的值的指针转换为UE的矩阵,(XY反转，缩放到厘米)
				static Matrix4d UGCMatrixPtrToUEMatrix4d(Gamedouble* pDoubleObjectMat);

				//! \brief 字符串转Gamelong
				static Gamelong CalHashCodeByChar(FString strName);

				//! \brief 地理坐标到笛卡尔坐标，涉及地理原点计算
				static FVector SphericalToCartesian_GeoOrigin(FVector vPos);

				//! \brief FString转Char(针对长路径字符串)，pChar申请的动态内存需要外部删除
				static Gamevoid FStringToANSIChar(FString Str, ANSICHAR* &pChar);

				//! \brief 折线拐角平滑处理
				//! \brief nFactor平滑参数 nSlice 切片数
				//! \brief bIsSym FALSE 椭圆弧 TRUE 圆弧
				static Gamevoid Chamfer(TArray<Vector3d>& vCurveds, TArray<Vector3d>& vLines, Gameint nFactor, Gamebool bIsSym, Gameint nSlice);

				//! \brief 细分插值点
				//! \brief arrPoints 线原始点
				//! \brief arrLocations 插值后点
				static Gamevoid GetSubdivisionPoints(TArray<FVector>& arrPoints, TArray<FVector>& arrLocations, Gamefloat fDistance);
				static Gamevoid GetSubdivisionPoints2(TArray<Vector3d>& arrPoints, TArray<Vector3d>& arrLocations, Gamefloat fDistance);

				//! \brief 射线与球体相交。
				//! \param vecStart 射线起点[in]。
				//! \param vecDirection 射线方向in]。
				//! \param dRadius 球半径[in]。
				//! \return 二者相交返回TRUE, 否则返回FALSE。
				static Gamebool RayIntersectionWithGlobe(Vector3d vStart, Vector3d vDirection, Vector3d& vIntersect, SceneType sceneType, Gamedouble dRadius);
				
				//! \brief 椭球获取经纬坐标对应的椭球半径
				static Gamedouble GetEllipsoidRadius(Gamedouble dLongitude, Gamedouble dLatitude, Gamedouble dAltitude);

				//! \brief 地球偏移。
				static FVector m_vWorldOffset;
			};
		}
	}
}