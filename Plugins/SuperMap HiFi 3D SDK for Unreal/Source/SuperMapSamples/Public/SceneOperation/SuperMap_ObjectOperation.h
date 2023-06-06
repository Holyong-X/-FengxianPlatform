// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "SuperMap_MainActor.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SuperMap_ObjectOperation.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FObjectOperationDelegate);

UCLASS()
class SUPERMAPSAMPLES_API ASuperMap_ObjectOperation : public AActor, public FSuperMap_MouseControl
{
	GENERATED_BODY()
	
public:	
	ASuperMap_ObjectOperation();
	~ASuperMap_ObjectOperation();
public:
	UPROPERTY(BlueprintAssignable)
	FObjectOperationDelegate CallEvent;

	UPROPERTY(BlueprintAssignable)
	FObjectOperationDelegate CallGetPosition;

	UFUNCTION(BlueprintCallable, Category = "SuperMap_ObjectOperation")
	void BuildObjectOperation(bool bOperation);

	UFUNCTION(BlueprintCallable, Category = "SuperMap_ObjectOperation")
	AStaticMeshActor* GetStaticMeshActor();

	UFUNCTION(BlueprintCallable, Category = "SuperMap_ObjectOperation")
	FVector GetPosition();

	UFUNCTION(BlueprintCallable, Category = "SuperMap_ObjectOperation")
	void ToJson();

	UFUNCTION(BlueprintCallable, Category = "SuperMap_ObjectOperation")
	void FromJson();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_ObjectOperation")
	TArray<AActor*> m_arrActors;

private:
	void MouseLeftButtonDown();

	void MouseRightButtonDown();

	void MouseRealTimeAnchor();

	AStaticMeshActor* m_StaticMeshActor;

	FVector m_vPosition;
protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
