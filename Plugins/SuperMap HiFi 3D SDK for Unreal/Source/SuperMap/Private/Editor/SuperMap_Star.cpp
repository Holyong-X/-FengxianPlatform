// Fill out your copyright notice in the Description page of Project Settings.


#include "Editor/SuperMap_Star.h"
#include "Component/SuperMap_ProceduralMeshComponent.h"

//! Multiplier for degrees to radians
#define DTOR    0.0174532925199432957692369077

//! Multiplier for radians to degrees
#define RTOD    57.295779513082320876798154814

// Sets default values
ASuperMap_Star::ASuperMap_Star()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 创建一个Mesh组件
	m_pMesh = CreateDefaultSubobject<USuperMap_ProceduralMeshComponent>(TEXT("Star"));
	m_pMesh->SetupAttachment(RootComponent);

	InitialRandomStar();
}

// Called when the game starts or when spawned
void ASuperMap_Star::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ASuperMap_Star::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FVector ASuperMap_Star::SphericalToCartesian(float fLon, float fLat, float fAlt)
{
	float fRadius = fAlt;
	float fRadCosLat = fRadius * cos(fLat);

	return FVector(fRadCosLat*sin(fLon),
		fRadius*sin(fLat),
		fRadCosLat*cos(fLon));
}

void ASuperMap_Star::InitialRandomStar()
{
	const int VertexNumber = 5000;
	float sphereRadius = 63781370000000.0f;

	// 顶点
	TArray<FVector> arrVertex;
	arrVertex.SetNumUninitialized(VertexNumber);

	// 顶点颜色
	TArray<FColor> arrColor;
	arrColor.SetNumUninitialized(VertexNumber);

	// 索引
	TArray<int32> arrIdx;
	arrIdx.SetNumUninitialized(VertexNumber);

	int nVertex = 0;
	FVector v;
	float fLon = 0;
	float fLat = 0;
	unsigned int verColor = 0;

	FMath::RandInit(1);
	for (nVertex = 0; nVertex < VertexNumber; nVertex++)
	{
		//把经纬度随机一下
		fLon = 1.0 * FMath::Rand() / RAND_MAX * 360 - 180;
		fLat = 1.0 * FMath::Rand() / RAND_MAX * 180 - 90;
		verColor = FMath::Rand() % 256;
		v = SphericalToCartesian(fLon*DTOR, fLat*DTOR, sphereRadius);

		//v *= 100.0f;
		//v.Z -= 637813700;

		//为了是看起来是白色，rgb设置成一样的值， alpha值设为1.0
		/*m_pVertices[nVertex * 3] = v.x;
		m_pVertices[nVertex * 3 + 1] = v.y;
		m_pVertices[nVertex * 3 + 2] = v.z;
		m_pVertexColor[ixVertex] = UGRGBA(verColor, verColor, verColor, 255);*/

		arrVertex[nVertex] = v;

		FColor color;
		color.R = 255.0;
		color.G = 255.0;
		color.B = 255.0;
		color.A = 255.0;

		arrColor[nVertex] = color;

		arrIdx[nVertex] = nVertex;
	}

	m_pMesh->SetDrawType(PT_PointList);

	TArray<FVector> EmptyVectorArray;
	TArray<FColor> EmptyColorArray;
	TArray<FVector2D> EmptyTexCoordArray;
	TArray<FProcMeshTangent> EmptyTangentArray;
	m_pMesh->CreateMeshSection(0, arrVertex, arrIdx, EmptyVectorArray, EmptyTexCoordArray, EmptyTexCoordArray, EmptyTexCoordArray, EmptyTexCoordArray, arrColor, EmptyTangentArray, false);

}

