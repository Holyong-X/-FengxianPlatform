#pragma once

#include "CoreMinimal.h"
#include "Layer3DType.h"
#include "Layout/SlateRect.h"
#include "Core/Selection3D.h"
#include "Core/Layer3DInfo.h"
#include "Data/Vector3d.h"
#include "Data/Vector4d.h"
#include "Data/GeoBox.h"
#include "Core/ClipMode.h"
#include "Core/AssetStyle.h"
#include "Base3D/Plane.h"
#include "Graphics3D/GameComponent.h"
#include "Data/Rectangle2D.h"
#include "Data/JsonFile.h"
#include "Runtime/Core/Public/Misc/FileHelper.h"
#include "Runtime/Json/Public/Serialization/JsonSerializer.h"
#include "Core/RealspaceDLL.h"
#include "Core/Style3D.h"
#include "Core/AssetStyle.h"

using namespace SuperMapSDK::UnrealEngine::Data;
using namespace SuperMapSDK::UnrealEngine::Base3D;
using namespace SuperMapSDK;

typedef void(*LayerDeleteEvent) (void* pActor);
class UWorld;

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			struct PlaneClipParam
			{
				//! \brief �ü���
				TArray<Plane> m_arrClipPlanes;

				//! \brief �ü�����
				BoxClipPart m_eBoxClipMode;

				//! \brief �ü�������ɫ
				Vector4d  m_vClipLineColor;
			};

			struct SUPERMAP_API LayerDeleteEventInfos
			{
			public:
				//ʵ�ִ����¼���Actor
				void* m_pActor;
				//�����¼�
				LayerDeleteEvent m_LayerDeleteEvent;
			public:
				LayerDeleteEventInfos()
				{
					m_pActor = nullptr;
				}
			};
			//class SuperMapSDK::GameComponent;

			class SUPERMAP_API UEAssetStyle
			{
			public:
				enum SUPERMAP_API Mode
				{
					//���СƷ
					ASSET_MESH = 0,
					//�����ʽ
					ASSET_MATERIAL = 1,
					//�ʲ�����
					ASSET_LOFT = 2
				};
			public:
				UEAssetStyle();
				~UEAssetStyle();

				//! \brief ���ò����滻����
				void SetAssetStyles(TMap<FString, AssetStyle*> mapAssetStyles);

				TMap<FString, AssetStyle*> GetAssetStyles();

				//! \brief �������
				UEAssetStyle::Mode GetMode();

				void SetMode(UEAssetStyle::Mode type);
			private:
				UEAssetStyle::Mode m_eMode;

				TMap<FString, AssetStyle*> m_mapAssetStyles;
			};

			class SUPERMAP_API Layer3D
			{
			public:
				Layer3D();
				Layer3D(FName strLayerName, Layer3DType eLayerType);
				Layer3D(void* pUGLayer3D, FName strLayerName, Layer3DType eLayerType);
				virtual ~Layer3D();

			protected:
				//! \brief ͼ������
				FName m_strLayerName;

				//! \brief ͼ����������
				FName m_strDataLayerName;

				//! \brief ͼ������
				Layer3DType m_eLayerType;

				//! \brief �ɼ����Ƿ�ı�
				bool m_bIsVisibleChanged;

				//! \brief �ɼ���
				bool m_bIsVisible;

				//! \brief ͼ�������Ϣ
				Layer3DMaterialInfo m_MaterialInfo;

				//! \brief ͼ����������Ϣ
				ObjectMaterialInfo m_ObjectMaterialInfo;

				//! \brief ͼ��ID
				int32 m_nLayerID;

				//! \brief ѡ�񼯶���
				Selection3D* m_pSelection;

				//! \brief �ü����ӵ�ָ��
				GeoBox* m_pClipBox;

				//! \brief ��ȡBox�ü�ģʽ
				BoxClipPart m_eBoxClipMode;

				//! \brief UGC����
				void* m_pUGLayer3D;

				//! \brief ���²ü�
				bool m_bUpdateClip;
				bool m_bHasClip;

				//! \brief �ü�ѹƽ�Ĳ���
				PlaneClipParam m_ClipParam;

				//! \brief ͼ����ڵ������
				Gamelong m_nNodeName;

				//! \brief ͼ����е���Ⱦ����
				TMap<Gamelong, GameComponent*> m_mapNativeGameComponent;

				//! \brief ��ʼ��
				Gamebool m_bInitial;

				//! \brief ����������
				Gamebool m_bVisibleInViewport[2];

				//! \brief �Ƿ����
				Gamebool m_bIsViewport;

				//! \brief ͼ���������
				UEAssetStyle* m_pUEAssetStyle;

				//! \brief ɾ��ͼ��ص��¼�
				LayerDeleteEventInfos m_LayerDeleteEventInfos;
			public:
				//! \brief ��ȡUGC���
				void* GetHandler();

				//! \brief ��ȡͼ����
				FName Name();

				//! \brief ��ȡͼ��ȫ·��
				FString GetDataPath();

				//! \brief ��ȡͼ��������
				FName DataName();

				//! \brief ��ȡͼ��ڵ���
				FName NodeName();

				//! \brief ��ȡͼ��ڵ�����hashcodeֵ
				Gamelong NodeNameHashCode();

				//! \brief ͼ������
				Layer3DType Type();

				OSGBType DataType();

				//! \brief ��ȡ�Ƿ�ɼ���
				virtual bool GetIsVisible();

				//! \brief ���ÿɼ���
				virtual void SetIsVisible(bool bVisible);

				//! \brief ���ò���� ƽ��ʹ��
				virtual void SetOriginalPosition(FVector vPos);

				//! \brief ����boundsֵ
				Rectangle2D GetBounds();

				//! \brief ��ȡͼ��ID
				int32 GetLayerID();

				//! \brief ����ͼ��ID
				void SetLayerID(int32 nLayerID);

				//! \brief ����ѡ��
				Selection3D* GetSelection3D();

				//! \brief ��ȡͼ�������Ϣ
				Layer3DMaterialInfo& GetMaterialInfo();

				//! \brief ����ͼ�������Ϣ
				void SetMaterialInfo(Layer3DMaterialInfo& info);

				//! \brief ��ȡͼ�������Ϣ
				ObjectMaterialInfo& GetObjectMaterialInfo();

				//! \brief ����ͼ�������Ϣ
				void SetObjectMaterialInfo(ObjectMaterialInfo& info);

				//! \brief ����ͼ�������Ϣ
				void DeleteObjectMaterialInfo(FString strMaterialName);

				//! \brief �����Զ���ü���
				virtual void SetCustomClipPlane(Vector3d firstPoint, Vector3d secondPoint, Vector3d thirdPoint);

				//! \biref ����һ�����ӣ���ͼ�����Ⱦ���ֽ��вü�
				void ClipByBox(GeoBox* pGeoBox, BoxClipPart ePlaneClipMode);

				//! \brief ��ȡ�ü�����
				GeoBox* GetClipBox();

				//! \brief ���²ü�����
				void UpdateClipParam();

				//! \brief ��ȡBox�ü�ģʽ
				BoxClipPart GetBoxClipPart();

				//! \brief ���òü����Ե�ߵ���ɫ
				void SetClipLineColor(Vector4d vClipLineColor);

				//! \brief ��ȡ�ü����Ե�ߵ���ɫ
				Vector4d GetClipLineColor();

				//! \brief ����Զ���ü���
				void ClearCustomClipPlane();

				//! \brief �����Ƿ����
				void SetSwipeEnabled(Gamebool bSwipe);

				//! \brief ��ȡ�Ƿ����
				Gamebool GetSwipeEnabled();

				//! \brief ���þ�������
				void SetSwipeRegion(Rectangle2D rcBox);

				//! \brief ��ȡ��������
				Rectangle2D GetSwipeRegion();

				//! \brief �����Ƿ����
				void SetViewportEnabled(Gamebool bViewport);

				//! \brief ����Json
				JsonFile* LayerToJson();

				//! \brief ����ͼ��
				void UpdateData();

				//! \brief ���÷���������
				void SetVisibleInViewport(Gameint nIndex, Gamebool visible);

				//! \brief ��ȡ����������
				Gamebool GetVisibleInViewport(Gameint nIndex);

				//! \brief ���ѡ�ж���
				void AddSelectedID(Gameint nID);

				//! \brief ���ѡ�ж���
				void ReleaseSelection();

				//! \brief ����ͼ��ѡ�з��
				void SetSelectStyle(Style3D* pStyle3D);

				//! \brief ��ȡͼ��ѡ�з��
				void GetSelectStyle(Style3D* &style3d);

				Gamebool IsMarkerLayer();
				void SetMarkerLayer(bool bIsMarkerLayer);

				//! \brief ��ȡͼ���������
				UEAssetStyle* GetUEAssetStyle();

				//! \brief ����ͼ����
				void SetStyle(Style3D* pStyle);

				//! \brief ��ȡͼ����
				void GetStyle(Style3D* &pStyle);

				//! \brief ��Ⱦ����
				virtual void Render(UWorld* pWorld);

				//! \brief ����ͼ����Զ�ɼ�����
				void SetMaxObjectVisibleDistance(Gamedouble dValue);

				//! \brief ����ͼ������ɼ�����
				//void SetMinObjectVisibleDistance(Gamedouble dValue);

				//! \brief ��ȡͼ����Զ����ɼ�����
				void GetMaxMinObjectVisibleDistance(Gamedouble& dmax, Gamedouble& dmin);

				//! \brief ���ͼ�����Ⱦ����
				virtual void AddNativeGameComponent(GameComponent* pGameComponent);
				//! \brief �Ƴ�ͼ�����Ⱦ����
				virtual void RemoveNativeGameComponent(GameComponent* pGameComponent);
				//! \brief ��ȡͼ��������Ⱦ����
				virtual TMap<Gamelong, GameComponent*>& GetAllNativeGameComponent();

				//! \brief ɾ��ͼ��ص�����
				void SetDeleteLayerEventFunc(void* pActor, LayerDeleteEvent evnt);
			protected:
				//! \brief �ɼ����Ƿ�ı�
				bool GetIsVisibleChanged();

				//! \brief ���ÿɼ����Ƿ�ı�
				void SetIsVisibleChanged(bool bVisible);

				//! \brief ��ȡ�ü��Ĳ���
				void GetClipParamFromUGC();
			};
		}
	}
}
