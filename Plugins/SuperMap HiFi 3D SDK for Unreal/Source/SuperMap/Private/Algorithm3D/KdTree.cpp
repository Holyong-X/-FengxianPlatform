#include "Algorithm3D/KdTree.h"
#include "Core/RealspaceDLL.h"

using namespace SuperMapSDK::UnrealEngine::Core;

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Algorithm3D
		{
			KdTree::KdTree()
			{
				m_pKdTree = nullptr;
			}

			KdTree::KdTree(TArray<Vector3d> Points)
			{
				m_pKdTree = nullptr;
				Gamedouble* dPoints = new Gamedouble[Points.Num() * 3];
				Gameint* nIndexPack = new Gameint[Points.Num()];
				for (int i = 0; i < Points.Num(); i++)
				{
					dPoints[i * 3] = Points[i].X;
					dPoints[i * 3 + 1] = Points[i].Y;
					dPoints[i * 3 + 2] = Points[i].Z;
					nIndexPack[i] = i;
				}
				_KDTree_Create(m_pKdTree, dPoints, Points.Num(), nIndexPack, 3);
				delete[] dPoints;
				dPoints = nullptr;
				delete[] nIndexPack;
				nIndexPack = nullptr;
			}

			KdTree::~KdTree()
			{
				_KDTree_Dispose(m_pKdTree);
				m_pKdTree = nullptr;
			}

			void KdTree::SearchKdTreeDis(Vector3d& searchPos, Gamedouble dRadius, Gameint& nPointSearch, TArray<Gameint>& nIndexArray, TArray<Gamedouble>& dDistanceArray)
			{
				Gameint* indexesPtr = nullptr;
				Gamedouble* distPtr = nullptr;
				_KDTree_SearchKdTreeDis2(m_pKdTree, searchPos.X, searchPos.Y, searchPos.Z, dRadius, nPointSearch, indexesPtr, distPtr);

				for (int i = 0; i < nPointSearch; i++)
				{
					nIndexArray.Add(indexesPtr[i]);
					dDistanceArray.Add(distPtr[i]);
				}

				if (nPointSearch > 0)
				{
					_FreeUGInt(indexesPtr);
					_FreeUGDouble(distPtr);
				}
			}
		}
	}
}