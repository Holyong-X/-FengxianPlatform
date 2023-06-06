#include "Component/SuperMap_InstancedActor.h"
#include "Engine/World.h"
#include "Base3D/CommonDefine.h"
#include "Core/Georeference.h"

using namespace SuperMapSDK;
using namespace SuperMapSDK::UnrealEngine::Core;

ASuperMap_InstancedActor::ASuperMap_InstancedActor()
{
	m_pInstanceStaticMeshComponent = CreateDefaultSubobject<UHierarchicalInstancedStaticMeshComponent>(TEXT("InstancedMesh"));
	m_pInstanceStaticMeshComponent->SetupAttachment(RootComponent);
}

ASuperMap_InstancedActor::~ASuperMap_InstancedActor()
{

}

void ASuperMap_InstancedActor::UpdateWorldOrigin()
{
	TArray<FTransform> arrNewTransform;
	Gameint nCount = m_arrMatrixs.Num();
	for (Gameint i = 0; i < nCount; i++)
	{
		Matrix4d mat4d = m_arrMatrixs[i];
		mat4d = Georeference::TransformECEFToUERelative(mat4d);
		FMatrix matf;
		Matrix4d::ToFMatrix(mat4d, matf);
		FTransform trans;
		trans.SetFromMatrix(matf);
		arrNewTransform.Add(trans);
	}

	m_pInstanceStaticMeshComponent->BatchUpdateInstancesTransforms(0, arrNewTransform, true);
}

void ASuperMap_InstancedActor::ApplyWorldOffset(const FVector& InOffset, bool bWorldShift)
{

}