#pragma once

#include "CoreMinimal.h"
#include "Component/MeshData.h"

class CustomRealRasterMesh
{

public:
	CustomRealRasterMesh();
	~CustomRealRasterMesh();

	//! \brief 创建骨架
	Gamevoid CreateMesh(const FSMMesh& meshData);

	//! \brief 设置名字
	Gamevoid SetName(FName strName);

	//! \brief 获取名字
	FName GetName();

	//! \brief 获取骨架
	FSMMesh& GetMesh();

	//! \brief 设置是否所属图层是否可见
	//! \param bVisible [in] 是否可见
	Gamevoid SetLayerVisibility(Gamebool bIsVisible);

	//! \brief 获取图层可见性
	//! \return 图层可见性
	Gamebool GetLayerVisibility();

	Gamevoid UpdateMesh(const FSMMesh & meshData, UGVertexDataStateSet nState);
private:
	//! \brief 名称
	FName m_strName;

	//! \brief 骨架包
	FSMMesh mMesh;


	//! \brief 所属图层的可见性
	Gamebool m_bVisibleLayer;
};