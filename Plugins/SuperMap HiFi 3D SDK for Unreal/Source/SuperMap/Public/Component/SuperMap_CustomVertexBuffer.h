#pragma once

#include <memory>

#include "CoreMinimal.h"
#include "Base3D/CommonDefine.h"
#include "Core/RealspaceDLL.h"

using namespace SuperMapSDK;

//! 渲染的数据类型
enum SuperMapModelType
{
	Model = 0,		 // 精模
	BlockModel = 1,  // block模型
	PointCloud = 2,  //点云
	Globe = 3,  //地形
	Other = 4
};

//////////////////////////////////////////////////////////////////
class FSuperMapVertexResourceArray :
	public FResourceArrayInterface
{
public:
	FSuperMapVertexResourceArray(const Gamevoid* InData, Gameuint InSize)
		: m_pData(InData)
		, m_nSize(InSize)
	{
	}

	virtual const Gamevoid* GetResourceData() const override { return m_pData; }
	virtual Gameuint GetResourceDataSize() const override { return m_nSize; }
	virtual Gamevoid Discard() override { }
	virtual Gamebool IsStatic() const override { return false; }
	virtual Gamebool GetAllowCPUAccess() const override { return false; }
	virtual Gamevoid SetAllowCPUAccess(Gamebool bInNeedsCPUAccess) override { }

private:
	const Gamevoid* m_pData;
	Gameuint m_nSize;
};
//////////////////////////////////////////////////////////////////

class FSuperMapBaseVertexBuffer
{
public:
	FSuperMapBaseVertexBuffer();
	virtual ~FSuperMapBaseVertexBuffer();

	virtual Gamevoid SetMesh(FSMMesh& smMesh) {};

	// 创建渲染侧资源
	virtual Gamevoid CreateRenderResources_RenderThread() {};

	// 更新顶点颜色
	virtual Gamevoid UpdateVertexColor_RenderThread(const FSMMesh& smMesh) {};

	// 更新顶点
	virtual Gamevoid UpdateVertex_RenderThread(const FSMMesh& smMesh) {};

	// 更新顶点属性
	virtual Gamevoid UpdateCustomVertexAttribute0_RenderThread(const FSMMesh& smMesh) {};

	virtual Gamevoid ReleaseResource() {};
protected:
	//! \brief 顶点数量
	Gameuint m_nVerticesNum;
};

class FSuperMapCustomVertexBuffer : public FSuperMapBaseVertexBuffer
{
public:
	FSuperMapCustomVertexBuffer();
	virtual ~FSuperMapCustomVertexBuffer();

	///////////////////////////////////////////////////////////////////////
	// 继承于FSuperMapBaseVertexBuffer的接口
	Gamevoid SetMesh(FSMMesh& smMesh) override;

	// 创建渲染侧资源
	Gamevoid CreateRenderResources_RenderThread() override;

	// 更新顶点颜色
	Gamevoid UpdateVertexColor_RenderThread(const FSMMesh& smMesh) override;

	// 更新顶点
	Gamevoid UpdateVertex_RenderThread(const FSMMesh& smMesh) override;

	// 更新顶点属性
	Gamevoid UpdateCustomVertexAttribute0_RenderThread(const FSMMesh& smMesh) override;

	// 更新实例化的顶点颜色
	Gamevoid UpdateInstanceVertexColor_RenderThread(Gameuint nColor, const TArray<Gameuint>& arrIds);

	Gamevoid ReleaseResource() override;
	///////////////////////////////////////////////////////////////////////

	Gameint GetCompressType() const;

	InstanceTpye GetInstanceType() const;
private:

	Gamevoid CreateRHIVertexBuffer(FVertexBuffer* pVertexBuffer, Gamevoid* src, SIZE_T size, EBufferUsageFlags bufferUsage);

	EVertexElementType SelectFloatVetType(Gameint dim, Gamebool compress);

	Gamevoid CreatePositionBufferAndComponent();
	Gamevoid CreateNormalBufferAndComponent();
	Gamevoid CreateTangentBufferAndComponent();
	Gamevoid CreateVertexColorBufferAndComponent();
	Gamevoid CreateSecondColorBufferAndComponent();
	Gamevoid CreateTexCoord0BufferAndComponent();
	Gamevoid CreateTexCoord1BufferAndComponent();
	Gamevoid CreateTexMatrixBufferAndComponent();
	Gamevoid CreateVertexWeightAndComponent();//W位
	Gamevoid CreateTilingTexCoordAndComponent();

	Gamevoid CreateInstanceSRV();
	Gamevoid CreateInstanceColorSRV();
private:
	FVertexStreamComponent m_PostionStreamComponent;
	FVertexStreamComponent m_pNormalStreamComponent;
	FVertexStreamComponent m_pTangentStreamComponent;
	FVertexStreamComponent m_pVertexColorStreamComponent;
	FVertexStreamComponent m_pSecondColorStreamComponent;
	FVertexStreamComponent m_pTexCoord0StreamComponent;
	FVertexStreamComponent m_pTexCoord1StreamComponent;
	//! \brief meshopt 用来存储纹理矩阵的信息
	FVertexStreamComponent m_pTexMatrixStreamComponent;
	FVertexStreamComponent m_pVertexWeightStreamComponent;
	FVertexStreamComponent m_pTilingTexCoordStreamComponent;

	//! \brief 0重纹理坐标的维度
	Gameint m_nTexCoord0Dim;
	//! \brief 1重纹理坐标的维度
	Gameint m_nTexCoord1Dim;
	//! \brief 顶点属性类是否包含了纹理矩阵
	Gameint m_nHasTexMatrixBuffer;
	//! \brief 顶点属性类是否包含了W位
	Gameint m_nHasVertexWeight;
	//! \brief 按位存储的顶点压缩类型
	Gameint m_nCompressType;

	FVector4 m_decodePositionMin;
	Gamefloat m_decodePositionNormConstant;

	FVector2D m_decodeTexCoord0Min;
	FVector2D m_decodeTexCoord1Min;

	FVector2D m_texCoord0CompressConstant;
	FVector2D m_texCoord1CompressConstant;

	DataVertex* m_pDataVertex;

	Gamefloat* m_pInstanceBuffer;
	Gameint m_nInstanceSize;
	Gameint m_nSizeInFloatPerInstance;

#if RHI_RAYTRACING
	// 注释: 
	// 光线追踪的几何体三角网只支持VET_FLOAT3的顶点格式，
	// 所以这个地方需要独立的一份顶点数据
	FVertexBuffer* m_pRayPostionBuffer;
#endif 

	FVertexBuffer* m_pPostionBuffer;
	FVertexBuffer* m_pNormalBuffer;
	FVertexBuffer* m_pTangentBuffer;
	FVertexBuffer* m_pVertexColorBuffer;
	FVertexBuffer* m_pSecondColorBuffer;
	FVertexBuffer* m_pTexCoord0Buffer;
	FVertexBuffer* m_pTexCoord1Buffer;
	FVertexBuffer* m_pTexMatrixBuffer;
	FVertexBuffer* m_pVertexWeightBuffer;
	FVertexBuffer* m_pTilingTexCoordBuffer;

	FShaderResourceViewRHIRef m_InstanceSRV;
	FShaderResourceViewRHIRef m_InstanceColorSRV;

	FVertexBuffer m_instanceVertexBuffer;
	FVertexBuffer m_instanceColorVertexBuffer;

	// 保留顶点颜色，选中高亮时用到
	Gameuint* m_pVertexColorData;
	Gameuint* m_pInstanceVertexColorData;
	// 是否使用的是UGC创建的内存
	Gamebool m_bUseUGCMemory;

	friend class FSuperMapCustomVertexFactory;
	friend class FSuperMapVertexFactoryShaderParameters;
	friend class FSuperMapMeshSceneProxy;

	friend class FSuperMapPolyLineMeshSceneProxy;
};

class FSuperMapRenderSection
{
public:
	FSuperMapRenderSection();
	~FSuperMapRenderSection();

	// 继承于FSuperMapBaseVertexBuffer的接口
	Gamevoid SetMesh(DataIndice*& pDataIndice);

	Gamevoid CreateRenderResources_RenderThread();

	Gamevoid ReleaseResource();
private:
	EPrimitiveType GetDrawType(Gameint ugOperationType);

private:
	EPrimitiveType m_eDrawType;
	//! \brief 图元数量
	Gameuint m_nPrimitivesNum;

	DataIndice* m_pDataIndex;

	FIndexBuffer* m_pIndexBuffer;

	//! \brief 对应的材质
	FSuperMapMaterialInterfaceCollection m_MaterialCollection;

	friend class FSuperMapMeshSceneProxy;
	friend class FSuperMapPolyLineMeshSceneProxy;
};