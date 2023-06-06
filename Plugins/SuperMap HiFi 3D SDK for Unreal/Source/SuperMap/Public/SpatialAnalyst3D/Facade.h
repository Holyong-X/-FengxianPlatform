#pragma once

#include "CoreMinimal.h"
#include "Core/Analyst3D.h"
#include "Core/SceneType.h"
#include "Core/Scene.h"
#include "ControlUE/CameraControl.h"
#include "Data/Vector3d.h"
#include "Data/Matrix4d.h"
#include "Data/GeoLine3D.h"
#include "Core/RealspaceDLL.h"

using namespace SuperMapSDK::UnrealEngine::Data;

class UWorld;
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
			
			class SUPERMAP_API Facade : public Analyst3D
			{
			public:
				//! \brief ���캯��
				Facade(UWorld* pWorld, Core::Scene* pScene, ControlUE::CameraControl* pCameraControl);
				virtual ~Facade();

				//! \brief ����/��ȡ����ļ�·��
				void SetOutputPath(FString strOutputPath);
				FString GetOutputPath();

				//! \brief ���ù۲���
				void SetViewLine(GeoLine3D* pGeoLine3D);

				//! \brief ���ó�ͼ����
				void SetResolution(Gamedouble dResolution);
				void SetVisibleHeight(Gamedouble dMin, Gamedouble dMax);
				void SetVisibleFarDistance(Gamedouble dFar);

				//! \brief ��ȡ��ͼ����
				Gamedouble GetResolution();
				void GetVisibleHeight(Gamedouble &dMin, Gamedouble &dMax);
				Gamedouble GetVisibleFarDistance();

			protected:
				void DoBuild();

				void DoClear();

				void Render();

				//! \brief �ͷ�
				void Release();
			private:
				//! \brief �۲�·��
				GeoLine3D* m_pGeoLine3D;

				//! \brief ���·��
				FString m_strOutputPath;

				//! \brief ��ͼ�ķֱ���
				Gamedouble m_dResolution;

				//! \brief �ɼ�����С�߶�
				Gamedouble m_dMinHeight;

				//! \brief �ɼ������߶�
				Gamedouble m_dMaxHeight;

				//! \brief �ɼ�����Զ����
				Gamedouble m_dFarDist;

				//! \brief �Ƿ��ͼ
				Gamebool m_bOutput;
			};
		}
	}
}