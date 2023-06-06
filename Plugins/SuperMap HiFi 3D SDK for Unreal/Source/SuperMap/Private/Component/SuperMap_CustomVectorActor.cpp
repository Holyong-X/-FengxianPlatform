#include "Component/SuperMap_CustomVectorActor.h"
#include "Core/Georeference.h"
#include "ControlUE/CameraControl.h"
#include "Algorithm3D/MathEngine.h"

#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif

using namespace SuperMapSDK::UnrealEngine::Algorithm3D;

ASuperMap_CustomVectorActor::ASuperMap_CustomVectorActor()
{
	PrimaryActorTick.bCanEverTick = true;
	m_pLineBatchComponent = CreateDefaultSubobject<ULineBatchComponent>(TEXT("Root"));
	SetRootComponent(m_pLineBatchComponent);
}

ASuperMap_CustomVectorActor::~ASuperMap_CustomVectorActor()
{

}

Gamevoid ASuperMap_CustomVectorActor::DrawPoints(TArray<GeoPoint3D*> arrPoints, Gamebool bReplaceOldPoints)
{
	if (bReplaceOldPoints)
	{
		m_vPoints = arrPoints;
	}
	
	if (m_pLineBatchComponent)
	{
		Gameint nCount = arrPoints.Num();
		for (Gameint n = 0; n < nCount; n++)
		{
			GeoPoint3D* pPoint = arrPoints[n];

			Vector3d vPoint = pPoint->GetPoint3D();

			if (CameraControl::m_eSceneType == UGC_PLANE)
			{
				vPoint *= M_TO_CM;
				Swap(vPoint.X, vPoint.Y);
				vPoint = Georeference::TransformUEAbsToUERelative(vPoint);
			}
			else if (CameraControl::m_eSceneType == UGC_EARTH ||
				CameraControl::m_eSceneType == UGC_EARTH_ELLIPSOID_WGS84)
			{
				vPoint = MathEngine::SphericalToCartesian2(vPoint.X, vPoint.Y, vPoint.Z);
				vPoint = Georeference::TransformOriginECEFToUEReative(vPoint);
			}

			FBatchedPoint batchPoint;
			batchPoint.Position = vPoint.ToFVector();
			batchPoint.Color = FLinearColor(1.0,0.0,0.0,1.0);
			batchPoint.PointSize = 5;
			batchPoint.RemainingLifeTime = 0;
			batchPoint.DepthPriority = SDPG_MAX;

			m_pLineBatchComponent->BatchedPoints.Add(batchPoint);
		}

		m_pLineBatchComponent->MarkRenderStateDirty();
	}
}

Gamevoid ASuperMap_CustomVectorActor::DrawLines(TArray<GeoLine3D*> arrLines, Gamebool bReplaceOldPoints)
{
	if (bReplaceOldPoints)
	{
		m_vLines = arrLines;
	}

	if (m_pLineBatchComponent)
	{
		Gameint nCount = arrLines.Num();
		for (Gameint n = 0; n < nCount; n++)
		{
			GeoLine3D* pLine = arrLines[n];

			TArray<Vector3d> arrPoints;
			pLine->GetPoints(arrPoints);

			for (Gameint k = 0; k < arrPoints.Num() - 1; k++)
			{
				Vector3d vStart = arrPoints[k];
				Vector3d vEnd = arrPoints[k+1];

				if (CameraControl::m_eSceneType == UGC_PLANE)
				{
					vStart *= M_TO_CM;
					Swap(vStart.X, vStart.Y);
					vStart = Georeference::TransformUEAbsToUERelative(vStart);

					vEnd *= M_TO_CM;
					Swap(vEnd.X, vEnd.Y);
					vEnd = Georeference::TransformUEAbsToUERelative(vEnd);
				}
				else if (CameraControl::m_eSceneType == UGC_EARTH ||
					CameraControl::m_eSceneType == UGC_EARTH_ELLIPSOID_WGS84)
				{
					vStart = MathEngine::SphericalToCartesian2(vStart.X, vStart.Y, vStart.Z);
					vStart = Georeference::TransformOriginECEFToUEReative(vStart);

					vEnd = MathEngine::SphericalToCartesian2(vEnd.X, vEnd.Y, vEnd.Z);
					vEnd = Georeference::TransformOriginECEFToUEReative(vEnd);
				}

				FBatchedLine batchLine;
				batchLine.Start = vStart.ToFVector();
				batchLine.End   = vEnd.ToFVector();
				batchLine.Color = FColor::Red;
				batchLine.Thickness = 5;
				batchLine.RemainingLifeTime = 0.0;
				batchLine.DepthPriority = SDPG_MAX;

				m_pLineBatchComponent->BatchedLines.Add(batchLine);
			}
		}

		m_pLineBatchComponent->MarkRenderStateDirty();
	}
}

Gamevoid ASuperMap_CustomVectorActor::DrawRegions(TArray<GeoRegion3D*> arrRegions, Gamebool bReplaceOldPoints)
{
	if (bReplaceOldPoints)
	{
		m_vRegions = arrRegions;
	}

	if (m_pLineBatchComponent)
	{
		Gameint nCount = arrRegions.Num();
		for (Gameint n = 0; n < nCount; n++)
		{
			GeoRegion3D* pRegion = arrRegions[n];

			TArray<Vector3d> arrPoints;
			pRegion->GetPoints(arrPoints);

			TArray<Gameint> arrIndexs;
			pRegion->GetTriangleIndices(arrIndexs);

			TArray<FVector> arrPointFs;
			for (Gameint k = 0; k < arrPoints.Num(); k++)
			{
				Vector3d v1 = arrPoints[k];

				if (CameraControl::m_eSceneType == UGC_PLANE)
				{
					v1 *= M_TO_CM;
					Swap(v1.X, v1.Y);
					v1 = Georeference::TransformUEAbsToUERelative(v1);
				}
				else if (CameraControl::m_eSceneType == UGC_EARTH ||
					CameraControl::m_eSceneType == UGC_EARTH_ELLIPSOID_WGS84)
				{
					v1 = MathEngine::SphericalToCartesian2(v1.X, v1.Y, v1.Z);
					v1 = Georeference::TransformOriginECEFToUEReative(v1);
				}

				arrPointFs.Add(v1.ToFVector());
			}

			FBatchedMesh batchMesh;
			batchMesh.MeshVerts = arrPointFs;
			batchMesh.MeshIndices = arrIndexs;
			batchMesh.Color = FColor::Red;
			batchMesh.RemainingLifeTime = 0.0;
			batchMesh.DepthPriority = SDPG_MAX;

			m_pLineBatchComponent->BatchedMeshes.Add(batchMesh);
		}

		m_pLineBatchComponent->MarkRenderStateDirty();
	}
}

Gamevoid ASuperMap_CustomVectorActor::UpdateWorldOrigin()
{
	if (m_pLineBatchComponent)
	{
		m_pLineBatchComponent->Flush();
	}

	DrawPoints(m_vPoints, false); 
	DrawLines(m_vLines, false);
	DrawRegions(m_vRegions, false);
}

Gamevoid ASuperMap_CustomVectorActor::ApplyWorldOffset(const FVector& InOffset, Gamebool bWorldShift)
{

}

Gamevoid ASuperMap_CustomVectorActor::Flush()
{
	if (m_pLineBatchComponent)
	{
		m_pLineBatchComponent->Flush();
	}
}

#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif