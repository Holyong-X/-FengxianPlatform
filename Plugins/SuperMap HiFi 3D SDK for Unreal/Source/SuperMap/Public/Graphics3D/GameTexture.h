#pragma once

#include "CoreMinimal.h"
#include "Base3D/CommonDefine.h"
#include "Core/RealspaceDLL.h"

class UTexture2D;
namespace SuperMapSDK
{
	//! \brief 创建纹理
	typedef void*(*CreateTextureFunction)(Gamelong nTextureHandle, Gameint width, Gameint height, Gameuint nSizeInByte, Gameuchar*& pByte, Gameint nFormat, 
		Gameint nCompressType, Gamebool bCanReleased, Gamebool bSRGB);

	//! \brief 销毁纹理
	typedef void(*DestroyTextureFunction)(void* pTextureHandle);

	//! \brief 更新纹理
	typedef void(*UpdateTextureFunction)(void* pTextureHandle,
		Gameint nOffsetX, Gameint nOffsetY, Gameint nWidth,
		Gameint nHeight, Gameuint nSizeInByte, Gameuchar* pByte,
		Gameint nFormat, Gameint nCompressType, Gamebool bCanReleased);

	//! \brief 纹理是否已上传显卡
	typedef Gamebool (*IsInitialGPUFunction)(void* pTextureHandle);

	//! \brief 创建实体对象
	void* CreateTexture(Gamelong nTextureHandle, Gameint nWidth, Gameint nHeight, Gameuint nSizeInByte, Gameuchar*& pByte, Gameint nFormat,
		Gameint nCompressType, Gamebool bCanReleased, Gamebool bSRGB);

	//! \brief 销毁纹理
	void DestroyTexture(void* pTextureHandle);

	//! \brief 更新纹理
	void UpdateTexture(void* pTextureHandle, Gameint nOffsetX, Gameint nOffsetY, Gameint width, Gameint height, 
		Gameuint nSizeInByte, Gameuchar* pByte, Gameint nFormat, Gameint nCompressType, Gamebool bCanReleased);

	//! \brief 获取纹理是否已上传显卡
	Gamebool IsInitialGPU(void* pTextureHandle);

	class SUPERMAP_API GameTexture
	{
	public:
		GameTexture();
		~GameTexture();
	public:
		//! \brief 初始化回掉函数
		static void InitializeCallbackHandle();

		//! \brief 设置UE纹理对象
		void SetTexture2D(UTexture2D* pTexture2D);

		//! \brief 获取UE纹理对象
		UTexture2D* GetTexture2D();

		//! \brief 设置纹理的名字
		void SetTexHashCodeName(Gamelong nHashCodeName);

		//! \brief 获取纹理的名字
		Gamelong GetTexHashCodeName();

		//! \brief 修改纹理是否上传显卡
		void SetInitialGPU(Gamebool bInitial);

		Gamebool GetInitialGPU();

		//! \brief 是否纹理已上传显卡
		Gamebool GetInitialAndUpdateGPU();

		//! \brief 设置/获取纹理宽度
		void SetWidth(Gameint nWidth);
		Gameint GetWidth();

		//! \brief 设置/获取纹理高度
		void SetHeight(Gameint nHeight);
		Gameint GetHeight();

		//! \brief 设置Update
		void AddUpdate();
		void RemoveUpdate();

		//! \brief 设置/获取纹理格式
		void SetPixelFormat(EPixelFormat ePixelFormat);
		EPixelFormat GetPixelFormat();

		//! \brief 设置/获取Mipmap个数
		void SetMipmapCount(Gameint nMipmap);
		Gameint GetMipmapCount();
	private:

		//! \biref UE的纹理对象
		UTexture2D* m_pTexture2D;

		//! \brief 纹理的名字
		Gamelong m_nHashCodeName;

		//! \brief 是否已经填完显卡
		Gamebool m_bInitialGPU;

		//! \brief 是否更新
		Gameint m_nUpdate1;
		Gameint m_nUpdate2;

		//! \brief 纹理宽度
		Gameint m_nWidth;

		//! \brief 纹理高度
		Gameint m_nHeight;

		//! \brief 纹理类型
		EPixelFormat m_ePixelFormat;

		//! \brief Mipmap层数
		Gameint m_nMipmap;
	};
}