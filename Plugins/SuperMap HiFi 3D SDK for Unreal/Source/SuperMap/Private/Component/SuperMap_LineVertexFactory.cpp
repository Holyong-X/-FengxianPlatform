// Copyright Epic Games, Inc. All Rights Reserved.

#include "Component/SuperMap_LineVertexFactory.h"
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

void FSuperMapEdgeLineVertexFactoryShaderParameters::Bind(const FShaderParameterMap& ParameterMap)
{
	LineWidth.Bind(ParameterMap, TEXT("LineWidth"));
}

void FSuperMapEdgeLineVertexFactoryShaderParameters::GetElementShaderBindings(
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
	FSuperMapEdgeLineVertexFactory* pVertexFactory = (FSuperMapEdgeLineVertexFactory*)InVertexFactory;
	//ShaderBindings.Add(Shader->GetUniformBufferParameter<FPointCloudVertexFactoryParameters>(), VertexFactory->GetPointCloudVertexFactoryUniformBuffer());

	auto pVertexBuffer = pVertexFactory->GetVertexBuffer();
	check(pVertexBuffer != nullptr);

	ShaderBindings.Add(LineWidth, pVertexBuffer->m_fLineWidth);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

FSuperMapEdgeLineVertexFactory::FSuperMapEdgeLineVertexFactory(ERHIFeatureLevel::Type InFeatureLevel) :
	FVertexFactory(InFeatureLevel),
	m_pVertexBuffer(nullptr)
{
}

void FSuperMapEdgeLineVertexFactory::SetVertexBuffer(FSuperMapLineVertexBuffer* pVertexBuffer)
{
	m_pVertexBuffer = pVertexBuffer;
}

FSuperMapLineVertexBuffer* FSuperMapEdgeLineVertexFactory::GetVertexBuffer() const
{
	return m_pVertexBuffer;
}

void FSuperMapEdgeLineVertexFactory::InitRHI()
{
	// VertexFactory needs to be able to support max possible shader platform and feature level
	// in case if we switch feature level at runtime.
	const bool bCanUseGPUScene = UseGPUScene(GMaxRHIShaderPlatform, GMaxRHIFeatureLevel);

	FVertexDeclarationElementList Elements;
	Elements.Add(AccessStreamComponent(m_pVertexBuffer->m_SidenessStreamComponent, 0));
	if (m_pVertexBuffer->m_SecondColorStreamComponent.VertexBuffer != NULL)
	{
		Elements.Add(AccessStreamComponent(m_pVertexBuffer->m_SecondColorStreamComponent, 1));
	}
	else
	{
		FVertexStreamComponent NullColorComponent(&GNullColorVertexBuffer, 0, 0, VET_PackedNormal, EVertexStreamUsage::ManualFetch);
		Elements.Add(AccessStreamComponent(NullColorComponent, 1));
	}
	Elements.Add(AccessStreamComponent(m_pVertexBuffer->m_Postion0StreamComponent, 2));
	Elements.Add(AccessStreamComponent(m_pVertexBuffer->m_Postion1StreamComponent, 3));
	Elements.Add(AccessStreamComponent(m_pVertexBuffer->m_FaceNormal0StreamComponent, 4));
	if (m_pVertexBuffer->m_FaceNormal1StreamComponent.VertexBuffer != NULL)
	{
		Elements.Add(AccessStreamComponent(m_pVertexBuffer->m_FaceNormal1StreamComponent, 5));
	}
	else
	{
		FVertexStreamComponent NullColorComponent(&GNullColorVertexBuffer, 0, 0, VET_PackedNormal, EVertexStreamUsage::ManualFetch);
		Elements.Add(AccessStreamComponent(NullColorComponent, 5));
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

	check(Streams.Num() > 0);

	InitDeclaration(Elements);
}

void FSuperMapEdgeLineVertexFactory::ReleaseRHI()
{
	FVertexFactory::ReleaseRHI();
}

bool FSuperMapEdgeLineVertexFactory::ShouldCompilePermutation(const FVertexFactoryShaderPermutationParameters& Parameters)
{
	return true;
}

void FSuperMapEdgeLineVertexFactory::ModifyCompilationEnvironment(const FVertexFactoryShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment)
{
#if SM_FOR_UE_FIVE
	OutEnvironment.SetDefine(TEXT("USE_UE5"), TEXT("1"));
#endif
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

IMPLEMENT_TYPE_LAYOUT(FSuperMapEdgeLineVertexFactoryShaderParameters);

IMPLEMENT_VERTEX_FACTORY_PARAMETER_TYPE(FSuperMapEdgeLineVertexFactory, SF_Vertex, FSuperMapEdgeLineVertexFactoryShaderParameters);
#if SM_FOR_UE_FIVE
IMPLEMENT_VERTEX_FACTORY_TYPE(FSuperMapEdgeLineVertexFactory, "/SuperMap/SuperMapEdgeLineVertexFactory.ush", EVertexFactoryFlags::UsedWithMaterials);
#else
IMPLEMENT_VERTEX_FACTORY_TYPE(FSuperMapEdgeLineVertexFactory, "/SuperMap/SuperMapEdgeLineVertexFactory.ush", true, true, true, false, true);
#endif

 // end SUPERMAP_USE_LOCAL_VERTEX_FACTORY

#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif