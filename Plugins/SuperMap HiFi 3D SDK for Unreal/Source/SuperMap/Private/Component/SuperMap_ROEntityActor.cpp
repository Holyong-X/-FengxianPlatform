// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/SuperMap_ROEntityActor.h"
#include "Materials/MaterialInstanceDynamic.h"

#include "Component/SuperMap_ProceduralMeshComponent.h"
#include "Component/SuperMap_LineMeshComponent.h"
#include "Component/SuperMap_MeshComponent.h"
#include "Core/ROCacheManager.h"
#include "Graphics3D/GameObjectManager.h"

//#include "SMMesh.h"
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif
// Sets default values
ASuperMap_ROEntityActor::ASuperMap_ROEntityActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	// 创建一个程序化组件
	m_pProceduralMeshCom = CreateDefaultSubobject<USuperMap_ProceduralMeshComponent>(TEXT("ProceduralMesh"));
	m_pProceduralMeshCom->SetupAttachment(RootComponent);

	m_pLineMeshCom = CreateDefaultSubobject<USuperMap_LineMeshComponent>(TEXT("LineMesh"));
	m_pLineMeshCom->SetupAttachment(RootComponent);

	m_pProceduralMeshCom->bRenderCustomDepth = true;
	m_vecWorldOffset = FIntVector(0,0,0);
	m_pMaterial = nullptr;
	m_nDrawType = 0;
	m_bIsMeshNode = false;
	m_bVisibleLayer = true;
	m_nHiddenIndex = -1;
}

ASuperMap_ROEntityActor::~ASuperMap_ROEntityActor()
{
	if (m_pMaterial != nullptr)
	{
		m_pMaterial->RemoveFromRoot();
		m_pMaterial = nullptr;
	}
}

Gamebool IsGlobeMesh(TArray<SM_SubMesh>& arrSubMeshs) {
	for (Gameint i = 0; i < arrSubMeshs.Num(); i++)
	{
		SM_SubMesh& subMesh = arrSubMeshs[i];
		if (subMesh.m_pMaterialInterface == nullptr)
		{
			continue;
		}
		FString strName = subMesh.m_pMaterialInterface->GetBaseMaterial()->GetName();
		if (strName == "Global") {
			return true;
		}
	}
	return false;
}

Gamevoid ASuperMap_ROEntityActor::CreateProceduralMesh(TArray<SM_Vertex>& arrVtxs, TArray<SM_SubMesh>& arrSubMeshs)
{
	FProcMeshSection NewSection;

	const Gameint NumVerts = arrVtxs.Num();
	NewSection.ProcVertexBuffer.Reset();
	NewSection.ProcVertexBuffer.AddUninitialized(NumVerts);
	for (Gameint VertIdx = 0; VertIdx < NumVerts; VertIdx++)
	{
		FProcMeshVertex& Vertex = NewSection.ProcVertexBuffer[VertIdx];

		Vertex.Position = arrVtxs[VertIdx].Position;
		Vertex.Normal = FVector(0.f, 0.f, 1.f);
		Vertex.UV0 = arrVtxs[VertIdx].UV0;
		Vertex.UV1 = FVector2D(0.f, 0.f);
		Vertex.UV2 = FVector2D(0.f, 0.f);
		Vertex.UV3 = FVector2D(0.f, 0.f);
		Vertex.Color = arrVtxs[VertIdx].Color;
		Vertex.Tangent = FProcMeshTangent();

		// Update bounding box
		NewSection.SectionLocalBox += Vertex.Position;
	}
	SM_SubMesh& subMesh = arrSubMeshs[0];
	// Copy index buffer (clamping to vertex range)
	Gameint NumTriIndices = subMesh.IndexBuffer.Num();

	NewSection.ProcIndexBuffer.Reset();
	NewSection.ProcIndexBuffer.AddUninitialized(NumTriIndices);
	for (Gameint IndexIdx = 0; IndexIdx < NumTriIndices; IndexIdx++)
	{
		NewSection.ProcIndexBuffer[IndexIdx] = FMath::Min(subMesh.IndexBuffer[IndexIdx], NumVerts - 1);
	}

	NewSection.bEnableCollision = false;

	if (subMesh.m_pMaterialInterface != nullptr)
	{
		m_pProceduralMeshCom->SetMaterial(0, subMesh.m_pMaterialInterface);
		m_pMaterial = subMesh.m_pMaterialInterface;
	}
	m_pProceduralMeshCom->SetProcMeshSection(0 , NewSection);
	m_pProceduralMeshCom->SetDrawType(m_nDrawType);
}

