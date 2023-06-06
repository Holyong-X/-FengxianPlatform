#pragma once

#include "CoreMinimal.h"
#include "Base3D/CommonDefine.h"
#include "Graphics3D/GameStruct.h"
#include "Graphics3D/GameMaterial.h"
#include "Graphics3D/GameEntityBase.h"
#include "Component/SuperMap_VertexBuffer.h"
#include "Component/SuperMap_CustomVertexBuffer.h"

class UMaterialInterface;
class USuperMap_MeshComponent;
namespace SuperMapSDK
{
	//! \brief ����Entity����
	typedef void*(*CreateEntityFunction)();

	//! \brief ����Entity
	typedef void(*DestroyEntityFunction)(void* pMeshHandle);

	//! \brief �������ݰ�
	typedef void (*SetVertexDataPackageFunction)(void* pMeshHandle, GameDataVertexPackage* pVertexDataPackage);

	//! \brief ���ù������ݰ�
	typedef void(*SetVertexDataPackageSharedBufferFunction)(void* pMeshHandle, void* pGameVertexDataPackage, Gameint nOffset, UGVertexDataStateSet nState);
	
	//! \brief ����������
	typedef void(*CreateSubMeshFunction)(void* pMeshHandle, GameIndexPackage* pIndexPackage);

	//! \brief ��ȡ�ҽӵ�Component
	typedef void*(*GetAttachComponentFunction)(void* pMeshHandle);

	//! \brief �ҽӲ���
	typedef Gamebool(*AddMaterialFunction)(void* pMeshHandle, void* nMaterialHandle);

	//! \brief ��Ӽ��Ƴ�����
	typedef Gamebool(*SubtractMaterialFunction)(void* pMeshHandle, void* nMaterialHandle);

	typedef Gamebool(*AppendMaterialFunction)(void* pMeshHandle, void* nMaterialHandle);


	//! \brief ������Ⱦ״̬
	typedef Gamelong(*SetRenderStateFunction)(void* pMeshHandle, UGRenderStateSet nRenderState);

	//! \brief ���ñ߿���
	typedef void(*SetBoundingBoxFunction)(void* pMeshHandle, void* pBoundBox);

	//! \brief �������������
	typedef void(*RemoveAllSubMeshFunction)(void* pMeshHandle, Gamebool bReleaseMaterial);

	//! \brief �ж��Ƿ�Ǽ��ϴ��Կ�
	typedef Gamebool(*IsMeshInitialGPUFunction)(void* pMeshHandle);

	//! \brief ������������
	typedef void(*AddSubMeshMaterialFunction)(void* pMeshHandle, char* strMaterialName);

	//! \brief ���������
	typedef void(*UpdateSubMeshesFunction)(Gamevoid* pMeshHandle, Gamevoid** pGameIndexPackages, Gameint nCount);

	//! \brief ����ʵ�����
	void* CreateEntity();

	//! \brief ����ʵ�����
	void DestroyEntity(void* pMeshHandle);

	//! \brief �������ݰ�
	void SetVertexDataPackage(void* pMeshHandle, GameDataVertexPackage* pVertexDataPackage);

	//! \brief ���ù������ݰ�
	void SetVertexDataPackageSharedBuffer(void* pMeshHandle, void* pGameVertexDataPackage, Gameint nOffset, UGVertexDataStateSet nState);

	//! \brief ����������
	void CreateSubMesh(void* pMeshHandle, GameIndexPackage* pIndexPackage);

	//! \brief �����������
	void AddSubMeshMaterial(void* pMeshHandle, char* strMaterialName);

	//! \brief �������������
	void UpdateSubMeshes(Gamevoid* pMeshHandle, Gamevoid** pIndexPackages, Gameint nCount);

	//! \brief ��ȡ�ҽӵĳ����ڵ�
	void* GetAttachComponent(void* pMeshHandle);

	//! \brief ��������
	Gamebool AddMaterial(void* pMeshHandle, void* pMaterialHandle);

	//! \brief ��Ӽ��Ƴ�����
	Gamebool SubtractMaterial(void* pMeshHandle, void* pMaterialHandle);

	Gamebool AppendMaterial(void* pMeshHandle, void* pMaterialHandle);


	//! \brief ������Ⱦ״̬
	Gamelong SetRenderState(void* pMeshHandle, UGRenderStateSet nRenderState);

	//! \brief ���ñ߿���
	void SetBoundingBox(void* pMeshHandle, void* pBoundBox);

	//! \brief �������������
	void RemoveAllSubMesh(void* pMeshHandle, Gamebool bReleaseMaterial);

	//! \brief �Ǽ��Ƿ��ϴ��Կ�
	Gamebool IsMeshInitialGPU(void* pMeshHandle);


	struct GameUpdateMesh
	{
	public:
		DataVertex* m_pUpdateDataVertex;
		Gameint m_nUpdateOffset;
		UGVertexDataStateSet m_nUpdateState;

		GameUpdateMesh()
		{
			m_pUpdateDataVertex = nullptr;
			m_nUpdateOffset = 0;
			m_nUpdateState = VST_ALL;
		}
	};

	class GameComponent;
	class SUPERMAP_API GameEntity : public GameEntityBase
	{
	public:
		GameEntity();
		virtual ~GameEntity();

	public:
		//! \brief ��ʼ���ص�����
		static void InitializeCallbackHandle();

		//! \brief �첽�ϴ�
		void AsyncUploadEntity();

		//! \brief �첽����
		void AsyncUpdateEntity(DataVertex* pDataVertex, Gameint nOffset, UGVertexDataStateSet nState);

		//! \brief ������ײ��������
		void CreateCollisionData();

		//! \brief ��ȡ��ײ���
		FSMMeshCollisionData* GetCollisionData();

		//! \brief ������ײ���
		void SetCollisionData(FSMMeshCollisionData* pCollisionData);

		//! \brief �����첽���
		void SetAsyncLoading(Gamebool bAsyncLoading);

		//! \brief ��ȡ�첽�Ƿ����
		Gamebool GetAsyncLoading();

		//! \brief ���ø��µĹǼ�
		Gamevoid SetAsyncUpdateMesh(DataVertex* pDataVertex, Gameint nOffset, UGVertexDataStateSet nState);

		//! \brief �Ƿ��и���
		Gamebool IsNeedUpdate();

		//! \brief ��ȡ���µĹǼܣ��ⲿ�ͷţ�
		TArray<GameUpdateMesh*>& GetUpdateMesh();

		//! \brief ʵ�������
		virtual EntityType Type();
	private:
		//! \brief ��ײ�������
		FSMMeshCollisionData* m_pSMMeshCollisionData;

		//! \brief �Ƿ��첽
		Gamebool m_bAsyncLoading;

		//! \brief ��ȫ
		Gamebool m_bReleaseBuffer;

		//! \brief �첽���¹Ǽ�
		TArray<GameUpdateMesh*> m_arrUpdateMeshs;
	};
}