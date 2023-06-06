#pragma once
#include "CoreMinimal.h"
#include "Core/Analyst3D.h"
#include "SpatialAnalyst3D/ViewShed.h"
#include "Core/RealspaceDLL.h"
#include "Core/SceneType.h"
#include "Core/Scene.h"
#include "ControlUE/CameraControl.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Data/Matrix4d.h"
#include "Data/GeoModel3D.h"

using namespace SuperMapSDK::UnrealEngine::Data;
using namespace SuperMapSDK::UnrealEngine::SpatialAnalyst3D;
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
			class SUPERMAP_API MultiViewShed3D : public Core::Analyst3D
			{
			public:
				//! \brief ���캯��
				MultiViewShed3D(UWorld* pWorld, Core::Scene* pScene, ControlUE::CameraControl* pCameraControl);
				virtual ~MultiViewShed3D();

			public:
				void AddViewShed(ViewShed* pViewShed);
				
				void RemoveViewShed(ViewShed* pViewShed);

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

				// ��������
				bool m_bUpdate;

				bool m_bEnable;

				void* m_pUGMultiViewShed3D;

				TArray<ViewShed*> m_arrViewShed;

				TArray<Matrix4d> m_matRenderTextureMat;

				TArray<Gamedouble> m_arrDistance;

				TArray<FVector> m_arrRealViewPos;
			};
		}
	}
}