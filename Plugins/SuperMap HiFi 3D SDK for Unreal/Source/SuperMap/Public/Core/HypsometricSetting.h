#pragma once
#include "CoreMinimal.h"
#include "Core/RealspaceDLL.h"
#include "Engine/Texture2D.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Component/SuperMap_MeshComponent.h"
#include "Data/GeoRegion3D.h"
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			enum DisplayMode
			{
				//! \brief 无
				NONE = 0,
				//! \brief 填充纹理
				Face = 1,
				//! \brief 等值线
				Line = 2,
				//! \brief 混合模式
				Face_And_Line = 3,
			};

			enum AnalysisMode
			{
				AM_CONTOUR_MAP = 0,	// 高度分析
				AM_GUIDES = 2,	// 参考线
			};

			class SUPERMAP_API HypsometricSetting
			{
			public:
				HypsometricSetting();
				~HypsometricSetting();
			public:

				//! \brief 设置是否显示线&填充色。
				void SetDisplayMode(DisplayMode mode);

				//! \brief 获得线的显示模式。
				DisplayMode GetDisplayMode();

				//! \brief 设置是分析模式
				void SetAnalysisMode(AnalysisMode mode);

				//! \brief 获得分析模式
				AnalysisMode GetAnalysisMode();

				//! \brief 设置间距
				void SetLinesInterval(double dLinesInterval);

				//! \brief 获取间距
				double GetLinesInterval();

				//! \brief 设置线颜色
				void SetLineColor(FColor color);

				//! \brief 获取线颜色
				FColor GetLineColor();

				//! \brief 设置颜色表最高值
				void SetColorTableMaxKey(double dMaxKey);

				//! \brief 获取颜色表最高值
				double GetColorTableMaxKey();

				//! \brief 设置颜色表最低值
				void SetColorTableMinKey(double dMinKey);

				//! \brief 获取颜色表最低值
				double GetColorTableMinKey();

				//! \brief 设置最小可见值
				void SetMinVisibleValue(double minValue);

				//! \brief 获取最小可见值
				double GetMinVisibleValue();

				//! \brief 设置最大可见值
				void SetMaxVisibleValue(double maxValue);

				//! \brief 获取最小可见值
				double GetMaxVisibleValue();

				//! \brief 设置颜色表文件路径
				void SetColorTableFile(FString strFilePath);

				//! \brief 获取颜色表文件路径
				FString GetColorTableFile();

				//! \brief 设置颜色表
				void SetColorTableTexture(UTexture2D* colorTableTexture);

				//! \brief 获取颜色表
				UTexture2D* GetColorTableTexture();
			private:
				void ReleaseTexture();
				void InitialColorTableTexture();
			private:
				//! \brief 颜色表文件
				FString m_strColorTableFile;
				//! \brief 颜色表纹理
				UTexture2D* m_colorTableTexture;
				//! \brief 对照表最大值
				double m_dCeil;
				//! \brief 对照表最小值
				double m_dFloor;
				//! \brief UGC对象
				void* m_pHypsometricSetting;
			};

			class SUPERMAP_API ModifyTerrainObject
			{
			public:
				ModifyTerrainObject();
				~ModifyTerrainObject();
			public:
				//! \brief 设置填挖方面
				//! \brief 外部需要删除GeoRegion3D(内部已复制)
				void SetRegion(GeoRegion3D* pGeoRegion3D);

				//! \brief 设置填挖方高度
				void SetHeight(double dHeight);

				void* GetHandler();
			private:
				void* m_pModifyTerrainObject;
			};

			class SUPERMAP_API ModifyTerrainSetting
			{
			public:
				ModifyTerrainSetting(void* pModifyTerrainSetting);
				ModifyTerrainSetting();
				~ModifyTerrainSetting();
			public:
				//! \brief 添加一个修改地形的对象
				void Add(ModifyTerrainObject* pModifyTerrainObject, FString tag);

				//! \brief 清除
				void Clear();
			private:
				void* m_pModifyTerrainSetting;
			};
		}
	}
}