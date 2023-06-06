#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Base3D/MaterialDefine.h"
#include "SuperMap_SkyAtmosphere.generated.h"

class USuperMap_ProceduralMeshComponent;
class UMaterialInstanceDynamic;
UCLASS()
class SUPERMAP_API ASuperMap_SkyAtmosphere : public AActor
{
	GENERATED_BODY()
public:
	ASuperMap_SkyAtmosphere();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// 创建大气骨架
	void InitialGPUSkyAtmosphere();

	// 渲染大气
	void RenderGPUSkyAtmosphere();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	// 自定义大气网格体
	USuperMap_ProceduralMeshComponent* m_pProceduralMeshCom;

	UMaterialInstanceDynamic* m_pSkyMat;

	// 大气半径
	float m_fOuterRadius;
};