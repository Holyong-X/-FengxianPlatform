#pragma once
#include "CoreMinimal.h"
#include "Data/Vector3d.h"
#include "Base3D/CommonDefine.h"

using namespace SuperMapSDK::UnrealEngine::Data;

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Algorithm3D
		{
			class SUPERMAP_API KdTree
			{
			public:
				KdTree();
				KdTree(TArray<Vector3d> Points);
				~KdTree();

				void SearchKdTreeDis(Vector3d& searchPos, Gamedouble dRadius, Gameint& nPointSearch, TArray<Gameint>& nIndexArray, TArray<Gamedouble>& dDistanceArray);
			private:
				void* m_pKdTree;
			};
			
		}
	}
}