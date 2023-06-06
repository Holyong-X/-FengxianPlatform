#pragma once

#include "CoreMinimal.h"
#include "Core/Layer3D.h"
#include "Data/Geometry.h"

using namespace SuperMapSDK::UnrealEngine::Data;

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			class SUPERMAP_API TrackingLayer : public Layer3D
			{
			public:
				TrackingLayer();
				virtual ~TrackingLayer();

			public:
				//! \brief 添加Geometry几何对象
				int32 AddGeometry(Geometry* pGeometry, FString strTag);

				//! \brief 移除图层中指定序号的对象
				bool Remove(int32 nIndex);

				//! \brief 返回图层中指定序号的几何体
				Geometry* Get(int32 nIndex);

				//! \brief 获取指定序号对象的标签名
				FString GetTag(int32 nIndex);

				//! \brief 设置图层中指定序号的对象的标签名
				void Clear();

				//! \brief 返回指定标签名对象的序号
				int32 IndexOf(FString strTag);

				//! \brief 图层中对象的个数
				int32 GetCount();

				//! \brief 添加图层的渲染对象
				virtual void AddNativeGameComponent(GameComponent* pGameComponent);
				//! \brief 移除图层的渲染对象
				virtual void RemoveNativeGameComponent(GameComponent* pGameComponent);
			private:
				void UpdateShaderForOneNativeGameComponent(GameComponent* pGameComponent);

				//! \brief 更换图层材质
				void UpdateMaterialInfo(GameMaterial* pGameMaterial);
			};

		}
	}
}