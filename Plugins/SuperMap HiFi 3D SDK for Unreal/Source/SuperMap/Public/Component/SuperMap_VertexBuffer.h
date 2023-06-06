#pragma once

#include <memory>

#include "CoreMinimal.h"
#include "DynamicMeshBuilder.h"
#include "Rendering/ColorVertexBuffer.h"
#include "Rendering/PositionVertexBuffer.h"
#include "Rendering/StaticMeshVertexBuffer.h"
#if! SM_FOR_UE_FIVE
#include "Component/SuperMapColorVertexBuffer.h"
#include "Component/SuperMapPositionVertexBuffer.h"
#include "Component/SuperMapStaticMeshVertexBuffer.h"
#endif
#include "Component/MeshData.h"
#include "Base3D/CommonDefine.h"
#include "Core/RealspaceDLL.h"

using namespace SuperMapSDK;

class FSuperMapVertexBuffer
{
public:
	FSuperMapVertexBuffer();
	~FSuperMapVertexBuffer();

	Gamevoid Create_GameOrWorkerThread(const FSMMesh & smMesh);
	Gamevoid SetupMeshBatch(FMeshBatch& meshBatch) const;
	Gamevoid Update_RenderThread(const FSMMesh & smMesh);
	Gamevoid UpdateVertexColor_RenderThread(const FSMMesh& smMesh);

	// 创建渲染侧资源
	Gamevoid CreateRenderResources_RenderThread();

	Gamevoid BindBuffer_RenderThread(const FVertexFactory* pVertexFactory, FStaticMeshDataType& StaticMeshData);

	Gamevoid SetMaterialName(FString material);

	Gameuint GetVertexBufferCount();
	FVertexBufferRHIRef GetVertexBufferRHI();
	FIndexBufferRHIRef GetIndexBufferRHI();
	FIndexBuffer* GetIndexBuffer();
	Gameuint GetPrimitiveCount();
	EPrimitiveType GetPrimitiveType();
	Gameuint GetIndexBufferCount();

	static EPrimitiveType GetDrawType(const FSMMesh& smMesh);
private:
	Gamevoid CopyGPUBufferLocked(FRHIVertexBuffer* rhiVertexBuffer, Gamevoid* src, SIZE_T size);
	Gamevoid FetchBuffersFromMeshData(const FSMMesh & smMesh);
	Gamevoid FetchColorBuffersFromMeshData(const FSMMesh & smMesh);

	FDynamicMeshIndexBuffer32 m_IndexBuffer;
	FDynamicMeshIndexBuffer16 m_ShortIndexBuffer;
#if SM_FOR_UE_FIVE
	FColorVertexBuffer m_ColorVertexBuffer;
	FPositionVertexBuffer m_PositionVertexBuffer;
	FStaticMeshVertexBuffer m_StaticMeshVertexBuffer;
#else
	FSuperMapColorVertexBuffer m_ColorVertexBuffer;
	FSuperMapPositionVertexBuffer m_PositionVertexBuffer;
	FSuperMapStaticMeshVertexBuffer m_StaticMeshVertexBuffer;
#endif
	//! \brief 绘制方式
	EPrimitiveType m_eDrawType;
	
	Gamebool m_bIsGlobal;

	FString m_strMaterialName;

	TArray<Gameuint> m_arrIndices;
};
