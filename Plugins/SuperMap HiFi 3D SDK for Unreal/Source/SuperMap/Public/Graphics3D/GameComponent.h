#pragma once
#include "CoreMinimal.h"
#include "Base3D/CommonDefine.h"
#include "Graphics3D/GameEntity.h"
#include "Graphics3D/GameEnum.h"
#include "Graphics3D/GameEntityBase.h"
#include "Graphics3D/GameStruct.h"
#include "Component/SuperMap_MeshComponentInterface.h"
#include "Core/RealspaceDLL.h"

namespace SuperMapSDK
{
	//! \brief ���������ڵ� 
	typedef void*(*CreateSceneNodeFunction)();

	//! \brief ���ٳ����ڵ�
	typedef void(*DestroySceneNodeFunction)(void* pSceneNodeHandle);

	//! \brief ���þ���
	typedef void(*SetObjectMatrixFunction)(void* pSceneNodeHandle, Gamedouble* pMatrix);

	//! \brief ���ÿɼ���
	typedef void(*SetVisibleFunction)(void* pSceneNodeHandle, bool bIsVisible);

	typedef void(*SetSceneNodeVisibleFunction)(void* pSceneNodeHandle, bool bIsVisible);
	
	//! \brief �ҽ�ʵ�����
	typedef Gamebool(*AttachEntityFunction)(void* pSceneNodeHandle, void* pMeshHandle);

	//! \brief ��ȡ�����ڵ�
	typedef void*(*GetGameObjectFunction)(Gamelong nSceneNodeName);

	//! \brief �����������ڵ�
	typedef void*(*GetOrCreateRootSceneNodeFunction)(Gamechar* strSceneName, Gameint nSceneManagerType);

	//! \brief ���ٳ������ڵ�
	typedef void(*DestroyRootSceneNodeFunction)(void* pSceneNodeHandle);

	//! \brief �����ӳ����ڵ�
	typedef void*(*CreateChildSceneNodeFunction)(void* pParentNodeHandle, Gamelong nSceneNodeName, Gameint nSceneManagerType);

	//! \brief ���������ڵ�
	void* CreateSceneNode();

	//! \brief ���ٳ����ڵ�
	void DestroySceneNode(void* pSceneNodeHandle);

	//! \brief ���þ���
	void SetUGCObjectMatrix(void* pSceneNodeHandle, Gamedouble* pMatrix);

	//! \brief ���ÿɼ���
	void SetVisible(void* pSceneNodeHandle, Gamebool bVisible);

	void SetNodeVisible(void* pSceneNodeHandle, Gamebool bVisible);

	//! \brief �ҽ�ʵ������
	Gamebool AttachEntity(void* pSceneNodeHandle, void* pMeshHandle);

	//! \brief 
	void* GetGameObject(Gamelong nSceneNodeName);

	//! \brief ��ȡ���ߴ����������ڵ�
	void* GetOrCreateRootSceneNode(Gamechar* strSceneName, Gameint nSceneManagerType);

	//! \brief ���ٳ����ڵ�
	void DestroyRootSceneNode(void* pSceneNodeHandle);

	//! \brief �����ӳ����ڵ�
	void* CreateChildSceneNode(void* pParentNodeHandle, Gamelong nSceneNodeName, Gameint nSceneManagerType);
	
	//! \brief ������������ڵ�
	class GameObjectListNode
	{

	public:
		GameObjectListNode()
		{
			m_pPrev = nullptr;
			m_pNext = nullptr;
			m_pGameComponent = nullptr;
		}

		//! \brief ��һ��ָ��
		GameObjectListNode* m_pPrev;

		//! \brief  ��һ��ָ��
		GameObjectListNode* m_pNext;

		//! \brief  ��ǰָ��
		GameComponent* m_pGameComponent;
	};

	class GameMaterial;
	class SUPERMAP_API GameComponent
	{
	public:
		GameComponent(Gamelong nName, Gamelong nParentName, Gameint nSceneManagerType);
		~GameComponent();
	public:
		//! \brief ��ʼ���ص�����
		static void InitializeCallbackHandle();

		//! \brief ��ȡʵ�����ݰ�
		GameEntityBase* GetEntity();

		//! \brief ����ʵ�����ݰ�
		void SetEntity(GameEntityBase* pGameEntity);

		//! \brief ���ó�����Ⱦ�ڵ�
		void SetSceneNode(USuperMap_MeshComponentInterface* pSceneNode);

		//! \brief ��ȡ������Ⱦ�ڵ�
		USuperMap_MeshComponentInterface* GetSceneNode();

		//! \brief ���þ���
		void SetObjectMatrix(Gamedouble* pDoubleMat);

