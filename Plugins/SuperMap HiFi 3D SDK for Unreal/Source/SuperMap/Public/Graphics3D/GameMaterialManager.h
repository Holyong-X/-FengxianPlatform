#pragma once

#include "CoreMinimal.h"
#include "Base3D/CommonDefine.h"
#include "Base3D/MaterialDefine.h"
#include "Graphics3D/GameStruct.h"
#include "Graphics3D/GameMaterial.h"
#include "Core/RealspaceDLL.h"
#include "Engine/World.h"
#include "Data/Matrix4d.h"

using namespace SuperMapSDK::UnrealEngine::Data;

class UMaterialParameterCollection;

namespace SuperMapSDK
{
	//! \brief ��������
	typedef Gamevoid*(*CreateMaterialFunction)(GameMaterialParam* pMaterialParam);

	//! \brief ɾ������
	typedef Gamevoid(*RemoveMaterialFunction)(Gamevoid* pMaterialHandle);

	//! \brief ��ȡ����
	typedef Gamevoid*(*GetMaterialFunction)(Gamelong nMaterialHandle);

	//! \brief ������
	typedef Gamebool(*FillMaterialFunction)(Gamevoid* pMaterialHandle, Gamevoid* pMaterialParam);

	//! \brief ���ò��ʲ���
	typedef Gamevoid(*SetMaterialIntParamFunction)(Gamevoid* pMaterialHandle, Gamechar* strParamName, Gameint nValue);
	typedef Gamevoid(*SetMaterialFloatParamFunction)(Gamevoid* pMaterialHandle, Gamechar* strParamName, Gamefloat fValue);
	typedef Gamevoid(*SetMaterialVector3dParamFunction)(Gamevoid* pMaterialHandle, Gamechar* strParamName, GameVec3d pValue);
	typedef Gamevoid(*SetMaterialVector4dParamFunction)(Gamevoid* pMaterialHandle, Gamechar* strParamName, GameVec4d pValue);
	typedef Gamevoid(*SetMaterialMatrix4dParamFunction)(Gamevoid* pMaterialHandle, Gamechar* strParamName, Gamevoid* pValue);
	typedef Gamevoid(*SetMaterialTextureParamFunction)(Gamevoid* pMaterialHandle, Gamechar* strParamName, Gameint nTexIndex, Gamechar* strTechniqueName);
	
	typedef Gamevoid(*SetMaterialIntShareParamFunction)(Gamechar* strParamName, Gameint nValue);
	typedef Gamevoid(*SetMaterialFloatShareParamFunction)(Gamechar* strParamName, Gamefloat fValue);
	typedef Gamevoid(*SetMaterialVector3dShareParamFunction)(Gamechar* strParamName, GameVec3d pValue);
	typedef Gamevoid(*SetMaterialVector4dShareParamFunction)(Gamechar* strParamName, GameVec4d pValue);
	typedef Gamevoid(*SetMaterialMatrix4dShareParamFunction)(Gamechar* strParamName, Gamevoid* pValue);

	//! \brief ���Tech
	typedef Gamebool(*FillTechniqueFunction)(Gamevoid* pMaterialHandle, Gamechar* strTechnique, Gamevoid* pMaterialParam);

	//! \brief ��������
	Gamevoid* CreateMaterial(GameMaterialParam* pMaterialParam);

	//! \brief ��ȡ����
	Gamevoid* GetMaterial(Gamelong nMaterialHandle);

	//! \brief ɾ������
	Gamevoid RemoveMaterial(Gamevoid* pMaterialHandle);

	//! \brief ������
	Gamebool FillMaterial(Gamevoid* pMaterialHandle, Gamevoid* pMaterialParam);

	//! \brief ���ò��ʲ���
	Gamevoid SetMaterialIntParam(Gamevoid* pMaterialHandle, Gamechar* strParamName, Gameint nValue);
	Gamevoid SetMaterialfloatParam(Gamevoid* pMaterialHandle, Gamechar* strParamName, Gamefloat nValue);
	Gamevoid SetMaterialVector3dParam(Gamevoid* pMaterialHandle, Gamechar* strParamName, GameVec3d vValue3d);
	Gamevoid SetMaterialVector4dParam(Gamevoid* pMaterialHandle, Gamechar* strParamName, GameVec4d vValue4d);
	Gamevoid SetMaterialMatrix4dParam(Gamevoid* pMaterialHandle, Gamechar* strParamName, Gamevoid* pValue);
	Gamevoid SetMaterialTextureParam(Gamevoid* pMaterialHandle, Gamechar* strParamName, Gameint nTexIndex,Gamechar* strTechniqueName);

	//! \brief ���ù������
	Gamevoid SetMaterialIntShareParam(Gamechar* strParamName, Gameint nValue);
	Gamevoid SetMaterialFloatShareParam(Gamechar* strParamName, Gamefloat fValue);
	Gamevoid SetMaterialVector3dShareParam(Gamechar* strParamName, GameVec3d vValue3d);
	Gamevoid SetMaterialVector4dShareParam(Gamechar* strParamName, GameVec4d vValue4d);
	Gamevoid SetMaterialMatrix4dShareParam(Gamechar* strParamName, Gamevoid* pValue);


	Gamebool FillTechnique(Gamevoid* pMaterialHandle, Gamechar* strTechnique, Gamevoid* pMaterialParam);

	class SUPERMAP_API GameMaterialManager
	{
	public:
		GameMaterialManager();
		~GameMaterialManager();

	public:
		//! \brief ��ʼ���ص�����
		static Gamevoid InitializeCallbackHandle();

		//! \brief ���ʹ�������
		static GameMaterialManager* GetSingleton();

		//! \brief ���ٵ�����
		static Gamevoid DestorySingleton();

		//! \brief ���ó���
		Gamevoid SetWorld(UWorld* pWorld);

		//! \brief ��������
		Gamevoid* CreateGameMaterial(GameMaterialParam* pMaterialParam);

		//! \brief ɾ������
		Gamevoid RemoveGameMaterial(Gamevoid* pMaterialHandle);

		//! \brief ������
		Gamebool FillGameMaterial(Gamevoid* pMaterialHandle, GameMaterialParam* pMaterialParam);

		//! \brief ����ѡ/�ռ��ѯ����
		Gamebool FillRectSelectMaterial(Gamevoid* pMaterialHandle, GameMaterialParam* pMaterialParam);

		//! \brief ��ȡ����
		GameMaterial* GetGameMaterial(Gamelong nMaterialHandle);

		//! \brief ��ȡ���в���
		TMap<Gamelong, GameMaterial*> GetAllGameMaterial();

		//! \brief �Ƿ񴴽���������
		Gamevoid SetIsCreateMaterialInViewport(Gamebool bCreateScreenMaterial);

		//! \brief �Ƿ񴴽���������
		Gamebool GetIsCreateMaterialInViewport();

		//! \brief ���ù������
		Gamevoid SetMatIntShareParam(Gamechar* strParamName     , Gameint nValue);
		Gamevoid SetMatFloatShareParam(Gamechar* strParamName   , Gamefloat fValue);
		Gamevoid SetMatVector3dShareParam(Gamechar* strParamName, GameVec3d vValue3d);
		Gamevoid SetMatVector4dShareParam(Gamechar* strParamName, GameVec4d vValue4d);
		Gamevoid SetMatMatrix4dShareParam(Gamechar* strParamName, Gamevoid* pValue);

		Gamevoid SetMatFloatShareParam(FName strParamName, Gamefloat fValue);
		Gamevoid SetMatVector4dShareParam(FName strParamName, FLinearColor v);
	private:
		//! \brief ���ù���������
		Gamevoid SetGPUMatrixShareParam(Matrix4d mat, FString strParamaName);
	private:
		static GameMaterialManager* m_pGameMaterialManager;

		//! \brief UE����
		UWorld* m_pWorld;

		//! \brief ����
		TMap<Gamelong, GameMaterial*> m_mapGameMaterials;

		//! \brief �Ƿ����
		Gamebool m_bCreateMaterialInViewport;

		//! \brief �����������
		UMaterialParameterCollection* m_pMaterialParameterCollection;
	};
}