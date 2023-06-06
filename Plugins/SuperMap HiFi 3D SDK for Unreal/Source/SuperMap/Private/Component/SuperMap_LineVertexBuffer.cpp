#include "Component/SuperMap_LineVertexBuffer.h"
#include "Base3D/CommonDefine.h"
#include "Base3D/StatsGroupDefine.h"
#include "Graphics3D/GameConvertor.h"
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif
FSuperMapLineVertexBuffer::FSuperMapLineVertexBuffer() :
	m_pSidenessBuffer(nullptr),
	m_pSecondColorBuffer(nullptr),
	m_pPostion0Buffer(nullptr),
	m_pPostion1Buffer(nullptr),
	m_pFaceNormal0Buffer(nullptr),
	m_pFaceNormal1Buffer(nullptr),
	m_pIndexBuffer(nullptr),
	m_pDataVertex(nullptr),
	m_pDataIndex(nullptr),
	m_nPrimitivesNum(0),
	m_fLineWidth(1.0f)

{
}

FSuperMapLineVertexBuffer::~FSuperMapLineVertexBuffer()
{
	if (m_pSidenessBuffer != nullptr)
	{
		m_pSidenessBuffer->ReleaseResource();
		delete m_pSidenessBuffer;
		m_pSidenessBuffer = nullptr;
	}

	if (m_pSecondColorBuffer != nullptr)
	{
		m_pSecondColorBuffer->ReleaseResource();
		delete m_pSecondColorBuffer;
		m_pSecondColorBuffer = nullptr;
	}

	if (m_pPostion0Buffer != nullptr)
	{
		m_pPostion0Buffer->ReleaseResource();
		delete m_pPostion0Buffer;
		m_pPostion0Buffer = nullptr;
	}

	if (m_pPostion1Buffer != nullptr)
	{
		m_pPostion1Buffer->ReleaseResource();
		delete m_pPostion1Buffer;
		m_pPostion1Buffer = nullptr;
	}

	if (m_pFaceNormal0Buffer != nullptr)
	{
		m_pFaceNormal0Buffer->ReleaseResource();
		delete m_pFaceNormal0Buffer;
		m_pFaceNormal0Buffer = nullptr;
	}

	if (m_pFaceNormal1Buffer != nullptr)
	{
		m_pFaceNormal1Buffer->ReleaseResource();
		delete m_pFaceNormal1Buffer;
		m_pFaceNormal1Buffer = nullptr;
	}

	if (m_pIndexBuffer != nullptr)
	{
		m_pIndexBuffer->ReleaseResource();
		delete m_pIndexBuffer;
		m_pIndexBuffer = nullptr;
	}
}

void FSuperMapLineVertexBuffer::SetMesh(FSMMesh& smMesh)
{
	check(smMesh.m_pDataVertex != nullptr && smMesh.m_arrDataIndex.Num() > 0);

	m_pDataVertex = smMesh.m_pDataVertex;
	m_pDataIndex = smMesh.m_arrDataIndex[0];

	smMesh.m_pDataVertex = nullptr;
	smMesh.m_arrDataIndex[0] = nullptr;
	smMesh.m_arrDataIndex.Empty();

	m_nVerticesNum = m_pDataVertex->m_nPosCount;
	m_nPrimitivesNum = m_pDataIndex->m_nIndexCount / 3;
}

void FSuperMapLineVertexBuffer::SetupMeshBatch(FMeshBatch& meshBatch) const
{
	FMeshBatchElement& BatchElement = meshBatch.Elements[0];
	BatchElement.FirstIndex = 0;
	BatchElement.MaxVertexIndex = m_nVerticesNum - 1;
	BatchElement.MinVertexIndex = 0;
	BatchElement.NumPrimitives = m_nPrimitivesNum;
	BatchElement.IndexBuffer = m_pIndexBuffer;
}

void FSuperMapLineVertexBuffer::CreateRHIVertexBuffer(FVertexBuffer* pVertexBuffer, void* src, SIZE_T size, EBufferUsageFlags bufferUsage)
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

void FSuperMapLineVertexBuffer::CreateSidenessBufferAndComponent()
{
	if (m_pDataVertex->m_Pos == nullptr)
	{
		return;
	}

	m_pSidenessBuffer = new FVertexBuffer();
	m_pSidenessBuffer->InitResource();
	uint32 nValueBytes = sizeof(Gamefloat);
	uint32 bufferSize = nValueBytes * m_pDataVertex->m_nPosDim * m_pDataVertex->m_nPosCount;
#if SM_FOR_UE_FIVE
	CreateRHIVertexBuffer(m_pSidenessBuffer, m_pDataVertex->m_Pos, bufferSize, EBufferUsageFlags::Static);
#else
	CreateRHIVertexBuffer(m_pSidenessBuffer, m_pDataVertex->m_Pos, bufferSize, EBufferUsageFlags::BUF_Static);
#endif

	m_SidenessStreamComponent.Offset = 0;
	m_SidenessStreamComponent.StreamOffset = 0;
	m_SidenessStreamComponent.Stride = nValueBytes * m_pDataVertex->m_nPosDim;
	m_SidenessStreamComponent.Type = EVertexElementType::VET_Float3;
	m_SidenessStreamComponent.VertexBuffer = m_pSidenessBuffer;
}

void FSuperMapLineVertexBuffer::CreateSecondColorBufferAndComponent()
{
	if (m_pDataVertex->m_PosSceondColor == nullptr)
	{
		return;
	}
	m_pSecondColorBuffer = new FVertexBuffer();
	m_pSecondColorBuffer->InitResource();
	uint32 bufferSize = sizeof(Gameuint) * m_pDataVertex->m_nSecondColorCount;
#if SM_FOR_UE_FIVE
	CreateRHIVertexBuffer(m_pSecondColorBuffer, m_pDataVertex->m_PosSceondColor, bufferSize, EBufferUsageFlags::Static);
#else
	CreateRHIVertexBuffer(m_pSecondColorBuffer, m_pDataVertex->m_PosSceondColor, bufferSize, EBufferUsageFlags::BUF_Static);
#endif

	m_SecondColorStreamComponent.Offset = 0;
	m_SecondColorStreamComponent.StreamOffset = 0;
	m_SecondColorStreamComponent.Stride = sizeof(Gameuint);
	m_SecondColorStreamComponent.Type = EVertexElementType::VET_Color;
	m_SecondColorStreamComponent.VertexBuffer = m_pSecondColorBuffer;
}

void FSuperMapLineVertexBuffer::CreatePosition0BufferAndComponent()
{
	if (m_pDataVertex->m_TexCoord == nullptr)
	{
		return;
	}
	m_pPostion0Buffer = new FVertexBuffer();
	m_pPostion0Buffer->InitResource();
	uint32 nValueBytes = sizeof(Gamefloat);
	uint32 bufferSize = nValueBytes * m_pDataVertex->m_nTexCoordDim * m_pDataVertex->m_nTexCoordCount;
#if SM_FOR_UE_FIVE
	CreateRHIVertexBuffer(m_pPostion0Buffer, m_pDataVertex->m_TexCoord, bufferSize, EBufferUsageFlags::Static);
#else
	CreateRHIVertexBuffer(m_pPostion0Buffer, m_pDataVertex->m_TexCoord, bufferSize, EBufferUsageFlags::BUF_Static);
#endif

	m_Postion0StreamComponent.Offset = 0;
	m_Postion0StreamComponent.StreamOffset = 0;
	m_Postion0StreamComponent.Stride = nValueBytes * m_pDataVertex->m_nTexCoordDim;
	m_Postion0StreamComponent.Type = EVertexElementType::VET_Float3;
	m_Postion0StreamComponent.VertexBuffer = m_pPostion0Buffer;
}

void FSuperMapLineVertexBuffer::CreatePosition1BufferAndComponent()
{
	if (m_pDataVertex->m_TexCoord1 == nullptr)
	{
		return;
	}
	m_pPostion1Buffer = new FVertexBuffer();
	m_pPostion1Buffer->InitResource();
	uint32 nValueBytes = sizeof(Gamefloat);
	uint32 bufferSize = nValueBytes * m_pDataVertex->m_nTexCoordDim1 * m_pDataVertex->m_nTexCoordCount1;
#if SM_FOR_UE_FIVE
	CreateRHIVertexBuffer(m_pPostion1Buffer, m_pDataVertex->m_TexCoord1, bufferSize, EBufferUsageFlags::Static);
#else
	CreateRHIVertexBuffer(m_pPostion1Buffer, m_pDataVertex->m_TexCoord1, bufferSize, EBufferUsageFlags::BUF_Static);
#endif

	m_Postion1StreamComponent.Offset = 0;
	m_Postion1StreamComponent.StreamOffset = 0;
	m_Postion1StreamComponent.Stride = nValueBytes * m_pDataVertex->m_nTexCoordDim1;
	m_Postion1StreamComponent.Type = EVertexElementType::VET_Float3;
	m_Postion1StreamComponent.VertexBuffer = m_pPostion1Buffer;
}

void FSuperMapLineVertexBuffer::CreateFaceNormal0BufferAndComponent()
{
	if (m_pDataVertex->m_TexCoord2 == nullptr)
	{
		return;
	}
	m_pFaceNormal0Buffer = new FVertexBuffer();
	m_pFaceNormal0Buffer->InitResource();
	uint32 nValueBytes = sizeof(Gamefloat);
	uint32 bufferSize = nValueBytes * m_pDataVertex->m_nTexCoordDim2 * m_pDataVertex->m_nTexCoordCount2;
#if SM_FOR_UE_FIVE
	CreateRHIVertexBuffer(m_pFaceNormal0Buffer, m_pDataVertex->m_TexCoord2, bufferSize, EBufferUsageFlags::Static);
#else
	CreateRHIVertexBuffer(m_pFaceNormal0Buffer, m_pDataVertex->m_TexCoord2, bufferSize, EBufferUsageFlags::BUF_Static);
#endif

	m_FaceNormal0StreamComponent.Offset = 0;
	m_FaceNormal0StreamComponent.StreamOffset = 0;
	m_FaceNormal0StreamComponent.Stride = nValueBytes * m_pDataVertex->m_nTexCoordDim2;
	m_FaceNormal0StreamComponent.Type = EVertexElementType::VET_Float3;
	m_FaceNormal0StreamComponent.VertexBuffer = m_pFaceNormal0Buffer;
}
void FSuperMapLineVertexBuffer::CreateFaceNormal1BufferAndComponent()
{
	if (m_pDataVertex->m_TexCoord3 == nullptr)
	{
		return;
	}
	m_pFaceNormal1Buffer = new FVertexBuffer();
	m_pFaceNormal1Buffer->InitResource();
	uint32 nValueBytes = sizeof(Gamefloat);
	uint32 bufferSize = nValueBytes * m_pDataVertex->m_nTexCoordDim3 * m_pDataVertex->m_nTexCoordCount3;
#if SM_FOR_UE_FIVE
	CreateRHIVertexBuffer(m_pFaceNormal1Buffer, m_pDataVertex->m_TexCoord3, bufferSize, EBufferUsageFlags::Static);
#else
	CreateRHIVertexBuffer(m_pFaceNormal1Buffer, m_pDataVertex->m_TexCoord3, bufferSize, EBufferUsageFlags::BUF_Static);
#endif

	m_FaceNormal1StreamComponent.Offset = 0;
	m_FaceNormal1StreamComponent.StreamOffset = 0;
	m_FaceNormal1StreamComponent.Stride = nValueBytes * m_pDataVertex->m_nTexCoordDim3;
	m_FaceNormal1StreamComponent.Type = EVertexElementType::VET_Float3;
	m_FaceNormal1StreamComponent.VertexBuffer = m_pFaceNormal1Buffer;
}

void FSuperMapLineVertexBuffer::CreateRenderResources_RenderThread()
{
	if (m_pDataVertex == nullptr)
	{
		return;
	}

	if (m_pDataIndex != nullptr)
	{
		m_pIndexBuffer = new FIndexBuffer();
		m_pIndexBuffer->InitResource();
		uint32 indexStride = 0;
		void* pIndex = nullptr;
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

		uint32 bufferSize = indexStride * m_pDataIndex->m_nIndexCount;
		FSuperMapVertexResourceArray resourceArray(pIndex, bufferSize);
#if SM_FOR_UE_FIVE
		FRHIResourceCreateInfo CreateInfo = FRHIResourceCreateInfo(TEXT(""));
#else
		FRHIResourceCreateInfo CreateInfo;
#endif
		CreateInfo.ResourceArray = &resourceArray;
		m_pIndexBuffer->IndexBufferRHI = RHICreateIndexBuffer(indexStride, bufferSize, BUF_Static, CreateInfo);
	}

	CreateSidenessBufferAndComponent();
	CreateSecondColorBufferAndComponent();
	CreatePosition0BufferAndComponent();
	CreatePosition1BufferAndComponent();
	CreateFaceNormal0BufferAndComponent();
	CreateFaceNormal1BufferAndComponent();

	if (m_pDataVertex != nullptr)
	{
		delete m_pDataVertex;
		m_pDataVertex = nullptr;
	}
	if (m_pDataIndex != nullptr)
	{
		delete m_pDataIndex;
		m_pDataIndex = nullptr;
	}
}

void FSuperMapLineVertexBuffer::ReleaseResource()
{
	if (m_pIndexBuffer != nullptr)
	{
		m_pIndexBuffer->ReleaseRHI();
	}

	if (m_pSidenessBuffer != nullptr)
	{
		m_pSidenessBuffer->ReleaseRHI();
	}

	if (m_pSecondColorBuffer != nullptr)
	{
		m_pSecondColorBuffer->ReleaseRHI();
	}

	if (m_pPostion0Buffer != nullptr)
	{
		m_pPostion0Buffer->ReleaseRHI();
	}

	if (m_pPostion1Buffer != nullptr)
	{
		m_pPostion1Buffer->ReleaseRHI();
	}

	if (m_pFaceNormal0Buffer != nullptr)
	{
		m_pFaceNormal0Buffer->ReleaseRHI();
	}

	if (m_pFaceNormal1Buffer != nullptr)
	{
		m_pFaceNormal1Buffer->ReleaseRHI();
	}
}
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif