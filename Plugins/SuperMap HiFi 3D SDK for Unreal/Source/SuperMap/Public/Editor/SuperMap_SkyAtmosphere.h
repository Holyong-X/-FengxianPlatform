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

	// ���������Ǽ�
	void InitialGPUSkyAtmosphere();

	// ��Ⱦ����
	void RenderGPUSkyAtmosphere();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	// �Զ������������
	USuperMap_ProceduralMeshComponent* m_pProceduralMeshCom;

	UMaterialInstanceDynamic* m_pSkyMat;

	// �����뾶
	float m_fOuterRadius;
};