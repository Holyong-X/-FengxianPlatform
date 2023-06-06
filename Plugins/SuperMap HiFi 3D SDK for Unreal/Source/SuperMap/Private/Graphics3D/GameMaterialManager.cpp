#include "Graphics3D/GameMaterialManager.h"
#include "Base3D/StatsGroupDefine.h"
#include "Materials/MaterialParameterCollection.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Kismet/KismetMaterialLibrary.h"
#include "Data/Matrix4d.h"
#include "Algorithm3D/MathEngine.h"
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif
using namespace SuperMapSDK;
using namespace SuperMapSDK::UnrealEngine::Core;
using namespace SuperMapSDK::UnrealEngine::Data;
using namespace SuperMapSDK::UnrealEngine::Algorithm3D;
namespace SuperMapSDK
{
	GameMaterialManager* GameMaterialManager::m_pGameMaterialManager = NULL;

	GameMaterialManager::GameMaterialManager()
	{
		m_bCreateMaterialInViewport    = false;
		m_pMaterialParameterCollection = LoadObject<UMaterialParameterCollection>(nullptr, *GPU_SHARED_PARAM);
		if (m_pMaterialParameterCollection != nullptr)
		{
			m_pMaterialParameterCollection->AddToRoot();
		}
		
	}

	GameMaterialManager::~GameMaterialManager()
	{
		for (TMap<Gamelong, GameMaterial*>::TConstIterator It = m_mapGameMaterials.CreateConstIterator(); It; ++It)
		{
			delete It->Value;
		}

		m_mapGameMaterials.Empty();
		if (m_pMaterialParameterCollection != nullptr)
		{
			m_pMaterialParameterCollection->RemoveFromRoot();
			m_pMaterialParameterCollection = nullptr;
		}
	}

	GameMaterialManager* GameMaterialManager::GetSingleton()
	{
		if (m_pGameMaterialManager == nullptr)
		{
			m_pGameMaterialManager = new GameMaterialManager();
		}

		return m_pGameMaterialManager;
	}

	Gamevoid GameMaterialManager::DestorySingleton()
	{
		if (m_pGameMaterialManager != nullptr)
		{
			delete m_pGameMaterialManager;
			m_pGameMaterialManager = nullptr;
		}
	}

	Gamevoid GameMaterialManager::InitializeCallbackHandle()
	{
		GetMaterialFunction			   getMaterial = GetMaterial;
		CreateMaterialFunction         createMaterial = CreateMaterial;
		RemoveMaterialFunction         removeMaterial = RemoveMaterial;
		FillMaterialFunction	       fillMaterial = FillMaterial;
		FillTechniqueFunction          fillTechniqueFunction = FillTechnique;
		SetMaterialIntParamFunction    setMaterialIntParam = SetMaterialIntParam;
		SetMaterialFloatParamFunction  setMaterialFloatParam = SetMaterialfloatParam;
		SetMaterialVector3dParamFunction setMaterialVector3dParam = SetMaterialVector3dParam;
		SetMaterialVector4dParamFunction setMaterialVector4dParam = SetMaterialVector4dParam;
		SetMaterialMatrix4dParamFunction setMaterialMatrix4dParam = SetMaterialMatrix4dParam;
		SetMaterialTextureParamFunction  setMaterialTextureParam = SetMaterialTextureParam;

		SetMaterialIntShareParamFunction setMaterialIntShareParam           = SetMaterialIntShareParam;
		SetMaterialFloatShareParamFunction setMaterialFloatShareParam       = SetMaterialFloatShareParam;
		SetMaterialVector3dShareParamFunction setMaterialVector3dShareParam = SetMaterialVector3dShareParam;
		SetMaterialVector4dShareParamFunction setMaterialVector4dShareParam = SetMaterialVector4dShareParam;
		SetMaterialMatrix4dShareParamFunction setMaterialMatrix4dShareParam = SetMaterialMatrix4dShareParam;

		if (_InitMaterialManagerCallbackHandle != nullptr)
		{
			_InitMaterialManagerCallbackHandle((Gamevoid*)getMaterial, (Gamevoid*)createMaterial, (Gamevoid*)removeMaterial, (Gamevoid*)fillMaterial, (Gamevoid*)fillTechniqueFunction,
				(Gamevoid*)setMaterialIntParam, (Gamevoid*)setMaterialFloatParam, (Gamevoid*)setMaterialVector3dParam, (Gamevoid*)setMaterialVector4dParam,
				(Gamevoid*)setMaterialMatrix4dParam, (Gamevoid*)setMaterialTextureParam);
		
			_InitMaterialManagerShareCallbackHandle((Gamevoid*)setMaterialIntShareParam, (Gamevoid*)setMaterialFloatShareParam,
				(Gamevoid*)setMaterialVector3dShareParam, (Gamevoid*)setMaterialVector4dShareParam, (Gamevoid*)setMaterialMatrix4dShareParam);
		}

	}

	Gamevoid* GameMaterialManager::CreateGameMaterial(GameMaterialParam* pMaterialParam)
	{
		if (pMaterialParam == nullptr)
		{
			return nullptr;
		}

		GameMaterial* pMaterial = new GameMaterial(pMaterialParam);
		Gamelong nMaterialHandle = pMaterialParam->m_nMaterialName;
		m_mapGameMaterials.Add(nMaterialHandle, pMaterial);
		return (Gamevoid*)pMaterial;
	}

	GameMaterial* GameMaterialManager::GetGameMaterial(Gamelong nMaterialHandle)
	{
		Gamebool bHas = m_mapGameMaterials.Contains(nMaterialHandle);
		if (bHas)
		{
			return m_mapGameMaterials[nMaterialHandle];
		}

		return nullptr;
	}

	Gamevoid GameMaterialManager::SetWorld(UWorld* pWorld)
	{
		m_pWorld = pWorld;
	}

	TMap<Gamelong, GameMaterial*> GameMaterialManager::GetAllGameMaterial()
	{
		return m_mapGameMaterials;
	}

	Gamebool GameMaterialManager::FillGameMaterial(Gamevoid* pMaterialHandle, GameMaterialParam* pMaterialParam)
	{
		GameMaterial* pGameMaterial = (GameMaterial*)pMaterialHandle;
		if (pGameMaterial != nullptr)
		{
			pGameMaterial->UpdateMaterial(pMaterialParam);
			return true;
		}

		return false;
	}

	Gamebool GameMaterialManager::FillRectSelectMaterial(Gamevoid* pMaterialHandle, GameMaterialParam* pMaterialParam)
	{
		GameMaterial* pGameMaterial = (GameMaterial*)pMaterialHandle;
		if (pGameMaterial != nullptr)
		{
			pGameMaterial->UpdateRectMaterial(pMaterialParam);
			return true;
		}

		return false;
	}

	Gamevoid GameMaterialManager::RemoveGameMaterial(Gamevoid* pMaterialHandle)
	{
		GameMaterial* pMaterial = (GameMaterial*)pMaterialHandle;
		Gamelong nMaterialHandle = pMaterial->GetMaterialParam()->m_nMaterialName;
		delete pMaterial;
		pMaterial = nullptr;

		m_mapGameMaterials.Remove(nMaterialHandle);
	}

	Gamevoid GameMaterialManager::SetIsCreateMaterialInViewport(Gamebool bCreateScreenMaterial)
	{
		m_bCreateMaterialInViewport = bCreateScreenMaterial;
	}

	Gamebool GameMaterialManager::GetIsCreateMaterialInViewport()
	{
		return m_bCreateMaterialInViewport;
	}

	Gamevoid GameMaterialManager::SetMatIntShareParam(Gamechar* strParamName, Gameint nValue)
	{
		if (m_pMaterialParameterCollection)
		{
			if (m_pMaterialParameterCollection->GetScalarParameterByName(strParamName) == nullptr)
			{
				return;
			}
			UKismetMaterialLibrary::SetScalarParameterValue(m_pWorld, m_pMaterialParameterCollection, strParamName, nValue);
		}
		
	}
	Gamevoid GameMaterialManager::SetMatFloatShareParam(Gamechar* strParamName, Gamefloat fValue)
	{
		if (m_pMaterialParameterCollection)
		{
			if (m_pMaterialParameterCollection->GetScalarParameterByName(strParamName) == nullptr)
			{
				return;
			}
			UKismetMaterialLibrary::SetScalarParameterValue(m_pWorld, m_pMaterialParameterCollection, strParamName, fValue);
		}
	}

	Gamevoid GameMaterialManager::SetMatFloatShareParam(FName strParamName, Gamefloat fValue)
	{
		if (m_pMaterialParameterCollection)
		{
			UKismetMaterialLibrary::SetScalarParameterValue(m_pWorld, m_pMaterialParameterCollection, strParamName, fValue);
		}
	}

	Gamevoid GameMaterialManager::SetMatVector4dShareParam(FName strParamName, FLinearColor v)
	{
		if (m_pMaterialParameterCollection)
		{
			UKismetMaterialLibrary::SetVectorParameterValue(m_pWorld, m_pMaterialParameterCollection, strParamName, v);
		}
	}

	Gamevoid GameMaterialManager::SetMatVector3dShareParam(Gamechar* strParamName, GameVec3d vValue3d)
	{
		if (m_pMaterialParameterCollection)
		{
			if (m_pMaterialParameterCollection->GetVectorParameterByName(strParamName) == nullptr)
			{
				return;
			}
			FLinearColor cValue = FLinearColor(vValue3d.x, vValue3d.y, vValue3d.z, 1.0);
			UKismetMaterialLibrary::SetVectorParameterValue(m_pWorld, m_pMaterialParameterCollection, strParamName, cValue);
		}
	}

	Gamevoid GameMaterialManager::SetGPUMatrixShareParam(Matrix4d mat, FString strParamaName)
	{
		FString strMatX = strParamaName + TEXT("X");
		FString strMatY = strParamaName + TEXT("Y");
		FString strMatZ = strParamaName + TEXT("Z");
		FString strMatW = strParamaName + TEXT("W");

		FLinearColor vColorX = FLinearColor(mat[0][0], mat[0][1], mat[0][2], mat[0][3]);
		FLinearColor vColorY = FLinearColor(mat[1][0], mat[1][1], mat[1][2], mat[1][3]);
		FLinearColor vColorZ = FLinearColor(mat[2][0], mat[2][1], mat[2][2], mat[2][3]);
		FLinearColor vColorW = FLinearColor(mat[3][0], mat[3][1], mat[3][2], mat[3][3]);

		UKismetMaterialLibrary::SetVectorParameterValue(m_pWorld, m_pMaterialParameterCollection, FName(strMatX), vColorX);
		UKismetMaterialLibrary::SetVectorParameterValue(m_pWorld, m_pMaterialParameterCollection, FName(strMatY), vColorY);
		UKismetMaterialLibrary::SetVectorParameterValue(m_pWorld, m_pMaterialParameterCollection, FName(strMatZ), vColorZ);
		UKismetMaterialLibrary::SetVectorParameterValue(m_pWorld, m_pMaterialParameterCollection, FName(strMatW), vColorW);

	}

	Gamevoid GameMaterialManager::SetMatVector4dShareParam(Gamechar* strParamName, GameVec4d vValue4d)
	{
		if (m_pMaterialParameterCollection)
		{
			
			FString strParam = UTF8_TO_TCHAR(strParamName);
			if (strParam.Compare("SQDepthProjMatrix") == 0)
			{
				// 设置由底层UGC的相机参数计算UE的投影的矩阵
				FString strMatX = strParam + TEXT("X");
				if (m_pMaterialParameterCollection->GetVectorParameterByName(FName(strMatX)) == nullptr)
				{
					return;
				}
				Gamedouble dFov = vValue4d.x * 0.5;
				Gamedouble dAspect = vValue4d.y;
				Gamedouble dNear = vValue4d.z * M_TO_CM;
				Gamedouble dFar = vValue4d.w * M_TO_CM;

				FReversedZPerspectiveMatrix ueProjMatrix(dFov, dAspect, 1.0, dNear, dFar);
				Matrix4d mat(ueProjMatrix);
				
				SetGPUMatrixShareParam(mat, strParam);
				return;
			}

			if (m_pMaterialParameterCollection->GetVectorParameterByName(strParamName) == nullptr)
			{
				return;
			}
			FLinearColor cValue = FLinearColor(vValue4d.x, vValue4d.y, vValue4d.z, vValue4d.w);
			if (strParam.Compare("ImageScissorBox") == 0)
			{
				cValue.R = (vValue4d.x + 1) / 2;
				cValue.G = (1 - vValue4d.w) / 2;
				cValue.B = (vValue4d.z + 1) / 2;
				cValue.A = (1 - vValue4d.y) / 2;
			}
			UKismetMaterialLibrary::SetVectorParameterValue(m_pWorld, m_pMaterialParameterCollection, strParamName, cValue);
		}
	}
	Gamevoid GameMaterialManager::SetMatMatrix4dShareParam(Gamechar* strParamName, Gamevoid* pValue)
	{
		if (m_pMaterialParameterCollection)
		{
			FString strParam = UTF8_TO_TCHAR(strParamName);
			FString strMatX = strParam + TEXT("X");

			if (m_pMaterialParameterCollection->GetVectorParameterByName(FName(strMatX)) == nullptr)
			{
				return;
			}

			Gamedouble* pDobleValue = (Gamedouble*)pValue;
			Matrix4d mat(pDobleValue);
			if (strParam.Compare("SQDepthViewMatrix") == 0)
			{
				// UGC TO UE
				Matrix4d matUGCView(pDobleValue);
				MathEngine::UGCViewMatrixToUEViewMatrix(matUGCView, mat);
			}

			SetGPUMatrixShareParam(mat, strParam);
		}
	}



	Gamevoid* GetMaterial(Gamelong nMaterialHandle)
	{
		return GameMaterialManager::GetSingleton()->GetGameMaterial(nMaterialHandle);
	}

	Gamevoid* CreateMaterial(GameMaterialParam* pMaterialParam)
	{
		STATS_SM_CREATMATERIAL

		return GameMaterialManager::GetSingleton()->CreateGameMaterial(pMaterialParam);
	}

	Gamevoid RemoveMaterial(Gamevoid* pMaterialHandle)
	{
		STATS_SM_REMOVEMATERIAL

		GameMaterialManager::GetSingleton()->RemoveGameMaterial(pMaterialHandle);
	}


	Gamebool FillMaterial(Gamevoid* pMaterialHandle, Gamevoid* pMaterialParam)
	{
		STATS_SM_FILLMATERIAL

		GameMaterialParam* pNewMaterialParam = (GameMaterialParam*)pMaterialParam;
		return GameMaterialManager::GetSingleton()->FillGameMaterial(pMaterialHandle, pNewMaterialParam);
	}

	Gamevoid SetMaterialIntParam(Gamevoid* pMaterialHandle, Gamechar* strParamName, Gameint nValue)
	{
		STATS_SM_SETMATERIALPARAM_INT

		GameMaterial* pMaterial = (GameMaterial*)pMaterialHandle;
		if (pMaterial != nullptr)
		{
			pMaterial->SetMaterialIntParam(strParamName, nValue);
		}
		return;
	}

	Gamevoid SetMaterialfloatParam(Gamevoid* pMaterialHandle, Gamechar* strParamName, Gamefloat nValue)
	{
		STATS_SM_SETMATERIALPARAM_FLOAT

		GameMaterial* pMaterial = (GameMaterial*)pMaterialHandle;
		if (pMaterial != nullptr)
		{
			pMaterial->SetMaterialfloatParam(strParamName, nValue);
		}
		return;
	}

	Gamevoid SetMaterialVector3dParam(Gamevoid* pMaterialHandle, Gamechar* strParamName, GameVec3d vValue3d)
	{
		STATS_SM_SETMATERIALPARAM_VECTOR3D
	}

	Gamevoid SetMaterialVector4dParam(Gamevoid* pMaterialHandle, Gamechar* strParamName, GameVec4d vValue4d)
	{
		STATS_SM_SETMATERIALPARAM_VECTOR4D

		GameMaterial* pMaterial = (GameMaterial*)pMaterialHandle;
		FString strParam = UTF8_TO_TCHAR(strParamName);
		if (pMaterial != nullptr)
		{
			if (strParam.Compare("ImageScissorBox") == 0)
			{
				GameMaterialManager::GetSingleton()->SetMatVector4dShareParam(strParamName, vValue4d);
			}
			else
			{
				pMaterial->SetMaterialVector4dParam(strParamName, vValue4d);
			}
		}
	}

	Gamevoid SetMaterialMatrix4dParam(Gamevoid* pMaterialHandle, Gamechar* strParamName, Gamevoid* pValue)
	{
		STATS_SM_SETMATERIALPARAM_MATRIX4D

		GameMaterial* pMaterial = (GameMaterial*)pMaterialHandle;
		if (pMaterial != nullptr)
		{
			pMaterial->SetMaterialMatrix4dParam(strParamName, pValue);
		}
	}

	Gamevoid SetMaterialTextureParam(Gamevoid* pMaterialHandle, Gamechar* strParamName, Gameint nTexIndex, Gamechar* strTechniqueName)
	{
		STATS_SM_SETMATERIALPARAM_TEXTURE

		GameMaterial* pMaterial = (GameMaterial*)pMaterialHandle;
		if (pMaterial != nullptr)
		{
			pMaterial->SetMaterialTextureParam(strParamName, nTexIndex);
		}
		return;
	}

	Gamebool FillTechnique(Gamevoid* pMaterialHandle, Gamechar* strTechnique, Gamevoid* pMaterialParam)
	{
		STATS_SM_FILLTECHNIQUE

		FString strTName = UTF8_TO_TCHAR(strTechnique);
		if(strTName.Compare(TEXT("SpatialQueryID")) == 0)
		{
			GameMaterialParam* pNewMaterialParam = (GameMaterialParam*)pMaterialParam;
			return GameMaterialManager::GetSingleton()->FillRectSelectMaterial(pMaterialHandle, pNewMaterialParam);
		}

		return true;
	}

	Gamevoid SetMaterialIntShareParam(Gamechar* strParamName, Gameint nValue)
	{
		GameMaterialManager::GetSingleton()->SetMatIntShareParam(strParamName, nValue);
	}

	Gamevoid SetMaterialFloatShareParam(Gamechar* strParamName, Gamefloat fValue)
	{
		GameMaterialManager::GetSingleton()->SetMatFloatShareParam(strParamName, fValue);
	}

	Gamevoid SetMaterialVector3dShareParam(Gamechar* strParamName, GameVec3d vValue3d)
	{
		GameMaterialManager::GetSingleton()->SetMatVector3dShareParam(strParamName, vValue3d);
	}

	Gamevoid SetMaterialVector4dShareParam(Gamechar* strParamName, GameVec4d vValue4d)
	{
		GameMaterialManager::GetSingleton()->SetMatVector4dShareParam(strParamName, vValue4d);
	}

	Gamevoid SetMaterialMatrix4dShareParam(Gamechar* strParamName, Gamevoid* pValue)
	{
		GameMaterialManager::GetSingleton()->SetMatMatrix4dShareParam(strParamName, pValue);
	}
}
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif