// Copyright Epic Games, Inc. All Rights Reserved.

#include "Component/SuperMapColorVertexBuffer.h"
#include "Component/SuperMapStaticMeshVertexData.h"
#include "CoreMinimal.h"
#include "RHI.h"
#include "Components.h"
#include "EngineUtils.h"
#include "ProfilingDebugging/LoadTimeTracker.h"

/*-----------------------------------------------------------------------------
FSuperMapColorVertexBuffer
-----------------------------------------------------------------------------*/
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif
/** The implementation of the static mesh color-only vertex data storage type. */
class FSuperMapColorVertexData :
	public TSuperMapStaticMeshVertexData<FColor>
{
public:
	FSuperMapColorVertexData(Gamebool InNeedsCPUAccess = false)
		: TSuperMapStaticMeshVertexData<FColor>(InNeedsCPUAccess)
	{
	}
};


FSuperMapColorVertexBuffer::FSuperMapColorVertexBuffer() :
	VertexData(NULL),
	Data(NULL),
	Stride(0),
	NumVertices(0)
{
}

FSuperMapColorVertexBuffer::FSuperMapColorVertexBuffer(const FSuperMapColorVertexBuffer &rhs) :
	VertexData(NULL),
	Data(NULL),
	Stride(0),
	NumVertices(0)
{
	if (rhs.VertexData)
	{
		InitFromColorArray(reinterpret_cast<FColor*>(rhs.VertexData->GetDataPointer()), rhs.VertexData->Num());
	}
	else
	{
		CleanUp();
	}
}

FSuperMapColorVertexBuffer::~FSuperMapColorVertexBuffer()
{
	CleanUp();
}

/** Delete existing resources */
Gamevoid FSuperMapColorVertexBuffer::CleanUp()
{
	if (VertexData)
	{
		delete VertexData;
		VertexData = NULL;
	}
}

Gamevoid FSuperMapColorVertexBuffer::Init(Gameuint InNumVertices, Gamebool bNeedsCPUAccess)
{
	NumVertices = InNumVertices;
	NeedsCPUAccess = bNeedsCPUAccess;

	// Allocate the vertex data storage type.
	AllocateData(bNeedsCPUAccess);

	// Allocate the vertex data buffer.
	VertexData->ResizeBuffer(NumVertices);
	Data = InNumVertices ? VertexData->GetDataPointer() : nullptr;
}

/**
* Initializes the buffer with the given vertices, used to convert legacy layouts.
* @param InVertices - The vertices to initialize the buffer with.
*/
Gamevoid FSuperMapColorVertexBuffer::Init(const TArray<FStaticMeshBuildVertex>& InVertices, Gamebool bNeedsCPUAccess)
{
	// First, make sure that there is at least one non-default vertex color in the original data.
	const Gameint InVertexCount = InVertices.Num();
	NeedsCPUAccess = bNeedsCPUAccess;
	Gamebool bAllColorsAreOpaqueWhite = true;
	Gamebool bAllColorsAreEqual = true;

	if (InVertexCount > 0)
	{
		const FColor FirstColor = InVertices[0].Color;

		for (Gameint CurVertexIndex = 0; CurVertexIndex < InVertexCount; ++CurVertexIndex)
		{
			const FColor CurColor = InVertices[CurVertexIndex].Color;

			if (CurColor.R != 255 || CurColor.G != 255 || CurColor.B != 255 || CurColor.A != 255)
			{
				bAllColorsAreOpaqueWhite = false;
			}

			if (CurColor.R != FirstColor.R || CurColor.G != FirstColor.G || CurColor.B != FirstColor.B || CurColor.A != FirstColor.A)
			{
				bAllColorsAreEqual = false;
			}

			if (!bAllColorsAreEqual && !bAllColorsAreOpaqueWhite)
			{
				break;
			}
		}
	}

	if (bAllColorsAreOpaqueWhite)
	{
		// Ensure no vertex data is allocated.
		CleanUp();

		// Clear the vertex count and stride.
		Stride = 0;
		NumVertices = 0;
	}
	else
	{
		Init(InVertexCount, bNeedsCPUAccess);

		// Copy the vertices into the buffer.
		for (Gameint VertexIndex = 0;VertexIndex < InVertices.Num();VertexIndex++)
		{
			const FStaticMeshBuildVertex& SourceVertex = InVertices[VertexIndex];
			const Gameuint DestVertexIndex = VertexIndex;
			VertexColor(DestVertexIndex) = SourceVertex.Color;
		}
	}
}

