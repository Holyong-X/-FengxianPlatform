// Fill out your copyright notice in the Description page of Project Settings.


#include "Toolkit/SuperMap_DetailsViewInfos.h"
#include "Graphics3D/GameMaterialManager.h"
#include "Core/Layer3D.h"
#include "Core/Layer3DS3MFile.h"
#include "Graphics3D/GameObjectManager.h"
#include "ControlUE/RealspaceView.h"

PRAGMA_DISABLE_OPTIMIZATION
ASuperMap_DetailsViewInfos::ASuperMap_DetailsViewInfos()
{
	m_ReplaceMaterial = nullptr;
	m_ReplaceLayerMaterial = nullptr;
	m_ReplaceStaticMesh = nullptr;
	m_ExcavationSideMaterial = nullptr;
	m_ExcavationTopMaterial = nullptr;
}

void ASuperMap_DetailsViewInfos::SetMaterialUVTiling(FString LayerName, FString OriMaterialName, FVector4 UVOffsetAndScale)
{
	if (m_ReplaceMaterial != nullptr)
	{
		Layer3D* pLayer = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(FName(LayerName));
		if (pLayer != nullptr)
		{
			ObjectMaterialInfo& materialInfos = pLayer->GetObjectMaterialInfo();
			TMap<FString, AssociateMaterialInfo> AssociateMaterialInfos = materialInfos.m_mapMaterialNameChanges;
			if (pLayer->Type() == Layer3DType::S3M)
			{
				//材质替换分割“_”确定前部名称
				Gameint nIndex = 0;
				if (OriMaterialName.FindLastChar(TCHAR('_'), nIndex))
				{
					Gameint nStrCount = OriMaterialName.Len() - nIndex;
					OriMaterialName.RemoveAt(nIndex, nStrCount);
				}
			}

			TMap<Gamelong, GameComponent*>& allGameComponent = pLayer->GetAllNativeGameComponent();
			for (TMap<Gamelong, GameComponent*>::TConstIterator It = allGameComponent.CreateConstIterator(); It; ++It)
			{
				TArray<GameMaterial*>& listGameMaterial = It->Value->GetAllGameMaterial();
				for (Gameint i = 0; i < listGameMaterial.Num(); i++)
				{
					GameMaterial* pGameMaterial = listGameMaterial[i];
					if (pGameMaterial == nullptr)
					{
						continue;
					}
					FString strMaterialOriginName = pGameMaterial->GetMaterialOrginName();
					Gameint nIndex1 = 0;
					if (strMaterialOriginName.FindLastChar(TCHAR('_'), nIndex1))
					{
						Gameint nStrCount = strMaterialOriginName.Len() - nIndex1;
						strMaterialOriginName.RemoveAt(nIndex1, nStrCount);
					}
					if (strMaterialOriginName.Compare(OriMaterialName) == 0)
					{
						UMaterialInstanceDynamic* pMat = pGameMaterial->GetMID();

						FLinearColor newUV = FLinearColor(UVOffsetAndScale);
						if (AssociateMaterialInfos.Find(OriMaterialName))
						{
							AssociateMaterialInfo info = AssociateMaterialInfos[OriMaterialName];
							newUV = newUV * info.MaterialOriginalUVTiling;
							pMat->SetVectorParameterValue(DEAFAULT_UV_OFFSET_AND_SCALE, newUV);
						}
					}
				}
			}

			if (AssociateMaterialInfos.Find(OriMaterialName))
			{
				AssociateMaterialInfo info = AssociateMaterialInfos[OriMaterialName];
				info.AssociateMaterialUVTiling = FLinearColor(UVOffsetAndScale);
				AssociateMaterialInfos.Add(OriMaterialName, info);
				materialInfos.m_mapMaterialNameChanges = AssociateMaterialInfos;
			}
		}
	}
}
PRAGMA_ENABLE_OPTIMIZATION