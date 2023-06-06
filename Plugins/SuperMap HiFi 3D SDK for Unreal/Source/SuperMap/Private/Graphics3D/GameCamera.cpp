#include "Graphics3D/GameCamera.h"
#include "Algorithm3D/MathEngine.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/PlayerController.h"
#include "Graphics3D/GameObjectManager.h"
#include "Component/SuperMap_MeshComponentInterface.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Base3D/StatsGroupDefine.h"
#include "Core/Georeference.h"
#include "Core/ROCacheManager.h"
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif
using namespace SuperMapSDK::UnrealEngine::Algorithm3D;
using namespace SuperMapSDK::UnrealEngine::Core;
namespace SuperMapSDK
{
	void SetViewMatrix(Gamevoid* pCameraHandle, Gamedouble* pViewMatrix)
	{
		STATS_SM_SETVIEWMATRIX

		GameCamera* pGameCamera = (GameCamera*)pCameraHandle;
		if (pGameCamera == nullptr)
		{
			return;
		}
		pGameCamera->SetViewMatrix(pViewMatrix);
	}

	void SetMainCameraViewMatrix(Gamedouble* pViewMatrix)
	{
		STATS_SM_SETMAINCAMERAVIEWMATRIX

		GameCameraManager::GetSingleton()->SetMainCameraViewMatrix(pViewMatrix);
	}

	void SetCameraParam(Gamevoid* pCameraHandle, Gamebool bOrthographic, Gamedouble& dFov, Gamedouble& dAspect, Gamedouble& dNear, Gamedouble& dFar, Gamedouble*& pProjMatrix)
	{
		STATS_SM_SETCAMERAPARAM

		GameCamera* pGameCamera = (GameCamera*)pCameraHandle;
		if (pGameCamera == nullptr)
		{
			return;
		}
		pGameCamera->SetCameraParam(bOrthographic, dFov, dAspect, dNear, dFar, pProjMatrix);
	}

	void SetProjMatrix(Gamevoid* pCameraHandle, Gamedouble* pProjMatrix)
	{
		STATS_SM_SETPROJMATRIX

		// TO DO
	}

	void SetUGCPosition(Gamevoid* pCameraHandle, Gamedouble dX, Gamedouble dY, Gamedouble dZ)
	{
		STATS_SM_SETUGCPOSITION

		GameCamera* pGameCamera = (GameCamera*)pCameraHandle;
		if (pGameCamera == nullptr)
		{
			return;
		}
		pGameCamera->SetUGCPosition(dX, dY, dZ);
	}

	void SetLookAt(Gamevoid* pCameraHandle,
		Gamedouble dTargetX, Gamedouble dTargetY, Gamedouble dTargetZ,
		Gamedouble dUpX, Gamedouble dUpY, Gamedouble dUpZ)
	{
		STATS_SM_SETLOOKAT

		GameCamera* pGameCamera = (GameCamera*)pCameraHandle;
		if (pGameCamera == nullptr)
		{
			return;
		}
		pGameCamera->SetLookAt(dTargetX, dTargetY, dTargetZ, dUpX, dUpY, dUpZ);
	}

	void SetViewportRect(Gamevoid* pCameraHandle,
		Gamedouble dX, Gamedouble dY, Gamedouble dWidth, Gamedouble dHeight)
	{
		STATS_SM_SETVIEWPORTRECT

		GameCamera* pGameCamera = (GameCamera*)pCameraHandle;
		if (pGameCamera == nullptr)
		{
			return;
		}
		pGameCamera->SetViewportRect(dX, dY, dWidth, dHeight);
	}

	void SetOrthoWindow(Gamevoid* pCameraHandle, Gamedouble dWidth, Gamedouble dHeight)
	{
		STATS_SM_SETORTHOWINDOW

		GameCamera* pGameCamera = (GameCamera*)pCameraHandle;
		if (pGameCamera == nullptr)
		{
			return;
		}
		pGameCamera->SetOrthoWindow(dWidth,dHeight);

	}
	////////////////////////////////////////////////////////////////////////////////////////////////////


	GameCamera::GameCamera(Gamebool bCreateActor)
	{
		m_pCameraActor = nullptr;
		m_nHandle = 0;

		if (bCreateActor)
		{
			UWorld* pWorld = GameObjectManager::GetSingleton()->GetWorld();
			if (pWorld != nullptr)
			{
				m_pCameraActor = pWorld->SpawnActor<ASuperMap_CaptureSceneActor>();
				m_nHandle = m_pCameraActor->GetUniqueID();
			}
		}
	}

	GameCamera::~GameCamera()
	{
		if (m_pCameraActor != nullptr)
		{
			m_pCameraActor->Destroy();
			m_pCameraActor = nullptr;
		}
	}

	Gameint GameCamera::GetHandle()
	{
		return m_nHandle;
	}

	void GameCamera::SetViewMatrix(Gamedouble* pViewMatrix)
	{
		if (m_pCameraActor == nullptr)
		{
			return;
		}

		Matrix4d matViewMatrix(pViewMatrix);

		Gamedouble dPosX, dPosY, dPosZ;
		Gamedouble dUpX, dUpY, dUpZ;
		Gamedouble dRightX, dRightY, dRightZ;

		Gamedouble* pDoubleMat = new Gamedouble[16];

		Matrix4d::ToDoublePointer(matViewMatrix, pDoubleMat);

		_DecomposeViewMatrix2(pDoubleMat, dPosX, dPosY, dPosZ,
			dUpX, dUpY, dUpZ,
			dRightX, dRightY, dRightZ);

		delete[] pDoubleMat;

		FVector vLocation(dPosY, dPosX, dPosZ);
		vLocation *= M_TO_CM;

		// 相机向上的轴(Z)
		FVector vUp(dUpY, dUpX, dUpZ);
		vUp.Normalize();

		// 相机的右轴（Y）
		FVector vRight(dRightY, dRightX, dRightZ);
		vRight.Normalize();

		FMatrix matRoationXY = FRotationMatrix::MakeFromYZ(vRight, vUp);
		FRotator rRotator = matRoationXY.Rotator();

		MathEngine::UpdateRotationAndLocation(vLocation, rRotator, Georeference::GetECEFtoGeoreference());

		vLocation -= FVector(m_pCameraActor->GetWorld()->OriginLocation);
		if (ROCacheManager::m_eSceneType == SceneType::Globe ||
			ROCacheManager::m_eSceneType == SceneType::Ellipsoid_WGS84)
		{
			vLocation -= MathEngine::m_vWorldOffset;
		}
		m_pCameraActor->SetActorLocationAndRotation(vLocation, rRotator);

		/*测试代码*/
		/*TArray<AActor*> arrActors;
		UGameplayStatics::GetAllActorsWithTag(m_pCameraActor->GetWorld(), FName(TEXT("DDD1")), arrActors);

		int32 nCount = arrActors.Num();
		for (int32 n = 0; n < nCount; n++)
		{
			AActor* pActor = (AActor*)arrActors[n];
			if (pActor != nullptr)
			{
				pActor->SetActorLocationAndRotation(vLocation, rRotator);
			}
		}*/
	}

	void GameCamera::SetCameraParam(Gamebool bOrthographic, Gamedouble& dFov, Gamedouble& dAspect, Gamedouble& dNear, Gamedouble& dFar, Gamedouble*& pProjMatrix)
	{
		if (m_pCameraActor == nullptr)
		{
			return;
		}

		if (bOrthographic)
		{
			FReversedZOrthoMatrix ueProjMatrix(m_nOrthoWidnowWidth / 2.0f , m_nOrthoWidnowHeight / 2.0f , 1.0 / ((dFar - dNear)*M_TO_CM),  -dNear * M_TO_CM);
			m_pCameraActor->SetOrthWidth(m_nOrthoWidnowWidth);
			m_pCameraActor->SetProjectionType(ECameraProjectionMode::Orthographic);
			/*m_pCameraActor->GetCameraComponent()->ProjectionMode = ECameraProjectionMode::Orthographic;
			m_pCameraActor->GetCameraComponent()->OrthoWidth = dWidth;
			m_pCameraActor->GetCameraComponent()->OrthoNearClipPlane = dNear * M_TO_CM;
			m_pCameraActor->GetCameraComponent()->OrthoFarClipPlane = dFar * M_TO_CM;
			m_pCameraActor->GetCameraComponent()->AspectRatio = dWidth / dHeight;*/
			m_pCameraActor->SetProjectionMatrix(ueProjMatrix);
			
			Matrix4d mat(ueProjMatrix);
			Matrix4d::ToDoublePointer(mat, pProjMatrix);
		}
		else
		{
			// dFov为垂直视场角需要变换
			dFov = dFov * 0.5;

			FReversedZPerspectiveMatrix ueProjMatrix(dFov, dAspect, 1.0, dNear * M_TO_CM, dFar * M_TO_CM);
			m_pCameraActor->SetProjectionMatrix(ueProjMatrix);
		
			Matrix4d mat(ueProjMatrix);
			Matrix4d::ToDoublePointer(mat, pProjMatrix);
		}	
	}

	void GameCamera::SetProjMatrix(Gamedouble* pProjMatrix)
	{
		// TO DO
	}

	void GameCamera::SetUGCPosition(Gamedouble dX, Gamedouble dY, Gamedouble dZ)
	{
		m_dCameraPositionX = dX;
		m_dCameraPositionY = dY;
	}

	void GameCamera::GetUGCPosition(Gamedouble& dX, Gamedouble& dY, Gamedouble& dZ)
	{
		dX = m_dCameraPositionX;
		dY = m_dCameraPositionY;
	}

	void GameCamera::SetLookAt(Gamedouble dTargetX, Gamedouble dTargetY, Gamedouble dTargetZ, Gamedouble dUpX, Gamedouble dUpY, Gamedouble dUpZ)
	{
		// TO DO
	}

	void GameCamera::SetViewportRect(Gamedouble dX, Gamedouble dY, Gamedouble dWidth, Gamedouble dHeight)
	{
		// TO DO
	}

	void GameCamera::SetOrthoWindow(Gamedouble dWidth, Gamedouble dHeight)
	{
		m_nOrthoWidnowWidth  = dWidth * M_TO_CM;
		m_nOrthoWidnowHeight = dHeight * M_TO_CM;
	}


	void GameCamera::GetOrthoWindow(Gamedouble& dWidth, Gamedouble& dHeight)
	{
		dWidth = m_nOrthoWidnowWidth * CM_TO_M;
		dHeight= m_nOrthoWidnowHeight * CM_TO_M;
	}

	ASuperMap_CaptureSceneActor* GameCamera::GetCaptureSceneActor()
	{
		return m_pCameraActor;
	}

	void GameCamera::UpdateShowObject(SceneManagerType nSceneType, Gamebool bUseRectMaterial, Gamebool bOutputAlpha)
	{
		if (nSceneType == DRAW_SPATIALQUERY)
		{
			TMap<Gamelong, GameComponent*>& mapGameComponents = GameObjectManager::GetSingleton()->GetRenderGameComponent();
			for (TMap<Gamelong, GameComponent*>::TConstIterator It = mapGameComponents.CreateConstIterator(); It; ++It)
			{
				GameComponent* pGameComponent = It->Value;
				UseMaterialFlag useFlag = pGameComponent->GetSceneNode()->GetUseMaterialFlag();
				bool bUse = useFlag == UseMaterialFlag::UMF_RECT_SELECTION;
				if (bUseRectMaterial != bUse)
				{
					useFlag = bUseRectMaterial ? UseMaterialFlag::UMF_RECT_SELECTION : UseMaterialFlag::UMF_NORMAL;
					pGameComponent->GetSceneNode()->SetUseMaterialFlag(useFlag);
				}

				Gamefloat fOutputAlpha = bOutputAlpha ? 1.0f : 0.0f;
				UMaterialInstanceDynamic* pMat = pGameComponent->GetRectSelectMaterial();
				if (pMat != nullptr)
				{
					pMat->SetScalarParameterValue(TEXT("OutputAlpha"), fOutputAlpha);
				}
			}
		}
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////

	GameCameraManager* GameCameraManager::m_pGameCameraManager = nullptr;
	GameCameraManager::GameCameraManager()
	{
		m_pWorld = nullptr;
	}

	GameCameraManager::~GameCameraManager()
	{
	}

	void GameCameraManager::SetWorld(UWorld* pWorld)
	{
		m_pWorld = pWorld;
	}

	UWorld* GameCameraManager::GetWorld()
	{
		return m_pWorld;
	}

	void GameCameraManager::SetMainCameraViewMatrix(Gamedouble* pViewMatrix)
	{
		if (m_pWorld == nullptr)
		{
			return;
		}

		Matrix4d matViewMatrix(pViewMatrix);

		Gamedouble dPosX, dPosY, dPosZ;
		Gamedouble dUpX, dUpY, dUpZ;
		Gamedouble dRightX, dRightY, dRightZ;

		Gamedouble* pDoubleMat = new Gamedouble[16];

		Matrix4d::ToDoublePointer(matViewMatrix, pDoubleMat);

		_DecomposeViewMatrix2(pDoubleMat, dPosX, dPosY, dPosZ,
			dUpX, dUpY, dUpZ,
			dRightX, dRightY, dRightZ);

		delete[] pDoubleMat;

		FVector vLocation(dPosY, dPosX, dPosZ);
		vLocation *= M_TO_CM;

		// 相机向上的轴(Z)
		FVector vUp(dUpY, dUpX, dUpZ);
		vUp.Normalize();

		// 相机的右轴（Y）
		FVector vRight(dRightY, dRightX, dRightZ);
		vRight.Normalize();

		FMatrix matRoationXY = FRotationMatrix::MakeFromYZ(vRight, vUp);
		FRotator rRotator = matRoationXY.Rotator();

		MathEngine::UpdateRotationAndLocation(vLocation, rRotator, Georeference::GetECEFtoGeoreference());

		vLocation -= FVector(m_pWorld->OriginLocation);

		if (ROCacheManager::m_eSceneType == SceneType::Globe ||
			ROCacheManager::m_eSceneType == SceneType::Ellipsoid_WGS84)
		{
			vLocation -= MathEngine::m_vWorldOffset;
		}
		m_pWorld->GetFirstPlayerController()->GetPawn()->SetActorLocation(vLocation);
		m_pWorld->GetFirstPlayerController()->SetControlRotation(rRotator);
	}

	void GameCameraManager::DestorySingleton()
	{
		if (m_pGameCameraManager != nullptr)
		{
			delete m_pGameCameraManager;
			m_pGameCameraManager = nullptr;
		}
	}

	GameCameraManager* GameCameraManager::GetSingleton()
	{
		if (m_pGameCameraManager == nullptr)
		{
			m_pGameCameraManager = new GameCameraManager();
		}

		return m_pGameCameraManager;
	}
	
	GameCamera* GameCameraManager::Create(Gamebool bCreateActor)
	{
		GameCamera* pGameCamera = new GameCamera(bCreateActor);
		m_mapCamera.Add(pGameCamera->GetHandle(), pGameCamera);
		return pGameCamera;
	}

	GameCamera* GameCameraManager::Get(Gameint cameraHandle)
	{
		Gamebool bHas = m_mapCamera.Contains(cameraHandle);
		if (bHas)
		{
			return m_mapCamera[cameraHandle];
		}
		return nullptr;
	}

	void GameCameraManager::Remove(Gameint cameraHandle)
	{
		Gamebool bHas = m_mapCamera.Contains(cameraHandle);
		if (bHas)
		{
			GameCamera* pGameCamera = m_mapCamera[cameraHandle];
			delete pGameCamera;
			pGameCamera = nullptr;

			m_mapCamera.Remove(cameraHandle);
		}
	}
}

#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif