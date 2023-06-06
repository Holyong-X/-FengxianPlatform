// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/TextRenderComponent.h"
#include "ControlUE/CameraControl.h"
#include "ControlUE/RealspaceView.h"
#include "Base3D/CommonDefine.h"
#include "SuperMap_TextActor.generated.h"


using namespace SuperMapSDK::UnrealEngine::ControlUE;


UCLASS()
class SUPERMAP_API ASuperMap_TextActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASuperMap_TextActor();

	Gamevoid SetParam(FVector Location, Gamefloat WorldSize, FColor Color, FText Text);

	Gamevoid UpdateWorldOrigin();
protected:
	// Called when the game starts or when spawned
	virtual Gamevoid BeginPlay() override;

public:	
	// Called every frame
	virtual Gamevoid Tick(Gamefloat DeltaTime) override;

	//! \brief UE�������
	UTextRenderComponent* m_TextRender;

	//! \brief Textλ��
	FVector m_vLocation;

	//! \brief ��¼Textԭʼλ��
	FVector m_vPriLocation;

	//! \brief Text�����С
	Gamefloat m_WorldSize;

	//! \brief Text��ɫ
	FColor m_Color;

	//! \brief Text����
	FText m_Text;

	//! \brief �ж��Ƿ����SetParam()����
	Gamebool m_bSetParam;

};
