#pragma once

#include "CoreMinimal.h"

class UWorld;
class UStaticMesh;
class ASuperMap_InstancedActor;
class ASuperMap_ROEntityActor;
class ASuperMap_SplineActor;

using namespace SuperMapSDK::UnrealEngine::Data;
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			//! \brief �����������
			struct SUPERMAP_API StyleParam
			{
			public:
				//! \brief ����ʲ�����
				FString m_strAssetResoureName;

				//! \brief ����ʲ�����·��
				FString m_strAssetResourePath;

				//����ʲ��ļ��
				float m_fDistance;
			}; 

			class SUPERMAP_API AssetStyle
			{
			public:
				AssetStyle(UWorld* pWorld);
				virtual ~AssetStyle();

			public:

				//! \brief ���÷�����
				void SetStyleParam(StyleParam & styleParam);

				//! \brief ��ȡ������
				StyleParam& GetStyleParam();

				bool BuildStyle(TArray<Vector3d> arrLocations);

				bool BuildStyle(TArray<FVector> arrLocations);

				bool BuildSubdivisionStyle(TArray<FVector> arrLocations);

				bool BuildStyle(TArray<FVector> arrPositions, TArray<int32> arrIndexs);

				bool BuildStyle(TArray<Vector3d> arrPositions, TArray<int32> arrIndexs);

				bool BuildStyle(TArray<TArray<Vector3d>> arrLinesPts);

			protected:
				//! \brief ����StaticMesh
				UStaticMesh* CreateStaticMesh(FString strAssetPath);

				//! \brief �����������ת��
				FQuat CallRotator(FVector vDirectionUP);
			private:

				void GetSubdivisionPoints(TArray<TArray<Vector3d>>& pots1, TArray<TArray<Vector3d>>& pots2);
			protected:
				//! \brief ��������
				StyleParam m_StyleParam;

				//! \brief UE�ĳ���������
				UWorld* m_pWorld;

				//! \brief ʵ������Ⱦ����
				ASuperMap_InstancedActor* m_pInstancedActor;

				ASuperMap_ROEntityActor* m_pROEntityActor;

				ASuperMap_SplineActor* m_pSplineActor;
			};

		}
	}
}