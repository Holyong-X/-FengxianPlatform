#pragma once

#include "CoreMinimal.h"
#include <vector>
#include "Component/SuperMap_InstancedActor.h"
class UWorld;
class UStaticMesh;
class ASuperMap_InstancedActor;

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{
			
			//! \brief 集合体类型
			enum SUPERMAP_API CollectionType
			{
				CT_POINT,   //  点
				CT_LINE,	//  线
				CT_REGION   //  面
			};

			//! \brief 集合体风格参数
			struct SUPERMAP_API CollectionStyleParam
			{
			public:
				//! \brief 外挂资产名称
				FString m_strAssetResoureName;

				//! \brief 外挂资产引用路径
				FString m_strAssetResourePath;

			};

			class Geometry;
			class SUPERMAP_API Collection
			{
			public:
				Collection(UWorld* pWorld);
				virtual ~Collection();

			public:
				//! \brief 构建风格
				virtual bool BuildStyle() = 0;

				//! \brief 获取集合体类型
				virtual CollectionType GetType() = 0;

				//! \brief 设置风格参数
				void SetStyleParam(CollectionStyleParam & styleParam);

				//! \brief 获取风格参数
				CollectionStyleParam& GetStyleParam();

				//! \brief 根据下标获取集合体的数据
				Geometry* GetGeometry(int32 nIndex);

				//! \brief 添加集合体数据
				void AddGeometry(Geometry* pGeometry);
			protected:
				//! \brief 加载StaticMesh
				UStaticMesh* CreateStaticMesh(FString strAssetPath);

				//! \brief 计算球面的旋转量
				FQuat CallRotator(FVector vDirectionUP);
				
			protected:

				//! \brief 集合体的类型
				CollectionType m_eCollectionType;

				//! \brief 集合体风格
				CollectionStyleParam m_StyleParam;

				//! \brief UE的场景管理器
				UWorld* m_pWorld;

				//! \brief 实例化渲染对象
				ASuperMap_InstancedActor* m_pInstancedActor;

				//! \brief 集合体数据
				TArray<Geometry*> m_Geometrys;
			};

		}
	}
}