		//! \brief ��ȡԭʼUGC����
		Matrix4d GetObjectUGCMatrix();

		//! \brief ���ÿɼ���
		void SetObjectVisible(Gamebool bVisible);

		void SetSceneNodeVisible(Gamebool bVisible);

		//! \brief ���ؽڵ������
		Gamelong GetNodeName();

		//! \brief ��GameComponent������
		Gamelong GetParentNodeName();

		//! \brief ��ȡ��������
		SceneManagerType GetSceneManagerType();

		//! \brief ��ȡ��������
		DataType GetDataType();

		//! \brief ���¹Ǽ�
		void UpdateMesh(DataVertex* pDataVertex , Gameint nOffset,UGVertexDataStateSet nState);

		//! \brief ����ʵ��������Ķ�����ɫ
		void UpdateInstanceVertexColor(Gameuint nColor, TArray<uint32>& arrIds);

		//! \brief �첽���Ǽ�
		void AsyncMesh();

		//! \brief ���Ǽ�
		void InitMesh();

		//! \brief ���ʵ�廯����
		void InitInstanceMesh(Gameint nIntanceSize, Gameint nSizeInFloatPerInstance, void* pValue);

		//! \brief ���¶�̬ԭ��
		void UpdateWorldOrigin(Vector3d vOrigin);

		//! \brief ����������
		void UpdateSubMeshes(TArray<DataIndice*> & arrIndices);

		//! \brief ���UE�����������
		void AddUESubMeshMaterial(GameMaterial* pGameMaterial);

		void SetSupport(Gamebool bValue);
		Gamebool IsSupport();

		//! \brief ��Ӳ���
		void AddGameMaterialForAsync(GameMaterial* pGameMaterial);
		void UpdateMaterialForAsync(GameMaterial* pGameMaterial);

		void AddGameMaterial(GameMaterial* pGameMaterial);
		TArray<GameMaterial*>& GetAllGameMaterial();

		void RemoveGameMaterial(GameMaterial* pGameMaterial);

		//! \brief ����ͼ������
		void SetLayerName(FString strLayerName);
		FString GetLayerName();

		//! \brief ��ȡ��ѡ
		UMaterialInstanceDynamic* GetRectSelectMaterial();

		//! \brief ��ȡ�������
		ComponentType GetComponentType();

		//! \brief ��������Node
		void SetListNode(GameObjectListNode* pNode);

		//! \brief ��ȡ����Node
		GameObjectListNode* GetListNode();

		//! \brief ɾ��UE ���������
		void RemoveUESubMeshMaterial();

		//! \brief ������Ⱦ��������
		void SetSceneName(FString strSceneName);

		//! \brief ��ȡ��Ⱦ��������
		FString GetSceneName();
	private:
		//! \brief ���ÿɼ���
		void SetVisibleForAllChildren(Gamebool bVisible, Gamebool bSetByParent, USuperMap_MeshComponentInterface* pSceneNode);
	
		//! \brief �ж��������
		ComponentType MakeComponentType();

		//! \brief ��ʼ��BillboardMesh
		void InitBillboardMesh();

		//! \brief �Ƿ�����ײ���
		Gamebool IsOpenCrash();
	private:
		//! \brief ��Ⱦ��������
		FString m_strSceneName;

		//! \brief GameComponent������
		Gamelong m_nNodeName;

		//! \brief ��GameComponent������
		Gamelong m_nParentNodeName;

		//! \brief GameComponent���ڵĳ�������
		SceneManagerType m_enSceneManagerType;

		//! \brief �����ڵ�
		USuperMap_MeshComponentInterface* m_pSceneNode;

		//! \brief ʵ��������ݰ�
		GameEntityBase* m_pGameEntity;

		//! \brief ����任����
		Matrix4d m_localToECEF;
		//! \brief ԭʼ����
		Matrix4d m_matUGCLocalToECEF;

		//! \brief �Ƿ����ϲ�֧����Ⱦ�Ķ�������
		Gamebool m_bSupport;

		//! \brief ԭʼ���ʲ���
		TArray<GameMaterial*> m_vecGameMaterial;

		//! \brief UE�Ӳ��ʲ���
		TArray<GameMaterial*> m_vecUESubMeshMaterial;

		//! \brief ʹ�õ�ѡ�����
		UMaterialInstanceDynamic* m_pSelectionMaterial;

		//! \brief ʹ�õĿ�ѡ����
		UMaterialInstanceDynamic* m_pRectSelectMaterial;

		//! \brief ��������
		DataType m_enDataType;

		//! \brief ͼ����
		FString m_strLayerName;

		//! \brief ��ǰ���������Node
		GameObjectListNode* m_pCurrentListNode;
	};
}