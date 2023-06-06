#pragma once
//#if (!SM_FOR_UE_FIVE && WITH_EDITOR)
#ifdef BUILD_EDITOR
#include "Engine.h"
#include "MaterialPropertyEx.h"
#include "DataExchange/MeshData.h"
#include "DataExchange/MaterialUtility.h"
#include "Base3D/CommonDefine.h"

using namespace SuperMapSDK;
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace DataExchange
		{
			enum SUPERMAP_API ChannelType
			{
				R = 1 << 0,
				G = 1 << 1,
				B = 1 << 2,
				A = 1 << 3,
				RGB = R | G | B,
				RGBA = R | G | B | A
			};

			struct SUPERMAP_API TexMappingData
			{
			public:
				Gamechar* texName;
				Gameint width;
				Gameint height;
				Gameuchar* texData;
				Gameint coordIndex;
				Gamefloat* transForm;
				Gamevoid* otherData;
				TexMappingData() :texName(nullptr), width(0), height(0), texData(nullptr), coordIndex(0), otherData(nullptr)
				{
					transForm = new Gamefloat[5]{ 0,0,1,1,0 };
				};
				~TexMappingData();
			};
			struct SUPERMAP_API MaterialData
			{
			public:
				wchar_t* name;
				Gameint alphaMode;//0: Unknown 1: Opcity  2: Mask  3: Blend
				Gamefloat alphaCutOff;
				TexMappingData* baseTexMap;
				Gamefloat* baseColorFactor;
				TexMappingData* MetallicRoughMap;
				Gamefloat metallicFactor;
				Gamefloat RoughnessFactor;
				TexMappingData* OcclusionMap;
				TexMappingData* EmissionMap;
				Gamefloat* EmissionFactor;
				TexMappingData* NormalMap;
				Gamefloat* BaseTex_matrix;//基础纹理
				Gamefloat* MetallicRough_matrix;//金属粗糙度
				Gamefloat* Occlusion_matrix;//遮挡
				Gamefloat* Emission_matrix;//自发光
				Gamefloat* Normal_matrix;//法线贴图
				MaterialData() :name(nullptr), alphaMode(0), alphaCutOff(0.0f), baseTexMap(nullptr), baseColorFactor(nullptr), MetallicRoughMap(nullptr), \
					metallicFactor(1.0f), RoughnessFactor(1.0f), OcclusionMap(nullptr), EmissionMap(nullptr), EmissionFactor(nullptr), NormalMap(nullptr), \
					BaseTex_matrix(nullptr), MetallicRough_matrix(nullptr), Occlusion_matrix(nullptr), Emission_matrix(nullptr), Normal_matrix(nullptr) {};
				~MaterialData();
			};

			struct SUPERMAP_API UVArray
			{
				Gamefloat* m_pTexCoord;
				Gameint m_nTexCoordCount;
				Gameint m_nTexCoordDim;
				Gameint m_nUVChannel;
				UVArray() :m_pTexCoord(nullptr), m_nTexCoordCount(0), m_nTexCoordDim(2), m_nUVChannel(0) {};
				~UVArray();
			};

			struct SUPERMAP_API SubMeshData
			{
				//顶点
				Gamefloat* m_pPos;
				Gameint m_nPosCount;
				Gameint m_nPosDim;

				//索引
				Gameint* m_pIndices;
				Gameint m_nIndexCount;

				//法线
				Gamefloat* m_pNormals;
				Gameint m_nNormalCount;
				Gameint m_nNormalDim;

				//顶点颜色
				Gameint* m_pPosColor;
				Gameint m_nColorCount;

				//纹理坐标
				UVArray* m_pUVs;
				Gameint m_nUVArrCount;

				Gamechar* mtlName;
				MaterialData* mtlData;
				SubMeshData() :m_pPos(nullptr), m_nPosCount(0), m_nPosDim(3), m_pIndices(nullptr), m_nIndexCount(0),
					m_pNormals(nullptr), m_nNormalCount(0), m_nNormalDim(3), m_pPosColor(nullptr), m_nColorCount(0),
					m_pUVs(nullptr), m_nUVArrCount(0), mtlName(nullptr), mtlData(nullptr) {};
				~SubMeshData();
			};

			struct SUPERMAP_API MeshData
			{
			public:
				Gamechar* m_strName;
				//索引
				SubMeshData* subMeshData;
				Gameint subMeshCount;

				//模型变换矩阵
				Gamefloat* m_ObjectMat;
				MeshData() :m_strName(nullptr), subMeshData(nullptr), \
					subMeshCount(0), m_ObjectMat(nullptr) {};
				~MeshData();
			};

			class SUPERMAP_API FMaterialConverter//构建MtlData,不改变其他成员
			{
				enum class E_ShadingModel
				{
					None = -1,
					Default,
					Unlit,
					ClearCoat
				};
			public:
				FMaterialConverter(MaterialData*& mtlData, UMaterialInterface* mat, FUeMeshData* meshData, TArray<Gameint> SecIndices)
					: mMtlData(mtlData), mMaterial(mat), mMeshData(meshData), SectionIndices(SecIndices) {}
				Gamevoid DoWork();
				Gamevoid SetMtlData(MaterialData* mtlData) { mMtlData = mtlData; };
				Gamevoid ConvertAlphaMode(Gameint& outAlphaMode);
				Gamevoid ConvertShadingModel(E_ShadingModel& outShadingModel);

				static Gamevoid ConvertColor(const FLinearColor& Value, Gamefloat*& OutValue, Gamebool bForceLDR);

				Gamefloat* TryGetConstantColor(const FMaterialPropertyEx& Property);
				Gamebool TryGetConstantColor(FLinearColor& OutValue, const FMaterialPropertyEx& Property);
				Gamebool TryGetConstantScalar(Gamefloat& OutValue, const FMaterialPropertyEx& Property)const;

				TexMappingData* TryGetSourceTexture(const FMaterialPropertyEx& Property, const TArray<FLinearColor>& AllowedMasks);
				Gamebool TryGetSourceTexture(const UTexture2D*& OutTexture, Gameint& OutTexCoord, Gamefloat*& OutTransform, \
					const FMaterialPropertyEx& Property, const TArray<FLinearColor>& AllowedMasks);

				Gamebool TryGetBakedMaterialPropertyF4(TexMappingData*& TexData, Gamefloat* &colorFactor, const FMaterialPropertyEx& Property, const FString& PropertyName);
				Gamebool TryGetBakedMaterialPropertyF(TexMappingData*& TexData, Gamefloat &colorFactor, const FMaterialPropertyEx& Property, const FString& PropertyName);
				Gamebool TryGetBakedMaterialProperty(TexMappingData*& TexData, const FMaterialPropertyEx& Property, const FString& PropertyName, Gamebool bTransformToLinear = false);
				Gamebool TryGetBaseColorAndOpacity(TexMappingData*& baseTexData, Gamefloat*& baseColorFactor, const FMaterialPropertyEx& BaseColorProperty, const FMaterialPropertyEx& OpacityProperty);
				Gamebool TryGetMetallicAndRoughness(TexMappingData*& MetRouTexData, Gamefloat& metFactor, Gamefloat& rouFactor, const FMaterialPropertyEx& MetallicProperty, const FMaterialPropertyEx& RoughnessProperty);
				Gamebool TryGetEmissive(MaterialData*& mtlData, const FMaterialPropertyEx& EmissiveProperty);
				Gamebool IsPropertyNonDefault(const FMaterialPropertyEx& Property) const;


				FPropBakeOutput BakeMaterialProperty(const FMaterialPropertyEx& Property, Gameint& OutTexCoord, Gamebool bFillAlpha = true);

				Gamevoid Tex2DToTexMappingData(UTexture2D* tex2D, TexMappingData* &texMapData, \
					ChannelType orgType = ChannelType::RGBA, ChannelType desType = ChannelType::RGBA, FIntPoint texSize = FIntPoint::ZeroValue);

				Gamebool BakedPixelsToTexMappingData(FPropBakeOutput& bakeData, TexMappingData* &texMapData, const FString& PropertyName);

				FString GetMaterialName() const;
				FString GetBakedTexName(const FString& PropertyName) const;
			private:
				MaterialData* mMtlData;
				const UMaterialInterface* mMaterial;
				const FUeMeshData* mMeshData;
				TArray<Gameint> SectionIndices;

				TSet<FMaterialPropertyEx> MeshDataBakedProperties;
			};
		}
	}
}
#endif