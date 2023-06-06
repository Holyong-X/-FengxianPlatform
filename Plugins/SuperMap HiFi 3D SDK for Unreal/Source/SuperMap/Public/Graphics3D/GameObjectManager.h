#pragma once
//===============================================
// ��Ⱦ���������
//===============================================

#include "CoreMinimal.h"
#include "Base3D/CommonDefine.h"
#include "Graphics3D/GameComponent.h"
#include "Graphics3D/GameOcclusionVolume.h"
#include "Engine/World.h"
#include "Component/SuperMap_InstancedActor.h"
#include "Component/SuperMap_CustomVectorActor.h"
#include "Component/SuperMap_SplineActor.h"
#include "Component/SuperMap_TextActor.h"
class ASuperMap_ROEntityActor;
class ASuperMap_SplineActor;
namespace SuperMapSDK
{
	//class SuperMapSDK::UnrealEngine::Core::Scene;

	class SUPERMAP_API GameObjectManager
	{
	public:
		GameObjectManager();
		~GameObjectManager();

	public:
		//! \brief ��ȡ������
		static GameObjectManager* GetSingleton();

		//! \brief �����ڵ���
		void* CreateOcclusionVolume(Gamelong nIDName);

		//! \brief ɾ���ڵ���
		void DestroyOcclusionVolume(void* pOcclusionVolumeHandle);

		//! \brief ���ٵ�����
		static void DestorySingleton();

		//! \brief �������߻�ȡ���ڵ�
		void* GetOrCreateRootSceneNode(Gamechar* strSceneName, Gameint nSceneManagerType);

		//! \brief ɾ�������ڵ�
		void DestroySceneNode(void* pSceneNodeHandle);

		//! \brief ���ö������
		void SetObjectMatrix(void* pSceneNodeHandle, Gamedouble* pMatrix);

		//! \brief ���ÿɼ���
		void SetVisible(void* pSceneNodeHandle, Gamebool bVisible);


		void SetSceneNodeVisible(void* pSceneNodeHandle, Gamebool bVisible);

		//! \brief �ҽӳ����ڵ�
		Gamebool AttachEntity(void* pSceneNodeHandle, void* pMeshHandle);

		//! \brief �����ӽڵ�
		void* CreateChildSceneNode(void* pParentNodeHandle, Gamelong nSceneNodeName, Gameint nSceneManagerType);

		//! \brief ���ó�������
		void SetWorld(UWorld* pWorld);
		UWorld* GetWorld();

		//! \brief ���ó�������
		void SetScene(void* pScene);
		void* GetScene();

		//! \brief ��ȡ�����ڵ�
		GameComponent* GetGameComponent(Gamelong nSceneNodeHandle);

		//! \brief �������綯̬ԭ��
		void UpdateWorldOrigin(Vector3d vOrigin);

		//! \brief ��ȡ���е���Ⱦ�ڵ�
		TMap<Gamelong, GameComponent*>& GetAllGameComponent();

		//! \brief ��ȡ��ʵ���������Ⱦ�ڵ�
		TMap<Gamelong, GameComponent*>& GetRenderGameComponent();

		//! \brief ��ȡʵ��������
		TMap<uint32, ASuperMap_InstancedActor*>& GetInstancedActors();

		//! \brief ��ȡʵ��������
		TMap<uint32, ASuperMap_SplineActor*>& GetSplineActors();

		//! \brief ��ȡʸ��
		TArray<ASuperMap_CustomVectorActor*>& GetVectorActors();

		//! \brief ��ȡROEntity_Line����
		TArray<ASuperMap_ROEntityActor*>& GetLineMeshActors();

		//! \brief ��ȡ���ֶ���
		TArray<ASuperMap_TextActor*>& GetTextActors();

		//! \brief ��ȡ�������ض���
		TArray<AActor*> & GetSceneHiddenActors();

		//! \brief ��ȡδ��ʼ�����������
		GameObjectListNode* GetUnInitialListNode();

		//! \brief ���δ��ʼ�����������
		void AddUnitialComponent(GameComponent* pGameComponent);

		//! \brief ɾ��δ��ʼ�����������
		void RemoveUnitialComponent(GameComponent* pGameComponent);

		//! \brief �����Ƿ�����ײ����
		void SetEnableCollision(Gamebool bEnable);

		//! \brief �Ƿ�����ײ����
		Gamebool IsEnableCollision();
	private:
		//! \brief ���������ڵ�
		USuperMap_MeshComponentInterface* CreateComponent(FName& name);

	private:
		//! \brief ��������
		void* m_pScene;

		//! \brief ���糡������
		UWorld* m_pWorld;

		//! \brief ��Ϸ���������
		static GameObjectManager* m_pGameObjectManager;

		//! \brief ���нڵ�������
		TMap<Gamelong, GameComponent*> m_mapGameComponents;

		//! \brief ��Ⱦ�ڵ�������
		TMap<Gamelong, GameComponent*> m_mapRenderGameComponents;

		//! \brief �����ܸ��ڵ�
		ASuperMap_ROEntityActor* m_pRootNode;

		//! \brief ����������ڵ�
		TMap<FString, GameComponent*> m_mapSceneRootComponent;

		//! \brief ����ʵ��������
		TMap<uint32, ASuperMap_InstancedActor*> m_mapInstancedActors;

		//! \brief ����ʵ��������
		TMap<uint32, ASuperMap_SplineActor*> m_mapSplineActors;

		//! \brief ���������
		TArray<ASuperMap_CustomVectorActor*> m_arrVectorActors;

		//! \brief ����ROEntity_Line����
		TArray<ASuperMap_ROEntityActor*> m_arrLineMeshActors;

		//! \brief ����������Ⱦ����
		TArray<ASuperMap_TextActor*> m_arrTextActors;

		//! \brief �ڵ������
		TMap<Gamelong, GameOcclusionVolume*> m_mapOcclusionVolumes;

		//! \brief �Ƿ�����ײ���
		Gamebool m_bEnableCollision;

		//! \brief ��Ҫ��ʼ���ڵ�����
		TMap<Gamelong, GameComponent*> m_mapUnInitialComponents;

		GameObjectListNode* m_pHead;
		GameObjectListNode* m_pTail;

		//! \brief ������Ȳ�����Ķ���
		TArray<AActor*> m_arrSceneHiddenActors;
	};
}
