#include "Data/GeoModel3D.h"

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{
			GeoModel3D::GeoModel3D()
			{
				m_pUGGeometry = nullptr;
				Core::_GeoModel3D_Create(m_pUGGeometry);
			}

			GeoModel3D::~GeoModel3D()
			{
				Core::_GeoModel3D_Destroy(m_pUGGeometry);
			}

			GeoModel3D::GeoModel3D(void* pGeoModel3D)
			{
				m_pUGGeometry = pGeoModel3D;
			}

			GeoModel3D* GeoModel3D::Copy()
			{
				void* pNewGeometry = nullptr;
				_GeoModel3D_Copy(m_pUGGeometry, pNewGeometry);
				GeoModel3D* newGeoModel3D = new GeoModel3D(pNewGeometry);
				return newGeoModel3D;
			}

			bool GeoModel3D::IsLonLat()
			{
				return Core::_GeoModel3D_IsLonLat(m_pUGGeometry);
			}

			GeometryType GeoModel3D::GetType()
			{
				return GeometryType::GT_GeoModel3D;
			}

			double GeoModel3D::Area()
			{
				return Core::_GeoModel3D_Area(m_pUGGeometry);
			}

			double GeoModel3D::MinZ()
			{
				return Core::_GeoModel3D_MinZ(m_pUGGeometry);
			}

			double GeoModel3D::MaxZ()
			{
				return Core::_GeoModel3D_MaxZ(m_pUGGeometry);
			}

			double GeoModel3D::GeoModel3D_GetDataVertex(DataSetGeometry* & pGeometrys,
				DataSetSkeleton*** & pSkeletons, int & nSkeletonCount,
				DataSetInstanceSkeleton*** & pInstanceSkeletons, int & nInstanceSkeletonCount,
				DataSetMaterial*** & pMaterials, int & nMaterialCount,
				DataSetTexture***  & pTextures, int & nTextureCount)
			{
				return Core::_GeoModel3D_GetDataVertex(m_pUGGeometry, pGeometrys, pSkeletons, nSkeletonCount, pInstanceSkeletons, nInstanceSkeletonCount, pMaterials, nMaterialCount, pTextures, nTextureCount);
			}

			void GeoModel3D::GetDataPatch(int nIndex, DataSetPatch*** & pMaterials, DataSetPatch* & pOut)
			{
				return Core::_GetDataPatch(nIndex, pMaterials, pOut);
			}

			void GeoModel3D::GetDataGeode(int nIndex, DataSetGeode*** & pMaterials, DataSetGeode* & pOut)
			{
				return Core::_GetDataGeode(nIndex, pMaterials, pOut);
			}

			void GeoModel3D::GetDataSkeleton(int nIndex, DataSetSkeleton*** & pMaterials, DataSetSkeleton* & pOut)
			{
				return Core::_GetDataSkeleton(nIndex, pMaterials, pOut);
			}

			void GeoModel3D::GetDataTexture(int nIndex, DataSetTexture*** & pMaterials, DataSetTexture* & pOut)
			{
				return Core::_GetDataTexture(nIndex, pMaterials, pOut);
			}

			void GeoModel3D::GetDataMaterial(int nIndex, DataSetMaterial*** & pMaterials, DataSetMaterial* & pOut)
			{
				return Core::_GetDataMaterial(nIndex, pMaterials, pOut);
			}
		}
	}
}