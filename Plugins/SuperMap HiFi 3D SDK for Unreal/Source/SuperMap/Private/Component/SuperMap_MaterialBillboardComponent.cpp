#pragma once

#include "Component/SuperMap_MaterialBillboardComponent.h"
#include "EngineGlobals.h"
#include "RHI.h"
#include "RenderResource.h"
#include "VertexFactory.h"
#include "PackedNormal.h"
#include "LocalVertexFactory.h"
#include "PrimitiveViewRelevance.h"
#include "Materials/MaterialInterface.h"
#include "PrimitiveSceneProxy.h"
#include "Engine/CollisionProfile.h"
#include "Curves/CurveFloat.h"
#include "SceneManagement.h"
#include "Engine/Engine.h"
#include "Engine/LevelStreaming.h"
#include "LevelUtils.h"
#include "PrimitiveSceneProxy.h"
#include "StaticMeshResources.h"
#include "Base3D/CommonDefine.h"
#if SM_FOR_UE_FIVE
#include "Runtime/RHI/Public/RHI.h"
#endif
using namespace SuperMapSDK;
/** A material sprite vertex. */
struct FSMMaterialSpriteVertex
{
	FVector Position;
	FPackedNormal TangentX;
	FPackedNormal TangentZ;
	FColor Color;
	FVector2D TexCoords;
};

/** A dummy vertex buffer used to give the FMaterialSpriteVertexFactory something to reference as a stream source. */
class FSMMaterialSpriteVertexBuffer : public FVertexBuffer
{
public:

	virtual Gamevoid InitRHI() override
	{
#if !SM_FOR_UE_FIVE
		FRHIResourceCreateInfo CreateInfo;
		VertexBufferRHI = RHICreateVertexBuffer(sizeof(FSMMaterialSpriteVertex), BUF_Static, CreateInfo);
#else
		FRHIResourceCreateInfo CreateInfo(TEXT("FMaterialSpriteVertexBuffer"));
		VertexBufferRHI = RHICreateVertexBuffer(sizeof(FSMMaterialSpriteVertex), BUF_Static, CreateInfo);
#endif
	}
};
static TGlobalResource<FSMMaterialSpriteVertexBuffer> GDummySMMaterialSpriteVertexBuffer;

class FSMMaterialSpriteVertexArray : public FOneFrameResource
{
public:
	TArray<FSMMaterialSpriteVertex, TInlineAllocator<4> > Vertices;
};

/** Represents a sprite to the scene manager. */
class FSMMaterialSpriteSceneProxy final : public FPrimitiveSceneProxy
{
public:
	SIZE_T GetTypeHash() const override
	{
		static size_t UniquePointer;
		return reinterpret_cast<size_t>(&UniquePointer);
	}

	/** Initialization constructor. */
	FSMMaterialSpriteSceneProxy(const UMaterialBillboardComponent* InComponent)
		: FPrimitiveSceneProxy(InComponent)
		, Elements(InComponent->Elements)
		, BaseColor(FColor::White)
		, VertexFactory(GetScene().GetFeatureLevel(), "FMaterialSpriteSceneProxy")
	{
		AActor* Owner = InComponent->GetOwner();
		if (Owner)
		{
			// Level colorization
			ULevel* Level = Owner->GetLevel();
			ULevelStreaming* LevelStreaming = FLevelUtils::FindStreamingLevel(Level);
			if (LevelStreaming)
			{
				// Selection takes priority over level coloration.
				SetLevelColor(LevelStreaming->LevelColor);
			}
		}

		USuperMap_MaterialBillboardComponent* pSMInComponent = (USuperMap_MaterialBillboardComponent*)InComponent;

		m_fMinU = pSMInComponent->m_fMinU;
		m_fMinV = pSMInComponent->m_fMinV;
		m_fMaxU = pSMInComponent->m_fMaxU;
		m_fMaxV = pSMInComponent->m_fMaxV;

		for (Gameint ElementIndex = 0; ElementIndex < Elements.Num(); ElementIndex++)
		{
			UMaterialInterface* Material = Elements[ElementIndex].Material;
			if (Material)
			{
				MaterialRelevance |= Material->GetRelevance_Concurrent(GetScene().GetFeatureLevel());
			}
		}

		FColor NewPropertyColor;
		GEngine->GetPropertyColorationColor((UObject*)InComponent, NewPropertyColor);
		SetPropertyColor(NewPropertyColor);

		StaticMeshVertexBuffers.PositionVertexBuffer.Init(1);
		StaticMeshVertexBuffers.StaticMeshVertexBuffer.Init(1, 1);
		StaticMeshVertexBuffers.ColorVertexBuffer.Init(1);

		const FSMMaterialSpriteSceneProxy* Self = this;
		ENQUEUE_RENDER_COMMAND(FMaterialSpriteSceneProxyInit)(
			[Self](FRHICommandListImmediate& RHICmdList)
		{
			Self->StaticMeshVertexBuffers.PositionVertexBuffer.InitResource();
			Self->StaticMeshVertexBuffers.StaticMeshVertexBuffer.InitResource();
			Self->StaticMeshVertexBuffers.ColorVertexBuffer.InitResource();

			FLocalVertexFactory::FDataType Data;
			Self->StaticMeshVertexBuffers.PositionVertexBuffer.BindPositionVertexBuffer(&Self->VertexFactory, Data);
			Self->StaticMeshVertexBuffers.StaticMeshVertexBuffer.BindTangentVertexBuffer(&Self->VertexFactory, Data);
			Self->StaticMeshVertexBuffers.StaticMeshVertexBuffer.BindPackedTexCoordVertexBuffer(&Self->VertexFactory, Data);
			Self->StaticMeshVertexBuffers.StaticMeshVertexBuffer.BindLightMapVertexBuffer(&Self->VertexFactory, Data, 0);
			Self->StaticMeshVertexBuffers.ColorVertexBuffer.BindColorVertexBuffer(&Self->VertexFactory, Data);
			Self->VertexFactory.SetData(Data);

			Self->VertexFactory.InitResource();
		});
	}

	~FSMMaterialSpriteSceneProxy()
	{
		VertexFactory.ReleaseResource();
		StaticMeshVertexBuffers.PositionVertexBuffer.ReleaseResource();
		StaticMeshVertexBuffers.StaticMeshVertexBuffer.ReleaseResource();
		StaticMeshVertexBuffers.ColorVertexBuffer.ReleaseResource();
	}

	virtual Gamevoid GetDynamicMeshElements(const TArray<const FSceneView*>& Views, const FSceneViewFamily& ViewFamily, Gameuint VisibilityMap, FMeshElementCollector& Collector) const override
	{
		QUICK_SCOPE_CYCLE_COUNTER(STAT_MaterialSpriteSceneProxy_GetDynamicMeshElements);

		const Gameint ElementStride = 4 * Elements.Num();
		const Gameint WorstCaseVertexBufferSize = ElementStride * Views.Num();

		if (WorstCaseVertexBufferSize > 0)
		{
			StaticMeshVertexBuffers.PositionVertexBuffer.Init(WorstCaseVertexBufferSize);
			StaticMeshVertexBuffers.StaticMeshVertexBuffer.Init(WorstCaseVertexBufferSize, 1);
			StaticMeshVertexBuffers.ColorVertexBuffer.Init(WorstCaseVertexBufferSize);

			for (Gameint ViewIndex = 0; ViewIndex < Views.Num(); ViewIndex++)
			{
				if (VisibilityMap & (1 << ViewIndex))
				{
					const FSceneView* View = Views[ViewIndex];

					const Gamebool bIsWireframe = View->Family->EngineShowFlags.Wireframe;
					// Determine the position of the source
					const FVector SourcePosition = GetLocalToWorld().GetOrigin();
					const FVector CameraToSource = View->ViewMatrices.GetViewOrigin() - SourcePosition;
					const Gamefloat DistanceToSource = CameraToSource.Size();

					const FVector CameraUp = -View->ViewMatrices.GetInvViewProjectionMatrix().TransformVector(FVector(1.0f, 0.0f, 0.0f));
					const FVector CameraRight = -View->ViewMatrices.GetInvViewProjectionMatrix().TransformVector(FVector(0.0f, 1.0f, 0.0f));
					const FMatrix WorldToLocal = GetLocalToWorld().InverseFast();
					const FMatrix ViewToLocal = View->ViewMatrices.GetInvViewMatrix() * WorldToLocal;
					const FVector TangentX = -ViewToLocal.TransformVector(FVector(1.0f, 0.0f, 0.0f));
					const FVector TangentY = -ViewToLocal.TransformVector(FVector(0.0f, 1.0f, 0.0f));
					const FVector TangentZ = -ViewToLocal.TransformVector(FVector(0.0f, 0.0f, 1.0f));
					//				

					// Draw the elements ordered so the last is on top of the first.
					for (Gameint ElementIndex = 0; ElementIndex < Elements.Num(); ++ElementIndex)
					{
						const FMaterialSpriteElement& Element = Elements[ElementIndex];

						if (Element.Material)
						{
							// Evaluate the size of the sprite.
							Gamefloat SizeX = Element.BaseSizeX;
							Gamefloat SizeY = Element.BaseSizeY;
							if (Element.DistanceToSizeCurve)
							{
								const Gamefloat SizeFactor = Element.DistanceToSizeCurve->GetFloatValue(DistanceToSource);
								SizeX *= SizeFactor;
								SizeY *= SizeFactor;
							}

							// Convert the size into world-space.
							const Gamefloat W = View->ViewMatrices.GetViewProjectionMatrix().TransformPosition(SourcePosition).W;
							const Gamefloat AspectRatio = CameraRight.Size() / CameraUp.Size();

							// TangentXYZ are normalized, so we don't / Right.Size() and Up.Size() again here
							const Gamefloat WorldSizeX = Element.bSizeIsInScreenSpace ? (SizeX               * W) : SizeX;
							const Gamefloat WorldSizeY = Element.bSizeIsInScreenSpace ? (SizeY * AspectRatio * W) : SizeY;

							// Evaluate the color/opacity of the sprite.
							FLinearColor Color = BaseColor;
							if (Element.DistanceToOpacityCurve)
							{
								Color.A *= Element.DistanceToOpacityCurve->GetFloatValue(DistanceToSource);
							}

							const int WriteOffset = ElementStride * ViewIndex + 4 * ElementIndex;
							for (Gameint VertexIndex = 0; VertexIndex < 4; ++VertexIndex)
							{
								const int WriteIndex = WriteOffset + VertexIndex;
								// correct TBN of billboard by ViewToLocal, notice that we use -TangentX
								StaticMeshVertexBuffers.StaticMeshVertexBuffer.SetVertexTangents(WriteIndex, GameVector3(-TangentX), GameVector3(TangentY), GameVector3(TangentZ));
								StaticMeshVertexBuffers.ColorVertexBuffer.VertexColor(WriteIndex) = Color.ToFColor(true);
							}

							// Set up the sprite vertex positions and texture coordinates.
							FVector v1 = -WorldSizeX * TangentY + +WorldSizeY * TangentX;
							FVector v2 = +WorldSizeX * TangentY + +WorldSizeY * TangentX;
							FVector v3 = -WorldSizeX * TangentY + -WorldSizeY * TangentX;
							FVector v4 = +WorldSizeX * TangentY + -WorldSizeY * TangentX;

							FVector dV = v1 - v3;

							v1 += dV;
							v2 += dV;
							v3 += dV;
							v4 += dV;

							StaticMeshVertexBuffers.PositionVertexBuffer.VertexPosition(WriteOffset + 0) = GameVector3(v1);
							StaticMeshVertexBuffers.PositionVertexBuffer.VertexPosition(WriteOffset + 1) = GameVector3(v2);
							StaticMeshVertexBuffers.PositionVertexBuffer.VertexPosition(WriteOffset + 2) = GameVector3(v3);
							StaticMeshVertexBuffers.PositionVertexBuffer.VertexPosition(WriteOffset + 3) = GameVector3(v4);

							StaticMeshVertexBuffers.StaticMeshVertexBuffer.SetVertexUV(WriteOffset + 0, 0, GameVector2(m_fMinU, m_fMaxV));
							StaticMeshVertexBuffers.StaticMeshVertexBuffer.SetVertexUV(WriteOffset + 1, 0, GameVector2(m_fMinU, m_fMinV));
							StaticMeshVertexBuffers.StaticMeshVertexBuffer.SetVertexUV(WriteOffset + 2, 0, GameVector2(m_fMaxU, m_fMaxV));
							StaticMeshVertexBuffers.StaticMeshVertexBuffer.SetVertexUV(WriteOffset + 3, 0, GameVector2(m_fMaxU, m_fMinV));

							// Set up the FMeshElement.
							FMeshBatch& Mesh = Collector.AllocateMesh();

							Mesh.VertexFactory = &VertexFactory;
							Mesh.MaterialRenderProxy = Element.Material->GetRenderProxy();
							Mesh.LCI = NULL;
							Mesh.ReverseCulling = IsLocalToWorldDeterminantNegative() ? true : false;
							Mesh.CastShadow = false;
							Mesh.DepthPriorityGroup = (ESceneDepthPriorityGroup)GetDepthPriorityGroup(View);
							Mesh.Type = PT_TriangleStrip;
							Mesh.bDisableBackfaceCulling = true;

							// Set up the FMeshBatchElement.
							FMeshBatchElement& BatchElement = Mesh.Elements[0];
							BatchElement.IndexBuffer = NULL;
							BatchElement.FirstIndex = 0;
							BatchElement.MinVertexIndex = 0;
							BatchElement.MaxVertexIndex = 3;
							BatchElement.NumPrimitives = 2;
							BatchElement.BaseVertexIndex = WriteOffset;

							Mesh.bCanApplyViewModeOverrides = true;
							Mesh.bUseWireframeSelectionColoring = IsSelected();

							Collector.AddMesh(ViewIndex, Mesh);
						}
					}
				}
			}

			FLocalVertexFactory* VertexFactoryPtr = &VertexFactory;
			const FSMMaterialSpriteSceneProxy* Self = this;
			ENQUEUE_RENDER_COMMAND(FMaterialSpriteSceneProxyLegacyInit)(
				[VertexFactoryPtr, Self](FRHICommandListImmediate& RHICmdList)
			{
				Self->StaticMeshVertexBuffers.PositionVertexBuffer.UpdateRHI();
				Self->StaticMeshVertexBuffers.StaticMeshVertexBuffer.UpdateRHI();
				Self->StaticMeshVertexBuffers.ColorVertexBuffer.UpdateRHI();

				FLocalVertexFactory::FDataType Data;
				Self->StaticMeshVertexBuffers.PositionVertexBuffer.BindPositionVertexBuffer(VertexFactoryPtr, Data);
				Self->StaticMeshVertexBuffers.StaticMeshVertexBuffer.BindTangentVertexBuffer(VertexFactoryPtr, Data);
				Self->StaticMeshVertexBuffers.StaticMeshVertexBuffer.BindPackedTexCoordVertexBuffer(VertexFactoryPtr, Data);
				Self->StaticMeshVertexBuffers.StaticMeshVertexBuffer.BindLightMapVertexBuffer(VertexFactoryPtr, Data, 0);
				Self->StaticMeshVertexBuffers.ColorVertexBuffer.BindColorVertexBuffer(VertexFactoryPtr, Data);
				VertexFactoryPtr->SetData(Data);

				VertexFactoryPtr->UpdateRHI();
			});
		}
	}

	virtual FPrimitiveViewRelevance GetViewRelevance(const FSceneView* View) const override
	{
		bool bVisible = View->Family->EngineShowFlags.BillboardSprites;
		FPrimitiveViewRelevance Result;
		Result.bDrawRelevance = IsShown(View);
		Result.bDynamicRelevance = true;
		Result.bShadowRelevance = IsShadowCast(View);
		MaterialRelevance.SetPrimitiveViewRelevance(Result);
		return Result;
	}
	virtual bool CanBeOccluded() const override { return !MaterialRelevance.bDisableDepthTest; }
	virtual Gameuint GetMemoryFootprint() const override { return sizeof(*this) + GetAllocatedSize(); }
	Gameuint GetAllocatedSize() const { return FPrimitiveSceneProxy::GetAllocatedSize(); }

private:
	/** The buffer containing vertex data. */
	mutable FStaticMeshVertexBuffers StaticMeshVertexBuffers;

	Gamefloat m_fMinU;
	Gamefloat m_fMinV;
	Gamefloat m_fMaxU;
	Gamefloat m_fMaxV;

	TArray<FMaterialSpriteElement> Elements;
	FMaterialRelevance MaterialRelevance;
	FColor BaseColor;
	mutable FLocalVertexFactory VertexFactory;
};

USuperMap_MaterialBillboardComponent::USuperMap_MaterialBillboardComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	m_fMinU = 0;
	m_fMinV = 0;

	m_fMaxU = 0;
	m_fMaxV = 0;

	SetCollisionProfileName(UCollisionProfile::NoCollision_ProfileName);
}

FPrimitiveSceneProxy* USuperMap_MaterialBillboardComponent::CreateSceneProxy()
{
	return new FSMMaterialSpriteSceneProxy(this);
}

Gamevoid USuperMap_MaterialBillboardComponent::SetUV(Gamefloat fMinU, Gamefloat fMinV, Gamefloat fMaxU, Gamefloat fMaxV)
{
	m_fMinU = fMinU;
	m_fMinV = fMinV;

	m_fMaxU = fMaxU;
	m_fMaxV = fMaxV;
}
