// Copyright Epic Games, Inc. All Rights Reserved.

#include "Component/SuperMapStaticMeshVertexBuffer.h"
#include "EngineUtils.h"
#include "Components.h"
#include "GPUSkinCache.h"
#include "ProfilingDebugging/LoadTimeTracker.h"
#include "Component/SuperMapStaticMeshVertexData.h"
#include "Base3D/CommonDefine.h"
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif
FSuperMapStaticMeshVertexBuffer::FSuperMapStaticMeshVertexBuffer() :
	TangentsData(nullptr),
	TexcoordData(nullptr),
	TangentsDataPtr(nullptr),
	TexcoordDataPtr(nullptr),
	NumTexCoords(0),
	NumVertices(0),
	bUseFullPrecisionUVs(!GVertexElementTypeSupport.IsSupported(VET_Half2)),
	bUseHighPrecisionTangentBasis(false)
{}

FSuperMapStaticMeshVertexBuffer::~FSuperMapStaticMeshVertexBuffer()
{
	CleanUp();
}

/** Delete existing resources */
Gamevoid FSuperMapStaticMeshVertexBuffer::CleanUp()
{
	if (TangentsData)
	{
		delete TangentsData;
		TangentsData = nullptr;
	}
	if (TexcoordData)
	{
		delete TexcoordData;
		TexcoordData = nullptr;
	}
}

Gamevoid FSuperMapStaticMeshVertexBuffer::Init(Gameuint InNumVertices, Gameuint InNumTexCoords, Gamebool bNeedsCPUAccess)
{
	NumTexCoords = InNumTexCoords;
	NumVertices = InNumVertices;
	NeedsCPUAccess = bNeedsCPUAccess;

	// Allocate the vertex data storage type.
	AllocateData(bNeedsCPUAccess);

	// Allocate the vertex data buffer.
	TangentsData->ResizeBuffer(NumVertices);
	TangentsDataPtr = NumVertices ? TangentsData->GetDataPointer() : nullptr;
	TexcoordData->ResizeBuffer(NumVertices * GetNumTexCoords());
	TexcoordDataPtr = NumVertices ? TexcoordData->GetDataPointer() : nullptr;
}

/**
* Initializes the buffer with the given vertices.
* @param InVertices - The vertices to initialize the buffer with.
* @param InNumTexCoords - The number of texture coordinate to store in the buffer.
*/
Gamevoid FSuperMapStaticMeshVertexBuffer::Init(const TArray<FStaticMeshBuildVertex>& InVertices, Gameuint InNumTexCoords, Gamebool bNeedsCPUAccess)
{
	Init(InVertices.Num(), InNumTexCoords, bNeedsCPUAccess);

	// Copy the vertices into the buffer.
	for (Gameint VertexIndex = 0; VertexIndex < InVertices.Num(); VertexIndex++)
	{
		const FStaticMeshBuildVertex& SourceVertex = InVertices[VertexIndex];
		const Gameuint DestVertexIndex = VertexIndex;
		SetVertexTangents(DestVertexIndex, FVector(SourceVertex.TangentX), FVector(SourceVertex.TangentY), FVector(SourceVertex.TangentZ));

		for (Gameuint UVIndex = 0; UVIndex < NumTexCoords; UVIndex++)
		{
			SetVertexUV(DestVertexIndex, UVIndex, FVector2D(SourceVertex.UVs[UVIndex]));
		}
	}
}

/**
* Initializes this vertex buffer with the contents of the given vertex buffer.
* @param InVertexBuffer - The vertex buffer to initialize from.
*/
Gamevoid FSuperMapStaticMeshVertexBuffer::Init(const FSuperMapStaticMeshVertexBuffer& InVertexBuffer, Gamebool bNeedsCPUAccess)
{
	NeedsCPUAccess = bNeedsCPUAccess;
	NumTexCoords = InVertexBuffer.GetNumTexCoords();
	NumVertices = InVertexBuffer.GetNumVertices();
	bUseFullPrecisionUVs = InVertexBuffer.GetUseFullPrecisionUVs();
	bUseHighPrecisionTangentBasis = InVertexBuffer.GetUseHighPrecisionTangentBasis();

	if (NumVertices)
	{
		AllocateData(bNeedsCPUAccess);
		{
			check(TangentsData->GetStride() == InVertexBuffer.TangentsData->GetStride());
			TangentsData->ResizeBuffer(NumVertices);
			TangentsDataPtr = TangentsData->GetDataPointer();
			const Gameuint8* InData = InVertexBuffer.TangentsDataPtr;
			FMemory::Memcpy(TangentsDataPtr, InData, TangentsData->GetStride() * NumVertices);
		}
		{
			check(TexcoordData->GetStride() == InVertexBuffer.TexcoordData->GetStride());
			check(GetNumTexCoords() == InVertexBuffer.GetNumTexCoords());
			const Gameuint8* InData = InVertexBuffer.TexcoordDataPtr;

			// convert half float data to full float if the HW requires it.
			if (!GetUseFullPrecisionUVs() && !GVertexElementTypeSupport.IsSupported(VET_Half2))
			{
				ConvertHalfTexcoordsToFloat(InData);
			}
			else
			{
				TexcoordData->ResizeBuffer(NumVertices * GetNumTexCoords());
				TexcoordDataPtr = TexcoordData->GetDataPointer();
				FMemory::Memcpy(TexcoordDataPtr, InData, TexcoordData->GetStride() * NumVertices * GetNumTexCoords());
			}
		}
	}
}

Gamevoid FSuperMapStaticMeshVertexBuffer::ConvertHalfTexcoordsToFloat(const Gameuint8* InData)
{
	check(TexcoordData);
	SetUseFullPrecisionUVs(true);

	FStaticMeshVertexDataInterface* OriginalTexcoordData = TexcoordData;

	typedef TSuperMapStaticMeshVertexUVsDatum<typename TSuperMapStaticMeshVertexUVsTypeSelector<ESuperMapStaticMeshVertexUVType::HighPrecision>::UVsTypeT> UVType;
	TexcoordData = new TSuperMapStaticMeshVertexData<UVType>(OriginalTexcoordData->GetAllowCPUAccess());
	TexcoordData->ResizeBuffer(NumVertices * GetNumTexCoords());
	TexcoordDataPtr = TexcoordData->GetDataPointer();
	TexcoordStride = sizeof(UVType);

	FVector2D* DestTexcoordDataPtr = (FVector2D*)TexcoordDataPtr;
	FVector2DHalf* SourceTexcoordDataPtr = (FVector2DHalf*)(InData ? InData : OriginalTexcoordData->GetDataPointer());
	for (Gameuint i = 0; i < NumVertices * GetNumTexCoords(); i++)
	{
		*DestTexcoordDataPtr++ = *SourceTexcoordDataPtr++;
	}

	delete OriginalTexcoordData;
	OriginalTexcoordData = nullptr;
}


Gamevoid FSuperMapStaticMeshVertexBuffer::AppendVertices(const FStaticMeshBuildVertex* Vertices, const Gameuint NumVerticesToAppend)
{
	if ((TangentsData == nullptr || TexcoordData == nullptr) && NumVerticesToAppend > 0)
	{
		check(NumVertices == 0);
		NumTexCoords = 1;

		// Allocate the vertex data storage type if it has never been allocated before
		AllocateData(NeedsCPUAccess);
	}

	if (NumVerticesToAppend > 0)
	{
		check(Vertices != nullptr);

		const Gameuint FirstDestVertexIndex = NumVertices;
		NumVertices += NumVerticesToAppend;

		TangentsData->ResizeBuffer(NumVertices);
		TexcoordData->ResizeBuffer(NumVertices * GetNumTexCoords());

		if (NumVertices > 0)
		{
			TangentsDataPtr = TangentsData->GetDataPointer();
			TexcoordDataPtr = TexcoordData->GetDataPointer();

			// Copy the vertices into the buffer.
			for (Gameuint VertexIter = 0; VertexIter < NumVerticesToAppend; ++VertexIter)
			{
				const FStaticMeshBuildVertex& SourceVertex = Vertices[VertexIter];

				const Gameuint DestVertexIndex = FirstDestVertexIndex + VertexIter;

				SetVertexTangents(DestVertexIndex, FVector(SourceVertex.TangentX), FVector(SourceVertex.TangentY), FVector(SourceVertex.TangentZ));
				for (Gameuint UVIndex = 0; UVIndex < NumTexCoords; UVIndex++)
				{
					 
					SetVertexUV(DestVertexIndex, UVIndex, FVector2D(SourceVertex.UVs[UVIndex]));
				}
			}
		}
	}
}


/**
* Serializer
*
* @param	Ar				Archive to serialize with
* @param	bNeedsCPUAccess	Whether the elements need to be accessed by the CPU
*/
Gamevoid FSuperMapStaticMeshVertexBuffer::Serialize(FArchive& Ar, Gamebool bNeedsCPUAccess)
{
	NeedsCPUAccess = bNeedsCPUAccess;

	DECLARE_SCOPE_CYCLE_COUNTER(TEXT("FSuperMapStaticMeshVertexBuffer::Serialize"), STAT_StaticMeshVertexBuffer_Serialize, STATGROUP_LoadTime);

	FStripDataFlags StripFlags(Ar, 0, VER_UE4_STATIC_SKELETAL_MESH_SERIALIZATION_FIX);

	SerializeMetaData(Ar);

	if (Ar.IsLoading())
	{
		// Allocate the vertex data storage type.
		AllocateData(bNeedsCPUAccess);
	}

	if (!StripFlags.IsDataStrippedForServer() || Ar.IsCountingMemory())
	{
		if (TangentsData != nullptr)
		{
			// Serialize the vertex data.
			TangentsData->Serialize(Ar);

			// Make a copy of the vertex data pointer.
			TangentsDataPtr = NumVertices ? TangentsData->GetDataPointer() : nullptr;
		}

		if (TexcoordData != nullptr)
		{
			// Serialize the vertex data.
			TexcoordData->Serialize(Ar);

			// Make a copy of the vertex data pointer.
			TexcoordDataPtr = NumVertices ? TexcoordData->GetDataPointer() : nullptr;

			// convert half float data to full float if the HW requires it.
			if (NumVertices && !GetUseFullPrecisionUVs() && !GVertexElementTypeSupport.IsSupported(VET_Half2))
			{
				ConvertHalfTexcoordsToFloat(nullptr);
			}
		}
	}
}

Gamevoid FSuperMapStaticMeshVertexBuffer::SerializeMetaData(FArchive& Ar)
{
	Ar << NumTexCoords << NumVertices;
	Ar << bUseFullPrecisionUVs;
	Ar << bUseHighPrecisionTangentBasis;

	InitTangentAndTexCoordStrides();
}

Gamevoid FSuperMapStaticMeshVertexBuffer::ClearMetaData()
{
	NumTexCoords = NumVertices = 0;
	bUseFullPrecisionUVs = !GVertexElementTypeSupport.IsSupported(VET_Half2);
	bUseHighPrecisionTangentBasis = false;
	TangentsStride = TexcoordStride = 0;
}


/**
* Specialized assignment operator, only used when importing LOD's.
*/
Gamevoid FSuperMapStaticMeshVertexBuffer::operator=(const FSuperMapStaticMeshVertexBuffer &Other)
{
	//VertexData doesn't need to be allocated here because Build will be called next,
	CleanUp();
	bUseFullPrecisionUVs = Other.bUseFullPrecisionUVs;
	bUseHighPrecisionTangentBasis = Other.bUseHighPrecisionTangentBasis;
}

