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

		//! \brief 获取数据包
		DataVertex* GetDataVertexPackage();

		//! \brief 设置数据包
		void SetDataVertexPackage(DataVertex* pDataVertex);

		//! \brief 获取索引包
		TArray<DataIndice*>& GetIndexPackages();

		//! \brief 获取索引个数
		Gameint GetIndexPackageCount();

		//! \brief 删除索引
		void RemoveIndexPackage(Gameint nIndex, Gameint nCount = 1);

		//! \brief 根据索引下标获取索引包
		DataIndice* GetIndexPackageByIndex(Gameint nIndex);

		//! \brief 根据索引下标设置索引包
		void SetIndexPackageByIndex(Gameint nIndex, DataIndice* pDataIndice);

		//! \brief 设置索引包
		void SetIndexPackages(TArray<DataIndice*>& arrDataIndices);

		//! \brief 添加索引包
		void AddIndexPackage(DataIndice* pDataIndice);

		//! \brief 设置挂载节点的名字
		void SetSceneNodeName(Gamelong nSceneNodeHandle);

		//! \brief 设置挂接节点
		void SetGameComponent(GameComponent* pGameComponent);

		//! \brief 获取挂接节点
		GameComponent* GetGameComponent();

		//! \brief 获取挂接节点的名字
		Gamelong GetSceneNodeName();

		//! \brief 获取EntityHashCode
		Gamelong GetEntityName();

		//! \brief 设置EntityHashCode
		void SetEntityName(Gamelong nEntityName);

		//! \brief 判断骨架数据包是否有效
		Gamebool IsValid();

		//! \brief 设置骨架的BoundBox
		void SetBBox(GameBoundingBox& box);

		//! \brief 获取骨架BoundBox
		GameBoundingBox GetBBox();

		//! \brief 设置是否初始化
		void SetIsInitialGPU(Gamebool bInitialGPU);

		//! \brief 获取是否初始化
		virtual Gamebool IsInitialGPU();

		//! \brief 设置是否初始化
		void SetIsUpdateGPU(Gamebool bUpdateGPU);

		//! \brief 获取是否初始化
		virtual Gamebool IsUpdateGPU();

		//! \brief 设置是否异步
		void SetCanAsync(Gamebool bCanAsync);

		//! \brief 是否是异步填网格
		virtual Gamebool IsCanAsync();

		//! \brief 实体包类型
		virtual EntityType Type();
	protected:
		//! \brief 数据包
		DataVertex* m_pDataVertex;

		//! \brief 索引包
		TArray<DataIndice*> m_arrDataIndices;

		//! \brief 挂接父场景节点
		Gamelong m_nParentSceneNodeName;

		//! \brief 渲染节点
		GameComponent* m_pGameComponent;

		//! \brief BoundBox
		GameBoundingBox m_GameBoundingBox;

		//! \brief 是否已经初始化
		Gamebool m_bInitialGPU;

		//! \brief 是否更新成功
		Gamebool m_bUpdateGPU;

		//! \brief 是否异步加载
		Gamebool m_bCanAsync;

		//! \brief HashCode
		Gamelong m_nEntityName;
	};
}