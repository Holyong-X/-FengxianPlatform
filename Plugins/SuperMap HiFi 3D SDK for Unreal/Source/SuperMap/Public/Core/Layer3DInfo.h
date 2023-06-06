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
				// ��������
				FString m_strMaterialName;

				// �������� - ·��ӳ��
				//! \brief	Key : ԭ��������
				//! \brief	Value :  �����������ƣ�ʡȥ·����
				TMap<FString, FString> m_mapMaterialMappingInfo;
			};

			struct AssociateMaterialInfo
			{
				//! \brief �滻���ʵ�����
				FString AssociateMaterialName;
				//! \brief �滻���ʵ�����·��
				FString AssociateMaterialPath;
				//! \brief �滻���ʵ�ԭʼUV����
				FLinearColor MaterialOriginalUVTiling;
				//! \brief �滻���ʵ�UV����
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
				// ���������޸�ӳ��
				TMap<FString, AssociateMaterialInfo> m_mapMaterialNameChanges;
			};
		}
	}
}