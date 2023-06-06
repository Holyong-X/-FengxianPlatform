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
#include "Base3D/CommonDefine.h"

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
			class SUPERMAP_API ViewDome : public Core::Analyst3D
			{
			public:
				enum DisplayMode
				{
					//! \brief 显示线模式
					LINE,
					//! \brief 显示面模式
					FACE,
					//! \brief 显示线面模式
					FACELINE,
				};

				//! \brief 闭合体类型
				enum DomeType
				{
					//! \brief 可视部分
					VisibleDome,
					//! \brief 不可视部分
					HiddenDome,
				};

				//! \brief 构造函数
				ViewDome(UWorld* pWorld, Core::Scene* pScene, ControlUE::CameraControl* pCameraControl);
				virtual ~ViewDome();

			public:
				//! \brief 获取颜色属性
				FVector4 GetViewDomeColor();

				//! \brief 设置颜色属性
				void SetViewDomeColor(const FVector4& color);

				//! \brief 获取线框颜色属性
				FVector4 GetViewDomeLineColor();

				//! \brief 设置线框颜色属性
				void SetViewDomeLineColor(const FVector4& color);

				//! \brief 设置视点位置
				void SetViewerPosition(FVector pos);

				//! \brief 获取视点位置
				FVector GetViewerPosition() const;

				//! \brief 获取可视距离属性
				Gamedouble GetViewDomeDistance();

				//! \brief 设置可视距离属性
				void SetViewDomeDistance(Gamedouble viewDistance);

				//! \brief 获取开敞度的结果类型（显示可视、不可视部分）
				ViewDome::DomeType GetDomeType();

				//! \brief 设置开敞度的结果类型
				void SetDomeType(ViewDome::DomeType modeType);

				//! \brief 获取开敞度的显示模式（线，填充，合）
				ViewDome::DisplayMode GetViewDomeDisplayStyle();

				//! \brief 设置开敞度的显示模式
				void SetViewDomeDisplayStyle(ViewDome::DisplayMode displayStyle);

				//! \brief 获取开敞度分析比例
				Gamedouble GetViewDomeRatio();

			protected:
				void DoBuild();

				void DoClear();

				void Render();

				//! \brief 释放
				void Release();
			private:
				void UpdateCamera();

				void UpdateShaderUniforms();

				//! \brief 设置纹理矩阵
				void SetMatrix(UMaterialInstanceDynamic* pMID, Matrix4d mat, FString strTex);
			public:
				//! \brief 对材质更新着色器参数
				// bNewMaterial 是否是新创建的材质
				void UpdateUniformsForMaterial(UMaterialInstanceDynamic* pMat, bool bNewMaterial);
			private:
				//! \brief 颜色
				FVector4 m_Color;

				//! \brief 线颜色
				FVector4 m_LineColor;

				FVector m_vViewerPosition;

				//! \brief 深度相机视图矩阵
				TArray<Matrix4d> m_matDepthViewMatrixs;
				//! \brief 深度相机投影矩阵
				TArray<Matrix4d> m_matDepthPrjMatrixs;

				// 参数更新
				Gamebool m_bUpdate;

				// 是否开启
				Gamebool m_bEnable;

				Gamedouble m_dDistance;

				ViewDome::DomeType m_eDomeType;

				ViewDome::DisplayMode m_eDisplayMode;

				void* m_pUGViewDome;
			};
		}
	}
}