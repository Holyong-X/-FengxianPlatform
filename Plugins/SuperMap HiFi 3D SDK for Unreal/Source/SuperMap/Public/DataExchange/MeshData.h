// Copyright Epic Games, Inc. All Rights Reserved.
//#if (!SM_FOR_UE_FIVE && WITH_EDITOR)
#ifdef BUILD_EDITOR
#pragma once

#include "CoreMinimal.h"
#include "MeshDescription.h"
#if WITH_EDITOR
// TODO: remove dependency to GLTFMaterialBaking in public header
#include "MaterialBakingStructures.h"
#endif

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace DataExchange
		{
			struct FUeMeshData
			{
				FUeMeshData(const UStaticMesh* StaticMesh, const UStaticMeshComponent* StaticMeshComponent, int32 LODIndex);
				FUeMeshData(const USkeletalMesh* SkeletalMesh, const USkeletalMeshComponent* SkeletalMeshComponent, int32 LODIndex);

				const FUeMeshData* GetParent() const;

				FString Name;
				int32 LODIndex;

#if WITH_EDITOR
				FPrimitiveData PrimitiveData;
				FMeshDescription Description;

				FLightMapRef LightMap;
				const FLightmapResourceCluster* LightMapResourceCluster;
				int32 LightMapTexCoord;

				int32 BakeUsingTexCoord;
#endif

				// TODO: find a better name for referencing the mesh-only data (no component)
				const FUeMeshData* Parent;
			};
		}
	}
}
#endif
