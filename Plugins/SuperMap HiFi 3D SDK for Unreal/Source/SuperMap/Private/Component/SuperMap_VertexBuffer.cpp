#include "Component/SuperMap_VertexBuffer.h"
#include "Base3D/CommonDefine.h"
#include "mikktspace.h"
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif
namespace
{
struct ComputeTangentSMVertex
{
public:
#if SM_FOR_UE_FIVE
	FPositionVertexBuffer* positionVertexBuffer;
	FStaticMeshVertexBuffer* staticMeshVertexBuffer;
#else
	FSuperMapPositionVertexBuffer* positionVertexBuffer;
	FSuperMapStaticMeshVertexBuffer* staticMeshVertexBuffer;
#endif
};
#if SM_FOR_UE_FIVE
static Gamevoid computeFlatNormals(const TArray<uint32_t>& indices, const FPositionVertexBuffer& positionBuffer, FStaticMeshVertexBuffer& vertexBuffer)
#else
static Gamevoid computeFlatNormals(const TArray<uint32_t>& indices, const FSuperMapPositionVertexBuffer& positionBuffer, FSuperMapStaticMeshVertexBuffer& vertexBuffer)
#endif
{
	// Compute flat normals
	for (int64_t i = 0; i < indices.Num(); i += 3) {
		FVector v0 = FVector(positionBuffer.VertexPosition(i));
		FVector v1 = FVector(positionBuffer.VertexPosition(i + 1));
		FVector v2 = FVector(positionBuffer.VertexPosition(i + 2));

		FVector v01 = v1 - v0;
		FVector v02 = v2 - v0;
		FVector normal = FVector::CrossProduct(v01, v02);
		FVector safeNormal = -normal.GetSafeNormal();
		FPackedNormal TangentX = FVector(1.0f, 0.0f, 0.0f);
		FPackedNormal TangentZ = safeNormal;
		TangentZ.Vector.W = 127;
		const auto TangentY = GenerateYAxis(TangentX, TangentZ);
		vertexBuffer.SetVertexTangents(i, GameVector3(TangentX.ToFVector()), GameVector3(TangentY), GameVector3(safeNormal));
		vertexBuffer.SetVertexTangents(i + 1, GameVector3(TangentX.ToFVector()), GameVector3(TangentY), GameVector3(safeNormal));
		vertexBuffer.SetVertexTangents(i + 2, GameVector3(TangentX.ToFVector()), GameVector3(TangentY), GameVector3(safeNormal));
	}
}

static Gameint mikkGetNumFaces(const SMikkTSpaceContext* Context) {
	ComputeTangentSMVertex* userData = reinterpret_cast<ComputeTangentSMVertex*>(Context->m_pUserData);
	return userData->positionVertexBuffer->GetNumVertices() / 3;
}

static Gameint mikkGetNumVertsOfFace(const SMikkTSpaceContext* Context, const Gameint FaceIdx) {
	ComputeTangentSMVertex* userData = reinterpret_cast<ComputeTangentSMVertex*>(Context->m_pUserData);
	Gameint NumVertices = userData->positionVertexBuffer->GetNumVertices();
	return FaceIdx < (NumVertices / 3) ? 3 : 0;
}

static Gamevoid mikkGetPosition(
	const SMikkTSpaceContext* Context,
	Gamefloat Position[3],
	const Gameint FaceIdx,
	const Gameint VertIdx) {
	ComputeTangentSMVertex* userData = reinterpret_cast<ComputeTangentSMVertex*>(Context->m_pUserData);
#if SM_FOR_UE_FIVE
	GameVector3& position = userData->positionVertexBuffer->VertexPosition(FaceIdx * 3 + VertIdx);
#else
	FVector& position = userData->positionVertexBuffer->VertexPosition(FaceIdx * 3 + VertIdx);
#endif
	Position[0] = position.X;
	Position[1] = position.Y;
	Position[2] = position.Z;
}

static Gamevoid mikkGetNormal(
	const SMikkTSpaceContext* Context,
	Gamefloat Normal[3],
	const Gameint FaceIdx,
	const Gameint VertIdx) {
	ComputeTangentSMVertex* userData = reinterpret_cast<ComputeTangentSMVertex*>(Context->m_pUserData);
#if SM_FOR_UE_FIVE
	GameVector3 normal = userData->staticMeshVertexBuffer->VertexTangentZ(FaceIdx * 3 + VertIdx);
#else
	FVector normal = userData->staticMeshVertexBuffer->VertexTangentZ(FaceIdx * 3 + VertIdx);
#endif
	Normal[0] = normal.X;
	Normal[1] = normal.Y;
	Normal[2] = normal.Z;
}

static Gamevoid mikkGetTexCoord(
	const SMikkTSpaceContext* Context,
	Gamefloat UV[2],
	const Gameint FaceIdx,
	const Gameint VertIdx) {
	ComputeTangentSMVertex* userData = reinterpret_cast<ComputeTangentSMVertex*>(Context->m_pUserData);
#if SM_FOR_UE_FIVE
	GameVector2 uv = userData->staticMeshVertexBuffer->GetVertexUV(FaceIdx * 3 + VertIdx, 0);
#else
	FVector2D uv = userData->staticMeshVertexBuffer->GetVertexUV(FaceIdx * 3 + VertIdx, 0);
#endif
	UV[0] = uv.X;
	UV[1] = uv.Y;
}

static Gamevoid mikkSetTSpaceBasic(
	const SMikkTSpaceContext* Context,
	const Gamefloat Tangent[3],
	const Gamefloat BitangentSign,
	const Gameint FaceIdx,
	const Gameint VertIdx) {
	ComputeTangentSMVertex* userData = reinterpret_cast<ComputeTangentSMVertex*>(Context->m_pUserData);
#if SM_FOR_UE_FIVE
	GameVector3 TangentZ = userData->staticMeshVertexBuffer->VertexTangentZ(FaceIdx * 3 + VertIdx);
#else
	FVector TangentZ = userData->staticMeshVertexBuffer->VertexTangentZ(FaceIdx * 3 + VertIdx);
#endif
	GameVector3 TangentX(Tangent[0], Tangent[1], Tangent[2]);
	GameVector3 TangentY = BitangentSign * GameVector3::CrossProduct(TangentZ, TangentX);
	userData->staticMeshVertexBuffer->SetVertexTangents(FaceIdx * 3 + VertIdx, TangentX, TangentY, TangentZ);
}

#if SM_FOR_UE_FIVE
static Gamevoid computeTangentSpace(FPositionVertexBuffer& positionVertexBuffer, FStaticMeshVertexBuffer& staticMeshVertexBuffer)
#else
static Gamevoid computeTangentSpace(FSuperMapPositionVertexBuffer& positionVertexBuffer, FSuperMapStaticMeshVertexBuffer& staticMeshVertexBuffer)
#endif
 {
	SMikkTSpaceInterface MikkTInterface;
	MikkTInterface.m_getNormal = mikkGetNormal;
	MikkTInterface.m_getNumFaces = mikkGetNumFaces;
	MikkTInterface.m_getNumVerticesOfFace = mikkGetNumVertsOfFace;
	MikkTInterface.m_getPosition = mikkGetPosition;
	MikkTInterface.m_getTexCoord = mikkGetTexCoord;
	MikkTInterface.m_setTSpaceBasic = mikkSetTSpaceBasic;
	MikkTInterface.m_setTSpace = nullptr;

	ComputeTangentSMVertex userData;
	userData.positionVertexBuffer = &positionVertexBuffer;
	userData.staticMeshVertexBuffer = &staticMeshVertexBuffer;

	SMikkTSpaceContext MikkTContext;
	MikkTContext.m_pInterface = &MikkTInterface;
	MikkTContext.m_pUserData = (Gamevoid*)(&userData);
	MikkTContext.m_bIgnoreDegenerates = false;
	genTangSpaceDefault(&MikkTContext);
}


inline Gamevoid InitOrUpdateResource(FRenderResource* Resource)
{
	if (!Resource->IsInitialized())
	{
		Resource->InitResource();
	}
	else
	{
		Resource->UpdateRHI();
	}
}
} // namespace

FSuperMapVertexBuffer::FSuperMapVertexBuffer()
{
	m_bIsGlobal = false;
}

FSuperMapVertexBuffer::~FSuperMapVertexBuffer()
{
	m_PositionVertexBuffer.ReleaseResource();
	m_StaticMeshVertexBuffer.ReleaseResource();
	m_ColorVertexBuffer.ReleaseResource();
	m_IndexBuffer.ReleaseResource();
	m_ShortIndexBuffer.ReleaseResource();
}

Gamevoid FSuperMapVertexBuffer::SetMaterialName(FString material)
{
	m_strMaterialName = material;
}

EPrimitiveType FSuperMapVertexBuffer::GetPrimitiveType()
{
	return m_eDrawType;
}
Gameuint FSuperMapVertexBuffer::GetIndexBufferCount()
{
	if (m_IndexBuffer.Indices.Num() > 0)
	{
		return m_IndexBuffer.Indices.Num();
	}

	if (m_ShortIndexBuffer.Indices.Num() > 0)
	{
		return m_ShortIndexBuffer.Indices.Num();
	}

	return 0;
}

Gameuint FSuperMapVertexBuffer::GetPrimitiveCount()
{
	Gameuint nNumPrimitives = 0;
	if (m_IndexBuffer.Indices.Num() > 0)
	{	
		if (m_eDrawType == PT_PointList)
		{
			nNumPrimitives = m_IndexBuffer.Indices.Num();
		}
		else if (m_eDrawType == PT_LineList)
		{
			nNumPrimitives = m_IndexBuffer.Indices.Num() / 2;
		}
		else
		{
			nNumPrimitives = m_IndexBuffer.Indices.Num() / 3;
		}
	}

	if (m_ShortIndexBuffer.Indices.Num() > 0)
	{
		if (m_eDrawType == PT_PointList)
		{
			nNumPrimitives = m_ShortIndexBuffer.Indices.Num();
		}
		else if (m_eDrawType == PT_LineList)
		{
			nNumPrimitives = m_ShortIndexBuffer.Indices.Num() / 2;
		}
		else
		{
			nNumPrimitives = m_ShortIndexBuffer.Indices.Num() / 3;
		}
	}

	return nNumPrimitives;
}

Gameuint FSuperMapVertexBuffer::GetVertexBufferCount()
{
	return m_PositionVertexBuffer.GetNumVertices();
}

FVertexBufferRHIRef FSuperMapVertexBuffer::GetVertexBufferRHI()
{
	return m_PositionVertexBuffer.VertexBufferRHI;
}

FIndexBuffer* FSuperMapVertexBuffer::GetIndexBuffer()
{
	if (m_IndexBuffer.Indices.Num() > 0)
	{
		return &m_IndexBuffer;
	}

	return &m_ShortIndexBuffer;
}

FIndexBufferRHIRef FSuperMapVertexBuffer::GetIndexBufferRHI()
{
	if (m_IndexBuffer.Indices.Num() > 0)
	{
		return m_IndexBuffer.IndexBufferRHI;
	}
	
	return m_ShortIndexBuffer.IndexBufferRHI;
}

Gamevoid FSuperMapVertexBuffer::CopyGPUBufferLocked(FRHIVertexBuffer* rhiVertexBuffer, Gamevoid* src, SIZE_T size)
{
	Gamevoid* VertexBufferData = RHILockVertexBuffer(rhiVertexBuffer, 0, size, RLM_WriteOnly);
	FMemory::Memcpy(VertexBufferData, src, size);
	RHIUnlockVertexBuffer(rhiVertexBuffer);
}

Gamevoid FSuperMapVertexBuffer::Create_GameOrWorkerThread(const FSMMesh & smMesh)
{
	m_eDrawType = FSuperMapVertexBuffer::GetDrawType(smMesh);

	Gameint nIndices = smMesh.m_arrDataIndex[0]->m_nIndexCount;
	Gameint NumVertices = smMesh.m_pDataVertex->m_nPosCount;

	// 顶点不共用，需要分裂顶点
	if (nIndices > 0 && m_eDrawType == PT_TriangleList && SuperMapSDK::m_bEnableNormal)
	{
		NumVertices = nIndices;
	}

	// 4重纹理坐标
	Gameint NumUVs = 5;

	m_PositionVertexBuffer.Init(NumVertices, false);
	m_StaticMeshVertexBuffer.SetUseHighPrecisionTangentBasis(true);
	m_StaticMeshVertexBuffer.SetUseFullPrecisionUVs(true);
	m_StaticMeshVertexBuffer.Init(NumVertices, NumUVs, false);
	m_ColorVertexBuffer.Init(NumVertices, true);

	FetchBuffersFromMeshData(smMesh);
}

Gamevoid FSuperMapVertexBuffer::FetchColorBuffersFromMeshData(const FSMMesh & smMesh)
{
	Gamevoid* pColorBuffer = m_ColorVertexBuffer.GetVertexData();
	FMemory::Memcpy(((Gameuint8*)pColorBuffer + smMesh.m_nSubMeshInfoOffset * sizeof(Gameuint)), (Gamevoid*)(smMesh.m_pDataVertex->m_PosColor),
		sizeof(Gameuint) * smMesh.m_pDataVertex->m_nColorCount);
}

Gamevoid FSuperMapVertexBuffer::FetchBuffersFromMeshData(const FSMMesh & smMesh)
{
	TArray<Gameuint> indices;

	static FVector4 XAxisTangent(1, 0, 0, 0);

	Gameint oldNumVertices = smMesh.m_pDataVertex->m_nPosCount;
	Gameint NumVertices = oldNumVertices;
	Gameint nIndices = smMesh.m_arrDataIndex[0]->m_nIndexCount;

	if (m_eDrawType == PT_TriangleList && SuperMapSDK::m_bEnableNormal)
	{
		NumVertices = nIndices;
	}

	Gameint nDim = smMesh.m_pDataVertex->m_nPosDim;

	Gamebool bModel = (m_strMaterialName.Compare("Model") == 0 ? true : false);
	Gamebool bModel_Translucent = (m_strMaterialName.Compare("Model_Translucent") == 0 ? true : false);

	for (Gameint i = 0; i < NumVertices; i++)
	{
		// 顶点
		Gameuint index = i;

		if (m_eDrawType == PT_TriangleList && SuperMapSDK::m_bEnableNormal)
		{
			if (smMesh.m_arrDataIndex[0]->m_shortIndex != nullptr)
			{
				index = smMesh.m_arrDataIndex[0]->m_shortIndex[i];
			}
			else if (smMesh.m_arrDataIndex[0]->m_Index != nullptr)
			{
				index = smMesh.m_arrDataIndex[0]->m_Index[i];
			}
		}

		if ((Gameint)index > (Gameint)oldNumVertices)
		{
			index = oldNumVertices;
		}

		indices.Add(index);

		GameVector3 vertex;
		vertex.Y = smMesh.m_pDataVertex->m_Pos[index * nDim + 0] * M_TO_CM;
		vertex.X = smMesh.m_pDataVertex->m_Pos[index * nDim + 1] * M_TO_CM;
		vertex.Z = smMesh.m_pDataVertex->m_Pos[index * nDim + 2] * M_TO_CM;
		if (nDim > 3)
		{
#if SM_FOR_UE_FIVE
			GameVector2 uv;
#else
			FVector2D uv;
#endif
			uv.X = smMesh.m_pDataVertex->m_Pos[index * nDim + 3] * M_TO_CM;
			uv.Y = smMesh.m_pDataVertex->m_Pos[index * nDim + 3] * M_TO_CM;
			m_StaticMeshVertexBuffer.SetVertexUV(i, 4, uv);
		}
		
		m_PositionVertexBuffer.VertexPosition(i) = vertex;
		//===============BlendWeights======================
		Gamebool bNewModel = false;
		if (smMesh.m_pDataVertex->m_nBlendWeightsCount == oldNumVertices && smMesh.m_pDataVertex->m_pBlendWeights != nullptr)
		{
#if SM_FOR_UE_FIVE
			GameVector2 weights;
#else
			FVector2D weights;
#endif
			
			weights.X = smMesh.m_pDataVertex->m_pBlendWeights[index];
			weights.Y = 0;

			bNewModel = true;
			m_StaticMeshVertexBuffer.SetVertexUV(i, 1, weights);
		}

		//===============法线===============================
		if (smMesh.m_pDataVertex->m_nNormalCount == oldNumVertices && smMesh.m_pDataVertex->m_Normal != nullptr)
		{
			FVector normal;
			normal.Y = smMesh.m_pDataVertex->m_Normal[index * 3 + 0];
			normal.X = smMesh.m_pDataVertex->m_Normal[index * 3 + 1];
			normal.Z = smMesh.m_pDataVertex->m_Normal[index * 3 + 2];
			FPackedNormal TangentX = FVector(1.0f, 0.0f, 0.0f);
			FPackedNormal TangentZ = normal;
			TangentZ.Vector.W = 127;
			const auto TangentY = GenerateYAxis(TangentX, TangentZ);
			m_StaticMeshVertexBuffer.SetVertexTangents(i, GameVector3(TangentX.ToFVector()), GameVector3(TangentY), GameVector3(TangentZ.ToFVector()));
		}
		//=================================================


		//===================================================
		if (smMesh.m_pDataVertex->m_nColorCount == oldNumVertices && smMesh.m_pDataVertex->m_PosColor != nullptr)
		{
			Gameuint nColor = smMesh.m_pDataVertex->m_PosColor[index];

			Gamefloat fR, fG, fB, fA;
			SuperMapSDK::UnrealEngine::Core::_IDRGBA(nColor, fR, fG, fB, fA);

			Gameuint8 r = fR * 255;
			Gameuint8 g = fG * 255;
			Gameuint8 b = fB * 255;
			Gameuint8 a = fA * 255;

			FColor color(r, g, b, a);
			m_ColorVertexBuffer.VertexColor(i) = color;
		}
	
		//===================================================

		//====================================================
		if (smMesh.m_pDataVertex->m_nSecondColorCount == oldNumVertices && smMesh.m_pDataVertex->m_PosSceondColor != nullptr)
		{
			Gameuint nColor = smMesh.m_pDataVertex->m_PosSceondColor[index];

			Gamefloat fR, fG, fB, fA;
			SuperMapSDK::UnrealEngine::Core::_IDRGBA(nColor, fR, fG, fB, fA);

			FVector4 fColor(fR, fG, fB, fA);
#if SM_FOR_UE_FIVE
			m_StaticMeshVertexBuffer.SetVertexUV(i, 2, GameVector2(fR, fG));
			m_StaticMeshVertexBuffer.SetVertexUV(i, 3, GameVector2(fB, fA));
#else
			m_StaticMeshVertexBuffer.SetVertexUV(i, 2, FVector2D(fR, fG));
			m_StaticMeshVertexBuffer.SetVertexUV(i, 3, FVector2D(fB, fA));
#endif
		}

		//====================================================
#if SM_FOR_UE_FIVE
		GameVector2 UVT;
#else
		FVector2D UVT;
#endif
		if (smMesh.m_pDataVertex->m_nTexCoordCount > 0)
		{
#if SM_FOR_UE_FIVE
			GameVector2 UV0;
			GameVector2 UV1;
#else
			FVector2D UV0;
			FVector2D UV1;
#endif
			if (smMesh.m_pDataVertex->m_nTexCoordDim == 2)
			{
				Gameint nTexDim = smMesh.m_pDataVertex->m_nTexCoordDim;

				UV0.X = smMesh.m_pDataVertex->m_TexCoord[nTexDim * index + 0];
				UV0.Y = smMesh.m_pDataVertex->m_TexCoord[nTexDim * index + 1];

				m_StaticMeshVertexBuffer.SetVertexUV(i, 0, UV0);
				if (bModel || bModel_Translucent)
				{
#if SM_FOR_UE_FIVE
					m_StaticMeshVertexBuffer.SetVertexUV(i, 1, GameVector2(0, 0));
#else
					m_StaticMeshVertexBuffer.SetVertexUV(i, 1, FVector2D(0, 0));
#endif
				}
			}
			else if (smMesh.m_pDataVertex->m_nTexCoordDim == 3)
			{
				Gameint nTexDim = smMesh.m_pDataVertex->m_nTexCoordDim;
	
				UV0.X = smMesh.m_pDataVertex->m_TexCoord[nTexDim * index + 0];
				UV0.Y = smMesh.m_pDataVertex->m_TexCoord[nTexDim * index + 1];
				UV1.X = smMesh.m_pDataVertex->m_TexCoord[nTexDim * index + 2];
				UVT.X = UV1.X;

				m_StaticMeshVertexBuffer.SetVertexUV(i, 0, UV0);
				if (!bNewModel)
				{
					m_StaticMeshVertexBuffer.SetVertexUV(i, 1, UV1);
				}
				
			}
		}
		
		if (smMesh.m_pDataVertex->m_nTexCoordCount1 > 0 && !bNewModel)
		{
			if (smMesh.m_pDataVertex->m_nTexCoordDim1 == 2)
			{
				Gameint nTexDim = smMesh.m_pDataVertex->m_nTexCoordDim1;
				UVT.Y = smMesh.m_pDataVertex->m_TexCoord1[nTexDim * index];
				m_StaticMeshVertexBuffer.SetVertexUV(i, 1, UVT);
			}
			else if (smMesh.m_pDataVertex->m_nTexCoordDim1 == 3)
			{
				Gameint nTexDim = smMesh.m_pDataVertex->m_nTexCoordDim1;
				UVT.Y = smMesh.m_pDataVertex->m_TexCoord1[nTexDim * index + 2];
				m_StaticMeshVertexBuffer.SetVertexUV(i, 1, UVT);
			}
		}
	}

	m_arrIndices = indices;

	// 因为UE是左手坐标系，所以在UE重新计算法线后需要把索引顺序反转一下才正确。如果没重新计算法线则不用
	// 计算法线后发现正反面反了，所以不把索引顺序反转，只是把法线反转一下。如果没重新计算法线则不用
	Gamebool bReverseIndex = false;
	if (m_eDrawType == PT_TriangleList && SuperMapSDK::m_bEnableNormal)
	{
		computeFlatNormals(indices, m_PositionVertexBuffer, m_StaticMeshVertexBuffer);
		// 计算切线需要用到纹理坐标,但是会导致卡顿，等有接口控制再放开
		//if (smMesh.m_pDataVertex->m_nTexCoordCount > 0)
		//{
		//	// 计算切线
		//	computeTangentSpace(m_PositionVertexBuffer, m_StaticMeshVertexBuffer);
		//}
	}

	// 因为顶点不共用了，所以重构索引
	if (m_eDrawType == PT_TriangleList && SuperMapSDK::m_bEnableNormal)
	{
		if (indices.Num() > std::numeric_limits<uint16>::max())
		{
			m_IndexBuffer.Indices.SetNum(nIndices);
			for (Gameint i = 0; i < indices.Num(); ++i) {
				if (bReverseIndex)
				{
					indices[i] = indices.Num() - i - 1;
				}
				else
				{
					indices[i] = i;
				}
			}
			FMemory::Memcpy(m_IndexBuffer.Indices.GetData(), indices.GetData(), nIndices * sizeof(Gameuint));
		}
		else
		{
			TArray<uint16> shortIndices;
			m_ShortIndexBuffer.Indices.SetNum(nIndices);
			for (Gameint i = 0; i < indices.Num(); ++i) {
				if (bReverseIndex)
				{
					shortIndices.Add(indices.Num() - i - 1);
				}
				else
				{
					shortIndices.Add(i);
				}
			}
			FMemory::Memcpy(m_ShortIndexBuffer.Indices.GetData(), shortIndices.GetData(), nIndices * sizeof(uint16));
		}
	}
	else
	{
		if (smMesh.m_arrDataIndex[0]->m_Index != nullptr)
		{
			m_IndexBuffer.Indices.SetNum(nIndices);
			FMemory::Memcpy(m_IndexBuffer.Indices.GetData(), smMesh.m_arrDataIndex[0]->m_Index, nIndices * sizeof(Gameint));
		}
		else if (smMesh.m_arrDataIndex[0]->m_shortIndex != nullptr)
		{
			m_ShortIndexBuffer.Indices.SetNum(nIndices);
			FMemory::Memcpy(m_ShortIndexBuffer.Indices.GetData(), smMesh.m_arrDataIndex[0]->m_shortIndex, nIndices * sizeof(uint16));
		}
	}
}

