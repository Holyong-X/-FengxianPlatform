#include "Component/SuperMap_StaticMeshComponent.h"
#include "Component/SuperMap_VertexBuffer.h"
#if PHYSICS_INTERFACE_PHYSX
#include "IPhysXCooking.h"
#else
#include "Chaos/CollisionConvexMesh.h"
#include "Chaos/TriangleMeshImplicitObject.h"
#if !SM_FOR_UE_FIVE
#include "ChaosDerivedDataUtil.h"
#endif
#endif
#include "Engine/CollisionProfile.h"
#include "Base3D/CommonDefine.h"

#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif

static Gamevoid computeFlatNormalsForStaticMesh(
	const TArray<uint32_t>& indices,
	TArray<FStaticMeshBuildVertex>& vertices) {
	// Compute flat normals
	for (int64_t i = 0; i < indices.Num(); i += 3) {
		FStaticMeshBuildVertex& v0 = vertices[i];
		FStaticMeshBuildVertex& v1 = vertices[i + 1];
		FStaticMeshBuildVertex& v2 = vertices[i + 2];

		GameVector3 v01 = v1.Position - v0.Position;
		GameVector3 v02 = v2.Position - v0.Position;
		GameVector3 normal = GameVector3::CrossProduct(v01, v02);

		v0.TangentZ = -normal.GetSafeNormal();
		v1.TangentZ = v0.TangentZ;
		v2.TangentZ = v0.TangentZ;
	}
}

USuperMap_StaticMeshComponent::USuperMap_StaticMeshComponent()
{
	m_bVisible      = true;
	m_bVisibleLayer = true;
	m_bUseComplexAsSimpleCollision = true;
	m_bCollision = false;
	m_pMaterial = nullptr;

#if PHYSICS_INTERFACE_PHYSX
	m_pPhysXCooking = GetPhysXCookingModule()->GetPhysXCooking();
#endif
}

USuperMap_StaticMeshComponent::~USuperMap_StaticMeshComponent()
{

}

Gamevoid USuperMap_StaticMeshComponent::SetName(FName strName)
{
	m_strName = strName;
}

FName USuperMap_StaticMeshComponent::GetName()
{
	return m_strName;
}

Gamevoid USuperMap_StaticMeshComponent::SetLayerVisibility(Gamebool bIsVisible)
{
	m_bVisibleLayer = bIsVisible;
	SetVisibility(bIsVisible, false);
}

Gamebool USuperMap_StaticMeshComponent::GetLayerVisibility()
{
	return m_bVisibleLayer;
}

Gamevoid USuperMap_StaticMeshComponent::SetRender(Gamebool bIsRender)
{
	m_bRender = bIsRender;
}

Gamebool USuperMap_StaticMeshComponent::GetRender()
{
	return m_bRender;
}


Gamevoid USuperMap_StaticMeshComponent::SetInternalVisibility(Gamebool bIsVisible)
{
	m_bVisible = bIsVisible;
	SetVisibility(bIsVisible, false);
}

Gamebool USuperMap_StaticMeshComponent::GetInternalVisibility()
{
	return m_bVisible;
}

Gamevoid USuperMap_StaticMeshComponent::SetCustomMaterial(UMaterialInterface* pMat)
{
	m_pMaterial = pMat;
	UStaticMesh* pStaticMesh = GetStaticMesh();
	if (pStaticMesh == nullptr)
	{
		return;
	}
	// TODO
	pStaticMesh->AddMaterial(pMat);
}

UMaterialInterface* USuperMap_StaticMeshComponent::GetCustomMaterial()
{
	return m_pMaterial;
}

Gamevoid USuperMap_StaticMeshComponent::SetLocalToECEF(const Matrix4d& mat)
{
	m_matLocalToECEF = mat;
}

Matrix4d USuperMap_StaticMeshComponent::GetLocalToECEF()
{
	return m_matLocalToECEF;
}

Gamevoid USuperMap_StaticMeshComponent::ComputeBoundingSphere(const FSMMesh& meshData, FBoxSphereBounds& boundingBoxAndSphere)
{
	FVector min;
	FVector max;
	boundingBoxAndSphere.SphereRadius = 0.0f;

	for (Gameint n = 0; n < meshData.m_pDataVertex->m_nPosCount; n++)
	{
		Gameint nVertexDim = meshData.m_pDataVertex->m_nPosDim;

		FVector pos;
		pos.Y = meshData.m_pDataVertex->m_Pos[n * nVertexDim + 0] * M_TO_CM;
		pos.X = meshData.m_pDataVertex->m_Pos[n * nVertexDim + 1] * M_TO_CM;
		pos.Z = meshData.m_pDataVertex->m_Pos[n * nVertexDim + 2] * M_TO_CM;

		if (n == 0)
		{
			min = pos;
			max = pos;
		}
		else
		{
			min.X = FMath::Min(min.X, pos.X);
			min.Y = FMath::Min(min.Y, pos.Y);
			min.Z = FMath::Min(min.Z, pos.Z);

			max.X = FMath::Max(max.X, pos.X);
			max.Y = FMath::Max(max.Y, pos.Y);
			max.Z = FMath::Max(max.Z, pos.Z);
		}
	}

	FBox aaBox(min, max);
	aaBox.GetCenterAndExtents(boundingBoxAndSphere.Origin,
		boundingBoxAndSphere.BoxExtent);
}
Gamevoid USuperMap_StaticMeshComponent::DecodeDataPackage(const FSMMesh& meshData)
{
	Gamebool bVertexCompress = GameConvertor::HasCompressOptions(meshData.m_pDataVertex->m_nCompressType, VertexCompressOptions::SVC_Vertex);
	Gamebool bNormalCompress = GameConvertor::HasCompressOptions(meshData.m_pDataVertex->m_nCompressType, VertexCompressOptions::SVC_Normal);
	Gamebool bTextureCoordCompress = GameConvertor::HasCompressOptions(meshData.m_pDataVertex->m_nCompressType, VertexCompressOptions::SVC_TexutreCoord);
	//! \brief 解压顶点
	
	Gameint nVertexCount = meshData.m_pDataVertex->m_nPosCount;
	Gameint nVertexDim = meshData.m_pDataVertex->m_nPosDim;
	Gamefloat* pNewPos = new Gamefloat[nVertexDim * nVertexCount];

	Gameint nNormalCount = meshData.m_pDataVertex->m_nNormalCount;
	Gameint nNormalDim = 2;
	Gamefloat* pNewNormal = new Gamefloat[nNormalCount * 3];
	meshData.m_pDataVertex->m_nNormalDim = 3;

	Gameint nTexCoordCount = meshData.m_pDataVertex->m_nTexCoordCount;
	Gameint nTexCoordDim = 2;
	Gamefloat* pNewTexCoord = new Gamefloat[nTexCoordCount * 2];
	for (Gameint i = 0; i < nVertexCount; i++)
	{
		if (bVertexCompress)
		{
			FVector4 vPos(0, 0, 0, 0);
			vPos.X = ((short*)(meshData.m_pDataVertex->m_Pos))[i * nVertexDim + 0];
			vPos.Y = ((short*)(meshData.m_pDataVertex->m_Pos))[i * nVertexDim + 1];
			vPos.Z = ((short*)(meshData.m_pDataVertex->m_Pos))[i * nVertexDim + 2];
			if (nVertexDim > 3)
			{
				vPos.W = ((short*)(meshData.m_pDataVertex->m_Pos))[i * nVertexDim + 3];
			}

			vPos *= meshData.m_pDataVertex->m_fVertCompressConstant;
			vPos += meshData.m_pDataVertex->m_vMinVerticesValue;

			pNewPos[i * nVertexDim + 0] = vPos.X;
			pNewPos[i * nVertexDim + 1] = vPos.Y;
			pNewPos[i * nVertexDim + 2] = vPos.Z;
			if (nVertexDim > 3)
			{
				pNewPos[i * nVertexDim + 3] = vPos.W;
			}
		}
		
		if (bNormalCompress && meshData.m_pDataVertex->m_nNormalCount > 0)
		{
			FVector2D vOriginNormal(0.0, 0.0);
			vOriginNormal.X = ((short*)(meshData.m_pDataVertex->m_Normal))[i * nNormalDim + 0];
			vOriginNormal.Y = ((short*)(meshData.m_pDataVertex->m_Normal))[i * nNormalDim + 1];

			vOriginNormal /= 127.0;

			FVector vNormal;
			vNormal.X = vOriginNormal.X;
			vNormal.Y = vOriginNormal.Y;
			vNormal.Z = 1.0f - FMath::Abs(vNormal.X) - FMath::Abs(vNormal.Y);

			pNewNormal[i * 3 + 0] = vNormal.X;
			pNewNormal[i * 3 + 1] = vNormal.Y;
			pNewNormal[i * 3 + 2] = vNormal.Z;
		}
		
		if (bTextureCoordCompress && meshData.m_pDataVertex->m_nTexCoordCount > 0)
		{
			FVector2D vTexCoord(0.0,0.0);
			vTexCoord.X = ((short*)(meshData.m_pDataVertex->m_TexCoord))[i * nTexCoordDim + 0];
			vTexCoord.Y = ((short*)(meshData.m_pDataVertex->m_TexCoord))[i * nTexCoordDim + 1];

			vTexCoord *= meshData.m_pDataVertex->m_texCoordCompressUV0Constant;
			vTexCoord += meshData.m_pDataVertex->m_texCoord0Min;

			pNewTexCoord[i * nTexCoordDim + 0] = vTexCoord.X;
			pNewTexCoord[i * nTexCoordDim + 1] = vTexCoord.Y;
		}

	}
	
	if (meshData.m_pDataVertex->m_Pos)
	{
		delete meshData.m_pDataVertex->m_Pos;
		meshData.m_pDataVertex->m_Pos = nullptr;
	}
	
	if (meshData.m_pDataVertex->m_Normal)
	{
		delete meshData.m_pDataVertex->m_Normal;
		meshData.m_pDataVertex->m_Normal = nullptr;
	}
	
	if (meshData.m_pDataVertex->m_TexCoord)
	{
		delete meshData.m_pDataVertex->m_TexCoord;
		meshData.m_pDataVertex->m_TexCoord = nullptr;
	}

	meshData.m_pDataVertex->m_Pos = pNewPos;
	meshData.m_pDataVertex->m_Normal = pNewNormal;
	meshData.m_pDataVertex->m_TexCoord = pNewTexCoord;

}

Gamevoid USuperMap_StaticMeshComponent::CreateStaticMeshRenderData(const FSMMesh & meshData, StaticMeshRenderData & smrd)
{
	m_eDrawType = FSuperMapVertexBuffer::GetDrawType(meshData);

	FStaticMeshRenderData* RenderData = new FStaticMeshRenderData();
	RenderData->AllocateLODResources(1);

	FStaticMeshLODResources& LODResources = RenderData->LODResources[0];

	FBoxSphereBounds BoundingBoxAndSphere;
	BoundingBoxAndSphere.SphereRadius = 0.0f;
	// 求包围盒
	ComputeBoundingSphere(meshData, BoundingBoxAndSphere);

	Gameint oldNumVertices = meshData.m_pDataVertex->m_nPosCount;
	Gameint NumVertices = oldNumVertices;
	Gameint nIndices = meshData.m_arrDataIndex[0]->m_nIndexCount;

	if (m_eDrawType == PT_TriangleList)
	{
		NumVertices = nIndices;
	}

	Gamebool hasVertexColors = false;

	TArray<FStaticMeshBuildVertex> StaticMeshBuildVertices;
	StaticMeshBuildVertices.SetNum(NumVertices);

	TArray<Gameuint> indices;

	for (Gameint n = 0; n < NumVertices; n++)
	{
		// 顶点
		Gameuint index = n;


		if (meshData.m_arrDataIndex[0]->m_shortIndex != nullptr)
		{
			index = meshData.m_arrDataIndex[0]->m_shortIndex[n];
		}

		if (meshData.m_arrDataIndex[0]->m_Index != nullptr)
		{
			index = meshData.m_arrDataIndex[0]->m_Index[n];
		}

		indices.Add(index);

		// 顶点
		if (meshData.m_pDataVertex->m_Pos != nullptr)
		{
			Gameint nVertexDim = meshData.m_pDataVertex->m_nPosDim;

			FVector pos;
			pos.Y = meshData.m_pDataVertex->m_Pos[index * nVertexDim + 0] * M_TO_CM;
			pos.X = meshData.m_pDataVertex->m_Pos[index * nVertexDim + 1] * M_TO_CM;
			pos.Z = meshData.m_pDataVertex->m_Pos[index * nVertexDim + 2] * M_TO_CM;

			FStaticMeshBuildVertex& vertex = StaticMeshBuildVertices[n];
			vertex.Position = GameVector3(pos);

			BoundingBoxAndSphere.SphereRadius = FMath::Max(
				(vertex.Position - GameVector3(BoundingBoxAndSphere.Origin)).Size(),
				BoundingBoxAndSphere.SphereRadius);
		}

		//===============BlendWeights======================
		Gamebool bNewModel = false;
		if (meshData.m_pDataVertex->m_pBlendWeights != nullptr)
		{
			// TODO
			FVector2D weights;
			weights.X = meshData.m_pDataVertex->m_pBlendWeights[index];
			weights.Y = 0;

			bNewModel = true;
			FStaticMeshBuildVertex& vertex = StaticMeshBuildVertices[n];
			vertex.UVs[1] = GameVector2(weights);
		}
		//=================================================

		// 法线
		if (meshData.m_pDataVertex->m_nNormalCount > 0 && meshData.m_pDataVertex->m_Normal != nullptr)
		{
			FVector normal;
			normal.Y = meshData.m_pDataVertex->m_Normal[index * 3 + 0];
			normal.X = meshData.m_pDataVertex->m_Normal[index * 3 + 1];
			normal.Z = meshData.m_pDataVertex->m_Normal[index * 3 + 2];

			FStaticMeshBuildVertex& vertex = StaticMeshBuildVertices[n];
			vertex.TangentZ = GameVector3(normal);
		}

		// 顶点颜色
		if (meshData.m_pDataVertex->m_nColorCount > 0 && meshData.m_pDataVertex->m_PosColor != nullptr)
		{
			Gameuint nColor = meshData.m_pDataVertex->m_PosColor[index];

			GameVector4 color;
			_IDRGBA(nColor, color.X, color.Y, color.Z, color.W);

			FStaticMeshBuildVertex& vertex = StaticMeshBuildVertices[n];
			vertex.Color = FColor(uint8(color.X * 255), uint8(color.Y * 255), uint8(color.Z * 255), uint8(color.W * 255));
			
			hasVertexColors = true;
		}

		if (meshData.m_pDataVertex->m_nTexCoordCount > 0 && meshData.m_pDataVertex->m_TexCoord != nullptr)
		{
			FStaticMeshBuildVertex& vertex = StaticMeshBuildVertices[n];
			Gameint nTexDim = meshData.m_pDataVertex->m_nTexCoordDim;
			FVector2D UV0;
			FVector2D UV1;
			if (nTexDim == 2)
			{
				UV0.X = meshData.m_pDataVertex->m_TexCoord[nTexDim * index + 0];
				UV0.Y = 1.0 - meshData.m_pDataVertex->m_TexCoord[nTexDim * index + 1];
				vertex.UVs[0] = GameVector2(UV0);
			}
			else if (nTexDim == 3)
			{
				UV0.X = meshData.m_pDataVertex->m_TexCoord[nTexDim * index + 0];
				UV0.Y = 1.0 - meshData.m_pDataVertex->m_TexCoord[nTexDim * index + 1];
				UV1.X = meshData.m_pDataVertex->m_TexCoord[nTexDim * index + 2];

				vertex.UVs[0] = GameVector2(UV0);
				if (!bNewModel)
				{
					vertex.UVs[1] = GameVector2(UV1);
				}

			}
		}

		if (meshData.m_pDataVertex->m_nVertexAttCount > 1)
		{
			FStaticMeshBuildVertex& vertex = StaticMeshBuildVertices[n];
			GameVector2 UV1;
			//! \brief 更新纹理矩阵
			VertexAttribute& vertexAtt = meshData.m_pDataVertex->m_vecVertexAttribute[1];
			if (vertexAtt.m_enVertexAttDataType == AT_FLOAT && vertexAtt.m_pVertexAttData != nullptr)
			{
				UV1.X = ((Gamefloat*)vertexAtt.m_pVertexAttData)[index * vertexAtt.m_nVertexAttDataDimension + 0];
				UV1.Y = 0;
				vertex.UVs[1] = UV1;
			}
			
		}
	}


	// OLD NOTE:因为UE是左手坐标系，所以在UE重新计算法线后需要把索引顺序反转一下才正确。如果没重新计算法线则不用
	// NEW NOTE:计算法线后发现正反面反了，所以不把索引顺序反转，只是把法线反转一下。如果没重新计算法线则不用
	Gamebool bReverseIndex = false;
	if (m_eDrawType == PT_TriangleList)
	{
		// 计算法线
		if (meshData.m_pDataVertex->m_Normal == nullptr)
		{
			computeFlatNormalsForStaticMesh(indices, StaticMeshBuildVertices);
		}
	}

	RenderData->Bounds = BoundingBoxAndSphere;


	// 初始化顶点
	LODResources.VertexBuffers.PositionVertexBuffer.Init(StaticMeshBuildVertices);

	// 如果有顶点颜色
	LODResources.bHasColorVertexData = hasVertexColors;

	// 顶点颜色
	FColorVertexBuffer& ColorVertexBuffer =
		LODResources.VertexBuffers.ColorVertexBuffer;
	if (hasVertexColors) {
		ColorVertexBuffer.Init(StaticMeshBuildVertices);
	}
	else if (meshData.m_arrDataIndex[0]->m_nIndexCount > 0) {
		ColorVertexBuffer.InitFromSingleColor(FColor::White, meshData.m_arrDataIndex[0]->m_nIndexCount);
	}
	LODResources.VertexBuffers.StaticMeshVertexBuffer.SetUseHighPrecisionTangentBasis(true);
	LODResources.VertexBuffers.StaticMeshVertexBuffer.SetUseFullPrecisionUVs(true);
	LODResources.VertexBuffers.StaticMeshVertexBuffer.Init(
		StaticMeshBuildVertices,
		4);

#if !SM_FOR_UE_FIVE
	FStaticMeshLODResources::FStaticMeshSectionArray& Sections =
		LODResources.Sections;
#else
	FStaticMeshSectionArray& Sections = LODResources.Sections;
#endif
	FStaticMeshSection& section = Sections.AddDefaulted_GetRef();
	section.bEnableCollision = true;

	section.NumTriangles = StaticMeshBuildVertices.Num() / 3;
	section.FirstIndex = 0;
	section.MinVertexIndex = 0;
	section.MaxVertexIndex = StaticMeshBuildVertices.Num() - 1;
	section.bEnableCollision = true;
	section.bCastShadow = true;

	// 因为顶点不共用了，所以重构索引
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

	LODResources.IndexBuffer.SetIndices(
		indices,
		indices.Num() > std::numeric_limits<uint16>::max()
		? EIndexBufferStride::Type::Force32Bit
		: EIndexBufferStride::Type::Force16Bit);

	LODResources.bHasDepthOnlyIndices = false;
	LODResources.bHasReversedIndices = false;
	LODResources.bHasReversedDepthOnlyIndices = false;
#if !SM_FOR_UE_FIVE
	LODResources.bHasAdjacencyInfo = false;
#endif
	section.MaterialIndex = 0;

	if (m_bCollision)
	{
#if PHYSICS_INTERFACE_PHYSX
		if (m_pPhysXCooking) {
			TArray<FVector> vertices;
			vertices.SetNum(StaticMeshBuildVertices.Num());

			for (size_t i = 0; i < StaticMeshBuildVertices.Num(); ++i) {
				vertices[i] = StaticMeshBuildVertices[i].Position;
			}

			TArray<FTriIndices> physicsIndices;
			physicsIndices.SetNum(StaticMeshBuildVertices.Num() / 3);

			for (size_t i = 0; i < StaticMeshBuildVertices.Num() / 3; ++i) {
				if (bReverseIndex)
				{
					physicsIndices[i].v0 = i * 3 + 2;
					physicsIndices[i].v1 = i * 3 + 1;
					physicsIndices[i].v2 = i * 3;
				}
				else
				{
					physicsIndices[i].v0 = i * 3;
					physicsIndices[i].v1 = i * 3 + 1;
					physicsIndices[i].v2 = i * 3 + 2;
				}
			}

			m_pPhysXCooking->CreateTriMesh(
				"PhysXGeneric",
				EPhysXMeshCookFlags::Default,
				vertices,
				physicsIndices,
				TArray<uint16>(),
				true,
				smrd.pCollisionMesh);
		}
#else
		if (StaticMeshBuildVertices.Num() != 0 && indices.Num() != 0) {
			smrd.pCollisionMesh = nullptr;
		}
#endif
	}

	smrd.m_pRenderData = RenderData;
	
}

Gamevoid USuperMap_StaticMeshComponent::CreateMesh(const FSMMesh & meshData, Gamebool bCollision)
{
	if (!meshData.isValid())
	{
		return;
	}

	//! \brief 解压
	if (meshData.m_pDataVertex->m_nCompressType > 0)
	{
		DecodeDataPackage(meshData);
	}

	m_bCollision = true;
	SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	bUseDefaultCollision = true;
	
	SetFlags(RF_Transient);
	
	StaticMeshRenderData smrd;
	smrd.pCollisionMesh = nullptr;
	CreateStaticMeshRenderData(meshData, smrd);

	FStaticMeshRenderData* RenderData = smrd.m_pRenderData;

	UStaticMesh* pStaticMesh = NewObject<UStaticMesh>();
	SetStaticMesh(pStaticMesh);
#if !SM_FOR_UE_FIVE
	pStaticMesh->bIsBuiltAtRuntime = true;
	pStaticMesh->RenderData =
		TUniquePtr<FStaticMeshRenderData>(RenderData);
	pStaticMesh->RenderData->ScreenSize[0].Default = 1.0f;
#else
	pStaticMesh->SetRenderData(TUniquePtr<FStaticMeshRenderData>(RenderData));
	pStaticMesh->GetRenderData()->ScreenSize[0].Default = 1.0f;
#endif
	pStaticMesh->NeverStream = true;

	if (m_pMaterial != nullptr)
	{
		pStaticMesh->AddMaterial(m_pMaterial);
	}

	pStaticMesh->InitResources();

	// Set up RenderData bounds and LOD data
	pStaticMesh->CalculateExtendedBounds();
	
	pStaticMesh->CreateBodySetup();

	GetBodySetup()->CollisionTraceFlag = ECollisionTraceFlag::CTF_UseComplexAsSimple;
	SetMobility(EComponentMobility::Static);

	//bDrawMeshCollisionIfComplex = true;
	//bDrawMeshCollisionIfSimple = true;

	if (smrd.pCollisionMesh) {
#if PHYSICS_INTERFACE_PHYSX
		GetBodySetup()->TriMeshes.Add(smrd.pCollisionMesh);
#else
		GetBodySetup()->ChaosTriMeshes.Add(smrd.pCollisionMesh);
#endif
		GetBodySetup()->bCreatedPhysicsMeshes = true;
	}
}

Gamevoid USuperMap_StaticMeshComponent::UpdateTransform(Vector3d vOffset, FTransform & transform)
{
	Georeference::TransformECEFToUERelative(m_matLocalToECEF, transform);
}

#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif