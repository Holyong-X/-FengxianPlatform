#pragma once

#include "CoreMinimal.h"
#include <vector>
#include "Component/SuperMap_InstancedActor.h"
class UWorld;
class UStaticMesh;
class ASuperMap_InstancedActor;

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{
			
			//! \brief ����������
			enum SUPERMAP_API CollectionType
			{
				CT_POINT,   //  ��
				CT_LINE,	//  ��
				CT_REGION   //  ��
			};

			//! \brief �����������
			struct SUPERMAP_API CollectionStyleParam
			{
			public:
				//! \brief ����ʲ�����
				FString m_strAssetResoureName;

				//! \brief ����ʲ�����·��
				FString m_strAssetResourePath;

			};

			class Geometry;
			class SUPERMAP_API Collection
			{
			public:
				Collection(UWorld* pWorld);
				virtual ~Collection();

			public:
				//! \brief �������
				virtual bool BuildStyle() = 0;

				//! \brief ��ȡ����������
				virtual CollectionType GetType() = 0;

				//! \brief ���÷�����
				void SetStyleParam(CollectionStyleParam & styleParam);

				//! \brief ��ȡ������
				CollectionStyleParam& GetStyleParam();

				//! \brief �����±��ȡ�����������
				Geometry* GetGeometry(int32 nIndex);

				//! \brief ��Ӽ���������
				void AddGeometry(Geometry* pGeometry);
			protected:
				//! \brief ����StaticMesh
				UStaticMesh* CreateStaticMesh(FString strAssetPath);

				//! \brief �����������ת��
				FQuat CallRotator(FVector vDirectionUP);
				
			protected:

				//! \brief �����������
				CollectionType m_eCollectionType;

				//! \brief ��������
				CollectionStyleParam m_StyleParam;

				//! \brief UE�ĳ���������
				UWorld* m_pWorld;

				//! \brief ʵ������Ⱦ����
				ASuperMap_InstancedActor* m_pInstancedActor;

				//! \brief ����������
				TArray<Geometry*> m_Geometrys;
			};

		}
	}
}