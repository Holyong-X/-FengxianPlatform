#pragma once

#include "CoreMinimal.h"
#include "Base3D/CommonDefine.h"
#include "Graphics3D/GameStruct.h"
#include "Graphics3D/GameMaterial.h"
#include "Core/ROCache.h"
#include "Graphics3D/GameEnum.h"

namespace SuperMapSDK
{
	class GameComponent;
	class SUPERMAP_API GameEntityBase
	{
	public:
		GameEntityBase();
		virtual ~GameEntityBase();

		//! \brief ��ȡ���ݰ�
		DataVertex* GetDataVertexPackage();

		//! \brief �������ݰ�
		void SetDataVertexPackage(DataVertex* pDataVertex);

		//! \brief ��ȡ������
		TArray<DataIndice*>& GetIndexPackages();

		//! \brief ��ȡ��������
		Gameint GetIndexPackageCount();

		//! \brief ɾ������
		void RemoveIndexPackage(Gameint nIndex, Gameint nCount = 1);

		//! \brief ���������±��ȡ������
		DataIndice* GetIndexPackageByIndex(Gameint nIndex);

		//! \brief ���������±�����������
		void SetIndexPackageByIndex(Gameint nIndex, DataIndice* pDataIndice);

		//! \brief ����������
		void SetIndexPackages(TArray<DataIndice*>& arrDataIndices);

		//! \brief ���������
		void AddIndexPackage(DataIndice* pDataIndice);

		//! \brief ���ù��ؽڵ������
		void SetSceneNodeName(Gamelong nSceneNodeHandle);

		//! \brief ���ùҽӽڵ�
		void SetGameComponent(GameComponent* pGameComponent);

		//! \brief ��ȡ�ҽӽڵ�
		GameComponent* GetGameComponent();

		//! \brief ��ȡ�ҽӽڵ������
		Gamelong GetSceneNodeName();

		//! \brief ��ȡEntityHashCode
		Gamelong GetEntityName();

		//! \brief ����EntityHashCode
		void SetEntityName(Gamelong nEntityName);

		//! \brief �жϹǼ����ݰ��Ƿ���Ч
		Gamebool IsValid();

		//! \brief ���ùǼܵ�BoundBox
		void SetBBox(GameBoundingBox& box);

		//! \brief ��ȡ�Ǽ�BoundBox
		GameBoundingBox GetBBox();

		//! \brief �����Ƿ��ʼ��
		void SetIsInitialGPU(Gamebool bInitialGPU);

		//! \brief ��ȡ�Ƿ��ʼ��
		virtual Gamebool IsInitialGPU();

		//! \brief �����Ƿ��ʼ��
		void SetIsUpdateGPU(Gamebool bUpdateGPU);

		//! \brief ��ȡ�Ƿ��ʼ��
		virtual Gamebool IsUpdateGPU();

		//! \brief �����Ƿ��첽
		void SetCanAsync(Gamebool bCanAsync);

		//! \brief �Ƿ����첽������
		virtual Gamebool IsCanAsync();

		//! \brief ʵ�������
		virtual EntityType Type();
	protected:
		//! \brief ���ݰ�
		DataVertex* m_pDataVertex;

		//! \brief ������
		TArray<DataIndice*> m_arrDataIndices;

		//! \brief �ҽӸ������ڵ�
		Gamelong m_nParentSceneNodeName;

		//! \brief ��Ⱦ�ڵ�
		GameComponent* m_pGameComponent;

		//! \brief BoundBox
		GameBoundingBox m_GameBoundingBox;

		//! \brief �Ƿ��Ѿ���ʼ��
		Gamebool m_bInitialGPU;

		//! \brief �Ƿ���³ɹ�
		Gamebool m_bUpdateGPU;

		//! \brief �Ƿ��첽����
		Gamebool m_bCanAsync;

		//! \brief HashCode
		Gamelong m_nEntityName;
	};
}