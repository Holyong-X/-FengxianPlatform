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
	//! \brief 创建材质
	typedef Gamevoid*(*CreateMaterialFunction)(GameMaterialParam* pMaterialParam);

	//! \brief 删除材质
	typedef Gamevoid(*RemoveMaterialFunction)(Gamevoid* pMaterialHandle);

	//! \brief 获取材质
	typedef Gamevoid*(*GetMaterialFunction)(Gamelong nMaterialHandle);

	//! \brief 填充材质
	typedef Gamebool(*FillMaterialFunction)(Gamevoid* pMaterialHandle, Gamevoid* pMaterialParam);

	//! \brief 设置材质参数
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

	//! \brief 填充Tech
	typedef Gamebool(*FillTechniqueFunction)(Gamevoid* pMaterialHandle, Gamechar* strTechnique, Gamevoid* pMaterialParam);

	//! \brief 创建材质
	Gamevoid* CreateMaterial(GameMaterialParam* pMaterialParam);

	//! \brief 获取材质
	Gamevoid* GetMaterial(Gamelong nMaterialHandle);

	//! \brief 删除材质
	Gamevoid RemoveMaterial(Gamevoid* pMaterialHandle);

	//! \brief 填充材质
	Gamebool FillMaterial(Gamevoid* pMaterialHandle, Gamevoid* pMaterialParam);

	//! \brief 设置材质参数
	Gamevoid SetMaterialIntParam(Gamevoid* pMaterialHandle, Gamechar* strParamName, Gameint nValue);
	Gamevoid SetMaterialfloatParam(Gamevoid* pMaterialHandle, Gamechar* strParamName, Gamefloat nValue);
	Gamevoid SetMaterialVector3dParam(Gamevoid* pMaterialHandle, Gamechar* strParamName, GameVec3d vValue3d);
	Gamevoid SetMaterialVector4dParam(Gamevoid* pMaterialHandle, Gamechar* strParamName, GameVec4d vValue4d);
	Gamevoid SetMaterialMatrix4dParam(Gamevoid* pMaterialHandle, Gamechar* strParamName, Gamevoid* pValue);
	Gamevoid SetMaterialTextureParam(Gamevoid* pMaterialHandle, Gamechar* strParamName, Gameint nTexIndex,Gamechar* strTechniqueName);

	//! \brief 设置共享参数
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
		//! \brief 初始化回掉函数
		static Gamevoid InitializeCallbackHandle();

		//! \brief 材质管理单例类
		static GameMaterialManager* GetSingleton();

		//! \brief 销毁单例类
		static Gamevoid DestorySingleton();

		//! \brief 设置场景
		Gamevoid SetWorld(UWorld* pWorld);

		//! \brief 创建材质
		Gamevoid* CreateGameMaterial(GameMaterialParam* pMaterialParam);

		//! \brief 删除材质
		Gamevoid RemoveGameMaterial(Gamevoid* pMaterialHandle);

		//! \brief 填充材质
		Gamebool FillGameMaterial(Gamevoid* pMaterialHandle, GameMaterialParam* pMaterialParam);

		//! \brief 填充框选/空间查询材质
		Gamebool FillRectSelectMaterial(Gamevoid* pMaterialHandle, GameMaterialParam* pMaterialParam);

		//! \brief 获取材质
		GameMaterial* GetGameMaterial(Gamelong nMaterialHandle);

		//! \brief 获取所有材质
		TMap<Gamelong, GameMaterial*> GetAllGameMaterial();

		//! \brief 是否创建分屏材质
		Gamevoid SetIsCreateMaterialInViewport(Gamebool bCreateScreenMaterial);

		//! \brief 是否创建分屏材质
		Gamebool GetIsCreateMaterialInViewport();

		//! \brief 设置共享参数
		Gamevoid SetMatIntShareParam(Gamechar* strParamName     , Gameint nValue);
		Gamevoid SetMatFloatShareParam(Gamechar* strParamName   , Gamefloat fValue);
		Gamevoid SetMatVector3dShareParam(Gamechar* strParamName, GameVec3d vValue3d);
		Gamevoid SetMatVector4dShareParam(Gamechar* strParamName, GameVec4d vValue4d);
		Gamevoid SetMatMatrix4dShareParam(Gamechar* strParamName, Gamevoid* pValue);

		Gamevoid SetMatFloatShareParam(FName strParamName, Gamefloat fValue);
		Gamevoid SetMatVector4dShareParam(FName strParamName, FLinearColor v);
	private:
		//! \brief 设置共享矩阵参数
		Gamevoid SetGPUMatrixShareParam(Matrix4d mat, FString strParamaName);
	private:
		static GameMaterialManager* m_pGameMaterialManager;

		//! \brief UE场景
		UWorld* m_pWorld;

		//! \brief 材质
		TMap<Gamelong, GameMaterial*> m_mapGameMaterials;

		//! \brief 是否分屏
		Gamebool m_bCreateMaterialInViewport;

		//! \brief 创建共享参数
		UMaterialParameterCollection* m_pMaterialParameterCollection;
	};
}