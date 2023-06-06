#pragma once

#include "CoreMinimal.h"
#include "Graphics3D/GameEntityBase.h"
#include "Core/RealspaceDLL.h"

class UStaticMesh;

namespace SuperMapSDK
{
	//! \brief ����ʵ����ʵ�����
	typedef void*(*CreateInstanceEntityFunction)(void* pSceneNodeHandle, void* pDataVertexPackage, void* pArrIndexPackages, void* pArrMaterialParams, Gameint nSubMeshCount, Gamechar* strMeshName);

	//! \brief ��ȡʵ�������Ⱦ�ڵ�
	typedef void*(*GetInstanceMeshAttachComponentFunction)(void* pEntityHandle);

	//! \brief дʵ������Ϣ
	typedef void (*WriteInstanceBufferFunction)(void* pEntityHandle, Gameint nIntanceSize, Gameint nSizeInFloatPerInstance, void* pValue);

	//! \brief ɾ��ʵ��������
	typedef void(*DestroyInstanceEntityFunction)(void* pEntityHandle);

	//! \brief ���ð�Χ��
	typedef void(*SetInstanceBoundingBoxFunction)(void* pEntityHandle, void* pBoundBox);

	//! \brief �޸Ķ�����ɫ
	typedef void(*UpdateInstanceVertexColorHandleFunction)(void* pEntityHandle, Gameuint nColor, Gameuint nInstanceSize, Gameushort* pInstanceIds);

	//! \brief ����ʵ����ʵ��
	void* CreateInstanceEntity(void* pSceneNodeHandle, void* pDataVertexPackage, void* pArrIndexPackages , void* pArrMaterialParams, Gameint nSubMeshCount, Gamechar* strMeshName);

	//! \brief ��ȡʵ�����
	void* GetInstanceMeshAttachComponent(void* pEntityHandle);

	//! \brief дʵ������Ϣ
	void WriteInstanceBuffer(void* pEntityHandle, Gameint nIntanceSize, Gameint nSizeInFloatPerInstance, void* pValue);

	//! \brief �޸�ʵ�����Ķ�����ɫ
	void SetInstanceVertexColor(void* pEntityHandle, Gameuint nColor, Gameuint nInstanceSize, Gameushort* pInstanceIds);

	//! \brief ɾ��ʵ�����
	void DestroyInstanceEntity(void* pEntityHandle);

	//! \brief ���ð�Χ��
	void SetInstanceBoundingBox(void* pEntityHandle, void* pBoundBox);

	class SUPERMAP_API GameInstanceEntity : public GameEntityBase
	{
	public:
		GameInstanceEntity();
		virtual ~GameInstanceEntity();

	public:
		//! \brief ��ʼ���ص�����
		static void InitializeCallbackHandle();

		//! \brief ����ʵ����������
		void SetEntityMeshName(FString strEntityMeshName);

		//! \brief ��ȡʵ����������
		FString GetEntityMeshName();

		//! \brief ���þ�̬����
		void SetStaticMesh(UStaticMesh* pStaticMesh);

		//! \brief ��ȡ��̬����
		UStaticMesh* GetStaticMesh();

		//! \brief Mesh�Ƿ��ϴ��Կ�
		virtual Gamebool IsInitialGPU();

		void AddGameMaterial(GameMaterial* pGameMaterial);

		//! \brief ʵ�������
		virtual EntityType Type();
	private:
		//! \brief �Ǽ�����
		FString m_strEntityMeshName;

		//! \brief ��̬����
		UStaticMesh* m_pStaticMesh;

		//! \brief ʹ�õĲ���
		TArray<GameMaterial*> m_vecGameMaterial;
	public:
		//! \brief ʵ������Ϣ
		Gameint m_nInstanceSize;
		Gameint m_nSizeInFloatPerInstance;
		Gamevoid* m_pValue;
	};
}