/**
* Initializes this vertex buffer with the contents of the given vertex buffer.
* @param InVertexBuffer - The vertex buffer to initialize from.
*/
Gamevoid FSuperMapColorVertexBuffer::Init(const FSuperMapColorVertexBuffer& InVertexBuffer, Gamebool bNeedsCPUAccess)
{
	NeedsCPUAccess = bNeedsCPUAccess;
	if (NumVertices)
	{
		Init(InVertexBuffer.GetNumVertices(), bNeedsCPUAccess);
		const Gameuint8* InData = InVertexBuffer.Data;
		FMemory::Memcpy(Data, InData, Stride * NumVertices);
	}
}

Gamevoid FSuperMapColorVertexBuffer::AppendVertices(const FStaticMeshBuildVertex* Vertices, const Gameuint NumVerticesToAppend)
{
	if (VertexData == nullptr && NumVerticesToAppend > 0)
	{
		check(NumVertices == 0);

		// Allocate the vertex data storage type if the buffer was never allocated before
		AllocateData(NeedsCPUAccess);
	}

	if (NumVerticesToAppend > 0)
	{
		// @todo: check if all opaque white, and if so append nothing

		check(VertexData != nullptr);	// Must only be called after Init() has already initialized the buffer!
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
				VertexColor(DestVertexIndex) = SourceVertex.Color;
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
Gamevoid FSuperMapColorVertexBuffer::Serialize(FArchive& Ar, Gamebool bNeedsCPUAccess)
{
	NeedsCPUAccess = bNeedsCPUAccess;
	FStripDataFlags StripFlags(Ar, 0, VER_UE4_STATIC_SKELETAL_MESH_SERIALIZATION_FIX);

	if (Ar.IsSaving() && NumVertices > 0 && VertexData == NULL)
	{
		// ...serialize as if the vertex count were zero. Else on load serialization breaks.
		// This situation should never occur because VertexData should not be null if NumVertices
		// is greater than zero. So really this should be a checkf but I don't want to crash
		// the Editor when saving a package.
		UE_LOG(LogStaticMesh, Warning, TEXT("Color vertex buffer being saved with NumVertices=%d Stride=%d VertexData=NULL. This should never happen."),
			NumVertices, Stride);

		Gameint SerializedStride = 0;
		Gameint SerializedNumVertices = 0;
		Ar << SerializedStride << SerializedNumVertices;
	}
	else
	{
		SerializeMetaData(Ar);

		if (Ar.IsLoading() && NumVertices > 0)
		{
			// Allocate the vertex data storage type.
			AllocateData(bNeedsCPUAccess);
		}

		if (!StripFlags.IsDataStrippedForServer() || Ar.IsCountingMemory())
		{
			if (VertexData != NULL)
			{
				// Serialize the vertex data.
				VertexData->Serialize(Ar);

				if (VertexData->Num() > 0)
				{
					// Make a copy of the vertex data pointer.
					Data = VertexData->GetDataPointer();
				}
			}
		}
	}
}

Gamevoid FSuperMapColorVertexBuffer::SerializeMetaData(FArchive& Ar)
{
	Ar << Stride << NumVertices;
}

Gamevoid FSuperMapColorVertexBuffer::ClearMetaData()
{
	Stride = NumVertices = 0;
}


/** Export the data to a string, used for editor Copy&Paste. */
Gamevoid FSuperMapColorVertexBuffer::ExportText(FString &ValueStr) const
{
	// the following code only works if there is data and this method should only be called if there is data
	check(NumVertices);

	ValueStr += FString::Printf(TEXT("ColorVertexData(%i)=("), NumVertices);

	// 9 characters per color (ARGB in hex plus comma)
	ValueStr.Reserve(ValueStr.Len() + NumVertices * 9);

	for (Gameuint i = 0; i < NumVertices; ++i)
	{
		Gameuint Raw = VertexColor(i).DWColor();
		// does not handle endianess	
		// order: ARGB
		TCHAR ColorString[10];

		// does not use FString::Printf for performance reasons
		FCString::Sprintf(ColorString, TEXT("%.8x,"), Raw);
		ValueStr += ColorString;
	}

	// replace , by )
	ValueStr[ValueStr.Len() - 1] = ')';
}



/** Export the data from a string, used for editor Copy&Paste. */
Gamevoid FSuperMapColorVertexBuffer::ImportText(const TCHAR* SourceText)
{
	check(SourceText);
	check(!VertexData);

	Gameuint VertexCount;

	if (FParse::Value(SourceText, TEXT("ColorVertexData("), VertexCount))
	{
		while (*SourceText && *SourceText != TEXT(')'))
		{
			++SourceText;
		}

		while (*SourceText && *SourceText != TEXT('('))
		{
			++SourceText;
		}

		check(*SourceText == TEXT('('));
		++SourceText;

		NumVertices = VertexCount;
		AllocateData(NeedsCPUAccess);
		VertexData->ResizeBuffer(NumVertices);
		Gameuint8 *Dst = (Gameuint8 *)VertexData->GetDataPointer();

		// 9 characters per color (ARGB in hex plus comma)
		for (Gameuint i = 0; i < NumVertices; ++i)
		{
			// does not handle endianess or malformed input
			*Dst++ = FParse::HexDigit(SourceText[6]) * 16 + FParse::HexDigit(SourceText[7]);
			*Dst++ = FParse::HexDigit(SourceText[4]) * 16 + FParse::HexDigit(SourceText[5]);
			*Dst++ = FParse::HexDigit(SourceText[2]) * 16 + FParse::HexDigit(SourceText[3]);
			*Dst++ = FParse::HexDigit(SourceText[0]) * 16 + FParse::HexDigit(SourceText[1]);
			SourceText += 9;
		}
		check(*(SourceText - 1) == TCHAR(')'));

		// Make a copy of the vertex data pointer.
		Data = VertexData->GetDataPointer();

		BeginInitResource(this);
	}
}

/**
* Specialized assignment operator, only used when importing LOD's.
*/
Gamevoid FSuperMapColorVertexBuffer::operator=(const FSuperMapColorVertexBuffer &Other)
{
	//VertexData doesn't need to be allocated here because Build will be called next,
	delete VertexData;
	VertexData = NULL;
}

Gamevoid FSuperMapColorVertexBuffer::GetVertexColors(TArray<FColor>& OutColors) const
{
	if (VertexData != NULL && NumVertices > 0)
	{
		OutColors.SetNumUninitialized(NumVertices);

		FMemory::Memcpy(OutColors.GetData(), VertexData->GetDataPointer(), NumVertices * VertexData->GetStride());
	}
}

/** Load from raw color array */
Gamevoid FSuperMapColorVertexBuffer::InitFromColorArray(const FColor *InColors, const Gameuint Count, const Gameuint InStride, Gamebool bNeedsCPUAccess)
{
	check(Count > 0);

	NumVertices = Count;
	NeedsCPUAccess = bNeedsCPUAccess;

	// Allocate the vertex data storage type.
	AllocateData(bNeedsCPUAccess);

	// Copy the colors
	{
		VertexData->ResizeBuffer(Count);

		const Gameuint8 *Src = (const Gameuint8 *)InColors;
		FColor *Dst = (FColor *)VertexData->GetDataPointer();

		for (Gameuint i = 0; i < Count; ++i)
		{
			*Dst++ = *(const FColor*)Src;

			Src += InStride;
		}
	}

	// Make a copy of the vertex data pointer.
	Data = VertexData->GetDataPointer();
}

Gameuint FSuperMapColorVertexBuffer::GetAllocatedSize() const
{
	if (VertexData)
	{
		return VertexData->GetResourceSize();
	}
	else
	{
		return 0;
	}
}

template <Gamebool bRenderThread>
FVertexBufferRHIRef FSuperMapColorVertexBuffer::CreateRHIBuffer_Internal()
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

FVertexBufferRHIRef FSuperMapColorVertexBuffer::CreateRHIBuffer_RenderThread()
{
	return CreateRHIBuffer_Internal<true>();
}

FVertexBufferRHIRef FSuperMapColorVertexBuffer::CreateRHIBuffer_Async()
{
	return CreateRHIBuffer_Internal<false>();
}

Gamevoid FSuperMapColorVertexBuffer::CopyRHIForStreaming(const FSuperMapColorVertexBuffer& Other, Gamebool InAllowCPUAccess)
{
	// Copy serialized properties.
	Stride = Other.Stride;
	NumVertices = Other.NumVertices;

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
	VertexBufferRHI = Other.VertexBufferRHI;
	ColorComponentsSRV = Other.ColorComponentsSRV;
}

Gamevoid FSuperMapColorVertexBuffer::InitRHI()
{
	SCOPED_LOADTIMER(FColorVertexBuffer_InitRHI);

	VertexBufferRHI = CreateRHIBuffer_RenderThread();

	if (VertexBufferRHI && RHISupportsManualVertexFetch(GMaxRHIShaderPlatform))
	{
		// When VertexData is null, this buffer hasn't been streamed in yet. We still need to create a FRHIShaderResourceView which will be
		// cached in a vertex factory uniform buffer later. The nullptr tells the RHI that the SRV doesn't view on anything yet.
		ColorComponentsSRV = RHICreateShaderResourceView(FShaderResourceViewInitializer(VertexData ? VertexBufferRHI : nullptr, PF_R8G8B8A8));
	}
}

Gamevoid FSuperMapColorVertexBuffer::ReleaseRHI()
{
	ColorComponentsSRV.SafeRelease();
	FVertexBuffer::ReleaseRHI();
}

Gamevoid FSuperMapColorVertexBuffer::AllocateData(Gamebool bNeedsCPUAccess /*= true*/)
{
	// Clear any old VertexData before allocating.
	CleanUp();

	VertexData = new FSuperMapColorVertexData(bNeedsCPUAccess);
	// Calculate the vertex stride.
	Stride = VertexData->GetStride();
}

Gamevoid FSuperMapColorVertexBuffer::BindColorVertexBuffer(const FVertexFactory* VertexFactory, FStaticMeshDataType& StaticMeshData) const
{
	if (GetNumVertices() == 0)
	{
		BindDefaultColorVertexBuffer(VertexFactory, StaticMeshData, NullBindStride::ZeroForDefaultBufferBind);
		return;
	}

	StaticMeshData.ColorComponentsSRV = ColorComponentsSRV;
	StaticMeshData.ColorIndexMask = ~0u;

	{
		StaticMeshData.ColorComponent = FVertexStreamComponent(
			this,
			0,	// Struct offset to color
			GetStride(),
			VET_Color,
			EVertexStreamUsage::ManualFetch
		);
	}
}

Gamevoid FSuperMapColorVertexBuffer::BindDefaultColorVertexBuffer(const FVertexFactory* VertexFactory, FStaticMeshDataType& StaticMeshData, NullBindStride BindStride)
{
	StaticMeshData.ColorComponentsSRV = GNullColorVertexBuffer.VertexBufferSRV;
	StaticMeshData.ColorIndexMask = 0;

	{
		const Gamebool bBindForDrawOverride = BindStride == NullBindStride::FColorSizeForComponentOverride;

		StaticMeshData.ColorComponent = FVertexStreamComponent(
			&GNullColorVertexBuffer,
			0, // Struct offset to color
			bBindForDrawOverride ? sizeof(FColor) : 0, //asserted elsewhere
			VET_Color,
			bBindForDrawOverride ? (EVertexStreamUsage::ManualFetch | EVertexStreamUsage::Overridden) : (EVertexStreamUsage::ManualFetch)
		);
	}
}
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif