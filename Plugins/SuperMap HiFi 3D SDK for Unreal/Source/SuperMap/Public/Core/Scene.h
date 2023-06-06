#pragma once

#include <map>
#include "CoreMinimal.h"
#include "Core/Analyst3D.h"
#include "Core/SceneType.h"
#include "Layout/SlateRect.h"
#include "ControlUE/CameraControl.h"
#include "Graphics3D/GameComponent.h"
#include "Base3D/CommonDefine.h"
#include "Core/Layer3D.h"
#include "Data/Rectangle2D.h"
#include "Core/Query3D.h"
#include "Core/CameraState.h"
#include "Core/RealspaceDLL.h"
#include "Core/GlobalImage.h"
class UWorld;

using namespace SuperMapSDK;
using namespace SuperMapSDK::UnrealEngine::Data;

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace ControlUE 
		{
			class CameraControl;
		}
		namespace Core
		{
			//! \brief ���ж�λ�ص��¼�
			typedef void(*FlownFunc)(void* pScene);
			void OnFlown(void* pScene);

			enum SUPERMAP_API PixelToGlobeMode
			{
				//! \brief ���κ�ģ�Ͷ������󽻵�
				TerrainAndModel = 0,

				//! \brief ֻ��ر��󽻵�
				Sphere = 1
			};

			enum MultiViewportMode
			{
				None = 0,//��ԭ����
				Horizontal = 1,//���ҷ���
			};

			enum SUPERMAP_API StereoMode
			{
				ANAGLYPHIC = 0, //����ɫ��ʽ
				HTCVIVE_VR = 10 //HTC VIVE������ʵͷ��
			};

			class Layer3Ds;
			class TerrainLayers;
			class TrackingLayer;
			class FlyManager;
			//class SuperMapSDK::GameComponent;
			class SUPERMAP_API Scene
			{
			public:
				Scene();
				~Scene();
			private:
				//! \brief ��ͨͼ���������
				Layer3Ds* m_pLayer3Ds;

				//! \brief ����ͼ�����
				TerrainLayers* m_pTerrainLayers;

				//! \brief ����ͼ�����
				TrackingLayer* m_pTrackingLayer;

				//! \brief ��������
				SceneType m_eSceneType;

				//! \brief ����α��������
				FVector m_vtTerrainPos;

				//! \brief ���������
				ControlUE::CameraControl* m_pCameraControl;

				//! \brief �����������
				std::map<FName, Analyst3D*> m_mapAnalyst;

				//! \brief ���糡������
				UWorld* m_pWorld;

				//! \brief ����
				void* m_pUGScene;

				//! \brief ����ģʽ
				MultiViewportMode m_eViewportMode;

				//! \brief �ռ��ѯ��
				Query3D* m_pQuery3D;

				//! \brief ���й���
				FlyManager* m_pFlyManager;

				//! \brief �����״̬
				CameraState* m_pCameraState;

				//! \brief ����Ӱ��
				GlobalImage* m_pGlobalImage;
			private:
				void GetLayer3DsFromXML();
				void GetTerrainLayersFromXML();
			public:
				//! \brief ��ȡ����Ӱ��
				GlobalImage* GetGlobalImage();

				//! \brief �������������
				void SetCameraControl(SuperMapSDK::UnrealEngine::ControlUE::CameraControl* pCamerControl);

				//! \brief ��ȡ���������
				CameraControl* GetCameraControl();

				//! \brief �������糡����
				void SetWorld(UWorld* pWorld);

				//! \brief ��ȡ���糡����
				UWorld* GetWorld();

				//! \brief ��ȡQuery3D
				Query3D* GetQuery3D();

				//! \brief ��ȡ��������
				SceneType GetSceneType();

				//! \brief ���ó�������
				void SetSceneType(SceneType eSceneType);

				//! \brief ����3Dͼ�㼯��
				Layer3Ds* GetLayer3Ds();

				//! \brief ���ص���ͼ�㼯��
				TerrainLayers* GetTerrainLayers();

				//! \brief ��ȡ����ͼ��
				TrackingLayer* GetTrackingLayer();

				//! \brief �������
				void SetCamera(Gamefloat* matView, Gamefloat fNearDist, Gamefloat fFarDist, Gamefloat fFov, Gamefloat fAspect);

				//! \brief �������Fov�ӽ�
				void SetCameraFov(Gamedouble dFov);

				//! \brief ��ȡ���Fov�ӽ�
				Gamedouble GetCameraFov();

				//! \brief ����ɵ�boundsλ�� 
				void EnsureVisible(Rectangle2D rect2D, Gamedouble dHeight = FIXED_ALTITUDE);

				//! \brief ���ͼ��
				void Clear();

				//! \brief ��������UE�ռ��µĵѿ�������
				Vector3d PixelToCartesian(Vector3d vMouse);

				//! \brief �������ض�Ӧ����ʵ��������
				Vector3d PixelToGlobe(Vector3d vMouse, PixelToGlobeMode mode = TerrainAndModel);

				//! \brief ��ȡ���������б�
				std::map<FName, Analyst3D*>& GetAnalyst3DList();

				//! \brief ȹ������
				Gamebool GetCreateSkirt();

				//! \brief ȹ������
				void SetCreateSkirt(Gamebool bCreatesSkirt);

				//! \brief ����ȹ�߸߶�
				void SetSkirtHeight(Gamefloat fHeight);

				//! \brief ����Json
				void ToJson(FString strPath);

				//! \brief ���÷���ģʽ
				void SetMultiViewportMode(MultiViewportMode mode);

				//! \brief ��ȡ����ģʽ
				MultiViewportMode GetMultiViewportMode();

				//! \brief ����������Ⱦ����(�ڲ����ú���)
				void Render();

				//! \brief ���xml�ļ�
				Gamebool ToXML(FString strFileAdress);

				//! \brief ��ȡxml�ļ�
				Gamebool FromXML(FString strFileAdress);

				//! \brief ͨ��ָ����γ�Ȼ�ȡ�ռ����� �� ģ����ת�Ƕ�
				//! \brief bUseGeoreference Ϊfalse �����Զ�̬ԭ��
				FTransform LongitudeLatitudeToUE(FVector vLonLat, Gamebool bIgnoreWorldOrigin = false);

				//! \brief ����������Ч����
				void SetShowInvalidation(Gamebool bShow);

				//! \brief ��������ָ��
				void SetHandler(void* pScene);

				//! \brief ��ȡ����ָ��
				void* GetHandler();

				//! \brief ��ȡ���й�����
				FlyManager* GetFlyManager();

				//! \brief ���÷��ж�λ
				void Fly(CameraState* pCameraState, Gameint milliseconds);

				//! \brief ���õ��ο���
				void SetTerrainExaggeration(Gamedouble dValue);

				//! \brief ��ȡ���ο�����ֵ
				Gamedouble GetTerrainExaggeration();

				//! \brief ��ȡѡ�ж���Ĳ�����Ϣ
				SelectedInfo GetSelectedInfo();

				//! \brief ��ȡ��������״̬
				CameraState* GetCameraState();

				//! \brief ��ʼ�����лص��¼�
				void InitializeFlyCallbackHandle();

				//! \brief ����������ʾģʽ
				void SetStereoMode(StereoMode mode);

				//! \brief ����ˢ��
				void Updata();

				//! \brief �ֲ�����ˢ��
				void GlobalRefreshRaster(Rectangle2D rec);

				//! \brief ��ȡ������ʾģʽ
				StereoMode GetStereoMode();

				void AddNativeGameComponent(GameComponent* pGameComponent);
				void RemoveNativeGameComponent(GameComponent* pGameComponent);

				Layer3D* FindLayerByNodeName(Gamelong nodeName);


				friend class SceneControl;
				friend class Analyst3D;
				friend class ROCacheManager;
			};
		}
	}
}