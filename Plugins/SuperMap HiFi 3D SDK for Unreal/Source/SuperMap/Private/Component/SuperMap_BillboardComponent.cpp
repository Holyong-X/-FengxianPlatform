#include "Component/SuperMap_BillboardComponent.h"
#include "Base3D/CommonDefine.h"
#include "Core/Georeference.h"
#include "Engine/Texture2D.h"
#include "Materials/MaterialInstanceDynamic.h"

USuperMap_BillboardComponent::USuperMap_BillboardComponent()
{
	m_bVisible = true;
	m_bVisibleLayer = true;
	m_pMaterial = nullptr;
	m_pSecondMaterial = nullptr;
	m_nBaseSizeX = 0;
	m_nBaseSizeY = 0;
}

Gamevoid USuperMap_BillboardComponent::CreateMesh(const FSMMesh& meshData, Gamebool bCollision)
{
	if (!meshData.isValid())
	{
		return;
	}

	// 三角形
	int32 nTriangleCount = meshData.m_arrDataIndex[0]->m_nIndexCount / 3;
	for (int32 n = 0; n < nTriangleCount; n+=2)
	{
		// 创建
		USuperMap_MaterialBillboardComponent* pBillboardComponent = NewObject<USuperMap_MaterialBillboardComponent>(this);
		pBillboardComponent->RegisterComponent();
		FAttachmentTransformRules transformRules(EAttachmentRule::KeepRelative, true);
		pBillboardComponent->AttachToComponent(this, transformRules);
		pBillboardComponent->SetHiddenInGame(false);
		// TODO
		if (m_pMaterial != nullptr) 
		{
			pBillboardComponent->AddElement(m_pMaterial, NULL, false, m_nBaseSizeX * 100, m_nBaseSizeY * 100, nullptr);
		}
		m_arrBillboardComponents.Add(pBillboardComponent);


		int32 nIndex1=0;
		int32 nIndex2=0;
		int32 nIndex3=0;
		int32 nIndex4=0;
		int32 nIndex5=0;
		int32 nIndex6=0;


		if (meshData.m_arrDataIndex[0]->m_shortIndex != nullptr)
		{
			nIndex1 = meshData.m_arrDataIndex[0]->m_shortIndex[n * 3 + 0];
			nIndex2 = meshData.m_arrDataIndex[0]->m_shortIndex[n * 3 + 1];
			nIndex3 = meshData.m_arrDataIndex[0]->m_shortIndex[n * 3 + 2];
															  
			nIndex4 = meshData.m_arrDataIndex[0]->m_shortIndex[n * 3 + 3];
			nIndex5 = meshData.m_arrDataIndex[0]->m_shortIndex[n * 3 + 4];
			nIndex6 = meshData.m_arrDataIndex[0]->m_shortIndex[n * 3 + 5];
		}

		if (meshData.m_arrDataIndex[0]->m_Index != nullptr)
		{
			nIndex1 = meshData.m_arrDataIndex[0]->m_Index[n * 3 + 0];
			nIndex2 = meshData.m_arrDataIndex[0]->m_Index[n * 3 + 1];
			nIndex3 = meshData.m_arrDataIndex[0]->m_Index[n * 3 + 2];
														 
			nIndex4 = meshData.m_arrDataIndex[0]->m_Index[n * 3 + 3];
			nIndex5 = meshData.m_arrDataIndex[0]->m_Index[n * 3 + 4];
			nIndex6 = meshData.m_arrDataIndex[0]->m_Index[n * 3 + 5];
		}

		float u = 0, ul = 0, v = 0, vl = 0;

		FMatrix matTex;
		Matrix4d::ToFMatrix(m_matTexcoord, matTex);
		if (meshData.m_pDataVertex->m_TexCoord != nullptr)
		{
			int32 nTexDim = meshData.m_pDataVertex->m_nTexCoordDim;
			FVector uv1;
			uv1.X = meshData.m_pDataVertex->m_TexCoord[nIndex1 * nTexDim + 0];
			uv1.Y = meshData.m_pDataVertex->m_TexCoord[nIndex1 * nTexDim + 1];
			uv1.Z = 1.0;

			FVector4 vUV1 = matTex.TransformPosition(uv1);

			u = ul = vUV1.X;
			v = vl = vUV1.Y;

			FVector uv2;
			uv2.X = meshData.m_pDataVertex->m_TexCoord[nIndex2 * nTexDim + 0];
			uv2.Y = meshData.m_pDataVertex->m_TexCoord[nIndex2 * nTexDim + 1];
			uv2.Z = 1.0;

			FVector4 vUV2 = matTex.TransformPosition(uv2);

			u  = FMath::Min(u,  vUV2.X);
			ul = FMath::Max(ul, vUV2.X);
			v  = FMath::Min(v,  vUV2.Y);
			vl = FMath::Max(vl, vUV2.Y);

			FVector uv3;
			uv3.X = meshData.m_pDataVertex->m_TexCoord[nIndex3 * nTexDim + 0];
			uv3.Y = meshData.m_pDataVertex->m_TexCoord[nIndex3 * nTexDim + 1];
			uv3.Z = 1.0;

			FVector4 vUV3 = matTex.TransformPosition(uv3);

			u  = FMath::Min(u,  vUV3.X);
			ul = FMath::Max(ul, vUV3.X); 
			v  = FMath::Min(v,  vUV3.Y);
			vl = FMath::Max(vl, vUV3.Y);

			FVector uv4;
			uv4.X = meshData.m_pDataVertex->m_TexCoord[nIndex4 * nTexDim + 0];
			uv4.Y = meshData.m_pDataVertex->m_TexCoord[nIndex4 * nTexDim + 1];
			uv4.Z = 1.0;

			FVector4 vUV4 = matTex.TransformPosition(uv4);

			u  = FMath::Min(u,  vUV4.X);
			ul = FMath::Max(ul, vUV4.X);
			v  = FMath::Min(v,  vUV4.Y);
			vl = FMath::Max(vl, vUV4.Y);

			FVector uv5;
			uv5.X = meshData.m_pDataVertex->m_TexCoord[nIndex5 * nTexDim + 0];
			uv5.Y = meshData.m_pDataVertex->m_TexCoord[nIndex5 * nTexDim + 1];
			uv5.Z = 1.0;

			FVector4 vUV5 = matTex.TransformPosition(uv5);

			u  = FMath::Min(u,  vUV5.X);
			ul = FMath::Max(ul, vUV5.X);
			v  = FMath::Min(v,  vUV5.Y);
			vl = FMath::Max(vl, vUV5.Y);

			FVector uv6;
			uv6.X = meshData.m_pDataVertex->m_TexCoord[nIndex6 * nTexDim + 0];
			uv6.Y = meshData.m_pDataVertex->m_TexCoord[nIndex6 * nTexDim + 1];
			uv6.Z = 1.0;

			FVector4 vUV6 = matTex.TransformPosition(uv6);

			u  = FMath::Min(u,  vUV6.X);
			ul = FMath::Max(ul, vUV6.X);
			v  = FMath::Min(v,  vUV6.Y);
			vl = FMath::Max(vl, vUV6.Y);
		}

		pBillboardComponent->SetUV(u, v, ul, vl);
		
		if (meshData.m_pDataVertex != nullptr)
		{
			int32 nVertexDim = meshData.m_pDataVertex->m_nPosDim;
			
			FVector vOffset;
			vOffset.Y = meshData.m_pDataVertex->m_Pos[nIndex1 * nVertexDim + 0] * M_TO_CM;
			vOffset.X = meshData.m_pDataVertex->m_Pos[nIndex1 * nVertexDim + 1] * M_TO_CM;
			vOffset.Z = meshData.m_pDataVertex->m_Pos[nIndex1 * nVertexDim + 2] * M_TO_CM;

			pBillboardComponent->SetRelativeLocation(vOffset);
		}
	}
}

Gamevoid USuperMap_BillboardComponent::SetBillboardParam(Gameint nBaseSizeX, Gameint nBaseSizeY, Matrix4d matTexcoord)
{
	m_nBaseSizeX = nBaseSizeX;
	m_nBaseSizeY = nBaseSizeY;
	m_matTexcoord = matTexcoord;
}

Gamevoid USuperMap_BillboardComponent::SetName(FName strName)
{
	m_strName = strName;
}

FName USuperMap_BillboardComponent::GetName()
{
	return m_strName;
}

Gamevoid USuperMap_BillboardComponent::SetLayerVisibility(Gamebool bIsVisible)
{
	m_bVisibleLayer = bIsVisible;
}

Gamebool USuperMap_BillboardComponent::GetLayerVisibility()
{
	return m_bVisibleLayer;
}

Gamevoid USuperMap_BillboardComponent::SetInternalVisibility(Gamebool bIsVisible)
{
	m_bVisible = bIsVisible;
}

Gamebool USuperMap_BillboardComponent::GetInternalVisibility()
{
	return m_bVisible;
}

Gamevoid USuperMap_BillboardComponent::SetLocalToECEF(const Matrix4d& mat)
{
	m_matLocalToECEF = mat;
}

Matrix4d USuperMap_BillboardComponent::GetLocalToECEF()
{
	return m_matLocalToECEF;
}

Gamevoid USuperMap_BillboardComponent::SetCustomMaterial(UMaterialInterface* pMat)
{
	m_pMaterial = pMat;
}

UMaterialInterface* USuperMap_BillboardComponent::GetCustomMaterial()
{
	return m_pMaterial;
}

Gamevoid USuperMap_BillboardComponent::SetCustomSecondMaterial(UMaterialInterface* pMat)
{
	m_pSecondMaterial = pMat;
}

UMaterialInterface* USuperMap_BillboardComponent::GetCustomSecondMaterial()
{
	return m_pSecondMaterial;
}

Matrix4d USuperMap_BillboardComponent::GetLocalToWorld()
{
	return m_matDoubleLocalToWorld;
}

Gamevoid USuperMap_BillboardComponent::UpdateTransform(Vector3d vOffset, FTransform & transform)
{
	Georeference::TransformECEFToUERelative(m_matLocalToECEF, transform);
}

Gamevoid USuperMap_BillboardComponent::SetTexture(UTexture2D* pTexture)
{
	int32 nBillboardComponentCount = m_arrBillboardComponents.Num();
	for (int32 n = 0; n < nBillboardComponentCount; n++)
	{
		UMaterialInstanceDynamic* pMID = (UMaterialInstanceDynamic*)m_arrBillboardComponents[n]->Elements[0].Material;
		pMID->SetTextureParameterValue(FName("SpriteTexture"), pTexture);
	}
}
