#pragma once

#include "CoreMinimal.h"
#include "Core/Layer3DDatasetVector.h"

class UWorld;

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			class SUPERMAP_API Layer3DDatasetVectorRegion : public Layer3DDatasetVector
			{
			public:
				Layer3DDatasetVectorRegion();
				Layer3DDatasetVectorRegion(FName strLayerName, Layer3DType eLayerType);
				virtual ~Layer3DDatasetVectorRegion();

			public:
				//! \brief �������
				virtual bool BuildStyle(UWorld* pWorld);

				//! \brief ��ȡ����
				virtual DatasetType GetType();

				//! \brief ��Ⱦ����
				virtual void Render(UWorld* pWorld);
			private:
				void GetVertexInfo(TArray<Data::Geometry*> arrGeometrys, TArray<int32>& arrIndexs, TArray<FVector>& arrPos);
				void GetVertexInfo(TArray<Data::Geometry*> arrGeometrys, TArray<int32>& arrIndexs, TArray<Vector3d>& arrPos);
			};

		}
	}
}