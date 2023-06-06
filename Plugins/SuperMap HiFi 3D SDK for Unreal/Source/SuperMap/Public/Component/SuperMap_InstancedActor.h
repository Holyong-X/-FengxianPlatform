#pragma once

#include "CoreMinimal.h"
#include "vector"
#include "Components/HierarchicalInstancedStaticMeshComponent.h"
#include "Data/Matrix4d.h"
#include "Base3D/CommonDefine.h"
#include "SuperMap_InstancedActor.generated.h"

using namespace SuperMapSDK;
using namespace SuperMapSDK::UnrealEngine::Data;
UCLASS()
class SUPERMAP_API ASuperMap_InstancedActor : public AActor
{
	GENERATED_BODY()

public:
	ASuperMap_InstancedActor();
	virtual ~ASuperMap_InstancedActor();

public:
	//! \brief Foliage���
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SupermapGIS")
	UHierarchicalInstancedStaticMeshComponent* m_pInstanceStaticMeshComponent;
	
	//! \brief ����ľ���
	std::vector<FTransform> m_arrTrans;

	//! \brief Foliage����Դ·��
	FString m_strFoliageResourcePath;

	//! \brief ����ľ���
	TArray<Matrix4d> m_arrMatrixs;

public:
	//! \brief ��������ԭ��
	void UpdateWorldOrigin();

protected:
	//! \brief ���������ƫ��
	virtual void ApplyWorldOffset(const FVector& InOffset, Gamebool bWorldShift);
};