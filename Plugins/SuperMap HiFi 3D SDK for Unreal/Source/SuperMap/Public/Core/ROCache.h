#pragma once

#include "CoreMinimal.h"
#include "Core/PBRMaterialParam.h"
#include "Graphics3D/GameStruct.h"

class UMaterialInstanceDynamic;
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			struct DataSubTexture
			{
				int32 m_nOffsetX;
				int32 m_nOffsetY;
				int32 m_nWidth;
				int32 m_nHeight;
				char* m_pByte;
			};

			struct DataTexture
			{
			public:
				char*   m_pByte;
				int32     m_nSize;
				__int64 m_nHashCode;
				int32   m_nDepth;
				int32     m_nComp;
				int32     m_nWidth;
				int32     m_nHeight;

				int32     m_nTextureFormat;

				// 纹理UGC层像素格式
				int32     m_nPixelFormat;

				int32	  m_nSubTexure;
				DataSubTexture*** m_pSubTexture;
			};

			struct ROTexture
			{
			public:
				__int64 m_strTextureName;

				DataTexture* m_pTexture;
			};

			struct ROMaterial
			{
			public:
				char* m_strRealMaterialName;
				__int64 m_strMaterialName;

				__int64 m_strTextureName;
				__int64 m_strTextureName1;
				__int64 m_strTextureName2;
				__int64 m_strTextureName3;

				// 纹理矩阵
				float* m_pTexTransform;
				float* m_pTexTransform1;
				float* m_pTexTransform2;
				float* m_pTexTransform3;

				// 着色器 Shader
				char* m_strShaderName;

				int m_nDataType;

				// 子纹理个数
				int m_nBatchSize;

				// BatchTextureIndex
				int m_nBatchTextureIndex;

				// 选中对象的个数
				int m_nBatchTexSize;

				// PBR材质参数
				PBRParam* m_pPBRParam;

				// 法线纹理下标
				int m_nNormalTexIndex;

				// 材质颜色
				float m_fDiffuseR;
				float m_fDiffuseG;
				float m_fDiffuseB;
				float m_fDiffuseA;

				//! \brief TIN地形的层级
				int m_nGlobalTinLevel;

				//! \brief TIN地形的平移矩阵
				double* m_pGlobalTinTran;
			};

			struct ROEntity
			{
			public:
				// 父节点名字
				char* m_strParentNodeName;
				// 节点名字
				char* m_strName;
				// 可见性
				int32 m_bVisible;

				// 绘制方式
				int32 m_OperationType;

				// 数据包
				DataVertex* m_pDataVertex;

				// 索引包数目
				unsigned int m_nIndexPackCount;

				// 索引包
				DataIndice*** m_arrIndexPack;
			};

			struct ROInstanceMesh
			{
			public:
				// 父节点名字
				char* m_strParentNodeName;

				// 实例化对象的名字
				char* m_strName;

				// 实例化对象骨架的名字
				char* m_strMeshName;

				// 数据包
				DataVertex* m_pDataVertex;

				// 索引包数目
				unsigned int m_nIndexPackCount;

				// 索引包
				DataIndice*** m_arrIndexPack;
			};

			struct ROEmptyNode
			{
			public:
				// 父节点名字
				char* m_strNodeName;

				// 需要的对象
				char* m_pEntityNames;
				int32 m_nEntityCount;
			};

			struct RONode
			{
			public:
				// 当前节点的名字
				char* m_strNodeName;

				// 父节点的名字
				char* m_strParentName;

				// 孩子节点的名字
				char*** m_pChildNames;

				// 孩子数目
				int32 m_nChildCount;

				// 实体对象
				ROEntity* m_pROEntity;

				// 实例化对象
				ROInstanceMesh* m_pROInstanceMesh;

				// 这个已经不需要了
				int32 m_nEntityCount;

				// 可见性
				int32 m_bVisible;

				// 属于场景管理器的类型
				int32 m_nSceneManagerType;
			};

			enum TextureType
			{
				RGB24,      // jpg
				RGBA32,     // png
				DXT1,       // DXT RGBA的压缩格式
				DXT5,       // DXT RGB的压缩格式
				FLOAT_RGBA,  // FLOAT纹理
				BGRA32,
				BGR24
			};

			struct ObjectFieldInfo
			{
			public:
				//属性、字段信息
				Gamechar* m_strFieldInfo;
				//字段的外键名
				Gamechar* m_strCaption;
			};

			enum DrawType
			{
				Triangles, // 三角形
				Quads,     // 四边形
				Lines,     // 线
				LineStrip, // line strip
				Points     // 点
			};

			struct SUPERMAP_API Sightline_Result
			{
			public:
				//! \brief 障碍点
				double m_barrierPointX;
				double m_barrierPointY;
				double m_barrierPointZ;
				//! \brief 是否可见
				bool m_bVisible;
				int m_nTargetIndex;

			public:
				Sightline_Result()
				{
					m_barrierPointX = 0.0;
					m_barrierPointY = 0.0;
					m_barrierPointZ = 0.0;

					m_bVisible = true;
					m_nTargetIndex = 0;
				}

				Sightline_Result(const Sightline_Result & result)
				{
					m_barrierPointX = result.m_barrierPointX;
					m_barrierPointY = result.m_barrierPointY;
					m_barrierPointZ = result.m_barrierPointZ;

					m_bVisible = result.m_bVisible;
					m_nTargetIndex = result.m_nTargetIndex;
				}
			};

			// 用来传参数的结构
			struct SUPERMAP_API ViewShedParamFromGameEngine
			{
			public:
				ViewShedParamFromGameEngine()
				{
					m_viewMatrix = NULL;
					m_projectionMatrix = NULL;
					m_pDepthBuffer = NULL;
					m_nTextureWidth = 0;
					m_nTextureHeight = 0;
					m_bIsForUE = true;
				}

				virtual ~ViewShedParamFromGameEngine()
				{
					if (m_pDepthBuffer != NULL)
					{
						delete (char*)m_pDepthBuffer;
						m_pDepthBuffer = NULL;
					}
				}

			public:
				double* m_viewMatrix;
				double* m_projectionMatrix;
				void* m_pDepthBuffer;
				int m_nTextureWidth;
				int m_nTextureHeight;
				bool m_bIsForUE;
			};

			struct DataSetTexture
			{
				char* m_pByte;
				int m_nSize;
				int m_nComp;
				int m_nWidth;
				int m_nHeight;
				int m_nTextureFormat;

				__int64 m_strTextureName;
				char* m_strRealTextureName;
			};

			struct DataSetMaterial
			{
				char* m_strMaterialName;
				__int64 m_strMaterialHashName;

				__int64 m_strTextureName;
				__int64 m_strTextureName1;
				__int64 m_strTextureName2;
				__int64 m_strTextureName3;

				bool m_bTransparentSorting;

				//! brief 材质颜色
				double m_dR;
				double m_dG;
				double m_dB;
				double m_dA;

				// 纹理矩阵
				float* m_pTexTransform;

				PBRParam* m_PBRParam;
			};

			struct DataSetSkeleton
			{
				// 骨架
				DataVertex* m_pDataVertex;

				// 索引
				DataIndice*** m_pDataIndice;
				uint32 m_nIndice;

				// 骨架名称
				char* m_strSkeletonName;

				// 引用次数
				int m_nRefCount;
			};

			//数据集对象实例化骨架结构
			struct DataSetInstanceSkeleton
			{
				DataSetSkeleton* m_pDataSetSkeleton;

				int** m_arrInstanceID;

				double*** m_arrInstanceMatrix;
			};

			struct DataSetGeode
			{
				// 模型矩阵[4x4]
				double* m_matModelView;

				// 模型
				DataSetSkeleton*** m_pDataSetSkeletons;

				// Skeleton的名字
				char*** m_pSkeletonNames;

				int32 m_nSkeletonCount;
			};

			//数据集对象Patch结构
			struct DataSetPatch
			{
				// 模型
				DataSetGeode*** m_pDataSetGeodes;
				int32 m_nGeodeCount;
			};

			struct DataSetGeometry
			{
				// 所属数据源的名字
				char* m_strDataSource;

				// 所属数据集的名字
				char* m_strDataSet;

				// 对象的ID
				int32 m_nID;

				// 插入点矩阵[4x4]
				double* m_matWorldView;

				DataSetPatch*** m_pDataSetPatchs;
				int32 m_nPatchCount;
			};


			struct SUPERMAP_API SelectedInfo
			{
			public:
				//! \brief 选择数据集模型的材质名称
				FString m_strMaterialName;

				//! \brief 选择数据集模型的图层名
				FString m_strLayerName;

				//! \brief 选择子对象
				UMaterialInstanceDynamic* m_pMatInstanceDynamic;
			};
		}
	}
}