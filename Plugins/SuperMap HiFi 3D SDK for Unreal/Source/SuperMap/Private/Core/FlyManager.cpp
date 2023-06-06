#include "Core/FlyManager.h"
#include "ControlUE/RealspaceView.h"

using namespace SuperMapSDK::UnrealEngine::ControlUE;

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			FlyManager::FlyManager()
			{
				m_pFlyManager = nullptr;
				m_pRoutes = nullptr;
				m_pScene = nullptr;
				_FlyManager_Create(m_pFlyManager);
			}

			FlyManager::FlyManager(Scene* pScene)
			{
				m_pFlyManager = nullptr;
				m_pRoutes = nullptr;
				m_pScene = pScene;
				_FlyManager_Create(m_pFlyManager);
			}

			FlyManager::~FlyManager()
			{
				if (m_pFlyManager != nullptr)
				{
					Stop();
					_FlyManager_Destroy(m_pFlyManager);
				}


				if (m_pRoutes != nullptr)
				{
					delete m_pRoutes;
					m_pRoutes = nullptr;
				}

				if (m_pScene != nullptr)
				{
					m_pScene = nullptr;
				}
			}

			void FlyManager::SetDuration(Gamedouble dDuration)
			{
				_FlyManager_SetGlobalProgressTime(m_pFlyManager, dDuration);
			}

			Gamedouble FlyManager::GetDuration()
			{
				return _FlyManager_CalcGlobalProgressTime(m_pFlyManager);
			}

			void FlyManager::SetPlayRate(Gamedouble dPlayRate)
			{
				_FlyManager_SetPlayRate(m_pFlyManager, dPlayRate);
			}

			Gamedouble FlyManager::GetPlayRate()
			{
				return _FlyManager_GetPlayRate(m_pFlyManager);
			}

			void FlyManager::SetTurningMode(FlyTurningMode eFlyTurningMode)
			{
				_FlyManager_SetTurningMode(m_pFlyManager, (Gameint)eFlyTurningMode);
			}

			FlyTurningMode FlyManager::GetTurningMode()
			{
				return (FlyTurningMode)_FlyManager_GetTurningMode(m_pFlyManager);
			}

			Routes* FlyManager::GetRoutes()
			{
				if (m_pRoutes == nullptr)
				{
					void* pRoutes = nullptr;
					_FlyManager_GetRoutes(m_pFlyManager, pRoutes);
					m_pRoutes = new Routes(pRoutes);
				}
			
				return m_pRoutes;
			}

			FlyStatus FlyManager::GetStatus()
			{
				return FlyStatus(_FlyManager_GetStatus(m_pFlyManager));
			}

			void FlyManager::Play()
			{
				if (GetStatus() == FlyStatus::Play)
				{
					return;
				}
				_FlyManager_Play(m_pFlyManager);
				RealspaceView::GetSingleton()->GetCameraControl()->SetEditMode(CMEditMode::ROAM);
			}

			void FlyManager::Stop()
			{
				_FlyManager_Stop(m_pFlyManager);
				RealspaceView::GetSingleton()->GetCameraControl()->SetEditMode(CMEditMode::NORMAL);
			}

			void FlyManager::Pause()
			{
				_FlyManager_Pause(m_pFlyManager);
				RealspaceView::GetSingleton()->GetCameraControl()->SetEditMode(CMEditMode::NORMAL);
			}

			void FlyManager::Update()
			{
				_FlyManager_Update(m_pFlyManager);
			}

			
			Gameint FlyManager::GetCurrentStopIndex()
			{
				return _FlyManager_GetCurrentStopIndex(m_pFlyManager);
			}

			
			void FlyManager::SetCurrentStopIndex(Gameint nIndex)
			{
				_FlyManager_SetCurrentStopIndex(m_pFlyManager, nIndex);
			}

			Gamebool FlyManager::GetArriedStatus()
			{
				if (_FlyManager_GetArrivedNewStopIndex(m_pFlyManager) == -1)
				{
					return true;
				}
				return false;
			}

			void FlyManager::SetOriginalPosition(Vector3d vOriginalPos)
			{
				if (m_pScene != nullptr && m_pScene->GetSceneType() == SceneType::Flat)
				{
					_FlyManager_SetOriginalPosition(m_pFlyManager, vOriginalPos.X, vOriginalPos.Y, vOriginalPos.Z);
				}	
			}

			Gamedouble FlyManager::GetCurrentProgress()
			{
				return _FlyManager_GetCurrentProgress(m_pFlyManager);
			}
		}
	}
}