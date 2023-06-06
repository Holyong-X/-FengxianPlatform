// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
//#if (!SM_FOR_UE_FIVE && WITH_EDITOR)
#ifdef BUILD_EDITOR
#include "CoreMinimal.h"

class ULightComponent;
class UCameraComponent;
//class AGLTFHotspotActor;

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace DataExchange
		{
			struct FNameUtility
			{
				template <typename EnumType, typename = typename TEnableIf<TIsEnum<EnumType>::Value>::Type>
				static FString GetName(EnumType Value)
				{
					const UEnum* Enum = StaticEnum<EnumType>();
					check(Enum != nullptr);
					const FString DisplayName = Enum->GetDisplayNameTextByValue(Value).ToString();
					return DisplayName.IsEmpty() ? FString::FromInt(static_cast<int32>(Value)) : DisplayName;
				}

				static FString GetName(const USceneComponent* Component);

				static FString GetName(const UStaticMeshComponent* Component);
				static FString GetName(const USkeletalMeshComponent* Component);
				static FString GetName(const ULightComponent* Component);
				static FString GetName(const UCameraComponent* Component);

				static char* FStringToChar(const FString& fStr);
			};
		}
	}
}
#endif