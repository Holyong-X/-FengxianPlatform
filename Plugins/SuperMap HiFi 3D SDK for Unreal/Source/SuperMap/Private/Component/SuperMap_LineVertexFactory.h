#pragma once

#include "CoreMinimal.h"
#include "RHI.h"
#include "RenderResource.h"
#include "UniformBuffer.h"
#include "VertexFactory.h"
#include "Component/SuperMap_LineVertexBuffer.h"

/**
 * Shader parameters for the vector field visualization vertex factory.
 */

class FSuperMapEdgeLineVertexFactoryShaderParameters :
	public FVertexFactoryShaderParameters
{
	DECLARE_TYPE_LAYOUT(FSuperMapEdgeLineVertexFactoryShaderParameters, NonVirtual);
public:
	void Bind(const FShaderParameterMap& ParameterMap);

	void GetElementShaderBindings(
		const class FSceneInterface* Scene,
		const class FSceneView* View,
		const class FMeshMaterialShader* Shader,
		const EVertexInputStreamType InputStreamType,
		ERHIFeatureLevel::Type FeatureLevel,
		const class FVertexFactory* InVertexFactory,
		const struct FMeshBatchElement& BatchElement,
		class FMeshDrawSingleShaderBindings& ShaderBindings,
		FVertexInputStreamArray& VertexStreams) const;

private:
	LAYOUT_FIELD(FShaderParameter, LineWidth);
};

class FSuperMapEdgeLineVertexFactory :
	public FVertexFactory
{
	DECLARE_VERTEX_FACTORY_TYPE(FSuperMapEdgeLineVertexFactory);

public:
	FSuperMapEdgeLineVertexFactory(ERHIFeatureLevel::Type InFeatureLevel);

	virtual ~FSuperMapEdgeLineVertexFactory(){}

	void SetVertexBuffer(FSuperMapLineVertexBuffer* pVertexBuffer);

	FSuperMapLineVertexBuffer* GetVertexBuffer() const;

	/////////////////////////////////////////////////////////////////////////////////////
	// 实现FRenderResource的接口
	/**
	 * Constructs render resources for this vertex factory.
	 */
	virtual void InitRHI() override;

	/**
	 * Release render resources for this vertex factory.
	 */
	virtual void ReleaseRHI() override;

	/**
	 * Should we cache the material's shadertype on this platform with this vertex factory?
	 */
	static bool ShouldCompilePermutation(const FVertexFactoryShaderPermutationParameters& Parameters);

	/**
	* Can be overridden by FVertexFactory subclasses to modify their compile environment just before compilation occurs.
	*/
	static void ModifyCompilationEnvironment(const FVertexFactoryShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment);
private:
	FSuperMapLineVertexBuffer* m_pVertexBuffer;
};
