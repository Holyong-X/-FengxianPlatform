#include "Render/RenderModel3D.h"
#include "Data/GeoModel3D.h"
#include "ControlUE/RealspaceView.h"
#include "UObject/UObjectGlobals.h"
#include "Engine/World.h"
#include "Engine/StaticMesh.h"
#include "Component/SuperMap_StaticMeshActor.h"
#include "Materials/MaterialInstanceConstant.h"
#if WITH_EDITOR
#include "AssetToolsModule.h"
#include "AssetRegistry/Public/AssetRegistryModule.h"
#include "Factories/MaterialInstanceConstantFactoryNew.h"
#endif
#include "mikktspace.h"
using namespace SuperMapSDK;
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Render
		{
#if WITH_EDITOR
			static int _mikkGetNumFaces(const SMikkTSpaceContext* Context) {
				TArray<FStaticMeshBuildVertex>& vertices =
					*reinterpret_cast<TArray<FStaticMeshBuildVertex>*>(Context->m_pUserData);
				return vertices.Num() / 3;
			}

			static int
				_mikkGetNumVertsOfFace(const SMikkTSpaceContext* Context, const int FaceIdx) {
				TArray<FStaticMeshBuildVertex>& vertices =
					*reinterpret_cast<TArray<FStaticMeshBuildVertex>*>(Context->m_pUserData);
				return FaceIdx < (vertices.Num() / 3) ? 3 : 0;
			}

			static void _mikkGetPosition(
				const SMikkTSpaceContext* Context,
				float Position[3],
				const int FaceIdx,
				const int VertIdx) {
				TArray<FStaticMeshBuildVertex>& vertices =
					*reinterpret_cast<TArray<FStaticMeshBuildVertex>*>(Context->m_pUserData);
				GameVector3& position = vertices[FaceIdx * 3 + VertIdx].Position;
				Position[0] = position.X;
				Position[1] = position.Y;
				Position[2] = position.Z;
			}

			static void _mikkGetNormal(
				const SMikkTSpaceContext* Context,
				float Normal[3],
				const int FaceIdx,
				const int VertIdx) {
				TArray<FStaticMeshBuildVertex>& vertices =
					*reinterpret_cast<TArray<FStaticMeshBuildVertex>*>(Context->m_pUserData);
				GameVector3& normal = vertices[FaceIdx * 3 + VertIdx].TangentZ;
				Normal[0] = normal.X;
				Normal[1] = normal.Y;
				Normal[2] = normal.Z;
			}

			static void _mikkGetTexCoord(
				const SMikkTSpaceContext* Context,
				float UV[2],
				const int FaceIdx,
				const int VertIdx) {
				TArray<FStaticMeshBuildVertex>& vertices =
					*reinterpret_cast<TArray<FStaticMeshBuildVertex>*>(Context->m_pUserData);
				GameVector2& uv = vertices[FaceIdx * 3 + VertIdx].UVs[0];
				UV[0] = uv.X;
				UV[1] = uv.Y;
			}

			static void _mikkSetTSpaceBasic(
				const SMikkTSpaceContext* Context,
				const float Tangent[3],
				const float BitangentSign,
				const int FaceIdx,
				const int VertIdx) {
				TArray<FStaticMeshBuildVertex>& vertices =
					*reinterpret_cast<TArray<FStaticMeshBuildVertex>*>(Context->m_pUserData);
				FStaticMeshBuildVertex& vertex = vertices[FaceIdx * 3 + VertIdx];
				vertex.TangentX = GameVector3(Tangent[0], Tangent[1], Tangent[2]);
				vertex.TangentY = BitangentSign * GameVector3::CrossProduct(vertex.TangentZ, vertex.TangentX);
			}

			static int _CalTextureSize(int nWidth, int nHeight, TextureType nFormat)
			{
				int nBlockSizeX = 0;
				int nBlockSizeY = 0;
				int nBlockBytes = 0;

				if (nFormat == TextureType::RGB24 || nFormat == TextureType::RGBA32)
				{
					nBlockSizeX = 1; nBlockSizeY = 1;
					if (nFormat == TextureType::RGB24)
					{
						nBlockBytes = 3;
					}
					else
					{
						nBlockBytes = 4;
					}
				}
				else if (nFormat == TextureType::DXT1 || nFormat == TextureType::DXT5)
				{
					nBlockSizeX = 4; nBlockSizeY = 4;
					nBlockBytes = 8;
					if (nFormat == TextureType::DXT5)
					{
						nBlockBytes = 16;
					}
				}
				else if (nFormat == TextureType::FLOAT_RGBA)
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

			void RenderModel3D::Render()
			{
				if (!m_bInitial)
				{
					Open();
				}
			}

			void RenderModel3D::SetPosition(FVector vPos)
			{
				m_vPosition = vPos;
			}

			void RenderModel3D::Open()
			{
				if (m_pGeometry->GetType() != GT_GeoModel3D)
					return;

				GeoModel3D* pGeoModel3D = (GeoModel3D*)m_pGeometry;

				DataSetGeometry* pGeometrys = nullptr;

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
					pGeoModel3D->GeoModel3D_GetDataVertex(pGeometrys,
						pSkeletons, nSkeleton,
						pInstanceSkeletons, nInstanceSkeleton,
						pMaterials, nMtl,
						pTextures, nTex);
				}

				// 创建纹理
				CreateTex2D(m_mapTexture, pTextures, nTex, "");

				// 创建材质
				CreateMaterial(m_mapMaterial, pMaterials, nMtl, m_mapTexture, "");

				// 创建骨架
				CreateSkeleton(m_mapSkeleton, pSkeletons, nSkeleton);

				// 创建实例化骨架
				CreateInstanceSkeleton(m_mapInstanceSkeleton, pInstanceSkeletons, nInstanceSkeleton);
				// 创建非实例化的静态网格
				if (pGeometrys != nullptr)
				{
					AddStaticMeshActor(pGeometrys);
				}

				m_mapMaterial.clear();
				m_mapTexture.clear();
				m_mapSkeleton.clear();
				m_mapInstanceSkeleton.clear();
				m_mapInstanceMaterial.clear();
			}

			void RenderModel3D::AddStaticMeshActor(DataSetGeometry* pGeometry)
			{
				// 遍历ModelPatch
				if (pGeometry->m_nPatchCount > 0 && pGeometry->m_pDataSetPatchs != nullptr)
				{
					ASuperMap_StaticMeshActor* pActor = SuperMapSDK::UnrealEngine::ControlUE::RealspaceView::GetSingleton()->GetWorld()->SpawnActor<ASuperMap_StaticMeshActor>();
					FString strDatasetName = "";//m_pDataset->GetName();
					FString strDataSourceName = "";// m_pDataset->GetDataSource()->GetName();

					pActor->Tags.Add("SM_UDB");
					pActor->Tags.Add(FName(strDatasetName));
					pActor->m_strDataSourceName = strDataSourceName;
					pActor->m_strDatasetName = strDatasetName;
					pActor->m_strSMID = FString::FromInt(pGeometry->m_nID);

					AddStaticMeshFromModelPatch(pActor, pGeometry->m_pDataSetPatchs, pGeometry->m_nPatchCount);
				}
			}

			void RenderModel3D::AddStaticMeshFromModelPatch(ASuperMap_StaticMeshActor* pActor, DataSetPatch*** pPatchs, int32 nPatch)
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

			void RenderModel3D::AddStaticMeshFormModelGeode(ASuperMap_StaticMeshActor* pActor, DataSetGeode*** pGeodes, int32 nGeode)
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

			UStaticMesh* RenderModel3D::CreateStaticMesh(ASuperMap_StaticMeshActor* pActor, FName strSkeletonName, DataVertex* pDataVertex, DataIndice*** pDataIndice, uint32 nIndiceCount)
			{
				FString meshName = strSkeletonName.ToString();
				FStaticMeshComponentRecreateRenderStateContext RecreateRenderStateContext(FindObject<UStaticMesh>(pActor, *meshName));
				UStaticMesh* pStaticMesh = NewObject<UStaticMesh>(SuperMapSDK::UnrealEngine::ControlUE::RealspaceView::GetSingleton()->GetWorld(), FName(meshName), RF_Public | RF_Standalone);
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
							GetTriangleIndex(j, pIndice, nIndex1, nIndex2, nIndex3);

							TArray<FStaticMeshBuildVertex> arrBuildVertexs;
							arrBuildVertexs.SetNum(3);

							// 获取三角形顶点
							GameVector3 vPos1, vPos2, vPos3;
							GetTrianglePos(nIndex1, nIndex2, nIndex3, pDataVertex, vPos1, vPos2, vPos3);

							arrBuildVertexs[0].Position = vPos1;
							arrBuildVertexs[1].Position = vPos2;
							arrBuildVertexs[2].Position = vPos3;

							// 计算法线
							GameVector3 vNormal1, vNormal2, vNormal3;
							GetTriangleNormal(nIndex1, nIndex2, nIndex3, pDataVertex, arrBuildVertexs,
								vNormal1, vNormal2, vNormal3);

							// 计算切线
							ComputeTangentSpace(arrBuildVertexs);
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
							GetTriangleColor(nIndex1, nIndex2, nIndex3, pDataVertex, vColor1, vColor2, vColor3);

							// 纹理坐标
							GameVector2 vTexcoord1, vTexcoord2, vTexcoord3;
							GetTriangleTexcoord(nIndex1, nIndex2, nIndex3, pDataVertex, vTexcoord1, vTexcoord2, vTexcoord3);

							FVertexID nVtxID1 = (*MeshDescription).CreateVertex();
							FVertexID nVtxID2 = (*MeshDescription).CreateVertex();
							FVertexID nVtxID3 = (*MeshDescription).CreateVertex();

							// 设置顶点
							SetTrianglePos(VertexPositions, nVtxID1, nVtxID2, nVtxID3, vPos1, vPos2, vPos3);

							TArray<FVertexInstanceID> VertexInstanceIDs;
							VertexInstanceIDs.SetNum(3);

							VertexInstanceIDs[0] = (*MeshDescription).CreateVertexInstance(nVtxID1);
							VertexInstanceIDs[1] = (*MeshDescription).CreateVertexInstance(nVtxID2);
							VertexInstanceIDs[2] = (*MeshDescription).CreateVertexInstance(nVtxID3);

							// 设置纹理坐标
							SetTriangleTexcoord(VertexInstanceUVs, VertexInstanceIDs, 0, vTexcoord1, vTexcoord2, vTexcoord3);
							SetTriangleTexcoord(VertexInstanceUVs, VertexInstanceIDs, 1, GameVector2(0.0, 0.0), GameVector2(0.0, 0.0), GameVector2(0.0, 0.0));

							// 设置顶点颜色
							SetTriangleColor(VertexInstanceColors, VertexInstanceIDs, vColor1, vColor2, vColor3);

							// 设置法线
							SetTriangleNormal(VertexInstanceNormals, VertexInstanceIDs, GameVector3(vNormal1), GameVector3(vNormal2), GameVector3(vNormal3));

							// 设置切线
							SetTriangleTangent(VertexInstanceTangents, VertexInstanceIDs, vTangent1, vTangent2, vTangent3);

							// 设置Bionormal
							SetTriangleBinormalSign(VertexInstanceBinormalSigns, VertexInstanceIDs, fBionormal1, fBionormal2, fBionormal3);

							TArray<FEdgeID> NewEdgeIDs;
							const FTriangleID NewPolygonID = (*MeshDescription).CreateTriangle(CurrentPolygonGroupID, VertexInstanceIDs, &NewEdgeIDs);
						}
					}

					pStaticMesh->CommitMeshDescription(LodIndex);
#if !SM_FOR_UE_FIVE
					pStaticMesh->StaticMaterials = Materials;

					// Set up the SectionInfoMap to enable collision
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

			UStaticMeshComponent* RenderModel3D::CreateStaticMeshComponent(UObject* pOuter, UStaticMesh* pStaticMesh, Matrix4d matLocalToWorld)
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

			void RenderModel3D::SetComponentMatrix(UStaticMeshComponent* pStaticMeshComponent, Matrix4d matLocalToWorld)
			{
				// 设置组件矩阵
				if (pStaticMeshComponent != NULL)
				{
					FVector vOffset(SuperMapSDK::UnrealEngine::ControlUE::RealspaceView::GetSingleton()->GetWorld()->OriginLocation);

					matLocalToWorld[3][0] -= m_vPosition.Y;
					matLocalToWorld[3][1] -= m_vPosition.X;
					matLocalToWorld[3][2] -= m_vPosition.Z;

					matLocalToWorld[3][0] *= M_TO_CM;
					matLocalToWorld[3][1] *= M_TO_CM;
					matLocalToWorld[3][2] *= M_TO_CM;

					matLocalToWorld[3][0] -= vOffset.X;
					matLocalToWorld[3][1] -= vOffset.Y;
					matLocalToWorld[3][2] -= vOffset.Z;

					FMatrix mat;
					Matrix4d::ToFMatrix(matLocalToWorld, mat);

					FTransform trans;
					trans.SetFromMatrix(mat);

					pStaticMeshComponent->SetWorldTransform(trans);
				}
			}

			//== static==
			void RenderModel3D::CreateTex2D(std::map<__int64, UTexture2D*> & mapTexture, DataSetTexture*** pTextures, int32 nTex, FString strDatasetName)
			{
				// 创建纹理到本地
				for (int32 n = 0; n < nTex; n++)
				{
					DataSetTexture* pDatasetTexture = (*pTextures)[n];

					if (pDatasetTexture == nullptr)
					{
						continue;
					}
					UTexture2D* pTexture2D = nullptr;
					FString strName = FString::Printf(TEXT("%lld"), pDatasetTexture->m_strTextureName);
					FString PackageName = TEXT("/SuperMap/Texture/") + strDatasetName + TEXT("/");
					PackageName += strName;

					int32 nWidth = pDatasetTexture->m_nWidth;
					int32 nHeight = pDatasetTexture->m_nHeight;

					// 获取纹理类型
					TextureType texType = TextureType::DXT5;
					GetTextureType(pDatasetTexture->m_nTextureFormat, texType);

					// 计算Mipmap
					std::map<int, int> mapMipmaps;
					CalMipMap(nWidth, nHeight, pDatasetTexture->m_nSize, texType, mapMipmaps);

					uint8* DataBuffer = (uint8*)pDatasetTexture->m_pByte;
					for (int32 k = 0; k < nWidth * nHeight; k++)
					{
						uint8 r = DataBuffer[k * 4 + 0];
						DataBuffer[k * 4 + 0] = DataBuffer[k * 4 + 2];
						DataBuffer[k * 4 + 2] = r;
					}

					int32 nBufferSize = pDatasetTexture->m_nSize;
					UPackage* pPack = nullptr;

					UPackage* Package = CreatePackage(nullptr, *PackageName);
					Package->FullyLoad();

					pTexture2D = NewObject<UTexture2D>(
						Package,
						UTexture2D::StaticClass(),
						FName(strName),
						RF_Public | RF_Standalone | RF_MarkAsRootSet | RF_Transactional
						);

					std::map<int, int>::iterator itor = mapMipmaps.begin();
					if (itor != mapMipmaps.end())
					{
						pTexture2D->PlatformData = new FTexturePlatformData();
						pTexture2D->PlatformData->SizeX = nWidth;
						pTexture2D->PlatformData->SizeY = nHeight;
						pTexture2D->PlatformData->SetNumSlices(1);
						pTexture2D->PlatformData->PixelFormat = EPixelFormat::PF_B8G8R8A8;

						// Allocate first mipmap.
						int32 NumBlocksX = nWidth / GPixelFormats[EPixelFormat::PF_B8G8R8A8].BlockSizeX;
						int32 NumBlocksY = nHeight / GPixelFormats[EPixelFormat::PF_B8G8R8A8].BlockSizeY;
						FTexture2DMipMap* Mip = new FTexture2DMipMap();
						pTexture2D->PlatformData->Mips.Add(Mip);
						Mip->SizeX = nWidth;
						Mip->SizeY = nHeight;
						Mip->BulkData.Lock(LOCK_READ_WRITE);

						nBufferSize = NumBlocksX * NumBlocksY * GPixelFormats[EPixelFormat::PF_B8G8R8A8].BlockBytes;

						void* Data = Mip->BulkData.Realloc(nBufferSize);
						FMemory::Memcpy(Data, DataBuffer, nBufferSize);
						Mip->BulkData.Unlock();
					}
					pTexture2D->MipGenSettings = TMGS_NoMipmaps;
					pTexture2D->UpdateResource();

					pTexture2D->Source.Init(nWidth, nHeight, 1, 1, TSF_BGRA8, DataBuffer);

					pTexture2D->PostEditChange();
					pTexture2D->MarkPackageDirty();
					FAssetRegistryModule::AssetCreated(pTexture2D);
					FString PackgeFileName = FPackageName::LongPackageNameToFilename(PackageName, FPackageName::GetAssetPackageExtension());

					mapTexture[pDatasetTexture->m_strTextureName] = pTexture2D;
				}
			}

			void RenderModel3D::CreateMaterial(std::map<__int64, std::pair<FName, UMaterialInstanceConstant*> > & mapMaterial, DataSetMaterial*** pMaterials, int32 nMtl, std::map<__int64, UTexture2D*> mapTexture, FString strDatasetName)
			{
				// 创建材质
				for (int32 n = 0; n < nMtl; n++)
				{
					DataSetMaterial* pDatasetMaterial = (*pMaterials)[n];
					if (pDatasetMaterial == nullptr)
					{
						continue;
					}

					UMaterial* pMateral = nullptr;
					if (pDatasetMaterial->m_bTransparentSorting)
					{
						pMateral = LoadObject<UMaterial>(SuperMapSDK::UnrealEngine::ControlUE::RealspaceView::GetSingleton()->GetWorld(), *SM_MODELTRANSPARENT_MAT);
					}
					else
					{
						pMateral = LoadObject<UMaterial>(SuperMapSDK::UnrealEngine::ControlUE::RealspaceView::GetSingleton()->GetWorld(), *SM_MODEL_MAT);
					}

					FString strPackageName = TEXT("/SuperMap/Mtl/") + strDatasetName + TEXT("/");
					FString strMatName = FString::Printf(TEXT("%lld"), pDatasetMaterial->m_strMaterialHashName);

					UMaterialInstanceConstantFactoryNew* pFactory = NewObject<UMaterialInstanceConstantFactoryNew>();
					FAssetToolsModule& AssetToolsModule = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools");
					strPackageName = FPackageName::GetLongPackagePath(strPackageName);

					UMaterialInstanceConstant* pMIConstant = Cast<UMaterialInstanceConstant>(AssetToolsModule.Get().CreateAsset(strMatName, strPackageName, UMaterialInstanceConstant::StaticClass(), (UFactory*)pFactory, NAME_None));
					if (pMIConstant == nullptr)
					{
						return;
					}
					pMIConstant->AddToRoot();
					pMIConstant->SetParentEditorOnly(pMateral);

					std::map<__int64, UTexture2D*>::iterator itorTexture = mapTexture.find(pDatasetMaterial->m_strTextureName);
					if (itorTexture != mapTexture.end())
					{
						float sizeX = itorTexture->second->GetSizeX();
						float sizeY = itorTexture->second->GetSizeY();
						FLinearColor texonesize;
						texonesize.R = sizeX;
						texonesize.G = sizeY;

						pMIConstant->SetTextureParameterValueEditorOnly(TEXT("TextureParam"), itorTexture->second);
						pMIConstant->SetScalarParameterValueEditorOnly(TEXT("TexCount"), 1.0);
						pMIConstant->SetVectorParameterValueEditorOnly(FName("TexOneSize"), texonesize);
					}

					pMIConstant->SetVectorParameterValueEditorOnly(TEXT("MaterialColor"), FLinearColor(pDatasetMaterial->m_dR,
						pDatasetMaterial->m_dG, pDatasetMaterial->m_dB, pDatasetMaterial->m_dA));

					std::pair<FName, UMaterialInstanceConstant*> info;
					FString strMaterialName = UTF8_TO_TCHAR(pDatasetMaterial->m_strMaterialName);
					info.first = FName(strMaterialName);
					info.second = pMIConstant;

					mapMaterial[pDatasetMaterial->m_strMaterialHashName] = info;
				}
			}

			void RenderModel3D::CreateSkeleton(std::map<FName, DataSetSkeleton*> & mapSkeleton, DataSetSkeleton*** pSkeletons, int32 nSkeleton)
			{
				for (int32 n = 0; n < nSkeleton; n++)
				{
					DataSetSkeleton* pDataSetSkeleton = (*pSkeletons)[n];

					if (pDataSetSkeleton != nullptr)
					{
						FString strSkeleton = UTF8_TO_TCHAR(pDataSetSkeleton->m_strSkeletonName);
						FName strSkeletonName(strSkeleton);
						mapSkeleton[strSkeletonName] = pDataSetSkeleton;
					}
				}
			}

			void RenderModel3D::CreateInstanceSkeleton(std::map<FName, std::pair<DataSetInstanceSkeleton*, UStaticMesh*> > & mapInstanceSkeleton, DataSetInstanceSkeleton*** pInstanceSkeletons, int32 nInstanceSkeleton)
			{
				for (int32 n = 0; n < nInstanceSkeleton; n++)
				{
					DataSetInstanceSkeleton* pDataSetInstanceSkeleton = (*pInstanceSkeletons)[n];

					if (pDataSetInstanceSkeleton != nullptr && pDataSetInstanceSkeleton->m_pDataSetSkeleton != nullptr)
					{
						FString strSkeleton = UTF8_TO_TCHAR(pDataSetInstanceSkeleton->m_pDataSetSkeleton->m_strSkeletonName);
						FName strSkeletonName(strSkeleton);

						std::pair<DataSetInstanceSkeleton*, UStaticMesh*> info;
						info.first = pDataSetInstanceSkeleton;
						info.second = nullptr;

						mapInstanceSkeleton[strSkeletonName] = info;
					}
				}
			}

			void RenderModel3D::GetTextureType(int nFormat, TextureType &texType)
			{
				switch (nFormat)
				{
				case 0:
					texType = TextureType::RGB24;
					break;
				case 1:
					texType = TextureType::RGBA32;
					break;
				case 2:
					texType = TextureType::DXT1;
					break;
				case 3:
					texType = TextureType::DXT5;
					break;
				case 4:
					texType = TextureType::FLOAT_RGBA;
					break;
				}
			}

			void RenderModel3D::CalMipMap(int nWidth, int nHeight, int nTextureSize, TextureType nFormat, std::map<int, int> & mapMipMaps)
			{
				int nMipmapLevel = 0;
				int nTotalTexSize = 0;
				while (true)
				{
					int nTexSize = _CalTextureSize(nWidth, nHeight, nFormat);

					mapMipMaps[nMipmapLevel] = nTexSize;

					nTotalTexSize += nTexSize;

					if (nTotalTexSize == nTextureSize)
					{
						break;
					}

					nWidth /= 2;
					nHeight /= 2;

					if (nWidth == 0 || nHeight == 0)
					{
						break;
					}

					nMipmapLevel++;
				}
			}

			void RenderModel3D::GetTriangleIndex(uint32 nIndex, DataIndice* pIndice, uint32 &nIndex1, uint32 &nIndex2, uint32 &nIndex3)
			{
				if (pIndice->m_shortIndex != nullptr)
				{
					nIndex1 = pIndice->m_shortIndex[nIndex];
					nIndex2 = pIndice->m_shortIndex[nIndex + 1];
					nIndex3 = pIndice->m_shortIndex[nIndex + 2];
				}

				if (pIndice->m_Index != nullptr)
				{
					nIndex1 = pIndice->m_Index[nIndex];
					nIndex2 = pIndice->m_Index[nIndex + 1];
					nIndex3 = pIndice->m_Index[nIndex + 2];
				}
			}

			void RenderModel3D::GetTrianglePos(uint32 nIndex1, uint32 nIndex2, uint32 nIndex3, DataVertex* pDataVertex, GameVector3 &vPos1, GameVector3 &vPos2, GameVector3 &vPos3)
			{
				if (pDataVertex->m_Pos != nullptr)
				{
					int32 nVertexDim = pDataVertex->m_nPosDim;

					vPos1.Y = pDataVertex->m_Pos[nIndex1 * nVertexDim + 0] * M_TO_CM;
					vPos1.X = pDataVertex->m_Pos[nIndex1 * nVertexDim + 1] * M_TO_CM;
					vPos1.Z = pDataVertex->m_Pos[nIndex1 * nVertexDim + 2] * M_TO_CM;

					vPos2.Y = pDataVertex->m_Pos[nIndex2 * nVertexDim + 0] * M_TO_CM;
					vPos2.X = pDataVertex->m_Pos[nIndex2 * nVertexDim + 1] * M_TO_CM;
					vPos2.Z = pDataVertex->m_Pos[nIndex2 * nVertexDim + 2] * M_TO_CM;

					vPos3.Y = pDataVertex->m_Pos[nIndex3 * nVertexDim + 0] * M_TO_CM;
					vPos3.X = pDataVertex->m_Pos[nIndex3 * nVertexDim + 1] * M_TO_CM;
					vPos3.Z = pDataVertex->m_Pos[nIndex3 * nVertexDim + 2] * M_TO_CM;
				}
			}

			void RenderModel3D::GetTriangleNormal(uint32 nIndex1, uint32 nIndex2, uint32 nIndex3,
				DataVertex* pDataVertex, TArray<FStaticMeshBuildVertex> & arrBuildVertexs,
				GameVector3 &vNormal1, GameVector3 &vNormal2, GameVector3 &vNormal3)
			{
				if (pDataVertex->m_Normal != nullptr)
				{
					vNormal1.Y = pDataVertex->m_Normal[nIndex1 * 3 + 0];
					vNormal1.X = pDataVertex->m_Normal[nIndex1 * 3 + 1];
					vNormal1.Z = pDataVertex->m_Normal[nIndex1 * 3 + 2];

					vNormal2.Y = pDataVertex->m_Normal[nIndex2 * 3 + 0];
					vNormal2.X = pDataVertex->m_Normal[nIndex2 * 3 + 1];
					vNormal2.Z = pDataVertex->m_Normal[nIndex2 * 3 + 2];

					vNormal3.Y = pDataVertex->m_Normal[nIndex3 * 3 + 0];
					vNormal3.X = pDataVertex->m_Normal[nIndex3 * 3 + 1];
					vNormal3.Z = pDataVertex->m_Normal[nIndex3 * 3 + 2];

					arrBuildVertexs[0].TangentZ = vNormal1;
					arrBuildVertexs[1].TangentZ = vNormal2;
					arrBuildVertexs[1].TangentZ = vNormal3;
				}
				else
				{
					// 计算法线
					TArray<uint32_t> arrIndices;
					arrIndices.Add(0);
					arrIndices.Add(1);
					arrIndices.Add(2);

					ComputeFlatNormals(arrIndices, arrBuildVertexs);

					vNormal1 = arrBuildVertexs[0].TangentZ;
					vNormal2 = arrBuildVertexs[1].TangentZ;
					vNormal3 = arrBuildVertexs[1].TangentZ;
				}
			}

			void RenderModel3D::GetTriangleColor(uint32 nIndex1, uint32 nIndex2, uint32 nIndex3, DataVertex* pDataVertex, GameVector4 &vColor1, GameVector4&vColor2, GameVector4&vColor3)
			{
				if (pDataVertex->m_PosColor != nullptr)
				{
					uint32 nColor1 = pDataVertex->m_PosColor[nIndex1];
					uint32 nColor2 = pDataVertex->m_PosColor[nIndex2];
					uint32 nColor3 = pDataVertex->m_PosColor[nIndex3];
					_IDRGBA(nColor1, vColor1.X, vColor1.Y, vColor1.Z, vColor1.W);
					_IDRGBA(nColor2, vColor2.X, vColor2.Y, vColor1.Z, vColor2.W);
					_IDRGBA(nColor3, vColor3.X, vColor3.Y, vColor1.Z, vColor3.W);
				}
			}

			void RenderModel3D::GetTriangleTexcoord(uint32 nIndex1, uint32 nIndex2, uint32 nIndex3, DataVertex* pDataVertex, GameVector2 &vTexcoord1, GameVector2&vTexcoord2, GameVector2&vTexcoord3)
			{
				if (pDataVertex->m_TexCoord != nullptr)
				{
					int32 nTexCoordDim = pDataVertex->m_nTexCoordDim;

					vTexcoord1.X = pDataVertex->m_TexCoord[nTexCoordDim * nIndex1 + 0];
					vTexcoord1.Y = pDataVertex->m_TexCoord[nTexCoordDim * nIndex1 + 1];

					vTexcoord2.X = pDataVertex->m_TexCoord[nTexCoordDim * nIndex2 + 0];
					vTexcoord2.Y = pDataVertex->m_TexCoord[nTexCoordDim * nIndex2 + 1];

					vTexcoord3.X = pDataVertex->m_TexCoord[nTexCoordDim * nIndex3 + 0];
					vTexcoord3.Y = pDataVertex->m_TexCoord[nTexCoordDim * nIndex3 + 1];
				}
			}

			void RenderModel3D::SetTrianglePos(TVertexAttributesRef<GameVector3> & VertexPositions, FVertexID nVtxID1, FVertexID nVtxID2, FVertexID nVtxID3, GameVector3 vPos1, GameVector3 vPos2, GameVector3 vPos3)
			{
				VertexPositions[nVtxID1] = vPos1;
				VertexPositions[nVtxID2] = vPos2;
				VertexPositions[nVtxID3] = vPos3;
			}

			void RenderModel3D::SetTriangleTexcoord(TVertexInstanceAttributesRef<GameVector2> & VertexInstanceUVs, TArray<FVertexInstanceID> & VertexInstanceIDs, int32 nTexcoordIndex, GameVector2 vTexcoord1, GameVector2 vTexcoord2, GameVector2 vTexcoord3)
			{
				VertexInstanceUVs.Set(VertexInstanceIDs[0], nTexcoordIndex, vTexcoord1);
				VertexInstanceUVs.Set(VertexInstanceIDs[1], nTexcoordIndex, vTexcoord2);
				VertexInstanceUVs.Set(VertexInstanceIDs[2], nTexcoordIndex, vTexcoord3);
			}

			void RenderModel3D::SetTriangleColor(TVertexInstanceAttributesRef<GameVector4> VertexInstanceColors, TArray<FVertexInstanceID> & VertexInstanceIDs, GameVector4 vColor1, GameVector4 vColor2, GameVector4 vColor3)
			{
				VertexInstanceColors.Set(VertexInstanceIDs[0], vColor1);
				VertexInstanceColors.Set(VertexInstanceIDs[1], vColor2);
				VertexInstanceColors.Set(VertexInstanceIDs[2], vColor3);
			}

			void RenderModel3D::SetTriangleNormal(TVertexInstanceAttributesRef<GameVector3> VertexInstanceNormals, TArray<FVertexInstanceID> & VertexInstanceIDs, GameVector3 vNormal1, GameVector3 vNormal2, GameVector3 vNormal3)
			{
				VertexInstanceNormals.Set(VertexInstanceIDs[0], vNormal1);
				VertexInstanceNormals.Set(VertexInstanceIDs[1], vNormal2);
				VertexInstanceNormals.Set(VertexInstanceIDs[2], vNormal3);
			}
		
			void RenderModel3D::SetTriangleTangent(TVertexInstanceAttributesRef<GameVector3> & VertexInstanceTangents, TArray<FVertexInstanceID> & VertexInstanceIDs, GameVector3 vTangent1, GameVector3 vTangent2, GameVector3 vTangent3)
			{
				VertexInstanceTangents.Set(VertexInstanceIDs[0], vTangent1);
				VertexInstanceTangents.Set(VertexInstanceIDs[1], vTangent2);
				VertexInstanceTangents.Set(VertexInstanceIDs[2], vTangent3);
			}

			void RenderModel3D::SetTriangleBinormalSign(TVertexInstanceAttributesRef<float> & VertexInstanceBinormalSigns, TArray<FVertexInstanceID> & VertexInstanceIDs, float fBinormalSign1, float fBinormalSign2, float fBinormalSign3)
			{
				VertexInstanceBinormalSigns.Set(VertexInstanceIDs[0], fBinormalSign1);
				VertexInstanceBinormalSigns.Set(VertexInstanceIDs[1], fBinormalSign2);
				VertexInstanceBinormalSigns.Set(VertexInstanceIDs[2], fBinormalSign3);
			}
		
			void RenderModel3D::ComputeTangentSpace(TArray<FStaticMeshBuildVertex>& vertices) {
				SMikkTSpaceInterface MikkTInterface;
				MikkTInterface.m_getNormal = _mikkGetNormal;
				MikkTInterface.m_getNumFaces = _mikkGetNumFaces;
				MikkTInterface.m_getNumVerticesOfFace = _mikkGetNumVertsOfFace;
				MikkTInterface.m_getPosition = _mikkGetPosition;
				MikkTInterface.m_getTexCoord = _mikkGetTexCoord;
				MikkTInterface.m_setTSpaceBasic = _mikkSetTSpaceBasic;
				MikkTInterface.m_setTSpace = nullptr;

				SMikkTSpaceContext MikkTContext;
				MikkTContext.m_pInterface = &MikkTInterface;
				MikkTContext.m_pUserData = (void*)(&vertices);
				MikkTContext.m_bIgnoreDegenerates = false;
				genTangSpaceDefault(&MikkTContext);
			}

			void RenderModel3D::ComputeFlatNormals(
				const TArray<uint32_t>& indices,
				TArray<FStaticMeshBuildVertex>& vertices) {
				// Compute flat normals
				for (int64_t i = 0; i < indices.Num(); i += 3) {
					FStaticMeshBuildVertex& v0 = vertices[i];
					FStaticMeshBuildVertex& v1 = vertices[i + 1];
					FStaticMeshBuildVertex& v2 = vertices[i + 2];

					GameVector3 v01 = v1.Position - v0.Position;
					GameVector3 v02 = v2.Position - v0.Position;
					GameVector3 normal = GameVector3::CrossProduct(v01, v02);

					v0.TangentZ = normal.GetSafeNormal();
					v1.TangentZ = v0.TangentZ;
					v2.TangentZ = v0.TangentZ;
				}
			}
#endif
		}
	}
}