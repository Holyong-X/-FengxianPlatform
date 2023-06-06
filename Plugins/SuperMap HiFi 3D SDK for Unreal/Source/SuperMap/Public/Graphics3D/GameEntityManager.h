#pragma once

#include "CoreMinimal.h"
#include "Base3D/CommonDefine.h"
#include "Graphics3D/GameEntity.h"
#include "Graphics3D/GameInstanceEntity.h"
#include "Engine/World.h"
#include "Core/RealspaceDLL.h"

namespace SuperMapSDK
{
	class SUPERMAP_API GameEntityManager
	{
	public:
		GameEntityManager();
		~GameEntityManager();

	public:
		//! \brief ��ȡ������
		static GameEntityManager* GetSingleton();

		//! \brief ���ٵ�����
		static void DestorySingleton();

		//! \brief ����ʵ������
		void* CreateEntity();

		//! \brief ɾ��ʵ������
		void Remove(void* pEntityHandle);

		//! \brief ��ȡʵ������
		GameEntityBase* GetEntity(Gamelong nEntityHandle);

		//! \brief ����ʵ����������
		void CreateInstanceEntity(Gamelong& nEntityHandle, GameInstanceEntity* & pInstanceEntity);

		//! \brief ��ȡ��̬����ӳ���
		TMap<FString, TKeyValuePair<UStaticMesh*, Gameint> >& GetStaticMeshMaps();

		//! \brief ɾ����̬����
		void RemoveStaticMesh(FString strStaticMeshName);

		//! \brief �Ǽ��Ƿ��ϴ��Կ�
		Gamebool IsMeshInitialGPU(void* pEntityHandle);

		//! \brief ���ó�������
		void SetWorld(UWorld* pWorld);

		//! \brief ��ȡ��������
		UWorld* GetWorld();
	private:
		//! \brief ������ָ��
		static GameEntityManager* m_pEntityManager;

		//! \brief Entity��
		TMap<Gamelong, GameEntityBase*> m_mapEntitys;

		//! \brief StaticMesh��
		TMap<FString, TKeyValuePair<UStaticMesh*, Gameint> > m_mapStaticMeshs;

		//! \brief ���糡������
		UWorld* m_pWorld;
	};
}