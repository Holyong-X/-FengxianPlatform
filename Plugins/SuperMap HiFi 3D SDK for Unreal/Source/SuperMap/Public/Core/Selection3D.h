#pragma once

#include "CoreMinimal.h"
#include "Base3D/CommonDefine.h"
#include "Core/RealspaceDLL.h"

using namespace SuperMapSDK;

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			class Layer3D;
			class Layer3DS3MFile;
			class SUPERMAP_API Selection3D
			{
			public:
				friend class Layer3DS3MFile;
			private:
				//! \brief 关联的图层
				Layer3D* m_pLayer;

				//! \brief UGC句柄
				void* m_pUGSelection3D;
			public:
				Selection3D(Layer3D* pLayer3D);
				~Selection3D();

				//! \brief 获取关联图层
				Layer3D* GetLayer();

				//! \brief 根据索引获取选择集ID
				Gameint GetID(Gameint nIndex);

				//! \brief 获取选择集中对象数目
				Gameint GetCount();

				//! \brief 添加ID
				Gameint Add(Gameint nID);
				
				//! \brief 清除所有ID
				void Clear();

				//! \brief 查找ID
				Gamebool FindID(Gameint nID);
			};
		}
	}
}