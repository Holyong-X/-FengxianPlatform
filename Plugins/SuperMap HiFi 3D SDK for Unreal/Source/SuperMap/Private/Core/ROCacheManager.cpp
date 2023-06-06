#include "Core/ROCacheManager.h"
#include "Engine/World.h"
#include "Engine/Engine.h"
#include "Engine/Texture2D.h"
#include "Core/Scene.h"
#include "Core/Layer3Ds.h"
#include "Core/Layer3DS3MFile.h"
#include "Core/Layer3DDatasetModel.h"
#include "SpatialAnalyst3D/ViewShed.h"
#include "SpatialAnalyst3D/ProjectionImage.h"
#include "Component/SuperMap_ROEntityActor.h"
#include "Component/SuperMap_MeshComponentInterface.h"
#include "Component/SuperMap_InstancedActor.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Materials/MaterialInstanceConstant.h"
#include "ControlUE/CameraControl.h"
#include "Component/MeshData.h"
#include "Core/Georeference.h"
#include "Algorithm3D/MathEngine.h"
#include "Core/TerrainLayers.h"
#include "Core/TerrainLayer.h"
#include "Component/SuperMap_CaptureSceneActor.h"
#include "Components/SceneCaptureComponent2D.h"
#include "GameFramework/Actor.h"
#include "Engine/StaticMesh.h"

using namespace SuperMapSDK::UnrealEngine::Algorithm3D;
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			FIntVector      ROCacheManager::m_vecWorldOrigin   = FIntVector(0, 0, 0);
			ROCacheManager* ROCacheManager::m_pROCacheManager  = NULL;
			SceneType       ROCacheManager::m_eSceneType       = Flat;
			FLinearColor    ROCacheManager::m_vID              = FLinearColor(-1.0f, -1.0f, -1.0f, -1.0f);
			FVector			ROCacheManager::m_vPlaneOffset	   = FVector(0, 0, 0);
			ROCacheManager::ROCacheManager()
			{
				m_strRoot = "Game/SceneRoot";
				m_pRootNode = nullptr;
				m_bAPIInitial = true;
				m_pCapureSceneActor = nullptr;
			}

			ROCacheManager::~ROCacheManager()
			{
				int32 nSize = m_qROCacheNode.size();
				for (int32 i = 0; i < nSize; i++)
				{
					UEROCacheNode* pROCacheNode = m_qROCacheNode.front();
					if (pROCacheNode)
					{
						delete pROCacheNode;
						pROCacheNode = nullptr;
					}

					m_qROCacheNode.pop();
				}

				Release();
			}

			ROCacheManager* ROCacheManager::GetSingleton()
			{
				if (m_pROCacheManager == NULL)
				{
					m_pROCacheManager = new ROCacheManager();
				}

				return m_pROCacheManager;
			}

			void ROCacheManager::Destroy()
			{
				if (m_pROCacheManager != NULL)
				{
					delete m_pROCacheManager;
					m_pROCacheManager = NULL;
				}
			}

			void ROCacheManager::SetCriticalSection(FCriticalSection* pCriticalSection)
			{
				m_pCriticalSection = pCriticalSection;
			}

			void ROCacheManager::DynamicGameObjectForData()
			{
				if (m_qROCacheNode.size() > 20)
				{
					return;
				}

				if (m_bAPIInitial)
				{
					if (_GetAllUpdata != NULL)
					{
						UEROCacheNode* pROCacheNode = new UEROCacheNode();

						pROCacheNode->pAddNodes = NULL;
						pROCacheNode->pUpdateNodes = NULL;
						pROCacheNode->pDeleteNodes = NULL;

						pROCacheNode->pAddMaterials = NULL;
						pROCacheNode->pUpdateMaterials = NULL;
						pROCacheNode->pDeleteMaterials = NULL;

						pROCacheNode->pAddTextures = NULL;
						pROCacheNode->pUpdateTextures = NULL;
						pROCacheNode->pDeleteTextures = NULL;

						pROCacheNode->nAddCount = 0;
						pROCacheNode->nUpdateCount = 0;
						pROCacheNode->nDeleteCount = 0;

						pROCacheNode->nAddMaterial = 0;
						pROCacheNode->nUpdateMaterial = 0;
						pROCacheNode->nDeleteMaterial = 0;

						pROCacheNode->nAddTexture = 0;
						pROCacheNode->nDeleteTexture = 0;
						pROCacheNode->nUpdateTexture = 0;


						_GetAllUpdata(pROCacheNode->pAddNodes,        pROCacheNode->nAddCount,
									  pROCacheNode->pUpdateNodes,     pROCacheNode->nUpdateCount,
									  pROCacheNode->pDeleteNodes,     pROCacheNode->nDeleteCount,
									  pROCacheNode->pAddMaterials,    pROCacheNode->nAddMaterial,
									  pROCacheNode->pUpdateMaterials, pROCacheNode->nUpdateMaterial,
									  pROCacheNode->pDeleteMaterials, pROCacheNode->nDeleteMaterial,
									  pROCacheNode->pAddTextures,     pROCacheNode->nAddTexture,
									  pROCacheNode->pUpdateTextures,  pROCacheNode->nUpdateTexture,
									  pROCacheNode->pDeleteTextures,  pROCacheNode->nDeleteTexture,
							false);

						if (pROCacheNode->nAddCount > 0     ||
							pROCacheNode->nUpdateCount > 0  ||
							pROCacheNode->nDeleteCount>0    ||
							pROCacheNode->nAddMaterial>0    ||
							pROCacheNode->nDeleteMaterial>0 ||
							pROCacheNode->nAddTexture>0     ||
							pROCacheNode->nUpdateTexture>0  ||
							pROCacheNode->nDeleteTexture>0  ||
							pROCacheNode->nUpdateMaterial > 0)
						{
					
							m_qROCacheNode.push(pROCacheNode);
						}
						else
						{
							delete pROCacheNode;
							pROCacheNode = nullptr;
						}
					}
				}
			}
			void ROCacheManager::DynamicGameObject()
			{
				if(m_qROCacheNode.size() > 0)
				{
					UEROCacheNode* pROCacheNode = m_qROCacheNode.front();
					if(pROCacheNode)
					{
						if (pROCacheNode->nDeleteMaterial > 0)
						{
							// 删除材质
							DeleteMaterial(pROCacheNode->pDeleteMaterials, pROCacheNode->nDeleteMaterial);
							if (_FreeArrayHashCode != NULL)
							{
								_FreeArrayHashCode(pROCacheNode->pDeleteMaterials, pROCacheNode->nDeleteMaterial);
							}

						}

						if (pROCacheNode->nAddMaterial > 0)
						{
							// 添加新的材质
							AddMaterial(pROCacheNode->pAddMaterials, pROCacheNode->nAddMaterial);
							if (_FreeArrayROMaterial != NULL)
							{
								_FreeArrayROMaterial(pROCacheNode->pAddMaterials, pROCacheNode->nAddMaterial);
							}
						}

						if (pROCacheNode->nAddTexture > 0)
						{
							// 添加新的纹理
							AddTextures(pROCacheNode->pAddTextures, pROCacheNode->nAddTexture);
							if (_FreeArrayROTexture != NULL)
							{
								_FreeArrayROTexture(pROCacheNode->pAddTextures, pROCacheNode->nAddTexture);
							}
						}

						if (pROCacheNode->nUpdateTexture > 0)
						{
							// 更新纹理
							AddTextures(pROCacheNode->pUpdateTextures, pROCacheNode->nUpdateTexture);
							if (_FreeArrayROTexture != NULL)
							{
								_FreeArrayROTexture(pROCacheNode->pUpdateTextures, pROCacheNode->nUpdateTexture);
							}
						}


						if (pROCacheNode->nDeleteTexture > 0)
						{
							// 删除纹理
							DeleteTextures(pROCacheNode->pDeleteTextures, pROCacheNode->nDeleteTexture);
							if (_FreeArrayHashCode != NULL)
							{
								_FreeArrayHashCode(pROCacheNode->pDeleteTextures, pROCacheNode->nDeleteTexture);
							}

						}

						if (pROCacheNode->nUpdateMaterial > 0)
						{
							// 删除纹理
							UpdateMaterial(pROCacheNode->pUpdateMaterials, pROCacheNode->nUpdateMaterial);
							if (_FreeArrayROMaterial != NULL)
							{
								_FreeArrayROMaterial(pROCacheNode->pUpdateMaterials, pROCacheNode->nUpdateMaterial);
							}
						}

						if (pROCacheNode->nDeleteCount > 0)
						{
							// 删除节点
							DeleteGameObjectForComponent(pROCacheNode->pDeleteNodes, pROCacheNode->nDeleteCount);
							if (_FreeArrayROEmptyNode != NULL)
							{
								_FreeArrayROEmptyNode(pROCacheNode->pDeleteNodes, pROCacheNode->nDeleteCount);
							}
						}

						if (pROCacheNode->nAddCount > 0)
						{
							// 添加新的
							AddGameObjectForComponent(pROCacheNode->pAddNodes, pROCacheNode->nAddCount);
							if (_FreeArrayRONode != NULL)
							{
								_FreeArrayRONode(pROCacheNode->pAddNodes, pROCacheNode->nAddCount);
							}
						}

						if (pROCacheNode->nUpdateCount > 0)
						{
							// 更新节点
							UpdateGameObjectForComponent(pROCacheNode->pUpdateNodes, pROCacheNode->nUpdateCount);
							if (_FreeArrayRONode != NULL)
							{
								_FreeArrayRONode(pROCacheNode->pUpdateNodes, pROCacheNode->nUpdateCount);
							}
						}

						delete pROCacheNode;
						pROCacheNode = nullptr;

						m_qROCacheNode.pop();
					}
				}
			}

			void ROCacheManager::Release()
			{
				//-----------------渲染队列----------------------------
				std::map<std::string, USuperMap_MeshComponentInterface*>::iterator itorRenderQueue = m_mapRootNode.begin();
				while (itorRenderQueue != m_mapRootNode.end())
				{
					USuperMap_MeshComponentInterface* pEntity = itorRenderQueue->second;
					if (pEntity != NULL)
					{
						pEntity->ReleaseMeshComponent();
						pEntity->ConditionalBeginDestroy();
						itorRenderQueue->second = NULL;
					}
					itorRenderQueue++;
				}
				m_mapRootNode.clear();


				itorRenderQueue = m_mapRenderQueue.begin();
				while (itorRenderQueue != m_mapRenderQueue.end())
				{
					USuperMap_MeshComponentInterface* pEntity = itorRenderQueue->second;
					if (pEntity != NULL)
					{
						pEntity->ReleaseMeshComponent();
						pEntity->ConditionalBeginDestroy();
						itorRenderQueue->second = NULL;
					}
					itorRenderQueue++;
				}
				m_mapRenderQueue.clear();

				//-------------------材质队列----------------------------
				std::map<__int64, UEROMaterial*>::iterator itorMaterial = m_mapMaterialManager.begin();
				while (itorMaterial != m_mapMaterialManager.end())
				{
					UEROMaterial* pMtl = itorMaterial->second;
					if (pMtl != NULL)
					{
						if (pMtl->m_pMaterialInstanceDynamic != NULL)
						{
							pMtl->m_pMaterialInstanceDynamic->RemoveFromRoot();
							pMtl->m_pMaterialInstanceDynamic = NULL;
						}

						if (pMtl->m_pMaterialInstanceConstant != NULL)
						{
							pMtl->m_pMaterialInstanceConstant->RemoveFromRoot();
							pMtl->m_pMaterialInstanceConstant = NULL;
						}

						delete pMtl;
						pMtl = NULL;
					}

					itorMaterial++;
				}

				m_mapMaterialManager.clear();

				//-------------------纹理队列-----------------------------
				std::map<__int64, UTexture2D*>::iterator itorTexture = m_mapTextureManager.begin();
				while (itorTexture != m_mapTextureManager.end())
				{
					UTexture2D* pTex = itorTexture->second;
					if (pTex != NULL)
					{
						pTex->RemoveFromRoot();
						itorTexture->second = NULL;
					}
					itorTexture++;
				}

				m_mapTextureManager.clear();
				//mapRootNode.clear();

				//---------------------ColorTable---------------------------

				std::map<FString, UTexture2D*>::iterator itorColorTable = m_mapColorTableManager.begin();
				while (itorColorTable != m_mapColorTableManager.end())
				{
					UTexture2D* pCol = itorColorTable->second;
					if (pCol != NULL)
					{
						pCol->RemoveFromRoot();
						itorColorTable->second = NULL;
					}
					itorColorTable++;
				}

				m_mapColorTableManager.clear();
				m_mapLayerInfo.clear();
				m_mapObjectInfo.clear();

				//--------------------StaticMeshs-----------------------------
				m_mapStaticMeshs.clear();
				m_mapInstancedActors.clear();
				m_mapRealTimeRasterRenderQueue.clear();

				if (m_pRootNode != nullptr)
				{
					m_pRootNode->Destroy();
					m_pRootNode = nullptr;
				}
				
				if (m_pCapureSceneActor != nullptr)
				{
					m_pCapureSceneActor->Destroy();
					m_pCapureSceneActor = nullptr;
				}

			}

			void ROCacheManager::SetWorld(UWorld* pWorld)
			{
				m_pWorld = pWorld;
			}

			void ROCacheManager::SetSceneOpt(Scene* pScene)
			{
				m_pScene = pScene;
			}


			std::map<std::string, USuperMap_MeshComponentInterface*> & ROCacheManager::GetRenderQueue()
			{
				return m_mapRenderQueue;
			}

			std::map<std::string, USuperMap_MeshComponentInterface*> & ROCacheManager::GetRealTimeRasterRenderQueue()
			{
				return m_mapRealTimeRasterRenderQueue;
			}

			std::map<std::string, USuperMap_MeshComponentInterface*> & ROCacheManager::GetRootQueue()
			{
				return m_mapRootNode;
			}

			UMaterialInstanceDynamic* ROCacheManager::GetDepthMaterial()
			{
				return m_pDepthMaterial;
			}

			ASuperMap_ROEntityActor* ROCacheManager::CreateActor(FName & name)
			{
				if (m_pWorld == NULL)
				{
					return NULL;
				}
				ASuperMap_ROEntityActor* pEActor = m_pWorld->SpawnActor<ASuperMap_ROEntityActor>();
				pEActor->SetName(name);

				return pEActor;
			}

			void ROCacheManager::UpdateMaterial(ROMaterial*** & pUpdateMaterial, int32 nCount)
			{
				for (int32 i = 0; i < nCount; i++)
				{
					ROMaterial* pMaterial = (*pUpdateMaterial)[i];
					if (pMaterial != nullptr)
					{
						std::map<__int64, UEROMaterial*>::iterator itor = m_mapMaterialManager.find(pMaterial->m_strMaterialName);
						if (itor != m_mapMaterialManager.end())
						{
							UEROMaterial* pUEMaterial = itor->second;

							pUEMaterial->m_nTextureHashCode = pMaterial->m_strTextureName;
							pUEMaterial->m_nTextureHashCode1 = pMaterial->m_strTextureName1;
							pUEMaterial->m_nTextureHashCode2 = pMaterial->m_strTextureName2;
							pUEMaterial->m_nTextureHashCode3 = pMaterial->m_strTextureName3;


							UMaterialInstanceDynamic* pMat = (UMaterialInstanceDynamic*)pUEMaterial->m_pMaterialInstanceDynamic;

							if (pMat != nullptr)
							{
								// 设置第一个纹理矩阵
								if (pMaterial->m_pTexTransform != NULL)
								{
									FLinearColor vX;
									vX.R = pMaterial->m_pTexTransform[0];
									vX.G = pMaterial->m_pTexTransform[1];
									vX.B = pMaterial->m_pTexTransform[2];
									vX.A = pMaterial->m_pTexTransform[3];

									FLinearColor vY;
									vY.R = pMaterial->m_pTexTransform[4];
									vY.G = pMaterial->m_pTexTransform[5];
									vY.B = pMaterial->m_pTexTransform[6];
									vY.A = pMaterial->m_pTexTransform[7];

									FLinearColor vZ;
									vZ.R = pMaterial->m_pTexTransform[8];
									vZ.G = pMaterial->m_pTexTransform[9];
									vZ.B = pMaterial->m_pTexTransform[10];
									vZ.A = pMaterial->m_pTexTransform[11];

									FLinearColor vW;
									vW.R = pMaterial->m_pTexTransform[12];
									vW.G = pMaterial->m_pTexTransform[13];
									vW.B = pMaterial->m_pTexTransform[14];
									vW.A = pMaterial->m_pTexTransform[15];

									pMat->SetVectorParameterValue(FName(TEXT("TexOneX")), vX);
									pMat->SetVectorParameterValue(FName(TEXT("TexOneY")), vY);
									pMat->SetVectorParameterValue(FName(TEXT("TexOneZ")), vZ);
									pMat->SetVectorParameterValue(FName(TEXT("TexOneW")), vW);
								}
								else
								{
									FLinearColor vX(1.0, 0.0, 0.0, 0.0);
									FLinearColor vY(0.0, 1.0, 0.0, 0.0);
									FLinearColor vZ(0.0, 0.0, 1.0, 0.0);
									FLinearColor vW(0.0, 0.0, 0.0, 1.0);
									pMat->SetVectorParameterValue(FName(TEXT("TexOneX")), vX);
									pMat->SetVectorParameterValue(FName(TEXT("TexOneY")), vY);
									pMat->SetVectorParameterValue(FName(TEXT("TexOneZ")), vZ);
									pMat->SetVectorParameterValue(FName(TEXT("TexOneW")), vW);

								}

								// 设置第二个纹理矩阵
								if (pMaterial->m_pTexTransform1 != NULL)
								{
									FLinearColor vX;
									vX.R = pMaterial->m_pTexTransform1[0];
									vX.G = pMaterial->m_pTexTransform1[1];
									vX.B = pMaterial->m_pTexTransform1[2];
									vX.A = pMaterial->m_pTexTransform1[3];

									FLinearColor vY;
									vY.R = pMaterial->m_pTexTransform1[4];
									vY.G = pMaterial->m_pTexTransform1[5];
									vY.B = pMaterial->m_pTexTransform1[6];
									vY.A = pMaterial->m_pTexTransform1[7];

									FLinearColor vZ;
									vZ.R = pMaterial->m_pTexTransform1[8];
									vZ.G = pMaterial->m_pTexTransform1[9];
									vZ.B = pMaterial->m_pTexTransform1[10];
									vZ.A = pMaterial->m_pTexTransform1[11];

									FLinearColor vW;
									vW.R = pMaterial->m_pTexTransform1[12];
									vW.G = pMaterial->m_pTexTransform1[13];
									vW.B = pMaterial->m_pTexTransform1[14];
									vW.A = pMaterial->m_pTexTransform1[15];


									pMat->SetVectorParameterValue(FName(TEXT("TexTwoX")), vX);
									pMat->SetVectorParameterValue(FName(TEXT("TexTwoY")), vY);
									pMat->SetVectorParameterValue(FName(TEXT("TexTwoZ")), vZ);
									pMat->SetVectorParameterValue(FName(TEXT("TexTwoW")), vW);
								}
								else
								{
									FLinearColor vX(1.0, 0.0, 0.0, 0.0);
									FLinearColor vY(0.0, 1.0, 0.0, 0.0);
									FLinearColor vZ(0.0, 0.0, 1.0, 0.0);
									FLinearColor vW(0.0, 0.0, 0.0, 1.0);
									pMat->SetVectorParameterValue(FName(TEXT("TexTwoX")), vX);
									pMat->SetVectorParameterValue(FName(TEXT("TexTwoY")), vY);
									pMat->SetVectorParameterValue(FName(TEXT("TexTwoZ")), vZ);
									pMat->SetVectorParameterValue(FName(TEXT("TexTwoW")), vW);
								}

								// 设置第三个纹理矩阵
								if (pMaterial->m_pTexTransform2 != NULL)
								{
									FLinearColor vX;
									vX.R = pMaterial->m_pTexTransform2[0];
									vX.G = pMaterial->m_pTexTransform2[1];
									vX.B = pMaterial->m_pTexTransform2[2];
									vX.A = pMaterial->m_pTexTransform2[3];

									FLinearColor vY;
									vY.R = pMaterial->m_pTexTransform2[4];
									vY.G = pMaterial->m_pTexTransform2[5];
									vY.B = pMaterial->m_pTexTransform2[6];
									vY.A = pMaterial->m_pTexTransform2[7];

									FLinearColor vZ;
									vZ.R = pMaterial->m_pTexTransform2[8];
									vZ.G = pMaterial->m_pTexTransform2[9];
									vZ.B = pMaterial->m_pTexTransform2[10];
									vZ.A = pMaterial->m_pTexTransform2[11];

									FLinearColor vW;
									vW.R = pMaterial->m_pTexTransform2[12];
									vW.G = pMaterial->m_pTexTransform2[13];
									vW.B = pMaterial->m_pTexTransform2[14];
									vW.A = pMaterial->m_pTexTransform2[15];


									pMat->SetVectorParameterValue(FName(TEXT("TexThreeX")), vX);
									pMat->SetVectorParameterValue(FName(TEXT("TexThreeY")), vY);
									pMat->SetVectorParameterValue(FName(TEXT("TexThreeZ")), vZ);
									pMat->SetVectorParameterValue(FName(TEXT("TexThreeW")), vW);
								}
								else
								{
									FLinearColor vX(1.0, 0.0, 0.0, 0.0);
									FLinearColor vY(0.0, 1.0, 0.0, 0.0);
									FLinearColor vZ(0.0, 0.0, 1.0, 0.0);
									FLinearColor vW(0.0, 0.0, 0.0, 1.0);
									pMat->SetVectorParameterValue(FName(TEXT("TexThreeX")), vX);
									pMat->SetVectorParameterValue(FName(TEXT("TexThreeY")), vY);
									pMat->SetVectorParameterValue(FName(TEXT("TexThreeZ")), vZ);
									pMat->SetVectorParameterValue(FName(TEXT("TexThreeW")), vW);
								}

								// 设置第四个纹理矩阵
								if (pMaterial->m_pTexTransform3 != NULL)
								{
									FLinearColor vX;
									vX.R = pMaterial->m_pTexTransform3[0];
									vX.G = pMaterial->m_pTexTransform3[1];
									vX.B = pMaterial->m_pTexTransform3[2];
									vX.A = pMaterial->m_pTexTransform3[3];

									FLinearColor vY;
									vY.R = pMaterial->m_pTexTransform3[4];
									vY.G = pMaterial->m_pTexTransform3[5];
									vY.B = pMaterial->m_pTexTransform3[6];
									vY.A = pMaterial->m_pTexTransform3[7];

									FLinearColor vZ;
									vZ.R = pMaterial->m_pTexTransform3[8];
									vZ.G = pMaterial->m_pTexTransform3[9];
									vZ.B = pMaterial->m_pTexTransform3[10];
									vZ.A = pMaterial->m_pTexTransform3[11];

									FLinearColor vW;
									vW.R = pMaterial->m_pTexTransform3[12];
									vW.G = pMaterial->m_pTexTransform3[13];
									vW.B = pMaterial->m_pTexTransform3[14];
									vW.A = pMaterial->m_pTexTransform3[15];


									pMat->SetVectorParameterValue(FName(TEXT("TexFourX")), vX);
									pMat->SetVectorParameterValue(FName(TEXT("TexFourY")), vY);
									pMat->SetVectorParameterValue(FName(TEXT("TexFourZ")), vZ);
									pMat->SetVectorParameterValue(FName(TEXT("TexFourW")), vW);
								}
								else
								{
									FLinearColor vX(1.0, 0.0, 0.0, 0.0);
									FLinearColor vY(0.0, 1.0, 0.0, 0.0);
									FLinearColor vZ(0.0, 0.0, 1.0, 0.0);
									FLinearColor vW(0.0, 0.0, 0.0, 1.0);
									pMat->SetVectorParameterValue(FName(TEXT("TexFourX")), vX);
									pMat->SetVectorParameterValue(FName(TEXT("TexFourY")), vY);
									pMat->SetVectorParameterValue(FName(TEXT("TexFourZ")), vZ);
									pMat->SetVectorParameterValue(FName(TEXT("TexFourW")), vW);
								}

								// 找到纹理，更新子纹理
								// 第一重纹理
								int32 nTexCount = 0;
								std::map<__int64, UTexture2D*>::iterator itorTex = m_mapTextureManager.find(pUEMaterial->m_nTextureHashCode);
								if (itorTex != m_mapTextureManager.end() && itorTex->second != nullptr)
								{
									pMat->SetTextureParameterValue(FName("TextureParam"), itorTex->second);

									float sizeX = itorTex->second->GetSizeX();
									float sizeY = itorTex->second->GetSizeY();
									FLinearColor texonesize;
									texonesize.R = sizeX;
									texonesize.G = sizeY;

									pMat->SetVectorParameterValue(FName("TexOneSize"), texonesize);

									nTexCount++;
								}
								else
								{
									pMat->SetTextureParameterValue(FName("TextureParam"), nullptr);
								}

								if (pMat != nullptr && pMat->GetBaseMaterial() != nullptr && pMat->GetBaseMaterial()->GetName() == "NewModel")
								{
									// 第二重纹理
									itorTex = m_mapTextureManager.find(pUEMaterial->m_nTextureHashCode1);
									if (itorTex != m_mapTextureManager.end() && itorTex->second != nullptr)
									{
										// 第三重纹理
										std::map<__int64, UTexture2D*>::iterator itorTex2 = m_mapTextureManager.find(pUEMaterial->m_nTextureHashCode2);
										if (itorTex2 != m_mapTextureManager.end() && itorTex2->second != nullptr)
										{
											pMat->SetTextureParameterValue(FName("TextureParam1"), itorTex2->second);
										}
										else
										{
											pMat->SetTextureParameterValue(FName("TextureParam1"), itorTex->second);
										}

										nTexCount++;
									}
								}
								else
								{
									// 第二重纹理
									itorTex = m_mapTextureManager.find(pUEMaterial->m_nTextureHashCode1);
									if (itorTex != m_mapTextureManager.end() && itorTex->second != nullptr)
									{
										pMat->SetTextureParameterValue(FName("TextureParam1"), itorTex->second);
										nTexCount++;
									}
									else
									{
										pMat->SetTextureParameterValue(FName("TextureParam1"), nullptr);
									}

									// 第三重纹理
									itorTex = m_mapTextureManager.find(pUEMaterial->m_nTextureHashCode2);
									if (itorTex != m_mapTextureManager.end() && itorTex->second != nullptr)
									{
										pMat->SetTextureParameterValue(FName("TextureParam2"), itorTex->second);
										nTexCount++;
									}
									else
									{
										pMat->SetTextureParameterValue(FName("TextureParam2"), nullptr);
									}

									// 第四重纹理
									itorTex = m_mapTextureManager.find(pUEMaterial->m_nTextureHashCode3);
									if (itorTex != m_mapTextureManager.end() && itorTex->second != nullptr)
									{
										pMat->SetTextureParameterValue(FName("TextureParam3"), itorTex->second);
										nTexCount++;
									}
									else
									{
										pMat->SetTextureParameterValue(FName("TextureParam3"), nullptr);
									}
								}

								pMat->SetScalarParameterValue(FName("TexCount"), nTexCount);


								if (pMaterial->m_nGlobalTinLevel > -1 && pMaterial->m_pGlobalTinTran != nullptr)
								{
									pMat->SetScalarParameterValue(FName(TEXT("SlopeTinLevel")), pMaterial->m_nGlobalTinLevel);
									MathEngine::SetShaderMatrixParamter(pMat, pMaterial->m_pGlobalTinTran, TEXT("SlopeTinMat"));
								}
							}

						}
					}
				}
			}

			void ROCacheManager::SetTextureMatrix(UMaterialInstanceDynamic* pMID, float* pTexMat, FString strTex)
			{
				// 设置第一个纹理矩阵
				if (pTexMat != nullptr && pMID != nullptr)
				{
					FLinearColor vX;
					vX.R = pTexMat[0];
					vX.G = pTexMat[1];
					vX.B = pTexMat[2];
					vX.A = pTexMat[3];

					FLinearColor vY;
					vY.R = pTexMat[4];
					vY.G = pTexMat[5];
					vY.B = pTexMat[6];
					vY.A = pTexMat[7];

					FLinearColor vZ;
					vZ.R = pTexMat[8];
					vZ.G = pTexMat[9];
					vZ.B = pTexMat[10];
					vZ.A = pTexMat[11];

					FLinearColor vW;
					vW.R = pTexMat[12];
					vW.G = pTexMat[13];
					vW.B = pTexMat[14];
					vW.A = pTexMat[15];

					FString strX = strTex + TEXT("X");
					FString strY = strTex + TEXT("Y");
					FString strZ = strTex + TEXT("Z");
					FString strW = strTex + TEXT("W");

					pMID->SetVectorParameterValue(FName(strX), vX);
					pMID->SetVectorParameterValue(FName(strY), vY);
					pMID->SetVectorParameterValue(FName(strZ), vZ);
					pMID->SetVectorParameterValue(FName(strW), vW);
				}
			}

			bool ROCacheManager::IsNeedCreateSecondMaterial(FString strShaderName)
			{
				if (strShaderName.Compare("Custom/ModelCache") == 0 ||
				    strShaderName.Compare("Custom/ModelCache2") == 0 ||
				    strShaderName.Compare("Custom/NewModelCache") == 0 ||
					strShaderName.Compare("Custom/NewModelCache2") == 0 ||
					strShaderName.Compare("Custom/ModelPro") == 0)
				{
					return true;
				}

				return false;
			}

			void ROCacheManager::CreateMID(bool bIsPBR, FString strShaderName, UMaterialInstanceDynamic* & pMID)
			{
				// 创建倾斜的材质
				if (strShaderName.Compare("Custom/Model") == 0)
				{
					UMaterialInterface* pMaterialInterface = LoadObject<UMaterialInterface>(nullptr, TEXT("/Supermap/Materials/Oblique"));

					pMID = UMaterialInstanceDynamic::Create(pMaterialInterface, nullptr);
				}
				// 创建地形的材质
				else if (strShaderName.Compare("Custom/Globe") == 0)
				{
					UMaterialInterface* pMaterialInterface = LoadObject<UMaterialInterface>(nullptr, TEXT("/Supermap/Materials/Global"));

					pMID = UMaterialInstanceDynamic::Create(pMaterialInterface, nullptr);
				}// 点云
				else if (strShaderName.Compare("Custom/PointCloud") == 0)
				{
					UMaterialInterface* pMaterialInterface = LoadObject<UMaterialInterface>(nullptr, TEXT("/Supermap/Materials/PointCloud"));

					pMID = UMaterialInstanceDynamic::Create(pMaterialInterface, nullptr);
				}// 精模
				else if (strShaderName.Compare("Custom/ModelCache") == 0)
				{
					UMaterialInterface* pMaterialInterface = nullptr;

					if (bIsPBR)
					{
						pMaterialInterface = LoadObject<UMaterialInterface>(nullptr, TEXT("/Supermap/Materials/ModelPBR"));
					}
					else
					{
						pMaterialInterface = LoadObject<UMaterialInterface>(nullptr, TEXT("/Supermap/Materials/Model"));
					}

					pMID = UMaterialInstanceDynamic::Create(pMaterialInterface, nullptr);
				}
				else if (strShaderName.Compare("Custom/ModelCache2") == 0)
				{
					UMaterialInterface* pMaterialInterface = nullptr;

					if (bIsPBR)
					{
						pMaterialInterface = LoadObject<UMaterialInterface>(nullptr, TEXT("/Supermap/Materials/Model_TranslucentPBR"));
					}
					else
					{
						pMaterialInterface = LoadObject<UMaterialInterface>(nullptr, TEXT("/Supermap/Materials/Model_Translucent"));
					}

					pMID = UMaterialInstanceDynamic::Create(pMaterialInterface, nullptr);
				}// 新精模
				else if (strShaderName.Compare("Custom/NewModelCache") == 0)
				{
					UMaterialInterface* pMaterialInterface = LoadObject<UMaterialInterface>(nullptr, TEXT("/Supermap/Materials/NewModel"));

					pMID = UMaterialInstanceDynamic::Create(pMaterialInterface, nullptr);
				}
				else if (strShaderName.Compare("Custom/NewModelCache2") == 0)
				{
					UMaterialInterface* pMaterialInterface = LoadObject<UMaterialInterface>(nullptr, TEXT("/Supermap/Materials/NewModel_Translucent"));

					pMID = UMaterialInstanceDynamic::Create(pMaterialInterface, nullptr);
				}
				else if (strShaderName.Compare("Custom/Billboard") == 0)
				{
					UMaterialInterface* pMaterialInterface = LoadObject<UMaterialInterface>(nullptr, TEXT("Material'/SuperMap/Materials/BillboardMaterial.BillboardMaterial'"));

					pMID = UMaterialInstanceDynamic::Create(pMaterialInterface, nullptr);
				}
				else if (strShaderName.Compare("Custom/ModelPro") == 0)
				{
					UMaterialInterface* pMaterialInterface = LoadObject<UMaterialInterface>(nullptr, TEXT("/Supermap/Materials/ModelPro"));
					
					pMID = UMaterialInstanceDynamic::Create(pMaterialInterface, nullptr);
				}
				else if (strShaderName.Compare("Custom/CommonNoTexture") == 0)
				{
					UMaterialInterface* pMaterialInterface = LoadObject<UMaterialInterface>(nullptr, TEXT("/Supermap/Materials/CommonNoTexture")); 

					pMID = UMaterialInstanceDynamic::Create(pMaterialInterface, nullptr);
				}
			}

			void ROCacheManager::SetPBRMaterialParam(UMaterialInstanceDynamic* pMID, ROMaterial* pMaterial)
			{
				if (pMID == nullptr || pMaterial == nullptr)
				{
					return;
				}

				pMID->SetScalarParameterValue(TEXT("NormalTexcoordIndex"), pMaterial->m_pPBRParam->m_nNormalTextureCoordIndex);
				pMID->SetScalarParameterValue(TEXT("NormalTextureIndex"), pMaterial->m_pPBRParam->m_nNormalTextureIndex);

				pMID->SetScalarParameterValue(TEXT("EmissiveTextureIndex"), pMaterial->m_pPBRParam->m_nEmissiveTextureIndex);
				pMID->SetScalarParameterValue(TEXT("EmissiveTexcoordIndex"), pMaterial->m_pPBRParam->m_nEmissiveTextureCoordIndex);

				pMID->SetScalarParameterValue(TEXT("OcclusionTexcoordIndex"), pMaterial->m_pPBRParam->m_nOcclusionTextureCoordIndex);
				pMID->SetScalarParameterValue(TEXT("OcclusionTextureIndex"), pMaterial->m_pPBRParam->m_nOcclusionTextureIndex);

				FVector vEmissiveFactor;
				vEmissiveFactor.X = pMaterial->m_pPBRParam->m_vec3EmissiveFactor.m_dFactorX;
				vEmissiveFactor.Y = pMaterial->m_pPBRParam->m_vec3EmissiveFactor.m_dFactorY;
				vEmissiveFactor.Z = pMaterial->m_pPBRParam->m_vec3EmissiveFactor.m_dFactorZ;
				pMID->SetVectorParameterValue(TEXT("EmissiveFactor"), vEmissiveFactor);

				pMID->SetScalarParameterValue(TEXT("NormalTextureScale"), pMaterial->m_pPBRParam->m_fNormalTextureScale);
				pMID->SetScalarParameterValue(TEXT("OcclusionTextureStrength"), pMaterial->m_pPBRParam->m_fOcclusionTextureStrength);
				
				if (pMaterial->m_pPBRParam->m_pPBRMetallicRough != nullptr)
				{
					FLinearColor vBaseFactor;
					vBaseFactor.R = pMaterial->m_pPBRParam->m_pPBRMetallicRough->m_vec4BaseColor.m_dFactorX;
					vBaseFactor.G = pMaterial->m_pPBRParam->m_pPBRMetallicRough->m_vec4BaseColor.m_dFactorY;
					vBaseFactor.B = pMaterial->m_pPBRParam->m_pPBRMetallicRough->m_vec4BaseColor.m_dFactorZ;
					vBaseFactor.A = pMaterial->m_pPBRParam->m_pPBRMetallicRough->m_vec4BaseColor.m_dFactorW;
					pMID->SetVectorParameterValue(TEXT("BaseFactor"), vBaseFactor);
					pMID->SetScalarParameterValue(TEXT("BaseTextureIndex"), pMaterial->m_pPBRParam->m_pPBRMetallicRough->m_nBaseColorTextureIndex);
					pMID->SetScalarParameterValue(TEXT("BaseTexcoordIndex"), pMaterial->m_pPBRParam->m_pPBRMetallicRough->m_nBaseColorTextureCoordIndex);
					pMID->SetScalarParameterValue(TEXT("MetallicTextureIndex") , pMaterial->m_pPBRParam->m_pPBRMetallicRough->m_nMetallicRoughnessTextureIndex);
					pMID->SetScalarParameterValue(TEXT("MetallicTextcoordIndex"), pMaterial->m_pPBRParam->m_pPBRMetallicRough->m_nMetallicRoughnessTextureCoordIndex);
					pMID->SetScalarParameterValue(TEXT("MetallicFactor"), pMaterial->m_pPBRParam->m_pPBRMetallicRough->m_fMetallicFactor);
					pMID->SetScalarParameterValue(TEXT("RoughnessFactor"), pMaterial->m_pPBRParam->m_pPBRMetallicRough->m_fRoughnessFactor);
				}


			}

			void ROCacheManager::AddMaterial(ROMaterial*** & pAddMaterial, int32 nCount)
			{
				for (int32 i = 0; i < nCount; i++)
				{
					ROMaterial* pMaterial = (*pAddMaterial)[i];

					if (pMaterial != NULL)
					{
						FString strMaterialRealName = UTF8_TO_TCHAR(pMaterial->m_strRealMaterialName);
						FString strOldName = strMaterialRealName;
						
						int32 nIndex = 0;
						if (strMaterialRealName.FindLastChar(TCHAR('_'), nIndex))
						{
							int32 nStrCount = strMaterialRealName.Len() - nIndex;
							strMaterialRealName.RemoveAt(nIndex , nStrCount);
						}

						UMaterialInstanceConstant* pMIC = NULL;
						if (strMaterialRealName.Len() < 200)
						{
							pMIC = FindObject<UMaterialInstanceConstant>(nullptr, *strMaterialRealName);
						}
						 
						UMaterialInstanceDynamic* pMID = NULL;
						FString strShaderName = pMaterial->m_strShaderName;
						bool bNeedSecondMaterial = IsNeedCreateSecondMaterial(strShaderName);
						bool bIsPBR = false;
						if (pMIC != nullptr)
						{
							pMID = UMaterialInstanceDynamic::Create(pMIC->Parent, nullptr);
							pMID->CopyMaterialUniformParameters(pMIC);

							pMIC->RemoveFromRoot();
							pMIC = nullptr;
						}
						else
						{
							if (pMaterial->m_pPBRParam != nullptr)
							{
								bIsPBR = true;
							}
							CreateMID(bIsPBR, strShaderName, pMID);
						}

						if (pMID == NULL)
						{
							continue;
						}

						pMID->AddToRoot();

						// 设置纹理矩阵
						if (pMID != NULL)
						{
							// 设置第一个纹理矩阵
							SetTextureMatrix(pMID, pMaterial->m_pTexTransform, TEXT("TexOne"));

							// 设置第二个纹理矩阵
							SetTextureMatrix(pMID, pMaterial->m_pTexTransform1, TEXT("TexTwo"));

							// 设置第三个纹理矩阵
							SetTextureMatrix(pMID, pMaterial->m_pTexTransform2, TEXT("TexThree"));

							// 设置第四个纹理矩阵
							SetTextureMatrix(pMID, pMaterial->m_pTexTransform3, TEXT("TexFour"));
						}

						pMID->SetScalarParameterValue(FName(TEXT("nDiffuseBatchTableSize")), pMaterial->m_nBatchSize);
						pMID->SetScalarParameterValue(FName(TEXT("nBatchTexSize")), pMaterial->m_nBatchTexSize);
						
						if (pMaterial->m_nGlobalTinLevel > -1 && pMaterial->m_pGlobalTinTran != nullptr)
						{
							pMID->SetScalarParameterValue(FName(TEXT("SlopeTinLevel")), pMaterial->m_nGlobalTinLevel);
							Matrix4d matSlopeTin(pMaterial->m_pGlobalTinTran);
							MathEngine::SetShaderMatrixParamter(pMID, matSlopeTin, TEXT("SlopeTinMat"));
						}

						if (bIsPBR)
						{
							// 设置PBR材质参数
							SetPBRMaterialParam(pMID, pMaterial);
						}

						if (pMID != nullptr)
						{
							std::map<__int64, UEROMaterial*>::iterator itor = m_mapMaterialManager.find(pMaterial->m_strMaterialName);
							if (itor == m_mapMaterialManager.end())
							{

								UEROMaterial* pUEMaterial = new UEROMaterial;
								pUEMaterial->m_strName = strOldName;
								pUEMaterial->m_nTextureHashCode  = pMaterial->m_strTextureName;
								pUEMaterial->m_nTextureHashCode1 = pMaterial->m_strTextureName1;
								pUEMaterial->m_nTextureHashCode2 = pMaterial->m_strTextureName2;
								pUEMaterial->m_nTextureHashCode3 = pMaterial->m_strTextureName3;
								pUEMaterial->m_nBatchTexIndex    = pMaterial->m_nBatchTextureIndex;
								pUEMaterial->m_pMaterialInstanceDynamic = pMID;
								pUEMaterial->m_pMaterialInstanceConstant = pMIC;
								pUEMaterial->m_bNeedSecondMaterial = bNeedSecondMaterial;
								pUEMaterial->m_bIsPBR = bIsPBR;
								pUEMaterial->m_nBaseTextureIndex = -1;
								pUEMaterial->m_nEmissiveTextureIndex = -1;
								pUEMaterial->m_nMetallicTextureIndex = -1;
								pUEMaterial->m_nOcclusionTextureIndex = -1;
								pUEMaterial->m_nNormalTextureIndex = -1;
								pUEMaterial->m_nTextureNormalIndex = pMaterial->m_nNormalTexIndex;
								if (bIsPBR)
								{
									pUEMaterial->m_nEmissiveTextureIndex = pMaterial->m_pPBRParam->m_nEmissiveTextureIndex;
									pUEMaterial->m_nNormalTextureIndex = pMaterial->m_pPBRParam->m_nNormalTextureIndex;
									pUEMaterial->m_nOcclusionTextureIndex = pMaterial->m_pPBRParam->m_nOcclusionTextureIndex;

									if (pMaterial->m_pPBRParam->m_pPBRMetallicRough != nullptr)
									{
										pUEMaterial->m_nBaseTextureIndex = pMaterial->m_pPBRParam->m_pPBRMetallicRough->m_nBaseColorTextureIndex;
										pUEMaterial->m_nMetallicTextureIndex = pMaterial->m_pPBRParam->m_pPBRMetallicRough->m_nMetallicRoughnessTextureIndex;
									}
								}

								if (pMaterial->m_pTexTransform != nullptr)
								{
									pUEMaterial->m_matTex = Matrix4d(pMaterial->m_pTexTransform);
								}
								
								if (strShaderName.Compare("Custom/Globe") == 0)
								{						
									if (ROCacheManager::m_eSceneType == Flat)
									{
										pUEMaterial->m_bCollision = true;
									}
									else
									{
										pUEMaterial->m_bCollision = false;
									}
								}
								else
								{
									pUEMaterial->m_bCollision = true;
								}

								if (strShaderName.Compare("Custom/PointCloud") == 0)
								{
									pUEMaterial->m_bCollision = false;
								}

								m_mapMaterialManager[pMaterial->m_strMaterialName] = pUEMaterial;
							}
						}

					}
				}
			}

			void ROCacheManager::DeleteMaterial(__int64*** & pDeleteMaterial, int32 nCount)
			{
				for (int32 i = 0; i < nCount; i++)
				{
					__int64* pMaterial = (*pDeleteMaterial)[i];

					if ((*pMaterial) != 0)
					{
						std::map<__int64, UEROMaterial*>::iterator itor = m_mapMaterialManager.find(*pMaterial);
						if (itor != m_mapMaterialManager.end())
						{
							/*暂时手动的删除，但不知道有没有删除干净*/
							UEROMaterial* pMtl = itor->second;

							if (pMtl != NULL)
							{
								if (pMtl->m_pMaterialInstanceDynamic != NULL)
								{
									pMtl->m_pMaterialInstanceDynamic->RemoveFromRoot();
								}

								if (pMtl->m_pMaterialInstanceConstant != NULL)
								{
									pMtl->m_pMaterialInstanceConstant->RemoveFromRoot();
								}
								
								delete pMtl;
							}

							m_mapMaterialManager.erase(itor->first);
						}
					}
				}
			}

			void ROCacheManager::AddTextures(ROTexture*** & pAddTexture, int32 nCount)
			{
				for (int32 i = 0; i < nCount; i++)
				{
					ROTexture* pTexture = (*pAddTexture)[i];

					if (pTexture != NULL)
					{
						if (pTexture->m_pTexture != NULL)
						{
							pTexture->m_pTexture->m_nHashCode = pTexture->m_strTextureName;

							if (pTexture->m_pTexture->m_nSubTexure > 0)
							{
								UpdateTex2D(pTexture->m_pTexture);
							}
							else
							{
								// 创建纹理
								ToTex2D(pTexture->m_pTexture);
							}
						}
					}
				}
			}

			void ROCacheManager::DeleteTextures(__int64*** & pDeleteTexture, int32 nCount)
			{
				for (int32 i = 0; i < nCount; i++)
				{
					__int64* pTexture = (*pDeleteTexture)[i];
					if ((*pTexture) != 0)
					{
						std::map<__int64, UTexture2D*>::iterator itor = m_mapTextureManager.find(*pTexture);
						if (itor != m_mapTextureManager.end())
						{
							UTexture2D* pTex = itor->second;
							if (pTex == NULL)
							{
								continue;
							}
							else
							{
								pTex->RemoveFromRoot();
								pTex->MarkPendingKill();
							}

							m_mapTextureManager.erase(itor->first);
						}
					}
				}
			}

			void ROCacheManager::UpdateTexRegion(UTexture2D* pTex2D, uint8* pByte, int32 nOffset, int32 nOffsetX, int32 nOffsetY, 
				int32 nWidth, int32 nHeight,bool bIsData, int32 nNum , int32 nMipIndex)
			{
				UGFREEBYTE freeByte = _FreeByte;
				FUpdateTextureRegion2D* pRegion2D = new FUpdateTextureRegion2D;

				pRegion2D->DestX = nOffsetX;
				pRegion2D->DestY = nOffsetY;

				pRegion2D->SrcX = 0;
				pRegion2D->SrcY = 0;

				pRegion2D->Width = nWidth;
				pRegion2D->Height = nHeight;

				EPixelFormat pixelFormat = pTex2D->GetPixelFormat();

				int32 BlockSizeX = GPixelFormats[pixelFormat].BlockSizeX;
				int32 BlockSizeY = GPixelFormats[pixelFormat].BlockSizeY;
				int32 BlockBytes = GPixelFormats[pixelFormat].BlockBytes;

				int32 nTexWidth = pTex2D->GetSizeX();
				int32 nTemp = nWidth + nOffsetX;
				if (nTemp > nTexWidth)
				{
					return;
				}

				pTex2D->UpdateTextureRegions(nMipIndex, 1, pRegion2D, BlockBytes * (pRegion2D->Width / BlockSizeX), BlockBytes, pByte + nOffset, [nNum, freeByte, bIsData, nOffset](auto InTextureData, auto InRegions)
				{
					if (nNum == 1)
					{
						if (bIsData)
						{
							delete (InTextureData - nOffset);
						}
						else
						{
							char* pByte = (char*)(InTextureData - nOffset);
							freeByte(pByte);
						}

					}

					delete InRegions;
				});
			}

			void ROCacheManager::ToTex2D(DataTexture* pDataTexture)
			{
				if (pDataTexture == NULL || pDataTexture->m_nWidth == 0 || pDataTexture->m_nHeight == 0)
				{
					return;
				}

				int32 nWidth = pDataTexture->m_nWidth;
				int32 nHeight = pDataTexture->m_nHeight;

				// 获取纹理类型
				TextureType texType = DXT5;
				GetTextureType(pDataTexture->m_nTextureFormat, texType);

				uint8* DataBuffer = (uint8*)pDataTexture->m_pByte;

				int32 nBufferSize = pDataTexture->m_nSize;

				UTexture2D* pTexture2D = NULL;

				std::map<__int64, UTexture2D*>::iterator itor = m_mapTextureManager.find(pDataTexture->m_nHashCode);
				if (itor == m_mapTextureManager.end())
				{
					if (pDataTexture->m_nTextureFormat == 2)
					{
						pTexture2D = UTexture2D::CreateTransient(nWidth, nHeight, EPixelFormat::PF_DXT1);
					}
					else if (pDataTexture->m_nTextureFormat == 3)
					{
						pTexture2D = UTexture2D::CreateTransient(nWidth, nHeight, EPixelFormat::PF_DXT5);
						//pTexture2D->AddressX = TextureAddress::TA_Clamp;
						//pTexture2D->AddressY = TextureAddress::TA_Clamp;
					}
					else if (pDataTexture->m_nTextureFormat == 1 || pDataTexture->m_nTextureFormat == 0
						|| pDataTexture->m_nTextureFormat == 5 || pDataTexture->m_nTextureFormat == 6)
					{
						pTexture2D = UTexture2D::CreateTransient(nWidth, nHeight, EPixelFormat::PF_R8G8B8A8);

						pTexture2D->AddressX = TextureAddress::TA_Clamp;
						pTexture2D->AddressY = TextureAddress::TA_Clamp;
						pTexture2D->SRGB = 0;
					}
					else if (pDataTexture->m_nTextureFormat == 4)
					{
						pTexture2D = UTexture2D::CreateTransient(nWidth, nHeight, EPixelFormat::PF_A32B32G32R32F);
						pTexture2D->Filter = TF_Nearest;
					}

					if (pTexture2D == NULL || pTexture2D->PlatformData == nullptr || pTexture2D->PlatformData->Mips.Num() == 0)
					{
						return;
					}

					pTexture2D->AddToRoot();

					m_mapTextureManager[pDataTexture->m_nHashCode] = pTexture2D;
				}
				else
				{
					pTexture2D = itor->second;
				}


				if (pTexture2D == NULL || pTexture2D->PlatformData == nullptr || pTexture2D->PlatformData->Mips.Num() == 0)
				{
					return;
				}

				// 计算Mipmap
				std::map<int, int> mapMipmaps;
				CalMipMap(nWidth, nHeight, pDataTexture->m_nSize, texType, mapMipmaps, pTexture2D->GetPixelFormat());

				bool bData = false;
				if (pDataTexture->m_nTextureFormat == 0 || pDataTexture->m_nTextureFormat == 6)
				{
					uint8* pNewData = new uint8[nWidth * nHeight * 4];

					for (int i = 0; i < nWidth * nHeight; i++)
					{
						pNewData[i * 4 + 0] = DataBuffer[i * 3 + 0];
						pNewData[i * 4 + 1] = DataBuffer[i * 3 + 1];
						pNewData[i * 4 + 2] = DataBuffer[i * 3 + 2];
						pNewData[i * 4 + 3] = 255;
					}

					DataBuffer = pNewData;
					texType = RGBA32;
					bData = true;
				}

				pTexture2D->UpdateResource();

				int32 nNum = mapMipmaps.size();
				int32 nOffset = 0;
				std::map<int, int>::iterator itorMipmap = mapMipmaps.begin();
				while (itorMipmap != mapMipmaps.end())
				{
					if (itorMipmap->first == 0)
					{
						nBufferSize = CalTextureSize(nWidth, nHeight, texType);
						UpdateTexRegion(pTexture2D, DataBuffer, nOffset, 0, 0, nWidth, nHeight, bData, nNum , 0);

						nOffset += nBufferSize;
						nNum--;
					}
					else
					{
						int32 nLevel = FMath::Pow(2, itorMipmap->first);

						int32 nMipWidth  = nWidth / nLevel;
						int32 nMipHeight = nHeight / nLevel;

						nBufferSize = CalTextureSize(nMipWidth, nMipHeight, texType);
						UpdateTexRegion(pTexture2D, DataBuffer, nOffset, 0, 0, nMipWidth, nMipHeight, bData, nNum , itorMipmap->first);

						nOffset += nBufferSize;
						nNum--;
					}

					itorMipmap++;
				}

				if (pDataTexture->m_nTextureFormat != 0 && pDataTexture->m_nTextureFormat != 6)
				{
					pDataTexture->m_pByte = nullptr;
				}
			}
			//===========================================================================================
			static void SetMIDMatrix(UMaterialInstanceDynamic* pMat, FMatrix mat)
			{
				FLinearColor vRow;
				vRow.R = mat.M[0][0];
				vRow.G = mat.M[0][1];
				vRow.B = mat.M[0][2];
				vRow.A = mat.M[0][3];
				pMat->SetVectorParameterValue(TEXT("CenterPositionOne"), vRow);

				vRow.R = mat.M[1][0];
				vRow.G = mat.M[1][1];
				vRow.B = mat.M[1][2];
				vRow.A = mat.M[1][3];
				pMat->SetVectorParameterValue(TEXT("CenterPositionTwo"), vRow);

				vRow.R = mat.M[2][0];
				vRow.G = mat.M[2][1];
				vRow.B = mat.M[2][2];
				vRow.A = mat.M[2][3];
				pMat->SetVectorParameterValue(TEXT("CenterPositionThree"), vRow);

				vRow.R = mat.M[3][0];
				vRow.G = mat.M[3][1];
				vRow.B = mat.M[3][2];
				vRow.A = mat.M[3][3];
				pMat->SetVectorParameterValue(TEXT("CenterPositionFour"), vRow);
			}

			void ROCacheManager::UpdateLayerInfo(UMaterialInstanceDynamic* &pMD, FString strParentName, USuperMap_MeshComponentInterface* pComponent)
			{
				int32 nPlane = (Core::ROCacheManager::m_eSceneType == SceneType::Flat ? 0 : 1);

				// 找到所属图层信息
				Layer3Ds* pLayer3Ds = m_pScene->GetLayer3Ds();
				int32 nLayer3D = pLayer3Ds->Count();
				for (int32 n = 0; n < nLayer3D; n++)
				{
					Layer3D* pLayer3D = pLayer3Ds->GetAt(n);
					if (pLayer3D->Type() == Layer3DType::DatasetModel)
					{
						pComponent->SetLayerName(pLayer3D->Name().ToString());
					}
					if (pLayer3D->Type() == Layer3DType::S3M)
					{
						Layer3DS3MFile* pLayer3DS3MFile = (Layer3DS3MFile*)pLayer3D;
						FString strSceneNode = pLayer3DS3MFile->NodeName().ToString();
						if (strSceneNode == strParentName)
						{
							HypsometricSetting* pHypsometricSetting = pLayer3DS3MFile->GetHypsometricSetting();
							double dOffset = pLayer3DS3MFile->GetConstantPolygonOffset();
							//分层设色
							if (pHypsometricSetting != nullptr)
							{
								pMD->SetScalarParameterValue(FName("HypsometricSettingMode"), int(pHypsometricSetting->GetAnalysisMode()));
								pMD->SetScalarParameterValue(FName("DisplayMode"), int(pHypsometricSetting->GetDisplayMode()));
								pMD->SetVectorParameterValue(FName("LineColor"), FLinearColor(pHypsometricSetting->GetLineColor()));
								pMD->SetScalarParameterValue(FName("LinesInterval"), pHypsometricSetting->GetLinesInterval());
								pMD->SetScalarParameterValue(FName("ColorTableMinKey"), pHypsometricSetting->GetColorTableMinKey());
								pMD->SetScalarParameterValue(FName("ColorTableMaxKey"), pHypsometricSetting->GetColorTableMaxKey());
								pMD->SetScalarParameterValue(FName("MinVisibleValue"), pHypsometricSetting->GetMinVisibleValue());
								pMD->SetScalarParameterValue(FName("MaxVisibleValue"), pHypsometricSetting->GetMaxVisibleValue());
								pMD->SetTextureParameterValue(FName("HypsometricSettingTexture"), pHypsometricSetting->GetColorTableTexture());
							}
							//多边形偏移
							if (dOffset > 0)
							{
								pMD->SetScalarParameterValue(FName("OffsetValue"), dOffset);
							}

							pLayer3DS3MFile->SetClipShaderParam(pMD);

						}
					}

				}	
			}

			void ROCacheManager::UpdateFlood(UMaterialInstanceDynamic* &pMD)
			{
				int nCount = m_pScene->GetTerrainLayers()->Count();
				if (nCount < 1)
				{
					return;
				}

				TerrainLayers* pTerrainLayers = m_pScene->GetTerrainLayers();
				if (pTerrainLayers->GetAt(0) == nullptr)
				{
					return;
				}

				HypsometricSetting* pHypsometricSetting = pTerrainLayers->GetHypsometricSetting();
				if (pHypsometricSetting != nullptr)
				{
					pMD->SetScalarParameterValue(FName("HypsometricSettingMode"), int(pHypsometricSetting->GetAnalysisMode()));
					pMD->SetScalarParameterValue(FName("DisplayMode"), int(pHypsometricSetting->GetDisplayMode()));
					pMD->SetVectorParameterValue(FName("LineColor"), FLinearColor(pHypsometricSetting->GetLineColor()));
					pMD->SetScalarParameterValue(FName("LinesInterval"), pHypsometricSetting->GetLinesInterval());
					pMD->SetScalarParameterValue(FName("ColorTableMinKey"), pHypsometricSetting->GetColorTableMinKey());
					pMD->SetScalarParameterValue(FName("ColorTableMaxKey"), pHypsometricSetting->GetColorTableMaxKey());
					pMD->SetScalarParameterValue(FName("MinVisibleValue"), pHypsometricSetting->GetMinVisibleValue());
					pMD->SetScalarParameterValue(FName("MaxVisibleValue"), pHypsometricSetting->GetMaxVisibleValue());
					pMD->SetTextureParameterValue(FName("HypsometricSettingTexture"), pHypsometricSetting->GetColorTableTexture());
				}
			}

			void ROCacheManager::UpdateSlope(UMaterialInstanceDynamic* &pMD)
			{
				int nCount = m_pScene->GetTerrainLayers()->Count();
				if (nCount < 1)
				{
					return;
				}

				TerrainLayers* pTerrainLayers = m_pScene->GetTerrainLayers();
				if (pTerrainLayers == nullptr)
				{
					return;
				}

				SlopeSetting* m_pSlopeSetting = pTerrainLayers->GetSlopeSetting();
				if (m_pSlopeSetting != nullptr)
				{
					float fColorTableMinKey = FMath::DegreesToRadians(m_pSlopeSetting->GetColorTableMinKey());
					float fColorTableMaxKey = FMath::DegreesToRadians(m_pSlopeSetting->GetColorTableMaxKey());
					float fMinVisibleValue = FMath::DegreesToRadians(m_pSlopeSetting->GetMinVisibleValue());
					float fMaxVisibleValue = FMath::DegreesToRadians(m_pSlopeSetting->GetMaxVisibleValue());
					float fTopLevl = _TerrainLayer_GetTopLevel();
					float fArrowsMove = m_pSlopeSetting->IsArrowMove() ? 1.0 : 0.0;

					pMD->SetScalarParameterValue(FName("SlopeDisplayMode"), int(m_pSlopeSetting->GetDisplaySytle()));
					pMD->SetScalarParameterValue(FName("SlopeFloorAngle"), fColorTableMinKey);
					pMD->SetScalarParameterValue(FName("SlopeCeilAngle"), fColorTableMaxKey);
					pMD->SetScalarParameterValue(FName("SlopeMinVisibleSlope"), fMinVisibleValue);
					pMD->SetScalarParameterValue(FName("SlopeMaxVisibleSlope"), fMaxVisibleValue);
					pMD->SetTextureParameterValue(FName("SlopeColorTexture"), m_pSlopeSetting->GetColorTableTexture());
					if (m_pSlopeSetting->GetArrowTexture() != nullptr)
					{
						pMD->SetTextureParameterValue(FName("SlopeArrowTexture"), m_pSlopeSetting->GetArrowTexture());
					}
					pMD->SetScalarParameterValue(FName("SlopeArrowsMove"), fArrowsMove);
					pMD->SetScalarParameterValue(FName("SlopeTopLevel"), fTopLevl);
				}
			}

			void ROCacheManager::UseLayerMaterial(UMaterialInstanceDynamic* &pMD, UEROMaterial* & pMat, FString strParentName)
			{
				
			}

			void ROCacheManager::AddInstancedMeshComponent(RONode* pRONode, USuperMap_MeshComponentInterface* pComponent)
			{
				// 添加实例化对象
				UStaticMesh* pStaticMesh = nullptr;
				FString strStaticMeshName = UTF8_TO_TCHAR(pRONode->m_pROInstanceMesh->m_strMeshName);

				int32 nIndex = strStaticMeshName.Find(TEXT("StaticMesh"));
				if (nIndex != INDEX_NONE)
				{
					strStaticMeshName.RemoveAt(0, nIndex);
				}

				std::map<FString, std::pair<UStaticMesh*, int32> >::iterator itorStaticMesh = m_mapStaticMeshs.find(strStaticMeshName);
				if (itorStaticMesh != m_mapStaticMeshs.end())
				{
					pStaticMesh = itorStaticMesh->second.first;
					itorStaticMesh->second.second++;
				}
				else
				{
					pStaticMesh = Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), nullptr, *strStaticMeshName));

					if (pStaticMesh != nullptr)
					{
						std::pair<UStaticMesh*, int32> pairInfo;
						pairInfo.first = pStaticMesh;
						pairInfo.second = 1;

						m_mapStaticMeshs[strStaticMeshName] = pairInfo;
					}

				}

				if (pStaticMesh != nullptr)
				{
					pComponent->SetCustomStaticMesh(strStaticMeshName, pStaticMesh);

					FSMMesh smMesh;
					smMesh.m_pDataVertex = pRONode->m_pROInstanceMesh->m_pDataVertex;
					smMesh.m_arrDataIndex.Add(( * pRONode->m_pROInstanceMesh->m_arrIndexPack)[0]);

					pComponent->CreateMesh(smMesh, false);
				}

				std::string actorName = pRONode->m_strNodeName;
				m_mapRenderQueue[actorName] = pComponent;
			}

			void ROCacheManager::SetPBRTextureParam(UEROMaterial* pMaterial, FName & strTexture, int32 nTexCount)
			{
				if (pMaterial == nullptr)
				{
					return;
				}

				// 基础纹理
				if (pMaterial->m_nBaseTextureIndex == nTexCount)
				{
					strTexture = TEXT("BaseTexture");
				}// 自发光纹理
				else if (pMaterial->m_nEmissiveTextureIndex == nTexCount)
				{
					strTexture = TEXT("EmissiveTexture");
				}// 法线纹理
				else if (pMaterial->m_nNormalTextureIndex == nTexCount)
				{
					strTexture = TEXT("NormalTexture");
				}// 金属纹理
				else if (pMaterial->m_nMetallicTextureIndex == nTexCount)
				{
					strTexture = TEXT("MetallicTexture");
				}// 遮挡纹理
				else if (pMaterial->m_nOcclusionTextureIndex == nTexCount)
				{
					strTexture = TEXT("OcclusionTexture");
				}
			}

			//===========================================================================================

			void ROCacheManager::CreateMesh(RONode* pRONode, ROEntity* pROEntity, USuperMap_MeshComponentInterface* pSceneNode, DataVertex* pDataVertex, DataIndice* pDataIndice, bool bCopyVertex)
			{
				// 材质
				int32 nTextureWidth = 0;
				int32 nTextureHeight = 0;
				Matrix4d matTex;
				UTexture2D* pSprite = nullptr;
				__int64 nMtlHashCode = pDataIndice->m_MtlHashCode;
				UMaterialInstanceDynamic*  pMID = NULL;
				UMaterialInstanceConstant*  pMIC = NULL;
				std::map<__int64, UEROMaterial*>::iterator itorMtl = m_mapMaterialManager.find(nMtlHashCode);
				int32 nTexCount = 0;
				int32 nBatchIndex = 0;
				bool bCollision = true;
				bool bNeedSecondMaterial = false;
				if (itorMtl != m_mapMaterialManager.end())
				{
					bool bIsPBR = itorMtl->second->m_bIsPBR;
					pMIC = itorMtl->second->m_pMaterialInstanceConstant;
					pMID = itorMtl->second->m_pMaterialInstanceDynamic;
					bCollision = itorMtl->second->m_bCollision;
					matTex = itorMtl->second->m_matTex;
					bNeedSecondMaterial = itorMtl->second->m_bNeedSecondMaterial;

					//原始材质名称
					pSceneNode->SetRealMaterialName(itorMtl->second->m_strName);

					if (pMIC == nullptr)
					{
						std::map<__int64, UTexture2D*>::iterator itorTex = m_mapTextureManager.find(itorMtl->second->m_nTextureHashCode);
						if (itorTex != m_mapTextureManager.end())
						{
							FName strName = "TextureParam";
							if (nBatchIndex == itorMtl->second->m_nBatchTexIndex)
							{
								strName = "BatchTexture";

								itorTex->second->Filter = TF_Nearest;
								itorTex->second->SRGB = 0;
							}
							else
							{
								nTexCount++;
							}

							if (bIsPBR)
							{
								SetPBRTextureParam(itorMtl->second, strName, nTexCount);
							}

							pMID->SetTextureParameterValue(strName, itorTex->second);

							float sizeX = itorTex->second->GetSizeX();
							float sizeY = itorTex->second->GetSizeY();
							FLinearColor texonesize;
							texonesize.R = sizeX;
							texonesize.G = sizeY;

							nTextureWidth = sizeX;
							nTextureHeight = sizeY;

							pMID->SetVectorParameterValue(FName("TexOneSize"), texonesize);

							pSprite = itorTex->second;
						}
						nBatchIndex++;

						if (pMID != nullptr && pMID->GetBaseMaterial() != nullptr && pMID->GetBaseMaterial()->GetName() == "NewModel")
						{
							itorTex = m_mapTextureManager.find(itorMtl->second->m_nTextureHashCode1);
							if (itorTex != m_mapTextureManager.end() && itorTex->second != nullptr)
							{
								std::map<__int64, UTexture2D*>::iterator itorTex2 = m_mapTextureManager.find(itorMtl->second->m_nTextureHashCode2);
								if (itorTex2 != m_mapTextureManager.end() && itorTex2->second != nullptr)
								{
									int nTempBatchIndex = nBatchIndex + 1;
									if (nBatchIndex == itorMtl->second->m_nBatchTexIndex)
									{
										pMID->SetTextureParameterValue(FName("BatchTexture"), itorTex2->second);
										pMID->SetTextureParameterValue(FName("TextureParam1"), itorTex->second);

										itorTex2->second->Filter = TF_Nearest;
										itorTex2->second->SRGB = 0;
									}
									else
									{
										pMID->SetTextureParameterValue(FName("TextureParam1"), itorTex2->second);
										nTexCount++;
									}
								}
								else
								{
									pMID->SetTextureParameterValue(FName("TextureParam1"), itorTex->second);
								}
							}
							nBatchIndex += 2;

							itorTex = m_mapTextureManager.find(itorMtl->second->m_nTextureHashCode3);
							if (itorTex != m_mapTextureManager.end() && itorTex->second != nullptr)
							{
								if (nBatchIndex == itorMtl->second->m_nBatchTexIndex)
								{
									pMID->SetTextureParameterValue(FName("BatchTexture"), itorTex->second);
									itorTex->second->Filter = TF_Nearest;
									itorTex->second->SRGB = 0;
								}
							}
						}
						else
						{
							itorTex = m_mapTextureManager.find(itorMtl->second->m_nTextureHashCode1);
							if (itorTex != m_mapTextureManager.end())
							{
								FName strName1 = "TextureParam1";
								if (nBatchIndex == itorMtl->second->m_nBatchTexIndex)
								{
									strName1 = "BatchTexture";
									itorTex->second->Filter = TF_Nearest;
									itorTex->second->SRGB = 0;
								}
								else
								{
									nTexCount++;
								}

								if (nBatchIndex == itorMtl->second->m_nTextureNormalIndex)
								{
									strName1 = "SMTexNormal";
									itorTex->second->SRGB = 0;
									float sizeX = itorTex->second->GetSizeX();
									float sizeY = itorTex->second->GetSizeY();
									if (sizeX == 4.0 && sizeY == 4.0)
									{
										pMID->SetScalarParameterValue(FName("InValidNormal"), 1.0);
									}
								}

								if (bIsPBR)
								{
									SetPBRTextureParam(itorMtl->second, strName1, nTexCount);
								}

								pMID->SetTextureParameterValue(strName1, itorTex->second);
								
							}
							nBatchIndex++;

							itorTex = m_mapTextureManager.find(itorMtl->second->m_nTextureHashCode2);
							if (itorTex != m_mapTextureManager.end())
							{
								FName strName2 = "TextureParam2";
								if (nBatchIndex == itorMtl->second->m_nBatchTexIndex)
								{
									strName2 = "BatchTexture";
									itorTex->second->Filter = TF_Nearest;
									itorTex->second->SRGB = 0;
								}
								else
								{
									nTexCount++;
								}

								if (nBatchIndex == itorMtl->second->m_nTextureNormalIndex)
								{
									strName2 = "SMTexNormal";
									itorTex->second->SRGB = 0;
									float sizeX = itorTex->second->GetSizeX();
									float sizeY = itorTex->second->GetSizeY();
									if (sizeX == 4.0 && sizeY == 4.0)
									{
										pMID->SetScalarParameterValue(FName("InValidNormal"), 1.0);
									}
								}

								if (bIsPBR)
								{
									SetPBRTextureParam(itorMtl->second, strName2, nTexCount);
								}

								pMID->SetTextureParameterValue(strName2, itorTex->second);
							}
							nBatchIndex++;

							itorTex = m_mapTextureManager.find(itorMtl->second->m_nTextureHashCode3);
							if (itorTex != m_mapTextureManager.end())
							{
								FName strName3 = "TextureParam3";
								if (nBatchIndex == itorMtl->second->m_nBatchTexIndex)
								{
									strName3 = "BatchTexture";
									itorTex->second->Filter = TF_Nearest;
									itorTex->second->SRGB = 0;
								}
								else
								{
									nTexCount++;
								}

								if (nBatchIndex == itorMtl->second->m_nTextureNormalIndex)
								{
									strName3 = "SMTexNormal";
									itorTex->second->SRGB = 0;
									float sizeX = itorTex->second->GetSizeX();
									float sizeY = itorTex->second->GetSizeY();
									if (sizeX == 4.0 && sizeY == 4.0)
									{
										pMID->SetScalarParameterValue(FName("InValidNormal"), 1.0);
									}
								}

								if (bIsPBR)
								{
									SetPBRTextureParam(itorMtl->second, strName3, nTexCount);
								}

								pMID->SetTextureParameterValue(strName3, itorTex->second);
								
							}
							nBatchIndex++;
						}

						if (itorMtl->second->m_nTextureNormalIndex != -1)
						{
							pMID->SetScalarParameterValue(FName("nSMNormalTexture"), 1.0);
						}

						if (itorMtl->second->m_nBatchTexIndex != -1)
						{
							pMID->SetScalarParameterValue(FName("nBatchTexture"), 1.0);
						}

						pMID->SetScalarParameterValue(FName("TexCount"), nTexCount);
						pMID->SetVectorParameterValue(FName("ID"), m_vID);

						UpdateAnalyst(pMID);

						FString strParentName(pRONode->m_strParentName);
						UseLayerMaterial(pMID, itorMtl->second, strParentName);

						UpdateLayerInfo(pMID, strParentName, pSceneNode);

						UpdateFlood(pMID);

						UpdateSlope(pMID);
					}

				}

				if (pDataVertex->m_doubleObjectMat != NULL)
				{
					FVector vOffset(ROCacheManager::m_vecWorldOrigin);
					Matrix4d doubleObjectMatrix(pDataVertex->m_doubleObjectMat);

					doubleObjectMatrix[3][0] *= M_TO_CM;
					doubleObjectMatrix[3][1] *= M_TO_CM;
					doubleObjectMatrix[3][2] *= M_TO_CM;

					doubleObjectMatrix = doubleObjectMatrix * Georeference::GetECEFtoGeoreference();

					doubleObjectMatrix[3][0] -= vOffset.X;
					doubleObjectMatrix[3][1] -= vOffset.Y;
					doubleObjectMatrix[3][2] -= vOffset.Z;

					FMatrix dMattt;
					Matrix4d::ToFMatrix(doubleObjectMatrix, dMattt);

					FTransform trans;
					trans.SetFromMatrix(dMattt);

					pSceneNode->SetWorldTransform(trans);
				}

				FSMMesh meshData;
				meshData.m_arrDataIndex.Add(pDataIndice);
				meshData.m_pDataVertex = pDataVertex;
				meshData.m_matTex = matTex;
				meshData.m_nTextureWidth = nTextureWidth;
				meshData.m_nTextureHeight = nTextureHeight;
				meshData.m_bCopyVertex = bCopyVertex;

				if (pMID != nullptr)
				{
					pSceneNode->CreateMesh(meshData, bCollision);
					pSceneNode->SetTexture(pSprite);
				}
				else if (pMIC != nullptr)
				{
					pSceneNode->CreateMesh(meshData, bCollision);
				}

				// 目前只在运行模式下设置选择对象使用的材质
				if (m_pWorld->WorldType != EWorldType::Editor)
				{
					if (bNeedSecondMaterial)
					{
						UMaterialInterface* pMI = nullptr;
						if (pMID != nullptr)
						{
							pMI = (UMaterialInterface*)pMID;
						}
						else if (pMIC != nullptr)
						{
							pMI = (UMaterialInterface*)pMIC;
						}

						CreateSelectionMaterial(pSceneNode, pMI);
					}
				}
			}



			void ROCacheManager::AddGameObjectForComponent(RONode*** & pAddNodes, int nCount)
			{
				for (int i = 0; i < nCount; i++)
				{
					RONode* pRONode = (*pAddNodes)[i];

					USuperMap_MeshComponentInterface* pSceneNode = CreateGameObjectForComponent(pRONode);

					if (pRONode != NULL)
					{
						if (pSceneNode != nullptr && pRONode->m_pROEntity != NULL
							&& pSceneNode->GetComponentType() == CustomRealTimeRaster)
						{
							ROEntity* pROEntity = pRONode->m_pROEntity;

							FSMMesh meshData;
							meshData.m_arrDataIndex.Add((*(pROEntity->m_arrIndexPack))[0]);
							meshData.m_pDataVertex = pROEntity->m_pDataVertex;
							meshData.m_nTextureWidth = 0;
							meshData.m_nTextureHeight = 0;

							pSceneNode->CreateMesh(meshData, false);

							std::string actorName = pRONode->m_strNodeName;
							m_mapRealTimeRasterRenderQueue[actorName] = pSceneNode;

							// 顶点数据包由上层来手动释放
							pROEntity->m_pDataVertex = nullptr;
							(*(pROEntity->m_arrIndexPack))[0] = nullptr;
							continue;
						}

						if (pRONode->m_pROInstanceMesh != nullptr)
						{
							AddInstancedMeshComponent(pRONode, pSceneNode);
						}

						if (pRONode->m_pROEntity != NULL)
						{
							ROEntity* pROEntity = pRONode->m_pROEntity;

							if (pROEntity != NULL)
							{
								if (pROEntity->m_pDataVertex != NULL)
								{
									
									if (pROEntity->m_nIndexPackCount > 1)
									{

										for (unsigned int j = 0; j < pROEntity->m_nIndexPackCount; j++)
										{
											FString nodeName = UTF8_TO_TCHAR(pRONode->m_strNodeName);
											FString nameChild = nodeName + "_" + FString::FromInt(j);
											
											const TCHAR* c = *nameChild;
											char* cc = TCHAR_TO_UTF8(c);


											USuperMap_MeshComponentInterface* pMeshInterface = NewObject<USuperMap_MeshComponentInterface>(pSceneNode);
											pMeshInterface->CreateMeshComponent(CustomMeshComponent);

											pMeshInterface->RegisterComponent();
											pMeshInterface->SetName(cc);


											DataIndice* pDataIndice = (*(pROEntity->m_arrIndexPack))[j];

											if (j == pROEntity->m_nIndexPackCount - 1)
											{
												CreateMesh(pRONode, pROEntity, pMeshInterface, pROEntity->m_pDataVertex, pDataIndice);
											}
											else
											{
												DataVertex* pDataVertex = pROEntity->m_pDataVertex->Copy();
												CreateMesh(pRONode, pROEntity, pMeshInterface, pDataVertex, pDataIndice, true);
											}


											if (pSceneNode->GetComponentType() == CustomMeshComponent)
											{
												// 顶点数据包由上层来手动释放
												(*(pROEntity->m_arrIndexPack))[j] = nullptr;
											}
										}

									}
									else
									{
										DataIndice* pDataIndice = (*(pROEntity->m_arrIndexPack))[0];

										CreateMesh(pRONode, pROEntity, pSceneNode, pROEntity->m_pDataVertex, pDataIndice);

										if (pSceneNode->GetComponentType() == CustomMeshComponent)
										{
											// 顶点数据包由上层来手动释放
											(*(pROEntity->m_arrIndexPack))[0] = nullptr;
										}
									}

									if (pSceneNode->GetComponentType() == CustomMeshComponent)
									{
										// 顶点数据包由上层来手动释放
										pROEntity->m_pDataVertex = nullptr;
									}

									std::string actorName = pRONode->m_strNodeName;
									m_mapRenderQueue[actorName] = pSceneNode;
								}
							}
						}

					}
				}
			}

			void ROCacheManager::UpdateGameObjectForComponent(RONode*** & pUpdateNodes, int nCount)
			{
				for (int i = 0; i < nCount; i++)
				{
					RONode* pRONode = (*pUpdateNodes)[i];

					if (pRONode != NULL)
					{
						std::map<std::string, USuperMap_MeshComponentInterface*>::iterator itor = m_mapRootNode.find(pRONode->m_strNodeName);
						if (itor != m_mapRootNode.end())
						{
							// 更改状态
							USuperMap_MeshComponentInterface* pComp = itor->second;
							bool bVisible = (pRONode->m_bVisible == 0 ? true : false);

							FString strName1(m_strRoot.c_str());
							FString strName2(pRONode->m_strParentName);
							if (strName1 == strName2)
							{
								SetLayerVisibleForComponent(pComp, !bVisible);
								continue;
							}

							if (pComp != nullptr)
							{
								pComp->SetInternalVisibility(!bVisible);
							}
						}
					}
				}
			}

			void ROCacheManager::DeleteGameObjectForComponent(ROEmptyNode*** & pDeleteNodes, int nCount)
			{
				for (int i = 0; i < nCount; i++)
				{
					ROEmptyNode* pDltNode = (*pDeleteNodes)[i];

					std::map<std::string, USuperMap_MeshComponentInterface*>::iterator itorComponent = m_mapRootNode.find(pDltNode->m_strNodeName);
					if (itorComponent != m_mapRootNode.end())
					{
						USuperMap_MeshComponentInterface* pComponent = itorComponent->second;
						DestroyNodeForComponent(pComponent);
					}
				}
			}

			void ROCacheManager::DestroyNodeForComponent(USuperMap_MeshComponentInterface* pEntityNode)
			{
				FString strNodeName = pEntityNode->GetName().ToString();
				std::string strName(TCHAR_TO_UTF8(*strNodeName));

				std::map<std::string, USuperMap_MeshComponentInterface*>::iterator itorCom = m_mapRootNode.find(strName);
				bool bInRootNode = ((itorCom == m_mapRootNode.end()) ? false : true);
				itorCom = m_mapRenderQueue.find(strName);
				bool bInRenderQueue = ((itorCom == m_mapRenderQueue.end()) ? false : true);

				if (!bInRootNode && !bInRenderQueue)
				{
					return;
				}

				{
					TArray<USceneComponent*> arrChilds = pEntityNode->GetAttachSceneComponentChildren();

					int nChildCount = arrChilds.Num();
					for (int i = 0; i < nChildCount; i++)
					{
						USuperMap_MeshComponentInterface* pSceneComponent = (USuperMap_MeshComponentInterface*)arrChilds[i];
						if (pSceneComponent == NULL)
						{
							continue;
						}

						DestroyNodeForComponent(pSceneComponent);
					}
				}

				if (bInRootNode)
				{
					m_mapRootNode.erase(strName);
					m_mapRealTimeRasterRenderQueue.erase(strName);
				}

				if (bInRenderQueue)
				{
					m_mapRenderQueue.erase(strName);
				}

				pEntityNode->ReleaseMeshComponent();
				pEntityNode->ConditionalBeginDestroy();
			}

			USuperMap_MeshComponentInterface* ROCacheManager::CreateGameObjectForComponent(RONode* pNode)
			{
				// 创建一个根节点的Actor
				if (m_pRootNode == nullptr)
				{
					m_pRootNode = m_pWorld->SpawnActor<ASuperMap_ROEntityActor>();
					m_pRootNode->Tags.Add(TEXT("SUPERMAP"));
				}

				// 创建一个根节点的组件
				std::map<std::string, USuperMap_MeshComponentInterface*>::iterator itorNode = m_mapRootNode.find(m_strRoot);
				if (itorNode == m_mapRootNode.end())
				{
					FName strName(m_strRoot.c_str());
					m_pRootComponent = ROCacheManager::CreateComponent(strName , pNode);
					m_mapRootNode[m_strRoot] = m_pRootComponent;
				}

				USuperMap_MeshComponentInterface* pParentEntity = nullptr;
				itorNode = m_mapRootNode.find(pNode->m_strParentName);
				if (itorNode != m_mapRootNode.end())
				{
					pParentEntity = itorNode->second;
				}


				USuperMap_MeshComponentInterface* pEntity = nullptr;
				itorNode = m_mapRootNode.find(pNode->m_strNodeName);
				if (itorNode == m_mapRootNode.end())
				{
					FName strName(pNode->m_strNodeName);
					pEntity = ROCacheManager::CreateComponent(strName, pNode);
					if (pParentEntity != nullptr)
					{
						FAttachmentTransformRules transformRules(EAttachmentRule::KeepRelative, true);
						pEntity->AttachToComponent(pParentEntity, transformRules);
					}

					std::string sName = pNode->m_strNodeName;
					m_mapRootNode[sName] = pEntity;
				}
				else
				{
					std::string sName = pNode->m_strNodeName;
					pEntity = m_mapRootNode[sName];
				}

				// 更新子节点
				if (pNode->m_nChildCount > 0 && pNode->m_pChildNames != NULL)
				{
					for (int j = 0; j < pNode->m_nChildCount; j++)
					{
						std::string sName = (*pNode->m_pChildNames)[j];
						itorNode = m_mapRootNode.find(sName);
						if (itorNode != m_mapRootNode.end())
						{
							USuperMap_MeshComponentInterface* pChildCom = itorNode->second;

							FAttachmentTransformRules transformRules(EAttachmentRule::KeepRelative, true);
							pChildCom->AttachToComponent(pEntity, transformRules);
						}
					}
				}

				return pEntity;
			}
			
			USuperMap_MeshComponentInterface* ROCacheManager::CreateComponent(FName& name, RONode* pNode)
			{
				if (m_pWorld == NULL || m_pRootNode == nullptr)
				{
					return NULL;
				}

				bool bIsBillboard = false;
				if (pNode->m_pROEntity != NULL)
				{
					DataIndice* pDataIndice = (*(pNode->m_pROEntity->m_arrIndexPack))[0];

					// 材质
					__int64 nMtlHashCode = pDataIndice->m_MtlHashCode;
					UMaterialInstanceDynamic*  pMID = NULL;
					UMaterialInstanceConstant*  pMIC = NULL;
					std::map<__int64, UEROMaterial*>::iterator itorMtl = m_mapMaterialManager.find(nMtlHashCode);
					if (itorMtl != m_mapMaterialManager.end())
					{
						pMID = itorMtl->second->m_pMaterialInstanceDynamic;
						if (pMID != nullptr)
						{
							if (pMID->GetBaseMaterial()->GetName() == TEXT("BillboardMaterial"))
							{
								bIsBillboard = true;
							}
						}
					}
				}

				ComponentType eComponentType = CustomMeshComponent;
				if (m_pWorld->WorldType == EWorldType::Editor)
				{
					if (pNode->m_pROInstanceMesh != nullptr)
					{
						eComponentType = CustomInstancedStaticMeshComponent;
					}
					else
					{
						if (bIsBillboard)
						{
							eComponentType = CustomBillboardComponent;
						}
						else
						{
							eComponentType = CustomStaticMeshComponent;
						}
					}
				}
				else
				{
					if (pNode->m_pROInstanceMesh != nullptr)
					{
						eComponentType = CustomInstancedStaticMeshComponent;
					}
					else
					{
						if (bIsBillboard)
						{
							eComponentType = CustomBillboardComponent;
						}
						else if (pNode->m_nSceneManagerType == REAL_TIME_ELEVATION_S3M)
						{
							eComponentType = CustomRealTimeRaster;
						}
						else
						{
							eComponentType = CustomMeshComponent;
						}
						
					}
				}

				USuperMap_MeshComponentInterface* pMeshInterface = NewObject<USuperMap_MeshComponentInterface>(m_pRootNode);
				pMeshInterface->CreateMeshComponent(eComponentType , m_pRootNode);

				pMeshInterface->RegisterComponent();
				pMeshInterface->SetName(name);
				return pMeshInterface;
			}

			void ROCacheManager::SetLayerVisibleForComponent(USuperMap_MeshComponentInterface* pComponent, bool bVisible)
			{
				if (pComponent == nullptr)
				{
					return;
				}

				if (pComponent->GetLayerVisibility() == bVisible)
				{
					return;
				}
				pComponent->SetLayerVisibility(bVisible);

				// 遍历所有节点
				TArray<USceneComponent*> arrChilds = pComponent->GetAttachSceneComponentChildren();

				int nChildCount = arrChilds.Num();
				for (int i = 0; i < nChildCount; i++)
				{
					USceneComponent* pSceneComponent = arrChilds[i];
					if (pSceneComponent != nullptr)
					{
						USuperMap_MeshComponentInterface* pProceduralMeshComponent = (USuperMap_MeshComponentInterface*)pSceneComponent;
						if (pProceduralMeshComponent != nullptr)
						{
							pProceduralMeshComponent->SetLayerVisibility(bVisible);
						}
					}
				}
			}

			//===========================================================================================
			
			void ROCacheManager::UpdateTex2D(DataTexture* pDataUpdateTexture)
			{
				if (pDataUpdateTexture->m_nSubTexure == 0)
				{
					return;
				}

				std::map<__int64, UTexture2D*>::iterator itor = m_mapTextureManager.find(pDataUpdateTexture->m_nHashCode);
				if (itor != m_mapTextureManager.end())
				{
					UTexture2D* pTexture2D = itor->second;
					if (pTexture2D != nullptr)
					{
						for (int i = 0; i < pDataUpdateTexture->m_nSubTexure; i++)
						{
							DataSubTexture* pDataSubTexture = (*pDataUpdateTexture->m_pSubTexture)[i];
							if (pDataSubTexture != nullptr)
							{
								UpdateTexRegion(pTexture2D , (uint8*)pDataSubTexture->m_pByte , 0, pDataSubTexture->m_nOffsetX, pDataSubTexture->m_nOffsetY,
									pDataSubTexture->m_nWidth, pDataSubTexture->m_nHeight, false, 1, 0);

								pDataSubTexture->m_pByte = nullptr;
							}

						}
					}
				}
			}

			ASuperMap_ROEntityActor* ROCacheManager::GetRootNode()
			{
				return m_pRootNode;
			}

			//===========================================================================

			void ROCacheManager::UpdateAnalyst(UMaterialInstanceDynamic* pMD)
			{
				if (pMD == nullptr)
				{
					return;
				}

				std::map<FName, Analyst3D*>& mapAnalyst3D = m_pScene->GetAnalyst3DList();
				std::map<FName, Analyst3D*>::iterator itor = mapAnalyst3D.begin();
				while (itor != mapAnalyst3D.end())
				{
					if (itor->second->GetAnalyzeMode() == View_Shed)
					{
						SpatialAnalyst3D::ViewShed* pViewShed = ((SpatialAnalyst3D::ViewShed*)(itor->second));
						if (pViewShed != nullptr)
						{
							pViewShed->UpdateUniformsForMaterial(pMD, true);
						}
					}
					else if (itor->second->GetAnalyzeMode() == Projection_Image)
					{
						SpatialAnalyst3D::ProjectionImage* pProjectionImage = ((SpatialAnalyst3D::ProjectionImage*)(itor->second));
						if (pProjectionImage != nullptr)
						{
							pProjectionImage->UpdateUniformsForMaterial(pMD, true);
						}
					}
					// TODO 其它分析功能

					itor++;
				}
			}

			int ROCacheManager::CalTextureSize(int nWidth, int nHeight, TextureType nFormat)
			{
				int nBlockSizeX = 0;
				int nBlockSizeY = 0;
				int nBlockBytes = 0;

				if (nFormat == RGB24 || nFormat == RGBA32 ||
					nFormat == BGR24 || nFormat == BGRA32)
				{
					nBlockSizeX = 1; nBlockSizeY = 1;
					if (nFormat == RGB24 || nFormat == BGR24)
					{
						nBlockBytes = 3;
					}
					else
					{
						nBlockBytes = 4;
					}
				}
				else if (nFormat == DXT1 || nFormat == DXT5)
				{
					nBlockSizeX = 4; nBlockSizeY = 4;
					nBlockBytes = 8;
					if (nFormat == DXT5)
					{
						nBlockBytes = 16;
					}
				}
				else if (nFormat == FLOAT_RGBA)
				{
					nBlockSizeX = 1; nBlockSizeY = 1;
					nBlockBytes = 16;
				}

				int nNumBlocksX = nWidth / nBlockSizeX;
				int nNumBlocksY = nHeight / nBlockSizeY;

				nNumBlocksX = (nNumBlocksX == 0 ? nNumBlocksX + 1 : nNumBlocksX);
				nNumBlocksY = (nNumBlocksY == 0 ? nNumBlocksY + 1 : nNumBlocksY);

				int nTexSize = (nNumBlocksX * nNumBlocksY * nBlockBytes);

				return nTexSize;
			}

			void ROCacheManager::CalMipMap(int nWidth, int nHeight, int nTextureSize, TextureType nFormat, std::map<int, int> & mapMipMaps, EPixelFormat pixelFormat)
			{
				int32 BlockSizeX = GPixelFormats[pixelFormat].BlockSizeX;
				int32 BlockSizeY = GPixelFormats[pixelFormat].BlockSizeY;
				int32 BlockBytes = GPixelFormats[pixelFormat].BlockBytes;
				int nMipmapLevel  = 0;
				int nTotalTexSize = 0;
				while (true)
				{
					if ((nWidth % BlockSizeX) != 0 || (nHeight % BlockSizeY) != 0)
					{
						break;
					}

					int nTexSize = CalTextureSize(nWidth , nHeight, nFormat);

					mapMipMaps[nMipmapLevel] = nTexSize;

					nTotalTexSize += nTexSize;

					if (nTotalTexSize == nTextureSize)
					{
						break;
					}

					nWidth  /= 2;
					nHeight /= 2;

					if (nWidth == 0 || nHeight == 0)
					{
						break;
					}

					nMipmapLevel++;
				}
			}

			void ROCacheManager::GetTextureType(int nFormat, TextureType &texType)
			{
				switch (nFormat)
				{
				case 0:
					texType = RGB24;
					break;
				case 1:
					texType = RGBA32;
					break;
				case 2:
					texType = DXT1;
					break;
				case 3:
					texType = DXT5;
					break;
				case 4:
					texType = FLOAT_RGBA;
					break;
				case 5:
					texType = BGRA32;
					break;
				case 6:
					texType = BGR24;
					break;
				}
			}

			std::map<FString, UTexture2D*> & ROCacheManager::GetColorTableManager()
			{
				return m_mapColorTableManager;
			}

			std::map<FString, Layer3DMaterialInfo*>& ROCacheManager::GetLayerInfo()
			{
				return m_mapLayerInfo;
			}

			std::map<FString, ObjectMaterialInfo*>& ROCacheManager::GetObjectInfo()
			{
				return m_mapObjectInfo;
			}

			std::map<FString, std::pair<UStaticMesh*, int32> >& ROCacheManager::GetStaticMeshs()
			{
				return m_mapStaticMeshs;
			}

			std::map<uint32, ASuperMap_InstancedActor*>& ROCacheManager::GetInstancedActors()
			{
				return m_mapInstancedActors;
			}

			std::map<int32, CustomRenderTargetInfo*>& ROCacheManager::GetTextureRenderTarget2D()
			{
				return m_mapTextureRenderTarget2D;
			}

			ASuperMap_CaptureSceneActor* ROCacheManager::GetAnaystActor()
			{
				if (m_pCapureSceneActor == nullptr)
				{
					m_pCapureSceneActor = m_pWorld->SpawnActor<ASuperMap_CaptureSceneActor>();
				}

				return m_pCapureSceneActor;
			}

			void ROCacheManager::AddHiddenActorForAnaystActor(AActor* pHiddenActor)
			{
				if (m_pCapureSceneActor != nullptr && pHiddenActor != nullptr)
				{
					// 获取场景采集组件
					USceneCaptureComponent2D* pSceneCaptureComponent2D = (USceneCaptureComponent2D*)m_pCapureSceneActor->GetRootComponent()->GetChildComponent(1);
					if (pSceneCaptureComponent2D == NULL)
					{
						return;
					}

					pSceneCaptureComponent2D->HiddenActors.Add(pHiddenActor);
				}
			}

			void ROCacheManager::CreateSelectionMaterial(USuperMap_MeshComponentInterface* pComponent, UMaterialInterface* pMI)
			{
				// 创建选中的
				UMaterialInterface* pMaterialInterface = LoadObject<UMaterialInterface>(nullptr, TEXT("/Supermap/Materials/Selection"));
				UMaterialInstanceDynamic* pSecondMaterial = UMaterialInstanceDynamic::Create(pMaterialInterface, nullptr);
				pSecondMaterial->AddToRoot();
				if (pMI != nullptr)
				{
					pSecondMaterial->CopyMaterialUniformParameters(pMI);
				}

				//pComponent->SetCustomSecondMaterial(pSecondMaterial);
			}
		}
	}
}