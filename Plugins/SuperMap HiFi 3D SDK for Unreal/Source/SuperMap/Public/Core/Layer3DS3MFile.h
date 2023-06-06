#pragma once

#include "CoreMinimal.h"
#include "Layer3D.h"
#include "Core/AttributeFields.h"
#include "Core/HypsometricSetting.h"
#include "Data/GeoRegion3D.h"
#include "Data/Matrix4d.h"
#include "Data/Vector4d.h"
#include "Core/ROCacheManager.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Core/RealspaceDLL.h"

using namespace SuperMapSDK::UnrealEngine::Data;
using namespace SuperMapSDK::UnrealEngine::Core;

class UWorld;
class UTextureRenderTarget2D;
class UTexture2D;
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			enum SUPERMAP_API ModifyRegionMode
			{
				ClipInside,
				ClipOutside,
				Mosaic,
				Flatten,
				Modify_None
			};

			enum SUPERMAP_API LoadingPriorityEnum
			{
				//�������
				Root_Priority,
				//�������
				Child_Priority,
				//��������
				UsePagedLodInfo,
				//������ȷ������л�
				Child_Priority_NonLinear

			};

			struct S3MEffectShaderParamters
			{
				//! \brief ��бѹƽ����ʸ����
				ModifyRegionMode m_eModifyRegionMode;

				//! \brief ��бѹƽ���ڷ�Χ
				FVector4 m_v4S3MEffectRectPos;

				//! \brief ѹƽ���ڶ���εĸ���
				int32 m_nRegionCount;

				//! \brief
				Matrix4d m_matWorldToFlattenLocal;
				Matrix4d m_matS3MEffectLocalToWorld;
				
				//! \brief ѹƽ���ڶ��������
				UTextureRenderTarget2D* m_pS3MEffectTexture;

				S3MEffectShaderParamters()
				{
					m_eModifyRegionMode = ModifyRegionMode::Modify_None;
					m_pS3MEffectTexture = nullptr;
				}
			};

			class SUPERMAP_API ObjectsColorDictionary
			{
			public:
				ObjectsColorDictionary(void* pUGLayer3D);
				~ObjectsColorDictionary();

				//! \brief ���ö�����ɫ
				void SetObjectsColor(TArray<Gameint> ids, FVector4 color);
				
				//! \brief ��ö�����ɫ
				TMap<Gameint, FVector4> GetObjectsColor();
				
				//! \brief ���ö�����ɫ
				void RemoveObjectsColor(TArray<Gameint> ids);

				//! \brief �������ж�����ɫ
				void ResetObjectsColor();

			private:

				void* m_pUGLayer3DS3MFile;
			};

			class SUPERMAP_API Layer3DS3MFile : public Layer3D
			{
			public:
				Layer3DS3MFile();
				Layer3DS3MFile(FName strLayerName, Layer3DType eLayerType);
				Layer3DS3MFile(void* pUGLayer3D, FName strLayerName, Layer3DType eLayerType);
				virtual ~Layer3DS3MFile();

				//! \brief ��ȡ��ǰͼ��������ֶ�
				std::vector<FString> GetFieldInfos();
				std::vector<FString> GetFieldInfos(Gameint nID);

				//! \brief ��ȡ��ǰ�����ֶ�����
				std::vector<FString> GetAllFieldValues(Gameint nID);

				//! \brief ��ȡͼ�����߶�
				Gamedouble GetMaxHeight();

				//! \brief ��ȡͼ��͸߳�
				Gamedouble GetMinHeight();

				//! \brief ���õ�ǰͼ���LOD�㼶
				void SetLODRangeScale(int nLayerID, float values);

				//! \brief ��ȡ��ǰͼ���LOD�㼶
				float GetLODRangeScale(int nLayerID);

				//! \brief ���ѹƽ��ʸ��(��ͼ���ͷ�ʸ����)
				void AddFlattenRegion(GeoRegion3D* pGeoRegion3D, FString strTag);

				//! \brief ���ѹƽʸ����
				void ClearFlattenRegion();

				//! \brief ��ȡѹƽ������Ҫ�Ĳ���
				S3MEffectShaderParamters GetS3MEffectParam();

				//! \brief ���÷ֲ���ɫ��
				void SetHypsometricSetting(HypsometricSetting* pHypsometricSetting);

				//! \brief ��ȡ�ֲ���ɫ��
				HypsometricSetting* GetHypsometricSetting();

				//! \brief ����ֲ���ɫ
				void ClearHypsometricSetting();

				//! \brief �����ƫ��
				void SetConstantPolygonOffset(double dOffset);
				double GetConstantPolygonOffset();

				//! \brief ����ID�б��ж���Ŀɼ���
				void SetObjectsVisible(TArray<Gameint> ids, Gamebool bVisible);

				//! \breif ����ID�б��ֲ����滻��
				void SetObjectsMaterial(TArray<Gameint> ids, FString strMaterialName);

				//! \brief ��Ⱦ����
				virtual void Render(UWorld* pWorld);

				//! \brief ��ȡͼ��߶������Сֵ
				double GetMaxDataValue();
				double GetMinDataValue();

				//! \brief ��ȡͼ��������Ϣ
				AttributeFields GetAttributeFields();

				//! \brief ģ����б����
				void SetModifyRegions(TArray<GeoRegion3D*> pGeoRegion3Ds, ModifyRegionMode type);

				void ClearModifyRegions();
				//! \brief ����/��ȡMeshopt�����Ƿ�CPU������
				void SetDecodeMeshopt(Gamebool value);
				Gamebool IsDecodeMeshopt();

				//! \brief ����S3Mͼ���������
				void ExportUEMaterialToJson(FString ScpFilePath);				
				
				//! \brief ��ӹ�������·����scp�ļ�
				void AddRelatedPathToScpFile(FString LayerInfoPath, FString ScpFilePath);

				//! \brief ��ȡ���ö�����ɫ��ָ��
				ObjectsColorDictionary* GetObjectsColorDictionary();

				//! \brief ���ü�������ģʽ
				void SetLoadingPriority(LoadingPriorityEnum type);

				//! \brief ��ȡ��������ģʽ
				LoadingPriorityEnum GetLoadingPriority();

				//! \brief ���Ӱ��ͼ��
				void SetCoverImageryLayer(TArray<Layer3D*> arrImageLayers);

				//! \brief ���ͼ�����Ⱦ����
				virtual void AddNativeGameComponent(GameComponent* pGameComponent);
				//! \brief �Ƴ�ͼ�����Ⱦ����
				virtual void RemoveNativeGameComponent(GameComponent* pGameComponent);
			private:
				//! \brief ����ѹƽ���ڲ���
				void CalS3MEffectParam(int32 nRegionCount, ModifyRegionMode type);

				//! \brief ͼ�����ѹƽ����
				void UpdateMaterialS3MEffectParam(int32 nRegionCount,bool bClear = false);

				//! \brief �������þ���
				void SetMaterialMatrix(UMaterialInstanceDynamic* pMID, Matrix4d mat, FString strName);

				//! \brief ��Ⱦ����
				void UpdataHypsometricSetting();

				//! \brief ���²ü���Ⱦ�Ĳ���
				void UpdateClipShaderParam();

				//! \brief ���ò��ʲü�����
				void SetClipShaderParam(UMaterialInstanceDynamic* pMID);

				//! \brief ����ѹƽ��ɫ������
				void SetFlattenShaderParam(UMaterialInstanceDynamic* pMID);

				//! \brief ���ÿ�����ɫ������
				void SetExcavationShaderParam(UMaterialInstanceDynamic* pMat);

				//! \brief ���õ�ֵ����ɫ������
				void SetHypsometricSettingShaderParam(UMaterialInstanceDynamic* pMID);

				//! \brief ����ͼ�����
				void UpdateMaterialInfo(GameMaterial* pGameMaterial);

				void UpdateShaderForOneNativeGameComponent(GameComponent* pGameComponent);

				//! \brief S3Mͼ����Ϣ����
				void LayerInfoToJson(FString strPath);
			private:
				//! \brief ��ǰ��ȡID�����������Ϣ
				AttributeFields m_AttributeFields;

				//! \brief ��бѹƽ���ڲ���
				S3MEffectShaderParamters m_S3MEffectParam;

				//! \brief �ȸ��߸߶ȳ���
				double m_dHypsometricHeight;

				//! \brief �����ƫ��������
				double m_dConstantPolygonOffset;

				//! \brief �ֲ���ɫ
				HypsometricSetting* m_pHypsometricSetting;

				//! \brief ѹƽ����
				Gamebool m_bUpdateS3MEffectShader;

				//! \brief ���������
				Gameint m_nModifyRegionsCount;

				//! \brief �ֲ���ɫ����
				Gamebool m_bUpdataHypsometricSetting;

				//! \brief ���ڡ�ѹƽ����
				ModifyRegionMode m_eModifyRegionMode;

				friend class ROCacheManager;

				//! \brief ��������ָ������
				TArray<UMaterialInterface*> m_arrPtrMaterialInterface;

				ObjectsColorDictionary* m_pObjectsColorDictionary;
			};
		}
	}
}