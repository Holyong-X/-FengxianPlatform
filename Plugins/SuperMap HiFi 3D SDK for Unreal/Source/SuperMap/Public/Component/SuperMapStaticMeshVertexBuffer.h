#pragma once

// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "RenderResource.h"
#include "RenderUtils.h"
#include "StaticMeshVertexData.h"
#include "PackedNormal.h"
#include "Components.h"
#include "Base3D/CommonDefine.h"

using namespace SuperMapSDK;
class FStaticMeshVertexDataInterface;

template<typename TangentTypeT>
struct TSuperMapStaticMeshVertexTangentDatum
{
	TangentTypeT TangentX;
	TangentTypeT TangentZ;

	FORCEINLINE FVector GetTangentX() const
	{
		return TangentX.ToFVector();
	}

	FORCEINLINE FVector4 GetTangentZ() const
	{
		return TangentZ.ToFVector4();
	}

	FORCEINLINE FVector GetTangentY() const
	{
		return GenerateYAxis(TangentX, TangentZ);
	}

	FORCEINLINE Gamevoid SetTangents(FVector X, FVector Y, FVector Z)
	{
		TangentX = X;
		TangentZ = FVector4(Z, GetBasisDeterminantSign(X, Y, Z));
	}

	friend FArchive& operator<<(FArchive& Ar, TSuperMapStaticMeshVertexTangentDatum& Vertex)
	{
		Ar << Vertex.TangentX;
		Ar << Vertex.TangentZ;
		return Ar;
	}
};

template<typename UVTypeT>
struct TSuperMapStaticMeshVertexUVsDatum
{
	UVTypeT UVs;

	FORCEINLINE FVector2D GetUV() const
	{
		return UVs;
	}

	FORCEINLINE Gamevoid SetUV(FVector2D UV)
	{
		UVs = UV;
	}

	friend FArchive& operator<<(FArchive& Ar, TSuperMapStaticMeshVertexUVsDatum& Vertex)
	{
		Ar << Vertex.UVs;
		return Ar;
	}
};

enum class ESuperMapStaticMeshVertexTangentBasisType
{
	Default,
	HighPrecision,
};

enum class ESuperMapStaticMeshVertexUVType
{
	Default,
	HighPrecision,
};

template<ESuperMapStaticMeshVertexTangentBasisType TangentBasisType>
struct TSuperMapStaticMeshVertexTangentTypeSelector
{
};

template<>
struct TSuperMapStaticMeshVertexTangentTypeSelector<ESuperMapStaticMeshVertexTangentBasisType::Default>
{
	typedef FPackedNormal TangentTypeT;
	static const EVertexElementType VertexElementType = VET_PackedNormal;
};

template<>
struct TSuperMapStaticMeshVertexTangentTypeSelector<ESuperMapStaticMeshVertexTangentBasisType::HighPrecision>
{
	typedef FPackedRGBA16N TangentTypeT;
	static const EVertexElementType VertexElementType = VET_Short4N;
};

template<ESuperMapStaticMeshVertexUVType UVType>
struct TSuperMapStaticMeshVertexUVsTypeSelector
{
};

template<>
struct TSuperMapStaticMeshVertexUVsTypeSelector<ESuperMapStaticMeshVertexUVType::Default>
{
	typedef FVector2DHalf UVsTypeT;
};

template<>
struct TSuperMapStaticMeshVertexUVsTypeSelector<ESuperMapStaticMeshVertexUVType::HighPrecision>
{
	typedef FVector2D UVsTypeT;
};

class FSuperMapStaticMeshVertexBuffer : public FRenderResource
{
	friend class FSuperMapStaticMeshVertexBuffer;

public:

	FSuperMapStaticMeshVertexBuffer();

	~FSuperMapStaticMeshVertexBuffer();

	Gamevoid CleanUp();

	Gamevoid Init(Gameuint InNumVertices, Gameuint InNumTexCoords, Gamebool bNeedsCPUAccess = true);

	Gamevoid Init(const TArray<FStaticMeshBuildVertex>& InVertices, Gameuint InNumTexCoords, Gamebool bNeedsCPUAccess = true);


	Gamevoid Init(const FSuperMapStaticMeshVertexBuffer& InVertexBuffer, Gamebool bNeedsCPUAccess = true);

	Gamevoid AppendVertices(const FStaticMeshBuildVertex* Vertices, const Gameuint NumVerticesToAppend);

	Gamevoid Serialize(FArchive& Ar, Gamebool bNeedsCPUAccess);

	Gamevoid SerializeMetaData(FArchive& Ar);

	Gamevoid ClearMetaData();

	Gamevoid operator=(const FSuperMapStaticMeshVertexBuffer &Other);

	template<ESuperMapStaticMeshVertexTangentBasisType TangentBasisTypeT>
	FORCEINLINE_DEBUGGABLE FVector4 VertexTangentX_Typed(Gameuint VertexIndex)const
	{
		typedef TSuperMapStaticMeshVertexTangentDatum<typename TSuperMapStaticMeshVertexTangentTypeSelector<TangentBasisTypeT>::TangentTypeT> TangentType;
		TangentType* ElementData = reinterpret_cast<TangentType*>(TangentsDataPtr);
		check((Gamevoid*)((&ElementData[VertexIndex]) + 1) <= (Gamevoid*)(TangentsDataPtr + TangentsData->GetResourceSize()));
		check((Gamevoid*)((&ElementData[VertexIndex]) + 0) >= (Gamevoid*)(TangentsDataPtr));
		return ElementData[VertexIndex].GetTangentX();
	}

	FORCEINLINE_DEBUGGABLE FVector4 VertexTangentX(Gameuint VertexIndex) const
	{
		checkSlow(VertexIndex < GetNumVertices());

		if (GetUseHighPrecisionTangentBasis())
		{
			return VertexTangentX_Typed<ESuperMapStaticMeshVertexTangentBasisType::HighPrecision>(VertexIndex);
		}
		else
		{
			return VertexTangentX_Typed<ESuperMapStaticMeshVertexTangentBasisType::Default>(VertexIndex);
		}
	}

	template<ESuperMapStaticMeshVertexTangentBasisType TangentBasisTypeT>
	FORCEINLINE_DEBUGGABLE FVector4 VertexTangentZ_Typed(Gameuint VertexIndex)const
	{
		typedef TSuperMapStaticMeshVertexTangentDatum<typename TSuperMapStaticMeshVertexTangentTypeSelector<TangentBasisTypeT>::TangentTypeT> TangentType;
		TangentType* ElementData = reinterpret_cast<TangentType*>(TangentsDataPtr);
		check((Gamevoid*)((&ElementData[VertexIndex]) + 1) <= (Gamevoid*)(TangentsDataPtr + TangentsData->GetResourceSize()));
		check((Gamevoid*)((&ElementData[VertexIndex]) + 0) >= (Gamevoid*)(TangentsDataPtr));
		return ElementData[VertexIndex].GetTangentZ();
	}

	FORCEINLINE_DEBUGGABLE FVector4 VertexTangentZ(Gameuint VertexIndex) const
	{
		checkSlow(VertexIndex < GetNumVertices());

		if (GetUseHighPrecisionTangentBasis())
		{
			return VertexTangentZ_Typed<ESuperMapStaticMeshVertexTangentBasisType::HighPrecision>(VertexIndex);
		}
		else
		{
			return VertexTangentZ_Typed<ESuperMapStaticMeshVertexTangentBasisType::Default>(VertexIndex);
		}
	}

	template<ESuperMapStaticMeshVertexTangentBasisType TangentBasisTypeT>
	FORCEINLINE_DEBUGGABLE FVector4 VertexTangentY_Typed(Gameuint VertexIndex)const
	{
		typedef TSuperMapStaticMeshVertexTangentDatum<typename TSuperMapStaticMeshVertexTangentTypeSelector<TangentBasisTypeT>::TangentTypeT> TangentType;
		TangentType* ElementData = reinterpret_cast<TangentType*>(TangentsDataPtr);
		check((Gamevoid*)((&ElementData[VertexIndex]) + 1) <= (Gamevoid*)(TangentsDataPtr + TangentsData->GetResourceSize()));
		check((Gamevoid*)((&ElementData[VertexIndex]) + 0) >= (Gamevoid*)(TangentsDataPtr));
		return ElementData[VertexIndex].GetTangentY();
	}

	FORCEINLINE_DEBUGGABLE FVector VertexTangentY(Gameuint VertexIndex) const
	{
		checkSlow(VertexIndex < GetNumVertices());

		if (GetUseHighPrecisionTangentBasis())
		{
			return VertexTangentY_Typed<ESuperMapStaticMeshVertexTangentBasisType::HighPrecision>(VertexIndex);
		}
		else
		{
			return VertexTangentY_Typed<ESuperMapStaticMeshVertexTangentBasisType::Default>(VertexIndex);
		}
	}

	FORCEINLINE_DEBUGGABLE Gamevoid SetVertexTangents(Gameuint VertexIndex, FVector X, FVector Y, FVector Z)
	{
		checkSlow(VertexIndex < GetNumVertices());

		if (GetUseHighPrecisionTangentBasis())
		{
			typedef TSuperMapStaticMeshVertexTangentDatum<typename TSuperMapStaticMeshVertexTangentTypeSelector<ESuperMapStaticMeshVertexTangentBasisType::HighPrecision>::TangentTypeT> TangentType;
			TangentType* ElementData = reinterpret_cast<TangentType*>(TangentsDataPtr);
			check((Gamevoid*)((&ElementData[VertexIndex]) + 1) <= (Gamevoid*)(TangentsDataPtr + TangentsData->GetResourceSize()));
			check((Gamevoid*)((&ElementData[VertexIndex]) + 0) >= (Gamevoid*)(TangentsDataPtr));
			ElementData[VertexIndex].SetTangents(X, Y, Z);
		}
		else
		{
			typedef TSuperMapStaticMeshVertexTangentDatum<typename TSuperMapStaticMeshVertexTangentTypeSelector<ESuperMapStaticMeshVertexTangentBasisType::Default>::TangentTypeT> TangentType;
			TangentType* ElementData = reinterpret_cast<TangentType*>(TangentsDataPtr);
			check((Gamevoid*)((&ElementData[VertexIndex]) + 1) <= (Gamevoid*)(TangentsDataPtr + TangentsData->GetResourceSize()));
			check((Gamevoid*)((&ElementData[VertexIndex]) + 0) >= (Gamevoid*)(TangentsDataPtr));
			ElementData[VertexIndex].SetTangents(X, Y, Z);
		}
	}

	FORCEINLINE_DEBUGGABLE Gamevoid SetVertexUV(Gameuint VertexIndex, Gameuint UVIndex, const FVector2D& Vec2D)
	{
		checkSlow(VertexIndex < GetNumVertices());
		checkSlow(UVIndex < GetNumTexCoords());

		if (GetUseFullPrecisionUVs())
		{
			typedef TSuperMapStaticMeshVertexUVsDatum<typename TSuperMapStaticMeshVertexUVsTypeSelector<ESuperMapStaticMeshVertexUVType::HighPrecision>::UVsTypeT> UVType;
			size_t UvStride = sizeof(UVType) * GetNumTexCoords();

			UVType* ElementData = reinterpret_cast<UVType*>(TexcoordDataPtr + (VertexIndex * UvStride));
			check((Gamevoid*)((&ElementData[UVIndex]) + 1) <= (Gamevoid*)(TexcoordDataPtr + TexcoordData->GetResourceSize()));
			check((Gamevoid*)((&ElementData[UVIndex]) + 0) >= (Gamevoid*)(TexcoordDataPtr));
			ElementData[UVIndex].SetUV(Vec2D);
		}
		else
		{
			typedef TSuperMapStaticMeshVertexUVsDatum<typename TSuperMapStaticMeshVertexUVsTypeSelector<ESuperMapStaticMeshVertexUVType::Default>::UVsTypeT> UVType;
			size_t UvStride = sizeof(UVType) * GetNumTexCoords();

			UVType* ElementData = reinterpret_cast<UVType*>(TexcoordDataPtr + (VertexIndex * UvStride));
			check((Gamevoid*)((&ElementData[UVIndex]) + 1) <= (Gamevoid*)(TexcoordDataPtr + TexcoordData->GetResourceSize()));
			check((Gamevoid*)((&ElementData[UVIndex]) + 0) >= (Gamevoid*)(TexcoordDataPtr));
			ElementData[UVIndex].SetUV(Vec2D);
		}
	}

	template<ESuperMapStaticMeshVertexUVType UVTypeT>
	FORCEINLINE_DEBUGGABLE FVector2D GetVertexUV_Typed(Gameuint VertexIndex, Gameuint UVIndex)const
	{
		typedef TSuperMapStaticMeshVertexUVsDatum<typename TSuperMapStaticMeshVertexUVsTypeSelector<UVTypeT>::UVsTypeT> UVType;
		size_t UvStride = sizeof(UVType) * GetNumTexCoords();

		UVType* ElementData = reinterpret_cast<UVType*>(TexcoordDataPtr + (VertexIndex * UvStride));
		check((Gamevoid*)((&ElementData[UVIndex]) + 1) <= (Gamevoid*)(TexcoordDataPtr + TexcoordData->GetResourceSize()));
		check((Gamevoid*)((&ElementData[UVIndex]) + 0) >= (Gamevoid*)(TexcoordDataPtr));
		return ElementData[UVIndex].GetUV();
	}

