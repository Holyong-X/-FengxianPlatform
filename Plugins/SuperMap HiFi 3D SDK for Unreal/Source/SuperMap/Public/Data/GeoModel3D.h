#pragma once
#include "CoreMinimal.h"
#include "Data/GeometryType.h"
#include "Data/Geometry3D.h"
#include "Core/ROCache.h"
#include "Core/RealspaceDLL.h"

using namespace SuperMapSDK::UnrealEngine::Core;
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{
			class SUPERMAP_API GeoModel3D : public Geometry3D
			{
			public:
				GeoModel3D();
				GeoModel3D(void* pGeoModel3D);
				virtual ~GeoModel3D();
				GeoModel3D* Copy();
			public:
				virtual GeometryType GetType();

				bool IsLonLat();

				double Area();

				double MinZ();

				double MaxZ();

			public:
				double GeoModel3D_GetDataVertex(DataSetGeometry* & pGeometrys,
					DataSetSkeleton*** & pSkeletons, int & nSkeletonCount,
					DataSetInstanceSkeleton*** & pInstanceSkeletons, int & nInstanceSkeletonCount,
					DataSetMaterial*** & pMaterials, int & nMaterialCount,
					DataSetTexture***  & pTextures, int & nTextureCount);

				void GetDataPatch(int nIndex, DataSetPatch*** & pMaterials, DataSetPatch* & pOut);

				void GetDataGeode(int nIndex, DataSetGeode*** & pMaterials, DataSetGeode* & pOut);

				static void GetDataSkeleton(int nIndex, DataSetSkeleton*** & pMaterials, DataSetSkeleton* & pOut);

				static void GetDataTexture(int nIndex, DataSetTexture*** & pMaterials, DataSetTexture* & pOut);

				static void GetDataMaterial(int nIndex, DataSetMaterial*** & pMaterials, DataSetMaterial* & pOut);

			private:

			};
		}
	}
}