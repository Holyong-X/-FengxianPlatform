// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "RenderResource.h"
#include "StaticMeshVertexData.h"
#include "Base3D/CommonDefine.h"

using namespace SuperMapSDK;
struct FStaticMeshBuildVertex;

class FSuperMapColorVertexBuffer : public FVertexBuffer
{
public:
	enum class NullBindStride
	{
		FColorSizeForComponentOverride, //when we want to bind null buffer with the expectation that it must be overridden.  Stride must be correct so override binds correctly
		ZeroForDefaultBufferBind, //when we want to bind the null color buffer for it to actually be used for draw.  Stride must be 0 so the IA gives correct data for all verts.
	};

	FSuperMapColorVertexBuffer();

	~FSuperMapColorVertexBuffer();

	Gamevoid CleanUp();

	Gamevoid Init(Gameuint InNumVertices, Gamebool bNeedsCPUAccess = true);

	Gamevoid Init(const TArray<FStaticMeshBuildVertex>& InVertices, Gamebool bNeedsCPUAccess = true);

	Gamevoid Init(const FSuperMapColorVertexBuffer& InVertexBuffer, Gamebool bNeedsCPUAccess = true);

	Gamevoid AppendVertices(const FStaticMeshBuildVertex* Vertices, const Gameuint NumVerticesToAppend);

	Gamevoid Serialize(FArchive& Ar, Gamebool bNeedsCPUAccess);

	Gamevoid SerializeMetaData(FArchive& Ar);

	Gamevoid ClearMetaData();

	Gamevoid ExportText(FString &ValueStr) const;

	Gamevoid ImportText(const TCHAR* SourceText);

	Gamevoid operator=(const FSuperMapColorVertexBuffer &Other);

	FORCEINLINE FColor& VertexColor(Gameuint VertexIndex)
	{
		checkSlow(VertexIndex < GetNumVertices());
		return *(FColor*)(Data + VertexIndex * Stride);
	}

	FORCEINLINE const FColor& VertexColor(Gameuint VertexIndex) const
	{
		checkSlow(VertexIndex < GetNumVertices());
		return *(FColor*)(Data + VertexIndex * Stride);
	}

	FORCEINLINE Gameuint GetStride() const
	{
		return Stride;
	}
	FORCEINLINE Gameuint GetNumVertices() const
	{
		return NumVertices;
	}

	Gameuint GetAllocatedSize() const;

	Gamevoid GetVertexColors(TArray<FColor>& OutColors) const;

	Gamevoid InitFromColorArray(const FColor *InColors, Gameuint Count, Gameuint Stride = sizeof(FColor), Gamebool bNeedsCPUAccess = true);

	Gamevoid InitFromColorArray(const TArray<FColor> &InColors)
	{
		InitFromColorArray(InColors.GetData(), InColors.Num());
	}

	Gamevoid InitFromSingleColor(const FColor &InColor, Gameuint Count)
	{
		InitFromColorArray(&InColor, Count, 0);
	}

	FVertexBufferRHIRef CreateRHIBuffer_RenderThread();
	FVertexBufferRHIRef CreateRHIBuffer_Async();

	Gamevoid CopyRHIForStreaming(const FSuperMapColorVertexBuffer& Other, Gamebool InAllowCPUAccess);

	template <Gameuint MaxNumUpdates>
	Gamevoid InitRHIForStreaming(FRHIVertexBuffer* IntermediateBuffer, TRHIResourceUpdateBatcher<MaxNumUpdates>& Batcher)
	{
		if (VertexBufferRHI && IntermediateBuffer)
		{
			Batcher.QueueUpdateRequest(VertexBufferRHI, IntermediateBuffer);
			if (ColorComponentsSRV)
			{
				Batcher.QueueUpdateRequest(ColorComponentsSRV, VertexBufferRHI, 4, PF_R8G8B8A8);
			}
		}
	}

	template <Gameuint MaxNumUpdates>
	Gamevoid ReleaseRHIForStreaming(TRHIResourceUpdateBatcher<MaxNumUpdates>& Batcher)
	{
		if (VertexBufferRHI)
		{
			Batcher.QueueUpdateRequest(VertexBufferRHI, nullptr);
		}
		if (ColorComponentsSRV)
		{
			Batcher.QueueUpdateRequest(ColorComponentsSRV, nullptr, 0, 0);
		}
	}

	virtual Gamevoid InitRHI() override;
	virtual Gamevoid ReleaseRHI() override;
	virtual FString GetFriendlyName() const override { return TEXT("ColorOnly Mesh Vertices"); }

	Gamevoid BindColorVertexBuffer(const class FVertexFactory* VertexFactory, struct FStaticMeshDataType& StaticMeshData) const;
	static Gamevoid BindDefaultColorVertexBuffer(const class FVertexFactory* VertexFactory, struct FStaticMeshDataType& StaticMeshData, NullBindStride BindStride);

	FORCEINLINE FRHIShaderResourceView* GetColorComponentsSRV() const { return ColorComponentsSRV; }

	Gamevoid* GetVertexData() { return Data; }
	const Gamevoid* GetVertexData() const { return Data; }

private:

	class FSuperMapColorVertexData* VertexData;
	FShaderResourceViewRHIRef ColorComponentsSRV;
	Gameuint8* Data;
	Gameuint Stride;
	Gameuint NumVertices;

	Gamebool NeedsCPUAccess = true;
	Gamevoid AllocateData(Gamebool bNeedsCPUAccess = true);

	template <Gamebool bRenderThread>
	FVertexBufferRHIRef CreateRHIBuffer_Internal();
	FSuperMapColorVertexBuffer(const FSuperMapColorVertexBuffer &rhs);
};
