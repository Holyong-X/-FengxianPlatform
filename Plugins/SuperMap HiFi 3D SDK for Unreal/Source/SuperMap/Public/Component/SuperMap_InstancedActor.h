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
	//! \brief Foliage组件
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SupermapGIS")
	UHierarchicalInstancedStaticMeshComponent* m_pInstanceStaticMeshComponent;
	
	//! \brief 组件的矩阵
	std::vector<FTransform> m_arrTrans;

	//! \brief Foliage的资源路径
	FString m_strFoliageResourcePath;

	//! \brief 组件的矩阵
	TArray<Matrix4d> m_arrMatrixs;

public:
	//! \brief 更新世界原点
	void UpdateWorldOrigin();

protected:
	//! \brief 世界坐标的偏移
	virtual void ApplyWorldOffset(const FVector& InOffset, Gamebool bWorldShift);
};