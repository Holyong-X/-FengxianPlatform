#pragma once

#include "CoreMinimal.h"
#include "RHI.h"
#include "RenderResource.h"
#include "UniformBuffer.h"
#include "VertexFactory.h"
#include "Component/SuperMap_CustomVertexBuffer.h"

/**
 * Shader parameters for the vector field visualization vertex factory.
 */

 /**
  * Uniform buffer to hold parameters for point cloud rendering
  */
BEGIN_GLOBAL_SHADER_PARAMETER_STRUCT(FSuperMapCustomVertexFactoryParameters, )
SHADER_PARAMETER_SRV(Buffer<float>, VertexFetch_InstanceBuffer)
SHADER_PARAMETER_SRV(Buffer<float>, VertexFetch_InstanceColorBuffer)
END_GLOBAL_SHADER_PARAMETER_STRUCT()
typedef TUniformBufferRef<FSuperMapCustomVertexFactoryParameters> FSuperMapCustomVertexFactoryBufferRef;

class FSuperMapVertexFactoryShaderParameters :
	public FVertexFactoryShaderParameters
{
	DECLARE_TYPE_LAYOUT(FSuperMapVertexFactoryShaderParameters, NonVirtual);
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
	LAYOUT_FIELD(FShaderParameter, TexCoord0Dim);
	LAYOUT_FIELD(FShaderParameter, HasTexMatrixBuffer);
	LAYOUT_FIELD(FShaderParameter, HasVertexWeight);
	LAYOUT_FIELD(FShaderParameter, HasMultiTemporalWeight);
	LAYOUT_FIELD(FShaderParameter, ModelType);
	LAYOUT_FIELD(FShaderParameter, DecodePositionMin);
	LAYOUT_FIELD(FShaderParameter, DecodePositionNormConstant);
	LAYOUT_FIELD(FShaderParameter, DecodeUV0Min);
	LAYOUT_FIELD(FShaderParameter, DecodeUV0NormConstant);
	LAYOUT_FIELD(FShaderResourceParameter, VertexFetch_InstanceBufferParameter);
	LAYOUT_FIELD(FShaderResourceParameter, VertexFetch_InstanceColorBufferParameter)
};

// 定义网格压缩类型
enum MeshCompressType
{
	MC_Default,
	MC_MeshOpt,
	MC_Draco
};

class FSuperMapCustomVertexFactory :
	public FVertexFactory
{
	DECLARE_VERTEX_FACTORY_TYPE(FSuperMapCustomVertexFactory);

public:
	FSuperMapCustomVertexFactory(ERHIFeatureLevel::Type InFeatureLevel);

	virtual ~FSuperMapCustomVertexFactory(){}

	struct CustomMacro
	{
		Gameint m_nHasMultiTemporalWeight = 0;
	};

	void SetCustomVertexBuffer(FSuperMapCustomVertexBuffer* pVertexBuffer);
	void SetCustomMacros(CustomMacro& Macro);
	CustomMacro& GetCustomMacros() { return m_Macro; }

	FSuperMapCustomVertexBuffer* GetVertexBuffer() const;

	inline const FUniformBufferRHIRef GetUniformBuffer() const
	{
		return m_UniformBuffer;
	}

	virtual MeshCompressType GetMeshCompressType() const
	{ return MC_Default; };

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
	FSuperMapCustomVertexBuffer* m_pCustomVertexBuffer;

	/** Buffers to read from */
	FUniformBufferRHIRef m_UniformBuffer;

protected:
	
	CustomMacro m_Macro;
};


class FSuperMapModelInstanceVertexFactory :
	public FSuperMapCustomVertexFactory
{
	DECLARE_VERTEX_FACTORY_TYPE(FSuperMapModelInstanceVertexFactory);
public:
	FSuperMapModelInstanceVertexFactory(ERHIFeatureLevel::Type InFeatureLevel)
		: FSuperMapCustomVertexFactory(InFeatureLevel)
	{}

	static bool ShouldCompilePermutation(const FVertexFactoryShaderPermutationParameters& Parameters);
	static void ModifyCompilationEnvironment(const FVertexFactoryShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment);
};

class FSuperMapPipeInstanceVertexFactory :
	public FSuperMapCustomVertexFactory
{
	DECLARE_VERTEX_FACTORY_TYPE(FSuperMapPipeInstanceVertexFactory);
public:
	FSuperMapPipeInstanceVertexFactory(ERHIFeatureLevel::Type InFeatureLevel)
		: FSuperMapCustomVertexFactory(InFeatureLevel)
	{}

	static bool ShouldCompilePermutation(const FVertexFactoryShaderPermutationParameters& Parameters);
	static void ModifyCompilationEnvironment(const FVertexFactoryShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment);
};


class FSuperMapMeshOptVertexFactory :
	public FSuperMapCustomVertexFactory
{
	DECLARE_VERTEX_FACTORY_TYPE(FSuperMapMeshOptVertexFactory);
public:
	FSuperMapMeshOptVertexFactory(ERHIFeatureLevel::Type InFeatureLevel)
		: FSuperMapCustomVertexFactory(InFeatureLevel)
	{}

	virtual MeshCompressType GetMeshCompressType() const override
	{
		return MC_MeshOpt;
	};

	static bool ShouldCompilePermutation(const FVertexFactoryShaderPermutationParameters& Parameters);
	static void ModifyCompilationEnvironment(const FVertexFactoryShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment);
};

class FSuperMapMeshOptNoTextureCompressVertexFactory :
	public FSuperMapCustomVertexFactory
{
	DECLARE_VERTEX_FACTORY_TYPE(FSuperMapMeshOptNoTextureCompressVertexFactory);
public:
	FSuperMapMeshOptNoTextureCompressVertexFactory(ERHIFeatureLevel::Type InFeatureLevel)
		: FSuperMapCustomVertexFactory(InFeatureLevel)
	{}

	virtual MeshCompressType GetMeshCompressType() const override
	{
		return MC_MeshOpt;
	};

	static bool ShouldCompilePermutation(const FVertexFactoryShaderPermutationParameters& Parameters);
	static void ModifyCompilationEnvironment(const FVertexFactoryShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment);
};

class FSuperMapPloyLineVertexFactory :
	public FSuperMapCustomVertexFactory
{
	DECLARE_VERTEX_FACTORY_TYPE(FSuperMapVertexFactory);
public:
	FSuperMapPloyLineVertexFactory(ERHIFeatureLevel::Type InFeatureLevel)
		: FSuperMapCustomVertexFactory(InFeatureLevel)
	{}

	static bool ShouldCompilePermutation(const FVertexFactoryShaderPermutationParameters& Parameters);
	static void ModifyCompilationEnvironment(const FVertexFactoryShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment);
};