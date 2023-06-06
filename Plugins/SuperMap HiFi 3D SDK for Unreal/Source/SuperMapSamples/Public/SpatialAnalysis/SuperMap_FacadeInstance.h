// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SuperMap_MainActor.h"
#include "Component/SuperMap_ROEntityActor.h"
#include "SpatialAnalyst3D/Facade.h"
#include "Data/Vector3d.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Base3D/MaterialDefine.h"
#include "SuperMap_FacadeInstance.generated.h"

using namespace SuperMapSDK::UnrealEngine::Data;
using namespace SuperMapSDK::UnrealEngine::SpatialAnalyst3D;

UCLASS()
class SUPERMAPSAMPLES_API ASuperMap_FacadeInstance : public AActor, public FSuperMap_MouseControl
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASuperMap_FacadeInstance();
	~ASuperMap_FacadeInstance();

public:

	UFUNCTION(BlueprintCallable, Category = "SuperMap_FacadeInstance")
	void BuildFacade(bool bFacade);

	UFUNCTION(BlueprintCallable, Category = "SuperMap_FacadeInstance")
	void SetVisibleFarDistance(float fFar);

	UFUNCTION(BlueprintCallable, Category = "SuperMap_FacadeInstance")
	void SetResolution(float fResolution);

	UFUNCTION(BlueprintCallable, Category = "SuperMap_FacadeInstance")
	void SetVisibleHeight(float fMin, float fMax);

	UFUNCTION(BlueprintCallable, Category = "SuperMap_FacadeInstance")
	void SetOutputPath(FString strOutputPath);

	UFUNCTION(BlueprintCallable, Category = "SuperMap_FacadeInstance")
	void CreateFacade();
private:
	void DrawLine(Vector3d vPos);

	void Realse();

	void CreateFileName(FString& strOutputPath);

	void DrawFace();
private:
	//! \brief �Ƿ���������ͼ
	Gamebool m_bFacade;
	//! \brief ��ʼ��
	Vector3d m_vStarPoint;
	//! \brief ��ֹ��
	Vector3d m_vEndPoint;
	//! \brief ʵʱ������
	ASuperMap_ROEntityActor* m_pROEntityActor;
	//! \brief ����ͼָ��
	Facade* m_pFacade;

	Gameint m_nMouseLeftDown;

	FName m_strAnalyst3DName;
	//! \brief ���Ƶ�
	Vector3d m_DrawFlatStartPoint;

	Vector3d m_DrawFlatEndPoint;

	Gamefloat m_minVisibleHeight;
	Gamefloat m_maxVisibleHeight;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	void MouseLeftButtonDown();

	void MouseRightButtonDown();

	void MouseRealTimeAnchor();
};
