// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "RenderResource.h"
#include "Base3D/CommonDefine.h"

using namespace SuperMapSDK;

struct FStaticMeshBuildVertex;

struct FSuperMapPositionVertex
{
	FVector	Position;

	friend FArchive& operator<<(FArchive& Ar, FSuperMapPositionVertex& V)
	{
		Ar << V.Position;
		return Ar;
	}
};

class FSuperMapPositionVertexBuffer : public FVertexBuffer
{
public:

	FSuperMapPositionVertexBuffer();

	~FSuperMapPositionVertexBuffer();

	Gamevoid CleanUp();

	Gamevoid Init(Gameuint NumVertices, Gamebool bInNeedsCPUAccess = true);

	Gamevoid Init(const TArray<FStaticMeshBuildVertex>& InVertices, Gamebool bInNeedsCPUAccess = true);

	Gamevoid Init(const FSuperMapPositionVertexBuffer& InVertexBuffer, Gamebool bInNeedsCPUAccess = true);

	Gamevoid Init(const TArray<FVector>& InPositions, Gamebool bInNeedsCPUAccess = true);

	Gamevoid AppendVertices(const FStaticMeshBuildVertex* Vertices, const Gameuint NumVerticesToAppend);

	Gamevoid Serialize(FArchive& Ar, Gamebool bInNeedsCPUAccess);

	Gamevoid SerializeMetaData(FArchive& Ar);

	Gamevoid ClearMetaData();

	Gamevoid operator=(const FSuperMapPositionVertexBuffer &Other);

	FORCEINLINE FVector& VertexPosition(Gameuint VertexIndex)
	{
		checkSlow(VertexIndex < GetNumVertices());
		return ((FSuperMapPositionVertex*)(Data + VertexIndex * Stride))->Position;
	}
	FORCEINLINE const FVector& VertexPosition(Gameuint VertexIndex) const
	{
		checkSlow(VertexIndex < GetNumVertices());
		return ((FSuperMapPositionVertex*)(Data + VertexIndex * Stride))->Position;
	}

	FORCEINLINE Gameuint GetStride() const
	{
		return Stride;
	}
	FORCEINLINE Gameuint GetNumVertices() const
	{
		return NumVertices;
	}

	FVertexBufferRHIRef CreateRHIBuffer_RenderThread();
	FVertexBufferRHIRef CreateRHIBuffer_Async();

	Gamevoid CopyRHIForStreaming(const FSuperMapPositionVertexBuffer& Other, Gamebool InAllowCPUAccess);

	template <Gameuint MaxNumUpdates>
	Gamevoid InitRHIForStreaming(FRHIVertexBuffer* IntermediateBuffer, TRHIResourceUpdateBatcher<MaxNumUpdates>& Batcher)
	{
		check(VertexBufferRHI);
		if (IntermediateBuffer)
		{
			Batcher.QueueUpdateRequest(VertexBufferRHI, IntermediateBuffer);
			if (PositionComponentSRV)
			{
				Batcher.QueueUpdateRequest(PositionComponentSRV, VertexBufferRHI, 4, PF_R32_FLOAT);
			}
		}
	}

	template <Gameuint MaxNumUpdates>
	Gamevoid ReleaseRHIForStreaming(TRHIResourceUpdateBatcher<MaxNumUpdates>& Batcher)
	{
		check(VertexBufferRHI);
		Batcher.QueueUpdateRequest(VertexBufferRHI, nullptr);
		if (PositionComponentSRV)
		{
			Batcher.QueueUpdateRequest(PositionComponentSRV, nullptr, 0, 0);
		}
	}

	virtual Gamevoid InitRHI() override;
	virtual Gamevoid ReleaseRHI() override;
	virtual FString GetFriendlyName() const override { return TEXT("PositionOnly Static-mesh vertices"); }

	Gamevoid BindPositionVertexBuffer(const class FVertexFactory* VertexFactory, struct FStaticMeshDataType& Data) const;

	Gamevoid* GetVertexData() { return Data; }
	const Gamevoid* GetVertexData() const { return Data; }

	FRHIShaderResourceView* GetSRV() const { return PositionComponentSRV; }

private:

	FShaderResourceViewRHIRef PositionComponentSRV;
	TMemoryImagePtr<class FSuperMapPositionVertexData> VertexData;
	uint8* Data;
	Gameuint Stride;
	Gameuint NumVertices;
	Gamebool bNeedsCPUAccess = true;
	Gamevoid AllocateData(Gamebool bInNeedsCPUAccess = true);
	template <Gamebool bRenderThread>
	FVertexBufferRHIRef CreateRHIBuffer_Internal();
};


