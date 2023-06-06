#include "Editor/SuperMap_SkyAtmosphere.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "GameFramework/PlayerController.h"
#include "Component/SuperMap_ProceduralMeshComponent.h"
#include "Engine/World.h"
//#include "SMMesh.h"

//! Multiplier for degrees to radians
#define DTOR    0.0174532925199432957692369077

//! Multiplier for radians to degrees
#define RTOD    57.295779513082320876798154814

using namespace SuperMapSDK;
ASuperMap_SkyAtmosphere::ASuperMap_SkyAtmosphere()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_pSkyMat = nullptr;
	m_fOuterRadius = 6528140.0f;

	// 创建一个自定义网格体
	m_pProceduralMeshCom = CreateDefaultSubobject<USuperMap_ProceduralMeshComponent>(TEXT("ProceduralMesh"));
	m_pProceduralMeshCom->SetupAttachment(RootComponent);

	//InitialGPUSkyAtmosphere();
}

void ASuperMap_SkyAtmosphere::InitialGPUSkyAtmosphere()
{
	int nRow = 100;
	int nRank = 200;

	// 初始化骨架和索引
	TArray<FVector>  arrVtxs;
	arrVtxs.SetNumUninitialized(nRow * nRank);

	TArray<FVector> arrNormals;
	//arrNormals.SetNumUninitialized(nRow * nRank);

	bool bIsGlobe = true;
	// 计算顶点坐标
	int i, j;
	for (i = 0; i < nRow; i++)
	{
		for (j = 0; j < nRank; j++)
		{
			float phi = 0.0f + i * 180.0f / (nRow - 1);
			float theta = j * 360.0f / (nRank - 1);
			phi = phi * DTOR;
			theta = theta * DTOR;
			phi = bIsGlobe ? phi : (phi > PI * 2 / 3 ? PI * 2 / 3 : phi);

			double vert1, vert2, vert3;
			vert1 = m_fOuterRadius * cosf(phi);
			vert2 = m_fOuterRadius * sinf(phi) * cosf(theta);
			vert3 = m_fOuterRadius * sinf(phi) * sinf(theta);

			FVector vtx;
			if (bIsGlobe)
			{
				vtx.X = vert1;
				vtx.Y = vert3;
				vtx.Z = vert2;
			}
			else
			{
				vtx.X = vert1;
				vtx.Y = vert2;
				vtx.Z = vert3;
			}

			// 纹理坐标
			arrVtxs[i*nRank + j] = vtx;
			vtx.Normalize();
			//arrNormals[i*nRank + j] = vtx;
		}
	}

	//m_pMesh->SetVertexBuffer(arrVtxs);

	// 顶点索引
	TArray<int32> arrIdxs;
	arrIdxs.SetNumUninitialized((nRow - 1) * (nRank - 1) * 6);

	// 设置索引
	for (i = 0; i < nRow - 1; i++)
	{
		for (j = 0; j < nRank - 1; j++)
		{
			arrIdxs[(i*(nRank - 1) + j) * 6 + 0] = (i * nRank + j);
			arrIdxs[(i*(nRank - 1) + j) * 6 + 1] = ((i + 1) * nRank + j);
			arrIdxs[(i*(nRank - 1) + j) * 6 + 2] = (i * nRank + (j + 1) % nRank);

			arrIdxs[(i*(nRank - 1) + j) * 6 + 3] = (i * nRank + (j + 1) % nRank);
			arrIdxs[(i*(nRank - 1) + j) * 6 + 4] = ((i + 1) * nRank + j);
			arrIdxs[(i*(nRank - 1) + j) * 6 + 5] = ((i + 1) * nRank + (j + 1) % nRank);
		}
	}

	TArray<int32> arrNewIds;
	// 处理无效的三角形
	for (i = 0; i < arrIdxs.Num(); i += 3)
	{
		int32 nIndex1 = arrIdxs[i + 0];
		int32 nIndex2 = arrIdxs[i + 1];
		int32 nIndex3 = arrIdxs[i + 2];

		FVector v1 = arrVtxs[nIndex1];
		FVector v2 = arrVtxs[nIndex2];
		FVector v3 = arrVtxs[nIndex3];

		if (v1 == v2
			|| v1 == v3
			|| v2 == v3)
		{
			continue;
		}

		// 索引顺序和组件相反
		arrNewIds.Add(nIndex3);
		arrNewIds.Add(nIndex2);
		arrNewIds.Add(nIndex1);
	}

	TArray<FVector> EmptyVectorArray;
	TArray<FColor> EmptyColorArray;
	TArray<FVector2D> EmptyTexCoordArray;
	TArray<FProcMeshTangent> EmptyTangentArray;

	m_pProceduralMeshCom->CreateMeshSection(0 , arrVtxs, arrNewIds, arrNormals, EmptyTexCoordArray, EmptyTexCoordArray, EmptyTexCoordArray, EmptyTexCoordArray, EmptyColorArray, EmptyTangentArray, false);

	UMaterialInterface* pMaterialInterface = LoadObject<UMaterialInterface>(nullptr, *SM_SKYRENDER_MAT);
	m_pSkyMat = UMaterialInstanceDynamic::Create(pMaterialInterface, nullptr);

	if (m_pSkyMat != nullptr)
	{
		m_pProceduralMeshCom->SetMaterial(0, m_pSkyMat);
	}
	m_pProceduralMeshCom->UpdateComponentCollision(false);
}

// 渲染大气
void ASuperMap_SkyAtmosphere::RenderGPUSkyAtmosphere()
{
	if (m_pSkyMat == nullptr)
	{
		return;
	}

	UWorld* pWorld = GetWorld();

	APlayerController* pPlayerController = pWorld->GetFirstPlayerController();
	APlayerCameraManager* pPlayerCameraManager = pPlayerController->PlayerCameraManager;

	if (pPlayerCameraManager == nullptr)
	{
		return;
	}

	// 相机（眼睛）位置
	FVector vCameraPos = pPlayerCameraManager->GetCameraLocation();
	vCameraPos.X /= 6378137.0f;
	vCameraPos.Y /= 6378137.0f;
	vCameraPos.Z /= 6378137.0f;
	m_pSkyMat->SetVectorParameterValue(FName("v3CameraPos"), vCameraPos);

	// 太阳的位置 
	FVector vSunLight = FVector(0, 1, 0);
	m_pSkyMat->SetVectorParameterValue(FName("v3LightPos"), vSunLight);

	// 太阳光颜色的倒数
	FVector v3InvWavelength;
	v3InvWavelength.X = 1.0f / (float)pow(0.650f, 4.0f);
	v3InvWavelength.Y = 1.0f / (float)pow(0.570f, 4.0f);
	v3InvWavelength.Z = 1.0f / (float)pow(0.475f, 4.0f);
	m_pSkyMat->SetVectorParameterValue(FName("v3InvWavelength"), v3InvWavelength);

	// 相机高度
	float fCameraHeight;
	float fCameraHeight2;
	FVector vCameraDir;
	vCameraPos.ToDirectionAndLength(vCameraDir, fCameraHeight);
	fCameraHeight2 = fCameraHeight * fCameraHeight;
	m_pSkyMat->SetScalarParameterValue(FName("fCameraHeight"), fCameraHeight);
	m_pSkyMat->SetScalarParameterValue(FName("fCameraHeight2"), fCameraHeight2);

	// 大气外半径长度
	float fOuterRadius = m_fOuterRadius / 6378137.0f;
	float fOuterRadius2 = fOuterRadius * fOuterRadius;
	m_pSkyMat->SetScalarParameterValue(FName("fOuterRadius"), fOuterRadius);
	m_pSkyMat->SetScalarParameterValue(FName("fOuterRadius2"), fOuterRadius2);

	// 大气内半径长度
	float fInnerRadius = 1.0f;
	m_pSkyMat->SetScalarParameterValue(FName("fInnerRadius"), 1.0f);
	m_pSkyMat->SetScalarParameterValue(FName("fInnerRadius2"), 1.0f);

	/*m_Kr = 0.0025f;
	m_Km = 0.001f;
	m_ESun = 20.0f;
	m_g = -0.99f;*/

	// 散射方程相关参数
	float Kr4PI = 0.0025f * 4.0f * 3.1415926535897932384626433833f;
	float Km4PI = 0.001f * 4.0f * 3.1415926535897932384626433833f;

	m_pSkyMat->SetScalarParameterValue(FName("fKrESun"), 0.0499999970f);
	m_pSkyMat->SetScalarParameterValue(FName("fKmESun"), 0.0200000014f);
	m_pSkyMat->SetScalarParameterValue(FName("fKr4PI"), 0.0314159244f);
	m_pSkyMat->SetScalarParameterValue(FName("fKm4PI"), 0.0125663709f);

	// 大气高度的倒数
	float fScale = 1.0f / (fOuterRadius - fInnerRadius);
	m_pSkyMat->SetScalarParameterValue(FName("fScale"), fScale);

	// 深度比例
	m_pSkyMat->SetScalarParameterValue(FName("fScaleDepth"), 0.25f);
	// fScale / 0.25f
	m_pSkyMat->SetScalarParameterValue(FName("fScaleOverScaleDepth"), 102.049019f);

	float m_g = -0.99f;
	m_pSkyMat->SetScalarParameterValue(FName("gMieConst"), -0.99f);
	m_pSkyMat->SetScalarParameterValue(FName("gMieConst2"), 0.980100036f);
}

void ASuperMap_SkyAtmosphere::BeginPlay()
{
	Super::BeginPlay();

	InitialGPUSkyAtmosphere();

	//m_pMesh->Update();
}

void ASuperMap_SkyAtmosphere::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RenderGPUSkyAtmosphere();
}