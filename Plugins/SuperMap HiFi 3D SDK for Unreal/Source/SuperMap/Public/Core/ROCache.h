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

				// ����UGC�����ظ�ʽ
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

				// �������
				float* m_pTexTransform;
				float* m_pTexTransform1;
				float* m_pTexTransform2;
				float* m_pTexTransform3;

				// ��ɫ�� Shader
				char* m_strShaderName;

				int m_nDataType;

				// ���������
				int m_nBatchSize;

				// BatchTextureIndex
				int m_nBatchTextureIndex;

				// ѡ�ж���ĸ���
				int m_nBatchTexSize;

				// PBR���ʲ���
				PBRParam* m_pPBRParam;

				// ���������±�
				int m_nNormalTexIndex;

				// ������ɫ
				float m_fDiffuseR;
				float m_fDiffuseG;
				float m_fDiffuseB;
				float m_fDiffuseA;

				//! \brief TIN���εĲ㼶
				int m_nGlobalTinLevel;

				//! \brief TIN���ε�ƽ�ƾ���
				double* m_pGlobalTinTran;
			};

			struct ROEntity
			{
			public:
				// ���ڵ�����
				char* m_strParentNodeName;
				// �ڵ�����
				char* m_strName;
				// �ɼ���
				int32 m_bVisible;

				// ���Ʒ�ʽ
				int32 m_OperationType;

				// ���ݰ�
				DataVertex* m_pDataVertex;

				// ��������Ŀ
				unsigned int m_nIndexPackCount;

				// ������
				DataIndice*** m_arrIndexPack;
			};

			struct ROInstanceMesh
			{
			public:
				// ���ڵ�����
				char* m_strParentNodeName;

				// ʵ�������������
				char* m_strName;

				// ʵ��������Ǽܵ�����
				char* m_strMeshName;

				// ���ݰ�
				DataVertex* m_pDataVertex;

				// ��������Ŀ
				unsigned int m_nIndexPackCount;

				// ������
				DataIndice*** m_arrIndexPack;
			};

			struct ROEmptyNode
			{
			public:
				// ���ڵ�����
				char* m_strNodeName;

				// ��Ҫ�Ķ���
				char* m_pEntityNames;
				int32 m_nEntityCount;
			};

			struct RONode
			{
			public:
				// ��ǰ�ڵ������
				char* m_strNodeName;

				// ���ڵ������
				char* m_strParentName;

				// ���ӽڵ������
				char*** m_pChildNames;

				// ������Ŀ
				int32 m_nChildCount;

				// ʵ�����
				ROEntity* m_pROEntity;

				// ʵ��������
				ROInstanceMesh* m_pROInstanceMesh;

				// ����Ѿ�����Ҫ��
				int32 m_nEntityCount;

				// �ɼ���
				int32 m_bVisible;

				// ���ڳ���������������
				int32 m_nSceneManagerType;
			};

			enum TextureType
			{
				RGB24,      // jpg
				RGBA32,     // png
				DXT1,       // DXT RGBA��ѹ����ʽ
				DXT5,       // DXT RGB��ѹ����ʽ
				FLOAT_RGBA,  // FLOAT����
				BGRA32,
				BGR24
			};

			struct ObjectFieldInfo
			{
			public:
				//���ԡ��ֶ���Ϣ
				Gamechar* m_strFieldInfo;
				//�ֶε������
				Gamechar* m_strCaption;
			};

			enum DrawType
			{
				Triangles, // ������
				Quads,     // �ı���
				Lines,     // ��
				LineStrip, // line strip
				Points     // ��
			};

			struct SUPERMAP_API Sightline_Result
			{
			public:
				//! \brief �ϰ���
				double m_barrierPointX;
				double m_barrierPointY;
				double m_barrierPointZ;
				//! \brief �Ƿ�ɼ�
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

			// �����������Ľṹ
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

				//! brief ������ɫ
				double m_dR;
				double m_dG;
				double m_dB;
				double m_dA;

				// �������
				float* m_pTexTransform;

				PBRParam* m_PBRParam;
			};

			struct DataSetSkeleton
			{
				// �Ǽ�
				DataVertex* m_pDataVertex;

				// ����
				DataIndice*** m_pDataIndice;
				uint32 m_nIndice;

				// �Ǽ�����
				char* m_strSkeletonName;

				// ���ô���
				int m_nRefCount;
			};

			//���ݼ�����ʵ�����Ǽܽṹ
			struct DataSetInstanceSkeleton
			{
				DataSetSkeleton* m_pDataSetSkeleton;

				int** m_arrInstanceID;

				double*** m_arrInstanceMatrix;
			};

			struct DataSetGeode
			{
				// ģ�;���[4x4]
				double* m_matModelView;

				// ģ��
				DataSetSkeleton*** m_pDataSetSkeletons;

				// Skeleton������
				char*** m_pSkeletonNames;

				int32 m_nSkeletonCount;
			};

			//���ݼ�����Patch�ṹ
			struct DataSetPatch
			{
				// ģ��
				DataSetGeode*** m_pDataSetGeodes;
				int32 m_nGeodeCount;
			};

			struct DataSetGeometry
			{
				// ��������Դ������
				char* m_strDataSource;

				// �������ݼ�������
				char* m_strDataSet;

				// �����ID
				int32 m_nID;

				// ��������[4x4]
				double* m_matWorldView;

				DataSetPatch*** m_pDataSetPatchs;
				int32 m_nPatchCount;
			};


			struct SUPERMAP_API SelectedInfo
			{
			public:
				//! \brief ѡ�����ݼ�ģ�͵Ĳ�������
				FString m_strMaterialName;

				//! \brief ѡ�����ݼ�ģ�͵�ͼ����
				FString m_strLayerName;

				//! \brief ѡ���Ӷ���
				UMaterialInstanceDynamic* m_pMatInstanceDynamic;
			};
		}
	}
}