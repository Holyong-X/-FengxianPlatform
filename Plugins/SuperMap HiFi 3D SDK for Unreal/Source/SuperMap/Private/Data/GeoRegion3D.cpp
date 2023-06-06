#include "Data/GeoRegion3D.h"
#include "Algorithm3D/MathEngine.h"

using namespace SuperMapSDK::UnrealEngine::Core;
using namespace SuperMapSDK::UnrealEngine::ControlUE;

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{
			GeoRegion3D::GeoRegion3D()
			{
				m_pUGGeometry = nullptr;
				Core::_GeoRegion3D_Create(m_pUGGeometry);
			}

			GeoRegion3D::GeoRegion3D(void* pGeoPoint3D)
			{
				m_pUGGeometry = pGeoPoint3D;
			}

			GeoRegion3D::~GeoRegion3D()
			{
				Core::_GeoRegion3D_Destroy(m_pUGGeometry);
			}

			GeoRegion3D* GeoRegion3D::Copy()
			{
				void* pNewGeometry = nullptr;
				_GeoRegion3D_Copy(m_pUGGeometry, pNewGeometry);
				GeoRegion3D* newGeoRegion3D = new GeoRegion3D(pNewGeometry);
				return newGeoRegion3D;
			}

			GeometryType GeoRegion3D::GetType()
			{
				return GeometryType::GT_GeoRegion3D;
			}

			//! \brief 得到所有的点
			void GeoRegion3D::GetPoints(TArray<Vector3d>& arrPoints)
			{
				double** pPoints = NULL;
				int nPointCount = 0;
				Core::_GeoRegion3D_GetPointCount(m_pUGGeometry, nPointCount);
				Core::_GeoRegion3D_GetPoints(m_pUGGeometry, pPoints);

				for (int i = 0; i < nPointCount; i++)
				{
					arrPoints.Add(Vector3d(pPoints[0][3 * i], pPoints[0][3 * i + 1], pPoints[0][3 * i + 2]));
				}

				Core::_ReleaseDoubleArray(pPoints);
			}

			void GeoRegion3D::GetPoints(TArray<FVector>& arrPoints)
			{
				TArray<FVector> arrPoint3D;
				if (m_arrPoint3Ds.Num() == 0)
				{
					double** pPoints = NULL;
					int nPointCount = 0;
					Core::_GeoRegion3D_GetPointCount(m_pUGGeometry, nPointCount);
					Core::_GeoRegion3D_GetPoints(m_pUGGeometry, pPoints);

					for (int i = 0; i < nPointCount; i++)
					{
						m_arrPoint3Ds.Add(Vector3d(pPoints[0][3 * i], pPoints[0][3 * i + 1], pPoints[0][3 * i + 2]));
					}

					Core::_ReleaseDoubleArray(pPoints);
				}

				for (int i = 0; i < m_arrPoint3Ds.Num(); i++)
				{
					arrPoint3D.Add(m_arrPoint3Ds[i].ToFVector());
				}

				arrPoints.Append(arrPoint3D);
			}

			void GeoRegion3D::GetPoints(double* &pData, int32 &nCount)
			{
				int32 nPointCount = m_arrPoint3Ds.Num();
				if (nPointCount > 0)
				{
					pData = new double[nPointCount * 3];
					for (int32 n = 0; n < nPointCount; n++)
					{
						pData[n * 3 + 0] = m_arrPoint3Ds[n].X;
						pData[n * 3 + 1] = m_arrPoint3Ds[n].Y;
						pData[n * 3 + 2] = m_arrPoint3Ds[n].Z;
					}
				}
				
				nCount = nPointCount;
			}

			//得到细分插值点
			void GeoRegion3D::GetSubdivisionPoints(TArray<FVector>& arrLocations, float fDistance)
			{
				TArray<FVector> points;
				this->GetPoints(points);

				if (ControlUE::CameraControl::m_eSceneType == ControlUE::UGC_EARTH ||
					ControlUE::CameraControl::m_eSceneType == ControlUE::UGC_EARTH_ELLIPSOID_WGS84)
				{
					for (int i = 0; i < points.Num(); i++)
					{
						points[i] = Algorithm3D::MathEngine::SphericalToCartesian(points[i].X, points[i].Y, points[i].Z);
					}
				}

				int nVertexIndice = 0;
				int32 nVertex = points.Num();
				float* pVertexData = new float[nVertex * 3];
				for (int i = 0; i < nVertex; i++)
				{
					pVertexData[nVertexIndice++] = points[i].X;
					pVertexData[nVertexIndice++] = points[i].Y;
					pVertexData[nVertexIndice++] = points[i].Z;
				}


				TArray<int32> polyCounts;
				this->GetPolyCounts(polyCounts);
				int nSunCount = polyCounts.Num();
				int* pPolyCounts = new int[nSunCount];
				for (int i = 0; i < nSunCount; i++)
				{
					pPolyCounts[i] = polyCounts[i];
				}


				int * pIndexes;
				int32 nIndice;
				bool bTriangle = SuperMapSDK::UnrealEngine::Algorithm3D::MathEngine::Triangulate(pVertexData, nVertex, nSunCount, pPolyCounts, pIndexes, nIndice);

				if (!bTriangle || nIndice <= 0)
				{
					SuperMapSDK::UnrealEngine::Algorithm3D::MathEngine::FreeUGInt(pIndexes);
					delete[] pVertexData;
					pVertexData = NULL;
					return;
				}

				uint32* pIndexeData = new uint32[nIndice];
				for (int j = 0; j < nIndice; j++)
				{
					pIndexeData[j] = pIndexes[j];
				}
				SuperMapSDK::UnrealEngine::Algorithm3D::MathEngine::FreeUGInt(pIndexes);


				ComputeSubdivision(pVertexData, nVertex, pIndexeData, nIndice, fDistance);

				delete[] pIndexeData;
				pIndexeData = NULL;

				for (int k = 0; k < nVertex; k++)
				{
					arrLocations.Add(FVector(pVertexData[3 * k], pVertexData[3 * k + 1], pVertexData[3 * k + 2]));
				}


				delete[] pVertexData;
				pVertexData = NULL;

				delete[] pPolyCounts;
				pPolyCounts = NULL;
			}


			//! \brief 获取所有子对象的点的个数总和
			int32 GeoRegion3D::GetPointCount()
			{
				int32 nPointCount = 0;
				Core::_GeoRegion3D_GetPointCount(m_pUGGeometry, nPointCount);
				return nPointCount;
			}

			//! \brief 获取所有子对象的个数
			int32 GeoRegion3D::GetSubCount()
			{
				int32 nSubCount = 0;
				Core::_GeoRegion3D_GetSubCount(m_pUGGeometry, nSubCount);
				return nSubCount;
			}


			void GeoRegion3D::GetPolyCounts(TArray<int32>& arrPolyCounts)
			{
				int** pPolyCounts = NULL;
				int nSubCount = 0;
				Core::_GeoRegion3D_GetSubCount(m_pUGGeometry, nSubCount);
				Core::_GeoRegion3D_GetPolyCounts(m_pUGGeometry, pPolyCounts);

				for (int i = 0; i < nSubCount; i++)
				{
					arrPolyCounts.Add(pPolyCounts[0][i]);
				}

				Core::_ReleaseIntArray(pPolyCounts);
			}

			void GeoRegion3D::GetTriangleIndices(TArray<int32>& indicesArray, Gameint nPrePtsNum)
			{
				TArray<FVector> points;
				this->GetPoints(points);

				int nVertexIndice = 0;
				int32 nVertex = points.Num();
				float* pVertexData = new float[nVertex * 3];
				for (int i = 0; i < nVertex; i++)
				{
					pVertexData[nVertexIndice++] = points[i].X;
					pVertexData[nVertexIndice++] = points[i].Y;
					pVertexData[nVertexIndice++] = points[i].Z;
				}


				TArray<int32> polyCounts;
				this->GetPolyCounts(polyCounts);

				int nSunCount = polyCounts.Num();

				int* pPolyCounts = new int[nSunCount];
				for (int i = 0; i < nSunCount; i++)
				{
					pPolyCounts[i] = polyCounts[i];
				}


				int * pIndexes = nullptr;
				int nIndice = 0;
				bool bTriangle = SuperMapSDK::UnrealEngine::Algorithm3D::MathEngine::Triangulate(pVertexData, nVertex, nSunCount, pPolyCounts, pIndexes, nIndice);
				
				if (!bTriangle)
				{
					if (pIndexes != nullptr)
					{
						SuperMapSDK::UnrealEngine::Algorithm3D::MathEngine::FreeUGInt(pIndexes);
					}
					
					delete[] pVertexData;
					pVertexData = NULL;
					delete[] pPolyCounts;
					pPolyCounts = NULL;
					return;
				}
				for (int j = 0; j < nIndice; j++)
				{
					indicesArray.Add(pIndexes[j] + nPrePtsNum);
				}
				SuperMapSDK::UnrealEngine::Algorithm3D::MathEngine::FreeUGInt(pIndexes);
				delete[] pVertexData;
				pVertexData = NULL;
				delete[] pPolyCounts;
				pPolyCounts = NULL;
			}
			
			void  GeoRegion3D::SetPoints(TArray<Vector3d> arrPoints)
			{
				m_arrPoint3Ds = arrPoints;
				double* pPoints = new double[m_arrPoint3Ds.Num() * 3];
				for (int i = 0; i < m_arrPoint3Ds.Num(); i++)
				{
					pPoints[3*i] = m_arrPoint3Ds[i].X;
					pPoints[3*i + 1] = m_arrPoint3Ds[i].Y;
					pPoints[3*i + 2] = m_arrPoint3Ds[i].Z;
				}
				Core::_GeoRegion3D_MakeWithPoints(m_pUGGeometry, pPoints, m_arrPoint3Ds.Num());
				delete[] pPoints;
				pPoints = NULL;
			}

			bool GeoRegion3D::ComputeSubdivision(float*& pVertexData, int32& nVertex, uint32*& pIndexes, int32& nIndice, float dMinDistance)
			{

				if (pVertexData == NULL || pIndexes == NULL)
				{
					return false;
				}

				TArray<uint32> arrIndex; //索引
				for (int32 i = 0; i < nIndice; i += 3)
				{
					uint32 nIndex1 = pIndexes[i];
					uint32 nIndex2 = pIndexes[i + 1];
					uint32 nIndex3 = pIndexes[i + 2];

					arrIndex.Add(nIndex1);
					arrIndex.Add(nIndex2);
					arrIndex.Add(nIndex3);
				}

				TArray<FVector> arrPoint3Ds; //顶点坐标
				arrPoint3Ds.SetNum(nVertex);

				for (int32 i = 0; i < nVertex; i++)
				{
					arrPoint3Ds[i].X = pVertexData[3 * i];
					arrPoint3Ds[i].Y = pVertexData[3 * i + 1];
					arrPoint3Ds[i].Z = pVertexData[3 * i + 2];
				}

				TMap<FString, uint32> mapEdges;
				float dMinSqrdDist = dMinDistance * dMinDistance;
				TArray<uint32> arrSubdividedIndices;
				while (arrIndex.Num() > 0)
				{
					uint32 nIndex2 = arrIndex[arrIndex.Num() - 1];
					arrIndex.RemoveAt(arrIndex.Num() - 1);

					uint32 nIndex1 = arrIndex[arrIndex.Num() - 1];
					arrIndex.RemoveAt(arrIndex.Num() - 1);

					uint32 nIndex0 = arrIndex[arrIndex.Num() - 1];
					arrIndex.RemoveAt(arrIndex.Num() - 1);

					FVector vPoint0 = arrPoint3Ds[nIndex0];
					FVector vPoint1 = arrPoint3Ds[nIndex1];
					FVector vPoint2 = arrPoint3Ds[nIndex2];

					float dDist0 = (vPoint1 - vPoint0).SizeSquared();
					float dDist1 = (vPoint2 - vPoint1).SizeSquared();
					float dDist2 = (vPoint2 - vPoint0).SizeSquared();

					FString strEdge;
					uint32 nNewIndex = -1;
					float dMaxDist = FMath::Max(dDist0, FMath::Max(dDist1, dDist2));
					if (dMaxDist > dMinSqrdDist)
					{
						if (dMaxDist == dDist0)
						{
							strEdge = FString::FormatAsNumber(FMath::Min(nIndex0, nIndex1)) + "_" + FString::FormatAsNumber(FMath::Max(nIndex0, nIndex1));

							if (mapEdges.Find(strEdge) == nullptr)
							{
								FVector midPoint3D = (vPoint0 + vPoint1) * 0.5;
								arrPoint3Ds.Add(midPoint3D);
								nNewIndex = arrPoint3Ds.Num() - 1;
								mapEdges.Add(strEdge, nNewIndex);
							}
							else
							{
								nNewIndex = mapEdges[strEdge];
							}

							arrIndex.Add(nIndex0); arrIndex.Add(nNewIndex); arrIndex.Add(nIndex2);
							arrIndex.Add(nNewIndex); arrIndex.Add(nIndex1); arrIndex.Add(nIndex2);
						}
						else if (dMaxDist == dDist1)
						{
							strEdge = FString::FormatAsNumber(FMath::Min(nIndex1, nIndex2)) + "_" + FString::FormatAsNumber(FMath::Max(nIndex1, nIndex2));

							if (mapEdges.Find(strEdge) == nullptr)
							{
								FVector midPoint3D = (vPoint1 + vPoint2) * 0.5;
								arrPoint3Ds.Add(midPoint3D);
								nNewIndex = arrPoint3Ds.Num() - 1;
								mapEdges.Add(strEdge, nNewIndex);
							}
							else
							{
								nNewIndex = mapEdges[strEdge];
							}

							arrIndex.Add(nIndex1); arrIndex.Add(nNewIndex); arrIndex.Add(nIndex0);
							arrIndex.Add(nNewIndex); arrIndex.Add(nIndex2); arrIndex.Add(nIndex0);
						}
						else if (dMaxDist == dDist2)
						{
							
							strEdge = FString::FormatAsNumber(FMath::Min(nIndex2, nIndex0)) + "_" + FString::FormatAsNumber(FMath::Max(nIndex2, nIndex0));

							if (mapEdges.Find(strEdge) == nullptr)
							{
								FVector midPoint3D = (vPoint0 + vPoint2) * 0.5;
								arrPoint3Ds.Add(midPoint3D);
								nNewIndex = arrPoint3Ds.Num() - 1;
								mapEdges.Add(strEdge, nNewIndex);
							}
							else
							{
								nNewIndex = mapEdges[strEdge];
							}

							arrIndex.Add(nIndex2); arrIndex.Add(nNewIndex); arrIndex.Add(nIndex1);
							arrIndex.Add(nNewIndex); arrIndex.Add(nIndex0); arrIndex.Add(nIndex1);
						}
					}
					else
					{
						arrSubdividedIndices.Add(nIndex0);
						arrSubdividedIndices.Add(nIndex1);
						arrSubdividedIndices.Add(nIndex2);
					}
				}

				if (arrPoint3Ds.Num() < 1 || arrSubdividedIndices.Num() < 1)
				{
					return false;
				}

				//顶点坐标
				
				uint32 nVertexCount = arrPoint3Ds.Num();
				float* pOutVertexData = new float[nVertexCount * 3];



				for (int32 i = 0; i < arrPoint3Ds.Num(); i++)
				{
					FVector vPoint3D = arrPoint3Ds[i];
					pOutVertexData[3 * i] = vPoint3D.X;
					pOutVertexData[3 * i + 1] = vPoint3D.Y;
					pOutVertexData[3 * i + 2] = vPoint3D.Z;
				}

				//索引
				uint32 nIndexCount = arrSubdividedIndices.Num();
				uint32* pOutIndexes = new uint32[nIndexCount];
	

				for (uint32 i = 0; i < nIndexCount; i++)
				{
					pOutIndexes[i] = arrSubdividedIndices[i];
				}

				if (pVertexData != NULL)
				{
					delete[] pVertexData;
					pVertexData = pOutVertexData;
					nVertex = nVertexCount;
				}

				if (pIndexes != NULL)
				{
					delete[] pIndexes;
					pIndexes = pOutIndexes;
					nIndice = nIndexCount;
				}

				return true;
			}

			bool GeoRegion3D::IsEmpty()
			{
				return m_arrPoint3Ds.Num() == 0;
			}

			void GeoRegion3D::Clear()
			{
				m_arrPoint3Ds.Empty();
				_Geometry_Clear(m_pUGGeometry);
			}

			int GeoRegion3D::AddPart(TArray<Vector3d> points)
			{
				m_arrPoint3Ds.Append(points);
				double* pPoints = new double[points.Num() * 3];
				for (int i = 0; i < points.Num(); i++)
				{
					pPoints[3 * i] = points[i].X;
					pPoints[3 * i + 1] = points[i].Y;
					pPoints[3 * i + 2] = points[i].Z;
				}

				Core::_GeoRegion3D_AddPart(m_pUGGeometry, pPoints, points.Num());

				delete[] pPoints;
				pPoints = NULL;
				return m_arrPoint3Ds.Num();
			}

			bool GeoRegion3D::InsertPart(int index, TArray<Vector3d> points)
			{
				m_arrPoint3Ds.Insert(points, index);

				double* pPoints = new double[points.Num() * 3];
				for (int i = 0; i < points.Num(); i++)
				{
					pPoints[3 * i] = points[i].X;
					pPoints[3 * i + 1] = points[i].Y;
					pPoints[3 * i + 2] = points[i].Z;
				}
				bool success = Core::_GeoRegion3D_InsertPart(m_pUGGeometry, index, pPoints, points.Num());
				delete[] pPoints;
				pPoints = NULL;
				return success;
			}

			bool GeoRegion3D::RemovePart(int index)
			{
				if (index >= m_arrPoint3Ds.Num())
				{
					return false;
				}
				m_arrPoint3Ds.RemoveAt(index);
				return Core::_GeoRegion3D_RemovePart(m_pUGGeometry, index);
			}

			Vector3d GeoRegion3D::GetInnerPoint3D()
			{
				Gamedouble  dx = 0, dy = 0, dz = 0;
				_GeoRegion3D_GetInnerPoint3D(m_pUGGeometry, dx, dy, dz);
				return Vector3d(dx, dy, dz);
			}
		}
	}
}