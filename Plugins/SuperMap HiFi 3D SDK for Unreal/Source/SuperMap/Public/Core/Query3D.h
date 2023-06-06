#pragma once

#include "CoreMinimal.h"
#include "Core/Analyst3D.h"
#include "Base3D/CommonDefine.h"
#include "Data/Vector3d.h"
#include "Data/Geometry3D.h"
#include "Core/RealspaceDLL.h"

using namespace SuperMapSDK::UnrealEngine::Base3D;
using namespace SuperMapSDK::UnrealEngine::Data;

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			class SUPERMAP_API Query3D
			{
			public:
				enum PositionMode
				{
					//! \brief 分离
					Disjoint3D = 0,
					//! \brief 相交
					Intersects3D = 1,
					//! \brief 包含
					Contains3D = 2,
				};
			public:
				//! \brief 构造函数
				Query3D();
				~Query3D();

				//! \brief 设置空间查询几何对象
				void SetQueryGeometry(Geometry3D* pGeometry3D);

				//! \brief 设置选中区域
				void SetPickRect(Vector3d vStart, Vector3d vEnd);

				//! \brief 设置几何查询的位置关系
				void SetPositionMode(Query3D::PositionMode nMode);

				//! \brief 获取几何查询的位置关系
				Query3D::PositionMode GetPositionMode();

				//! \brief 设置关联图层
				void AddLayerID(Gameint nLayerID);

				//! \brief 更新选中区域
				void UpdateRectSelect();

				//! \brief 获取选中的所有ID
				TMap<Gameint, TArray<Gameint> > GetQueryIDs();

				//! \brief 移除空间查询图层ID。
				void RemoveLayerID(Gameint nLayerId);

				//! \brief 空间查询结束
				void Realse();
			private:
				void* m_pUGQuery3D;
			};
		}
	}
}