Gamevoid ASuperMap_ROEntityActor::CreateProceduralMesh(TArray<SM_Vertex>& arrVtxs, TArray<SM_SubMesh>& arrSubMeshs, const Matrix4d& objectMatrix)
{
	Gamebool bGlobeMesh = IsGlobeMesh(arrSubMeshs);
	// 顶点
	TArray<FVector> arrVertices;
	// 纹理坐标
	TArray<FVector2D> arrTextureCoords1;
	TArray<FVector2D> arrTextureCoords2;

	// secondColor
	TArray<FVector2D> arrTextureCoords3;
	TArray<FVector2D> arrTextureCoords4;

	// 法线坐标
	TArray<FVector> arrNormals;

	// 顶点颜色
	TArray<FColor> arrColor;
	for (Gameint i = 0; i < arrVtxs.Num(); i++)
	{
		SM_Vertex & vtx = arrVtxs[i];
		arrVertices.Add(vtx.Position);
		arrTextureCoords1.Add(vtx.UV0);
		arrTextureCoords2.Add(vtx.UV1);
		arrColor.Add(vtx.Color);

		if (bGlobeMesh)
		{
			FVector2D wValue;
			wValue.X = vtx.PositionW;
			wValue.Y = vtx.PositionW;
			arrTextureCoords3.Add(wValue);
		}
		else
		{
			FVector2D sR;
			sR.X = vtx.SecondColor.X;
			sR.Y = vtx.SecondColor.Y;

			arrTextureCoords3.Add(sR);

			sR.X = vtx.SecondColor.Z;
			sR.Y = vtx.SecondColor.W;

			arrTextureCoords4.Add(sR);
		}


		arrNormals.Add(vtx.Normal);
	}



	TArray<Gameint> arrIdxs;
	for (Gameint i = 0; i < arrSubMeshs.Num(); i++)
	{
		SM_SubMesh & subMesh = arrSubMeshs[i];

		TArray<FVector>    EmptyVectorArray;
		TArray<FColor>     EmptyColorArray;
		TArray<FVector2D>  EmptyTexCoordArray;
		TArray<FProcMeshTangent> EmptyTangentArray;

		if (subMesh.m_pMaterialInterface != nullptr)
		{
			m_pProceduralMeshCom->SetMaterial(0, subMesh.m_pMaterialInterface);
			m_pMaterial = subMesh.m_pMaterialInterface;	
		}
		m_pProceduralMeshCom->CreateMeshSection(i, arrVertices, subMesh.IndexBuffer, arrNormals, arrTextureCoords1, arrTextureCoords2, arrTextureCoords3, arrTextureCoords4, arrColor, EmptyTangentArray, m_bCollision);
		m_pProceduralMeshCom->SetDrawType(m_nDrawType);
	}

	m_matDoubleLocalToWorld = objectMatrix;
}

