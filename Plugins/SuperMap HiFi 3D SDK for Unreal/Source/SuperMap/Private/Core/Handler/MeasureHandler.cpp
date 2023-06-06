// Fill out your copyright notice in the Description page of Project Settings.

#include "Core/Handler/MeasureHandler.h"
#include "Engine/World.h"
#include "Core/SceneType.h"
#include "Core/ROCacheManager.h"
#include "ControlUE/CameraControl.h"
#include "Core/Georeference.h"
#include "Graphics3D/GameObjectManager.h"
using namespace SuperMapSDK::UnrealEngine::ControlUE;
using namespace SuperMapSDK;
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			MeasureHandler::MeasureHandler(UWorld* pWorld, Core::Scene* pScene, ControlUE::CameraControl* pCameraControl)
			{
				m_bHandlerStop = false;
				m_eMeasureAction = MeasureArea;
				m_dHeight = -999999999;
				m_pROEntityActor_Line = pWorld->SpawnActor<ASuperMap_ROEntityActor>();
				TArray<ASuperMap_ROEntityActor*>& arrLineMeshActors = GameObjectManager::GetSingleton()->GetLineMeshActors();
				arrLineMeshActors.Add(m_pROEntityActor_Line);
				m_pROEntityActor = pWorld->SpawnActor<ASuperMap_ROEntityActor>();
				m_pROEntityActor_Face = pWorld->SpawnActor<ASuperMap_ROEntityActor>();

				m_pMeasureText = pWorld->SpawnActor<ASuperMap_TextActor>();
				TArray<ASuperMap_TextActor*>& arrTextActors = GameObjectManager::GetSingleton()->GetTextActors();
				arrTextActors.Add(m_pMeasureText);
			}

			MeasureHandler::~MeasureHandler()
			{
				Release();
			}

			void MeasureHandler::Release()
			{
				m_pROEntityActor_Line->Destroy(false, false);
				m_pROEntityActor_Line = nullptr;

				m_pROEntityActor->Destroy(false, false);
				m_pROEntityActor = nullptr;

				m_pROEntityActor_Face->Destroy(false, false);
				m_pROEntityActor_Face = nullptr;

				m_listTargetPos.Empty();

				m_pMeasureText->Destroy(false, false);
				m_pMeasureText = nullptr;
			}

			void MeasureHandler::UpdateMeasure()
			{
				if (m_eMeasureAction == MeasureDistance)
				{
					TArray<SM_Vertex> arrVtxs;//顶点
					for (Gameint i = 0; i < m_listTargetPos.Num(); i++)
					{
						SM_Vertex point;
						point.Position = m_listTargetPos[i].ToFVector();
						point.Color = FColor::Green;
						arrVtxs.Add(point);
					}

					TArray<SM_SubMesh> arrSubMeshs;//mesh
					SM_SubMesh subMesh;

					if (m_pROEntityActor_Line->GetMaterial() == nullptr)
					{
						UMaterialInterface* pMaterialInterface = LoadObject<UMaterialInterface>(nullptr, *SM_LINERENDER_MAT);
						UMaterialInstanceDynamic* pMat = UMaterialInstanceDynamic::Create(pMaterialInterface, nullptr);
						pMat->AddToRoot();
						subMesh.m_pMaterialInterface = pMat;
						m_pROEntityActor_Line->SetMaterial(pMat);
					}

					Gameint nLineCount = m_listTargetPos.Num() - 1;

					TArray<Gameint> arrIndexs;//索引
					for (Gameint j = 0; j < nLineCount; j++)
					{
						arrIndexs.Add(j);
						arrIndexs.Add(j + 1);
					}
					subMesh.IndexBuffer = arrIndexs;
					arrSubMeshs.Add(subMesh);

					m_pROEntityActor_Line->SetDrawType(2);//0三角、2线
					m_pROEntityActor_Line->CreateLineMeshComponent(arrVtxs, arrSubMeshs);

					Gamedouble dDistanceTotal = 0.;
					TArray<Gamedouble> arrResults = GetCurLength();
					FVector vLocation;
					FString strResult;
					if (m_listTargetPos.Num() == 1 && m_bHandlerStop)
					{
						m_pMeasureText->SetParam(vLocation, 1000, FColor::Red, FText::FromString(FString("")));
					}
					if (arrVtxs.Num() > 1)
					{
						for (Gameint i = 0; i < arrResults.Num() - 1; i++)
						{
							dDistanceTotal += arrResults[i];
						}					
						// 点选右键
						if (m_bHandlerStop)
						{
							strResult = FString::Printf(TEXT(" Total Dist. : %.2f  m"), (dDistanceTotal + arrResults[arrResults.Num() - 1] ) / 100.f);
						}
						// 未点选右键
						else
						{
							strResult = FString::Printf(TEXT(" Current Dist. : %.2f m, "), (arrResults[arrResults.Num() - 1] / 100.f)) + FString::Printf(TEXT("Total Dist. : %.2f  m"), ( dDistanceTotal + arrResults[arrResults.Num() - 1] )/ 100.f);
						}
						vLocation = arrVtxs[arrVtxs.Num() - 1].Position;
						m_pMeasureText->SetParam(vLocation, 1000, FColor::Red, FText::FromString(strResult));		
					}		
					
				}
				else if (m_eMeasureAction == MeasureArea)
				{
					TArray<SM_Vertex> arrVtxs;//顶点
					for (Gameint i = 0; i < m_listTargetPos.Num(); i++)
					{
						SM_Vertex point;
						point.Position = m_listTargetPos[i].ToFVector();
						point.Color = FColor::Yellow;
						arrVtxs.Add(point);
					}

					TArray<SM_SubMesh> arrSubMeshs;//mesh
					SM_SubMesh subMesh;

					if (m_pROEntityActor_Line->GetMaterial() == nullptr)
					{
						UMaterialInterface* pMaterialInterface = LoadObject<UMaterialInterface>(nullptr, *SM_LINERENDER_MAT);
						UMaterialInstanceDynamic* pMat = UMaterialInstanceDynamic::Create(pMaterialInterface, nullptr);
						pMat->AddToRoot();
						subMesh.m_pMaterialInterface = pMat;
						m_pROEntityActor_Line->SetMaterial(pMat);
					}

					Gameint nLineCount = m_listTargetPos.Num() - 1;

					TArray<Gameint> arrIndexs;//索引
					for (Gameint j = 0; j < nLineCount; j++)
					{
						arrIndexs.Add(j);
						arrIndexs.Add(j + 1);
					}
					arrIndexs.Add(m_listTargetPos.Num() - 1);
					arrIndexs.Add(0);

					subMesh.IndexBuffer = arrIndexs;
					arrSubMeshs.Add(subMesh);

					m_pROEntityActor_Line->SetDrawType(2);//0三角、2线
					m_pROEntityActor_Line->CreateLineMeshComponent(arrVtxs, arrSubMeshs);

					FString strResult = FString::Printf(TEXT(" Area : %.2f  m^2"), (GetArea() / 10000.f));
					FVector vLocation = FVector::ZeroVector;

					vLocation = arrVtxs[arrVtxs.Num() - 1].Position;
					m_pMeasureText->SetParam(vLocation, 1000, FColor::Red, FText::FromString(strResult));

				}
				else if (m_eMeasureAction == MeasureHeight && m_listTargetPos.Num() >= 2)
				{
					TArray<SM_Vertex> arrVtxs;
					SM_Vertex v1;
					v1.Position = m_listTargetPos[0].ToFVector();
					v1.Color = FColor::Green;
					arrVtxs.Add(v1);
					if (CameraControl::m_eSceneType == UGC_EARTH ||
						CameraControl::m_eSceneType == UGC_EARTH_ELLIPSOID_WGS84)
					{
						//地球动态坐标原点
						Vector3d vPos0 = Georeference::TransformUERelativeToGeorefenceECEF(m_listTargetPos[0]);
						Vector3d vPos1 = Georeference::TransformUERelativeToGeorefenceECEF(m_listTargetPos[1]);

						Gamedouble height0 = vPos0.Magnitude();
						Gamedouble height1 = vPos1.Magnitude();
						
						Vector3d vPosition;
						if (height1 > height0)
						{
							vPosition = vPos0;
							vPosition = vPosition.Normalize() * height1;
						}
						else
						{
							vPosition = vPos1;
							vPosition = vPosition.Normalize() * height0;
						}
						
						SM_Vertex v2;
						v2.Position = Georeference::TransformGeorefenceECEFToUERelative(vPosition).ToFVector();
						v2.Color = FColor::Green;
						arrVtxs.Add(v2);
					}
					else if (CameraControl::m_eSceneType == UGC_PLANE)
					{
						SM_Vertex v2;
						FVector vCenter;
						if (m_listTargetPos[0].Z > m_listTargetPos[1].Z)
						{
							vCenter.X = m_listTargetPos[1].X;
							vCenter.Y = m_listTargetPos[1].Y;
							vCenter.Z = m_listTargetPos[0].Z;
						}
						else
						{
							vCenter.X = m_listTargetPos[0].X;
							vCenter.Y = m_listTargetPos[0].Y;
							vCenter.Z = m_listTargetPos[1].Z;
						}
						v2.Position = vCenter;
						v2.Color = FColor::Green;
						arrVtxs.Add(v2);
					}
					SM_Vertex v3;
					v3.Position = m_listTargetPos[1].ToFVector();
					v3.Color = FColor::Green;
					arrVtxs.Add(v3);
					TArray<SM_SubMesh> arrSubMeshs;
					SM_SubMesh subMesh;
					if (m_pROEntityActor_Line->GetMaterial() == nullptr)
					{
						UMaterialInterface* pMaterialInterface = LoadObject<UMaterialInterface>(nullptr, *SM_LINERENDER_MAT);
						UMaterialInstanceDynamic* pMat = UMaterialInstanceDynamic::Create(pMaterialInterface, nullptr);
						pMat->AddToRoot();
						subMesh.m_pMaterialInterface = pMat;
						m_pROEntityActor_Line->SetMaterial(pMat);
					}
					TArray<Gameint> arrIndexs;
					arrIndexs.Add(0);
					arrIndexs.Add(1);
					arrIndexs.Add(1);
					arrIndexs.Add(2);
					subMesh.IndexBuffer = arrIndexs;
					arrSubMeshs.Add(subMesh);
					m_pROEntityActor_Line->SetDrawType(2);
					m_pROEntityActor_Line->CreateLineMeshComponent(arrVtxs, arrSubMeshs);


					FString strResult = FString::Printf(TEXT(" Height : %.2f m"), GetHeight());
					FVector vLocation = arrVtxs[arrVtxs.Num() - 2].Position;
					m_pMeasureText->SetParam(vLocation, 1000, FColor::Red, FText::FromString(strResult));

				}
				else if (m_eMeasureAction == MeasureHorizontalDistance)
				{
					TArray<SM_Vertex> arrVtxs;//顶点
					SM_Vertex point1;
					point1.Position = m_listTargetPos[0].ToFVector();
					point1.Color = FColor::Green;
					arrVtxs.Add(point1);
					if (CameraControl::m_eSceneType == UGC_EARTH ||
						CameraControl::m_eSceneType == UGC_EARTH_ELLIPSOID_WGS84)
					{
						for (Gameint i = 0; i < m_listTargetPos.Num(); i++)
						{
							Vector3d vPosition = Georeference::TransformUERelativeToGeorefenceECEF(m_listTargetPos[i]);
							vPosition = vPosition.Normalize();
							vPosition *= (m_dHeight * CM_TO_M);

							SM_Vertex point;
							point.Position = Georeference::TransformGeorefenceECEFToUERelative(vPosition).ToFVector();
							point.Color = FColor::Green;
							arrVtxs.Add(point);
						}
					}
					else if (CameraControl::m_eSceneType == UGC_PLANE)
					{
						for (Gameint i = 0; i < m_listTargetPos.Num(); i++)
						{
							SM_Vertex point;
							FVector vector = m_listTargetPos[i].ToFVector();
							vector.Z = m_dHeight;
							point.Position = vector;
							point.Color = FColor::Green;
							arrVtxs.Add(point);
						}
					}
					point1.Position = m_listTargetPos[m_listTargetPos.Num() - 1].ToFVector();
					point1.Color = FColor::Green;
					arrVtxs.Add(point1);

					TArray<SM_SubMesh> arrSubMeshs;
					SM_SubMesh subMesh;
					if (m_pROEntityActor_Line->GetMaterial() == nullptr)
					{
						UMaterialInterface* pMaterialInterface = LoadObject<UMaterialInterface>(nullptr, *SM_LINERENDER_MAT);
						UMaterialInstanceDynamic* pMat = UMaterialInstanceDynamic::Create(pMaterialInterface, nullptr);
						pMat->AddToRoot();
						subMesh.m_pMaterialInterface = pMat;
						m_pROEntityActor_Line->SetMaterial(pMat);
					}
					TArray<Gameint> arrIndexs;

					for (Gameint j = 0; j < m_listTargetPos.Num() + 1; j++)
					{
						arrIndexs.Add(j);
						arrIndexs.Add(j + 1);
					}

					subMesh.IndexBuffer = arrIndexs;
					arrSubMeshs.Add(subMesh);
					m_pROEntityActor_Line->SetDrawType(2);
					m_pROEntityActor_Line->CreateLineMeshComponent(arrVtxs, arrSubMeshs);
					Gamedouble dDistanceTotal = 0.;
					TArray<Gamedouble> arrResults = GetCurLength();
					FVector vLocation;
					FString strResult;
					if (m_listTargetPos.Num() == 1 && m_bHandlerStop )
					{
						m_pMeasureText->SetParam(vLocation, 1000, FColor::Red, FText::FromString(FString("")));
						
						arrVtxs.Empty();
						arrSubMeshs.Empty();

						m_pROEntityActor_Line->CreateLineMeshComponent(arrVtxs, arrSubMeshs);

					}
					if (arrResults.Num() >= 1)
					{
						for (Gameint i = 0; i < arrResults.Num() - 1; i++)
						{
							dDistanceTotal += arrResults[i];
						}
						// 点选右键
						if (m_bHandlerStop)
						{		
							strResult = FString::Printf(TEXT("Total H. Dist. : %.2f m"), (dDistanceTotal + arrResults[arrResults.Num() - 1]) / 100.f);
						}
						// 未点选右键
						else
						{
							strResult = FString::Printf(TEXT(" H. Dist. : %.2f m, "), arrResults[arrResults.Num() - 1] / 100.f) + FString::Printf(TEXT("Total H. Dist. : %.2f m"), (dDistanceTotal + arrResults[arrResults.Num() - 1]) / 100.f);
						}
						vLocation = arrVtxs[arrVtxs.Num() - 2].Position;
						m_pMeasureText->SetParam(vLocation, 1000, FColor::Red, FText::FromString(strResult));
					}
				}
			}

			void MeasureHandler::UpdateMeasureArea()
			{
				TArray<SM_Vertex> arrVtxs;//顶点
				for (Gameint i = 0; i < m_listTargetPos.Num(); i++)
				{
					SM_Vertex point;
					point.Position = m_listTargetPos[i].ToFVector();
					point.Color = FColor::Green;
					arrVtxs.Add(point);
				}

				TArray<SM_SubMesh> arrSubMeshs;//mesh
				SM_SubMesh subMesh;
				if (m_pROEntityActor_Face->GetMaterial() == nullptr)
				{
					UMaterialInterface* pMaterialInterface = LoadObject<UMaterialInterface>(nullptr, *SM_LINERENDER_MAT);
					UMaterialInstanceDynamic* pMat = UMaterialInstanceDynamic::Create(pMaterialInterface, nullptr);
					pMat->SetScalarParameterValue(FName("Transparent"), 0.2);
					pMat->AddToRoot();
					subMesh.m_pMaterialInterface = pMat;
					m_pROEntityActor_Face->SetMaterial(pMat);
				}
				else
				{
					UMaterialInstanceDynamic* pMat = (UMaterialInstanceDynamic*)m_pROEntityActor_Face->GetMaterial();
					pMat->SetScalarParameterValue(FName("Transparent"), 0.2);
				}

				TArray<Gameint> arrIndexs;//索引
				GeoRegion3D geoRegion3D;
				geoRegion3D.SetPoints(m_listTargetPos);
				geoRegion3D.GetTriangleIndices(arrIndexs);

				subMesh.IndexBuffer = arrIndexs;
				arrSubMeshs.Add(subMesh);

				m_pROEntityActor_Face->SetDrawType(0);//0三角、2线
				m_pROEntityActor_Face->CreateProceduralMesh(arrVtxs, arrSubMeshs);
			}

			void MeasureHandler::MeasureAreaEnd()
			{
				if (m_eMeasureAction == MeasureArea)
				{
					UpdateMeasureArea();
				}
			}

			double MeasureHandler::GetArea()
			{
				Gamedouble dArea = 0;
				TArray<Gameint> arrIndexs;//索引

				SuperMapSDK::UnrealEngine::Data::GeoRegion3D geoRegion3D = SuperMapSDK::UnrealEngine::Data::GeoRegion3D();
				geoRegion3D.SetPoints(m_listTargetPos);
				geoRegion3D.GetTriangleIndices(arrIndexs);
				for (Gameint j = 0; j < arrIndexs.Num(); j++)
				{
					if (arrIndexs[j] >= m_listTargetPos.Num())
					{
						arrIndexs[j] -= m_listTargetPos.Num();
					}
				}
				for (Gameint i = 0; i < arrIndexs.Num() / 3; i++)
				{
					FVector point1 = m_listTargetPos[arrIndexs[i * 3]].ToFVector();
					FVector point2 = m_listTargetPos[arrIndexs[i * 3 + 1]].ToFVector();
					FVector point3 = m_listTargetPos[arrIndexs[i * 3 + 2]].ToFVector();
				
					FVector point12 = point2 - point1;
					FVector point13 = point3 - point1;
				
					FVector vTempVector = FVector::CrossProduct(point12, point13);
					Gamedouble dSingeArea = 0.5 * sqrt(vTempVector | vTempVector);
				
					dArea += dSingeArea;
				}

				return dArea;
			}

			Gamedouble MeasureHandler::GetHeight()
			{
				Gamedouble height = 0;
				if (m_listTargetPos.Num() >= 2)
				{
					if (CameraControl::m_eSceneType == UGC_EARTH ||
						CameraControl::m_eSceneType == UGC_EARTH_ELLIPSOID_WGS84)
					{
						Vector3d v0 = Georeference::TransformUERelativeToGeorefenceECEF(m_listTargetPos[0]);
						Vector3d v1 = Georeference::TransformUERelativeToGeorefenceECEF(m_listTargetPos[1]);

						height = v1.Magnitude() - v0.Magnitude();
					}
					else if (CameraControl::m_eSceneType == UGC_PLANE)
					{
						height = m_listTargetPos[1].Z - m_listTargetPos[0].Z;
						height *= CM_TO_M;
					}
				}
				return abs(height);
			}

			TArray<Gamedouble> MeasureHandler::GetCurLength()
			{
				TArray<Gamedouble> arrCurLength;
				if (m_eMeasureAction == MeasureDistance)
				{
					for (Gameint i = 0; i < m_listTargetPos.Num() - 1; i++)
					{
						Gamedouble length = sqrt((m_listTargetPos[i + 1].X - m_listTargetPos[i].X)*(m_listTargetPos[i + 1].X - m_listTargetPos[i].X) + (m_listTargetPos[i + 1].Y - m_listTargetPos[i].Y)*(m_listTargetPos[i + 1].Y - m_listTargetPos[i].Y) + (m_listTargetPos[i + 1].Z - m_listTargetPos[i].Z)*(m_listTargetPos[i + 1].Z - m_listTargetPos[i].Z));
						arrCurLength.Add(length);
					}
				}
				else if (m_eMeasureAction == MeasureHorizontalDistance)
				{
					for (Gameint i = 0; i < m_listTargetPos.Num() - 1; i++)
					{
						FVector p1 = CalculateForHorizontal(m_listTargetPos[i + 1]);
						FVector p2 = CalculateForHorizontal(m_listTargetPos[i]);
						Gamedouble length = sqrt((p1.X - p2.X)*(p1.X - p2.X) + (p1.Y - p2.Y)*(p1.Y - p2.Y) + (p1.Z - p2.Z)*(p1.Z - p2.Z));
						arrCurLength.Add(length);
					}					
				}
				return arrCurLength;
			}

			FVector MeasureHandler::CalculateForHorizontal(Vector3d Target)
			{
				FVector point;
				if (CameraControl::m_eSceneType == UGC_EARTH ||
					CameraControl::m_eSceneType == UGC_EARTH_ELLIPSOID_WGS84)
				{
					Vector3d vPosition = Georeference::TransformUERelativeToGeorefenceECEF(Target);
					vPosition = vPosition.Normalize();
					vPosition *= (m_dHeight*CM_TO_M);

					point = Georeference::TransformGeorefenceECEFToUERelative(vPosition).ToFVector();
				}
				else if (CameraControl::m_eSceneType == UGC_PLANE)
				{
					FVector vector = Target.ToFVector();
					vector.Z = m_dHeight;
					point = vector;
				}
				return point;
			}

			void MeasureHandler::SetMeasureAction(MeasureHandler::MeasureAction Measureaction)
			{
				m_eMeasureAction = Measureaction;
			}

			MeasureHandler::MeasureAction MeasureHandler::GetMeasureAction()
			{
				return m_eMeasureAction;
			}

			void MeasureHandler::SetTargetPoint(Gameint nIndex, Vector3d vPoint)
			{
				if (m_listTargetPos.Num() < nIndex + 1)
				{
					return;
				}

				m_listTargetPos[nIndex] = vPoint;

				if (m_eMeasureAction == MeasureHorizontalDistance)
				{
					if (CameraControl::m_eSceneType == UGC_PLANE)
					{
						GetTargetPointMaxHeight();
						if (m_dHeight < vPoint.Z)
						{
							m_dHeight = vPoint.Z;
						}
					}
					else if (CameraControl::m_eSceneType == UGC_EARTH ||
						     CameraControl::m_eSceneType == UGC_EARTH_ELLIPSOID_WGS84)
					{
						Vector3d vPos = Georeference::TransformUERelativeToGeorefenceECEF(vPoint);
						Gamedouble dLen = vPos.Magnitude() * M_TO_CM;

						GetTargetPointMaxHeight();
						if (m_dHeight < dLen)
						{
							m_dHeight = dLen;
						}
					}
				}
			}

			void MeasureHandler::GetTargetPointMaxHeight()
			{
				Gamedouble height = -999999999;
				for (Gameint i = 0; i < m_listTargetPos.Num(); i++)
				{
					if (CameraControl::m_eSceneType == UGC_PLANE)
					{
						if (height < m_listTargetPos[i].Z)
						{
							height = m_listTargetPos[i].Z;
						}
					}
					else if (CameraControl::m_eSceneType == UGC_EARTH ||
							CameraControl::m_eSceneType == UGC_EARTH_ELLIPSOID_WGS84)
					{
						Vector3d vPos = Georeference::TransformUERelativeToGeorefenceECEF(m_listTargetPos[i]);
						Gamedouble dLen = vPos.Magnitude() * M_TO_CM;

						if (height < dLen)
						{
							height = dLen;
						}
					}
				}
				m_dHeight = height;
			}

			FVector MeasureHandler::GetTargetPoint(Gameint nIndex)
			{
				return m_listTargetPos[nIndex].ToFVector();
			}

			void MeasureHandler::AddTargetPoint(Vector3d vPoint)
			{
				m_listTargetPos.Add(vPoint);
			}

			int MeasureHandler::GetTargetPointCount()
			{
				return m_listTargetPos.Num();
			}

			void MeasureHandler::RemoveTargetPoint(Gameint nIndex)
			{
				m_listTargetPos.RemoveAt(nIndex);
			}

			void MeasureHandler::SetHandlerStop(Gamebool bStop)
			{
				m_bHandlerStop = bStop;
			}

			Gamebool MeasureHandler::GetHandlerStop()
			{
				return m_bHandlerStop;
			}

		}
	}
}

