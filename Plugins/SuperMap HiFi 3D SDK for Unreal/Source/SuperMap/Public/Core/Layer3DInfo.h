#pragma once

#include "CoreMinimal.h"

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			struct Layer3DMaterialInfo
			{
				// 材质名称
				FString m_strMaterialName;

				// 材质名称 - 路径映射
				//! \brief	Key : 原材质名称
				//! \brief	Value :  关联材质名称（省去路径）
				TMap<FString, FString> m_mapMaterialMappingInfo;
			};

			struct AssociateMaterialInfo
			{
				//! \brief 替换材质的名称
				FString AssociateMaterialName;
				//! \brief 替换材质的引用路径
				FString AssociateMaterialPath;
				//! \brief 替换材质的原始UV缩放
				FLinearColor MaterialOriginalUVTiling;
				//! \brief 替换材质的UV缩放
				FLinearColor AssociateMaterialUVTiling;

				AssociateMaterialInfo()
				{
					AssociateMaterialName = "";
					AssociateMaterialPath = "";
					AssociateMaterialUVTiling = FLinearColor(1, 1, 1, 1);
					MaterialOriginalUVTiling = FLinearColor(1, 1, 1, 1);
				}
			};

			struct ObjectMaterialInfo
			{
				// 材质名称修改映射
				TMap<FString, AssociateMaterialInfo> m_mapMaterialNameChanges;
			};
		}
	}
}