Gamevoid ASuperMap_ROEntityActor::CreateProceduralMesh(
	SuperMapSDK::DataVertex* pDataVertex,
	SuperMapSDK::DataIndice* pDataIndice,
	UMaterialInterface* pMat)
{
	Gamedouble* pDMat = pDataVertex->m_doubleObjectMat;
	Matrix4d doubleObjectMatrix(pDMat);
	Gamebool bGlobeMesh = false;

	if (pMat != nullptr)
	{
		FString strName = pMat->GetBaseMaterial()->GetName();
		if (strName == "Global") {
			bGlobeMesh = true;
		}
	}
	
	// 顶点
	TArray<FVector> arrVertices;
	// 纹理坐标
	TArray<FVector2D> arrTextureCoords1;
	TArray<FVector2D> arrTextureCoords2;

	// secondColor
	TArray<FVector2D> arrTextureCoords3;
	TArray<FVector2D> arrTextureCoords4;

	// 法线坐标
	TArray<FVector> arrNormals;

	// 顶点颜色
	TArray<FColor> arrColor;

	// 顶点
	Gameint nVtxDim = pDataVertex->m_nPosDim;
	for (Gameint i = 0; i < pDataVertex->m_nPosCount; i++)
	{
		//==================================================
		FVector pos;
		pos.Y = pDataVertex->m_Pos[nVtxDim * i + 0];
		pos.X = pDataVertex->m_Pos[nVtxDim * i + 1];
		pos.Z = pDataVertex->m_Pos[nVtxDim * i + 2];
		arrVertices.Add(pos);
		if (nVtxDim == 4 && bGlobeMesh) {
			FVector2D wValue;
			wValue.X = pDataVertex->m_Pos[nVtxDim * i + 3];
			wValue.Y = pDataVertex->m_Pos[nVtxDim * i + 3];
			arrTextureCoords3.Add(wValue);
		}

		//===================================================
		if (pDataVertex->m_nTexCoordCount == pDataVertex->m_nPosCount && pDataVertex->m_TexCoord != nullptr)
		{
			FVector2D UV0;
			FVector2D UV1;
			Gameint nTexDim = pDataVertex->m_nTexCoordDim;
			if (nTexDim == 2)
			{
				UV0.X = pDataVertex->m_TexCoord[nTexDim * i + 0];
				UV0.Y = pDataVertex->m_TexCoord[nTexDim * i + 1];
				arrTextureCoords1.Add(UV0);
			}
			else if (nTexDim == 3)
			{
				UV1.X = pDataVertex->m_TexCoord[nTexDim * i + 0];
				UV1.Y = pDataVertex->m_TexCoord[nTexDim * i + 1];
				UV0.X = pDataVertex->m_TexCoord[nTexDim * i + 2];

				arrTextureCoords1.Add(UV0);
				arrTextureCoords2.Add(UV1);
			}
		}

		//======================================================
		if (pDataVertex->m_nNormalCount == pDataVertex->m_nPosCount && pDataVertex->m_Normal != nullptr)
		{
			uint32 nNormalCount = pDataVertex->m_nNormalCount;
			uint32 nNormalDim = pDataVertex->m_nNormalDim;

			FVector Normal;
			// 这里XY需要反一下，因为UE的轴和组件的不一样
			Normal.Y = pDataVertex->m_Normal[i * nNormalDim + 0];
			Normal.X = pDataVertex->m_Normal[i * nNormalDim + 1];
			Normal.Z = pDataVertex->m_Normal[i * nNormalDim + 2];
			arrNormals.Add(Normal);
		}

		//=======================================================
		if (pDataVertex->m_nColorCount == pDataVertex->m_nPosCount && pDataVertex->m_PosColor != nullptr)
		{
			uint32 nColor = pDataVertex->m_PosColor[i];
			
			Gamefloat fR, fG, fB, fA;
			SuperMapSDK::UnrealEngine::Core::_IDRGBA(nColor , fR, fG, fB, fA);

			uint8 r = fR * 255;
			uint8 g = fG * 255;
			uint8 b = fB * 255;
			uint8 a = fA * 255;

			FColor color(r, g, b, a);
			arrColor.Add(color);
		}
		//========================================================
		if (pDataVertex->m_nSecondColorCount == pDataVertex->m_nPosCount && pDataVertex->m_PosSceondColor != nullptr)
		{
			uint32 nColor = pDataVertex->m_PosSceondColor[i];

			Gamefloat fR, fG, fB, fA;
			SuperMapSDK::UnrealEngine::Core::_IDRGBA(nColor, fR, fG, fB, fA);

			FVector4 fColor(fR, fG, fB, fA);
			arrTextureCoords3.Add(FVector2D(fColor.X, fColor.Y));
			arrTextureCoords4.Add(FVector2D(fColor.Z, fColor.W));
		}

	}

	if (pDataIndice != nullptr)
	{
		TArray<FVector>    EmptyVectorArray;
		TArray<FColor>     EmptyColorArray;
		TArray<FVector2D>  EmptyTexCoordArray;
		TArray<FProcMeshTangent> EmptyTangentArray;

		TArray<Gameint> arrIndices;
		for (Gameint j = 0; j < 1; j++)
		{
			for (Gameint i = 0; i < pDataIndice->m_nIndexCount; i++)
			{
				if (pDataIndice->m_Index != nullptr)
				{
					arrIndices.Add(pDataIndice->m_Index[i]);
				}
				else
				{
					arrIndices.Add(pDataIndice->m_shortIndex[i]);
				}	
			}

			m_nDrawType = pDataIndice->m_nOperationType;

			if (pMat != nullptr)
			{
				m_pProceduralMeshCom->SetMaterial(0, pMat);
				m_pMaterial = pMat;
			}
			m_pProceduralMeshCom->CreateMeshSection(0, arrVertices, arrIndices, arrNormals, arrTextureCoords1, arrTextureCoords2, arrTextureCoords3, arrTextureCoords4, arrColor, EmptyTangentArray, m_bCollision);
			m_pProceduralMeshCom->SetDrawType(m_nDrawType);
		}
	}
	
	m_matDoubleLocalToWorld = doubleObjectMatrix;
}


