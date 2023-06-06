#pragma once

#include "CoreMinimal.h"
#include "Base3D/CommonDefine.h"
#include "Core/RealspaceDLL.h"

class UTexture2D;
namespace SuperMapSDK
{
	//! \brief ��������
	typedef void*(*CreateTextureFunction)(Gamelong nTextureHandle, Gameint width, Gameint height, Gameuint nSizeInByte, Gameuchar*& pByte, Gameint nFormat, 
		Gameint nCompressType, Gamebool bCanReleased, Gamebool bSRGB);

	//! \brief ��������
	typedef void(*DestroyTextureFunction)(void* pTextureHandle);

	//! \brief ��������
	typedef void(*UpdateTextureFunction)(void* pTextureHandle,
		Gameint nOffsetX, Gameint nOffsetY, Gameint nWidth,
		Gameint nHeight, Gameuint nSizeInByte, Gameuchar* pByte,
		Gameint nFormat, Gameint nCompressType, Gamebool bCanReleased);

	//! \brief �����Ƿ����ϴ��Կ�
	typedef Gamebool (*IsInitialGPUFunction)(void* pTextureHandle);

	//! \brief ����ʵ�����
	void* CreateTexture(Gamelong nTextureHandle, Gameint nWidth, Gameint nHeight, Gameuint nSizeInByte, Gameuchar*& pByte, Gameint nFormat,
		Gameint nCompressType, Gamebool bCanReleased, Gamebool bSRGB);

	//! \brief ��������
	void DestroyTexture(void* pTextureHandle);

	//! \brief ��������
	void UpdateTexture(void* pTextureHandle, Gameint nOffsetX, Gameint nOffsetY, Gameint width, Gameint height, 
		Gameuint nSizeInByte, Gameuchar* pByte, Gameint nFormat, Gameint nCompressType, Gamebool bCanReleased);

	//! \brief ��ȡ�����Ƿ����ϴ��Կ�
	Gamebool IsInitialGPU(void* pTextureHandle);

	class SUPERMAP_API GameTexture
	{
	public:
		GameTexture();
		~GameTexture();
	public:
		//! \brief ��ʼ���ص�����
		static void InitializeCallbackHandle();

		//! \brief ����UE�������
		void SetTexture2D(UTexture2D* pTexture2D);

		//! \brief ��ȡUE�������
		UTexture2D* GetTexture2D();

		//! \brief �������������
		void SetTexHashCodeName(Gamelong nHashCodeName);

		//! \brief ��ȡ���������
		Gamelong GetTexHashCodeName();

		//! \brief �޸������Ƿ��ϴ��Կ�
		void SetInitialGPU(Gamebool bInitial);

		Gamebool GetInitialGPU();

		//! \brief �Ƿ��������ϴ��Կ�
		Gamebool GetInitialAndUpdateGPU();

		//! \brief ����/��ȡ������
		void SetWidth(Gameint nWidth);
		Gameint GetWidth();

		//! \brief ����/��ȡ����߶�
		void SetHeight(Gameint nHeight);
		Gameint GetHeight();

		//! \brief ����Update
		void AddUpdate();
		void RemoveUpdate();

		//! \brief ����/��ȡ�����ʽ
		void SetPixelFormat(EPixelFormat ePixelFormat);
		EPixelFormat GetPixelFormat();

		//! \brief ����/��ȡMipmap����
		void SetMipmapCount(Gameint nMipmap);
		Gameint GetMipmapCount();
	private:

		//! \biref UE���������
		UTexture2D* m_pTexture2D;

		//! \brief ���������
		Gamelong m_nHashCodeName;

		//! \brief �Ƿ��Ѿ������Կ�
		Gamebool m_bInitialGPU;

		//! \brief �Ƿ����
		Gameint m_nUpdate1;
		Gameint m_nUpdate2;

		//! \brief ������
		Gameint m_nWidth;

		//! \brief ����߶�
		Gameint m_nHeight;

		//! \brief ��������
		EPixelFormat m_ePixelFormat;

		//! \brief Mipmap����
		Gameint m_nMipmap;
	};
}