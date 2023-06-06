#include "Component/CustomRealRasterMesh.h"

CustomRealRasterMesh::CustomRealRasterMesh()
{
	m_bVisibleLayer = true;
}

CustomRealRasterMesh::~CustomRealRasterMesh()
{
	// ÒªÊÍ·Å
}

Gamevoid CustomRealRasterMesh::CreateMesh(const FSMMesh& meshData)
{
	mMesh.m_arrDataIndex.SetNum(meshData.m_arrDataIndex.Num());
	for (int i = 0; i < meshData.m_arrDataIndex.Num(); i++)
	{
		mMesh.m_arrDataIndex[i] = meshData.m_arrDataIndex[i];
	}
	mMesh.m_pDataVertex = meshData.m_pDataVertex;

	mMesh.m_matTex = meshData.m_matTex;
	mMesh.m_nTextureWidth = meshData.m_nTextureWidth;
	mMesh.m_nTextureHeight = meshData.m_nTextureHeight;
}

Gamevoid CustomRealRasterMesh::SetName(FName strName)
{
	m_strName = strName;
}

FName CustomRealRasterMesh::GetName()
{
	return m_strName;
}

FSMMesh& CustomRealRasterMesh::GetMesh()
{
	return mMesh;
}

Gamevoid CustomRealRasterMesh::SetLayerVisibility(Gamebool bIsVisible)
{
	m_bVisibleLayer = bIsVisible;
}

Gamebool CustomRealRasterMesh::GetLayerVisibility()
{
	return m_bVisibleLayer;
}


Gamevoid CustomRealRasterMesh::UpdateMesh(const FSMMesh & smMesh, UGVertexDataStateSet nState)
{
	if (nState == VST_VertexColor)
	{
		// Ìæ»»ÑÕÉ«
		FMemory::Memcpy(mMesh.m_pDataVertex->m_PosColor + smMesh.m_nSubMeshInfoOffset,
			smMesh.m_pDataVertex->m_PosColor, sizeof(Gameuint) * smMesh.m_pDataVertex->m_nColorCount);
	}
}