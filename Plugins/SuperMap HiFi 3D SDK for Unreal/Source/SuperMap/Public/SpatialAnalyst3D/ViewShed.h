#pragma once
#include "CoreMinimal.h"
#include "Core/Analyst3D.h"
#include "Core/RealspaceDLL.h"
#include "Core/SceneType.h"
#include "Core/Scene.h"
#include "ControlUE/CameraControl.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Data/Matrix4d.h"
#include "Data/GeoModel3D.h"

using namespace SuperMapSDK::UnrealEngine::Data;

class UWorld;
class ASuperMap_ROEntityActor;
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			class Scene;
		}

		namespace ControlUE
		{
			class CameraControl;
		}

		namespace SpatialAnalyst3D
		{
			class SUPERMAP_API ViewShed : public Core::Analyst3D
			{
			public:
				//! \brief 构造函数
				ViewShed(UWorld* pWorld, Core::Scene* pScene, ControlUE::CameraControl* pCameraControl);
				virtual ~ViewShed();

			public:
				//! \brief 设置可见区域颜色
				void SetVisibleAreaColor(const FVector4& color);

				//! \brief 获取可见区域颜色
				FVector4 GetVisibleAreaColor();

				//! \brief 设置隐藏区域颜色
				void SetHiddenAreaColor(const FVector4& color);

				//! \brief 获取隐藏区域颜色
				FVector4 GetHiddenAreaColor();

				//! \brief 设置视点位置
				void SetViewerPosition(FVector pos);

				//! \brief 获取视点位置
				FVector GetViewerPosition() const;

				//! \brief 设置视线方向
				void SetDirection(double dir);

				//! \brief 获取视线方向
				double GetDirection();

				//! \brief 设置倾斜角度
				void SetPitch(double pitch);

				//! \brief 获取倾斜角度
				double GetPitch();

				//! \brief 设置水平视角
				void SetHorizontalFov(double fov);

				//! \brief 获取水平视角
				double GetHorizontalFov();

				//! \brief 设置垂直视角
				void SetVerticalFov(double fov);

				//! \brief 获取垂直视角
				double GetVerticalFov();

				//! \brief 设置可视距离
				void SetDistance(double dist);

				//! \brief 获取可视距离
				double GetDistance();

				//! \brief 通过辅助点设置分析相机方向和距离
				void SetDistDirByPoint(const FVector& point);

				//! \brief 获取可见区域体
				GeoModel3D* GetViewShedVisibleBody();

				//! \brief 获取不可见区域体
				GeoModel3D* GetViewShedHiddenBody();

				//! \brief 获取障碍点
				TArray<Vector3d> GetBarrierPoints();

				//! \brief 设置名字
				void SetName(FString name);
				FString GetName();

				void* GetHandler();
			public:
				//! \brief 设置纹理矩阵
				void SetMatrix(UMaterialInstanceDynamic* pMID, Matrix4d mat, FString strTex);

				//! \brief 对材质更新着色器参数
				// bNewMaterial 是否是新创建的材质
				void UpdateUniformsForMaterial(UMaterialInstanceDynamic* pMat, bool bNewMaterial);
			protected:
				void DoBuild();

				void DoClear();

				void Render();

				//! \brief 释放
				void Release();

			private:
				void UpdateCamera();

				void UpdateShaderUniforms();
			private:
				//! \brief 可见区域颜色
				FVector4 m_VisibleAreaColor;

				//! \brief 不可见区域颜色
				FVector4 m_HiddenAreaColor;

				// 分析相机方向角
				double m_Direction;

				// 分析相机方向角
				double m_Pitch;

				// 分析相机水平张角
				double m_HorizontalFov;

				// 分析相机垂直张角
				double m_VerticalFov;

				// 最远分析距离
				double m_Distance;

				// 观察点坐标
				FVector m_vViewerPosition;

				//! \brief 深度相机视图矩阵
				Matrix4d m_matDepthViewMatrix;
				//! \brief 深度相机投影矩阵
				Matrix4d m_matDepthPrjMatrix;
				//! \brief 深度相机的视图投影矩阵
				Matrix4d m_matRenderTextureMat;
				//! \brief 将主场景相机坐标系转换为分析相机的相机坐标系
				Matrix4d m_matMainViewPosToDepthViewPos;

				// 深度图相机的视图投影矩阵
				Matrix4d m_matDepthCameraViewProj;

				double m_dNearClip;
				double m_dFarClip;

				// 参数更新
				bool m_bUpdate;

				// 是否开启
				bool m_bEnable;

				void* m_pUGViewShed;

				FVector m_vRealViewPos;
			};
		}
	}
}