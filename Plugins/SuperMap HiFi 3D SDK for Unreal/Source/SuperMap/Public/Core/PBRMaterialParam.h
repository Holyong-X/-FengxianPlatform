#pragma once

#include "CoreMinimal.h"

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{

			// 记录颜色因子
			struct PBRFactor4d
			{
				double m_dFactorX;
				double m_dFactorY;
				double m_dFactorZ;
				double m_dFactorW;
			};

			struct PBRFactor3d
			{
				double m_dFactorX;
				double m_dFactorY;
				double m_dFactorZ;
			};

			// 纹理运动参数
			struct UVMotionParameter
			{
				//! \brief U方向的速度
				float m_fSpeedU;
				//! \brief V方向的速度
				float m_fSpeedV;
				//! \brief 周期
				float m_fPeriod;
			};

			struct TextureMotionParam
			{
				//! \brief 纹理平移运动的参数
				UVMotionParameter m_OffsetMotion;
				//! \brief 纹理缩放的参数
				UVMotionParameter m_TilingMotion;
			};

			struct PBRMetallicRough
			{
				//! \brief 物体的基本颜色因子
				PBRFactor4d m_vec4BaseColor;
				//! \brief 物体基本颜色的纹理在纹理数组中的序号
				int32 m_nBaseColorTextureIndex;
				//! \brief 物体基本颜色的纹理坐标在纹理坐标数组中的序号
				int32 m_nBaseColorTextureCoordIndex;
				//! \brief 基色纹理运动的参数对象
				TextureMotionParam m_BaseColorTextureMotion;
				//! \brief 金属度和粗糙性纹理在纹理数组中的序号(R通道存储金属度，G通道存储粗糙度)
				int32 m_nMetallicRoughnessTextureIndex;
				//! \brief 金属度和粗糙性纹理的纹理坐标在数组中的序号
				int32 m_nMetallicRoughnessTextureCoordIndex;
				//! \brief 控制金属性强弱的因子
				float m_fMetallicFactor;
				//! \brief 控制粗糙性强弱的因子
				float m_fRoughnessFactor;
			};

			struct PBRSpecularGlossy
			{
				//! \brief 散射颜色
				PBRFactor4d m_vec4DiffuseFactor;
				//! \brief 镜面光颜色
				PBRFactor3d m_vec3SpecularFactor;
				//! \brief 高光强度
				float m_fGlossinessFactor;
				//! \brief 散射颜色纹理
				char* m_strDiffuseTexture;
				//! \brief 镜面光高光强度纹理，RGB通道存镜面光颜色，A通道存高光强度
				char* m_strSpecularGlossinessTexture;
			};

			// PBR材质
			struct PBRParam
			{
				//! \brief 控制自发光强度的因子
				PBRFactor3d m_vec3EmissiveFactor;
				//! \brief 自发光纹理在纹理数组中的序号 RGB纹理
				int32 m_nEmissiveTextureIndex;
				//! \brief 自发光纹理的纹理坐标在纹理坐标数组中的序号
				int32 m_nEmissiveTextureCoordIndex;
				//! \brief 自发光纹理运动的参数对象
				TextureMotionParam m_EmissiveTextureMotion;
				//! \brief 法线纹理在纹理数组中的序号，物体表面的凹凸细节 float格式RGB纹理
				int32 m_nNormalTextureIndex;
				//! \brief 法线纹理的纹理坐标在纹理坐标数组中的序号
				int32 m_nNormalTextureCoordIndex;
				//! \brief 法线纹理的缩放因子
				float m_fNormalTextureScale;
				//! \brief 遮挡图在纹理数组中的序号，用于物体表面凹凸性对光照的影响，比如缝隙处就暗 float灰度纹理
				int32 m_nOcclusionTextureIndex;
				//! \brief 遮挡图的纹理坐标在纹理坐标数组中的序号
				int32 m_nOcclusionTextureCoordIndex;
				//! \brief 遮挡图的缩放因子
				float m_fOcclusionTextureStrength;
				//! \brief UGAlphaMode
				int32	m_AlphaMode;
				//! \brief 当alphaMode为Mask时，着色器根据这个值和baseColor的Alpha值进行比较决定是否丢弃
				float	m_fAlphaCutoff;
				//! \brief 是否双面渲染
				int32 m_bDoubleSided;

				//! \brief 金属粗糙度模型
				PBRMetallicRough* m_pPBRMetallicRough;

				//! \brief 镜面光高光模型
				PBRSpecularGlossy* m_pPBRSpecularGlossy;
			};
		}
	}
}