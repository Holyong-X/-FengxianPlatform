#include "Core/Scene.h"
#include "Core/Layer3Ds.h"
#include "Core/TerrainLayers.h"
#include "Base3D/CommonDefine.h"
#include "Data/Vector3d.h"
#include "Core/Georeference.h"
#include "Core/TerrainLayer.h"
#include "Core/Layer3D.h"
#include "Core/TrackingLayer.h"
#include "Graphics3D/GameComponent.h"
#include "Data/Vector2d.h"
#include "Graphics3D/GameMaterialManager.h"
#include "ControlUE/CameraControl.h"
#include "Core/FlyManager.h"
#include "Algorithm3D/MathEngine.h"
using namespace SuperMapSDK::UnrealEngine::Algorithm3D;
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			Scene::Scene()
			{
				m_pLayer3Ds      = new Layer3Ds(this);
				m_pTerrainLayers = new TerrainLayers(this);
				m_eSceneType     = Globe;
				m_vtTerrainPos   = FVector(0.0f, 0.0f, 0.0f);
				m_pWorld         = nullptr;
				m_pCameraControl = nullptr;
				m_pUGScene       = nullptr;
				m_pTrackingLayer = nullptr;
				m_pQuery3D       = nullptr;
				m_pFlyManager    = nullptr;
				m_pCameraState = nullptr;
				m_eViewportMode = SuperMapSDK::UnrealEngine::Core::None;
				m_pGlobalImage = nullptr;
			}

			Scene::~Scene()
			{
				if (m_pLayer3Ds != nullptr)
				{
					m_pLayer3Ds->Clear();
					delete m_pLayer3Ds;
					m_pLayer3Ds = nullptr;
				}

				if (m_pTerrainLayers != nullptr)
				{
					delete m_pTerrainLayers;
					m_pTerrainLayers = nullptr;
				}

				if (m_pUGScene != nullptr)
				{
					m_pUGScene = nullptr;
				}

				if (m_pTrackingLayer != nullptr)
				{
					delete m_pTrackingLayer;
					m_pTrackingLayer = nullptr;
				}

				if (m_pFlyManager != nullptr)
				{
					delete m_pFlyManager;
					m_pFlyManager = nullptr;
				}

				if (m_pCameraState != nullptr)
				{
					delete m_pCameraState;
					m_pCameraState = nullptr;
				}

				if (m_pGlobalImage != nullptr)
				{
					delete m_pGlobalImage;
					m_pGlobalImage = nullptr;
				}

				if (m_pQuery3D != nullptr)
				{
					delete m_pQuery3D;
					m_pQuery3D = nullptr;
				}
				m_pWorld = nullptr;
				m_pCameraControl = nullptr;
				m_eViewportMode = SuperMapSDK::UnrealEngine::Core::None;
			}

			GlobalImage* Scene::GetGlobalImage()
			{
				if (m_pGlobalImage == nullptr)
				{
					void* pUGCGlobalImage = nullptr;
					_Scene_GetGlobalImage(m_pUGScene,pUGCGlobalImage);
					m_pGlobalImage = new GlobalImage(pUGCGlobalImage);
				}

				return m_pGlobalImage;
			}

			void Scene::SetHandler(void* pScene)
			{
				m_pUGScene = pScene;
			}

			void* Scene::GetHandler()
			{
				return m_pUGScene;
			}

			void Scene::Clear()
			{
				if (m_pLayer3Ds != nullptr)
				{
					m_pLayer3Ds->Clear();
				}

				if (m_pTerrainLayers != nullptr)
				{
					m_pTerrainLayers->ClearSlopeSetting();
					m_pTerrainLayers->Clear();
				}

				if (m_pTrackingLayer != nullptr)
				{
					delete m_pTrackingLayer;
					m_pTrackingLayer = nullptr;
				}

				std::map<FName, Analyst3D*>::iterator itor = m_mapAnalyst.begin();
				while (itor != m_mapAnalyst.end())
				{
					Analyst3D* pAnalyst3D = itor->second;
					if (pAnalyst3D != nullptr)
					{
						delete pAnalyst3D;
						pAnalyst3D = nullptr;
					}
					itor++;
				}

				m_mapAnalyst.clear();

				if (m_pFlyManager != nullptr)
				{
					delete m_pFlyManager;
					m_pFlyManager = nullptr;
				}
				if (m_pCameraState != nullptr)
				{
					delete m_pCameraState;
					m_pCameraState = nullptr;
				}
				if (m_pGlobalImage != nullptr)
				{
					delete m_pGlobalImage;
					m_pGlobalImage = nullptr;
				}
				m_eViewportMode = SuperMapSDK::UnrealEngine::Core::None;
			}

			Layer3Ds* Scene::GetLayer3Ds()
			{
				return m_pLayer3Ds;
			}

			TerrainLayers* Scene::GetTerrainLayers()
			{
				return m_pTerrainLayers;
			}

			TrackingLayer* Scene::GetTrackingLayer()
			{
				if (m_pTrackingLayer == nullptr)
				{
					m_pTrackingLayer = new TrackingLayer();
				}
				return m_pTrackingLayer;
			}

			void Scene::SetSceneType(SceneType eSceneType)
			{
				m_eSceneType = eSceneType;
			}

			SceneType Scene::GetSceneType()
			{
				return m_eSceneType;
			}

			void Scene::SetCamera(Gamefloat* matView, Gamefloat fNearDist, Gamefloat fFarDist, Gamefloat fFov, Gamefloat fAspect)
			{
				if (_SetCamera != nullptr)
				{
					_SetCamera(matView, fNearDist, fFarDist, fFov, fAspect);
				}
			}

			void Scene::SetCameraFov(Gamedouble dFov)
			{
				m_pCameraControl->SetFov(dFov);
			}

			Gamedouble Scene::GetCameraFov()
			{
				return m_pCameraControl->GetFov();
			}

			void Scene::EnsureVisible(Rectangle2D rect2D, Gamedouble dHeight)
			{
				FVector vPostion;
				Vector2d fVector2D = rect2D.Center();
				vPostion.X = fVector2D.X;
				vPostion.Y = fVector2D.Y;
				vPostion.Z = fmax(fabs(rect2D.Right - rect2D.Left), fabs(rect2D.Top - rect2D.Bottom));

				if (ControlUE::CameraControl::m_eSceneType == ControlUE::UGC_PLANE)
				{
					vPostion.Z = dHeight;
					FVector vCameraLocal = vPostion * M_TO_CM;
					Swap(vCameraLocal.X, vCameraLocal.Y);
					m_pCameraControl->FlyToBounds(vCameraLocal, FVector());
				}
				if (ControlUE::CameraControl::m_eSceneType == ControlUE::UGC_EARTH ||
					ControlUE::CameraControl::m_eSceneType == ControlUE::UGC_EARTH_ELLIPSOID_WGS84)
				{
					float dSize = vPostion.Z;

					dSize /= 2;
					if (dSize > (90 - FMath::RadiansToDegrees(PI / 8)))
					{
						dSize = (90 - FMath::RadiansToDegrees(PI / 8));
					}
					float dAltitude = sin(FMath::DegreesToRadians(dSize)) * 6378137.0;
					if (tan(PI / 8) != 0)
					{
						dAltitude /= tan(PI / 8);
					}
					dAltitude += cos(FMath::DegreesToRadians(dSize)) * 6378137.0;
					dAltitude = dAltitude - 6378137.0;

					FVector vLonLat = FVector(vPostion.Y, vPostion.X, 0.0);
					Data::Vector3d vCameraLocal3d;
					_SphericalToCartesian(vPostion.X, vPostion.Y, dAltitude, vCameraLocal3d.X, vCameraLocal3d.Y, vCameraLocal3d.Z);
					FVector vCameraLocal = vCameraLocal3d.ToFVector();
					vCameraLocal = vCameraLocal * 100;

					m_pCameraControl->FlyToBounds(vCameraLocal, vLonLat);

				}
			}

			Vector3d Scene::PixelToCartesian(Vector3d vMouse)
			{
				Vector3d vPos = m_pCameraControl->GetLocalWorldPosition(vMouse.X, vMouse.Y);
				vPos -= Vector3d(m_pCameraControl->m_vecWorldOrigin);
				return vPos;
			}

			std::map<FName, Analyst3D*>& Scene::GetAnalyst3DList()
			{
				return m_mapAnalyst;
			}

			void Scene::Render()
			{
				std::map<FName, Analyst3D*>::iterator itor = m_mapAnalyst.begin();
				while (itor != m_mapAnalyst.end())
				{
					Analyst3D* pAnalyst3D = itor->second;
					if (pAnalyst3D != nullptr)
					{
						pAnalyst3D->Render();
					}

					itor++;
				}

				int32 nLayer3D = m_pLayer3Ds->Count();
				for (int32 n = 0; n < nLayer3D; n++)
				{
					m_pLayer3Ds->GetAt(n)->Render(m_pWorld);
				}

				if (m_pTerrainLayers->Count() > 0)
				{
					m_pTerrainLayers->Render();
				}
			}

			void Scene::SetCameraControl(ControlUE::CameraControl* pCameraControl)
			{
				m_pCameraControl = pCameraControl;
			}

			CameraControl* Scene::GetCameraControl()
			{
				return m_pCameraControl;
			}

			void Scene::SetWorld(UWorld* pWorld)
			{
				m_pWorld = pWorld;
			}

			UWorld* Scene::GetWorld()
			{
				return m_pWorld;
			}

			Query3D* Scene::GetQuery3D()
			{
				if (m_pQuery3D == nullptr)
				{
					m_pQuery3D = new Query3D();
				}
				return m_pQuery3D;
			}

			Vector3d Scene::PixelToGlobe(Vector3d vMouse, PixelToGlobeMode mode)
			{
				Gamebool bUseDepth = true;
				if (mode == PixelToGlobeMode::Sphere)
				{
					bUseDepth = false;
				}

				Vector3d vLocal = m_pCameraControl->GetLocalWorldPosition(vMouse.X, vMouse.Y, bUseDepth);

				if (m_eSceneType == Flat)
				{
					vLocal *= CM_TO_M;
					vLocal += FVector(m_vtTerrainPos.Y, m_vtTerrainPos.X, m_vtTerrainPos.Z);
					vLocal *= M_TO_CM;

					double vPosX = vLocal.X;
					double vPosY = vLocal.Y;

					vLocal.X = vPosY;
					vLocal.Y = vPosX;

					return vLocal;
				}
				else if (m_eSceneType == Globe || m_eSceneType == Ellipsoid_WGS84)
				{
					//（UGC和UE坐标，X轴和Y轴是反的）
					vLocal += Vector3d(MathEngine::m_vWorldOffset);
					FRotator fRotator;
					FTransform fTransform = FTransform(fRotator, vLocal.ToFVector());

					Matrix4d matRot(fTransform.ToMatrixWithScale());
					matRot = matRot * Georeference::GetECEFtoGeoreference().Invert();

					FMatrix matfloatRot;
					Matrix4d::ToFMatrix(matRot, matfloatRot);

					fTransform.SetFromMatrix(matfloatRot);
					vLocal = fTransform.GetLocation();

					vLocal *= CM_TO_M;

					// 地理坐标
					Vector3d vLonLat3d;
					_CartesianToSphericalD(vLocal.Y, vLocal.X, vLocal.Z, vLonLat3d.X, vLonLat3d.Y, vLonLat3d.Z);

					return vLonLat3d;
				}

				return Vector3d(0.0, 0.0, 0.0);
			}

			FTransform Scene::LongitudeLatitudeToUE(FVector vLonLat, Gamebool bIgnoreWorldOrigin)
			{
				FTransform location;

				if (m_eSceneType == SceneType::Globe || m_eSceneType == Ellipsoid_WGS84)
				{
					double dQuaternionX, dQuaternionY, dQuaternionZ, dQuaternionW;
					double lon = vLonLat.X;
					double lat = vLonLat.Y;
					double altitude = vLonLat.Z;

					_LongitudeLatitudeToGameEngine(lon, lat, altitude, dQuaternionX, dQuaternionY, dQuaternionZ, dQuaternionW);

					FQuat quaternion(dQuaternionX, dQuaternionY, dQuaternionZ, dQuaternionW);

					FRotator rQuaternion = quaternion.Rotator();

					FVector vTranslation = FVector((float)lat * M_TO_CM, (float)lon * M_TO_CM, (float)altitude * M_TO_CM);

					location = FTransform(rQuaternion, vTranslation);

					Matrix4d matRot(location.ToMatrixWithScale());
					matRot = matRot * Georeference::GetECEFtoGeoreference();

					FMatrix matfRot;
					Matrix4d::ToFMatrix(matRot, matfRot);

					location.SetFromMatrix(matfRot);
					FVector vLocation = location.GetLocation();
					vLocation -= MathEngine::m_vWorldOffset;
					if (!bIgnoreWorldOrigin)
					{
						vLocation -= FVector(m_pCameraControl->m_vecWorldOrigin);
					}
					location.SetLocation(vLocation);
				}
				return location;
			}

			void Scene::SetCreateSkirt(Gamebool bCreatesSkirt)
			{
				_SetCreateSkirt(bCreatesSkirt);
			}

			Gamebool Scene::GetCreateSkirt()
			{
				Gamebool bCreateSkirt = _GetCreateSkirt();
				return bCreateSkirt;
			}

			void Scene::SetSkirtHeight(Gamefloat fHeight)
			{
				_SetSkirtHeight(fHeight);
			}

			Gamebool Scene::ToXML(FString strFileAdress)
			{
				const TCHAR* cFileAdress = *strFileAdress;
				ANSICHAR* ccFileAdress = TCHAR_TO_UTF8(cFileAdress);

				_ToXML(ccFileAdress);
				return true;
			}

			Gamebool Scene::FromXML(FString strFileAdress)
			{
				const TCHAR* cFileAdress = *strFileAdress;
				ANSICHAR* ccFileAdress = TCHAR_TO_UTF8(cFileAdress);

				Gamebool result = _Scene_FromXML(m_pUGScene, ccFileAdress);

				if (result)
				{
					GetLayer3DsFromXML();
					GetTerrainLayersFromXML();
				}
				return result;
			}

			void Scene::GetLayer3DsFromXML()
			{
				void** pUGLayers = nullptr;
				Gameint nCount;
				_Scene_GetLayer3Ds(m_pUGScene, pUGLayers, nCount);
				for (Gameint i = 0; i < nCount; i++)
				{
					void* pLayer = pUGLayers[i];
					Gameint nID = _Layer3D_GetID(pLayer);
					Gameint nType = _Layer3D_GetType(pLayer);
					char* layerName;
					_Layer3D_GetName(pLayer, layerName);
					FString name = UTF8_TO_TCHAR(layerName);
					Layer3D* layer3D = m_pLayer3Ds->CreateLayer(FName(name), Layer3DType(nType), pLayer);
					layer3D->SetLayerID(nID);
					m_pLayer3Ds->InternalInsert(m_pLayer3Ds->Count(), layer3D);
				}
			}

			void Scene::GetTerrainLayersFromXML()
			{
				void** pUGLayers = nullptr;
				Gameint nCount;
				_Scene_GetTerrainLayers(m_pUGScene, pUGLayers, nCount);
				for (Gameint i = 0; i < nCount; i++)
				{
					char* terrainName;
					_TerrainLayer_GetName(terrainName);
					FString name = UTF8_TO_TCHAR(terrainName);
					TerrainLayer* pTerrainLayer = new TerrainLayer(FName(name));
					TArray<TerrainLayer*>& terrain3Ds = m_pTerrainLayers->GetTerrainLayer3Ds();
					terrain3Ds.Add(pTerrainLayer);
				}
			}

			void Scene::SetShowInvalidation(Gamebool bShow)
			{
				_Scene_SetShowInvalidation(bShow);
			}

			SelectedInfo Scene::GetSelectedInfo()
			{
				FVector vMouse;
				m_pWorld->GetFirstPlayerController()->GetMousePosition(vMouse.X, vMouse.Y);

				FHitResult hitResult;
				m_pCameraControl->LineTrace(vMouse.X, vMouse.Y, hitResult);

				SelectedInfo materialInfo;
				materialInfo.m_pMatInstanceDynamic = nullptr;
				UPrimitiveComponent* pComponent = hitResult.GetComponent();

				if (pComponent != nullptr)
				{
					AActor* pActor = pComponent->GetOwner();
					if (pActor->ActorHasTag(TEXT("SUPERMAP")))
					{
						USuperMap_MeshComponent* pMeshComponent = (USuperMap_MeshComponent*)hitResult.GetComponent();

						TArray<UMaterialInterface*> arrCustomMaterials;
						pMeshComponent->GetAllCustomMaterials(arrCustomMaterials);
						for (int materialIndex = 0; materialIndex < arrCustomMaterials.Num(); materialIndex++)
						{
							UMaterialInterface* pMat = arrCustomMaterials[materialIndex];
							if (pMat != nullptr)
							{
								UMaterialInstanceDynamic* pMatDynamic = (UMaterialInstanceDynamic*)pMat;
								pMatDynamic->SetVectorParameterValue(TEXT("SubSelectedColor"), FLinearColor(1, 0, 1, 1));
								materialInfo.m_strMaterialName = pMeshComponent->GetRealMaterialName();
								materialInfo.m_strLayerName = pMeshComponent->GetLayerName();
								materialInfo.m_pMatInstanceDynamic = pMatDynamic;
							}
						}
					}
				}

				return materialInfo;
			}

			void Scene::AddNativeGameComponent(GameComponent* pGameComponent)
			{
				if (pGameComponent == nullptr)
				{
					return;
				}

				switch (pGameComponent->GetDataType())
				{
					case DataType::Globe:
						m_pTerrainLayers->AddNativeGameComponent(pGameComponent);
						break;
					default:
					{
						Layer3D* layer = FindLayerByNodeName(pGameComponent->GetParentNodeName());
						if (layer != nullptr)
						{
							layer->AddNativeGameComponent(pGameComponent);
						}
					}
				}
			}

			void Scene::RemoveNativeGameComponent(GameComponent* pGameComponent)
			{
				if (pGameComponent == nullptr)
				{
					return;
				}

				switch (pGameComponent->GetDataType())
				{
				case DataType::Globe:
					m_pTerrainLayers->RemoveNativeGameComponent(pGameComponent);
					break;
				default:
				{
					Layer3D* layer = FindLayerByNodeName(pGameComponent->GetParentNodeName());
					if (layer != nullptr)
					{
						layer->RemoveNativeGameComponent(pGameComponent);
					}
				}
				}
			}

			Layer3D* Scene::FindLayerByNodeName(Gamelong nodeName)
			{
				Layer3D* layer = m_pLayer3Ds->FindLayerByNodeName(nodeName);
				if (layer != nullptr)
				{
					return layer;
				}
				if (m_pTrackingLayer != nullptr && m_pTrackingLayer->NodeNameHashCode() == nodeName)
				{
					return m_pTrackingLayer;
				}
				return nullptr;
			}

			void Scene::ToJson(FString strPath)
			{
				JsonFile* jsonArrLayerFile = new JsonFile(JsonValueType::arrayValue);

				for (int i = 0; i < m_pLayer3Ds->Count(); i++)
				{
					jsonArrLayerFile->Add(m_pLayer3Ds->GetAt(i)->LayerToJson());
				}			

				JsonFile* jsonSceneFile = new JsonFile(JsonValueType::objectValue);
				jsonSceneFile->Add("Layers", jsonArrLayerFile);

				// 场景数组 目前只有一个
				JsonFile* jsonSceneSFile = new JsonFile(JsonValueType::arrayValue);
				jsonSceneSFile->Add(jsonSceneFile);

				// 数据源
				JsonFile* jsonDatasourceSetFile = new JsonFile(JsonValueType::arrayValue);
				JsonFile* jsonServerFile = new JsonFile(JsonValueType::objectValue);

				jsonServerFile->Add("Server", FString(""));
				jsonDatasourceSetFile->Add(jsonServerFile);

				JsonFile* rootJsonFile = new JsonFile(JsonValueType::objectValue);
				rootJsonFile->Add("DataSources", jsonDatasourceSetFile);
				rootJsonFile->Add("Scenes", jsonSceneSFile);
				rootJsonFile->Add("Version", FString("1.0"));
				rootJsonFile->SaveToStdFile(strPath);

				delete jsonArrLayerFile;
				jsonArrLayerFile = nullptr;
				delete jsonSceneFile;
				jsonSceneFile = nullptr;
				delete jsonSceneSFile;
				jsonSceneSFile = nullptr;
				delete jsonDatasourceSetFile;
				jsonDatasourceSetFile = nullptr;
				delete jsonServerFile;
				jsonServerFile = nullptr;
				delete rootJsonFile;
				rootJsonFile = nullptr;
			}

			void Scene::SetMultiViewportMode(MultiViewportMode mode)
			{
				m_eViewportMode = mode;
				switch (m_eViewportMode)
				{
				case SuperMapSDK::UnrealEngine::Core::None:
					GameMaterialManager::GetSingleton()->SetIsCreateMaterialInViewport(false);
					for (int i = 0; i < m_pLayer3Ds->Count(); i++)
					{
						Layer3D* pLayer = m_pLayer3Ds->GetAt(i);
						pLayer->SetViewportEnabled(false);
					}
					break;
				case SuperMapSDK::UnrealEngine::Core::Horizontal:
					GameMaterialManager::GetSingleton()->SetIsCreateMaterialInViewport(true);
					for (int i = 0; i < m_pLayer3Ds->Count(); i++)
					{
						Layer3D* pLayer = m_pLayer3Ds->GetAt(i);
						pLayer->SetViewportEnabled(true);
					}
					break;
				default:
					break;
				}
				Updata();
			}

			MultiViewportMode Scene::GetMultiViewportMode()
			{
				return m_eViewportMode;
			}

			FlyManager* Scene::GetFlyManager()
			{
				if (m_pFlyManager == nullptr)
				{
					m_pFlyManager = new FlyManager(this);
				}
				return m_pFlyManager;
			}

			void Scene::Fly(CameraState* pCameraState, Gameint milliseconds)
			{
				InitializeFlyCallbackHandle();
				if (_Scene_FlyToCamera)
				{
					_Scene_FlyToCamera(m_pUGScene, pCameraState->GetUGCameraHandler(), milliseconds);
					m_pCameraControl->SetEditMode(CMEditMode::ROAM);
				}
			}

			CameraState* Scene::GetCameraState()
			{
				if (m_pCameraState == nullptr)
				{
					void* pCamera = nullptr;
					_Scene_GetCamera(m_pUGScene, pCamera);
					m_pCameraState = new CameraState(pCamera);
				}
				return m_pCameraState;
			}

			void Scene::SetTerrainExaggeration(Gamedouble dValue)
			{
				if (_Scene_SetTerrainExaggeration)
				{
					_Scene_SetTerrainExaggeration(m_pUGScene, dValue);
				}
			}

			Gamedouble Scene::GetTerrainExaggeration()
			{
				Gamedouble dResult = 0;
				if (_Scene_GetTerrainExaggeration)
				{
					_Scene_GetTerrainExaggeration(m_pUGScene, dResult);
				}
				return dResult;
			}

			void Scene::InitializeFlyCallbackHandle()
			{
				FlownFunc flown = OnFlown;
				_Scene_SetEndFlyFunc(m_pUGScene,this,(void*)flown);
			}

			void OnFlown(void* pScene)
			{
				Scene* pUEScene = (Scene*)pScene;
				CameraControl* pCameraControl = pUEScene->GetCameraControl();
				if (pCameraControl == nullptr)
				{
					return;
				}
				pUEScene->GetCameraState()->SyncMainCam(pCameraControl);
				pCameraControl->SetEditMode(CMEditMode::NORMAL);
			}

			void Scene::SetStereoMode(StereoMode mode)
			{
				_Scene_SetStereoMode(m_pUGScene, (int)mode);
			}

			StereoMode Scene::GetStereoMode()
			{
				return (StereoMode)_Scene_GetStereoMode(m_pUGScene);
			}

			void Scene::Updata()
			{
				Gameint nCount = m_pLayer3Ds ->Count();
				for (Gameint i = 0; i < nCount; i++)
				{
					Layer3D* pLayer = m_pLayer3Ds->GetAt(i);
					pLayer->UpdateData();
				}
				_Scene_Updata(m_pUGScene);
			}

			void Scene::GlobalRefreshRaster(Rectangle2D rec)
			{
				_Scene_GlobalRefreshRaster(m_pUGScene, rec.Left, rec.Top, rec.Right, rec.Bottom);
			}
		}
	}
}

#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif