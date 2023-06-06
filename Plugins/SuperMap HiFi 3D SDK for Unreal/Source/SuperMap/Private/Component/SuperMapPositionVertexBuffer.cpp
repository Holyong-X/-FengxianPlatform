// Copyright Epic Games, Inc. All Rights Reserved.

#include "Component/SuperMapPositionVertexBuffer.h"

#include "CoreMinimal.h"
#include "RHI.h"
#include "Components.h"

#include "Component/SuperMapStaticMeshVertexData.h"
#include "GPUSkinCache.h"

/*-----------------------------------------------------------------------------
FSuperMapPositionVertexBuffer
-----------------------------------------------------------------------------*/
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif
/** The implementation of the static mesh position-only vertex data storage type. */
class FSuperMapPositionVertexData :
	public TSuperMapStaticMeshVertexData<FSuperMapPositionVertex>
{
public:
	FSuperMapPositionVertexData(Gamebool InNeedsCPUAccess = false)
		: TSuperMapStaticMeshVertexData<FSuperMapPositionVertex>(InNeedsCPUAccess)
	{
	}
};


FSuperMapPositionVertexBuffer::FSuperMapPositionVertexBuffer() :
	VertexData(NULL),
	Data(NULL),
	Stride(0),
	NumVertices(0)
{}

FSuperMapPositionVertexBuffer::~FSuperMapPositionVertexBuffer()
{
	CleanUp();
}

/** Delete existing resources */
Gamevoid FSuperMapPositionVertexBuffer::CleanUp()
{
	if (VertexData)
	{
		delete VertexData;
		VertexData = nullptr;
	}
}

Gamevoid FSuperMapPositionVertexBuffer::Init(Gameuint InNumVertices, Gamebool bInNeedsCPUAccess)
{
	NumVertices = InNumVertices;
	bNeedsCPUAccess = bInNeedsCPUAccess;

	// Allocate the vertex data storage type.
	AllocateData(bInNeedsCPUAccess);

	// Allocate the vertex data buffer.
	VertexData->ResizeBuffer(NumVertices);
	Data = NumVertices ? VertexData->GetDataPointer() : nullptr;
}

/**
* Initializes the buffer with the given vertices, used to convert legacy layouts.
* @param InVertices - The vertices to initialize the buffer with.
*/
Gamevoid FSuperMapPositionVertexBuffer::Init(const TArray<FStaticMeshBuildVertex>& InVertices, Gamebool bInNeedsCPUAccess)
{
	Init(InVertices.Num(), bInNeedsCPUAccess);

	// Copy the vertices into the buffer.
	for (Gameint VertexIndex = 0;VertexIndex < InVertices.Num();VertexIndex++)
	{
		const FStaticMeshBuildVertex& SourceVertex = InVertices[VertexIndex];
		const Gameuint DestVertexIndex = VertexIndex;
		VertexPosition(DestVertexIndex) = FVector(SourceVertex.Position);
	}
}

/**
* Initializes this vertex buffer with the contents of the given vertex buffer.
* @param InVertexBuffer - The vertex buffer to initialize from.
*/
Gamevoid FSuperMapPositionVertexBuffer::Init(const FSuperMapPositionVertexBuffer& InVertexBuffer, Gamebool bInNeedsCPUAccess)
{
	bNeedsCPUAccess = bInNeedsCPUAccess;
	if (InVertexBuffer.GetNumVertices())
	{
		Init(InVertexBuffer.GetNumVertices(), bInNeedsCPUAccess);

		check(Stride == InVertexBuffer.GetStride());

		const Gameuint8* InData = InVertexBuffer.Data;
		FMemory::Memcpy(Data, InData, Stride * NumVertices);
	}
}

Gamevoid FSuperMapPositionVertexBuffer::Init(const TArray<FVector>& InPositions, Gamebool bInNeedsCPUAccess)
{
	NumVertices = InPositions.Num();
	bNeedsCPUAccess = bInNeedsCPUAccess;
	if (NumVertices)
	{
		AllocateData(bInNeedsCPUAccess);
		check(Stride == InPositions.GetTypeSize());
		VertexData->ResizeBuffer(NumVertices);
		Data = VertexData->GetDataPointer();
		FMemory::Memcpy(Data, InPositions.GetData(), Stride * NumVertices);
	}
}

Gamevoid FSuperMapPositionVertexBuffer::AppendVertices(const FStaticMeshBuildVertex* Vertices, const Gameuint NumVerticesToAppend)
{
	if (VertexData == nullptr && NumVerticesToAppend > 0)
	{
		// Allocate the vertex data storage type if the buffer was never allocated before
		AllocateData(bNeedsCPUAccess);
	}

	if (NumVerticesToAppend > 0)
	{
		check(VertexData != nullptr);
		check(Vertices != nullptr);

		const Gameuint FirstDestVertexIndex = NumVertices;
		NumVertices += NumVerticesToAppend;
		VertexData->ResizeBuffer(NumVertices);
		if (NumVertices > 0)
		{
			Data = VertexData->GetDataPointer();

			// Copy the vertices into the buffer.
			for (Gameuint VertexIter = 0; VertexIter < NumVerticesToAppend; ++VertexIter)
			{
				const FStaticMeshBuildVertex& SourceVertex = Vertices[VertexIter];

				const Gameuint DestVertexIndex = FirstDestVertexIndex + VertexIter;
				VertexPosition(DestVertexIndex) = FVector(SourceVertex.Position);
			}
		}
	}
}

/**
 * Serializer
 *
 * @param	Ar					Archive to serialize with
 * @param	bInNeedsCPUAccess	Whether the elements need to be accessed by the CPU
 */
Gamevoid FSuperMapPositionVertexBuffer::Serialize(FArchive& Ar, Gamebool bInNeedsCPUAccess)
{
	bNeedsCPUAccess = bInNeedsCPUAccess;

	SerializeMetaData(Ar);

	if (Ar.IsLoading())
	{
		// Allocate the vertex data storage type.
		AllocateData(bInNeedsCPUAccess);
	}

	if (VertexData != NULL)
	{
		// Serialize the vertex data.
		VertexData->Serialize(Ar);

		// Make a copy of the vertex data pointer.
		Data = NumVertices ? VertexData->GetDataPointer() : nullptr;
	}
}

Gamevoid FSuperMapPositionVertexBuffer::SerializeMetaData(FArchive& Ar)
{
	Ar << Stride << NumVertices;
}

Gamevoid FSuperMapPositionVertexBuffer::ClearMetaData()
{
	Stride = NumVertices = 0;
}

/**
* Specialized assignment operator, only used when importing LOD's.
*/
Gamevoid FSuperMapPositionVertexBuffer::operator=(const FSuperMapPositionVertexBuffer &Other)
{
	//VertexData doesn't need to be allocated here because Build will be called next,
	VertexData = NULL;
}

template <Gamebool bRenderThread>
FVertexBufferRHIRef FSuperMapPositionVertexBuffer::CreateRHIBuffer_Internal()
{
	if (NumVertices)
	{
		FResourceArrayInterface* RESTRICT ResourceArray = VertexData ? VertexData->GetResourceArray() : nullptr;
		const Gameuint SizeInBytes = ResourceArray ? ResourceArray->GetResourceDataSize() : 0;
#if !SM_FOR_UE_FIVE
		FRHIResourceCreateInfo CreateInfo(ResourceArray);
#else
		TCHAR* InDebugName = TEXT("");
		FRHIResourceCreateInfo CreateInfo(InDebugName, ResourceArray);
#endif
		CreateInfo.bWithoutNativeResource = !VertexData;
		if (bRenderThread)
		{
			return RHICreateVertexBuffer(SizeInBytes, BUF_Static | BUF_ShaderResource, CreateInfo);
		}
		else
		{
			return RHIAsyncCreateVertexBuffer(SizeInBytes, BUF_Static | BUF_ShaderResource, CreateInfo);
		}
	}
	return nullptr;
}

FVertexBufferRHIRef FSuperMapPositionVertexBuffer::CreateRHIBuffer_RenderThread()
{
	return CreateRHIBuffer_Internal<true>();
}

FVertexBufferRHIRef FSuperMapPositionVertexBuffer::CreateRHIBuffer_Async()
{
	return CreateRHIBuffer_Internal<false>();
}

/** Copy everything, keeping reference to the same RHI resources. */
Gamevoid FSuperMapPositionVertexBuffer::CopyRHIForStreaming(const FSuperMapPositionVertexBuffer& Other, Gamebool InAllowCPUAccess)
{
	// Copy serialized properties.
	Stride = Other.Stride;
	NumVertices = Other.NumVertices;

	// Handle CPU access.
	if (InAllowCPUAccess)
	{
		bNeedsCPUAccess = Other.bNeedsCPUAccess;
		AllocateData(bNeedsCPUAccess);
	}
	else
	{
		bNeedsCPUAccess = false;
	}

	// Copy resource references.
	VertexBufferRHI = Other.VertexBufferRHI;
	PositionComponentSRV = Other.PositionComponentSRV;
}

Gamevoid FSuperMapPositionVertexBuffer::InitRHI()
{
	VertexBufferRHI = CreateRHIBuffer_RenderThread();
	// we have decide to create the SRV based on GMaxRHIShaderPlatform because this is created once and shared between feature levels for editor preview.
	// Also check to see whether cpu access has been activated on the vertex data
	if (VertexBufferRHI)
	{
		// we have decide to create the SRV based on GMaxRHIShaderPlatform because this is created once and shared between feature levels for editor preview.
		Gamebool bSRV = RHISupportsManualVertexFetch(GMaxRHIShaderPlatform) || IsGPUSkinCacheAvailable(GMaxRHIShaderPlatform);

		// When bAllowCPUAccess is true, the meshes is likely going to be used for Niagara to spawn particles on mesh surface.
		// And it can be the case for CPU *and* GPU access: no differenciation today. That is why we create a SRV in this case.
		// This also avoid setting lots of states on all the members of all the different buffers used by meshes. Follow up: https://jira.it.epicgames.net/browse/UE-69376.
		bSRV |= (VertexData && VertexData->GetAllowCPUAccess());
		if (bSRV)
		{
			// When VertexData is null, this buffer hasn't been streamed in yet. We still need to create a FRHIShaderResourceView which will be
			// cached in a vertex factory uniform buffer later. The nullptr tells the RHI that the SRV doesn't view on anything yet.
			PositionComponentSRV = RHICreateShaderResourceView(FShaderResourceViewInitializer(VertexData ? VertexBufferRHI : nullptr, PF_R32_FLOAT));
		}
	}
}

Gamevoid FSuperMapPositionVertexBuffer::ReleaseRHI()
{
	PositionComponentSRV.SafeRelease();
	FVertexBuffer::ReleaseRHI();
}

Gamevoid FSuperMapPositionVertexBuffer::AllocateData(Gamebool bInNeedsCPUAccess /*= true*/)
{
	// Clear any old VertexData before allocating.
	CleanUp();

	VertexData = new FSuperMapPositionVertexData(bInNeedsCPUAccess);
	// Calculate the vertex stride.
	Stride = VertexData->GetStride();
}

Gamevoid FSuperMapPositionVertexBuffer::BindPositionVertexBuffer(const FVertexFactory* VertexFactory, FStaticMeshDataType& StaticMeshData) const
{
	StaticMeshData.PositionComponent = FVertexStreamComponent(
		this,
		STRUCT_OFFSET(FPositionVertex, Position),
		GetStride(),
		VET_Float3
	);
	StaticMeshData.PositionComponentSRV = PositionComponentSRV;
}
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif
