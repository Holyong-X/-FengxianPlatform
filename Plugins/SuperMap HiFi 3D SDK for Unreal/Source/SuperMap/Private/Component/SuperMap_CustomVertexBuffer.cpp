#include "Component/SuperMap_CustomVertexBuffer.h"
#include "Component/SuperMap_VertexBuffer.h"
#include "Base3D/CommonDefine.h"
#include "Base3D/StatsGroupDefine.h"
#include "Graphics3D/GameConvertor.h"

#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
FSuperMapBaseVertexBuffer::FSuperMapBaseVertexBuffer() :
	m_nVerticesNum(0)
{

}

FSuperMapBaseVertexBuffer::~FSuperMapBaseVertexBuffer()
{

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

FSuperMapCustomVertexBuffer::FSuperMapCustomVertexBuffer() :
	m_nTexCoord0Dim(0),
	m_nTexCoord1Dim(0),
	m_nHasTexMatrixBuffer(0),
	m_nHasVertexWeight(0),
	m_nCompressType(0),
	m_decodePositionNormConstant(0.0f),
	m_pDataVertex(nullptr),
	m_pInstanceBuffer(nullptr),
	m_nInstanceSize(0),
	m_nSizeInFloatPerInstance(0),
	m_pPostionBuffer(nullptr),
	m_pNormalBuffer(nullptr),
	m_pTangentBuffer(nullptr),
	m_pVertexColorBuffer(nullptr),
	m_pSecondColorBuffer(nullptr),
	m_pTexCoord0Buffer(nullptr),
	m_pTexCoord1Buffer(nullptr),
	m_pTexMatrixBuffer(nullptr),
	m_pVertexWeightBuffer(nullptr),
	m_pVertexColorData(nullptr),
	m_pInstanceVertexColorData(nullptr),
	m_bUseUGCMemory(false)
{
}

FSuperMapCustomVertexBuffer::~FSuperMapCustomVertexBuffer()
{
	if (m_pPostionBuffer != nullptr)
	{
		m_pPostionBuffer->ReleaseResource();
		delete m_pPostionBuffer;
		m_pPostionBuffer = nullptr;
	}
	if (m_pNormalBuffer != nullptr)
	{
		m_pNormalBuffer->ReleaseResource();
		delete m_pNormalBuffer;
		m_pNormalBuffer = nullptr;
	}
	if (m_pTangentBuffer != nullptr)
	{
		m_pTangentBuffer->ReleaseResource();
		delete m_pTangentBuffer;
		m_pTangentBuffer = nullptr;
	}
	if (m_pVertexColorBuffer != nullptr)
	{
		m_pVertexColorBuffer->ReleaseResource();
		delete m_pVertexColorBuffer;
		m_pVertexColorBuffer = nullptr;
	}
	if (m_pSecondColorBuffer != nullptr)
	{
		m_pSecondColorBuffer->ReleaseResource();
		delete m_pSecondColorBuffer;
		m_pSecondColorBuffer = nullptr;
	}

	if (m_pTexCoord0Buffer != nullptr)
	{
		m_pTexCoord0Buffer->ReleaseResource();
		delete m_pTexCoord0Buffer;
		m_pTexCoord0Buffer = nullptr;
	}
	if (m_pTexCoord1Buffer != nullptr)
	{
		m_pTexCoord1Buffer->ReleaseResource();
		delete m_pTexCoord1Buffer;
		m_pTexCoord1Buffer = nullptr;
	}

	if (m_pTexMatrixBuffer != nullptr)
	{
		m_pTexMatrixBuffer->ReleaseResource();
		delete m_pTexMatrixBuffer;
		m_pTexMatrixBuffer = nullptr;
	}

	if (m_pVertexWeightBuffer != nullptr)
	{
		m_pVertexWeightBuffer->ReleaseResource();
		delete m_pVertexWeightBuffer;
		m_pVertexWeightBuffer = nullptr;
	}

	m_instanceVertexBuffer.ReleaseResource();
	m_instanceColorVertexBuffer.ReleaseResource();

	if (m_pDataVertex != nullptr)
	{
		delete m_pDataVertex;
		m_pDataVertex = nullptr;
	}

	if (m_pInstanceBuffer != nullptr)
	{
		FMemory::Free(m_pInstanceBuffer);
		m_pInstanceBuffer = nullptr;
	}

	if (m_pVertexColorData != nullptr)
	{
		if (m_bUseUGCMemory)
		{
			_FreeUGUint(m_pVertexColorData);
		}
		else
		{
			FMemory::Free(m_pVertexColorData);
		}
		m_pVertexColorData = nullptr;
	}

	if (m_pInstanceVertexColorData != nullptr)
	{
		FMemory::Free(m_pInstanceVertexColorData);
		m_pInstanceVertexColorData = nullptr;
	}
}

Gamevoid FSuperMapCustomVertexBuffer::SetMesh(FSMMesh& smMesh)
{
	check(smMesh.m_arrDataIndex.Num() > 0);

	m_pDataVertex = smMesh.m_pDataVertex;
	m_pInstanceBuffer = (Gamefloat*)smMesh.m_pInstanceBuffer;
	m_nInstanceSize = smMesh.m_nIntanceSize;
	m_nSizeInFloatPerInstance = smMesh.m_nSizeInFloatPerInstance;

	smMesh.m_pDataVertex = nullptr;
	smMesh.m_pInstanceBuffer = nullptr;

	m_nVerticesNum = m_pDataVertex->m_nPosCount;
}

Gameint FSuperMapCustomVertexBuffer::GetCompressType() const
{
	return m_nCompressType;
}

InstanceTpye FSuperMapCustomVertexBuffer::GetInstanceType() const
{
	if (m_nSizeInFloatPerInstance == SIZE_PER_MODEL_INSTANCE)
	{
		return InstanceTpye::IT_MODEL;
	}
	else if(m_nSizeInFloatPerInstance == SIZE_PER_PIPE_INSTANCE)
	{
		return InstanceTpye::IT_PIPE;
	}
	return InstanceTpye::IT_NONE;
}

Gamevoid FSuperMapCustomVertexBuffer::CreateRHIVertexBuffer(FVertexBuffer* pVertexBuffer, Gamevoid* src, SIZE_T size, EBufferUsageFlags bufferUsage)
{
	FSuperMapVertexResourceArray resourceArray(src, size);
#if SM_FOR_UE_FIVE
	FRHIResourceCreateInfo CreateInfo = FRHIResourceCreateInfo(TEXT(""));
#else
	FRHIResourceCreateInfo CreateInfo;
#endif
	CreateInfo.ResourceArray = &resourceArray;
	pVertexBuffer->VertexBufferRHI = RHICreateVertexBuffer(size, bufferUsage, CreateInfo);
}

EVertexElementType FSuperMapCustomVertexBuffer::SelectFloatVetType(Gameint dim, Gamebool bCompress)
{
	check(dim >= 0 && dim < 5);
	switch (dim)
	{
	case 1:
		// 一维的数据不支持压缩
		check(!bCompress);
		return EVertexElementType::VET_Float1;
	case 2:
		return bCompress ? EVertexElementType::VET_Short2 : EVertexElementType::VET_Float2;
	case 3:
		// 三维的数据不支持压缩
		check(!bCompress);
		return EVertexElementType::VET_Float3;
	case 4:
		return bCompress ? EVertexElementType::VET_Short4 : EVertexElementType::VET_Float4;
	default:
		break;
	}
	return EVertexElementType::VET_Float4;
}

Gamevoid FSuperMapCustomVertexBuffer::CreateRenderResources_RenderThread()
{
#if! SM_FOR_UE_FIVE
	STATS_SM_CREATERENDERRESOURCE
#endif
	if (m_pDataVertex == nullptr)
	{
		return;
	}

	m_nCompressType = m_pDataVertex->m_nCompressType;
	m_bUseUGCMemory = m_pDataVertex->m_bUGMemory;

	CreatePositionBufferAndComponent();
	CreateNormalBufferAndComponent();
	CreateTangentBufferAndComponent();
	CreateVertexColorBufferAndComponent();
	CreateSecondColorBufferAndComponent();
	CreateTexCoord0BufferAndComponent();
	CreateTexCoord1BufferAndComponent();
	CreateTexMatrixBufferAndComponent();
	CreateVertexWeightAndComponent();
	CreateTilingTexCoordAndComponent();
	CreateInstanceSRV();
	CreateInstanceColorSRV();

	if (m_pDataVertex != nullptr)
	{
		delete m_pDataVertex;
		m_pDataVertex = nullptr;
	}

	if (m_pInstanceBuffer != nullptr)
	{
		FMemory::Free(m_pInstanceBuffer);
		m_pInstanceBuffer = nullptr;
	}
}

Gamevoid FSuperMapCustomVertexBuffer::UpdateVertexColor_RenderThread(const FSMMesh& smMesh)
{
	if (m_pVertexColorBuffer != nullptr)
	{
		Gameuint writeBufferSize = sizeof(Gameuint) * smMesh.m_pDataVertex->m_nColorCount;
		Gameuint offset = smMesh.m_nSubMeshInfoOffset * sizeof(Gameuint);

		Gameuint wholeBufferSize = m_pVertexColorBuffer->VertexBufferRHI.GetReference()->GetSize();

		Gamevoid* pVertexBufferData = RHILockVertexBuffer(m_pVertexColorBuffer->VertexBufferRHI, 0, wholeBufferSize, RLM_WriteOnly);
		Gameuint* pWritePos = m_pVertexColorData + smMesh.m_nSubMeshInfoOffset;
		FMemory::Memcpy(pWritePos, (Gamevoid*)smMesh.m_pDataVertex->m_PosColor, writeBufferSize);
		FMemory::Memcpy(pVertexBufferData, (Gamevoid*)m_pVertexColorData, wholeBufferSize);
		RHIUnlockVertexBuffer(m_pVertexColorBuffer->VertexBufferRHI);
	}
	else
	{
		if (m_pDataVertex != nullptr && m_pDataVertex->m_PosColor != nullptr)
		{
			// 替换颜色
			FMemory::Memcpy(m_pDataVertex->m_PosColor + smMesh.m_nSubMeshInfoOffset,
				smMesh.m_pDataVertex->m_PosColor, sizeof(Gameuint) * smMesh.m_pDataVertex->m_nColorCount);
		}
	}
}

Gamevoid FSuperMapCustomVertexBuffer::UpdateVertex_RenderThread(const FSMMesh& smMesh)
{
	if (m_pPostionBuffer != nullptr)
	{
		uint32 offset = smMesh.m_nSubMeshInfoOffset * sizeof(Gameuint);
		uint32 wholeBufferSize = m_pPostionBuffer->VertexBufferRHI.GetReference()->GetSize();

		void* pVertexBufferData = RHILockVertexBuffer(m_pPostionBuffer->VertexBufferRHI, 0, wholeBufferSize, RLM_WriteOnly);
		FMemory::Memcpy(pVertexBufferData, (void*)smMesh.m_pDataVertex->m_Pos, wholeBufferSize);
		RHIUnlockVertexBuffer(m_pPostionBuffer->VertexBufferRHI);
	}
	else
	{
		if (m_pDataVertex != nullptr && m_pDataVertex->m_Pos != nullptr)
		{
			// 替换顶点
			FMemory::Memcpy(m_pDataVertex->m_Pos + smMesh.m_nSubMeshInfoOffset,
				smMesh.m_pDataVertex->m_Pos, sizeof(Gameuint) * smMesh.m_pDataVertex->m_nPosCount * smMesh.m_pDataVertex->m_nPosDim);
		}
	}
}

Gamevoid FSuperMapCustomVertexBuffer::UpdateInstanceVertexColor_RenderThread(Gameuint nColor, const TArray<Gameuint>& arrIds)
{
	if (!m_instanceColorVertexBuffer.VertexBufferRHI.IsValid())
	{
		return;
	}

	Gameuint wholeBufferSize = m_instanceColorVertexBuffer.VertexBufferRHI.GetReference()->GetSize();
	Gamevoid* pVertexBufferData = RHILockVertexBuffer(m_instanceColorVertexBuffer.VertexBufferRHI, 0, wholeBufferSize, RLM_WriteOnly);
	for (Gameint i = 0; i < arrIds.Num(); i++)
	{
		m_pInstanceVertexColorData[arrIds[i]] = nColor;
	}
	FMemory::Memcpy(pVertexBufferData, (Gamevoid*)m_pInstanceVertexColorData, wholeBufferSize);
	RHIUnlockVertexBuffer(m_instanceColorVertexBuffer.VertexBufferRHI);
}

Gamevoid FSuperMapCustomVertexBuffer::UpdateCustomVertexAttribute0_RenderThread(const FSMMesh& smMesh)
{
	VertexAttribute vertexAttribute = smMesh.m_pDataVertex->m_vecVertexAttribute[VertexAttributeDescript::VERTEXWEIGHT];
	if (m_pVertexWeightBuffer != nullptr)
	{
		uint32 writeBufferSize = sizeof(Gamefloat) * vertexAttribute.m_nVertexAttDataDimension * vertexAttribute.m_nVertexAttDataCount;
		uint32 offset = smMesh.m_nSubMeshInfoOffset * sizeof(Gamefloat);
		uint32 wholeBufferSize = m_pVertexWeightBuffer->VertexBufferRHI.GetReference()->GetSize();
		void* pVertexBufferData = RHILockVertexBuffer(m_pVertexWeightBuffer->VertexBufferRHI, 0, wholeBufferSize, RLM_WriteOnly);
		FMemory::Memcpy(pVertexBufferData, (void*)vertexAttribute.m_pVertexAttData, wholeBufferSize);
		RHIUnlockVertexBuffer(m_pVertexWeightBuffer->VertexBufferRHI);
	}
}

Gamevoid FSuperMapCustomVertexBuffer::CreatePositionBufferAndComponent()
{
	if (m_pDataVertex->m_Pos == nullptr)
	{
		return;
	}

	m_pPostionBuffer = new FVertexBuffer();
	m_pPostionBuffer->InitResource();
	Gameuint nValueBytes = 0;
	Gamebool compress = GameConvertor::HasCompressOptions(m_pDataVertex->m_nCompressType, VertexCompressOptions::SVC_Vertex);
	if (compress)
	{
		nValueBytes = sizeof(Gameushort);
	}
	else
	{
		nValueBytes = sizeof(Gamefloat);
	}

	Gameuint bufferSize = nValueBytes * m_pDataVertex->m_nPosDim * m_pDataVertex->m_nPosCount;
#if SM_FOR_UE_FIVE
	CreateRHIVertexBuffer(m_pPostionBuffer, m_pDataVertex->m_Pos, bufferSize, EBufferUsageFlags::Static);
#else
	CreateRHIVertexBuffer(m_pPostionBuffer, m_pDataVertex->m_Pos, bufferSize, EBufferUsageFlags::BUF_Static);
#endif

	m_PostionStreamComponent.Offset = 0;
	m_PostionStreamComponent.StreamOffset = 0;
	m_PostionStreamComponent.Stride = nValueBytes * m_pDataVertex->m_nPosDim;
	m_PostionStreamComponent.Type = SelectFloatVetType(m_pDataVertex->m_nPosDim, compress);
	m_PostionStreamComponent.VertexBuffer = m_pPostionBuffer;

	m_decodePositionMin = m_pDataVertex->m_vMinVerticesValue;
	m_decodePositionNormConstant = m_pDataVertex->m_fVertCompressConstant;
}

Gamevoid FSuperMapCustomVertexBuffer::CreateNormalBufferAndComponent()
{
	if (m_pDataVertex->m_Normal == nullptr)
	{
		return;
	}
	m_pNormalBuffer = new FVertexBuffer();
	m_pNormalBuffer->InitResource();
	Gameuint nValueBytes = 0;
	Gamebool compress = GameConvertor::HasCompressOptions(m_pDataVertex->m_nCompressType, VertexCompressOptions::SVC_Normal);
	if (compress)
	{
		nValueBytes = sizeof(Gameushort);
	}
	else
	{
		nValueBytes = sizeof(Gamefloat);
	}
	Gameuint bufferSize = nValueBytes * m_pDataVertex->m_nNormalDim * m_pDataVertex->m_nNormalCount;
#if SM_FOR_UE_FIVE
	CreateRHIVertexBuffer(m_pNormalBuffer, m_pDataVertex->m_Normal, bufferSize, EBufferUsageFlags::Static);
#else
	CreateRHIVertexBuffer(m_pNormalBuffer, m_pDataVertex->m_Normal, bufferSize, EBufferUsageFlags::BUF_Static);
#endif

	m_pNormalStreamComponent.Offset = 0;
	m_pNormalStreamComponent.StreamOffset = 0;
	m_pNormalStreamComponent.Stride = nValueBytes * m_pDataVertex->m_nNormalDim;
	m_pNormalStreamComponent.Type = SelectFloatVetType(m_pDataVertex->m_nNormalDim, compress);
	m_pNormalStreamComponent.VertexBuffer = m_pNormalBuffer;
}

Gamevoid FSuperMapCustomVertexBuffer::CreateTangentBufferAndComponent()
{
	if (m_pDataVertex->m_Tangent == nullptr)
	{
		return;
	}

	m_pTangentBuffer = new FVertexBuffer();
	m_pTangentBuffer->InitResource();
	Gameuint nValueBytes = 0;
	Gamebool compress = GameConvertor::HasCompressOptions(m_pDataVertex->m_nCompressType, VertexCompressOptions::SVC_Normal);
	if (compress)
	{
		nValueBytes = sizeof(Gameushort);
	}
	else
	{
		nValueBytes = sizeof(Gamefloat);
	}
	Gameuint bufferSize = nValueBytes * m_pDataVertex->m_nTangentDim * m_pDataVertex->m_nTangentCount;

#if SM_FOR_UE_FIVE
	CreateRHIVertexBuffer(m_pTangentBuffer, m_pDataVertex->m_Tangent, bufferSize, EBufferUsageFlags::Static);
#else
	CreateRHIVertexBuffer(m_pTangentBuffer, m_pDataVertex->m_Tangent, bufferSize, EBufferUsageFlags::BUF_Static);
#endif 

	// 创建
	m_pTangentStreamComponent.Offset = 0;
	m_pTangentStreamComponent.StreamOffset = 0;
	m_pTangentStreamComponent.Stride = nValueBytes * m_pDataVertex->m_nTangentDim;
	m_pTangentStreamComponent.Type = SelectFloatVetType(m_pDataVertex->m_nTangentDim, compress);
	m_pTangentStreamComponent.VertexBuffer = m_pTangentBuffer;
}
Gamevoid FSuperMapCustomVertexBuffer::CreateVertexColorBufferAndComponent()
{
	if (m_pDataVertex->m_PosColor == nullptr)
	{
		return;
	}
	m_pVertexColorBuffer = new FVertexBuffer();
	m_pVertexColorBuffer->InitResource();
	Gameuint bufferSize = sizeof(Gameuint) * m_pDataVertex->m_nColorCount;

#if SM_FOR_UE_FIVE
	CreateRHIVertexBuffer(m_pVertexColorBuffer, m_pDataVertex->m_PosColor, bufferSize, EBufferUsageFlags::Static);
#else
	CreateRHIVertexBuffer(m_pVertexColorBuffer, m_pDataVertex->m_PosColor, bufferSize, EBufferUsageFlags::BUF_Static);
#endif

	m_pVertexColorData = m_pDataVertex->m_PosColor;
	m_pDataVertex->m_PosColor = nullptr;

	m_pVertexColorStreamComponent.Offset = 0;
	m_pVertexColorStreamComponent.StreamOffset = 0;
	m_pVertexColorStreamComponent.Stride = sizeof(Gameuint);
	m_pVertexColorStreamComponent.Type = EVertexElementType::VET_Color;
	m_pVertexColorStreamComponent.VertexBuffer = m_pVertexColorBuffer;
}

Gamevoid FSuperMapCustomVertexBuffer::CreateSecondColorBufferAndComponent()
{
	if (m_pDataVertex->m_PosSceondColor == nullptr)
	{
		return;
	}
	m_pSecondColorBuffer = new FVertexBuffer();
	m_pSecondColorBuffer->InitResource();
	Gameuint bufferSize = sizeof(Gameuint) * m_pDataVertex->m_nSecondColorCount;
#if SM_FOR_UE_FIVE
	CreateRHIVertexBuffer(m_pSecondColorBuffer, m_pDataVertex->m_PosSceondColor, bufferSize, EBufferUsageFlags::Static);
#else
	CreateRHIVertexBuffer(m_pSecondColorBuffer, m_pDataVertex->m_PosSceondColor, bufferSize, EBufferUsageFlags::BUF_Static);
#endif
	
	m_pSecondColorStreamComponent.Offset = 0;
	m_pSecondColorStreamComponent.StreamOffset = 0;
	m_pSecondColorStreamComponent.Stride = sizeof(Gameuint);
	m_pSecondColorStreamComponent.Type = EVertexElementType::VET_Color;
	m_pSecondColorStreamComponent.VertexBuffer = m_pSecondColorBuffer;
}

Gamevoid FSuperMapCustomVertexBuffer::CreateTexCoord0BufferAndComponent()
{
	if (m_pDataVertex->m_TexCoord == nullptr)
	{
		return;
	}
	m_pTexCoord0Buffer = new FVertexBuffer();
	m_pTexCoord0Buffer->InitResource();
	Gameuint nValueBytes = 0;
	Gamebool compress = GameConvertor::HasCompressOptions(m_pDataVertex->m_nCompressType, VertexCompressOptions::SVC_TexutreCoord);
	if (compress)
	{
		nValueBytes = sizeof(Gameushort);
	}
	else
	{
		nValueBytes = sizeof(Gamefloat);
	}
	Gameuint bufferSize = nValueBytes * m_pDataVertex->m_nTexCoordDim * m_pDataVertex->m_nTexCoordCount;
#if SM_FOR_UE_FIVE
	CreateRHIVertexBuffer(m_pTexCoord0Buffer, m_pDataVertex->m_TexCoord, bufferSize, EBufferUsageFlags::Static);
#else
	CreateRHIVertexBuffer(m_pTexCoord0Buffer, m_pDataVertex->m_TexCoord, bufferSize, EBufferUsageFlags::BUF_Static);
#endif

	m_pTexCoord0StreamComponent.Offset = 0;
	m_pTexCoord0StreamComponent.StreamOffset = 0;
	m_pTexCoord0StreamComponent.Stride = nValueBytes * m_pDataVertex->m_nTexCoordDim;
	m_pTexCoord0StreamComponent.Type = SelectFloatVetType(m_pDataVertex->m_nTexCoordDim, compress);
	m_pTexCoord0StreamComponent.VertexBuffer = m_pTexCoord0Buffer;

	m_decodeTexCoord0Min = m_pDataVertex->m_texCoord0Min;
	m_texCoord0CompressConstant = m_pDataVertex->m_texCoordCompressUV0Constant;

	m_nTexCoord0Dim = m_pDataVertex->m_nTexCoordDim;
}

Gamevoid FSuperMapCustomVertexBuffer::CreateTexCoord1BufferAndComponent()
{
	if (m_pDataVertex->m_TexCoord1 == nullptr || m_pDataVertex->m_nTexCoordCount1 == 0)
	{
		return;
	}
	m_pTexCoord1Buffer = new FVertexBuffer();
	m_pTexCoord1Buffer->InitResource();
	Gameuint nValueBytes = 0;
	Gamebool compress = GameConvertor::HasCompressOptions(m_pDataVertex->m_nCompressType, VertexCompressOptions::SVC_TexutreCoord);
	if (compress)
	{
		nValueBytes = sizeof(Gameushort);
	}
	else
	{
		nValueBytes = sizeof(Gamefloat);
	}
	Gameuint bufferSize = nValueBytes * m_pDataVertex->m_nTexCoordDim1 * m_pDataVertex->m_nTexCoordCount1;
#if SM_FOR_UE_FIVE
	CreateRHIVertexBuffer(m_pTexCoord1Buffer, m_pDataVertex->m_TexCoord1, bufferSize, EBufferUsageFlags::Static);
#else
	CreateRHIVertexBuffer(m_pTexCoord1Buffer, m_pDataVertex->m_TexCoord1, bufferSize, EBufferUsageFlags::BUF_Static);
#endif
	m_pTexCoord1StreamComponent.Offset = 0;
	m_pTexCoord1StreamComponent.StreamOffset = 0;
	m_pTexCoord1StreamComponent.Stride = nValueBytes * m_pDataVertex->m_nTexCoordDim1;
	m_pTexCoord1StreamComponent.Type = SelectFloatVetType(m_pDataVertex->m_nTexCoordDim1, compress);
	m_pTexCoord1StreamComponent.VertexBuffer = m_pTexCoord1Buffer;

	m_decodeTexCoord1Min = m_pDataVertex->m_texCoord1Min;
	m_texCoord1CompressConstant = m_pDataVertex->m_texCoordCompressUV1Constant;

	m_nTexCoord1Dim = m_pDataVertex->m_nTexCoordDim1;
}

Gamevoid FSuperMapCustomVertexBuffer::CreateTexMatrixBufferAndComponent()
{
	if (m_pDataVertex->m_pBlendWeights == nullptr && m_pDataVertex->m_vecVertexAttribute.Num() == 0)
	{
		return;
	}
	m_pTexMatrixBuffer = new FVertexBuffer();
	m_pTexMatrixBuffer->InitResource();

	// block数据会用到m_pBlendWeights，和m_vecVertexAttribute中的纹理矩阵只会有一个存在
	if (m_pDataVertex->m_pBlendWeights != nullptr)
	{
		Gameuint nValueBytes = sizeof(Gamefloat);
		Gameuint bufferSize = nValueBytes * m_pDataVertex->m_nBlendWeightsCount;
#if SM_FOR_UE_FIVE
		CreateRHIVertexBuffer(m_pTexMatrixBuffer, m_pDataVertex->m_pBlendWeights, bufferSize, EBufferUsageFlags::Static);
#else
		CreateRHIVertexBuffer(m_pTexMatrixBuffer, m_pDataVertex->m_pBlendWeights, bufferSize, EBufferUsageFlags::BUF_Static);
#endif
		
		m_pTexMatrixStreamComponent.Offset = 0;
		m_pTexMatrixStreamComponent.StreamOffset = 0;
		m_pTexMatrixStreamComponent.Stride = nValueBytes;
		m_pTexMatrixStreamComponent.Type = SelectFloatVetType(1, false);
		m_pTexMatrixStreamComponent.VertexBuffer = m_pTexMatrixBuffer;
	}
	else
	{
		VertexAttribute vertexAttribute = m_pDataVertex->m_vecVertexAttribute[VertexAttributeDescript::TEXTURECOORDMATRIX];
		if (vertexAttribute.m_pVertexAttData == nullptr)
		{
			return;
		}

		Gameuint nValueBytes = sizeof(Gamefloat);
		Gameuint bufferSize = nValueBytes * vertexAttribute.m_nVertexAttDataCount * vertexAttribute.m_nVertexAttDataDimension;
#if SM_FOR_UE_FIVE
		CreateRHIVertexBuffer(m_pTexMatrixBuffer, vertexAttribute.m_pVertexAttData, bufferSize, EBufferUsageFlags::Static);
#else
		CreateRHIVertexBuffer(m_pTexMatrixBuffer, vertexAttribute.m_pVertexAttData, bufferSize, EBufferUsageFlags::BUF_Static);
#endif
		
		m_pTexMatrixStreamComponent.Offset = 0;
		m_pTexMatrixStreamComponent.StreamOffset = 0;
		m_pTexMatrixStreamComponent.Stride = nValueBytes * vertexAttribute.m_nVertexAttDataDimension;
		m_pTexMatrixStreamComponent.Type = SelectFloatVetType(vertexAttribute.m_nVertexAttDataDimension, false);
		m_pTexMatrixStreamComponent.VertexBuffer = m_pTexMatrixBuffer;
	}
	

	m_nHasTexMatrixBuffer = 1;
	
}

Gamevoid FSuperMapCustomVertexBuffer::CreateVertexWeightAndComponent()
{

	if (m_pDataVertex->m_vecVertexAttribute.Num() == 0)
	{
		return;
	}
	VertexAttribute vertexAttribute = m_pDataVertex->m_vecVertexAttribute[VertexAttributeDescript::VERTEXWEIGHT];
	if (vertexAttribute.m_pVertexAttData == nullptr)
	{
		return;
	}
	m_pVertexWeightBuffer = new FVertexBuffer();
	m_pVertexWeightBuffer->InitResource();
	Gameuint nValueBytes = sizeof(Gamefloat);
	switch (vertexAttribute.m_enVertexAttDataType)
	{
	case VertexAttributeType::AT_32BIT:
	{
		nValueBytes = sizeof(Gameint);
		break;
	}
	case VertexAttributeType::AT_FLOAT:
	{
		nValueBytes = sizeof(Gamefloat);
		break;
	}
	case VertexAttributeType::AT_16BIT:
	{
		nValueBytes = sizeof(Gameushort);
		break;
	}
	default:
		break;
	}

	Gameuint bufferSize = nValueBytes * vertexAttribute.m_nVertexAttDataCount * vertexAttribute.m_nVertexAttDataDimension;
#if SM_FOR_UE_FIVE
	CreateRHIVertexBuffer(m_pVertexWeightBuffer, vertexAttribute.m_pVertexAttData, bufferSize, EBufferUsageFlags::Static);
#else
	CreateRHIVertexBuffer(m_pVertexWeightBuffer, vertexAttribute.m_pVertexAttData, bufferSize, EBufferUsageFlags::BUF_Static);
#endif
	
	m_pVertexWeightStreamComponent.Offset = 0;
	m_pVertexWeightStreamComponent.StreamOffset = 0;
	m_pVertexWeightStreamComponent.Stride = nValueBytes * vertexAttribute.m_nVertexAttDataDimension;
	m_pVertexWeightStreamComponent.Type = SelectFloatVetType(vertexAttribute.m_nVertexAttDataDimension, false);
	m_pVertexWeightStreamComponent.VertexBuffer = m_pVertexWeightBuffer;
	m_nHasVertexWeight = 1;
}

Gamevoid FSuperMapCustomVertexBuffer::CreateTilingTexCoordAndComponent()
{
	if (m_pDataVertex->m_vecVertexAttribute.Num() == 0)
	{
		return;
	}
	VertexAttribute vertexAttribute = m_pDataVertex->m_vecVertexAttribute[VertexAttributeDescript::TILINGTEXTURECOORDS];
	if (vertexAttribute.m_pVertexAttData == nullptr)
	{
		return;
	}

	m_pTilingTexCoordBuffer = new FVertexBuffer();
	m_pTilingTexCoordBuffer->InitResource();

	Gameuint nValueBytes = sizeof(Gamefloat);
	switch (vertexAttribute.m_enVertexAttDataType)
	{
	case VertexAttributeType::AT_32BIT:
	{
		nValueBytes = sizeof(Gameint);
		break;
	}
	case VertexAttributeType::AT_FLOAT:
	{
		nValueBytes = sizeof(Gamefloat);
		break;
	}
	case VertexAttributeType::AT_16BIT:
	{
		nValueBytes = sizeof(Gameushort);
		break;
	}
	default:
		break;
	}

	Gameuint bufferSize = nValueBytes * vertexAttribute.m_nVertexAttDataCount * vertexAttribute.m_nVertexAttDataDimension;
#if SM_FOR_UE_FIVE
	CreateRHIVertexBuffer(m_pTilingTexCoordBuffer, vertexAttribute.m_pVertexAttData, bufferSize, EBufferUsageFlags::Static);
#else
	CreateRHIVertexBuffer(m_pTilingTexCoordBuffer, vertexAttribute.m_pVertexAttData, bufferSize, EBufferUsageFlags::BUF_Static);
#endif
	
	m_pTilingTexCoordStreamComponent.Offset = 0;
	m_pTilingTexCoordStreamComponent.StreamOffset = 0;
	m_pTilingTexCoordStreamComponent.Stride = nValueBytes * vertexAttribute.m_nVertexAttDataDimension;
	m_pTilingTexCoordStreamComponent.Type = SelectFloatVetType(vertexAttribute.m_nVertexAttDataDimension, false);
	m_pTilingTexCoordStreamComponent.VertexBuffer = m_pTilingTexCoordBuffer;
}

Gamevoid FSuperMapCustomVertexBuffer::CreateInstanceSRV()
{
	if (m_nInstanceSize == 0 || m_pInstanceBuffer == nullptr)
	{
		return;
	}
	Gameuint nValueBytes = sizeof(Gamefloat);
	Gameuint bufferSize = nValueBytes * m_nInstanceSize * m_nSizeInFloatPerInstance;
	FSuperMapVertexResourceArray ResourceArray(m_pInstanceBuffer, bufferSize);
#if SM_FOR_UE_FIVE
	FRHIResourceCreateInfo CreateInfo = FRHIResourceCreateInfo(TEXT("InstanceBuffer"));
#else
	FRHIResourceCreateInfo CreateInfo;
#endif
	CreateInfo.ResourceArray = &ResourceArray;
	m_instanceVertexBuffer.VertexBufferRHI = RHICreateVertexBuffer(bufferSize, BUF_Static | BUF_ShaderResource, CreateInfo);
	m_InstanceSRV = RHICreateShaderResourceView(m_instanceVertexBuffer.VertexBufferRHI, 4, PF_R32_FLOAT);
}

Gameuint GetAsLongABGR(Gamefloat r, Gamefloat g, Gamefloat b, Gamefloat a)
{
	Gameuchar val8;
	Gameuint val32 = 0;

	// Alpha
	val8 = (Gameuchar)(a * 255);
	val32 = val8 << 24;

	// Blue
	val8 = (Gameuchar)(b * 255);
	val32 += val8 << 16;

	// Green
	val8 = (Gameuchar)(g * 255);
	val32 += val8 << 8;

	// Red
	val8 = (Gameuchar)(r * 255);
	val32 += val8;
	return val32;
}

Gamevoid FSuperMapCustomVertexBuffer::CreateInstanceColorSRV()
{
	if (m_nInstanceSize == 0 || m_pInstanceBuffer == nullptr)
	{
		return;
	}
	
	Gameuint nValueBytes = sizeof(Gameuint);
	Gameuint bufferSize = nValueBytes * m_nInstanceSize;
	m_pInstanceVertexColorData = (Gameuint*)FMemory::Malloc(bufferSize);
	Gameuint* pUint = (Gameuint*)m_pInstanceBuffer;
	if (m_nSizeInFloatPerInstance == SIZE_PER_MODEL_INSTANCE)
	{
		for (Gameint i = 0; i < m_nInstanceSize; i++)
		{
			Gamefloat r = m_pInstanceBuffer[i * SIZE_PER_MODEL_INSTANCE + 12];
			Gamefloat g = m_pInstanceBuffer[i * SIZE_PER_MODEL_INSTANCE + 13];
			Gamefloat b = m_pInstanceBuffer[i * SIZE_PER_MODEL_INSTANCE + 14];
			Gamefloat a = m_pInstanceBuffer[i * SIZE_PER_MODEL_INSTANCE + 15];
			m_pInstanceVertexColorData[i] = GetAsLongABGR(r, g, b, a);
		}
	}
	else if (m_nSizeInFloatPerInstance == SIZE_PER_PIPE_INSTANCE)
	{
		for (Gameint i = 0; i < m_nInstanceSize; i++)
		{
			m_pInstanceVertexColorData[i] = pUint[i * SIZE_PER_PIPE_INSTANCE + 27];
		}
	}
	FSuperMapVertexResourceArray ResourceArray(m_pInstanceVertexColorData, bufferSize);
#if SM_FOR_UE_FIVE
	FRHIResourceCreateInfo CreateInfo = FRHIResourceCreateInfo(TEXT("InstanceColorBuffer"));
#else
	FRHIResourceCreateInfo CreateInfo;
#endif
	CreateInfo.ResourceArray = &ResourceArray;
	m_instanceColorVertexBuffer.VertexBufferRHI = RHICreateVertexBuffer(bufferSize, BUF_Static | BUF_ShaderResource, CreateInfo);
	m_InstanceColorSRV = RHICreateShaderResourceView(m_instanceColorVertexBuffer.VertexBufferRHI, sizeof(Gamefloat), PF_R32_FLOAT);
}

Gamevoid FSuperMapCustomVertexBuffer::ReleaseResource()
{
	if (m_pPostionBuffer != nullptr)
	{
		m_pPostionBuffer->ReleaseRHI();
	}
	if (m_pNormalBuffer != nullptr)
	{
		m_pNormalBuffer->ReleaseRHI();
	}
	if (m_pTangentBuffer != nullptr)
	{
		m_pTangentBuffer->ReleaseRHI();
	}
	if (m_pVertexColorBuffer != nullptr)
	{
		m_pVertexColorBuffer->ReleaseRHI();
	}
	if (m_pSecondColorBuffer != nullptr)
	{
		m_pSecondColorBuffer->ReleaseRHI();
	}
	if (m_pTexCoord0Buffer != nullptr)
	{
		m_pTexCoord0Buffer->ReleaseRHI();
	}
	if (m_pTexCoord1Buffer != nullptr)
	{
		m_pTexCoord1Buffer->ReleaseRHI();
	}
	if (m_pTexMatrixBuffer != nullptr)
	{
		m_pTexMatrixBuffer->ReleaseRHI();
	}

	m_instanceVertexBuffer.ReleaseRHI();
	m_instanceColorVertexBuffer.ReleaseRHI();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

FSuperMapRenderSection::FSuperMapRenderSection() :
	m_eDrawType(PT_TriangleList),
	m_nPrimitivesNum(0),
	m_pDataIndex(nullptr),
	m_pIndexBuffer(nullptr)
{
}

FSuperMapRenderSection::~FSuperMapRenderSection()
{
	if (m_pDataIndex != nullptr)
	{
		delete m_pDataIndex;
		m_pDataIndex = nullptr;
	}

	if (m_pIndexBuffer != nullptr)
	{
		m_pIndexBuffer->ReleaseResource();
		delete m_pIndexBuffer;
		m_pIndexBuffer = nullptr;
	}
}

Gamevoid FSuperMapRenderSection::ReleaseResource()
{
	if (m_pIndexBuffer != nullptr)
	{
		m_pIndexBuffer->ReleaseRHI();
	}
}

Gamevoid FSuperMapRenderSection::CreateRenderResources_RenderThread()
{
	if (m_pDataIndex == nullptr)
	{
		return;
	}
	m_pIndexBuffer = new FIndexBuffer();
	m_pIndexBuffer->InitResource();
	Gameuint indexStride = 0;
	Gamevoid* pIndex = nullptr;
	if (m_pDataIndex->m_enIndexType == 0)
	{
		indexStride = sizeof(Gameushort);
		pIndex = m_pDataIndex->m_shortIndex;
	}
	else
	{
		indexStride = sizeof(Gameuint);
		pIndex = m_pDataIndex->m_Index;
	}

	Gameuint bufferSize = indexStride * m_pDataIndex->m_nIndexCount;
	FSuperMapVertexResourceArray resourceArray(pIndex, bufferSize);
#if SM_FOR_UE_FIVE
	FRHIResourceCreateInfo CreateInfo = FRHIResourceCreateInfo(TEXT(""));
#else
	FRHIResourceCreateInfo CreateInfo;
#endif
	CreateInfo.ResourceArray = &resourceArray;
	m_pIndexBuffer->IndexBufferRHI = RHICreateIndexBuffer(indexStride, bufferSize, BUF_Static, CreateInfo);

	if (m_pDataIndex != nullptr)
	{
		delete m_pDataIndex;
		m_pDataIndex = nullptr;
	}
}

Gamevoid FSuperMapRenderSection::SetMesh(DataIndice*& pDataIndice)
{
	if (pDataIndice == nullptr)
	{
		return;
	}

	m_eDrawType = GetDrawType(pDataIndice->m_nOperationType);

	if (m_eDrawType == PT_PointList)
	{
		// TODO
		m_nPrimitivesNum = pDataIndice->m_nIndexCount;
	}
	else if (m_eDrawType == PT_LineList)
	{
		m_nPrimitivesNum = pDataIndice->m_nIndexCount / 2;
	}
	else
	{
		m_nPrimitivesNum = pDataIndice->m_nIndexCount / 3;
	}
	m_pDataIndex = pDataIndice;
	pDataIndice = nullptr;
}

EPrimitiveType FSuperMapRenderSection::GetDrawType(Gameint ugOperationType)
{
	EPrimitiveType eDrawType = PT_PointList;
	switch (ugOperationType)
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

#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif