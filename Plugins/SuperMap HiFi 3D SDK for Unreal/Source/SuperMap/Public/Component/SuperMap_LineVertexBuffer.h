#pragma once

#include <memory>

#include "CoreMinimal.h"
#include "Base3D/CommonDefine.h"
#include "Core/RealspaceDLL.h"
#include "Component/SuperMap_CustomVertexBuffer.h"

using namespace SuperMapSDK;

//! 渲染线的方式
enum LineRenderType
{
	SIMPLE_LINE = 0,		// 简单线型，使用FPrimitiveDrawInterface接口渲染
	COMPLEX_LINE = 1		// 复杂线型，使用顶点工厂渲染
};

struct SM_LineSegment
{
public:
	FVector start;
	FVector end;
	FColor color;

	SM_LineSegment()
		: start(0.f, 0.f, 0.f)
		, end(0.f, 0.f, 1.f)
	{}
};

class FSuperMapLineVertexBuffer : public FSuperMapBaseVertexBuffer
{
public:
	FSuperMapLineVertexBuffer();
	virtual ~FSuperMapLineVertexBuffer();

	///////////////////////////////////////////////////////////////////////
	// 继承于FSuperMapBaseVertexBuffer的接口
	Gamevoid SetMesh(FSMMesh& smMesh) override;

	// 创建渲染侧资源
	Gamevoid CreateRenderResources_RenderThread() override;

	Gamevoid ReleaseResource() override;
	///////////////////////////////////////////////////////////////////////
	Gamevoid SetupMeshBatch(FMeshBatch& meshBatch) const;
private:
	Gamevoid CreateRHIVertexBuffer(FVertexBuffer* pVertexBuffer, Gamevoid* src, SIZE_T size, EBufferUsageFlags bufferUsage);

	Gamevoid CreateSidenessBufferAndComponent();
	Gamevoid CreateSecondColorBufferAndComponent();
	Gamevoid CreatePosition0BufferAndComponent();
	Gamevoid CreatePosition1BufferAndComponent();
	Gamevoid CreateFaceNormal0BufferAndComponent();
	Gamevoid CreateFaceNormal1BufferAndComponent();
private:
	FVertexStreamComponent m_SidenessStreamComponent;
	FVertexStreamComponent m_SecondColorStreamComponent;
	FVertexStreamComponent m_Postion0StreamComponent;
	FVertexStreamComponent m_Postion1StreamComponent;
	FVertexStreamComponent m_FaceNormal0StreamComponent;
	FVertexStreamComponent m_FaceNormal1StreamComponent;

	FVertexBuffer* m_pSidenessBuffer;
	FVertexBuffer* m_pSecondColorBuffer;
	FVertexBuffer* m_pPostion0Buffer;
	FVertexBuffer* m_pPostion1Buffer;
	FVertexBuffer* m_pFaceNormal0Buffer;
	FVertexBuffer* m_pFaceNormal1Buffer;

	FIndexBuffer* m_pIndexBuffer;

	DataVertex* m_pDataVertex;
	DataIndice* m_pDataIndex;

	Gameuint m_nIndicesNum;
	Gameuint m_nPrimitivesNum;

	Gamefloat m_fLineWidth;

	friend class FSuperMapEdgeLineVertexFactory;
	friend class FSuperMapEdgeLineVertexFactoryShaderParameters;
};