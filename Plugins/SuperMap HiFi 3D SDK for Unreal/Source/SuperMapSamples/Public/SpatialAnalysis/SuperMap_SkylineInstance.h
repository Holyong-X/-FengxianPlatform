// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SuperMap_MainActor.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SuperMap_SkylineInstance.generated.h"

UCLASS()
class SUPERMAPSAMPLES_API ASuperMap_SkylineInstance : public AActor , public FSuperMap_MouseControl
{
	GENERATED_BODY()
	
public:	
	ASuperMap_SkylineInstance();
	~ASuperMap_SkylineInstance();

private:
	void MouseLeftButtonDown();

	void MouseRightButtonDown();

	void MouseRealTimeAnchor();
public:	

	//! \brief ����߷���
	//! \param bclip [in] true��ʼ
	UFUNCTION(BlueprintCallable, Category = "SuperMap_SkylineInstance")
	void SetIsSkyline(bool bskyline);

	//! \brief ��������ɫ
	UFUNCTION(BlueprintCallable, Category = "SuperMap_SkylineInstance")
	void SetSkylineColor(FColor color);

	//! \brief ���ø�����
	UFUNCTION(BlueprintCallable, Category = "SuperMap_SkylineInstance")
	void SetViewerPitch(float pitch);

	//! \brief ����/��ȡ���ߵ�ˮƽ����,����Ϊ0
	UFUNCTION(BlueprintCallable, Category = "SuperMap_SkylineInstance")
	void SetViewerDirection(float direction);

	//! \brief ���û�ȡ����߰뾶
	UFUNCTION(BlueprintCallable, Category = "SuperMap_SkylineInstance")
	void SetRadius(float dRadius);

	//! \brief ��ӱպ�������
	UFUNCTION(BlueprintCallable, Category = "SuperMap_SkylineInstance")
	void SetSkylineSectorBody(float fHeight);

	//! \brief ��ȡ�ϰ�����
	UFUNCTION(BlueprintCallable, Category = "SuperMap_SkylineInstance")
	void SkylineGetObjectIDs(bool isLight);

	//! \breif �Ƿ���ʾ��ά��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_SkylineInstance")
	bool m_bSkyline2D;

	//! \breif ��ȡ��ά�ߵ�
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_SkylineInstance")
	TArray<FVector2D> m_arrPoint2Ds;
private:

	//! \brief ���������
	void BuildSkyline();

	//! \brief ��ȡ��ά�����
	void GetSkyline2D();

	bool m_bSkyline;

	FName m_strAnalyst3DName;
	//! \brief ���߷���
	float m_dDirection;
	//! \brief ������
	float m_dPitch;
	//�� \brief ����߰뾶
	float m_dRadius;
	//�� \brief �������ɫ
	FColor m_cColor;
	//�� \brief �ϰ�ͼ�㼰������id
	TMap<Gameint, TArray<Gameint>> m_mapLayerIds;
};
