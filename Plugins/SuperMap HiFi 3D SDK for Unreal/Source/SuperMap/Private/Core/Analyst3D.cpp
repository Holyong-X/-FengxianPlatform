#include "Core/Analyst3D.h"
#include "Core/Scene.h"
#include "Engine/World.h"

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			Analyst3D::Analyst3D(UWorld* pWorld, Scene* pScene, ControlUE::CameraControl* pCameraControl)
			{
				m_pWorld = pWorld;
				m_pScene = pScene;
				m_pCameraControl = pCameraControl;
			}
			Analyst3D::~Analyst3D()
			{
				m_pWorld = nullptr;
				m_pScene = nullptr;
				m_pCameraControl = nullptr;
			}

			void Analyst3D::Build()
			{
				DoBuild();
			}

			void Analyst3D::Clear()
			{
				DoClear();
			}

			AnalyzeMode Analyst3D::GetAnalyzeMode()
			{
				return m_eAnalyzeMode;
			}
		}
	}
}