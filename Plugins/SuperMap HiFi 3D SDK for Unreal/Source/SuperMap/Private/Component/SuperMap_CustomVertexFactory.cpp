// Copyright Epic Games, Inc. All Rights Reserved.

#include "Component/SuperMap_CustomVertexFactory.h"
#include "RHIStaticStates.h"
#include "SceneManagement.h"
#include "EngineGlobals.h"
#include "Engine/Engine.h"
#include "Materials/Material.h"
#include "ShaderParameterUtils.h"
#include "MeshMaterialShader.h"
#include "Graphics3D/GameConvertor.h"

#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif


IMPLEMENT_GLOBAL_SHADER_PARAMETER_STRUCT(FSuperMapCustomVertexFactoryParameters, "CustomMeshVF");

void FSuperMapVertexFactoryShaderParameters::Bind(const FShaderParameterMap& ParameterMap)
{
	TexCoord0Dim.Bind(ParameterMap, TEXT("TexCoord0Dim"));
	HasTexMatrixBuffer.Bind(ParameterMap, TEXT("HasTexMatrixBuffer"));
	ModelType.Bind(ParameterMap, TEXT("ModelType"));
	DecodePositionMin.Bind(ParameterMap, TEXT("DecodePositionMin"));
	DecodePositionNormConstant.Bind(ParameterMap, TEXT("DecodePositionNormConstant"));
	DecodeUV0Min.Bind(ParameterMap, TEXT("DecodeUV0Min"));
	DecodeUV0NormConstant.Bind(ParameterMap, TEXT("DecodeUV0NormConstant"));
	HasVertexWeight.Bind(ParameterMap, TEXT("HasVertexWeight"));
	HasMultiTemporalWeight.Bind(ParameterMap, TEXT("HasMultiTemporalWeight"));
	VertexFetch_InstanceBufferParameter.Bind(ParameterMap, TEXT("VertexFetch_InstanceBuffer"));
	VertexFetch_InstanceColorBufferParameter.Bind(ParameterMap, TEXT("VertexFetch_InstanceColorBuffer"));
}

void FSuperMapVertexFactoryShaderParameters::GetElementShaderBindings(
	const class FSceneInterface* Scene,
	const class FSceneView* View,
	const class FMeshMaterialShader* Shader,
	const EVertexInputStreamType InputStreamType,
	ERHIFeatureLevel::Type FeatureLevel,
	const class FVertexFactory* InVertexFactory,
	const struct FMeshBatchElement& BatchElement,
	class FMeshDrawSingleShaderBindings& ShaderBindings,
	FVertexInputStreamArray& VertexStreams) const
{
	FSuperMapCustomVertexFactory* pVertexFactory = (FSuperMapCustomVertexFactory*)InVertexFactory;
	//ShaderBindings.Add(Shader->GetUniformBufferParameter<FPointCloudVertexFactoryParameters>(), VertexFactory->GetPointCloudVertexFactoryUniformBuffer());
	FSuperMapCustomVertexFactory::CustomMacro& Macro = pVertexFactory->GetCustomMacros();
	auto pVertexBuffer = pVertexFactory->GetVertexBuffer();
	check(pVertexBuffer != nullptr);

	ShaderBindings.Add(TexCoord0Dim, pVertexBuffer->m_nTexCoord0Dim);
	ShaderBindings.Add(HasTexMatrixBuffer, pVertexBuffer->m_nHasTexMatrixBuffer);
	ShaderBindings.Add(HasVertexWeight, pVertexBuffer->m_nHasVertexWeight);
	ShaderBindings.Add(HasMultiTemporalWeight, Macro.m_nHasMultiTemporalWeight);
	ShaderBindings.Add(ModelType, 0);

	ShaderBindings.Add(DecodePositionMin, GameVector4(pVertexBuffer->m_decodePositionMin));
	ShaderBindings.Add(DecodePositionNormConstant, pVertexBuffer->m_decodePositionNormConstant);
	ShaderBindings.Add(DecodeUV0Min, GameVector2(pVertexBuffer->m_decodeTexCoord0Min));
	ShaderBindings.Add(DecodeUV0NormConstant, GameVector2(pVertexBuffer->m_texCoord0CompressConstant));

	ShaderBindings.Add(VertexFetch_InstanceBufferParameter, pVertexBuffer->m_InstanceSRV);
	ShaderBindings.Add(VertexFetch_InstanceColorBufferParameter, pVertexBuffer->m_InstanceColorSRV);
	if (pVertexFactory->GetUniformBuffer().IsValid())
	{
		ShaderBindings.Add(Shader->GetUniformBufferParameter<FSuperMapCustomVertexFactoryParameters>(), pVertexFactory->GetUniformBuffer());
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

FSuperMapCustomVertexFactory::FSuperMapCustomVertexFactory(ERHIFeatureLevel::Type InFeatureLevel) : 
	FVertexFactory(InFeatureLevel),
	m_pCustomVertexBuffer(nullptr)
{
}

void FSuperMapCustomVertexFactory::SetCustomVertexBuffer(FSuperMapCustomVertexBuffer* pVertexBuffer)
{
	m_pCustomVertexBuffer = pVertexBuffer;
}

void FSuperMapCustomVertexFactory::SetCustomMacros(CustomMacro& Macro)
{
	m_Macro.m_nHasMultiTemporalWeight = Macro.m_nHasMultiTemporalWeight;
}

FSuperMapCustomVertexBuffer* FSuperMapCustomVertexFactory::GetVertexBuffer() const
{
	return m_pCustomVertexBuffer;
}

void FSuperMapCustomVertexFactory::InitRHI()
{
	// VertexFactory needs to be able to support max possible shader platform and feature level
	// in case if we switch feature level at runtime.
	const bool bCanUseGPUScene = UseGPUScene(GMaxRHIShaderPlatform, GMaxRHIFeatureLevel);

	FVertexDeclarationElementList Elements;
	if (m_pCustomVertexBuffer->m_PostionStreamComponent.VertexBuffer != NULL)
	{
		Elements.Add(AccessStreamComponent(m_pCustomVertexBuffer->m_PostionStreamComponent, 0));
	}

	{
#if SM_FOR_UE_FIVE
		SetPrimitiveIdStreamIndex(ERHIFeatureLevel::Num, EVertexInputStreamType::Default, -1);
#else
		const uint8 Index = static_cast<uint8>(EVertexInputStreamType::Default);
		PrimitiveIdStreamIndex[Index] = -1;
#endif
		if (GetType()->SupportsPrimitiveIdStream() && bCanUseGPUScene)
		{
			// When the VF is used for rendering in normal mesh passes, this vertex buffer and offset will be overridden
			Elements.Add(AccessStreamComponent(FVertexStreamComponent(&GPrimitiveIdDummy, 0, 0, sizeof(uint32), VET_UInt, EVertexStreamUsage::Instancing), 13));
#if SM_FOR_UE_FIVE
			SetPrimitiveIdStreamIndex(ERHIFeatureLevel::Num, EVertexInputStreamType::Default, Elements.Last().StreamIndex);
#else
			PrimitiveIdStreamIndex[Index] = Elements.Last().StreamIndex;
#endif
		}
	}

	// only tangent,normal are used by the stream. the binormal is derived in the shader
	if (m_pCustomVertexBuffer->m_pTangentStreamComponent.VertexBuffer != NULL)
	{
		Elements.Add(AccessStreamComponent(m_pCustomVertexBuffer->m_pTangentStreamComponent, 1));
	}
	else
	{
		FVertexStreamComponent NullColorComponent(&GNullColorVertexBuffer, 0, 0, VET_PackedNormal, EVertexStreamUsage::ManualFetch);
		Elements.Add(AccessStreamComponent(NullColorComponent, 1));
	}

	if (m_pCustomVertexBuffer->m_pNormalStreamComponent.VertexBuffer != NULL)
	{
		Elements.Add(AccessStreamComponent(m_pCustomVertexBuffer->m_pNormalStreamComponent, 2));
	}
	else
	{
		FVertexStreamComponent NullColorComponent(&GNullColorVertexBuffer, 0, 0, VET_PackedNormal, EVertexStreamUsage::ManualFetch);
		Elements.Add(AccessStreamComponent(NullColorComponent, 2));
	}

	if (m_pCustomVertexBuffer->m_pVertexColorStreamComponent.VertexBuffer)
	{
		Elements.Add(AccessStreamComponent(m_pCustomVertexBuffer->m_pVertexColorStreamComponent, 3));
	}
	else
	{
		//If the mesh has no color component, set the null color buffer on a new stream with a stride of 0.
		//This wastes 4 bytes of bandwidth per vertex, but prevents having to compile out twice the number of vertex factories.
		FVertexStreamComponent NullColorComponent(&GNullColorVertexBuffer, 0, 0, VET_Color, EVertexStreamUsage::ManualFetch);
		Elements.Add(AccessStreamComponent(NullColorComponent, 3));
	}

	if (m_pCustomVertexBuffer->m_pSecondColorStreamComponent.VertexBuffer)
	{
		Elements.Add(AccessStreamComponent(m_pCustomVertexBuffer->m_pSecondColorStreamComponent, 4));
	}
	else
	{
		//If the mesh has no color component, set the null color buffer on a new stream with a stride of 0.
		//This wastes 4 bytes of bandwidth per vertex, but prevents having to compile out twice the number of vertex factories.
		FVertexStreamComponent NullColorComponent(&GNullColorVertexBuffer, 0, 0, VET_Color, EVertexStreamUsage::ManualFetch);
		Elements.Add(AccessStreamComponent(NullColorComponent, 4));
	}


	if (m_pCustomVertexBuffer->m_pTexCoord0StreamComponent.VertexBuffer != NULL)
	{
		Elements.Add(AccessStreamComponent(m_pCustomVertexBuffer->m_pTexCoord0StreamComponent, 5));
	}
	else
	{
		FVertexStreamComponent NullColorComponent(&GNullColorVertexBuffer, 0, 0, VET_Float4, EVertexStreamUsage::ManualFetch);
		Elements.Add(AccessStreamComponent(NullColorComponent, 5));
	}

	if (m_pCustomVertexBuffer->m_pTexCoord1StreamComponent.VertexBuffer != NULL)
	{
		Elements.Add(AccessStreamComponent(m_pCustomVertexBuffer->m_pTexCoord1StreamComponent, 6));
	}
	else
	{
		FVertexStreamComponent NullColorComponent(&GNullColorVertexBuffer, 0, 0, VET_Float4, EVertexStreamUsage::ManualFetch);
		Elements.Add(AccessStreamComponent(NullColorComponent, 6));
	}

	if (m_pCustomVertexBuffer->m_pTexMatrixStreamComponent.VertexBuffer != NULL)
	{
		Elements.Add(AccessStreamComponent(m_pCustomVertexBuffer->m_pTexMatrixStreamComponent, 7));
	}
	else
	{
		FVertexStreamComponent NullColorComponent(&GNullColorVertexBuffer, 0, 0, VET_Float4, EVertexStreamUsage::ManualFetch);
		Elements.Add(AccessStreamComponent(NullColorComponent, 7));
	}

	if (m_pCustomVertexBuffer->m_pVertexWeightStreamComponent.VertexBuffer != NULL)
	{
		Elements.Add(AccessStreamComponent(m_pCustomVertexBuffer->m_pVertexWeightStreamComponent, 8));
	}
	else
	{
		FVertexStreamComponent NullColorComponent(&GNullColorVertexBuffer, 0, 0, VET_Float1, EVertexStreamUsage::ManualFetch);
		Elements.Add(AccessStreamComponent(NullColorComponent, 8));
	}

	if (m_pCustomVertexBuffer->m_pTilingTexCoordStreamComponent.VertexBuffer != NULL)
	{
		Elements.Add(AccessStreamComponent(m_pCustomVertexBuffer->m_pTilingTexCoordStreamComponent, 9));
	}
	else
	{
		FVertexStreamComponent NullColorComponent(&GNullColorVertexBuffer, 0, 0, VET_Float1, EVertexStreamUsage::ManualFetch);
		Elements.Add(AccessStreamComponent(NullColorComponent, 9));
	}

	if (m_pCustomVertexBuffer->m_InstanceSRV.IsValid())
	{
		FSuperMapCustomVertexFactoryParameters uniformParameters;
		uniformParameters.VertexFetch_InstanceBuffer = m_pCustomVertexBuffer->m_InstanceSRV;
		uniformParameters.VertexFetch_InstanceColorBuffer = m_pCustomVertexBuffer->m_InstanceColorSRV;
		m_UniformBuffer = FSuperMapCustomVertexFactoryBufferRef::CreateUniformBufferImmediate(uniformParameters, UniformBuffer_MultiFrame);
	}

	check(Streams.Num() > 0);

	InitDeclaration(Elements);
}

void FSuperMapCustomVertexFactory::ReleaseRHI()
{
	m_UniformBuffer.SafeRelease();
	FVertexFactory::ReleaseRHI();
}

bool FSuperMapCustomVertexFactory::ShouldCompilePermutation(const FVertexFactoryShaderPermutationParameters& Parameters)
{
	return true;
}

void FSuperMapCustomVertexFactory::ModifyCompilationEnvironment(const FVertexFactoryShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment)
{

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool FSuperMapModelInstanceVertexFactory::ShouldCompilePermutation(const FVertexFactoryShaderPermutationParameters& Parameters)
{
	return FSuperMapCustomVertexFactory::ShouldCompilePermutation(Parameters);
}

void FSuperMapModelInstanceVertexFactory::ModifyCompilationEnvironment(const FVertexFactoryShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment)
{
	FSuperMapCustomVertexFactory::ModifyCompilationEnvironment(Parameters, OutEnvironment);
	OutEnvironment.SetDefine(TEXT("INSTANCE_TYPE"), TEXT("1"));
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool FSuperMapPipeInstanceVertexFactory::ShouldCompilePermutation(const FVertexFactoryShaderPermutationParameters& Parameters)
{
	return FSuperMapCustomVertexFactory::ShouldCompilePermutation(Parameters);
}

void FSuperMapPipeInstanceVertexFactory::ModifyCompilationEnvironment(const FVertexFactoryShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment)
{
	FSuperMapCustomVertexFactory::ModifyCompilationEnvironment(Parameters, OutEnvironment);
	OutEnvironment.SetDefine(TEXT("INSTANCE_TYPE"), TEXT("2"));
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool FSuperMapMeshOptVertexFactory::ShouldCompilePermutation(const FVertexFactoryShaderPermutationParameters& Parameters)
{
	return FSuperMapCustomVertexFactory::ShouldCompilePermutation(Parameters);
}

void FSuperMapMeshOptVertexFactory::ModifyCompilationEnvironment(const FVertexFactoryShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment)
{
	FSuperMapCustomVertexFactory::ModifyCompilationEnvironment(Parameters, OutEnvironment);
	OutEnvironment.SetDefine(TEXT("MESH_OPT"), TEXT("1"));
	OutEnvironment.SetDefine(TEXT("TEXTURE_COMPRESS"), TEXT("1"));
}

bool FSuperMapMeshOptNoTextureCompressVertexFactory::ShouldCompilePermutation(const FVertexFactoryShaderPermutationParameters& Parameters)
{
	return FSuperMapCustomVertexFactory::ShouldCompilePermutation(Parameters);
}

void FSuperMapMeshOptNoTextureCompressVertexFactory::ModifyCompilationEnvironment(const FVertexFactoryShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment)
{
	FSuperMapCustomVertexFactory::ModifyCompilationEnvironment(Parameters, OutEnvironment);
	OutEnvironment.SetDefine(TEXT("MESH_OPT"), TEXT("1"));
	OutEnvironment.SetDefine(TEXT("TEXTURE_COMPRESS"), TEXT("0"));
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool FSuperMapPloyLineVertexFactory::ShouldCompilePermutation(const FVertexFactoryShaderPermutationParameters& Parameters)
{
	return FSuperMapCustomVertexFactory::ShouldCompilePermutation(Parameters);
}

void FSuperMapPloyLineVertexFactory::ModifyCompilationEnvironment(const FVertexFactoryShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment)
{
#if SM_FOR_UE_FIVE
	OutEnvironment.SetDefine(TEXT("USE_UE5"), TEXT("1"));
#endif
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

IMPLEMENT_TYPE_LAYOUT(FSuperMapVertexFactoryShaderParameters);

IMPLEMENT_VERTEX_FACTORY_PARAMETER_TYPE(FSuperMapCustomVertexFactory, SF_Vertex, FSuperMapVertexFactoryShaderParameters);
#if SM_FOR_UE_FIVE_1
IMPLEMENT_VERTEX_FACTORY_TYPE(FSuperMapCustomVertexFactory, "/SuperMap/SuperMapCustomVertexFactory5_1.ush", EVertexFactoryFlags::UsedWithMaterials);
#elif SM_FOR_UE_FIVE
IMPLEMENT_VERTEX_FACTORY_TYPE(FSuperMapCustomVertexFactory, "/SuperMap/SuperMapCustomVertexFactory5.ush", EVertexFactoryFlags::UsedWithMaterials);
#else
IMPLEMENT_VERTEX_FACTORY_TYPE(FSuperMapCustomVertexFactory, "/SuperMap/SuperMapCustomVertexFactory4.ush", true, true, true, false, true);
#endif

IMPLEMENT_VERTEX_FACTORY_PARAMETER_TYPE(FSuperMapModelInstanceVertexFactory, SF_Vertex, FSuperMapVertexFactoryShaderParameters);
#if SM_FOR_UE_FIVE_1
IMPLEMENT_VERTEX_FACTORY_TYPE(FSuperMapModelInstanceVertexFactory, "/SuperMap/SuperMapCustomVertexFactory5_1.ush", EVertexFactoryFlags::UsedWithMaterials);
#elif SM_FOR_UE_FIVE
IMPLEMENT_VERTEX_FACTORY_TYPE(FSuperMapModelInstanceVertexFactory, "/SuperMap/SuperMapCustomVertexFactory5.ush", EVertexFactoryFlags::UsedWithMaterials);
#else
IMPLEMENT_VERTEX_FACTORY_TYPE(FSuperMapModelInstanceVertexFactory, "/SuperMap/SuperMapCustomVertexFactory4.ush", true, true, true, false, true);
#endif

IMPLEMENT_VERTEX_FACTORY_PARAMETER_TYPE(FSuperMapPipeInstanceVertexFactory, SF_Vertex, FSuperMapVertexFactoryShaderParameters);
#if SM_FOR_UE_FIVE_1
IMPLEMENT_VERTEX_FACTORY_TYPE(FSuperMapPipeInstanceVertexFactory, "/SuperMap/SuperMapCustomVertexFactory5_1.ush", EVertexFactoryFlags::UsedWithMaterials);
#elif SM_FOR_UE_FIVE
IMPLEMENT_VERTEX_FACTORY_TYPE(FSuperMapPipeInstanceVertexFactory, "/SuperMap/SuperMapCustomVertexFactory5.ush", EVertexFactoryFlags::UsedWithMaterials);
#else
IMPLEMENT_VERTEX_FACTORY_TYPE(FSuperMapPipeInstanceVertexFactory, "/SuperMap/SuperMapCustomVertexFactory4.ush", true, true, true, false, true);
#endif


IMPLEMENT_VERTEX_FACTORY_PARAMETER_TYPE(FSuperMapMeshOptVertexFactory, SF_Vertex, FSuperMapVertexFactoryShaderParameters);
#if SM_FOR_UE_FIVE_1
IMPLEMENT_VERTEX_FACTORY_TYPE(FSuperMapMeshOptVertexFactory, "/SuperMap/SuperMapCustomVertexFactory5_1.ush", EVertexFactoryFlags::UsedWithMaterials);
#elif SM_FOR_UE_FIVE
IMPLEMENT_VERTEX_FACTORY_TYPE(FSuperMapMeshOptVertexFactory, "/SuperMap/SuperMapCustomVertexFactory5.ush", EVertexFactoryFlags::UsedWithMaterials);
#else
IMPLEMENT_VERTEX_FACTORY_TYPE(FSuperMapMeshOptVertexFactory, "/SuperMap/SuperMapCustomVertexFactory4.ush", true, true, true, false, true);
#endif
IMPLEMENT_VERTEX_FACTORY_PARAMETER_TYPE(FSuperMapMeshOptNoTextureCompressVertexFactory, SF_Vertex, FSuperMapVertexFactoryShaderParameters);
#if SM_FOR_UE_FIVE_1
IMPLEMENT_VERTEX_FACTORY_TYPE(FSuperMapMeshOptNoTextureCompressVertexFactory, "/SuperMap/SuperMapCustomVertexFactory5_1.ush", EVertexFactoryFlags::UsedWithMaterials);
#elif SM_FOR_UE_FIVE
IMPLEMENT_VERTEX_FACTORY_TYPE(FSuperMapMeshOptNoTextureCompressVertexFactory, "/SuperMap/SuperMapCustomVertexFactory5.ush", EVertexFactoryFlags::UsedWithMaterials);
#else
IMPLEMENT_VERTEX_FACTORY_TYPE(FSuperMapMeshOptNoTextureCompressVertexFactory, "/SuperMap/SuperMapCustomVertexFactory4.ush", true, true, true, false, true);
#endif

// PolyLine
IMPLEMENT_VERTEX_FACTORY_PARAMETER_TYPE(FSuperMapPloyLineVertexFactory, SF_Vertex, FSuperMapVertexFactoryShaderParameters);
//SuperMapPolyLineVertexFactory
#if SM_FOR_UE_FIVE
IMPLEMENT_VERTEX_FACTORY_TYPE(FSuperMapPloyLineVertexFactory, "/SuperMap/SuperMapPolyLineVertexFactory.ush", EVertexFactoryFlags::UsedWithMaterials);
#else
IMPLEMENT_VERTEX_FACTORY_TYPE(FSuperMapPloyLineVertexFactory, "/SuperMap/SuperMapPolyLineVertexFactory.ush", true, true, true, false, true);
#endif


#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif