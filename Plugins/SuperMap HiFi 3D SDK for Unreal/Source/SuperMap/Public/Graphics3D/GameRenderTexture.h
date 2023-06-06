#pragma once

#include "CoreMinimal.h"
#include "Base3D/CommonDefine.h"
#include "Graphics3D/GameEnum.h"
#include "Core/RealspaceDLL.h"
#include "Component/CustomRealRasterMesh.h"

namespace SuperMapSDK
{
	class GameCamera;
	class GameComponent;
	class SUPERMAP_API GameRenderTexture
	{
	public:
		GameRenderTexture(Gamelong nTextureName, FString strSceneName, SceneManagerType sceneManagerType, int32 nWidth, int32 nHeight, int32 nFormat);
		~GameRenderTexture();
	public:
		//! \brief ��ȡ��������
		SceneManagerType GetSceneManagerType();

		//! \brief ����Ⱦ������ӵ���Ӧ���͵�renderTexture��
		void AddGameComponent(GameComponent* pGameComponent);

		//! \brief ����Ⱦ�����renderTexture���Ƴ�
		void RemoveGameComponent(GameComponent* pGameComponent);

		//! \brief ��ȡ��������
		void* GetFrameBuffer(int32 nXOffset, int32 nYOffset, int32 nWidth, int32 nHeight, int32& nBufferSize);

		//! \brief ��Ⱦ����
		void UpdateScene();

		//! \brief ��ȡ������
		Gamelong GetHandle();

		//! \brief ��ȡ���������������
		void* GetCameraHandle();

		//! \brief ��ȡ��ȾĿ��
		UTextureRenderTarget2D* GetRenderTarget();

		//! \brief ��ȡ��бģ��ѹƽ������ȾĿ��
		UTextureRenderTarget2D* GetFlattenRenderTarget();

		//! \brief ��ȡ��������
		FString GetSceneName();

		//! \brief �ռ��ѯ��Ⱦ����
		void RenderObjectWithSpatialQuery();
	private:
		// ����Ⱦ������Ķ�����ʵʱդ�񻯵ķ�ʽ���Ƶ���ǰ��������
		void RealtimeRaster();

		void RealtimeRasterFlattenRegion();

		void RealtimeRasterExcavationRegion();

		void RealtimeRasterImage(TArray<CustomRealRasterMesh*> arrRasterMesh, TArray<FVector4> transforms, TArray<Gamelong> textureNames);

		//! \brief ������ȾĿ��
		void CreateRenderTarget(UTextureRenderTarget2D* &pRenderTarget);

		//! \brief ����ͼ���ѡ�����
		void SetShaderParameterForSelection(Gamebool bRenderToSelectionTexture, Gamebool bRenderAlpha);
	private:
		//! \brief ��ȾĿ��
		UTextureRenderTarget2D* m_pFlattenRenderTarget;
		UTextureRenderTarget2D* m_pRenderTarget;
		UTextureRenderTarget2D* m_pAlphaRenderTarget;
		UTextureRenderTarget2D* m_pSelectRenderTarget;
		//! \brief ��Ⱦ�����С
		Gameint m_nWidth;
		Gameint m_nHeight;

		//! \brief ��������
		Gamelong m_nTextureName;

		//! \brief ��������
		FString m_strSceneName;

		//! \brief ��������
		SceneManagerType m_eSceneManagerType;

		//! \brief ͼ����е���Ⱦ����
		TMap<Gamelong, GameComponent*> m_mapGameComponent;

		//! \brief ���е��������
		GameCamera* m_pGameCamera;

		//! \brief ������
		Gamelong m_nHandle;

		//! \brief �����ʽ
		PixelFormat m_nPixelFormat;
	};
}