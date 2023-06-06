#include "Core/Layer3DDatasetModel.h"
#include "Engine/World.h"
#include "Engine/StaticMesh.h"
#include "Component/SuperMap_StaticMeshActor.h"
#include "Materials/MaterialInstanceConstant.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "ControlUE/RealspaceView.h"
#include "Kismet/GameplayStatics.h"
#if WITH_EDITOR
#include "AssetToolsModule.h"
#include "AssetRegistry/Public/AssetRegistryModule.h"
#include "Factories/MaterialInstanceConstantFactoryNew.h"
#endif
#include "Runtime/Core/Public/Misc/FileHelper.h"
#include "Runtime/Json/Public/Serialization/JsonSerializer.h"
#include "mikktspace.h"
#include "Data/AssetLibrary.h"
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif
using namespace SuperMapSDK::UnrealEngine::ControlUE;
using namespace SuperMapSDK::UnrealEngine::Data;
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			
			Layer3DDatasetModel::Layer3DDatasetModel()
			{
				m_pDataset = nullptr;
			}

			Layer3DDatasetModel::Layer3DDatasetModel(void* pUGLayer3D, FName strLayerName, Layer3DType eLayerType) :Layer3D(pUGLayer3D, strLayerName, eLayerType)
			{
				m_pDataset = nullptr;
				m_pWorld = nullptr;
				m_vPosition = FVector(0,0,0);
			}

			Layer3DDatasetModel::~Layer3DDatasetModel()
			{

			}

			void Layer3DDatasetModel::AddNativeGameComponent(GameComponent* pGameComponent)
			{
				m_mapNativeGameComponent.Add(pGameComponent->GetNodeName(), pGameComponent);
				if (m_bIsViewport)
				{
					if (pGameComponent != nullptr)
					{
						USuperMap_MeshComponentInterface* pComponent = pGameComponent->GetSceneNode();
						if (pComponent != nullptr)
						{
							pComponent->SetVisibleInViewport(0, m_bVisibleInViewport[0]);
							pComponent->SetVisibleInViewport(1, m_bVisibleInViewport[1]);
						}
					}
				}
				UpdateShaderForOneNativeGameComponent(pGameComponent);
			}

			void Layer3DDatasetModel::RemoveNativeGameComponent(GameComponent* pGameComponent)
			{
				m_mapNativeGameComponent.Remove(pGameComponent->GetNodeName());
			}

			void Layer3DDatasetModel::UpdateShaderForOneNativeGameComponent(GameComponent* pGameComponent)
			{
				TArray<GameMaterial*> &listGameMaterial = pGameComponent->GetAllGameMaterial();
				for (int i = 0; i < listGameMaterial.Num(); i++)
				{
					GameMaterial* pGameMaterial = listGameMaterial[i];
					if (pGameMaterial == nullptr)
					{
						continue;
					}

					// 更新图层需要替换的材质
					UpdateObjectMaterialInfo(pGameMaterial);
				}
				pGameComponent->SetLayerName(m_strLayerName.ToString());
			}

			void Layer3DDatasetModel::UpdateObjectMaterialInfo(GameMaterial* pGameMaterial)
			{
				FString strMaterialOriginName = pGameMaterial->GetMaterialOrginName();

				Gamebool isFind = (m_ObjectMaterialInfo.m_mapMaterialNameChanges.Find(strMaterialOriginName) != nullptr);
				FString strNewMaterialPath = "";
				if (isFind)
				{
					strNewMaterialPath = m_ObjectMaterialInfo.m_mapMaterialNameChanges[strMaterialOriginName].AssociateMaterialPath;
				}

				if (strNewMaterialPath == "")
				{
					//初始化替换材质
					Gameint nIndex = 0;
					if (strMaterialOriginName.FindChar(TCHAR('_'), nIndex))
					{
						int32 nStrCount = strMaterialOriginName.Len() - nIndex;
						strMaterialOriginName.RemoveAt(nIndex, nStrCount);
						strNewMaterialPath = GetHomologousAsset(strMaterialOriginName);
						if (strNewMaterialPath == "")
						{
							return;
						}
					}
					else
					{
						return;
					}

					AssociateMaterialInfo info;
					info.AssociateMaterialPath = strNewMaterialPath;

					m_ObjectMaterialInfo.m_mapMaterialNameChanges[strMaterialOriginName] = info;
				}

				UMaterialInstanceDynamic* pMID = pGameMaterial->GetMID();
				// 创建材质
				UMaterialInterface* pMaterialInterface = LoadObject<UMaterialInterface>(nullptr, *strNewMaterialPath);
				UMaterialInstanceDynamic* pNewMID = UMaterialInstanceDynamic::Create(pMaterialInterface, nullptr);
				pNewMID->AddToRoot();
				//pNewMID->CopyMaterialUniformParameters(pMID);
				pGameMaterial->SetMID(pNewMID);
				pGameMaterial->UpdateShaderParam();
			}

			FString Layer3DDatasetModel::GetHomologousAsset(FString strKey)
			{
				TMap<FString, FString> mapMaterialAsset = AssetLibrary::GetSingleton()->GetUEAssetLibrary().m_mapMaterialAsset;
				FString* strNewMaterialAsset = mapMaterialAsset.Find(strKey);
				if (strNewMaterialAsset == NULL)
				{
					return "";
				}
				return (*strNewMaterialAsset);
			}

			void Layer3DDatasetModel::SetDataset(Dataset* pDataset)
			{
				m_pDataset = pDataset;
			}

			Dataset* Layer3DDatasetModel::GetDataset()
			{
				return m_pDataset;
			}
		#if WITH_EDITOR
			void Layer3DDatasetModel::SetOriginalPosition(FVector vPos)
			{
				m_vPosition = vPos;

				FString strName = m_strLayerName.ToString();
				const TCHAR* c = *strName;
				ANSICHAR* cc = TCHAR_TO_UTF8(c);
				_SetOriginalPosition(2, cc, vPos.X, vPos.Y, vPos.Z);
			}

			void Layer3DDatasetModel::SetWorld(UWorld* pWorld)
			{
				m_pWorld = pWorld;
			}

			bool Layer3DDatasetModel::Open()
			{
				DataSetGeometry*** pGeometrys = nullptr;
				int32 nGeo = 0;

				DataSetSkeleton*** pSkeletons = nullptr;
				int32 nSkeleton = 0;

				DataSetInstanceSkeleton*** pInstanceSkeletons = nullptr;
				int32 nInstanceSkeleton = 0;

				DataSetMaterial*** pMaterials = nullptr;
				int32 nMtl = 0;

				DataSetTexture*** pTextures = nullptr;
				int32 nTex = 0;

				if (_GetDatasetModelData != nullptr)
				{
					_GetDatasetModelData(m_pDataset->Handler(),
						pGeometrys, nGeo,
						pSkeletons, nSkeleton,
						pInstanceSkeletons, nInstanceSkeleton,
						pMaterials, nMtl,
						pTextures, nTex);
				}

				// 创建纹理
				RenderModel3D::CreateTex2D(m_mapTexture, pTextures, nTex, m_pDataset->GetName());

				// 创建材质
				RenderModel3D::CreateMaterial(m_mapMaterial, pMaterials, nMtl, m_mapTexture, "");

				// 创建骨架
				RenderModel3D::CreateSkeleton(m_mapSkeleton, pSkeletons, nSkeleton);

				// 创建实例化骨架
				RenderModel3D::CreateInstanceSkeleton(m_mapInstanceSkeleton, pInstanceSkeletons, nInstanceSkeleton);
				// 创建非实例化的静态网格
				for (int32 n = 0; n < nGeo; n++)
				{
					DataSetGeometry* pDatasetGeo = (*pGeometrys)[n];

					if (pDatasetGeo == nullptr)
					{
						continue;
					}

					AddStaticMeshActor(pDatasetGeo);
				}

				_FreeModelMesh(pGeometrys, nGeo);
				_FreeModelMaterial(pMaterials, nMtl);
				_FreeModelTexture(pTextures, nTex);
				_FreeDataSetSkeletons(pSkeletons, nSkeleton);
				_FreeDataSetInstanceSkeletons(pInstanceSkeletons, nInstanceSkeleton);

				m_mapMaterial.clear();
				m_mapTexture.clear();
				m_mapSkeleton.clear();
				m_mapInstanceSkeleton.clear();
				m_mapInstanceMaterial.clear();
				return true;
			}

			void Layer3DDatasetModel::SetComponentMatrix(UStaticMeshComponent* pStaticMeshComponent, Matrix4d matLocaToWorld)
			{
				// 设置组件矩阵
				if (pStaticMeshComponent != NULL)
				{
					FVector vOffset(m_pWorld->OriginLocation);

					matLocaToWorld[3][0] -= m_vPosition.Y;
					matLocaToWorld[3][1] -= m_vPosition.X;
					matLocaToWorld[3][2] -= m_vPosition.Z;

					matLocaToWorld[3][0] *= M_TO_CM;
					matLocaToWorld[3][1] *= M_TO_CM;
					matLocaToWorld[3][2] *= M_TO_CM;

					matLocaToWorld[3][0] -= vOffset.X;
					matLocaToWorld[3][1] -= vOffset.Y;
					matLocaToWorld[3][2] -= vOffset.Z;

					FMatrix mat;
					Matrix4d::ToFMatrix(matLocaToWorld, mat);

					FTransform trans;
					trans.SetFromMatrix(mat);

					pStaticMeshComponent->SetWorldTransform(trans);
				}
			}

			UStaticMesh* Layer3DDatasetModel::CreateStaticMesh(ASuperMap_StaticMeshActor* pActor, FName strSkeletonName, DataVertex* pDataVertex, DataIndice*** pDataIndice, uint32 nIndiceCount)
			{
				FString meshName = strSkeletonName.ToString();
				FStaticMeshComponentRecreateRenderStateContext RecreateRenderStateContext(FindObject<UStaticMesh>(pActor, *meshName));
				UStaticMesh* pStaticMesh = NewObject<UStaticMesh>(m_pWorld, FName(meshName), RF_Public | RF_Standalone);
				if (pStaticMesh != NULL)
				{
					// 创建一个MeshDescription
					pStaticMesh->AddSourceModel();
					const int32 LodIndex = pStaticMesh->GetNumSourceModels() - 1;

					pStaticMesh->GetSourceModel(LodIndex).BuildSettings.bUseHighPrecisionTangentBasis = true;

					FMeshDescription* MeshDescription = pStaticMesh->CreateMeshDescription(LodIndex);

					// 创建静态网格
					// 顶点
					TVertexAttributesRef<GameVector3> VertexPositions = (*MeshDescription).VertexAttributes().GetAttributesRef<GameVector3>(MeshAttribute::Vertex::Position);
					// 法线
					TVertexInstanceAttributesRef<GameVector3> VertexInstanceNormals = (*MeshDescription).VertexInstanceAttributes().GetAttributesRef<GameVector3>(MeshAttribute::VertexInstance::Normal);
					// 切线
					TVertexInstanceAttributesRef<GameVector3> VertexInstanceTangents = (*MeshDescription).VertexInstanceAttributes().GetAttributesRef<GameVector3>(MeshAttribute::VertexInstance::Tangent);
					// BionormalSigns
					TVertexInstanceAttributesRef<float> VertexInstanceBinormalSigns = (*MeshDescription).VertexInstanceAttributes().GetAttributesRef<float>(MeshAttribute::VertexInstance::BinormalSign);
					// 顶点颜色
					TVertexInstanceAttributesRef<GameVector4> VertexInstanceColors = (*MeshDescription).VertexInstanceAttributes().GetAttributesRef<GameVector4>(MeshAttribute::VertexInstance::Color);
					// 纹理坐标
					TVertexInstanceAttributesRef<GameVector2> VertexInstanceUVs = (*MeshDescription).VertexInstanceAttributes().GetAttributesRef<GameVector2>(MeshAttribute::VertexInstance::TextureCoordinate);
					VertexInstanceUVs.SetNumIndices(2);
					// 材质
					TPolygonGroupAttributesRef<FName> PolygonGroupImportedMaterialSlotNames = (*MeshDescription).PolygonGroupAttributes().GetAttributesRef<FName>(MeshAttribute::PolygonGroup::ImportedMaterialSlotName);

					TArray<FStaticMaterial> Materials;

					// 通过索引的方式获取点
					for (uint32 i = 0; i < nIndiceCount; i++)
					{
						DataIndice* pIndice = (*pDataIndice)[i];
						UMaterial* pMaterialInterface = nullptr;
						UMaterialInstanceConstant* pMID = nullptr;
						std::map<__int64, std::pair<FName, UMaterialInstanceConstant*> >::iterator itorMtl = m_mapMaterial.find(pIndice->m_MtlHashCode);
						if (itorMtl != m_mapMaterial.end())
						{
							pMID = itorMtl->second.second;
							pActor->m_mapMaterials.Add(itorMtl->second.first.ToString(), pMID);
							m_mapInstanceMaterial[strSkeletonName] = itorMtl->second;
						}

						if (pMID == nullptr)
						{
							continue;
						}

						FStaticMaterial mtl(pMID);
						Materials.Add(mtl);

						FPolygonGroupID CurrentPolygonGroupID = FPolygonGroupID::Invalid;
						if (CurrentPolygonGroupID == FPolygonGroupID::Invalid)
						{
							CurrentPolygonGroupID = (*MeshDescription).CreatePolygonGroup();
							PolygonGroupImportedMaterialSlotNames[CurrentPolygonGroupID] = pMID->GetFName();
						}

						for (int32 j = 0; j < pIndice->m_nIndexCount; j += 3)
						{
							uint32 nIndex1 = 0;
							uint32 nIndex2 = 0;
							uint32 nIndex3 = 0;

							// 获取三角形索引
							RenderModel3D::GetTriangleIndex(j, pIndice, nIndex1, nIndex2, nIndex3);
							TArray<FStaticMeshBuildVertex> arrBuildVertexs;
							arrBuildVertexs.SetNum(3);

							// 获取三角形顶点
							GameVector3 vPos1, vPos2, vPos3;
							RenderModel3D::GetTrianglePos(nIndex1, nIndex2, nIndex3, pDataVertex, vPos1, vPos2, vPos3);

							arrBuildVertexs[0].Position = vPos1;
							arrBuildVertexs[1].Position = vPos2;
							arrBuildVertexs[2].Position = vPos3;

							// 计算法线
							GameVector3 vNormal1, vNormal2, vNormal3;
							RenderModel3D::GetTriangleNormal(nIndex1, nIndex2, nIndex3, pDataVertex, arrBuildVertexs,
								vNormal1, vNormal2, vNormal3);

							// 计算切线
							RenderModel3D::ComputeTangentSpace(arrBuildVertexs);
							GameVector3 vTangent1, vTangent2, vTangent3;
							vTangent1 = arrBuildVertexs[0].TangentX;
							vTangent2 = arrBuildVertexs[1].TangentX;
							vTangent3 = arrBuildVertexs[2].TangentX;

							// 计算BinormalSign
							float fBionormal1, fBionormal2, fBionormal3;
							fBionormal1 = arrBuildVertexs[0].TangentY.Size() / vTangent1.Size();
							fBionormal2 = arrBuildVertexs[1].TangentY.Size() / vTangent2.Size();
							fBionormal3 = arrBuildVertexs[2].TangentY.Size() / vTangent3.Size();

							// 顶点颜色
							GameVector4 vColor1(1.0, 1.0, 1.0, 1.0), vColor2(1.0, 1.0, 1.0, 1.0), vColor3(1.0, 1.0, 1.0, 1.0);
							RenderModel3D::GetTriangleColor(nIndex1, nIndex2, nIndex3, pDataVertex, vColor1, vColor2, vColor3);

							// 纹理坐标
							GameVector2 vTexcoord1, vTexcoord2, vTexcoord3;
							RenderModel3D::GetTriangleTexcoord(nIndex1, nIndex2, nIndex3, pDataVertex, vTexcoord1, vTexcoord2, vTexcoord3);

							FVertexID nVtxID1 = (*MeshDescription).CreateVertex();
							FVertexID nVtxID2 = (*MeshDescription).CreateVertex();
							FVertexID nVtxID3 = (*MeshDescription).CreateVertex();

							// 设置顶点
							RenderModel3D::SetTrianglePos(VertexPositions, nVtxID1, nVtxID2, nVtxID3, vPos1, vPos2, vPos3);

							TArray<FVertexInstanceID> VertexInstanceIDs;
							VertexInstanceIDs.SetNum(3);

							VertexInstanceIDs[0] = (*MeshDescription).CreateVertexInstance(nVtxID1);
							VertexInstanceIDs[1] = (*MeshDescription).CreateVertexInstance(nVtxID2);
							VertexInstanceIDs[2] = (*MeshDescription).CreateVertexInstance(nVtxID3);

							// 设置纹理坐标
							RenderModel3D::SetTriangleTexcoord(VertexInstanceUVs, VertexInstanceIDs, 0, vTexcoord1, vTexcoord2, vTexcoord3);
							RenderModel3D::SetTriangleTexcoord(VertexInstanceUVs, VertexInstanceIDs, 1, GameVector2(0.0, 0.0), GameVector2(0.0, 0.0), GameVector2(0.0, 0.0));

							// 设置顶点颜色
							RenderModel3D::SetTriangleColor(VertexInstanceColors, VertexInstanceIDs, vColor1, vColor2, vColor3);

							// 设置法线
							RenderModel3D::SetTriangleNormal(VertexInstanceNormals, VertexInstanceIDs, vNormal1, vNormal2, vNormal3);

							// 设置切线
							RenderModel3D::SetTriangleTangent(VertexInstanceTangents, VertexInstanceIDs, vTangent1, vTangent2, vTangent3);

							// 设置Bionormal
							RenderModel3D::SetTriangleBinormalSign(VertexInstanceBinormalSigns, VertexInstanceIDs, fBionormal1, fBionormal2, fBionormal3);

							TArray<FEdgeID> NewEdgeIDs;
							const FTriangleID NewPolygonID = (*MeshDescription).CreateTriangle(CurrentPolygonGroupID, VertexInstanceIDs, &NewEdgeIDs);
						}
					}

					pStaticMesh->CommitMeshDescription(LodIndex);
#if !SM_FOR_UE_FIVE
					pStaticMesh->StaticMaterials = Materials;
					const int32 NumSections = pStaticMesh->StaticMaterials.Num();
#else
					pStaticMesh->SetStaticMaterials(Materials);
					const int32 NumSections = pStaticMesh->GetStaticMaterials().Num();
#endif
					for (int32 SectionIdx = 0; SectionIdx < NumSections; ++SectionIdx)
					{
						FMeshSectionInfo Info = pStaticMesh->GetSectionInfoMap().Get(0, SectionIdx);
						Info.MaterialIndex = SectionIdx;
						Info.bEnableCollision = true;
						pStaticMesh->GetSectionInfoMap().Set(0, SectionIdx, Info);
						pStaticMesh->GetOriginalSectionInfoMap().Set(0, SectionIdx, Info);
					}

					pStaticMesh->ImportVersion = EImportStaticMeshVersion::LastVersion;
					pStaticMesh->Build(true);
				}

				return pStaticMesh;
			}

			UStaticMeshComponent* Layer3DDatasetModel::CreateStaticMeshComponent(UObject* pOuter, UStaticMesh* pStaticMesh, Matrix4d matLocalToWorld)
			{
				// 创建组件
				UStaticMeshComponent* pMeshComponent = NewObject<UStaticMeshComponent>(pOuter);

				SetComponentMatrix(pMeshComponent, matLocalToWorld);

				pMeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
				pMeshComponent->SetCollisionObjectType(ECollisionChannel::ECC_WorldStatic);

				pMeshComponent->SetStaticMesh(pStaticMesh);
				pMeshComponent->RegisterComponent();

				return pMeshComponent;
			}

			void Layer3DDatasetModel::AddStaticMeshFormModelGeode(ASuperMap_StaticMeshActor* pActor, DataSetGeode*** pGeodes, int32 nGeode)
			{
				for (int32 n = 0; n < nGeode; n++)
				{
					DataSetGeode* pGeode = (*pGeodes)[n];
					Matrix4d matWorldView(pGeode->m_matModelView);
					// 设置模型局部矩阵
					if (pGeode != nullptr)
					{
						for (int32 k = 0; k < pGeode->m_nSkeletonCount; k++)
						{
							char* pSkeletonName = (*pGeode->m_pSkeletonNames)[k];
							FString strSkeleton = UTF8_TO_TCHAR(pSkeletonName);
							FName strSkeletonName(strSkeleton);

							// 找到实例化骨架
							std::map<FName, std::pair<DataSetInstanceSkeleton*, UStaticMesh*> >::iterator itorInstance = m_mapInstanceSkeleton.find(strSkeletonName);
							if (itorInstance != m_mapInstanceSkeleton.end())
							{
								DataSetInstanceSkeleton* pDataSetInstanceSkeleton = itorInstance->second.first;
								if (pDataSetInstanceSkeleton != nullptr && pDataSetInstanceSkeleton->m_pDataSetSkeleton != nullptr)
								{
									DataSetSkeleton* pSkeleton = pDataSetInstanceSkeleton->m_pDataSetSkeleton;
									UStaticMesh* pStaticMesh = itorInstance->second.second;
									if (pStaticMesh == nullptr)
									{
										// 创建静态网格
										pStaticMesh = CreateStaticMesh(pActor, strSkeletonName, pSkeleton->m_pDataVertex, pSkeleton->m_pDataIndice, pSkeleton->m_nIndice);
										itorInstance->second.second = pStaticMesh;
									}
									else
									{
										std::map<FName, std::pair<FName, UMaterialInstanceConstant*> >::iterator itorInstanceMat = m_mapInstanceMaterial.find(strSkeletonName);
										if (itorInstanceMat != m_mapInstanceMaterial.end())
										{
											pActor->m_mapMaterials.Add(itorInstanceMat->second.first.ToString(), itorInstanceMat->second.second);
										}
									}

									Matrix4d matLocalView(pSkeleton->m_pDataVertex->m_doubleObjectMat);
									Matrix4d matLocalToWorld = matLocalView * matWorldView;

									UStaticMeshComponent* pMeshComponent = CreateStaticMeshComponent(pActor->GetStaticMeshComponent(), pStaticMesh, matLocalToWorld);
									pActor->StaticMeshComponents.Add(pMeshComponent);
									
									FMatrix matFLocalView;
									Matrix4d::ToFMatrix(matLocalToWorld, matFLocalView);
									pActor->m_arrMatrixs.Add(matFLocalView);
								}
								

								continue;
							}
							// 找到骨架
							std::map<FName, DataSetSkeleton*>::iterator itor = m_mapSkeleton.find(strSkeletonName);
							if (itor != m_mapSkeleton.end())
							{
								DataSetSkeleton* pSkeleton = itor->second;
								if (pSkeleton != nullptr)
								{
									// 创建静态网格
									UStaticMesh* pStaticMesh = CreateStaticMesh(pActor, strSkeletonName, pSkeleton->m_pDataVertex, pSkeleton->m_pDataIndice, pSkeleton->m_nIndice);

									Matrix4d matLocalView(pSkeleton->m_pDataVertex->m_doubleObjectMat);
									Matrix4d matLocalToWorld = matLocalView * matWorldView;

									// 创建组件
									UStaticMeshComponent* pMeshComponent = CreateStaticMeshComponent(pActor->GetStaticMeshComponent(), pStaticMesh, matLocalToWorld);
									pActor->StaticMeshComponents.Add(pMeshComponent);

									FMatrix matFLocalView;
									Matrix4d::ToFMatrix(matLocalToWorld, matFLocalView);
									pActor->m_arrMatrixs.Add(matFLocalView);
								}
							}

						}

					}
				}
			}

			void Layer3DDatasetModel::AddStaticMeshFromModelPatch(ASuperMap_StaticMeshActor* pActor, DataSetPatch*** pPatchs, int32 nPatch)
			{
				for (int32 n = 0; n < nPatch; n++)
				{
					DataSetPatch* pPatch = (*pPatchs)[n];
					if (pPatch == nullptr)
					{
						continue;
					}

					if (pPatch->m_nGeodeCount > 0 && pPatch->m_pDataSetGeodes != nullptr)
					{
						AddStaticMeshFormModelGeode(pActor, pPatch->m_pDataSetGeodes, pPatch->m_nGeodeCount);
					}

				}
			}

			void Layer3DDatasetModel::AddStaticMeshActor(DataSetGeometry* pGeometry)
			{
				// 遍历ModelPatch
				if (pGeometry->m_nPatchCount > 0 && pGeometry->m_pDataSetPatchs != nullptr)
				{
					ASuperMap_StaticMeshActor* pActor = m_pWorld->SpawnActor<ASuperMap_StaticMeshActor>();
					
					FString strDatasetName    = m_pDataset->GetName();
					FString strDataSourceName = m_pDataset->GetDataSource()->GetName();

					pActor->Tags.Add("SM_UDB");
					pActor->Tags.Add(FName(strDatasetName));
					pActor->m_strDataSourceName = strDataSourceName;
					pActor->m_strDatasetName    = strDatasetName;
					pActor->m_strSMID = FString::FromInt(pGeometry->m_nID);

					AddStaticMeshFromModelPatch(pActor, pGeometry->m_pDataSetPatchs, pGeometry->m_nPatchCount);
				}
			}

			void Layer3DDatasetModel::ToJson()
			{
				FString strJson;
				TSharedRef<TJsonWriter<>> JsonWriter = TJsonWriterFactory<>::Create(&strJson);

				JsonWriter->WriteObjectStart();
				JsonWriter->WriteValue(TEXT("MaterialSource"), TEXT("UE"));

				// 找到所有的静态的网格保存文件
				TArray<AActor*> Actors;
				UGameplayStatics::GetAllActorsWithTag(m_pWorld, FName(m_pDataset->GetName()), Actors);

				TMap<FString, bool> mapHasSave;

				int32 nSize = Actors.Num();
				for (int32 i = 0; i < nSize; i++)
				{
					ASuperMap_StaticMeshActor* pActor = (ASuperMap_StaticMeshActor*)Actors[i];

					for (auto & elem : pActor->m_mapMaterials)
					{
						FString strKey = elem.Key;
						FString strValue = elem.Value->GetPathName();

						if (mapHasSave.Find(strKey))
						{
							continue;
						}

						JsonWriter->WriteValue(strKey, strValue);
						mapHasSave.Add(strKey, true);
					}
				}

				JsonWriter->WriteObjectEnd();
				JsonWriter->Close();

				FString FileName = FPaths::ProjectDir() + TEXT("MaterialFile/")+ m_pDataset->GetName() + TEXT(".json");
				FFileHelper::SaveStringToFile(strJson, *FileName, FFileHelper::EEncodingOptions::ForceUTF8);
			}
		#endif
		}
	}
}
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif
