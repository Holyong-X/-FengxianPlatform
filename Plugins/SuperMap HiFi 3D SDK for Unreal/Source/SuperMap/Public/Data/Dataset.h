#pragma once

#include <map>
#include "Data/Geometry.h"
#include "Data/FieldInfo.h"
#include "Data/Rectangle2D.h"
#include "Core/RealspaceDLL.h"
using namespace SuperMapSDK::UnrealEngine::Data;

class UWorld;
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{
			//! \brief 数据集类型
			enum SUPERMAP_API DatasetType
			{
				DT_UnKnown = -1,  //未知
				DT_POINT,   //  点
				DT_LINE,	//  线
				DT_REGION,  //  面
				DT_Model,	//	模型	
			};

			class DataSource;
			class SUPERMAP_API Dataset
			{
			public:
				Dataset();
				Dataset(DataSource* pDataSource, void* pUGDataset);
				~Dataset();

				void* Handler();

				//! \brief 获取数据集名字
				//! \return 数据集名字
				FString GetName();

				//! \brief 查询数据集几何体
				//! \return 几何体
				TArray<Geometry*> Query();

				//! \brief 查询数据集通过SQL
				//! \param strSQL [in] SQL命令
				//! \return 几何体
				TArray<Geometry*> QueryBySql(FString strSQL);

				//! \brief 查询属性字段属性值
				//! \param strFieldName [in] 属性字段
				//! \return 属性值
				TArray<FString> QueryField(FString strFieldName);

				//! \brief 查询属性通过ID
				//! \param nID [in] 对象ID
				//! \return 属性值
				TArray<FString> QueryAttributeById(int32 nID);

				//! \brief 获取字段信息
				//! \param arrFieldInfo [out] 字段信息
				void GetFieldInfos(TArray<FieldInfo>& arrFieldInfo);

				//! \brief 获取数据集Bound
				//! \return 数据集Bound
				Rectangle2D GetBounds();

				//! \brief 返回数据集类型
				//! \return 数据集类型
				DatasetType GetType();

				//! \brief 获取所属数据源
				//! \return 数据源
				DataSource* GetDataSource();
			
			private:

				//! \brief 所属数据源
				DataSource* m_pDataSource;

				//! \brief 绑定数据集实体
				void* m_pUGDataset;

				//! \brief 数据集名字
				FString m_strName;

				//! \brief 场景管理器
				UWorld* m_pWorld;
			};
		}
	}
}