	FORCEINLINE_DEBUGGABLE FVector2D GetVertexUV(Gameuint VertexIndex, Gameuint UVIndex) const
	{
		checkSlow(VertexIndex < GetNumVertices());
		checkSlow(UVIndex < GetNumTexCoords());

		if (GetUseFullPrecisionUVs())
		{
			return GetVertexUV_Typed<ESuperMapStaticMeshVertexUVType::HighPrecision>(VertexIndex, UVIndex);
		}
		else
		{
			return GetVertexUV_Typed<ESuperMapStaticMeshVertexUVType::Default>(VertexIndex, UVIndex);
		}
	}

	FORCEINLINE_DEBUGGABLE Gameuint GetNumVertices() const
	{
		return NumVertices;
	}

	FORCEINLINE_DEBUGGABLE Gameuint GetNumTexCoords() const
	{
		return NumTexCoords;
	}

	FORCEINLINE_DEBUGGABLE Gamebool GetUseFullPrecisionUVs() const
	{
		return bUseFullPrecisionUVs;
	}

	FORCEINLINE_DEBUGGABLE Gamevoid SetUseFullPrecisionUVs(Gamebool UseFull)
	{
		bUseFullPrecisionUVs = UseFull;
	}

	FORCEINLINE_DEBUGGABLE Gamebool GetUseHighPrecisionTangentBasis() const
	{
		return bUseHighPrecisionTangentBasis;
	}

	FORCEINLINE_DEBUGGABLE Gamevoid SetUseHighPrecisionTangentBasis(Gamebool bUseHighPrecision)
	{
		bUseHighPrecisionTangentBasis = bUseHighPrecision;
	}

	FORCEINLINE_DEBUGGABLE Gameuint GetResourceSize() const
	{
		return (TangentsStride + (TexcoordStride * GetNumTexCoords())) * NumVertices;
	}

	FVertexBufferRHIRef CreateTangentsRHIBuffer_RenderThread();
	FVertexBufferRHIRef CreateTangentsRHIBuffer_Async();
	FVertexBufferRHIRef CreateTexCoordRHIBuffer_RenderThread();
	FVertexBufferRHIRef CreateTexCoordRHIBuffer_Async();

	Gamevoid CopyRHIForStreaming(const FSuperMapStaticMeshVertexBuffer& Other, Gamebool InAllowCPUAccess);

	template <Gameuint MaxNumUpdates>
	Gamevoid InitRHIForStreaming(
		FRHIVertexBuffer* IntermediateTangentsBuffer,
		FRHIVertexBuffer* IntermediateTexCoordBuffer,
		TRHIResourceUpdateBatcher<MaxNumUpdates>& Batcher)
	{
		check(TangentsVertexBuffer.VertexBufferRHI && TexCoordVertexBuffer.VertexBufferRHI);
		if (IntermediateTangentsBuffer)
		{
			Batcher.QueueUpdateRequest(TangentsVertexBuffer.VertexBufferRHI, IntermediateTangentsBuffer);
			if (TangentsSRV)
			{
				Batcher.QueueUpdateRequest(
					TangentsSRV,
					TangentsVertexBuffer.VertexBufferRHI,
					GetUseHighPrecisionTangentBasis() ? 8u : 4u,
					GetUseHighPrecisionTangentBasis() ? (Gameuint8)PF_R16G16B16A16_SNORM : (Gameuint8)PF_R8G8B8A8_SNORM);;
			}
		}
		if (IntermediateTexCoordBuffer)
		{
			Batcher.QueueUpdateRequest(TexCoordVertexBuffer.VertexBufferRHI, IntermediateTexCoordBuffer);
			if (TextureCoordinatesSRV)
			{
				Batcher.QueueUpdateRequest(
					TextureCoordinatesSRV,
					TexCoordVertexBuffer.VertexBufferRHI,
					GetUseFullPrecisionUVs() ? 8u : 4u,
					GetUseFullPrecisionUVs() ? (Gameuint8)PF_G32R32F : (Gameuint8)PF_G16R16F);
			}
		}
	}

	template<Gameuint MaxNumUpdates>
	Gamevoid ReleaseRHIForStreaming(TRHIResourceUpdateBatcher<MaxNumUpdates>& Batcher)
	{
		check(TangentsVertexBuffer.VertexBufferRHI && TexCoordVertexBuffer.VertexBufferRHI);
		Batcher.QueueUpdateRequest(TangentsVertexBuffer.VertexBufferRHI, nullptr);
		Batcher.QueueUpdateRequest(TexCoordVertexBuffer.VertexBufferRHI, nullptr);
		if (TangentsSRV)
		{
			Batcher.QueueUpdateRequest(TangentsSRV, nullptr, 0, 0);
		}
		if (TextureCoordinatesSRV)
		{
			Batcher.QueueUpdateRequest(TextureCoordinatesSRV, nullptr, 0, 0);
		}
	}

	// FRenderResource interface.
	virtual Gamevoid InitRHI() override;
	virtual Gamevoid ReleaseRHI() override;
	virtual Gamevoid InitResource() override;
	virtual Gamevoid ReleaseResource() override;
	virtual FString GetFriendlyName() const override { return TEXT("Static-mesh vertices"); }

	Gamevoid BindTangentVertexBuffer(const FVertexFactory* VertexFactory, struct FStaticMeshDataType& Data) const;
	Gamevoid BindTexCoordVertexBuffer(const FVertexFactory* VertexFactory, struct FStaticMeshDataType& Data, int ClampedNumTexCoords = -1) const;
	Gamevoid BindPackedTexCoordVertexBuffer(const FVertexFactory* VertexFactory, struct FStaticMeshDataType& Data) const;
	Gamevoid BindLightMapVertexBuffer(const FVertexFactory* VertexFactory, struct FStaticMeshDataType& Data, int LightMapCoordinateIndex) const;

	FORCEINLINE_DEBUGGABLE Gamevoid* GetTangentData() { return TangentsDataPtr; }
	FORCEINLINE_DEBUGGABLE const Gamevoid* GetTangentData() const { return TangentsDataPtr; }

	FORCEINLINE_DEBUGGABLE Gamevoid* GetTexCoordData() { return TexcoordDataPtr; }
	FORCEINLINE_DEBUGGABLE const Gamevoid* GetTexCoordData() const { return TexcoordDataPtr; }

	int GetTangentSize();

	int GetTexCoordSize();

	FORCEINLINE_DEBUGGABLE Gamebool GetAllowCPUAccess()
	{
		if (!TangentsData || !TexcoordData)
			return false;

		return TangentsData->GetAllowCPUAccess() && TexcoordData->GetAllowCPUAccess();
	}

	class FSuperMapTangentsVertexBuffer : public FVertexBuffer
	{
		virtual FString GetFriendlyName() const override { return TEXT("FTangentsVertexBuffer"); }
	} TangentsVertexBuffer;

	class FSuperMapTexcoordVertexBuffer : public FVertexBuffer
	{
		virtual FString GetFriendlyName() const override { return TEXT("FTexcoordVertexBuffer"); }
	} TexCoordVertexBuffer;

	inline Gamebool IsValid()
	{
		return IsValidRef(TangentsVertexBuffer.VertexBufferRHI) && IsValidRef(TexCoordVertexBuffer.VertexBufferRHI);
	}

	FRHIShaderResourceView* GetTangentsSRV() const { return TangentsSRV; }
	FRHIShaderResourceView* GetTexCoordsSRV() const { return TextureCoordinatesSRV; }
private:

	FStaticMeshVertexDataInterface* TangentsData;
	FShaderResourceViewRHIRef TangentsSRV;

	FStaticMeshVertexDataInterface* TexcoordData;
	FShaderResourceViewRHIRef TextureCoordinatesSRV;

	Gameuint8* TangentsDataPtr;
	Gameuint8* TexcoordDataPtr;

	Gameuint TangentsStride;
	Gameuint TexcoordStride;

	Gameuint NumTexCoords;

	Gameuint NumVertices;

	Gamebool bUseFullPrecisionUVs;
	Gamebool bUseHighPrecisionTangentBasis;

	Gamebool NeedsCPUAccess = true;

	Gamevoid AllocateData(Gamebool bNeedsCPUAccess = true);
	Gamevoid ConvertHalfTexcoordsToFloat(const Gameuint8* InData);

	template <Gamebool bRenderThread>
	FVertexBufferRHIRef CreateTangentsRHIBuffer_Internal();

	template<Gamebool bRenderThread>
	FVertexBufferRHIRef CreateTexCoordRHIBuffer_Internal();

	Gamevoid InitTangentAndTexCoordStrides();
};