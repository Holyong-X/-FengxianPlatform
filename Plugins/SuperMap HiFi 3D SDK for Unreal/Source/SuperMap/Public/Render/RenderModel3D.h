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
				//! \brief 创建纹理
				//! \param pTextures [in] 纹理
				//! \param nTex		 [in] 纹理个数
				static void CreateTex2D(std::map<__int64, UTexture2D*> & mapTexture, DataSetTexture*** pTextures, int32 nTex, FString strDatasetName);

				//! \brief 创建材质
				//! \param pMaterials [in] 材质
				//! \param nMtl		  [in] 材质
				static void CreateMaterial(std::map<__int64, std::pair<FName, UMaterialInstanceConstant*> >  & mapMaterial, DataSetMaterial*** pMaterials, int32 nMtl, std::map<__int64, UTexture2D*> mapTexture, FString strDatasetName);

				//! \brief 创建骨架
				//! \param pSkeletons [in] 骨架
				//! \param nSkeleton  [in] 骨架个数
				static void CreateSkeleton(std::map<FName, DataSetSkeleton*> & mapSkeleton, DataSetSkeleton*** pSkeletons, int32 nSkeleton);

				//! \brief 创建实例化骨架
				//! \param pInstanceSkeletons [in] 实例化骨架
				//! \param nInstanceSkeleton  [in] 实例化骨架个数
				static void CreateInstanceSkeleton(std::map<FName, std::pair<DataSetInstanceSkeleton*, UStaticMesh*> > & mapInstanceSkeleton, DataSetInstanceSkeleton*** pInstanceSkeletons, int32 nInstanceSkeleton);
			
				//! \brief 获取三角网索引
				//! \param nIndex  [in] 三角形下标
				//! \param pIndice [in] 索引
				//! \param nIndex1 [out] 三角形第一个顶点下标
				//! \param nIndex2 [out] 三角形第二个顶点下标
				//! \param nIndex3 [out] 三角形第三个顶点下标
				static void GetTriangleIndex(uint32 nIndex, DataIndice* pIndice, uint32 &nIndex1, uint32 &nIndex2, uint32 &nIndex3);

				//! \brief 获取三角形顶点
				//! \param nIndex1 [in] 三角形第一个顶点下标
				//! \param nIndex2 [in] 三角形第二个顶点下标
				//! \param nIndex3 [in] 三角形第三个顶点下标
				//! \param pDataVertex		[in] 骨架数据包
				//! \param vPos1   [out] 三角形第一个顶点坐标
				//! \param vPos2   [out] 三角形第二个顶点坐标
				//! \param vPos3   [out] 三角形第三个顶点坐标
				static void GetTrianglePos(uint32 nIndex1, uint32 nIndex2, uint32 nIndex3, DataVertex* pDataVertex, GameVector3 &vPos1, GameVector3 &vPos2, GameVector3 &vPos3);

				//! \brief 获取三角形法线
				//! \param nIndex1 [in] 三角形第一个顶点下标
				//! \param nIndex2 [in] 三角形第二个顶点下标
				//! \param nIndex3 [in] 三角形第三个顶点下标
				//! \param pDataVertex		[in] 骨架数据包
				//! \param arrBuildVertexs  [in] 三角网
				//! \param vNormal1			[out] 三角形第一个顶点法线
				//! \param vNormal2         [out] 三角形第二个顶点法线
				//! \param vNormal3			[out] 三角形第三个顶点法线
				static void GetTriangleNormal(uint32 nIndex1, uint32 nIndex2, uint32 nIndex3,
					DataVertex* pDataVertex, TArray<FStaticMeshBuildVertex> & arrBuildVertexs,
					GameVector3 &vNormal1, GameVector3 &vNormal2, GameVector3 &vNormal3);

				//! \brief 获取三角形顶点颜色
				//! \param nIndex1 [in] 三角形第一个顶点下标
				//! \param nIndex2 [in] 三角形第二个顶点下标
				//! \param nIndex3 [in] 三角形第三个顶点下标
				//! \param pDataVertex		[in] 骨架数据包
				//! \param vColor1			[out] 三角形第一个顶点颜色
				//! \param vColor2          [out] 三角形第二个顶点颜色
				//! \param vColor3			[out] 三角形第三个顶点颜色
				static void GetTriangleColor(uint32 nIndex1, uint32 nIndex2, uint32 nIndex3, DataVertex* pDataVertex, GameVector4 &vColor1, GameVector4&vColor2, GameVector4&vColor3);

				//! \brief 获取三角形顶点纹理坐标
				//! \param nIndex1 [in] 三角形第一个顶点下标
				//! \param nIndex2 [in] 三角形第二个顶点下标
				//! \param nIndex3 [in] 三角形第三个顶点下标
				//! \param pDataVertex		[in] 骨架数据包
				//! \param vTexcoord1			[out] 三角形第一个顶点纹理坐标
				//! \param vTexcoord2           [out] 三角形第二个顶点纹理坐标
				//! \param vTexcoord3			[out] 三角形第三个顶点纹理坐标
				static void GetTriangleTexcoord(uint32 nIndex1, uint32 nIndex2, uint32 nIndex3, DataVertex* pDataVertex, GameVector2 &vTexcoord1, GameVector2&vTexcoord2, GameVector2&vTexcoord3);

				//! \brief 设置三角形顶点坐标
				//! \param VertexPositions [in] 顶点坐标容器
				//! \param nVtxID1 [in] 三角形第一个顶点ID
				//! \param nVtxID3 [in] 三角形第二个顶点ID
				//! \param nVtxID4 [in] 三角形第三个顶点ID
				//! \param vPos1   [in] 三角形第一个顶点坐标
				//! \param vPos2   [in] 三角形第二个顶点坐标
				//! \param vPos3   [in] 三角形第三个顶点坐标
				static void SetTrianglePos(TVertexAttributesRef<GameVector3> & VertexPositions, FVertexID nVtxID1, FVertexID nVtxID2, FVertexID nVtxID3, GameVector3 vPos1, GameVector3 vPos2, GameVector3 vPos3);
			
				//! \brief 设置三角形顶点纹理坐标
				//! \param VertexInstanceTangents [in] 顶点纹理坐标容器
				//! \param VertexInstanceIDs [in] 三角形顶点索引ID
				//! \param vTexcoord1   [in] 三角形第一个顶点纹理坐标
				//! \param vTexcoord2   [in] 三角形第二个顶点纹理坐标
				//! \param vTexcoord3   [in] 三角形第三个顶点纹理坐标
				static void SetTriangleTexcoord(TVertexInstanceAttributesRef<GameVector2> & VertexInstanceUVs, TArray<FVertexInstanceID> & VertexInstanceIDs, int32 nTexcoordIndex, GameVector2 vTexcoord1, GameVector2 vTexcoord2, GameVector2 vTexcoord3);
			
				//! \brief 设置三角形顶点颜色
				//! \param VertexInstanceTangents [in] 顶点颜色容器
				//! \param VertexInstanceIDs [in] 三角形顶点索引ID
				//! \param vColor1   [in] 三角形第一个顶点颜色
				//! \param vColor2   [in] 三角形第二个顶点颜色
				//! \param vColor3   [in] 三角形第三个顶点颜色
				static void SetTriangleColor(TVertexInstanceAttributesRef<GameVector4> VertexInstanceColors, TArray<FVertexInstanceID> & VertexInstanceIDs, GameVector4 vColor1, GameVector4 vColor2, GameVector4 vColor3);
				
				//! \brief 设置三角形顶点法线
				//! \param VertexInstanceNormals [in] 顶点法线容器
				//! \param VertexInstanceIDs [in] 三角形顶点索引ID
				//! \param vPos1   [in] 三角形第一个顶点法线
				//! \param vPos2   [in] 三角形第二个顶点法线
				//! \param vPos3   [in] 三角形第三个顶点法线
				static void SetTriangleNormal(TVertexInstanceAttributesRef<GameVector3> VertexInstanceNormals, TArray<FVertexInstanceID> & VertexInstanceIDs, GameVector3 vNormal1, GameVector3 vNormal2, GameVector3 vNormal3);

				//! \brief 设置三角形顶点切线
				//! \param VertexInstanceTangents [in] 顶点切线容器
				//! \param VertexInstanceIDs [in] 三角形顶点索引ID
				//! \param vTangent1   [in] 三角形第一个顶点切线
				//! \param vTangent2   [in] 三角形第二个顶点切线
				//! \param vTangent3   [in] 三角形第三个顶点切线
				static void SetTriangleTangent(TVertexInstanceAttributesRef<GameVector3> & VertexInstanceTangents, TArray<FVertexInstanceID> & VertexInstanceIDs, GameVector3 vTangent1, GameVector3 vTangent2, GameVector3 vTangent3);
				
				//! \brief 设置三角形顶点BinormalSign
				//! \param VertexInstanceBinormalSigns [in] 顶点BinormalSign容器
				//! \param VertexInstanceIDs [in] 三角形顶点索引ID
				//! \param fBinormalSign1   [in] 三角形第一个顶点BinormalSign
				//! \param fBinormalSign2   [in] 三角形第二个顶点BinormalSign
				//! \param fBinormalSign3   [in] 三角形第三个顶点BinormalSign
				static void SetTriangleBinormalSign(TVertexInstanceAttributesRef<float> & VertexInstanceBinormalSigns, TArray<FVertexInstanceID> & VertexInstanceIDs, float fBinormalSign1, float fBinormalSign2, float fBinormalSign3);
			
				static void ComputeTangentSpace(TArray<FStaticMeshBuildVertex>& vertices);

				static void ComputeFlatNormals(const TArray<uint32_t>& indices, TArray<FStaticMeshBuildVertex>& vertices);

				static void CalMipMap(int nWidth, int nHeight, int nTextureSize, TextureType nFormat, std::map<int, int> & mapMipMaps);

				static void GetTextureType(int nFormat, TextureType &texType);

			protected:

				void Render();

			public:
				
				void Open();

				//! \brief 设置插入点 平面使用
				void SetPosition(FVector vPos);

			private:
				//! \brief 添加对象
				//! \param pGeometry [in] 对象
				void AddStaticMeshActor(DataSetGeometry* pGeometry);

				//! \brief 遍历ModelPatch
				//! \param pActor  [in] 创建的对象
				//! \param pPatchs [in] ModelPatch
				//! \param nPatch  [in] ModelPatch个数
				void AddStaticMeshFromModelPatch(ASuperMap_StaticMeshActor* pActor, DataSetPatch*** pPatchs, int32 nPatch);

				//! \brief 遍历ModelGeode
				//! \param pActor  [in] 创建的对象
				//! \param pGeodes [in] ModelGeode
				//! \param nGeode  [in] ModelGeode个数
				void AddStaticMeshFormModelGeode(ASuperMap_StaticMeshActor* pActor, DataSetGeode*** pGeodes, int32 nGeode);

				//! \brief 创建静态网格
				//! \param pActor           [in] 创建的对象
				//! \param strSkeletonName  [in] 骨架的名字
				//! \param pDataVertex		[in] 骨架数据包
				//! \param pDataIndice		[in] 索引包
				//! \param nDataIndice		[in] 索引包个数
				UStaticMesh* CreateStaticMesh(ASuperMap_StaticMeshActor* pActor, FName strSkeletonName, DataVertex* pDataVertex, DataIndice*** pDataIndice, uint32 nIndiceCount);
				
				//! \brief 创建静态网格组件
				//! \brief pStaticMesh     [in] 静态网格
				//! \brief matLocalToWorld [in] 矩阵
				UStaticMeshComponent* CreateStaticMeshComponent(UObject* pOuter, UStaticMesh* pStaticMesh, Matrix4d matLocalToWorld);

				//! \brief 设置组件矩阵
				//! \param pStaticMeshComponent [in] 组件
				//! \param matLocaToWorld		[in] 变换矩阵
				void SetComponentMatrix(UStaticMeshComponent* pStaticMeshComponent, Matrix4d matLocalToWorld);
#endif
			private:
				//! \brief 临时材质管理器
				std::map<__int64, std::pair<FName, UMaterialInstanceConstant*> >  m_mapMaterial;

				//! \brief 临时纹理管理器
				std::map<__int64, UTexture2D*>  m_mapTexture;

				//! \brief 临时非实例化骨架管理器
				std::map<FName, DataSetSkeleton*> m_mapSkeleton;

				//! \brief 临时实例化骨架管理器
				std::map<FName, std::pair<DataSetInstanceSkeleton*, UStaticMesh*> > m_mapInstanceSkeleton;

				//! \brief 临时实例化材质换了器
				std::map<FName, std::pair<FName, UMaterialInstanceConstant*> > m_mapInstanceMaterial;

				//! \brief 插入点
				FVector m_vPosition;
			};
		}
	}
}