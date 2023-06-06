//////////////////////////////////////////////////////////////////////////                                         
//!  \file Skyline.h
//!  \brief ʵ�ֻ�������ߺ�����߷�����
//!  \details
//!  \attention ����߷�����������ߣ��ڶ�����߽��з���ǰ���������������
//////////////////////////////////////////////////////////////////////////
#pragma once
#include "CoreMinimal.h"
#include "Core/Analyst3D.h"
#include "Core/SceneType.h"
#include "Core/Scene.h"
#include "ControlUE/CameraControl.h"
#include "Data/Vector3d.h"
#include "Data/GeoLine3D.h"
#include "Data/GeoLine.h"
#include "Data/Matrix4d.h"
#include "Core/RealspaceDLL.h"
#include "Data/GeoModel3D.h"

using namespace SuperMapSDK::UnrealEngine::Data;
using namespace SuperMapSDK::UnrealEngine::Core;

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
			class SUPERMAP_API Skyline : public Core::Analyst3D
			{
			public:
				//! \brief ���캯��
				Skyline(UWorld* pWorld, Core::Scene* pScene, ControlUE::CameraControl* pCameraControl);
				virtual ~Skyline();

				//! \brief ����/��ȡ���ߵ�ˮƽ����,����Ϊ0
				void SetViewerDirection(const double direction);
				double GetViewerDirection();

				//! \brief ����/��ȡ���ߵĸ����Ƕȣ�ˮƽ����Ϊ0
				void SetViewerPitch(const double pitch);
				double GetViewerPitch();

				//! \brief ���û�ȡ����߰뾶
				void SetRadius(double dRadius);
				double GetRadius();

				//! \brief �����������ɫ
				void SetSkylineColor(const FColor& color);
				FColor GetSkylineColor() const;

				//! \brief ���ù۲��λ��
				void SetViewerPosition(Vector3d vPos);

				//! \brief ��ȡ�۲��λ��
				Vector3d GetViewerPosition();

				//! \brief ��ȡ��ά�������
				GeoLine* GetSkyline2D();

				//! \brief ��ȡ�����
				GeoLine3D* GetSkyline(double dRadius);

				//! \brief ��ȡ�������
				//! \brief ���������߶�
				GeoModel3D* GetSkylineSectorBody(double dHeight);

				//! \brief ��ȡ������ϰ�������ͼ��ͽ���id
				TMap<Gameint, TArray<Gameint>> GetObjectIDs();
			protected:
				void DoBuild();

				void DoClear();

				void Render();

				//! \brief �ͷ�
				void Release();

				//! \brief ���������
				void CreateSkyline3D(GeoLine3D* pGeoLine3D);

			private:
				//! \brief ʵʱ������(�����״̬)
				ASuperMap_ROEntityActor* m_pSkylineActor;
			private:

				//! \brief �������ɫ
				FColor m_skylineColor;

				//! \brief �Ƿ���������
				bool m_bUpdateSkyline;

				//! \brief UGC����
				void* m_pSkyline;
			};
		}
	}
}