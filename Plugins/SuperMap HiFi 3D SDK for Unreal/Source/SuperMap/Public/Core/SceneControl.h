#pragma once

#include "CoreMinimal.h"
#include "Core/SceneEditorWnd.h"
#include "Data/Workspace.h"
#include "Core/RealspaceDLL.h"

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			class Scene;
			class SUPERMAP_API SceneControl
			{
			public:
				SceneControl();
				~SceneControl();
			private:
				//! \brief ����
				Scene* m_pScene;

				//! \brief �����༭
				SceneEditorWnd* m_pSceneEditorWnd;

				Workspace* m_pWorkspace;
			public:
				//! \brief ��ȡ����
				Scene* GetScene();

				//! \brief ��ʼ��
				bool InitializeScene(int32 width, int32 height);

				//! \brief ��ʼ��
				void Render();

				//! \brief ֹͣ����
				void ShutDown(bool bQuitApplication);

				//! \brief ���õ��εĲ����
				void SetTerrainPosition(float x, float y, float z);

				//! \brief ��ȡ���εĲ����
				FVector GetTerrainPosition();

				//! \brief ��ȡ�����༭��
				SceneEditorWnd* GetSceneEditorWnd();

				//! \brief ��ȡ�����ռ�
				Workspace* GetWorkspace();

				void SetMultiTexture(Gamebool bSet);
			};
		}
	}
}