#include "Render/TextureRenderer.h"
#include "Engine/TextureRenderTarget2D.h"
#if !SM_FOR_UE_25
#include "Rendering/Texture2DResource.h"
#endif
#include "RenderCore/Public/GlobalShader.h"
#include "RenderCore/Public/ShaderParameterUtils.h"
#include "ControlUE/RealspaceView.h"
#include "Engine/World.h"
#include "Graphics3D/GameTextureManager.h"


#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif

using namespace SuperMapSDK::UnrealEngine::ControlUE;

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Render
		{
			class FCustomTextureGlobalShader : public FGlobalShader
			{
				DECLARE_INLINE_TYPE_LAYOUT(FCustomTextureGlobalShader, NonVirtual);

			public:
				static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters &Parameters)
				{
					return IsFeatureLevelSupported(Parameters.Platform, ERHIFeatureLevel::SM5);
				}

				static void ModifyCompilationEnvironment(const FGlobalShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment)
				{
					FGlobalShader::ModifyCompilationEnvironment(Parameters, OutEnvironment);
				}

				FCustomTextureGlobalShader() {}

				FCustomTextureGlobalShader(const ShaderMetaType::CompiledShaderInitializerType& Initializer):FGlobalShader(Initializer)
				{
					
				}
			};

			class FCustomTextureVertexShader : public FCustomTextureGlobalShader
			{
				DECLARE_GLOBAL_SHADER(FCustomTextureVertexShader)
			public:
				FCustomTextureVertexShader() {}
				FCustomTextureVertexShader(const ShaderMetaType::CompiledShaderInitializerType& Initializer):FCustomTextureGlobalShader(Initializer){}
			};

			class FCustomTexturePixelShader : public FCustomTextureGlobalShader
			{
				DECLARE_GLOBAL_SHADER(FCustomTexturePixelShader)
			public:
				FCustomTexturePixelShader() {}
				FCustomTexturePixelShader(const ShaderMetaType::CompiledShaderInitializerType& Initializer) :FCustomTextureGlobalShader(Initializer) {}
			};

			IMPLEMENT_SHADER_TYPE(,FCustomTextureVertexShader, TEXT("/SuperMap/CustomPixelShader.usf"), TEXT("MainVS"), SF_Vertex);
			IMPLEMENT_SHADER_TYPE(,FCustomTexturePixelShader, TEXT("/SuperMap/CustomPixelShader.usf"), TEXT("MainPS"), SF_Pixel);

			void FRegionVertexBuffer::CreateRHI(TResourceArray<FTextureVertex, VERTEXBUFFER_ALIGNMENT> & VertexBuffer)
			{
#if !SM_FOR_UE_FIVE
				FRHIResourceCreateInfo CreateInfo(&VertexBuffer);
#else
				TCHAR* InDebugName = TEXT("");
				FRHIResourceCreateInfo CreateInfo(InDebugName, &VertexBuffer);
#endif
				VertexBufferRHI = RHICreateVertexBuffer(VertexBuffer.GetResourceDataSize(), BUF_Static, CreateInfo);
			}

			void FRegionIndexBuffer::CreateRHI(TResourceArray<uint32, INDEXBUFFER_ALIGNMENT> &IndexBuffer)
			{
#if !SM_FOR_UE_FIVE
				FRHIResourceCreateInfo CreateInfo(&IndexBuffer);
#else
				TCHAR* InDebugName = TEXT("");
				FRHIResourceCreateInfo CreateInfo(InDebugName, &IndexBuffer);
#endif
				IndexBufferRHI = RHICreateIndexBuffer(sizeof(uint32), IndexBuffer.GetResourceDataSize(), BUF_Static, CreateInfo);
			}

			void TextureRenderer::DrawRegionByGlobalShader(TArray<FTextureVertex> Vertexs, TArray<uint32> Indices, UTextureRenderTarget2D* pRenderTarget2D)
			{
				check(IsInGameThread());

				FTextureRenderTargetResource* RenderTargetRHI = pRenderTarget2D->GameThread_GetRenderTargetResource();

				ENQUEUE_RENDER_COMMAND(CaptureCommand)(
					[RenderTargetRHI, Vertexs, Indices](FRHICommandListImmediate & RHICmdList){
					TextureRenderer::DrawCustomRegion(RHICmdList, Vertexs, Indices , RenderTargetRHI);
				});

				RealspaceView::GetSingleton()->GetWorld()->SendAllEndOfFrameUpdates();
			}

			void TextureRenderer::DrawCustomRegion(FRHICommandListImmediate & RHIImmCmdList, TArray<FTextureVertex> Vertexs, TArray<uint32> Indices, FTextureRenderTargetResource* RenderTargetRHI1)
			{
				check(IsInRenderingThread());

				FTexture2DRHIRef RenderTargetRHI = RenderTargetRHI1->GetRenderTargetTexture();

				FRegionVertexBuffer CustomRegionVertexBuffer;

				int32 nVertexCount = Vertexs.Num();

				TResourceArray<FTextureVertex, VERTEXBUFFER_ALIGNMENT> VertexRes;
				VertexRes.SetNumUninitialized(nVertexCount);

				for (int n = 0; n < nVertexCount; n++)
				{
					VertexRes[n].Position = Vertexs[n].Position;
					VertexRes[n].UV = Vertexs[n].UV;
				}

				CustomRegionVertexBuffer.CreateRHI(VertexRes);
				int32 nIndexCount = Indices.Num();

				FRegionIndexBuffer CustomRegionIndexBuffer;
				TResourceArray<uint32, INDEXBUFFER_ALIGNMENT> IndexBuffer;
				IndexBuffer.SetNumUninitialized(nIndexCount);

				for (int n = 0; n < nIndexCount; n++)
				{
					IndexBuffer[n] = Indices[n];
				}
				
				CustomRegionIndexBuffer.CreateRHI(IndexBuffer);
				
#if !SM_FOR_UE_FIVE
				RHIImmCmdList.TransitionResource(EResourceTransitionAccess::EWritable, RenderTargetRHI);
				FRHIRenderPassInfo RPInfo(RenderTargetRHI, ERenderTargetActions::DontLoad_Store, RenderTargetRHI1->TextureRHI);
#else
				RHIImmCmdList.TransitionResource(ERHIAccess::WritableMask, RenderTargetRHI);
				FRHIRenderPassInfo RPInfo(RenderTargetRHI, ERenderTargetActions::DontLoad_Store);
#endif
				RHIImmCmdList.BeginRenderPass(RPInfo, TEXT("CustomTexturePixelShaderPass"));

				const ERHIFeatureLevel::Type FeatureLevel = GMaxRHIFeatureLevel;
				FGlobalShaderMap* GlobalShaderMap = GetGlobalShaderMap(FeatureLevel);

				TShaderMapRef<FCustomTextureVertexShader> VertexShader(GlobalShaderMap);
				TShaderMapRef<FCustomTexturePixelShader> PixelShader(GlobalShaderMap);

				FTextureVertexDeclaration VertexDeclaration;
				VertexDeclaration.InitRHI();

				FGraphicsPipelineStateInitializer GraphicsPSOInit;
				RHIImmCmdList.ApplyCachedRenderTargets(GraphicsPSOInit);
				GraphicsPSOInit.DepthStencilState = TStaticDepthStencilState<false, CF_Always>::GetRHI();
				GraphicsPSOInit.BlendState = TStaticBlendState<>::GetRHI();
				GraphicsPSOInit.RasterizerState = TStaticRasterizerState<>::GetRHI();
				GraphicsPSOInit.PrimitiveType = PT_TriangleList;
				GraphicsPSOInit.BoundShaderState.VertexDeclarationRHI = VertexDeclaration.VertexDeclarationRHI;
				GraphicsPSOInit.BoundShaderState.VertexShaderRHI = VertexShader.GetVertexShader();
				GraphicsPSOInit.BoundShaderState.PixelShaderRHI = PixelShader.GetPixelShader();
				SetGraphicsPipelineState(RHIImmCmdList, GraphicsPSOInit);

				RHIImmCmdList.SetViewport(0,0,0.f, RenderTargetRHI->GetSizeX(), RenderTargetRHI->GetSizeY(), 1.f);

				RHIImmCmdList.SetStreamSource(0, CustomRegionVertexBuffer.VertexBufferRHI, 0);
				RHIImmCmdList.DrawIndexedPrimitive(
					CustomRegionIndexBuffer.IndexBufferRHI, 
					/*BaseVertexIndex*/ 0,
					/*MinIndex*/ 0,
					/*NumVertexs*/ nVertexCount,
					/*StartIndex*/ 0,
					/*NumPrimitive*/nIndexCount/3,
					/*NumInstances*/ 1
				);

				RHIImmCmdList.EndRenderPass();

				//SetUniformBufferParameterImmediate(RHIImmCmdList, PixelShader.GetPixelShader(), );

				//VertexShader->Set
			}





			class FRealTimeRasterImageVertexShader : public FCustomTextureGlobalShader
			{
				DECLARE_GLOBAL_SHADER(FRealTimeRasterImageVertexShader)
			public:
				FRealTimeRasterImageVertexShader() 
				{
				
				}
				FRealTimeRasterImageVertexShader(const ShaderMetaType::CompiledShaderInitializerType& Initializer) :FCustomTextureGlobalShader(Initializer)
				{
					transform.Bind(Initializer.ParameterMap, TEXT("transform"));
				}

				/*
				BEGIN_GLOBAL_SHADER_PARAMETER_STRUCT(FSimpleUniformStructParameter, )
					SHADER_PARAMETER(FVector4, transform)
				END_GLOBAL_SHADER_PARAMETER_STRUCT()
				*/

				template <typename TRHIShader>
				void SetParameters(FRHICommandList& RHICmdList, TRHIShader* ShaderRHI, FVector4 imageTransform)
				{
					//FSimpleUniformStructParameter shaderStructData;
					//shaderStructData.transform = transform;

					//SetUniformBufferParameterImmediate(RHICmdList, ShaderRHI, GetUniformBufferParameter<FSimpleUniformStructParameter>(), shaderStructData);

					SetShaderValue(RHICmdList, ShaderRHI, transform, GameVector4(imageTransform));
					
				}

				LAYOUT_FIELD(FShaderParameter, transform);
				
			};

			class FRealTimeRasterImagePixelShader : public FCustomTextureGlobalShader
			{
				DECLARE_GLOBAL_SHADER(FRealTimeRasterImagePixelShader)
			public:
				FRealTimeRasterImagePixelShader() 
				{
					
				}
				FRealTimeRasterImagePixelShader(const ShaderMetaType::CompiledShaderInitializerType& Initializer) :FCustomTextureGlobalShader(Initializer) 
				{
					textureSampler.Bind(Initializer.ParameterMap, TEXT("textureSampler"));
					textureVal.Bind(Initializer.ParameterMap, TEXT("textureVal"));
					colorVal.Bind(Initializer.ParameterMap, TEXT("colorVal"));
				}

				template <typename TRHIShader>
				void SetParameters(FRHICommandList& RHICmdList, TRHIShader* ShaderRHI, const FLinearColor& imageColor, FTexture2DRHIRef InInputTexture)
				{
					SetTextureParameter(RHICmdList, ShaderRHI, textureVal, textureSampler, TStaticSamplerState<SF_Trilinear, AM_Clamp, AM_Clamp, AM_Clamp>::GetRHI(), InInputTexture);

					SetShaderValue(RHICmdList, ShaderRHI, colorVal, imageColor);
				}

				LAYOUT_FIELD(FShaderResourceParameter, textureVal);
				LAYOUT_FIELD(FShaderResourceParameter, textureSampler);
				LAYOUT_FIELD(FShaderParameter, colorVal);
			};

			IMPLEMENT_SHADER_TYPE(, FRealTimeRasterImageVertexShader, TEXT("/SuperMap/TextureTransparen.usf"), TEXT("MainVS"), SF_Vertex);
			IMPLEMENT_SHADER_TYPE(, FRealTimeRasterImagePixelShader, TEXT("/SuperMap/TextureTransparen.usf"), TEXT("MainPS"), SF_Pixel);


			void TextureRenderer::DrawRealtimeRaster(TArray<TArray<FTextureVertex> > Vertexs, TArray<TArray<uint32> >Indices, TArray<FVector4> transform, TArray<Gamelong> textureName, 
				TArray<FVector4> colors, TArray<uint32> orders, UTextureRenderTarget2D* pRenderTarget2D)
			{
				check(IsInGameThread());

				FTextureRenderTargetResource* RenderTargetRHI = pRenderTarget2D->GameThread_GetRenderTargetResource();

				ENQUEUE_RENDER_COMMAND(CaptureCommand)(
					[RenderTargetRHI, Vertexs, Indices, transform, textureName, colors, orders](FRHICommandListImmediate & RHICmdList) {
					TextureRenderer::DrawRealtimeRaster(RHICmdList, Vertexs, Indices, transform, textureName, colors, orders, RenderTargetRHI);
				});

				RealspaceView::GetSingleton()->GetWorld()->SendAllEndOfFrameUpdates();
			}

			void TextureRenderer::DrawRealtimeRaster(FRHICommandListImmediate & RHIImmCmdList, TArray<TArray<FTextureVertex> > Vertexs, TArray<TArray<uint32> > Indices, TArray<FVector4> transform, 
				TArray<Gamelong> textureName, TArray<FVector4> colors, TArray<uint32> orders, FTextureRenderTargetResource* RenderTargetRHI1)
			{
				check(IsInRenderingThread());

				FTexture2DRHIRef RenderTargetRHI = RenderTargetRHI1->GetRenderTargetTexture();

#if !SM_FOR_UE_FIVE
				RHIImmCmdList.TransitionResource(EResourceTransitionAccess::EWritable, RenderTargetRHI);
				FRHIRenderPassInfo RPInfo(RenderTargetRHI, ERenderTargetActions::DontLoad_Store, RenderTargetRHI1->TextureRHI);
#else
				RHIImmCmdList.TransitionResource(ERHIAccess::WritableMask, RenderTargetRHI);
				FRHIRenderPassInfo RPInfo(RenderTargetRHI, ERenderTargetActions::DontLoad_Store);
#endif

				const ERHIFeatureLevel::Type FeatureLevel = GMaxRHIFeatureLevel;
				FGlobalShaderMap* GlobalShaderMap = GetGlobalShaderMap(FeatureLevel);


				FTextureVertexDeclaration VertexDeclaration;
				VertexDeclaration.InitRHI();

				TShaderMapRef<FRealTimeRasterImageVertexShader> VertexShader(GlobalShaderMap);
				TShaderMapRef<FRealTimeRasterImagePixelShader> PixelShader(GlobalShaderMap);

				FGraphicsPipelineStateInitializer GraphicsPSOInit;
				RHIImmCmdList.ApplyCachedRenderTargets(GraphicsPSOInit);
				GraphicsPSOInit.DepthStencilState = TStaticDepthStencilState<false, CF_Always>::GetRHI();
				GraphicsPSOInit.BlendState = TStaticBlendState<CW_RGB, BO_Add, BF_SourceAlpha, BF_InverseSourceAlpha, BO_Add, BF_Zero, BF_One>::GetRHI();
				GraphicsPSOInit.RasterizerState = TStaticRasterizerState<>::GetRHI();
				GraphicsPSOInit.PrimitiveType = PT_TriangleList;
				GraphicsPSOInit.BoundShaderState.VertexDeclarationRHI = VertexDeclaration.VertexDeclarationRHI;
				GraphicsPSOInit.BoundShaderState.VertexShaderRHI = VertexShader.GetVertexShader();
				GraphicsPSOInit.BoundShaderState.PixelShaderRHI = PixelShader.GetPixelShader();

				RHIImmCmdList.SetViewport(0, 0, 0.f, RenderTargetRHI->GetSizeX(), RenderTargetRHI->GetSizeY(), 1.f);

				int32 nImageCount = orders.Num();

				for (int32 i = 0; i < nImageCount; i++)
				{
					
					FRegionVertexBuffer CustomRegionVertexBuffer;

					int32 nVertexCount = Vertexs[orders[i]].Num();

					TResourceArray<FTextureVertex, VERTEXBUFFER_ALIGNMENT> VertexRes;
					VertexRes.SetNumUninitialized(nVertexCount);

					for (int n = 0; n < nVertexCount; n++)
					{
						VertexRes[n].Position = Vertexs[orders[i]][n].Position;
						VertexRes[n].UV = Vertexs[orders[i]][n].UV;
					}



					CustomRegionVertexBuffer.CreateRHI(VertexRes);
					int32 nIndexCount = Indices[orders[i]].Num();

					FRegionIndexBuffer CustomRegionIndexBuffer;
					TResourceArray<uint32, INDEXBUFFER_ALIGNMENT> IndexBuffer;
					IndexBuffer.SetNumUninitialized(nIndexCount);

					for (int n = 0; n < nIndexCount; n++)
					{
						IndexBuffer[n] = Indices[orders[i]][n];
					}

					CustomRegionIndexBuffer.CreateRHI(IndexBuffer);

					RHIImmCmdList.BeginRenderPass(RPInfo, TEXT("TextureTransparen"));
					SetGraphicsPipelineState(RHIImmCmdList, GraphicsPSOInit);

					GameTexture* pGameTexture = GameTextureManager::GetSingleton()->GetTexture(textureName[orders[i]]);
					if (pGameTexture != nullptr && pGameTexture->GetTexture2D() != nullptr)
					{
						UTexture2D* pTexture2D = pGameTexture->GetTexture2D();
#if SM_FOR_UE_25 || SM_FOR_UE_26
						FTextureResource* pResource = pTexture2D->Resource;
#else
						FTextureResource* pResource = pTexture2D->GetResource();
#endif
						if (pResource != nullptr)
						{
							FTexture2DRHIRef TextureRHI = ((FTexture2DResource*)(pResource))->GetTexture2DRHI();

							FLinearColor imageColor;
							imageColor.R = colors[orders[i]].X;
							imageColor.G = colors[orders[i]].Y;
							imageColor.B = colors[orders[i]].Z;
							imageColor.A = colors[orders[i]].W;

							PixelShader->SetParameters(RHIImmCmdList, PixelShader.GetPixelShader(), imageColor, TextureRHI);

							VertexShader->SetParameters(RHIImmCmdList, VertexShader.GetVertexShader(), transform[orders[i]]);
						}
					}

					RHIImmCmdList.SetStreamSource(0, CustomRegionVertexBuffer.VertexBufferRHI, 0);
					RHIImmCmdList.DrawIndexedPrimitive(
						CustomRegionIndexBuffer.IndexBufferRHI,
						0,
						0,
						nVertexCount,
						0,
						nIndexCount / 3,
						1
					);

					RHIImmCmdList.EndRenderPass();
				}

				
				
			}

			class FRealTimeRasterVectorVertexShader : public FCustomTextureGlobalShader
			{
				DECLARE_GLOBAL_SHADER(FRealTimeRasterVectorVertexShader)
			public:
				FRealTimeRasterVectorVertexShader()
				{

				}
				FRealTimeRasterVectorVertexShader(const ShaderMetaType::CompiledShaderInitializerType& Initializer) :FCustomTextureGlobalShader(Initializer)
				{
					transform.Bind(Initializer.ParameterMap, TEXT("transform"));
				}


				template <typename TRHIShader>
				void SetParameters(FRHICommandList& RHICmdList, TRHIShader* ShaderRHI, FVector4 imageTransform)
				{
					SetShaderValue(RHICmdList, ShaderRHI, transform, GameVector4(imageTransform));
				}

				LAYOUT_FIELD(FShaderParameter, transform);

			};

			class FRealTimeRasterVectorPixelShader : public FCustomTextureGlobalShader
			{
				DECLARE_GLOBAL_SHADER(FRealTimeRasterVectorPixelShader)
			public:
				FRealTimeRasterVectorPixelShader()
				{

				}
				FRealTimeRasterVectorPixelShader(const ShaderMetaType::CompiledShaderInitializerType& Initializer) :FCustomTextureGlobalShader(Initializer)
				{
					//textureVal.Bind(Initializer.ParameterMap, TEXT("textureVal"));
					colorVal.Bind(Initializer.ParameterMap, TEXT("colorVal"));
				}

				template <typename TRHIShader>
				void SetParameters(FRHICommandList& RHICmdList, TRHIShader* ShaderRHI, const FLinearColor& vectorColor/*, FTexture2DRHIRef InInputTexture*/)
				{
					//SetTextureParameter(RHICmdList, ShaderRHI, textureVal, textureSampler, TStaticSamplerState<SF_Trilinear, AM_Clamp, AM_Clamp, AM_Clamp>::GetRHI(), InInputTexture);

					SetShaderValue(RHICmdList, ShaderRHI, colorVal, vectorColor);
				}

				//LAYOUT_FIELD(FShaderResourceParameter, textureVal);
				//LAYOUT_FIELD(FShaderResourceParameter, textureSampler);
				LAYOUT_FIELD(FShaderParameter, colorVal);
			};

			IMPLEMENT_SHADER_TYPE(, FRealTimeRasterVectorVertexShader, TEXT("/SuperMap/Vector.usf"), TEXT("MainVS"), SF_Vertex);
			IMPLEMENT_SHADER_TYPE(, FRealTimeRasterVectorPixelShader, TEXT("/SuperMap/Vector.usf"), TEXT("MainPS"), SF_Pixel);

			void TextureRenderer::DrawRealtimeRasterVector(TArray<CustomRealRasterMesh*> meshes, FVector4 transform, TArray<Matrix4d> objectTransform, UTextureRenderTarget2D* pRenderTarget2D, Gamebool bSecondColor)
			{
				check(IsInGameThread());

				FTextureRenderTargetResource* RenderTargetRHI = pRenderTarget2D->GameThread_GetRenderTargetResource();

				ENQUEUE_RENDER_COMMAND(CaptureCommand)(
					[RenderTargetRHI, meshes, transform, objectTransform, bSecondColor](FRHICommandListImmediate & RHICmdList) {
					TextureRenderer::DrawRealtimeRasterVector(RHICmdList, meshes, transform, objectTransform, RenderTargetRHI, bSecondColor);
				});

				RealspaceView::GetSingleton()->GetWorld()->SendAllEndOfFrameUpdates();
			}

			void TextureRenderer::DrawRealtimeRasterVector(FRHICommandListImmediate & RHIImmCmdList, TArray<CustomRealRasterMesh*> meshes, FVector4 transform, TArray<Matrix4d> objectTransform, FTextureRenderTargetResource* RenderTargetRHI1, Gamebool bSecondColor)
			{
				check(IsInRenderingThread());

				FTexture2DRHIRef RenderTargetRHI = RenderTargetRHI1->GetRenderTargetTexture();

#if !SM_FOR_UE_FIVE
				RHIImmCmdList.TransitionResource(EResourceTransitionAccess::EWritable, RenderTargetRHI);
				FRHIRenderPassInfo RPInfo(RenderTargetRHI, ERenderTargetActions::DontLoad_Store, RenderTargetRHI1->TextureRHI);
#else
				RHIImmCmdList.TransitionResource(ERHIAccess::WritableMask, RenderTargetRHI);
				FRHIRenderPassInfo RPInfo(RenderTargetRHI, ERenderTargetActions::DontLoad_Store);
#endif

				const ERHIFeatureLevel::Type FeatureLevel = GMaxRHIFeatureLevel;
				FGlobalShaderMap* GlobalShaderMap = GetGlobalShaderMap(FeatureLevel);


				FVectorVertexDeclaration VertexDeclaration;
				VertexDeclaration.InitRHI();

				TShaderMapRef<FRealTimeRasterVectorVertexShader> VertexShader(GlobalShaderMap);
				TShaderMapRef<FRealTimeRasterVectorPixelShader> PixelShader(GlobalShaderMap);

				FGraphicsPipelineStateInitializer GraphicsPSOInit;
				RHIImmCmdList.ApplyCachedRenderTargets(GraphicsPSOInit);
				GraphicsPSOInit.DepthStencilState = TStaticDepthStencilState<false, CF_Always>::GetRHI();
				if (bSecondColor)
				{
					GraphicsPSOInit.BlendState = TStaticBlendState<>::GetRHI();
				}
				else
				{
					GraphicsPSOInit.BlendState = TStaticBlendState<CW_RGB, BO_Add, BF_SourceAlpha, BF_InverseSourceAlpha, BO_Add, BF_Zero, BF_One>::GetRHI();
				}
				GraphicsPSOInit.RasterizerState = TStaticRasterizerState<>::GetRHI();
				GraphicsPSOInit.PrimitiveType = PT_TriangleList;
				GraphicsPSOInit.BoundShaderState.VertexDeclarationRHI = VertexDeclaration.VertexDeclarationRHI;
				GraphicsPSOInit.BoundShaderState.VertexShaderRHI = VertexShader.GetVertexShader();
				GraphicsPSOInit.BoundShaderState.PixelShaderRHI = PixelShader.GetPixelShader();

				RHIImmCmdList.SetViewport(0, 0, 0.f, RenderTargetRHI->GetSizeX(), RenderTargetRHI->GetSizeY(), 1.f);

				int32 nCount = meshes.Num();
				for (int32 i = 0; i < nCount; i++)
				{
					//mesh
					FSMMesh& mesh = meshes[i]->GetMesh();
					
					//顶点
					int32 nPosCount = mesh.m_pDataVertex->m_nPosCount;
					int32 nPosDim = mesh.m_pDataVertex->m_nPosDim;

					TResourceArray<Gamefloat, VERTEXBUFFER_ALIGNMENT> VertexBuffer;
					VertexBuffer.SetNumUninitialized(nPosCount * nPosDim);
					memcpy(VertexBuffer.GetData(), mesh.m_pDataVertex->m_Pos, nPosCount * nPosDim * sizeof(Gamefloat));

#if !SM_FOR_UE_FIVE
					FRHIResourceCreateInfo CreateVertexInfo(&VertexBuffer);
#else
					TCHAR* InDebugName = TEXT("");
					FRHIResourceCreateInfo CreateVertexInfo(InDebugName, &VertexBuffer);
#endif


					TResourceArray<Gameuint, VERTEXBUFFER_ALIGNMENT> VertexColorBuffer;
					VertexColorBuffer.SetNumUninitialized(nPosCount);

					if (bSecondColor)
					{
						memcpy(VertexColorBuffer.GetData(), mesh.m_pDataVertex->m_PosSceondColor, nPosCount * sizeof(Gameuint));
					}
					else
					{
						memcpy(VertexColorBuffer.GetData(), mesh.m_pDataVertex->m_PosColor, nPosCount * sizeof(Gameuint));
					}
					

#if !SM_FOR_UE_FIVE
					FRHIResourceCreateInfo CreateVertexColorInfo(&VertexColorBuffer);
#else
					FRHIResourceCreateInfo CreateVertexColorInfo(InDebugName, &VertexColorBuffer);
#endif



					FVertexBuffer VectorVertexBuffer;
					VectorVertexBuffer.VertexBufferRHI = RHICreateVertexBuffer(VertexBuffer.GetResourceDataSize(), BUF_Static, CreateVertexInfo);


					FVertexBuffer VectorVertexColorBuffer;
					VectorVertexColorBuffer.VertexBufferRHI = RHICreateVertexBuffer(VertexColorBuffer.GetResourceDataSize(), BUF_Static, CreateVertexColorInfo);

					//索引
					int32 nIndexCount = mesh.m_arrDataIndex[0]->m_nIndexCount;

					FIndexBuffer VectorIndexBuffer;

					if (mesh.m_arrDataIndex[0]->m_Index != nullptr)
					{
						TResourceArray<Gameuint, INDEXBUFFER_ALIGNMENT> IndexBuffer;
						IndexBuffer.SetNumUninitialized(nIndexCount);

						memcpy(IndexBuffer.GetData(), mesh.m_arrDataIndex[0]->m_Index, nIndexCount * sizeof(Gameuint));

#if !SM_FOR_UE_FIVE
						FRHIResourceCreateInfo CreateIndexInfo(&IndexBuffer);
#else
						FRHIResourceCreateInfo CreateIndexInfo(InDebugName, &IndexBuffer);
#endif

						VectorIndexBuffer.IndexBufferRHI = RHICreateIndexBuffer(sizeof(Gameuint), IndexBuffer.GetResourceDataSize(), BUF_Static, CreateIndexInfo);

					}
					else if (mesh.m_arrDataIndex[0]->m_shortIndex != nullptr)
					{
						TResourceArray<Gameushort, INDEXBUFFER_ALIGNMENT> IndexBuffer;
						IndexBuffer.SetNumUninitialized(nIndexCount);

						memcpy(IndexBuffer.GetData(), mesh.m_arrDataIndex[0]->m_shortIndex, nIndexCount * sizeof(Gameushort));

#if !SM_FOR_UE_FIVE
						FRHIResourceCreateInfo CreateInfo(&IndexBuffer);
#else
						FRHIResourceCreateInfo CreateInfo(InDebugName, &IndexBuffer);
#endif

						VectorIndexBuffer.IndexBufferRHI = RHICreateIndexBuffer(sizeof(Gameushort), IndexBuffer.GetResourceDataSize(), BUF_Static, CreateInfo);
					}

					RHIImmCmdList.BeginRenderPass(RPInfo, TEXT("VectorTransparen"));
					SetGraphicsPipelineState(RHIImmCmdList, GraphicsPSOInit);

					FLinearColor vectorColor;
					vectorColor.R = 1.0;
					vectorColor.G = 0.0;
					vectorColor.B = 0.0;
					vectorColor.A = 1.0;

					PixelShader->SetParameters(RHIImmCmdList, PixelShader.GetPixelShader(), vectorColor);

					Vector3d objectTrans = objectTransform[i].GetTrans(); 

					FVector4 realTransform = transform;
					realTransform.X -= objectTrans.X;
					realTransform.Y -= objectTrans.Y;

					VertexShader->SetParameters(RHIImmCmdList, VertexShader.GetVertexShader(), realTransform);

					RHIImmCmdList.SetStreamSource(0, VectorVertexBuffer.VertexBufferRHI, 0);
					RHIImmCmdList.SetStreamSource(1, VectorVertexColorBuffer.VertexBufferRHI, 0);
					
					RHIImmCmdList.DrawIndexedPrimitive(
						VectorIndexBuffer.IndexBufferRHI,
						0,
						0,
						nPosCount,
						0,
						nIndexCount / 3,
						1
					);

					RHIImmCmdList.EndRenderPass();
				}

			}


			class FRealTimeRasterVectorWithTextureVertexShader : public FCustomTextureGlobalShader
			{
				DECLARE_GLOBAL_SHADER(FRealTimeRasterVectorWithTextureVertexShader)
			public:
				FRealTimeRasterVectorWithTextureVertexShader()
				{

				}
				FRealTimeRasterVectorWithTextureVertexShader(const ShaderMetaType::CompiledShaderInitializerType& Initializer) :FCustomTextureGlobalShader(Initializer)
				{
					transform.Bind(Initializer.ParameterMap, TEXT("transform"));
					translation.Bind(Initializer.ParameterMap, TEXT("translation"));
				}


				template <typename TRHIShader>
				void SetParameters(FRHICommandList& RHICmdList, TRHIShader* ShaderRHI, FVector4 meshTransform, FVector4 meshTransform2)
				{
					SetShaderValue(RHICmdList, ShaderRHI, transform, GameVector4(meshTransform));
					SetShaderValue(RHICmdList, ShaderRHI, translation, GameVector4(meshTransform2));
				}

				LAYOUT_FIELD(FShaderParameter, transform);
				LAYOUT_FIELD(FShaderParameter, translation);

			};

			class FRealTimeRasterVectorWithTexturePixelShader : public FCustomTextureGlobalShader
			{
				DECLARE_GLOBAL_SHADER(FRealTimeRasterVectorWithTexturePixelShader)
			public:
				FRealTimeRasterVectorWithTexturePixelShader()
				{

				}
				FRealTimeRasterVectorWithTexturePixelShader(const ShaderMetaType::CompiledShaderInitializerType& Initializer) :FCustomTextureGlobalShader(Initializer)
				{
					textureSampler.Bind(Initializer.ParameterMap, TEXT("textureSampler"));
					textureVal.Bind(Initializer.ParameterMap, TEXT("textureVal"));
					//colorVal.Bind(Initializer.ParameterMap, TEXT("colorVal"));
				}

				template <typename TRHIShader>
				void SetParameters(FRHICommandList& RHICmdList, TRHIShader* ShaderRHI, FTexture2DRHIRef InInputTexture)
				{
					SetTextureParameter(RHICmdList, ShaderRHI, textureVal, textureSampler, TStaticSamplerState<SF_Trilinear, AM_Clamp, AM_Clamp, AM_Clamp>::GetRHI(), InInputTexture);

					//SetShaderValue(RHICmdList, ShaderRHI, colorVal, imageColor);
				}

				LAYOUT_FIELD(FShaderResourceParameter, textureVal);
				LAYOUT_FIELD(FShaderResourceParameter, textureSampler);
				//LAYOUT_FIELD(FShaderParameter, colorVal);
			};

			IMPLEMENT_SHADER_TYPE(, FRealTimeRasterVectorWithTextureVertexShader, TEXT("/SuperMap/VectorWithTexture.usf"), TEXT("MainVS"), SF_Vertex);
			IMPLEMENT_SHADER_TYPE(, FRealTimeRasterVectorWithTexturePixelShader, TEXT("/SuperMap/VectorWithTexture.usf"), TEXT("MainPS"), SF_Pixel);

			void TextureRenderer::DrawRealtimeRasterVectorWithTexture(TArray<CustomRealRasterMesh*> meshes, FVector4 transform, TArray<FVector4> arrTrans,TArray<Matrix4d> texMatrix, TArray<Gamelong> arrGameTexture,UTextureRenderTarget2D* pRenderTarget2D)
			{
				check(IsInGameThread());

				FTextureRenderTargetResource* RenderTargetRHI = pRenderTarget2D->GameThread_GetRenderTargetResource();

				ENQUEUE_RENDER_COMMAND(CaptureCommand)(
					[RenderTargetRHI, meshes, transform, arrTrans, texMatrix, arrGameTexture](FRHICommandListImmediate& RHICmdList) {
						TextureRenderer::DrawRealtimeRasterVectorWithTexture(RHICmdList, meshes,  transform, arrTrans, texMatrix, arrGameTexture, RenderTargetRHI);
					});

				RealspaceView::GetSingleton()->GetWorld()->SendAllEndOfFrameUpdates();
			}

			void TextureRenderer::DrawRealtimeRasterVectorWithTexture(FRHICommandListImmediate& RHIImmCmdList, TArray<CustomRealRasterMesh*> meshes, FVector4 transform, TArray<FVector4> arrTrans,TArray<Matrix4d> texMatrix, TArray<Gamelong> arrGameTexture, FTextureRenderTargetResource* RenderTargetRHI1)
			{
				check(IsInRenderingThread());

				FTexture2DRHIRef RenderTargetRHI = RenderTargetRHI1->GetRenderTargetTexture();

#if !SM_FOR_UE_FIVE
				RHIImmCmdList.TransitionResource(EResourceTransitionAccess::EWritable, RenderTargetRHI);
				FRHIRenderPassInfo RPInfo(RenderTargetRHI, ERenderTargetActions::DontLoad_Store, RenderTargetRHI1->TextureRHI);
#else
				RHIImmCmdList.TransitionResource(ERHIAccess::WritableMask, RenderTargetRHI);
				FRHIRenderPassInfo RPInfo(RenderTargetRHI, ERenderTargetActions::DontLoad_Store);
#endif

				const ERHIFeatureLevel::Type FeatureLevel = GMaxRHIFeatureLevel;
				FGlobalShaderMap* GlobalShaderMap = GetGlobalShaderMap(FeatureLevel);


				FVectorVertexDeclarationWithTexture VertexDeclaration;
				VertexDeclaration.InitRHI();

				TShaderMapRef<FRealTimeRasterVectorWithTextureVertexShader> VertexShader(GlobalShaderMap);
				TShaderMapRef<FRealTimeRasterVectorWithTexturePixelShader> PixelShader(GlobalShaderMap);

				FGraphicsPipelineStateInitializer GraphicsPSOInit;
				RHIImmCmdList.ApplyCachedRenderTargets(GraphicsPSOInit);
				GraphicsPSOInit.DepthStencilState = TStaticDepthStencilState<false, CF_Always>::GetRHI();
				GraphicsPSOInit.BlendState = TStaticBlendState<CW_RGB, BO_Add, BF_SourceAlpha, BF_InverseSourceAlpha, BO_Add, BF_Zero, BF_One>::GetRHI();
				GraphicsPSOInit.RasterizerState = TStaticRasterizerState<>::GetRHI();
				GraphicsPSOInit.PrimitiveType = PT_TriangleList;
				GraphicsPSOInit.BoundShaderState.VertexDeclarationRHI = VertexDeclaration.VertexDeclarationRHI;
				GraphicsPSOInit.BoundShaderState.VertexShaderRHI = VertexShader.GetVertexShader();
				GraphicsPSOInit.BoundShaderState.PixelShaderRHI = PixelShader.GetPixelShader();

				RHIImmCmdList.SetViewport(0, 0, 0.f, RenderTargetRHI->GetSizeX(), RenderTargetRHI->GetSizeY(), 1.f);

				int32 nCount = meshes.Num();

				for (int32 i = 0; i < nCount; i++)
				{
					//mesh
					FSMMesh& mesh = meshes[i]->GetMesh();

					//顶点
					int32 nPosCount = mesh.m_pDataVertex->m_nPosCount;
					int32 nPosDim = mesh.m_pDataVertex->m_nPosDim;

					//纹理坐标
					int32 nTexCoordCount = mesh.m_pDataVertex->m_nTexCoordCount;
					int32 nTexCoordDim = 2;

					TResourceArray<Gamefloat, VERTEXBUFFER_ALIGNMENT> VertexBuffer;
					VertexBuffer.SetNumUninitialized(nPosCount * nPosDim);
					memcpy(VertexBuffer.GetData(), mesh.m_pDataVertex->m_Pos, nPosCount * nPosDim * sizeof(Gamefloat));

#if !SM_FOR_UE_FIVE
					FRHIResourceCreateInfo CreateVertexInfo(&VertexBuffer);
#else
					TCHAR* InDebugName = TEXT("");
					FRHIResourceCreateInfo CreateVertexInfo(InDebugName, &VertexBuffer);
#endif

					TResourceArray<Gamefloat, VERTEXBUFFER_ALIGNMENT> VertexUVBuffer;
					VertexUVBuffer.SetNumUninitialized(nTexCoordCount * nTexCoordDim);
					memcpy(VertexUVBuffer.GetData(), mesh.m_pDataVertex->m_TexCoord, nTexCoordCount*nTexCoordDim * sizeof(Gamefloat));
					

#if !SM_FOR_UE_FIVE
					FRHIResourceCreateInfo CreateVertexUVInfo(&VertexUVBuffer);
#else
					FRHIResourceCreateInfo CreateVertexUVInfo(InDebugName, &VertexUVBuffer);
#endif

					FVertexBuffer VectorVertexBuffer;
					VectorVertexBuffer.VertexBufferRHI = RHICreateVertexBuffer(VertexBuffer.GetResourceDataSize(), BUF_Static, CreateVertexInfo);

					FVertexBuffer VectorVertexUVBuffer;
					VectorVertexUVBuffer.VertexBufferRHI = RHICreateVertexBuffer(VertexUVBuffer.GetResourceDataSize(), BUF_Static, CreateVertexUVInfo);

					//索引
					int32 nIndexCount = mesh.m_arrDataIndex[0]->m_nIndexCount;

					FIndexBuffer VectorIndexBuffer;

					if (mesh.m_arrDataIndex[0]->m_Index != nullptr)
					{
						TResourceArray<Gameuint, INDEXBUFFER_ALIGNMENT> IndexBuffer;
						IndexBuffer.SetNumUninitialized(nIndexCount);

						memcpy(IndexBuffer.GetData(), mesh.m_arrDataIndex[0]->m_Index, nIndexCount * sizeof(Gameuint));

#if !SM_FOR_UE_FIVE
						FRHIResourceCreateInfo CreateIndexInfo(&IndexBuffer);
#else
						FRHIResourceCreateInfo CreateIndexInfo(InDebugName, &IndexBuffer);
#endif

						VectorIndexBuffer.IndexBufferRHI = RHICreateIndexBuffer(sizeof(Gameuint), IndexBuffer.GetResourceDataSize(), BUF_Static, CreateIndexInfo);

					}
					else if (mesh.m_arrDataIndex[0]->m_shortIndex != nullptr)
					{
						TResourceArray<Gameushort, INDEXBUFFER_ALIGNMENT> IndexBuffer;
						IndexBuffer.SetNumUninitialized(nIndexCount);

						memcpy(IndexBuffer.GetData(), mesh.m_arrDataIndex[0]->m_shortIndex, nIndexCount * sizeof(Gameushort));

#if !SM_FOR_UE_FIVE
						FRHIResourceCreateInfo CreateIndexInfo(&IndexBuffer);
#else
						FRHIResourceCreateInfo CreateIndexInfo(InDebugName, &IndexBuffer);
#endif

						VectorIndexBuffer.IndexBufferRHI = RHICreateIndexBuffer(sizeof(Gameushort), IndexBuffer.GetResourceDataSize(), BUF_Static, CreateIndexInfo);
					}
					
					GameTexture* pGameTexture = GameTextureManager::GetSingleton()->GetTexture(arrGameTexture[i]);
					if (pGameTexture != nullptr)
					{
						UTexture2D* pTexture2D = pGameTexture->GetTexture2D();
#if SM_FOR_UE_25 || SM_FOR_UE_26
						FTextureResource* pResource = pTexture2D->Resource;
#else
						FTextureResource* pResource = pTexture2D->GetResource();
#endif
						
						if (pResource != nullptr)
						{
							FTexture2DRHIRef TextureRHI = ((FTexture2DResource*)(pResource))->GetTexture2DRHI();
							PixelShader->SetParameters(RHIImmCmdList, PixelShader.GetPixelShader(), TextureRHI);
						}
					}
					RHIImmCmdList.BeginRenderPass(RPInfo, TEXT("VectorTransparen"));
					SetGraphicsPipelineState(RHIImmCmdList, GraphicsPSOInit);
					
					VertexShader->SetParameters(RHIImmCmdList, VertexShader.GetVertexShader(), transform, arrTrans[i]);

					RHIImmCmdList.SetStreamSource(0, VectorVertexBuffer.VertexBufferRHI, 0);
					RHIImmCmdList.SetStreamSource(1, VectorVertexUVBuffer.VertexBufferRHI, 0);

					RHIImmCmdList.DrawIndexedPrimitive(
						VectorIndexBuffer.IndexBufferRHI,
						0,
						0,
						nPosCount,
						0,
						nIndexCount / 3,
						1
					);

					RHIImmCmdList.EndRenderPass();
				}

			}
		}
	}
}
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif