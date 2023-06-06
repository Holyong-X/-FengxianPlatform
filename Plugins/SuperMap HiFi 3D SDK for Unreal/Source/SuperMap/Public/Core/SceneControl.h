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
				//! \brief 场景
				Scene* m_pScene;

				//! \brief 场景编辑
				SceneEditorWnd* m_pSceneEditorWnd;

				Workspace* m_pWorkspace;
			public:
				//! \brief 获取场景
				Scene* GetScene();

				//! \brief 初始化
				bool InitializeScene(int32 width, int32 height);

				//! \brief 初始化
				void Render();

				//! \brief 停止运行
				void ShutDown(bool bQuitApplication);

				//! \brief 设置地形的插入点
				void SetTerrainPosition(float x, float y, float z);

				//! \brief 获取地形的插入点
				FVector GetTerrainPosition();

				//! \brief 获取场景编辑类
				SceneEditorWnd* GetSceneEditorWnd();

				//! \brief 获取工作空间
				Workspace* GetWorkspace();

				void SetMultiTexture(Gamebool bSet);
			};
		}
	}
}