EPrimitiveType FSuperMapVertexBuffer::GetDrawType(const FSMMesh& smMesh)
{
	EPrimitiveType eDrawType = PT_PointList;
	if (smMesh.m_arrDataIndex[0] == nullptr)
	{
		return eDrawType;
	}
	switch (smMesh.m_arrDataIndex[0]->m_nOperationType)
	{
	case 0:
		eDrawType = PT_TriangleList;
		break;
	case 1:
		eDrawType = PT_QuadList;
		break;
	case 2:
		eDrawType = PT_LineList;
		break;
	case 4:
		eDrawType = PT_PointList;
		break;
	case 3:
	default:
		eDrawType = PT_TriangleList;
		break;
	}
	return eDrawType;
}

Gamevoid FSuperMapVertexBuffer::CreateRenderResources_RenderThread()
{
	check(IsInRenderingThread());

	InitOrUpdateResource(&m_PositionVertexBuffer);
	InitOrUpdateResource(&m_StaticMeshVertexBuffer);
	InitOrUpdateResource(&m_ColorVertexBuffer);

	if (m_IndexBuffer.Indices.Num() > 0)
	{
		InitOrUpdateResource(&m_IndexBuffer);
	}
	if (m_ShortIndexBuffer.Indices.Num() > 0)
	{
		InitOrUpdateResource(&m_ShortIndexBuffer);
	}
}

Gamevoid FSuperMapVertexBuffer::BindBuffer_RenderThread(const FVertexFactory* pVertexFactory, FStaticMeshDataType& Data)
{
	m_PositionVertexBuffer.BindPositionVertexBuffer(pVertexFactory, Data);
	m_StaticMeshVertexBuffer.BindTangentVertexBuffer(pVertexFactory, Data);
	m_StaticMeshVertexBuffer.BindPackedTexCoordVertexBuffer(pVertexFactory, Data);
	m_StaticMeshVertexBuffer.BindLightMapVertexBuffer(pVertexFactory, Data, 0);
	m_ColorVertexBuffer.BindColorVertexBuffer(pVertexFactory, Data);
}

Gamevoid FSuperMapVertexBuffer::SetupMeshBatch(FMeshBatch& meshBatch) const
{
	FMeshBatchElement& BatchElement = meshBatch.Elements[0];

	BatchElement.FirstIndex = 0;

	Gameuint nNumPrimitives = 0;
	if (m_IndexBuffer.Indices.Num() > 0)
	{
		BatchElement.IndexBuffer = &m_IndexBuffer;
		if (m_eDrawType == PT_PointList)
		{
			nNumPrimitives = m_IndexBuffer.Indices.Num();
		}
		else if (m_eDrawType == PT_LineList)
		{
			nNumPrimitives = m_IndexBuffer.Indices.Num() / 2;
		}
		else
		{
			nNumPrimitives = m_IndexBuffer.Indices.Num() / 3;
		}
	}
	else if(m_ShortIndexBuffer.Indices.Num() > 0)
	{
		BatchElement.IndexBuffer = &m_ShortIndexBuffer;
		if (m_eDrawType == PT_PointList)
		{
			nNumPrimitives = m_ShortIndexBuffer.Indices.Num();
		}
		else if (m_eDrawType == PT_LineList)
		{
			nNumPrimitives = m_ShortIndexBuffer.Indices.Num() / 2;
		}
		else
		{
			nNumPrimitives = m_ShortIndexBuffer.Indices.Num() / 3;
		}
	}
	
	BatchElement.MaxVertexIndex = m_PositionVertexBuffer.GetNumVertices() - 1;
	BatchElement.MinVertexIndex = 0;
	BatchElement.NumPrimitives = nNumPrimitives;
}

Gamevoid FSuperMapVertexBuffer::Update_RenderThread(const FSMMesh & smMesh)
{
	FetchBuffersFromMeshData(smMesh);

	CopyGPUBufferLocked(m_PositionVertexBuffer.VertexBufferRHI, m_PositionVertexBuffer.GetVertexData(),
						m_PositionVertexBuffer.GetNumVertices() * m_PositionVertexBuffer.GetStride());
	CopyGPUBufferLocked(m_ColorVertexBuffer.VertexBufferRHI, m_ColorVertexBuffer.GetVertexData(),
						m_ColorVertexBuffer.GetNumVertices() * m_ColorVertexBuffer.GetStride());
	CopyGPUBufferLocked(m_StaticMeshVertexBuffer.TangentsVertexBuffer.VertexBufferRHI, m_StaticMeshVertexBuffer.GetTangentData(),
						m_StaticMeshVertexBuffer.GetTangentSize());
	CopyGPUBufferLocked(m_StaticMeshVertexBuffer.TexCoordVertexBuffer.VertexBufferRHI, m_StaticMeshVertexBuffer.GetTexCoordData(),
						m_StaticMeshVertexBuffer.GetTexCoordSize());
}

Gamevoid FSuperMapVertexBuffer::UpdateVertexColor_RenderThread(const FSMMesh & smMesh)
{	
	if (!m_ColorVertexBuffer.IsInitialized())
	{
		m_ColorVertexBuffer.InitResource();
	}

	FetchColorBuffersFromMeshData(smMesh);

	CopyGPUBufferLocked(m_ColorVertexBuffer.VertexBufferRHI, m_ColorVertexBuffer.GetVertexData(),
		m_ColorVertexBuffer.GetNumVertices() * m_ColorVertexBuffer.GetStride());

}

#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif