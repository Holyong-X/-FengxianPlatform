#pragma once
#include "Base3D/CommonDefine.h"
#include "Component/SuperMap_OcclusionVolumeComponent.h"
namespace SuperMapSDK
{

	//! \brief �����ڵ��� 
	typedef Gamevoid* (*CreateOcclusionVolumeFunction)(Gamelong strIDName);

	//! \brief ɾ���ڵ���
	typedef Gamevoid (*DestroyOcclusionVolumeFunction)(Gamevoid* pOcclusionVolumeHandle);

	//! \brief ���ð�Χ��
	typedef Gamevoid (*SetOVBoundingBoxFunction)(Gamevoid* pOcclusionVolumeHandle, Gamevoid* pBoundBox);

	//! \brief �����ڵ���
	Gamevoid* CreateOcclusionVolume(Gamelong strIDName);

	//! \brief ɾ���ڵ���
	Gamevoid DestroyOcclusionVolume(Gamevoid* pOcclusionVolumeHandle);

	//! \brief ���ð�Χ��
	Gamevoid SetOVBoundingBox(Gamevoid* pOcclusionVolumeHandle, Gamevoid* pBoundBox);

	class GameOcclusionVolume
	{
	public:
		GameOcclusionVolume(Gamelong nIDName, USuperMap_OcclusionVolumeComponent* pComponent);
		~GameOcclusionVolume();
	public:
		//! \brief ��ʼ���ص�����
		static void InitializeCallbackHandle();

		//! \brief ��ȡID��
		Gamelong GetIDName();

		//! \brief ���ð�Χ��
		void SetBBox(FBox & box);

	private:
		//! \brief �ڵ��������
		Gamelong m_nIDName;

		//! \brief ��Ⱦ�ڵ�
		USuperMap_OcclusionVolumeComponent* m_pOcclusionVolumeComponent;
	};
}