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
				//! \brief ���캯��
				ViewShed(UWorld* pWorld, Core::Scene* pScene, ControlUE::CameraControl* pCameraControl);
				virtual ~ViewShed();

			public:
				//! \brief ���ÿɼ�������ɫ
				void SetVisibleAreaColor(const FVector4& color);

				//! \brief ��ȡ�ɼ�������ɫ
				FVector4 GetVisibleAreaColor();

				//! \brief ��������������ɫ
				void SetHiddenAreaColor(const FVector4& color);

				//! \brief ��ȡ����������ɫ
				FVector4 GetHiddenAreaColor();

				//! \brief �����ӵ�λ��
				void SetViewerPosition(FVector pos);

				//! \brief ��ȡ�ӵ�λ��
				FVector GetViewerPosition() const;

				//! \brief �������߷���
				void SetDirection(double dir);

				//! \brief ��ȡ���߷���
				double GetDirection();

				//! \brief ������б�Ƕ�
				void SetPitch(double pitch);

				//! \brief ��ȡ��б�Ƕ�
				double GetPitch();

				//! \brief ����ˮƽ�ӽ�
				void SetHorizontalFov(double fov);

				//! \brief ��ȡˮƽ�ӽ�
				double GetHorizontalFov();

				//! \brief ���ô�ֱ�ӽ�
				void SetVerticalFov(double fov);

				//! \brief ��ȡ��ֱ�ӽ�
				double GetVerticalFov();

				//! \brief ���ÿ��Ӿ���
				void SetDistance(double dist);

				//! \brief ��ȡ���Ӿ���
				double GetDistance();

				//! \brief ͨ�����������÷����������;���
				void SetDistDirByPoint(const FVector& point);

				//! \brief ��ȡ�ɼ�������
				GeoModel3D* GetViewShedVisibleBody();

				//! \brief ��ȡ���ɼ�������
				GeoModel3D* GetViewShedHiddenBody();

				//! \brief ��ȡ�ϰ���
				TArray<Vector3d> GetBarrierPoints();

				//! \brief ��������
				void SetName(FString name);
				FString GetName();

				void* GetHandler();
			public:
				//! \brief �����������
				void SetMatrix(UMaterialInstanceDynamic* pMID, Matrix4d mat, FString strTex);

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
				//! \brief �ɼ�������ɫ
				FVector4 m_VisibleAreaColor;

				//! \brief ���ɼ�������ɫ
				FVector4 m_HiddenAreaColor;

				// ������������
				double m_Direction;

				// ������������
				double m_Pitch;

				// �������ˮƽ�Ž�
				double m_HorizontalFov;

				// ���������ֱ�Ž�
				double m_VerticalFov;

				// ��Զ��������
				double m_Distance;

				// �۲������
				FVector m_vViewerPosition;

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

				void* m_pUGViewShed;

				FVector m_vRealViewPos;
			};
		}
	}
}