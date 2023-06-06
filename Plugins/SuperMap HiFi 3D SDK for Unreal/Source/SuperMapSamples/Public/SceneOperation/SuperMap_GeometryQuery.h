// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SuperMap_MainActor.h"
#include "Base3D/CommonDefine.h"
#include "Base3D/MaterialDefine.h"
#include "Core/Query3D.h"
#include "Data/GeoBox.h"
#include "Component/SuperMap_ROEntityActor.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SuperMap_GeometryQuery.generated.h"

UCLASS()
class SUPERMAPSAMPLES_API ASuperMap_GeometryQuery : public AActor, public FSuperMap_MouseControl
{
	GENERATED_BODY()
	
public:	
	ASuperMap_GeometryQuery();
	~ASuperMap_GeometryQuery();
	virtual void Tick(float DeltaTime) override;
private:
	void MouseLeftButtonDown();

	void MouseRightButtonDown();

	void MouseRealTimeAnchor();
protected:
	virtual void BeginPlay() override;
public:	
	//! \brief �����ռ��ѯ
	UFUNCTION(BlueprintCallable, Category = "ASuperMap_GeometryQuery")
	void BuildGeometryQuery(bool bGeometryQuery);
private:
	void DrawBox(Vector3d vPos);

	void CalculateGeoBoxParam();

	double GetLengthFromVector(Vector3d start, Vector3d end);

	void Realse();
private:
	//! \brief ��ʼ��
	Vector3d m_vStart;
	Vector3d m_vStartDraw;
	//! \brief ��ֹ��
	Vector3d m_vEnd;
	Vector3d m_vEndDraw;
	//! \brief ��
	Gamedouble m_dWidth;

	//! \brief ��
	Gamedouble m_dLength;

	//! \brief ��
	Gamedouble m_dHeight;

	//! \brief ���ĵ�
	Vector3d m_vCenter;

	Gamebool m_bGeometryQuery;

	GeoBox* m_pGeoBox;

	Gameint m_nMouseLeftDown;

	ASuperMap_ROEntityActor* m_pROEntityActor;
};
