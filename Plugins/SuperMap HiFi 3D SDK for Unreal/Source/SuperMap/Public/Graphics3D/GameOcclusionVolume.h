#pragma once
#include "Base3D/CommonDefine.h"
#include "Component/SuperMap_OcclusionVolumeComponent.h"
namespace SuperMapSDK
{

	//! \brief 创建遮挡体 
	typedef Gamevoid* (*CreateOcclusionVolumeFunction)(Gamelong strIDName);

	//! \brief 删除遮挡体
	typedef Gamevoid (*DestroyOcclusionVolumeFunction)(Gamevoid* pOcclusionVolumeHandle);

	//! \brief 设置包围盒
	typedef Gamevoid (*SetOVBoundingBoxFunction)(Gamevoid* pOcclusionVolumeHandle, Gamevoid* pBoundBox);

	//! \brief 创建遮挡体
	Gamevoid* CreateOcclusionVolume(Gamelong strIDName);

	//! \brief 删除遮挡体
	Gamevoid DestroyOcclusionVolume(Gamevoid* pOcclusionVolumeHandle);

	//! \brief 设置包围盒
	Gamevoid SetOVBoundingBox(Gamevoid* pOcclusionVolumeHandle, Gamevoid* pBoundBox);

	class GameOcclusionVolume
	{
	public:
		GameOcclusionVolume(Gamelong nIDName, USuperMap_OcclusionVolumeComponent* pComponent);
		~GameOcclusionVolume();
	public:
		//! \brief 初始化回掉函数
		static void InitializeCallbackHandle();

		//! \brief 获取ID名
		Gamelong GetIDName();

		//! \brief 设置包围盒
		void SetBBox(FBox & box);

	private:
		//! \brief 遮挡体的名字
		Gamelong m_nIDName;

		//! \brief 渲染节点
		USuperMap_OcclusionVolumeComponent* m_pOcclusionVolumeComponent;
	};
}