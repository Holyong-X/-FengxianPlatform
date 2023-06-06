#pragma once

#include "CoreMinimal.h"
#include "RenderCore/Public/RenderResource.h"
#include "RHI/Public/RHI.h"
#include "RHI/Public/RHIResources.h"
#include "RHI/Public/RHICommandList.h"
#include "Component/CustomRealRasterMesh.h"

class FTextureRenderTargetResource;
class UTextureRenderTarget2D;

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Render
		{
			struct FTextureVertex
			{
				GameVector4 Position;
				GameVector2 UV;
			};

			class FRegionVertexBuffer : public FVertexBuffer
			{
			public:
				void CreateRHI(TResourceArray<FTextureVertex, VERTEXBUFFER_ALIGNMENT> & VertexBuffer);
			};

			class FRegionIndexBuffer : public FIndexBuffer
			{
			public:
				void CreateRHI(TResourceArray<uint32, INDEXBUFFER_ALIGNMENT> &IndexBuffer);
			};

			class FTextureVertexDeclaration : public FRenderResource
			{
			public:
				FVertexDeclarationRHIRef VertexDeclarationRHI;

				virtual void InitRHI() override
				{
					FVertexDeclarationElementList Elements;
					uint32 nStride = sizeof(FTextureVertex);
					Elements.Add(FVertexElement(0, STRUCT_OFFSET(FTextureVertex, Position), VET_Float4, 0, nStride));
					Elements.Add(FVertexElement(0, STRUCT_OFFSET(FTextureVertex, UV), VET_Float2, 1, nStride));
					VertexDeclarationRHI = RHICreateVertexDeclaration(Elements);
				}

				virtual void ReleaseRHI() override
				{
					VertexDeclarationRHI.SafeRelease();
				}

			};




			class FVectorVertexDeclaration : public FRenderResource
			{
			public:
				FVertexDeclarationRHIRef VertexDeclarationRHI;

				virtual void InitRHI() override
				{
					FVertexDeclarationElementList Elements;
					uint32 nStride = 3*sizeof(Gamefloat);
					Elements.Add(FVertexElement(0, 0, VET_Float3, 0, nStride));



					nStride = sizeof(Gameuint);
					Elements.Add(FVertexElement(1, 0, VET_Color, 1, nStride));


					VertexDeclarationRHI = RHICreateVertexDeclaration(Elements);
				}

				virtual void ReleaseRHI() override
				{
					VertexDeclarationRHI.SafeRelease();
				}

			};

			class FVectorVertexDeclarationWithTexture : public FRenderResource
			{
			public:
				FVertexDeclarationRHIRef VertexDeclarationRHI;

				virtual void InitRHI() override
				{
					FVertexDeclarationElementList Elements;
					uint32 nStride = 3 * sizeof(Gamefloat);
					Elements.Add(FVertexElement(0, 0, VET_Float3, 0, nStride));

					nStride = 2 * sizeof(Gamefloat);
					Elements.Add(FVertexElement(1, 0, VET_Float2, 1, nStride));

					VertexDeclarationRHI = RHICreateVertexDeclaration(Elements);
				}

				virtual void ReleaseRHI() override
				{
					VertexDeclarationRHI.SafeRelease();
				}

			};

			class TextureRenderer
			{
			public:
				static void DrawRegionByGlobalShader(TArray<FTextureVertex> Vertexs, TArray<uint32> Indices ,UTextureRenderTarget2D* pRenderTarget2D);
			
				static void DrawCustomRegion(FRHICommandListImmediate & RHIImmCmdList, TArray<FTextureVertex> Vertexs, TArray<uint32> Indices, FTextureRenderTargetResource* RenderTargetRHI1);

				//Ó°ÏñÕ¤¸ñ»¯
				static void DrawRealtimeRaster(TArray<TArray<FTextureVertex> > Vertexs, TArray<TArray<uint32> > Indices, TArray <FVector4> transform, TArray <Gamelong> textureName, 
					TArray<FVector4> colors, TArray<uint32> orders, UTextureRenderTarget2D* pRenderTarget2D);

				static void DrawRealtimeRaster(FRHICommandListImmediate & RHIImmCmdList, TArray<TArray<FTextureVertex> > Vertexs, TArray<TArray<uint32> > Indices,
					TArray<FVector4> transform, TArray<Gamelong> textureName, TArray<FVector4> colors, TArray<uint32> orders, FTextureRenderTargetResource* RenderTargetRHI1);




				static void DrawRealtimeRasterVector(TArray<CustomRealRasterMesh*> meshes, FVector4 transform, TArray<Matrix4d> objectTransform, UTextureRenderTarget2D* pRenderTarget2D, Gamebool bSecondColor = false);

				static void DrawRealtimeRasterVector(FRHICommandListImmediate & RHIImmCmdList, TArray<CustomRealRasterMesh*>meshes, FVector4 transform, TArray<Matrix4d> objectTransform, FTextureRenderTargetResource* RenderTargetRHI1, Gamebool bSecondColor = false);
			
				static void DrawRealtimeRasterVectorWithTexture(TArray<CustomRealRasterMesh*> meshes,FVector4 transform, TArray<FVector4> arrTrans,TArray<Matrix4d> texMatrix, TArray<Gamelong> arrGameTexture, UTextureRenderTarget2D* pRenderTarget2D);

				static void DrawRealtimeRasterVectorWithTexture(FRHICommandListImmediate& RHIImmCmdList, TArray<CustomRealRasterMesh*> meshes, FVector4 transform, TArray<FVector4> arrTrans, TArray<Matrix4d> texMatrix, TArray<Gamelong> arrGameTexture, FTextureRenderTargetResource* RenderTargetRHI1);

			};
		}
	}
}