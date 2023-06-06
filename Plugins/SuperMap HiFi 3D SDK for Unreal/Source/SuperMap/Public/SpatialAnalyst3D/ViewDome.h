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
					//! \brief ��ʾ��ģʽ
					LINE,
					//! \brief ��ʾ��ģʽ
					FACE,
					//! \brief ��ʾ����ģʽ
					FACELINE,
				};

				//! \brief �պ�������
				enum DomeType
				{
					//! \brief ���Ӳ���
					VisibleDome,
					//! \brief �����Ӳ���
					HiddenDome,
				};

				//! \brief ���캯��
				ViewDome(UWorld* pWorld, Core::Scene* pScene, ControlUE::CameraControl* pCameraControl);
				virtual ~ViewDome();

			public:
				//! \brief ��ȡ��ɫ����
				FVector4 GetViewDomeColor();

				//! \brief ������ɫ����
				void SetViewDomeColor(const FVector4& color);

				//! \brief ��ȡ�߿���ɫ����
				FVector4 GetViewDomeLineColor();

				//! \brief �����߿���ɫ����
				void SetViewDomeLineColor(const FVector4& color);

				//! \brief �����ӵ�λ��
				void SetViewerPosition(FVector pos);

				//! \brief ��ȡ�ӵ�λ��
				FVector GetViewerPosition() const;

				//! \brief ��ȡ���Ӿ�������
				Gamedouble GetViewDomeDistance();

				//! \brief ���ÿ��Ӿ�������
				void SetViewDomeDistance(Gamedouble viewDistance);

				//! \brief ��ȡ�����ȵĽ�����ͣ���ʾ���ӡ������Ӳ��֣�
				ViewDome::DomeType GetDomeType();

				//! \brief ���ÿ����ȵĽ������
				void SetDomeType(ViewDome::DomeType modeType);

				//! \brief ��ȡ�����ȵ���ʾģʽ���ߣ���䣬�ϣ�
				ViewDome::DisplayMode GetViewDomeDisplayStyle();

				//! \brief ���ÿ����ȵ���ʾģʽ
				void SetViewDomeDisplayStyle(ViewDome::DisplayMode displayStyle);

				//! \brief ��ȡ�����ȷ�������
				Gamedouble GetViewDomeRatio();

			protected:
				void DoBuild();

				void DoClear();

				void Render();

				//! \brief �ͷ�
				void Release();
			private:
				void UpdateCamera();

				void UpdateShaderUniforms();

				//! \brief �����������
				void SetMatrix(UMaterialInstanceDynamic* pMID, Matrix4d mat, FString strTex);
			public:
				//! \brief �Բ��ʸ�����ɫ������
				// bNewMaterial �Ƿ����´����Ĳ���
				void UpdateUniformsForMaterial(UMaterialInstanceDynamic* pMat, bool bNewMaterial);
			private:
				//! \brief ��ɫ
				FVector4 m_Color;

				//! \brief ����ɫ
				FVector4 m_LineColor;

				FVector m_vViewerPosition;

				//! \brief ��������ͼ����
				TArray<Matrix4d> m_matDepthViewMatrixs;
				//! \brief ������ͶӰ����
				TArray<Matrix4d> m_matDepthPrjMatrixs;

				// ��������
				Gamebool m_bUpdate;

				// �Ƿ���
				Gamebool m_bEnable;

				Gamedouble m_dDistance;

				ViewDome::DomeType m_eDomeType;

				ViewDome::DisplayMode m_eDisplayMode;

				void* m_pUGViewDome;
			};
		}
	}
}