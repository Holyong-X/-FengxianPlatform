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
			typedef void(*ProfileGetImageEvent)(void* pActor);

			struct SUPERMAP_API ProfileGetImageCallBack
			{
			public:
				void* m_pActor;
				//触发事件
				ProfileGetImageEvent Event;
			public:
				ProfileGetImageCallBack()
				{
					m_pActor = nullptr;
				}
				void Execute()
				{
					if (m_pActor == nullptr)
					{
						return;
					}
					Event(m_pActor);
				}
			};

			class SUPERMAP_API Profile : public Core::Analyst3D
			{
			public:
				//! \brief 构造函数
				Profile(UWorld* pWorld, Core::Scene* pScene, ControlUE::CameraControl* pCameraControl);
				virtual ~Profile();

			public:
				//! \brief 设置剖面的高度
				//! \remarks 单位是米
				void SetExtendHeight(double height);
				double GetExtendHeight();

				//! \brief 设置剖面线分析的起始点
				void SetStartPoint3D(Vector3d vPoint);
				Vector3d GetStartPoint3D();

				//! \brief 设置剖面线分析的结束点
				void SetEndPoint3D(Vector3d vPoint);
				Vector3d GetEndPoint3D();

				//! \brief 获取剖面图纹理左上点对应的三维位置
				Vector3d GetLeftTopPosition();

				//! \brief 获取剖面图纹理右下点对应的三维位置
				Vector3d GetRightBottomPosition();

				UTexture2D* GetImageData();

				void CallFunc_ProfileInstance(void* pActor, ProfileGetImageEvent QAEvent);
			protected:
				void DoBuild();

				void DoClear();

				void Render();

				//! \brief 释放
				void Release();
			private:
				void OutputProfileToImageData(UTexture2D* & pTexture2D);
			private:

				// 是否开启
				Gamebool m_bEnable;

				void* m_pUGProfile;

				UTexture2D* m_pTexture2D;

				//回调事件结构体
				ProfileGetImageCallBack m_ProfileGetImageEvent;
			};
		}
	}
}