Gamevoid ASuperMap_ROEntityActor::CreateProceduralMesh(
	SuperMapSDK::DataVertex* pDataVertex,
	TArray<SM_SubMesh>& arrSubMeshs)
{
	Gamedouble* pDMat = pDataVertex->m_doubleObjectMat;
	Matrix4d doubleObjectMatrix(pDMat);
	Gamebool bGlobeMesh = IsGlobeMesh(arrSubMeshs);
	// 顶点
	TArray<FVector> arrVertices;
	// 纹理坐标
	TArray<FVector2D> arrTextureCoords1;
	TArray<FVector2D> arrTextureCoords2;

	// secondColor
	TArray<FVector2D> arrTextureCoords3;
	TArray<FVector2D> arrTextureCoords4;

	// 法线坐标
	TArray<FVector> arrNormals;

	// 顶点颜色
	TArray<FColor> arrColor;

	// 顶点
	Gameint nVtxDim = pDataVertex->m_nPosDim;
	for (Gameint i = 0; i < pDataVertex->m_nPosCount; i++)
	{
		FVector pos;
		pos.Y = pDataVertex->m_Pos[nVtxDim * i + 0];
		pos.X = pDataVertex->m_Pos[nVtxDim * i + 1];
		pos.Z = pDataVertex->m_Pos[nVtxDim * i + 2];
		arrVertices.Add(pos);
		if (nVtxDim == 4 && bGlobeMesh) {
			FVector2D wValue;
			wValue.X = pDataVertex->m_Pos[nVtxDim * i + 3];
			wValue.Y = pDataVertex->m_Pos[nVtxDim * i + 3];
			arrTextureCoords3.Add(wValue);
		}
	}

	// 纹理坐标
	if (pDataVertex->m_nTexCoordCount > 0)
	{	
		FVector2D UV0;
		FVector2D UV1;
		if (pDataVertex->m_nTexCoordDim == 2)
		{
			Gameint nTexDim = pDataVertex->m_nTexCoordDim;

			for (Gameint i = 0; i < pDataVertex->m_nTexCoordCount; i++)
			{
				UV0.X = pDataVertex->m_TexCoord[nTexDim * i + 0];
				UV0.Y = pDataVertex->m_TexCoord[nTexDim * i + 1];

				arrTextureCoords1.Add(UV0);
			}
		}
		else if (pDataVertex->m_nTexCoordDim == 3)
		{
			Gameint nTexDim = pDataVertex->m_nTexCoordDim;

			for (Gameint i = 0; i < pDataVertex->m_nTexCoordCount; i++)
			{
				UV1.X = pDataVertex->m_TexCoord[nTexDim * i + 0];
				UV1.Y = pDataVertex->m_TexCoord[nTexDim * i + 1];
				UV0.X = pDataVertex->m_TexCoord[nTexDim * i + 2];

				arrTextureCoords1.Add(UV0);
				arrTextureCoords2.Add(UV1);
			}
		}
	}

	// 法线
	if (pDataVertex->m_nNormalCount > 0 && pDataVertex->m_Normal != NULL)
	{
		uint32 nNormalCount = pDataVertex->m_nNormalCount;
		uint32 nNormalDim = pDataVertex->m_nNormalDim;

		for (uint32 i = 0; i < nNormalCount; i++)
		{
			FVector Normal;
			// 这里XY需要反一下，因为UE的轴和组件的不一样
			Normal.Y = pDataVertex->m_Normal[i * nNormalDim + 0];
			Normal.X = pDataVertex->m_Normal[i * nNormalDim + 1];
			Normal.Z = pDataVertex->m_Normal[i * nNormalDim + 2];
			arrNormals.Add(Normal);
		}
	}

	// 顶点颜色
	if (pDataVertex->m_nColorCount > 0 && pDataVertex->m_PosColor != NULL)
	{
		for (Gameint i = 0; i < pDataVertex->m_nColorCount; i++)
		{
			uint8 r = pDataVertex->m_PosColor[i * 4 + 0] * 255;
			uint8 g = pDataVertex->m_PosColor[i * 4 + 1] * 255;
			uint8 b = pDataVertex->m_PosColor[i * 4 + 2] * 255;
			uint8 a = pDataVertex->m_PosColor[i * 4 + 3] * 255;

			FColor color(r, g, b, a);
			arrColor.Add(color);
		}
	}

	// secondColor
	if (pDataVertex->m_nSecondColorCount > 0 && pDataVertex->m_PosSceondColor != NULL)
	{
		for (Gameint i = 0; i < pDataVertex->m_nSecondColorCount; i++)
		{
			Gamefloat fr = pDataVertex->m_PosSceondColor[i * 4 + 0];
			Gamefloat fg = pDataVertex->m_PosSceondColor[i * 4 + 1];
			Gamefloat fb = pDataVertex->m_PosSceondColor[i * 4 + 2];
			Gamefloat fa = pDataVertex->m_PosSceondColor[i * 4 + 3];
			FVector4 fColor(fr, fg, fb, fa);
			arrTextureCoords3.Add(FVector2D(fColor.X, fColor.Y));
			arrTextureCoords4.Add(FVector2D(fColor.Z, fColor.W));
		}
	}

	TArray<Gameint> arrIdxs;
	for (Gameint i = 0; i < arrSubMeshs.Num(); i++)
	{
		SM_SubMesh& subMesh = arrSubMeshs[i];

		TArray<FVector>    EmptyVectorArray;
		TArray<FColor>     EmptyColorArray;
		TArray<FVector2D>  EmptyTexCoordArray;
		TArray<FProcMeshTangent> EmptyTangentArray;

		if (subMesh.m_pMaterialInterface != nullptr)
		{
			m_pProceduralMeshCom->SetMaterial(0, subMesh.m_pMaterialInterface);
			m_pMaterial = subMesh.m_pMaterialInterface;
		}
		m_pProceduralMeshCom->CreateMeshSection(i, arrVertices, subMesh.IndexBuffer, arrNormals, arrTextureCoords1, arrTextureCoords2, arrTextureCoords3, arrTextureCoords4, arrColor, EmptyTangentArray, m_bCollision);
		m_pProceduralMeshCom->SetDrawType(m_nDrawType);
	}

	m_matDoubleLocalToWorld = doubleObjectMatrix;
}

Gamevoid ASuperMap_ROEntityActor::CreateLineMeshComponent(TArray<SM_Vertex>& arrVtxs, TArray<SM_SubMesh>& arrSubMeshs)
{
	m_arrLineVtxs = arrVtxs;
	m_arrLineSubMeshs = arrSubMeshs;
	m_pLineMeshCom->CreateSimpleLineMesh(arrVtxs, arrSubMeshs);
	for (Gameint i = 0; i < m_arrLineVtxs.Num(); i++)
	{
		m_arrLineVtxs[i].Position += FVector(ROCacheManager::m_vecWorldOrigin);
	}
}

Gamevoid ASuperMap_ROEntityActor::SetIsSceneHiddenObject(Gamebool bHiddenObject)
{
	TArray<AActor*>& arrHiddenActors = GameObjectManager::GetSingleton()->GetSceneHiddenActors();

	if (bHiddenObject)
	{
		m_nHiddenIndex = arrHiddenActors.Add(this);
	}
	else
	{
		if (m_nHiddenIndex > -1)
		{
			arrHiddenActors.Remove(this);
			m_nHiddenIndex = -1;
		}
	}
}

Gamevoid ASuperMap_ROEntityActor::SetWorldOrigin(FIntVector & vIntOrigin)
{
	m_vecWorldOffset = vIntOrigin;
}

Gamebool ASuperMap_ROEntityActor::GetIsMeshNode()
{
	return m_bIsMeshNode;
}

Gamevoid ASuperMap_ROEntityActor::ClearMesh()
{
	m_pProceduralMeshCom->Clear();
}

Gamebool ASuperMap_ROEntityActor::GetCollision()
{
	return m_bCollision;
}

Gamevoid ASuperMap_ROEntityActor::SetCollision(Gamebool bEable)
{
	m_bCollision = bEable;
	m_pProceduralMeshCom->UpdateComponentCollision(bEable);
}

Gamevoid ASuperMap_ROEntityActor::BeginPlay()
{
	Super::BeginPlay();

}

Gamevoid ASuperMap_ROEntityActor::Tick(Gamefloat DeltaTime)
{
	Super::Tick(DeltaTime);

}

Gamevoid ASuperMap_ROEntityActor::SetProceduralMeshComponent(USuperMap_ProceduralMeshComponent* pProceduralMeshComponent)
{
	m_pProceduralMeshCom = pProceduralMeshComponent;
}

USuperMap_ProceduralMeshComponent* ASuperMap_ROEntityActor::GetProceduralMeshComponent()
{
	return m_pProceduralMeshCom;
}

UMaterialInterface* ASuperMap_ROEntityActor::GetMaterial()
{
	return m_pMaterial;
}

Gamevoid ASuperMap_ROEntityActor::SetMaterial(UMaterialInterface* pMaterial)
{
	pMaterial->AddToRoot();
	m_pMaterial = pMaterial;
}

Gamevoid ASuperMap_ROEntityActor::SetDrawType(Gameint nDrawType)
{
	m_nDrawType = nDrawType;
}

Gamevoid ASuperMap_ROEntityActor::SetName(FName strName)
{
	m_strName = strName;
}

FName ASuperMap_ROEntityActor::GetName()
{
	return m_strName;
}

Gamebool ASuperMap_ROEntityActor::GetVisibleLayer()
{
	return m_bVisibleLayer;
}

Gamevoid ASuperMap_ROEntityActor::SetVisibleLayer(Gamebool bVisible)
{
	if (m_bVisibleLayer == bVisible)
	{
		return;
	}

	m_bVisibleLayer = bVisible;
}

Gamevoid ASuperMap_ROEntityActor::SetIsMeshNode(Gamebool bMeshNode)
{
	m_bIsMeshNode = bMeshNode;
}

Gamevoid ASuperMap_ROEntityActor::SetLocalToWorld(Matrix4d & mat)
{
	m_matDoubleLocalToWorld = mat;
}

FIntVector ASuperMap_ROEntityActor::GetWorldOrigin()
{
	return m_vecWorldOffset;
}

Matrix4d ASuperMap_ROEntityActor::GetLocalToWorld()
{
	return m_matDoubleLocalToWorld;
}

Gamevoid ASuperMap_ROEntityActor::ApplyWorldOffset(const FVector& InOffset, Gamebool bWorldShift)
{
	/*外部手动变换, 内部不做处理*/
}

Gamevoid ASuperMap_ROEntityActor::UpdateWorldOrigin()
{
	TArray<SM_Vertex> arrVtxs = m_arrLineVtxs;
	for (Gameint i = 0; i < arrVtxs.Num(); i++)
	{
		arrVtxs[i].Position -= FVector(ROCacheManager::m_vecWorldOrigin);
	}
	m_pLineMeshCom->CreateSimpleLineMesh(arrVtxs, m_arrLineSubMeshs);
}
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif