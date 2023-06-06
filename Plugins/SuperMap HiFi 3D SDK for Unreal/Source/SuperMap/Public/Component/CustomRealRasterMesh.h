#pragma once

#include "CoreMinimal.h"
#include "Component/MeshData.h"

class CustomRealRasterMesh
{

public:
	CustomRealRasterMesh();
	~CustomRealRasterMesh();

	//! \brief �����Ǽ�
	Gamevoid CreateMesh(const FSMMesh& meshData);

	//! \brief ��������
	Gamevoid SetName(FName strName);

	//! \brief ��ȡ����
	FName GetName();

	//! \brief ��ȡ�Ǽ�
	FSMMesh& GetMesh();

	//! \brief �����Ƿ�����ͼ���Ƿ�ɼ�
	//! \param bVisible [in] �Ƿ�ɼ�
	Gamevoid SetLayerVisibility(Gamebool bIsVisible);

	//! \brief ��ȡͼ��ɼ���
	//! \return ͼ��ɼ���
	Gamebool GetLayerVisibility();

	Gamevoid UpdateMesh(const FSMMesh & meshData, UGVertexDataStateSet nState);
private:
	//! \brief ����
	FName m_strName;

	//! \brief �Ǽܰ�
	FSMMesh mMesh;


	//! \brief ����ͼ��Ŀɼ���
	Gamebool m_bVisibleLayer;
};