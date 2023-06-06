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
				//! \brief ���캯��
				ProjectionImage(UWorld* pWorld, Core::Scene* pScene, ControlUE::CameraControl* pCameraControl);
				virtual ~ProjectionImage();

			public:
				//! \brief �����ӵ�λ��
				void SetViewerPosition(Vector3d pos);

				//! \brief ��ȡ�ӵ�λ��
				Vector3d GetViewerPosition();

				//! \brief �������߷���
				void SetHeading(double dDir);

				//! \brief ��ȡ���߷���
				double GetHeading();

				//! \brief ������б�Ƕ�
				void SetPitch(double dPitch);

				//! \brief ��ȡ��б�Ƕ�
				double GetPitch();

				//! \brief ����ͬ����׼��
				void SetAffineMatrix(Vector3d v3X, Vector3d v3Y);

				//! \brief ��ȡͬ����׼��
				void GetAffineMatrix(Vector3d &v3X, Vector3d &v3Y);

				//! \biref ��ȡ/�����Ƿ�ʹ��ͬ����׼��
				void SetIsHomnymyPoints(bool bUsed);
				bool IsHomnymyPoints();

				//! \brief ����Ͷ����Ϣ
				bool ProjectionToXML(FString strFileName);

				//! \brief ��ȡͶ����Ϣ
				bool ProjectionFromXML(FString strFileName);

				//! \brief ����ͶӰͼƬ
				void SetImageData(UTexture2D* pImage);

				//! \brief �������
				void SetHintLineLength(Gamedouble dLength);
			public:

				//! \brief �Բ��ʸ�����ɫ������
				// bNewMaterial �Ƿ����´����Ĳ���
				void UpdateUniformsForMaterial(UMaterialInstanceDynamic* pMat, bool bNewMaterial);
			protected:
				void DoBuild();

				void DoClear();

				void Render();

				//! \brief �ͷ�
				void Release();

			private:
				void UpdateCamera();

				void UpdateShaderUniforms();
			private:

				// ������������
				double m_Direction;

				// ������������
				double m_Pitch;

				// �۲������
				Vector3d m_vViewerPosition;

				//! \brief ��������ͼ����
				Matrix4d m_matDepthViewMatrix;
				//! \brief ������ͶӰ����
				Matrix4d m_matDepthPrjMatrix;
				//! \brief ����������ͼͶӰ����
				Matrix4d m_matRenderTextureMat;
				//! \brief ���������������ϵת��Ϊ����������������ϵ
				Matrix4d m_matMainViewPosToDepthViewPos;

				// ���ͼ�������ͼͶӰ����
				Matrix4d m_matDepthCameraViewProj;

				double m_dNearClip;
				double m_dFarClip;

				// ��������
				bool m_bUpdate;

				// �Ƿ���
				bool m_bEnable;

				// ͶӰ����
				UTexture2D* m_pProjectionTexture;

				// UGC����
				void* m_pUGProjectionImage;

			};
		}
	}
}