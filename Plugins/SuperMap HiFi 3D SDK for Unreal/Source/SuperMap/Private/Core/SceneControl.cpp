#include "Core/SceneControl.h"
#include "Core/Scene.h"
#include "Core/Public/Misc/MessageDialog.h"
#include "Core.h"
#include "ControlUE/RealspaceView.h"
#include "ControlUE/CameraControl.h"
using namespace SuperMapSDK::UnrealEngine::ControlUE;

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			SceneControl::SceneControl()
			{
				m_pScene = new Scene();
				m_pSceneEditorWnd = new Core::SceneEditorWnd(m_pScene);
				m_pWorkspace = nullptr;
			}

			SceneControl::~SceneControl()
			{
				if (m_pScene != nullptr)
				{
					delete m_pScene;
					m_pScene = nullptr;
				}

				if (m_pSceneEditorWnd != nullptr)
				{
					delete m_pSceneEditorWnd;
					m_pSceneEditorWnd = nullptr;
				}

				if (m_pWorkspace != nullptr)
				{
					delete m_pWorkspace;
					m_pWorkspace = nullptr;
				}
			}

			void SceneControl::Render()
			{
				if (_Render != nullptr)
				{
					_Render();
				}
			}

			Scene* SceneControl::GetScene()
			{
				return m_pScene;
			}

			bool SceneControl::InitializeScene(int32 width, int32 height)
			{
				int32 nType = (m_pScene->GetSceneType() == Globe ? 3 : 2);
				nType = (m_pScene->GetSceneType() == Ellipsoid_WGS84 ? 7: nType);
				void* pScene = nullptr;
				bool bInit = _InitialScene(width, height, nType, width, height, pScene);
				m_pScene->SetHandler(pScene);
				return bInit;
			}

			void SceneControl::ShutDown(bool bQuitApplication)
			{
				m_pScene->Clear();
				m_pSceneEditorWnd->Release();
				if (m_pWorkspace != nullptr)
				{
					delete m_pWorkspace;
					m_pWorkspace = nullptr;
				}
				if (bQuitApplication && _Kill != nullptr)
				{
					_Kill();
				}
				else
				{
					_DestroyScene();
				}
			}

			void SceneControl::SetTerrainPosition(float x, float y, float z)
			{
				m_pScene->m_vtTerrainPos = FVector(x, y, z);
				ROCacheManager::m_vPlaneOffset = FVector(x, y, z);
				if (_SetPosition != nullptr)
				{
					_SetPosition(x, y, z);
				}
			}

			FVector SceneControl::GetTerrainPosition()
			{
				return m_pScene->m_vtTerrainPos;
			}

			Core::SceneEditorWnd* SceneControl::GetSceneEditorWnd()
			{
				return m_pSceneEditorWnd;
			}

			Workspace* SceneControl::GetWorkspace()
			{
				if (m_pWorkspace == nullptr)
				{
					void* pWorkspace = nullptr;
					_SceneControl_GetWorkspace(pWorkspace);

					m_pWorkspace = new Workspace(pWorkspace);
				}

				return m_pWorkspace;
			}

			void SceneControl::SetMultiTexture(Gamebool bSet)
			{
				_SceneControl_SetMultiTexture(bSet);
			}
		}
	}
}

