// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SuperMap_MainActor.h"
#include "ControlUE/RealspaceView.h"
#include "Data/Vector3d.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Base3D/MaterialDefine.h"
#include "SuperMap_ProfileInstance.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FProfileTextureDelegate);

void CallbackFunc_ProfileInstance(void* pActor);

UCLASS()
class SUPERMAPSAMPLES_API ASuperMap_ProfileInstance : public AActor, public FSuperMap_MouseControl
{
	GENERATED_BODY()
	
public:	
	ASuperMap_ProfileInstance();
	~ASuperMap_ProfileInstance();
private:
	void MouseLeftButtonDown();

	void MouseRightButtonDown();

	void MouseRealTimeAnchor();

	void DrawLine(Vector3d vPos);

	void Realse();
public:
	//! \brief �Ƿ��������
	//! \param bclip [in] true��ʼ
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ProfileInstance")
	void BuildProfile(bool bProfile);

	//! \brief ��ȡ�������ͼ
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ProfileInstance")
	UTexture2D* GetImageData();

	//! \brief ��ȡ����ͼ�߶�
	//! \brief XΪ���߶ȣ�YΪ��С�߶�
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ProfileInstance")
	FVector2D GetHeightPosition();

	//! \brief �ص������¼�
	UPROPERTY(BlueprintAssignable)
	FProfileTextureDelegate CallProfileTexture;

	//! \brief ִ�жಥ
	void ExecuteBroadcast();
protected:
	virtual void BeginPlay() override;
public:	
	virtual void Tick(float DeltaTime) override;
private:

	Gamebool m_bProfile;
	//! \brief ��ʼ��
	Vector3d m_vStarPoint;
	//! \brief ��ֹ��
	Vector3d m_vEndPoint;
	//! \brief ʵʱ������
	ASuperMap_ROEntityActor* m_pROEntityActor;
	//! \brief ���Ƶ�
	Vector3d m_DrawFlatStartPoint;

	Vector3d m_DrawFlatEndPoint;

	Vector3d a;

	Vector3d b;

	Gameint m_nMouseLeftDown;

	FName m_strAnalyst3DName;
};
