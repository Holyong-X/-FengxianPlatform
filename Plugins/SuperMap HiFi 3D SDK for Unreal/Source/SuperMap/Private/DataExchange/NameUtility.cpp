// Copyright Epic Games, Inc. All Rights Reserved.
//#if (!SM_FOR_UE_FIVE && WITH_EDITOR)
#ifdef BUILD_EDITOR
#include "DataExchange/NameUtility.h"
#include "Animation/SkeletalMeshActor.h"
#include "Engine.h"
#include <string>

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace DataExchange
		{
			namespace
			{
				template <typename ActorType>
				FString GetActorNameIfOwnerOfType(const UActorComponent* Component)
				{
					if (const ActorType* Owner = Cast<ActorType>(Component->GetOwner()))
					{
						return Owner->GetName();
					}

					return Component->GetName();
				}
			}

			FString FNameUtility::GetName(const USceneComponent* Component)
			{
				if (const AActor* Owner = Component->GetOwner())
				{
					return Owner->GetName() + TEXT("_") + Component->GetName();
				}

				return Component->GetName();
			}

			FString FNameUtility::GetName(const UStaticMeshComponent* Component)
			{
				return GetActorNameIfOwnerOfType<AStaticMeshActor>(Component);
			}

			FString FNameUtility::GetName(const USkeletalMeshComponent* Component)
			{
				return GetActorNameIfOwnerOfType<ASkeletalMeshActor>(Component);
			}

			FString FNameUtility::GetName(const ULightComponent* Component)
			{
				return GetActorNameIfOwnerOfType<ALight>(Component);
			}

			FString FNameUtility::GetName(const UCameraComponent* Component)
			{
				return GetActorNameIfOwnerOfType<ACameraActor>(Component);
			}

			char* FNameUtility::FStringToChar(const FString& fStr)
			{
				std::string strTmp = TCHAR_TO_UTF8(*fStr);
				char* pChar = new char[strTmp.size()];
				FMemory::Memcpy(pChar, strTmp.c_str(), strTmp.size());
				return pChar;
			}
		}
	}
}
#endif