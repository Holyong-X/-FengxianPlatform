#pragma once

#include "CoreMinimal.h"
#include "Core/Layer3D.h"
#include "Core/ROCache.h"
#include "Data/DataSource.h"
#include "Data/Dataset.h"
#include "Render/RenderModel3D.h"
#include "StaticMeshDescription/Public/StaticMeshAttributes.h"
#include "MeshDescription/Public/MeshDescription.h"
#include <map>
#include "Core/RealspaceDLL.h"

class ASuperMap_StaticMeshActor;
class UStaticMeshComponent;
class UStaticMesh;
class UWorld;
class UMaterial;
class UMaterialInstanceConstant;
class UMaterialInstanceDynamic;
class UTexture2D;

using namespace SuperMapSDK::UnrealEngine::Data;
using namespace SuperMapSDK::UnrealEngine::Render;
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			class SUPERMAP_API Layer3DDatasetModel : public Layer3D
			{
			public:
				Layer3DDatasetModel();
				Layer3DDatasetModel(void* pUGLayer3D, FName strLayerName, Layer3DType eLayerType);
				virtual ~Layer3DDatasetModel();

			public:
				//! \brief 添加图层的渲染对象
				virtual void AddNativeGameComponent(GameComponent* pGameComponent);

				//! \brief 移除图层的渲染对象
				virtual void RemoveNativeGameComponent(GameComponent* pGameComponent);

				//! \brief 设置数据集
				//! \param pDataset [in] 数据集
				void SetDataset(Dataset* pDataset);

				//! \brief 获取模型数据集
				Dataset* GetDataset();
			private:
				//! \brief 更换对象材质
				void UpdateObjectMaterialInfo(GameMaterial* pGameMaterial);

				void UpdateShaderForOneNativeGameComponent(GameComponent* pGameComponent);

				//! \brief 根据名称获取对应资产
				FString GetHomologousAsset(FString strKey);
			#if WITH_EDITOR
			public:
				//! \brief 设置UE的场景管理器
				void SetWorld(UWorld* pWorld);

				//! \brief 打开图层
				//! \return 
				bool Open();

				//! \brief 生成材质对应的文件
				void ToJson();

				//! \brief 设置插入点 平面使用
				virtual void SetOriginalPosition(FVector vPos);

			private:

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

				//! \brief 添加对象
				//! \param pGeometry [in] 对象
				void AddStaticMeshActor(DataSetGeometry* pGeometry);
				
				//! \brief 创建静态网格
				//! \param pActor           [in] 创建的对象
				//! \param strSkeletonName  [in] 骨架的名字
				//! \param pDataVertex		[in] 骨架数据包
				//! \param pDataIndice		[in] 索引包
				//! \param nDataIndice		[in] 索引包个数
				UStaticMesh* CreateStaticMesh(ASuperMap_StaticMeshActor* pActor, FName strSkeletonName, DataVertex* pDataVertex, DataIndice*** pDataIndice, uint32 nIndiceCount);

				//! \brief 设置组件矩阵
				//! \param pStaticMeshComponent [in] 组件
				//! \param matLocaToWorld		[in] 变换矩阵
				void SetComponentMatrix(UStaticMeshComponent* pStaticMeshComponent, Matrix4d matLocalToWorld);

				//! \brief 创建静态网格组件
				//! \brief pStaticMesh     [in] 静态网格
				//! \brief matLocalToWorld [in] 矩阵
				UStaticMeshComponent* CreateStaticMeshComponent(UObject* pOuter, UStaticMesh* pStaticMesh, Matrix4d matLocaToWorld);
			#endif
			private:

				//! \brief 插入点
				FVector m_vPosition;

				//! \brief UE的场景管理器
				UWorld* m_pWorld; 

				//! \brief 数据集
				Dataset* m_pDataset;

				//! \brief 临时材质管理器
				std::map<__int64, std::pair<FName, UMaterialInstanceConstant*> >  m_mapMaterial;

				//! \brief 临时纹理管理器
				std::map<__int64, UTexture2D*>  m_mapTexture;

				//! \brief 临时非实例化骨架管理器
				std::map<FName, DataSetSkeleton*> m_mapSkeleton;

				//! \brief 临时实例化骨架管理器
				std::map<FName, std::pair<DataSetInstanceSkeleton* , UStaticMesh*> > m_mapInstanceSkeleton;

				//! \brief 临时实例化材质换了器
				std::map<FName, std::pair<FName, UMaterialInstanceConstant*> > m_mapInstanceMaterial;
			};

		}
	}
}