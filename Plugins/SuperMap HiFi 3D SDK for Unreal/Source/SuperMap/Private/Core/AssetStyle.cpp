#include "Core/AssetStyle.h"
#include "Engine/StaticMesh.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Component/SuperMap_ROEntityActor.h"
#include "Component/SuperMap_InstancedActor.h"
#include "Component/SuperMap_SplineActor.h"
#include "Core/ROCacheManager.h"
#include "Base3D/CommonDefine.h"
#include "ControlUE/CameraControl.h"
#include "Core/Georeference.h"
#include "Graphics3D/GameObjectManager.h"
#include "Algorithm3D/MathEngine.h"
#include "Data/Vector2d.h"

#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif
using namespace SuperMapSDK::UnrealEngine::ControlUE;
using namespace SuperMapSDK::UnrealEngine::Algorithm3D;
using namespace SuperMapSDK::UnrealEngine::Data;
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			AssetStyle::AssetStyle(UWorld* pWorld)
			{
				m_pWorld = pWorld;
				m_pInstancedActor = nullptr;
				m_pROEntityActor = nullptr;
				m_pSplineActor = nullptr;
			}

			AssetStyle::~AssetStyle()
			{
				if (m_pInstancedActor != nullptr)
				{
					uint32 nID = m_pInstancedActor->GetUniqueID();
					TMap<uint32, ASuperMap_InstancedActor*>& mapInstancedActor = GameObjectManager::GetSingleton()->GetInstancedActors();
					mapInstancedActor.Remove(nID);

					m_pInstancedActor->Destroy();
				}

				if (m_pSplineActor != nullptr)
				{
					uint32 nSplineID = m_pSplineActor->GetUniqueID();
					TMap<uint32, ASuperMap_SplineActor*>& mapSplineActor = GameObjectManager::GetSingleton()->GetSplineActors();
					mapSplineActor.Remove(nSplineID);
					m_pSplineActor->Destroy();
				}

				if (m_pROEntityActor != nullptr)
				{
					m_pROEntityActor->Destroy();
				}
			}

			void AssetStyle::SetStyleParam(StyleParam & styleParam)
			{
				m_StyleParam = styleParam;
			}

			StyleParam& AssetStyle::GetStyleParam()
			{
				return m_StyleParam;
			}

	
			FQuat AssetStyle::CallRotator(FVector vDirectionUP)
			{
				FVector vUp = vDirectionUP;
				vUp.Normalize();

				FVector vInitital(0, 0, 1);
				vInitital.Normalize();

				float fACos = FMath::Acos(FVector::DotProduct(vInitital, vUp));
				FVector vAxis = FVector::CrossProduct(vInitital, vUp);

				FQuat q(vAxis, fACos);

				FRotator r(0, 0, 0);

				FQuat qInitital(r);
				qInitital = q * qInitital;
				qInitital.Normalize();

				return qInitital;
			}

			UStaticMesh* AssetStyle::CreateStaticMesh(FString strAssetPath)
			{
				UStaticMesh* pStaticMesh = Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), nullptr, *strAssetPath));
				return pStaticMesh;
			}

			bool AssetStyle::BuildStyle(TArray<Vector3d> arrLocations)
			{
				if (m_pWorld == nullptr || arrLocations.Num() == 0)
				{
					return false;
				}

				if (m_StyleParam.m_strAssetResoureName.IsEmpty() ||
					m_StyleParam.m_strAssetResourePath.IsEmpty())
				{
					return false;
				}

				// 载入静态网格
				UStaticMesh* pStaticMesh = CreateStaticMesh(m_StyleParam.m_strAssetResourePath);
				if (pStaticMesh == nullptr)
				{
					return false;
				}

				if (m_pInstancedActor == nullptr)
				{
					m_pInstancedActor = m_pWorld->SpawnActor<ASuperMap_InstancedActor>();
					TMap<uint32, ASuperMap_InstancedActor*>& mapInstancedActor = GameObjectManager::GetSingleton()->GetInstancedActors();

					uint32 nID = m_pInstancedActor->GetUniqueID();
					mapInstancedActor.Add(nID, m_pInstancedActor);
				}

				m_pInstancedActor->m_pInstanceStaticMeshComponent->SetStaticMesh(pStaticMesh);

				// 最基础的模式（每个点上面）
				for (int32 nGeometry = 0; nGeometry < arrLocations.Num(); nGeometry++)
				{
					Matrix4d mat4dOrigin;
					FTransform trans;
					FTransform transOrigin;
					FVector vWorldOrigin = FVector(m_pWorld->OriginLocation);
					if (ControlUE::CameraControl::m_eSceneType == ControlUE::UGC_PLANE)
					{
						Vector3d vLocation_CE;
						vLocation_CE.X = arrLocations[nGeometry].Y * M_TO_CM;
						vLocation_CE.Y = arrLocations[nGeometry].X * M_TO_CM;
						vLocation_CE.Z = arrLocations[nGeometry].Z * M_TO_CM;

						transOrigin.SetLocation(vLocation_CE.ToFVector());

						Vector3d vLocationd = vLocation_CE - Vector3d(vWorldOrigin);
						trans.SetLocation(vLocationd.ToFVector());
						mat4dOrigin.SetTrans(vLocation_CE);
					}
					else if (CameraControl::m_eSceneType == UGC_EARTH ||
						CameraControl::m_eSceneType == UGC_EARTH_ELLIPSOID_WGS84)
					{
						Vector3d vSphericalLocation = arrLocations[nGeometry];


						// 通过经纬度计算矩阵
						Gamedouble* pMatrix = new Gamedouble[16];

						_CalMatrix(vSphericalLocation.X, vSphericalLocation.Y, vSphericalLocation.Z, pMatrix);

						Matrix4d matTransMatrix = MathEngine::UGCMatrixPtrToUEMatrix4d(pMatrix);
						mat4dOrigin = matTransMatrix;
						FMatrix matF;
						Matrix4d::ToFMatrix(matTransMatrix, matF);
						transOrigin.SetFromMatrix(matF);
						matTransMatrix = Georeference::TransformECEFToUERelative(matTransMatrix);
						Matrix4d::ToFMatrix(matTransMatrix, matF);
						trans.SetFromMatrix(matF);

						delete[] pMatrix;
						pMatrix = nullptr;
					}

					m_pInstancedActor->m_pInstanceStaticMeshComponent->AddInstance(trans);
					m_pInstancedActor->m_arrTrans.push_back(transOrigin);
					m_pInstancedActor->m_arrMatrixs.Add(mat4dOrigin);
				}

				return true;
			}


			bool AssetStyle::BuildStyle(TArray<FVector> arrLocations)
			{
				if (m_pWorld == nullptr || arrLocations.Num() == 0)
				{
					return false;
				}

				if (m_StyleParam.m_strAssetResoureName.IsEmpty() ||
					m_StyleParam.m_strAssetResourePath.IsEmpty())
				{
					return false;
				}

				// 载入静态网格
				UStaticMesh* pStaticMesh = CreateStaticMesh(m_StyleParam.m_strAssetResourePath);
				if (pStaticMesh == nullptr)
				{
					return false;
				}

				if (m_pInstancedActor == nullptr)
				{
					m_pInstancedActor = m_pWorld->SpawnActor<ASuperMap_InstancedActor>();
					TMap<uint32, ASuperMap_InstancedActor*>& mapInstancedActor = GameObjectManager::GetSingleton()->GetInstancedActors();
					
					uint32 nID = m_pInstancedActor->GetUniqueID();
					mapInstancedActor.Add(nID, m_pInstancedActor);
				}

				m_pInstancedActor->m_pInstanceStaticMeshComponent->SetStaticMesh(pStaticMesh);

				// 最基础的模式（每个点上面）
				for (int32 nGeometry = 0; nGeometry < arrLocations.Num(); nGeometry++)
				{
					Matrix4d mat4dOrigin;
					FTransform trans;
					FTransform transOrigin;
					FVector vWorldOrigin = FVector(m_pWorld->OriginLocation);
					if (ControlUE::CameraControl::m_eSceneType == ControlUE::UGC_PLANE)
					{
						Vector3d vLocation_CE;
						vLocation_CE.X = arrLocations[nGeometry].Y * M_TO_CM;
						vLocation_CE.Y = arrLocations[nGeometry].X * M_TO_CM;
						vLocation_CE.Z = arrLocations[nGeometry].Z * M_TO_CM;

						transOrigin.SetLocation(vLocation_CE.ToFVector());

						Vector3d vLocationd = vLocation_CE - Vector3d(vWorldOrigin);
						trans.SetLocation(vLocationd.ToFVector());
						mat4dOrigin.SetTrans(vLocation_CE);
					}
					else if (CameraControl::m_eSceneType == UGC_EARTH ||
						 CameraControl::m_eSceneType == UGC_EARTH_ELLIPSOID_WGS84)
					{
						FVector vSphericalLocation = arrLocations[nGeometry];
						FVector vRealLocation = Algorithm3D::MathEngine::SphericalToCartesian(vSphericalLocation.X, vSphericalLocation.Y, vSphericalLocation.Z);

						vRealLocation *= M_TO_CM;

						FQuat qRotation = CallRotator(vRealLocation);

						trans.SetLocation(vRealLocation);
						trans.SetRotation(qRotation);

						//地理原点设置
						FMatrix mat = trans.ToMatrixWithScale();
						mat4dOrigin = Matrix4d(mat);
						Matrix4d mat4d = Georeference::TransformECEFToUERelative(mat4dOrigin);
						Matrix4d::ToFMatrix(mat4d, mat);
						mat4dOrigin = mat;
						trans.SetFromMatrix(mat);
						transOrigin.SetLocation(vRealLocation);
						transOrigin.SetRotation(qRotation);
					}

					m_pInstancedActor->m_pInstanceStaticMeshComponent->AddInstance(trans);
					m_pInstancedActor->m_arrTrans.push_back(transOrigin);
					m_pInstancedActor->m_arrMatrixs.Add(mat4dOrigin);
				}

				return true;
			}

			bool AssetStyle::BuildStyle(TArray<Vector3d> arrPositions, TArray<int32> arrIndexs)
			{
				if (m_pWorld == nullptr || arrPositions.Num() == 0 || arrIndexs.Num() == 0)
				{
					return false;
				}

				if (m_StyleParam.m_strAssetResoureName.IsEmpty() ||
					m_StyleParam.m_strAssetResourePath.IsEmpty())
				{
					return false;
				}

				if (m_pROEntityActor == nullptr)
				{
					m_pROEntityActor = m_pWorld->SpawnActor<ASuperMap_ROEntityActor>();
				}


				//遍历顶点计算范围
				Vector2d vMax, vMin;
				for (int32 i = 0; i < arrPositions.Num(); i++)
				{
					if (i == 0)
					{
						vMax.X = arrPositions[i].X;
						vMax.Y = arrPositions[i].Y;
						vMin.X = arrPositions[i].X;
						vMin.Y = arrPositions[i].Y;
					}
					else
					{
						vMax.X = FMath::Max(arrPositions[i].X, vMax.X);
						vMax.Y = FMath::Max(arrPositions[i].Y, vMax.Y);
						vMin.X = FMath::Min(arrPositions[i].X, vMin.X);
						vMin.Y = FMath::Min(arrPositions[i].Y, vMin.Y);
					}
				}

				Vector2d vWidth = vMax - vMin;

				TArray<SM_Vertex> arrVtxs;//顶点
				for (int32 i = 0; i < arrPositions.Num(); i++)
				{
					Vector3d vPoint3d;
					if (ControlUE::CameraControl::m_eSceneType == ControlUE::UGC_PLANE)
					{
						vPoint3d = arrPositions[i] *= M_TO_CM;;
						Swap(vPoint3d.X, vPoint3d.Y);
						vPoint3d = Georeference::TransformUEAbsToUERelative(vPoint3d);
					}
					else if (ControlUE::CameraControl::m_eSceneType == ControlUE::UGC_EARTH ||
						ControlUE::CameraControl::m_eSceneType == UGC_EARTH_ELLIPSOID_WGS84)
					{
						vPoint3d = arrPositions[i];
						vPoint3d = MathEngine::SphericalToCartesian2(vPoint3d.X, vPoint3d.Y, vPoint3d.Z);
						vPoint3d = Georeference::TransformOriginECEFToUEReative(vPoint3d);
					}
					SM_Vertex sm_point;
					sm_point.Position = vPoint3d.ToFVector();
					sm_point.UV0 = FVector2D(((arrPositions[i].X - vMin.X) / vWidth.X), ((arrPositions[i].Y - vMin.Y) / vWidth.Y));

					sm_point.Color = FColor::Green;
					arrVtxs.Add(sm_point);
				}

				SM_SubMesh subMesh;
				if (m_pROEntityActor->GetMaterial() == nullptr)
				{
					UMaterialInterface* pMaterialInterface = LoadObject<UMaterialInterface>(nullptr, *m_StyleParam.m_strAssetResourePath);
					UMaterialInstanceDynamic* pMat = UMaterialInstanceDynamic::Create(pMaterialInterface, nullptr);
					subMesh.m_pMaterialInterface = pMat;
				}

				subMesh.IndexBuffer = arrIndexs;

				TArray<SM_SubMesh> arrSubMeshs;//mesh
				arrSubMeshs.Add(subMesh);


				m_pROEntityActor->SetDrawType(0);//0三角、2线
				m_pROEntityActor->CreateProceduralMesh(arrVtxs, arrSubMeshs);


				return true;
			}

			bool AssetStyle::BuildStyle(TArray<FVector> arrPositions, TArray<int32> arrIndexs)
			{

				if (m_pWorld == nullptr || arrPositions.Num() == 0 || arrIndexs.Num() == 0)
				{
					return false;
				}

				if (m_StyleParam.m_strAssetResoureName.IsEmpty() ||
					m_StyleParam.m_strAssetResourePath.IsEmpty())
				{
					return false;
				}

				if (m_pROEntityActor == nullptr)
				{
					m_pROEntityActor = m_pWorld->SpawnActor<ASuperMap_ROEntityActor>();
				}


				//遍历顶点计算范围
				FVector2D vMax, vMin;
				for (int32 i = 0; i < arrPositions.Num(); i++)
				{
					if (i == 0)
					{
						vMax.X = arrPositions[i].X;
						vMax.Y = arrPositions[i].Y;
						vMin.X = arrPositions[i].X;
						vMin.Y = arrPositions[i].Y;
					}
					else
					{
						vMax.X = FMath::Max(arrPositions[i].X, vMax.X);
						vMax.Y = FMath::Max(arrPositions[i].Y, vMax.Y); 
						vMin.X = FMath::Min(arrPositions[i].X, vMin.X);
						vMin.Y = FMath::Min(arrPositions[i].Y, vMin.Y); 
					}
				}

				FVector2D vWidth = vMax - vMin;

				TArray<SM_Vertex> arrVtxs;//顶点
				for (int32 i = 0; i < arrPositions.Num(); i++)
				{
					double dX = 0, dY = 0, dZ = 0;
					if (ControlUE::CameraControl::m_eSceneType == ControlUE::UGC_PLANE)
					{
						dX = arrPositions[i].Y;
						dY = arrPositions[i].X;
						dZ = arrPositions[i].Z;
					}
					else if (ControlUE::CameraControl::m_eSceneType == ControlUE::UGC_EARTH ||
						     ControlUE::CameraControl::m_eSceneType == UGC_EARTH_ELLIPSOID_WGS84)
					{
						Core::_SphericalToCartesian(arrPositions[i].X, arrPositions[i].Y, arrPositions[i].Z, dX, dY, dZ);
					}
					
					// 考虑地理源点和动态源点
					SM_Vertex point;
					Vector3d vecPt(dX*M_TO_CM, dY*M_TO_CM, dZ*M_TO_CM);
					if (CameraControl::m_eSceneType == UGC_EARTH ||
						CameraControl::m_eSceneType == UGC_EARTH_ELLIPSOID_WGS84)
					{
						vecPt.MultiplyMatrix(Georeference::GetECEFtoGeoreference());
						vecPt = vecPt - MathEngine::m_vWorldOffset;
					}
					point.Position = FVector(vecPt.X - m_pWorld->OriginLocation.X,
						vecPt.Y - m_pWorld->OriginLocation.Y,
 						vecPt.Z - m_pWorld->OriginLocation.Z);
					point.UV0 = FVector2D(((arrPositions[i].X - vMin.X) / vWidth.X), ((arrPositions[i].Y - vMin.Y) / vWidth.Y));

					point.Color = FColor::Green;
					arrVtxs.Add(point);
				}

				SM_SubMesh subMesh;
				if (m_pROEntityActor->GetMaterial() == nullptr)
				{
					UMaterialInterface* pMaterialInterface = LoadObject<UMaterialInterface>(nullptr, *m_StyleParam.m_strAssetResourePath);
					UMaterialInstanceDynamic* pMat = UMaterialInstanceDynamic::Create(pMaterialInterface, nullptr);
					subMesh.m_pMaterialInterface = pMat;
				}

				subMesh.IndexBuffer = arrIndexs;

				TArray<SM_SubMesh> arrSubMeshs;//mesh
				arrSubMeshs.Add(subMesh);


				m_pROEntityActor->SetDrawType(0);//0三角、2线
				m_pROEntityActor->CreateProceduralMesh(arrVtxs, arrSubMeshs);


				return true;
			}

			bool AssetStyle::BuildStyle(TArray<TArray<Vector3d>> arrLinesPts)
			{
				UStaticMesh* pStaticMesh = Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), nullptr, *m_StyleParam.m_strAssetResourePath));
				if (pStaticMesh == nullptr)
				{
					return false;
				}
				TMap<uint32, ASuperMap_SplineActor*>& mapSplineActor = GameObjectManager::GetSingleton()->GetSplineActors();
				if (m_pSplineActor != nullptr)
				{
					uint32 nSplineID = m_pSplineActor->GetUniqueID();
					mapSplineActor.Remove(nSplineID);
					m_pSplineActor->Destroy();
				}
				m_pSplineActor = m_pWorld->SpawnActor<ASuperMap_SplineActor>();
				uint32 nID = m_pSplineActor->GetUniqueID();
				mapSplineActor.Add(nID, m_pSplineActor);

				m_pSplineActor->SetInitPoints(arrLinesPts);
				// 考虑地理源点和动态
				for (Gameint i = 0; i < arrLinesPts.Num(); i++)
				{
					for (Gameint j = 0; j < arrLinesPts[i].Num(); j++)
					{
						Vector3d vecPt;
						if (CameraControl::m_eSceneType == UGC_PLANE)
						{

							vecPt.X = (arrLinesPts[i][j].Y - ROCacheManager::m_vPlaneOffset.Y) * M_TO_CM;
							vecPt.Y = (arrLinesPts[i][j].X - ROCacheManager::m_vPlaneOffset.X) * M_TO_CM;
							vecPt.Z = (arrLinesPts[i][j].Z - ROCacheManager::m_vPlaneOffset.Z) * M_TO_CM;
							vecPt = vecPt - Vector3d(m_pWorld->OriginLocation);
						}
						if (CameraControl::m_eSceneType == UGC_EARTH ||
							CameraControl::m_eSceneType == UGC_EARTH_ELLIPSOID_WGS84)
						{
							arrLinesPts[i][j] = MathEngine::SphericalToCartesian2(arrLinesPts[i][j].X, arrLinesPts[i][j].Y, arrLinesPts[i][j].Z);
							vecPt = arrLinesPts[i][j] * M_TO_CM;
							vecPt.MultiplyMatrix(Georeference::GetECEFtoGeoreference());
							vecPt = vecPt - MathEngine::m_vWorldOffset;
							vecPt = vecPt - Vector3d(m_pWorld->OriginLocation);
						}
						arrLinesPts[i][j] = vecPt.ToFVector();
					}
				}
				/*
				// 计算转角处的插入点
				TArray<TArray<Vector3d>> pts;
				for (Gameint i = 0; i < arrLinesPts.Num(); i++)
				{
					TArray<Vector3d> linePoints1;
					MathEngine::Chamfer(linePoints1, arrLinesPts[i], 5, false, 10);
					pts.Add(linePoints1);
				}

				//线段差值（用于特效线，分段）
				TArray<TArray<Vector3d>> pts1;
				GetSubdivisionPoints(arrLinesPts, pts1);
				*/
				m_pSplineActor->SetSplineStaticMesh(pStaticMesh);
				m_pSplineActor->CreateSplineMesh(arrLinesPts);
				if (m_pROEntityActor != nullptr)
				{
					m_pROEntityActor->Destroy();
					m_pROEntityActor = nullptr;
				}
				return true;
			}

			bool AssetStyle::BuildSubdivisionStyle(TArray<FVector> arrLocations)
			{
				if (m_pWorld == nullptr || arrLocations.Num() == 0)
				{
					return false;
				}

				if (m_StyleParam.m_strAssetResoureName.IsEmpty() ||
					m_StyleParam.m_strAssetResourePath.IsEmpty())
				{
					return false;
				}

				// 载入静态网格
				UStaticMesh* pStaticMesh = CreateStaticMesh(m_StyleParam.m_strAssetResourePath);
				if (pStaticMesh == nullptr)
				{
					return false;
				}
				if (m_pInstancedActor == nullptr)
				{
					m_pInstancedActor = m_pWorld->SpawnActor<ASuperMap_InstancedActor>();
					TMap<uint32, ASuperMap_InstancedActor*>& mapInstancedActor = GameObjectManager::GetSingleton()->GetInstancedActors();

					uint32 nID = m_pInstancedActor->GetUniqueID();
					mapInstancedActor.Add(nID, m_pInstancedActor);
				}
				m_pInstancedActor->m_pInstanceStaticMeshComponent->SetStaticMesh(pStaticMesh);

				// 最基础的模式（每个点上面）
				for (int32 nGeometry = 0; nGeometry < arrLocations.Num(); nGeometry++)
				{
					FTransform trans;
					FTransform transOrigin;
					FVector vWorldOrigin = FVector(m_pWorld->OriginLocation);
					Matrix4d mat4dOrigin;
					if (ControlUE::CameraControl::m_eSceneType == ControlUE::UGC_PLANE)
					{
						FVector vLocation_CE;
						vLocation_CE.X = arrLocations[nGeometry].Y * M_TO_CM;
						vLocation_CE.Y = arrLocations[nGeometry].X * M_TO_CM;
						vLocation_CE.Z = arrLocations[nGeometry].Z * M_TO_CM;
						transOrigin.SetLocation(vLocation_CE);
						FVector vLocation = vLocation_CE - vWorldOrigin;
						trans.SetLocation(vLocation);
					}
					else if (ControlUE::CameraControl::m_eSceneType == ControlUE::UGC_EARTH ||
						     ControlUE::CameraControl::m_eSceneType == UGC_EARTH_ELLIPSOID_WGS84)
					{
						FVector vRealLocation = arrLocations[nGeometry];

						vRealLocation *= M_TO_CM;

						FQuat qRotation = CallRotator(vRealLocation);

						trans.SetLocation(vRealLocation);
						trans.SetRotation(qRotation);

						//地理原点设置
						FMatrix mat = trans.ToMatrixWithScale();
						mat4dOrigin = Matrix4d(mat);
						Matrix4d mat4d = Georeference::TransformECEFToUERelative(mat4dOrigin);
						Matrix4d::ToFMatrix(mat4d, mat);
						trans.SetFromMatrix(mat);
						transOrigin.SetLocation(vRealLocation);
						transOrigin.SetRotation(qRotation);
					}

					m_pInstancedActor->m_pInstanceStaticMeshComponent->AddInstance(trans);
					m_pInstancedActor->m_arrMatrixs.Add(mat4dOrigin);
					m_pInstancedActor->m_arrTrans.push_back(transOrigin);
				}

				if (m_pROEntityActor != nullptr)
				{
					m_pROEntityActor->Destroy();
					m_pROEntityActor = nullptr;
				}

				return true;
			}

			void AssetStyle::GetSubdivisionPoints(TArray<TArray<Vector3d>>& pots1, TArray<TArray<Vector3d>>& pots2)
			{
				for (int pt = 0; pt < pots1.Num(); pt++)
				{
					TArray<Vector3d> arrLocations;
					TArray<Vector3d> arrPoints = pots1[pt];
					MathEngine::GetSubdivisionPoints2(arrPoints, arrLocations, 400);
					pots2.Add(arrLocations);
				}
			}
		}
	}
}
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif