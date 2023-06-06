#pragma once

#include <memory>

#include "CoreMinimal.h"
#include "Base3D/CommonDefine.h"
#include "Core/RealspaceDLL.h"

using namespace SuperMapSDK;

//! ��Ⱦ����������
enum SuperMapModelType
{
	Model = 0,		 // ��ģ
	BlockModel = 1,  // blockģ��
	PointCloud = 2,  //����
	Globe = 3,  //����
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

	// ������Ⱦ����Դ
	virtual Gamevoid CreateRenderResources_RenderThread() {};

	// ���¶�����ɫ
	virtual Gamevoid UpdateVertexColor_RenderThread(const FSMMesh& smMesh) {};

	// ���¶���
	virtual Gamevoid UpdateVertex_RenderThread(const FSMMesh& smMesh) {};

	// ���¶�������
	virtual Gamevoid UpdateCustomVertexAttribute0_RenderThread(const FSMMesh& smMesh) {};

	virtual Gamevoid ReleaseResource() {};
protected:
	//! \brief ��������
	Gameuint m_nVerticesNum;
};

class FSuperMapCustomVertexBuffer : public FSuperMapBaseVertexBuffer
{
public:
	FSuperMapCustomVertexBuffer();
	virtual ~FSuperMapCustomVertexBuffer();

	///////////////////////////////////////////////////////////////////////
	// �̳���FSuperMapBaseVertexBuffer�Ľӿ�
	Gamevoid SetMesh(FSMMesh& smMesh) override;

	// ������Ⱦ����Դ
	Gamevoid CreateRenderResources_RenderThread() override;

	// ���¶�����ɫ
	Gamevoid UpdateVertexColor_RenderThread(const FSMMesh& smMesh) override;

	// ���¶���
	Gamevoid UpdateVertex_RenderThread(const FSMMesh& smMesh) override;

	// ���¶�������
	Gamevoid UpdateCustomVertexAttribute0_RenderThread(const FSMMesh& smMesh) override;

	// ����ʵ�����Ķ�����ɫ
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
	Gamevoid CreateVertexWeightAndComponent();//Wλ
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
	//! \brief meshopt �����洢����������Ϣ
	FVertexStreamComponent m_pTexMatrixStreamComponent;
	FVertexStreamComponent m_pVertexWeightStreamComponent;
	FVertexStreamComponent m_pTilingTexCoordStreamComponent;

	//! \brief 0�����������ά��
	Gameint m_nTexCoord0Dim;
	//! \brief 1�����������ά��
	Gameint m_nTexCoord1Dim;
	//! \brief �����������Ƿ�������������
	Gameint m_nHasTexMatrixBuffer;
	//! \brief �����������Ƿ������Wλ
	Gameint m_nHasVertexWeight;
	//! \brief ��λ�洢�Ķ���ѹ������
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
	// ע��: 
	// ����׷�ٵļ�����������ֻ֧��VET_FLOAT3�Ķ����ʽ��
	// ��������ط���Ҫ������һ�ݶ�������
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

	// ����������ɫ��ѡ�и���ʱ�õ�
	Gameuint* m_pVertexColorData;
	Gameuint* m_pInstanceVertexColorData;
	// �Ƿ�ʹ�õ���UGC�������ڴ�
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

	// �̳���FSuperMapBaseVertexBuffer�Ľӿ�
	Gamevoid SetMesh(DataIndice*& pDataIndice);

	Gamevoid CreateRenderResources_RenderThread();

	Gamevoid ReleaseResource();
private:
	EPrimitiveType GetDrawType(Gameint ugOperationType);

private:
	EPrimitiveType m_eDrawType;
	//! \brief ͼԪ����
	Gameuint m_nPrimitivesNum;

	DataIndice* m_pDataIndex;

	FIndexBuffer* m_pIndexBuffer;

	//! \brief ��Ӧ�Ĳ���
	FSuperMapMaterialInterfaceCollection m_MaterialCollection;

	friend class FSuperMapMeshSceneProxy;
	friend class FSuperMapPolyLineMeshSceneProxy;
};