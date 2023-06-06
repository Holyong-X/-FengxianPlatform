#pragma once

#include "CoreMinimal.h"
#include "Core/Analyst3D.h"
#include "Core/SceneType.h"
#include "Core/Scene.h"
#include "ControlUE/CameraControl.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Data/Vector3d.h"
#include "Data/Matrix4d.h"
#include "Data/GeoModel3D.h"
#include "Core/RealspaceDLL.h"

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
			
			class SUPERMAP_API ProjectionImage : public Analyst3D
			{
			public:
				//! \brief 构造函数
				ProjectionImage(UWorld* pWorld, Core::Scene* pScene, ControlUE::CameraControl* pCameraControl);
				virtual ~ProjectionImage();

			public:
				//! \brief 设置视点位置
				void SetViewerPosition(Vector3d pos);

				//! \brief 获取视点位置
				Vector3d GetViewerPosition();

				//! \brief 设置视线方向
				void SetHeading(double dDir);

				//! \brief 获取视线方向
				double GetHeading();

				//! \brief 设置倾斜角度
				void SetPitch(double dPitch);

				//! \brief 获取倾斜角度
				double GetPitch();

				//! \brief 设置同名配准点
				void SetAffineMatrix(Vector3d v3X, Vector3d v3Y);

				//! \brief 获取同名配准点
				void GetAffineMatrix(Vector3d &v3X, Vector3d &v3Y);

				//! \biref 获取/设置是否使用同名配准点
				void SetIsHomnymyPoints(bool bUsed);
				bool IsHomnymyPoints();

				//! \brief 保存投放信息
				bool ProjectionToXML(FString strFileName);

				//! \brief 读取投放信息
				bool ProjectionFromXML(FString strFileName);

				//! \brief 设置投影图片
				void SetImageData(UTexture2D* pImage);

				//! \brief 设置深度
				void SetHintLineLength(Gamedouble dLength);
			public:

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

				// 分析相机方向角
				double m_Direction;

				// 分析相机方向角
				double m_Pitch;

				// 观察点坐标
				Vector3d m_vViewerPosition;

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

				// 投影纹理
				UTexture2D* m_pProjectionTexture;

				// UGC对象
				void* m_pUGProjectionImage;

			};
		}
	}
}