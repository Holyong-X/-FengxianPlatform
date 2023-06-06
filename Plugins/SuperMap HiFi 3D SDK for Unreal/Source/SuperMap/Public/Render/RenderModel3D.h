#pragma once
#include "CoreMinimal.h"
#include "Data/Geometry3D.h"
#include "Data/GeoModel3D.h"
#include "Render/RenderObject.h"
#include "Data/Matrix4d.h"
#include "StaticMeshDescription/Public/StaticMeshAttributes.h"
#include "MeshDescription/Public/MeshDescription.h"
#include "Graphics3D/GameStruct.h"
#include <map>
#include "Core/RealspaceDLL.h"
#include "Base3D/MaterialDefine.h"

class ASuperMap_StaticMeshActor;
class UStaticMeshComponent;
class UStaticMesh;
class UWorld;
class UMaterial;
class UMaterialInstanceConstant;
class UMaterialInstanceDynamic;
class UTexture2D;

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Render
		{
			class SUPERMAP_API RenderModel3D : public RenderObject
			{
#if WITH_EDITOR
			public:
				//! \brief ��������
				//! \param pTextures [in] ����
				//! \param nTex		 [in] �������
				static void CreateTex2D(std::map<__int64, UTexture2D*> & mapTexture, DataSetTexture*** pTextures, int32 nTex, FString strDatasetName);

				//! \brief ��������
				//! \param pMaterials [in] ����
				//! \param nMtl		  [in] ����
				static void CreateMaterial(std::map<__int64, std::pair<FName, UMaterialInstanceConstant*> >  & mapMaterial, DataSetMaterial*** pMaterials, int32 nMtl, std::map<__int64, UTexture2D*> mapTexture, FString strDatasetName);

				//! \brief �����Ǽ�
				//! \param pSkeletons [in] �Ǽ�
				//! \param nSkeleton  [in] �Ǽܸ���
				static void CreateSkeleton(std::map<FName, DataSetSkeleton*> & mapSkeleton, DataSetSkeleton*** pSkeletons, int32 nSkeleton);

				//! \brief ����ʵ�����Ǽ�
				//! \param pInstanceSkeletons [in] ʵ�����Ǽ�
				//! \param nInstanceSkeleton  [in] ʵ�����Ǽܸ���
				static void CreateInstanceSkeleton(std::map<FName, std::pair<DataSetInstanceSkeleton*, UStaticMesh*> > & mapInstanceSkeleton, DataSetInstanceSkeleton*** pInstanceSkeletons, int32 nInstanceSkeleton);
			
				//! \brief ��ȡ����������
				//! \param nIndex  [in] �������±�
				//! \param pIndice [in] ����
				//! \param nIndex1 [out] �����ε�һ�������±�
				//! \param nIndex2 [out] �����εڶ��������±�
				//! \param nIndex3 [out] �����ε����������±�
				static void GetTriangleIndex(uint32 nIndex, DataIndice* pIndice, uint32 &nIndex1, uint32 &nIndex2, uint32 &nIndex3);

				//! \brief ��ȡ�����ζ���
				//! \param nIndex1 [in] �����ε�һ�������±�
				//! \param nIndex2 [in] �����εڶ��������±�
				//! \param nIndex3 [in] �����ε����������±�
				//! \param pDataVertex		[in] �Ǽ����ݰ�
				//! \param vPos1   [out] �����ε�һ����������
				//! \param vPos2   [out] �����εڶ�����������
				//! \param vPos3   [out] �����ε�������������
				static void GetTrianglePos(uint32 nIndex1, uint32 nIndex2, uint32 nIndex3, DataVertex* pDataVertex, GameVector3 &vPos1, GameVector3 &vPos2, GameVector3 &vPos3);

				//! \brief ��ȡ�����η���
				//! \param nIndex1 [in] �����ε�һ�������±�
				//! \param nIndex2 [in] �����εڶ��������±�
				//! \param nIndex3 [in] �����ε����������±�
				//! \param pDataVertex		[in] �Ǽ����ݰ�
				//! \param arrBuildVertexs  [in] ������
				//! \param vNormal1			[out] �����ε�һ�����㷨��
				//! \param vNormal2         [out] �����εڶ������㷨��
				//! \param vNormal3			[out] �����ε��������㷨��
				static void GetTriangleNormal(uint32 nIndex1, uint32 nIndex2, uint32 nIndex3,
					DataVertex* pDataVertex, TArray<FStaticMeshBuildVertex> & arrBuildVertexs,
					GameVector3 &vNormal1, GameVector3 &vNormal2, GameVector3 &vNormal3);

				//! \brief ��ȡ�����ζ�����ɫ
				//! \param nIndex1 [in] �����ε�һ�������±�
				//! \param nIndex2 [in] �����εڶ��������±�
				//! \param nIndex3 [in] �����ε����������±�
				//! \param pDataVertex		[in] �Ǽ����ݰ�
				//! \param vColor1			[out] �����ε�һ��������ɫ
				//! \param vColor2          [out] �����εڶ���������ɫ
				//! \param vColor3			[out] �����ε�����������ɫ
				static void GetTriangleColor(uint32 nIndex1, uint32 nIndex2, uint32 nIndex3, DataVertex* pDataVertex, GameVector4 &vColor1, GameVector4&vColor2, GameVector4&vColor3);

				//! \brief ��ȡ�����ζ�����������
				//! \param nIndex1 [in] �����ε�һ�������±�
				//! \param nIndex2 [in] �����εڶ��������±�
				//! \param nIndex3 [in] �����ε����������±�
				//! \param pDataVertex		[in] �Ǽ����ݰ�
				//! \param vTexcoord1			[out] �����ε�һ��������������
				//! \param vTexcoord2           [out] �����εڶ���������������
				//! \param vTexcoord3			[out] �����ε�����������������
				static void GetTriangleTexcoord(uint32 nIndex1, uint32 nIndex2, uint32 nIndex3, DataVertex* pDataVertex, GameVector2 &vTexcoord1, GameVector2&vTexcoord2, GameVector2&vTexcoord3);

				//! \brief ���������ζ�������
				//! \param VertexPositions [in] ������������
				//! \param nVtxID1 [in] �����ε�һ������ID
				//! \param nVtxID3 [in] �����εڶ�������ID
				//! \param nVtxID4 [in] �����ε���������ID
				//! \param vPos1   [in] �����ε�һ����������
				//! \param vPos2   [in] �����εڶ�����������
				//! \param vPos3   [in] �����ε�������������
				static void SetTrianglePos(TVertexAttributesRef<GameVector3> & VertexPositions, FVertexID nVtxID1, FVertexID nVtxID2, FVertexID nVtxID3, GameVector3 vPos1, GameVector3 vPos2, GameVector3 vPos3);
			
				//! \brief ���������ζ�����������
				//! \param VertexInstanceTangents [in] ����������������
				//! \param VertexInstanceIDs [in] �����ζ�������ID
				//! \param vTexcoord1   [in] �����ε�һ��������������
				//! \param vTexcoord2   [in] �����εڶ���������������
				//! \param vTexcoord3   [in] �����ε�����������������
				static void SetTriangleTexcoord(TVertexInstanceAttributesRef<GameVector2> & VertexInstanceUVs, TArray<FVertexInstanceID> & VertexInstanceIDs, int32 nTexcoordIndex, GameVector2 vTexcoord1, GameVector2 vTexcoord2, GameVector2 vTexcoord3);
			
				//! \brief ���������ζ�����ɫ
				//! \param VertexInstanceTangents [in] ������ɫ����
				//! \param VertexInstanceIDs [in] �����ζ�������ID
				//! \param vColor1   [in] �����ε�һ��������ɫ
				//! \param vColor2   [in] �����εڶ���������ɫ
				//! \param vColor3   [in] �����ε�����������ɫ
				static void SetTriangleColor(TVertexInstanceAttributesRef<GameVector4> VertexInstanceColors, TArray<FVertexInstanceID> & VertexInstanceIDs, GameVector4 vColor1, GameVector4 vColor2, GameVector4 vColor3);
				
				//! \brief ���������ζ��㷨��
				//! \param VertexInstanceNormals [in] ���㷨������
				//! \param VertexInstanceIDs [in] �����ζ�������ID
				//! \param vPos1   [in] �����ε�һ�����㷨��
				//! \param vPos2   [in] �����εڶ������㷨��
				//! \param vPos3   [in] �����ε��������㷨��
				static void SetTriangleNormal(TVertexInstanceAttributesRef<GameVector3> VertexInstanceNormals, TArray<FVertexInstanceID> & VertexInstanceIDs, GameVector3 vNormal1, GameVector3 vNormal2, GameVector3 vNormal3);

				//! \brief ���������ζ�������
				//! \param VertexInstanceTangents [in] ������������
				//! \param VertexInstanceIDs [in] �����ζ�������ID
				//! \param vTangent1   [in] �����ε�һ����������
				//! \param vTangent2   [in] �����εڶ�����������
				//! \param vTangent3   [in] �����ε�������������
				static void SetTriangleTangent(TVertexInstanceAttributesRef<GameVector3> & VertexInstanceTangents, TArray<FVertexInstanceID> & VertexInstanceIDs, GameVector3 vTangent1, GameVector3 vTangent2, GameVector3 vTangent3);
				
				//! \brief ���������ζ���BinormalSign
				//! \param VertexInstanceBinormalSigns [in] ����BinormalSign����
				//! \param VertexInstanceIDs [in] �����ζ�������ID
				//! \param fBinormalSign1   [in] �����ε�һ������BinormalSign
				//! \param fBinormalSign2   [in] �����εڶ�������BinormalSign
				//! \param fBinormalSign3   [in] �����ε���������BinormalSign
				static void SetTriangleBinormalSign(TVertexInstanceAttributesRef<float> & VertexInstanceBinormalSigns, TArray<FVertexInstanceID> & VertexInstanceIDs, float fBinormalSign1, float fBinormalSign2, float fBinormalSign3);
			
				static void ComputeTangentSpace(TArray<FStaticMeshBuildVertex>& vertices);

				static void ComputeFlatNormals(const TArray<uint32_t>& indices, TArray<FStaticMeshBuildVertex>& vertices);

				static void CalMipMap(int nWidth, int nHeight, int nTextureSize, TextureType nFormat, std::map<int, int> & mapMipMaps);

				static void GetTextureType(int nFormat, TextureType &texType);

			protected:

				void Render();

			public:
				
				void Open();

				//! \brief ���ò���� ƽ��ʹ��
				void SetPosition(FVector vPos);

			private:
				//! \brief ��Ӷ���
				//! \param pGeometry [in] ����
				void AddStaticMeshActor(DataSetGeometry* pGeometry);

				//! \brief ����ModelPatch
				//! \param pActor  [in] �����Ķ���
				//! \param pPatchs [in] ModelPatch
				//! \param nPatch  [in] ModelPatch����
				void AddStaticMeshFromModelPatch(ASuperMap_StaticMeshActor* pActor, DataSetPatch*** pPatchs, int32 nPatch);

				//! \brief ����ModelGeode
				//! \param pActor  [in] �����Ķ���
				//! \param pGeodes [in] ModelGeode
				//! \param nGeode  [in] ModelGeode����
				void AddStaticMeshFormModelGeode(ASuperMap_StaticMeshActor* pActor, DataSetGeode*** pGeodes, int32 nGeode);

				//! \brief ������̬����
				//! \param pActor           [in] �����Ķ���
				//! \param strSkeletonName  [in] �Ǽܵ�����
				//! \param pDataVertex		[in] �Ǽ����ݰ�
				//! \param pDataIndice		[in] ������
				//! \param nDataIndice		[in] ����������
				UStaticMesh* CreateStaticMesh(ASuperMap_StaticMeshActor* pActor, FName strSkeletonName, DataVertex* pDataVertex, DataIndice*** pDataIndice, uint32 nIndiceCount);
				
				//! \brief ������̬�������
				//! \brief pStaticMesh     [in] ��̬����
				//! \brief matLocalToWorld [in] ����
				UStaticMeshComponent* CreateStaticMeshComponent(UObject* pOuter, UStaticMesh* pStaticMesh, Matrix4d matLocalToWorld);

				//! \brief �����������
				//! \param pStaticMeshComponent [in] ���
				//! \param matLocaToWorld		[in] �任����
				void SetComponentMatrix(UStaticMeshComponent* pStaticMeshComponent, Matrix4d matLocalToWorld);
#endif
			private:
				//! \brief ��ʱ���ʹ�����
				std::map<__int64, std::pair<FName, UMaterialInstanceConstant*> >  m_mapMaterial;

				//! \brief ��ʱ���������
				std::map<__int64, UTexture2D*>  m_mapTexture;

				//! \brief ��ʱ��ʵ�����Ǽܹ�����
				std::map<FName, DataSetSkeleton*> m_mapSkeleton;

				//! \brief ��ʱʵ�����Ǽܹ�����
				std::map<FName, std::pair<DataSetInstanceSkeleton*, UStaticMesh*> > m_mapInstanceSkeleton;

				//! \brief ��ʱʵ�������ʻ�����
				std::map<FName, std::pair<FName, UMaterialInstanceConstant*> > m_mapInstanceMaterial;

				//! \brief �����
				FVector m_vPosition;
			};
		}
	}
}