template <Gamebool bRenderThread>
FVertexBufferRHIRef FSuperMapStaticMeshVertexBuffer::CreateTangentsRHIBuffer_Internal()
{
	if (GetNumVertices())
	{
		FResourceArrayInterface* RESTRICT ResourceArray = TangentsData ? TangentsData->GetResourceArray() : nullptr;
		const Gameuint SizeInBytes = ResourceArray ? ResourceArray->GetResourceDataSize() : 0;
#if !SM_FOR_UE_FIVE
		FRHIResourceCreateInfo CreateInfo(ResourceArray);
#else
		TCHAR* InDebugName = TEXT("");
		FRHIResourceCreateInfo CreateInfo(InDebugName, ResourceArray);
#endif
		CreateInfo.bWithoutNativeResource = !TangentsData;
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

FVertexBufferRHIRef FSuperMapStaticMeshVertexBuffer::CreateTangentsRHIBuffer_RenderThread()
{
	return CreateTangentsRHIBuffer_Internal<true>();
}

FVertexBufferRHIRef FSuperMapStaticMeshVertexBuffer::CreateTangentsRHIBuffer_Async()
{
	return CreateTangentsRHIBuffer_Internal<false>();
}

template <Gamebool bRenderThread>
FVertexBufferRHIRef FSuperMapStaticMeshVertexBuffer::CreateTexCoordRHIBuffer_Internal()
{
	if (GetNumTexCoords())
	{
		FResourceArrayInterface* RESTRICT ResourceArray = TexcoordData ? TexcoordData->GetResourceArray() : nullptr;
		const Gameuint SizeInBytes = ResourceArray ? ResourceArray->GetResourceDataSize() : 0;
#if !SM_FOR_UE_FIVE
		FRHIResourceCreateInfo CreateInfo(ResourceArray);
#else
		TCHAR* InDebugName = TEXT("");
		FRHIResourceCreateInfo CreateInfo(InDebugName, ResourceArray);
#endif
		CreateInfo.bWithoutNativeResource = !TexcoordData;
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

FVertexBufferRHIRef FSuperMapStaticMeshVertexBuffer::CreateTexCoordRHIBuffer_RenderThread()
{
	return CreateTexCoordRHIBuffer_Internal<true>();
}

FVertexBufferRHIRef FSuperMapStaticMeshVertexBuffer::CreateTexCoordRHIBuffer_Async()
{
	return CreateTexCoordRHIBuffer_Internal<false>();
}

Gamevoid FSuperMapStaticMeshVertexBuffer::CopyRHIForStreaming(const FSuperMapStaticMeshVertexBuffer& Other, Gamebool InAllowCPUAccess)
{
	// Copy serialized properties.
	TangentsStride = Other.TangentsStride;
	TexcoordStride = Other.TexcoordStride;
	NumTexCoords = Other.NumTexCoords;
	NumVertices = Other.NumVertices;
	bUseFullPrecisionUVs = Other.bUseFullPrecisionUVs;
	bUseHighPrecisionTangentBasis = Other.bUseHighPrecisionTangentBasis;

	// Handle CPU access.
	if (InAllowCPUAccess)
	{
		NeedsCPUAccess = Other.NeedsCPUAccess;
		AllocateData(NeedsCPUAccess);
	}
	else
	{
		NeedsCPUAccess = false;
	}

	// Copy resource references.
	TangentsVertexBuffer.VertexBufferRHI = Other.TangentsVertexBuffer.VertexBufferRHI;
	TexCoordVertexBuffer.VertexBufferRHI = Other.TexCoordVertexBuffer.VertexBufferRHI;
	TangentsSRV = Other.TangentsSRV;
	TextureCoordinatesSRV = Other.TextureCoordinatesSRV;
}

Gamevoid FSuperMapStaticMeshVertexBuffer::InitRHI()
{
	//SCOPED_LOADTIMER(FStaticMeshVertexBuffer_InitRHI);

	TangentsVertexBuffer.VertexBufferRHI = CreateTangentsRHIBuffer_RenderThread();
	TexCoordVertexBuffer.VertexBufferRHI = CreateTexCoordRHIBuffer_RenderThread();
	if (TangentsVertexBuffer.VertexBufferRHI && (RHISupportsManualVertexFetch(GMaxRHIShaderPlatform) || IsGPUSkinCacheAvailable(GMaxRHIShaderPlatform)))
	{
		// When TangentsData is null, this buffer hasn't been streamed in yet. We still need to create a FRHIShaderResourceView which will be
		// cached in a vertex factory uniform buffer later. The nullptr tells the RHI that the SRV doesn't view on anything yet.
		TangentsSRV = RHICreateShaderResourceView(FShaderResourceViewInitializer(
			TangentsData ? TangentsVertexBuffer.VertexBufferRHI : nullptr,
			GetUseHighPrecisionTangentBasis() ? PF_R16G16B16A16_SNORM : PF_R8G8B8A8_SNORM));
	}
	if (TexCoordVertexBuffer.VertexBufferRHI && RHISupportsManualVertexFetch(GMaxRHIShaderPlatform))
	{
		// When TexcoordData is null, this buffer hasn't been streamed in yet. We still need to create a FRHIShaderResourceView which will be
		// cached in a vertex factory uniform buffer later. The nullptr tells the RHI that the SRV doesn't view on anything yet.
		TextureCoordinatesSRV = RHICreateShaderResourceView(FShaderResourceViewInitializer(
			TexcoordData ? TexCoordVertexBuffer.VertexBufferRHI : nullptr,
			GetUseFullPrecisionUVs() ? PF_G32R32F : PF_G16R16F));
	}
}

Gamevoid FSuperMapStaticMeshVertexBuffer::ReleaseRHI()
{
	TangentsSRV.SafeRelease();
	TextureCoordinatesSRV.SafeRelease();
	TangentsVertexBuffer.ReleaseRHI();
	TexCoordVertexBuffer.ReleaseRHI();
}

Gamevoid FSuperMapStaticMeshVertexBuffer::InitResource()
{
	FRenderResource::InitResource();
	TangentsVertexBuffer.InitResource();
	TexCoordVertexBuffer.InitResource();
}

Gamevoid FSuperMapStaticMeshVertexBuffer::ReleaseResource()
{
	FRenderResource::ReleaseResource();
	TangentsVertexBuffer.ReleaseResource();
	TexCoordVertexBuffer.ReleaseResource();
}

Gamevoid FSuperMapStaticMeshVertexBuffer::AllocateData(Gamebool bNeedsCPUAccess /*= true*/)
{
	// Clear any old VertexData before allocating.
	CleanUp();

	Gameuint VertexStride = 0;
	if (GetUseHighPrecisionTangentBasis())
	{
		typedef TSuperMapStaticMeshVertexTangentDatum<typename TSuperMapStaticMeshVertexTangentTypeSelector<ESuperMapStaticMeshVertexTangentBasisType::HighPrecision>::TangentTypeT> TangentType;
		TangentsStride = sizeof(TangentType);
		TangentsData = new TSuperMapStaticMeshVertexData<TangentType>(bNeedsCPUAccess);
	}
	else
	{
		typedef TSuperMapStaticMeshVertexTangentDatum<typename TSuperMapStaticMeshVertexTangentTypeSelector<ESuperMapStaticMeshVertexTangentBasisType::Default>::TangentTypeT> TangentType;
		TangentsStride = sizeof(TangentType);
		TangentsData = new TSuperMapStaticMeshVertexData<TangentType>(bNeedsCPUAccess);
	}

	if (GetUseFullPrecisionUVs())
	{
		typedef TSuperMapStaticMeshVertexUVsDatum<typename TSuperMapStaticMeshVertexUVsTypeSelector<ESuperMapStaticMeshVertexUVType::HighPrecision>::UVsTypeT> UVType;
		TexcoordStride = sizeof(UVType);
		TexcoordData = new TSuperMapStaticMeshVertexData<UVType>(bNeedsCPUAccess);
	}
	else
	{
		typedef TSuperMapStaticMeshVertexUVsDatum<typename TSuperMapStaticMeshVertexUVsTypeSelector<ESuperMapStaticMeshVertexUVType::Default>::UVsTypeT> UVType;
		TexcoordStride = sizeof(UVType);
		TexcoordData = new TSuperMapStaticMeshVertexData<UVType>(bNeedsCPUAccess);
	}
}

int FSuperMapStaticMeshVertexBuffer::GetTangentSize()
{
	if (GetUseHighPrecisionTangentBasis())
	{
		typedef TSuperMapStaticMeshVertexTangentDatum<typename TSuperMapStaticMeshVertexTangentTypeSelector<ESuperMapStaticMeshVertexTangentBasisType::HighPrecision>::TangentTypeT> TangentType;
		TangentsStride = sizeof(TangentType);
		return TangentsStride * GetNumVertices();
	}
	else
	{
		typedef TSuperMapStaticMeshVertexTangentDatum<typename TSuperMapStaticMeshVertexTangentTypeSelector<ESuperMapStaticMeshVertexTangentBasisType::Default>::TangentTypeT> TangentType;
		TangentsStride = sizeof(TangentType);
		return TangentsStride * GetNumVertices();
	}
}

int FSuperMapStaticMeshVertexBuffer::GetTexCoordSize()
{
	if (GetUseFullPrecisionUVs())
	{
		typedef TSuperMapStaticMeshVertexUVsDatum<typename TSuperMapStaticMeshVertexUVsTypeSelector<ESuperMapStaticMeshVertexUVType::HighPrecision>::UVsTypeT> UVType;
		TexcoordStride = sizeof(UVType);
		return TexcoordStride * GetNumTexCoords() * GetNumVertices();
	}
	else
	{
		typedef TSuperMapStaticMeshVertexUVsDatum<typename TSuperMapStaticMeshVertexUVsTypeSelector<ESuperMapStaticMeshVertexUVType::Default>::UVsTypeT> UVType;
		TexcoordStride = sizeof(UVType);
		return TexcoordStride * GetNumTexCoords() * GetNumVertices();
	}
}

Gamevoid FSuperMapStaticMeshVertexBuffer::InitTangentAndTexCoordStrides()
{
	typedef TSuperMapStaticMeshVertexTangentDatum<typename TSuperMapStaticMeshVertexTangentTypeSelector<ESuperMapStaticMeshVertexTangentBasisType::HighPrecision>::TangentTypeT> HighPrecTangentType;
	typedef TSuperMapStaticMeshVertexTangentDatum<typename TSuperMapStaticMeshVertexTangentTypeSelector<ESuperMapStaticMeshVertexTangentBasisType::Default>::TangentTypeT> DefaultTangentType;
	typedef TSuperMapStaticMeshVertexUVsDatum<typename TSuperMapStaticMeshVertexUVsTypeSelector<ESuperMapStaticMeshVertexUVType::HighPrecision>::UVsTypeT> HighPrecUVType;
	typedef TSuperMapStaticMeshVertexUVsDatum<typename TSuperMapStaticMeshVertexUVsTypeSelector<ESuperMapStaticMeshVertexUVType::Default>::UVsTypeT> DefaultUVType;

	TangentsStride = GetUseHighPrecisionTangentBasis() ? sizeof(HighPrecTangentType) : sizeof(DefaultTangentType);
	TexcoordStride = GetUseFullPrecisionUVs() ? sizeof(HighPrecUVType) : sizeof(DefaultUVType);
}

Gamevoid FSuperMapStaticMeshVertexBuffer::BindTangentVertexBuffer(const FVertexFactory* VertexFactory, FStaticMeshDataType& Data) const
{
	{
		Data.TangentsSRV = TangentsSRV;
	}

	{
		Gameuint TangentSizeInBytes = 0;
		Gameuint TangentXOffset = 0;
		Gameuint TangentZOffset = 0;
		EVertexElementType TangentElemType = VET_None;

		if (GetUseHighPrecisionTangentBasis())
		{
			typedef TSuperMapStaticMeshVertexTangentDatum<typename TSuperMapStaticMeshVertexTangentTypeSelector<ESuperMapStaticMeshVertexTangentBasisType::HighPrecision>::TangentTypeT> TangentType;
			TangentElemType = TSuperMapStaticMeshVertexTangentTypeSelector<ESuperMapStaticMeshVertexTangentBasisType::HighPrecision>::VertexElementType;
			TangentXOffset = STRUCT_OFFSET(TangentType, TangentX);
			TangentZOffset = STRUCT_OFFSET(TangentType, TangentZ);
			TangentSizeInBytes = sizeof(TangentType);

		}
		else
		{
			typedef TSuperMapStaticMeshVertexTangentDatum<typename TSuperMapStaticMeshVertexTangentTypeSelector<ESuperMapStaticMeshVertexTangentBasisType::Default>::TangentTypeT> TangentType;
			TangentElemType = TSuperMapStaticMeshVertexTangentTypeSelector<ESuperMapStaticMeshVertexTangentBasisType::Default>::VertexElementType;
			TangentXOffset = STRUCT_OFFSET(TangentType, TangentX);
			TangentZOffset = STRUCT_OFFSET(TangentType, TangentZ);
			TangentSizeInBytes = sizeof(TangentType);
		}

		Data.TangentBasisComponents[0] = FVertexStreamComponent(
			&TangentsVertexBuffer,
			TangentXOffset,
			TangentSizeInBytes,
			TangentElemType,
			EVertexStreamUsage::ManualFetch
		);

		Data.TangentBasisComponents[1] = FVertexStreamComponent(
			&TangentsVertexBuffer,
			TangentZOffset,
			TangentSizeInBytes,
			TangentElemType,
			EVertexStreamUsage::ManualFetch
		);
	}
}

Gamevoid FSuperMapStaticMeshVertexBuffer::BindPackedTexCoordVertexBuffer(const FVertexFactory* VertexFactory, FStaticMeshDataType& Data) const
{
	Data.TextureCoordinates.Empty();
	Data.NumTexCoords = GetNumTexCoords();

	{
		Data.TextureCoordinatesSRV = TextureCoordinatesSRV;
	}

	{
		EVertexElementType UVDoubleWideVertexElementType = VET_None;
		EVertexElementType UVVertexElementType = VET_None;
		Gameuint UVSizeInBytes = 0;
		if (GetUseFullPrecisionUVs())
		{
			UVSizeInBytes = sizeof(TSuperMapStaticMeshVertexUVsTypeSelector<ESuperMapStaticMeshVertexUVType::HighPrecision>::UVsTypeT);
			UVDoubleWideVertexElementType = VET_Float4;
			UVVertexElementType = VET_Float2;
		}
		else
		{
			UVSizeInBytes = sizeof(TSuperMapStaticMeshVertexUVsTypeSelector<ESuperMapStaticMeshVertexUVType::Default>::UVsTypeT);
			UVDoubleWideVertexElementType = VET_Half4;
			UVVertexElementType = VET_Half2;
		}

		Gameuint UvStride = UVSizeInBytes * GetNumTexCoords();

		Gameint UVIndex;
		for (UVIndex = 0; UVIndex < (Gameint)GetNumTexCoords() - 1; UVIndex += 2)
		{
			Data.TextureCoordinates.Add(FVertexStreamComponent(
				&TexCoordVertexBuffer,
				UVSizeInBytes * UVIndex,
				UvStride,
				UVDoubleWideVertexElementType,
				EVertexStreamUsage::ManualFetch
			));
		}

		// possible last UV channel if we have an odd number
		if (UVIndex < (Gameint)GetNumTexCoords())
		{
			Data.TextureCoordinates.Add(FVertexStreamComponent(
				&TexCoordVertexBuffer,
				UVSizeInBytes * UVIndex,
				UvStride,
				UVVertexElementType,
				EVertexStreamUsage::ManualFetch
			));
		}
	}
}

Gamevoid FSuperMapStaticMeshVertexBuffer::BindTexCoordVertexBuffer(const FVertexFactory* VertexFactory, FStaticMeshDataType& Data, int ClampedNumTexCoords) const
{
	Data.TextureCoordinates.Empty();
	Data.NumTexCoords = GetNumTexCoords();

	{
		Data.TextureCoordinatesSRV = TextureCoordinatesSRV;
	}

	{
		EVertexElementType UVVertexElementType = VET_None;
		Gameuint UVSizeInBytes = 0;

		if (GetUseFullPrecisionUVs())
		{
			UVSizeInBytes = sizeof(TSuperMapStaticMeshVertexUVsTypeSelector<ESuperMapStaticMeshVertexUVType::HighPrecision>::UVsTypeT);
			UVVertexElementType = VET_Float2;
		}
		else
		{
			UVSizeInBytes = sizeof(TSuperMapStaticMeshVertexUVsTypeSelector<ESuperMapStaticMeshVertexUVType::Default>::UVsTypeT);
			UVVertexElementType = VET_Half2;
		}

		Gameuint UvStride = UVSizeInBytes * GetNumTexCoords();

		if (ClampedNumTexCoords > -1)
		{
			ClampedNumTexCoords = FMath::Min<Gameuint>(GetNumTexCoords(), MAX_TEXCOORDS);
		}
		else
		{
			ClampedNumTexCoords = GetNumTexCoords();
		}

		check(ClampedNumTexCoords >= 0);

		for (Gameuint UVIndex = 0; UVIndex < (Gameuint)ClampedNumTexCoords; UVIndex++)
		{
			Data.TextureCoordinates.Add(FVertexStreamComponent(
				&TexCoordVertexBuffer,
				UVSizeInBytes * UVIndex,
				UvStride,
				UVVertexElementType,
				EVertexStreamUsage::ManualFetch
			));
		}
	}
}

Gamevoid FSuperMapStaticMeshVertexBuffer::BindLightMapVertexBuffer(const FVertexFactory* VertexFactory, FStaticMeshDataType& Data, int LightMapCoordinateIndex) const
{
	LightMapCoordinateIndex = LightMapCoordinateIndex < (Gameint)GetNumTexCoords() ? LightMapCoordinateIndex : (Gameint)GetNumTexCoords() - 1;
	check(LightMapCoordinateIndex >= 0);

	Data.LightMapCoordinateIndex = LightMapCoordinateIndex;
	Data.NumTexCoords = GetNumTexCoords();

	{
		Data.TextureCoordinatesSRV = TextureCoordinatesSRV;
	}

	{
		EVertexElementType UVVertexElementType = VET_None;
		Gameuint UVSizeInBytes = 0;

		if (GetUseFullPrecisionUVs())
		{
			UVSizeInBytes = sizeof(TSuperMapStaticMeshVertexUVsTypeSelector<ESuperMapStaticMeshVertexUVType::HighPrecision>::UVsTypeT);
			UVVertexElementType = VET_Float2;
		}
		else
		{
			UVSizeInBytes = sizeof(TSuperMapStaticMeshVertexUVsTypeSelector<ESuperMapStaticMeshVertexUVType::Default>::UVsTypeT);
			UVVertexElementType = VET_Half2;
		}

		Gameuint UvStride = UVSizeInBytes * GetNumTexCoords();

		if (LightMapCoordinateIndex >= 0 && (Gameuint)LightMapCoordinateIndex < GetNumTexCoords())
		{
			Data.LightMapCoordinateComponent = FVertexStreamComponent(
				&TexCoordVertexBuffer,
				UVSizeInBytes * LightMapCoordinateIndex,
				UvStride,
				UVVertexElementType,
				EVertexStreamUsage::ManualFetch
			);
		}
	}
}
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif