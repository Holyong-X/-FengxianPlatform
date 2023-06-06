#pragma once
#include "CoreMinimal.h"
#include "Core/RealspaceDLL.h"
#include "Engine/Texture2D.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Component/SuperMap_MeshComponent.h"
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			struct SlopeMapShaderParams
			{
			public:
				SlopeMapShaderParams();
			public:
				int SlopeDisplayMode;
				float SlopeFloorAngle;
				float SlopeCeilAngle;
				float SlopeMinVisibleSlope;
				float SlopeMaxVisibleSlope;
				UTexture2D* SlopeColorTexture;
				UTexture2D* SlopeArrowTexture;
				float SlopeArrowsMove;
				float SlopeTopLevel;
				float SlopeTimeVal;
			};

			class SUPERMAP_API SlopeSetting
			{
			public:
				//! \brief 显示模式
				enum DisplayMode
				{
					//! \brief 不使用显示模式
					NONE = 0,
					//! \brief 显示填充
					FACE = 1,
					//! \brief 显示坡向
					ARROW = 2,
					//! \brief 显示填充和坡向
					FACE_AND_ARROW = 3
				};

			public:
				SlopeSetting();

				SlopeSetting(SlopeSetting& other);

				~SlopeSetting();
			public:
				SlopeSetting& operator=(SlopeSetting& other);

				//! \brief 设置是否显示线&填充色。
				void SetDisplaySytle(SlopeSetting::DisplayMode mode);

				//! \brief 获得线的显示模式。
				SlopeSetting::DisplayMode GetDisplaySytle();

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

				//! \brief 设置颜色表
				void SetColorTableTexture(UTexture2D* colorTableTexture);

				//! \brief 获取颜色表
				UTexture2D* GetColorTableTexture();

				//! \brief 设置坡向箭头纹理
				void SetArrowTexture(UTexture2D* arrowTexture);

				//! \brief 获取坡向箭头纹理
				UTexture2D* GetArrowTexture();

				//! \brief 设置坡向箭头是否运动
				void SetArrowMove(bool isMove);

				//! \brief 获取坡向箭头是否运动
				bool IsArrowMove();

				//! \brief 更着色器参数对象赋值
				void UpdateShaderParams(SlopeMapShaderParams& param);
			private:
				void ReleaseTexture();
				void InitialColorTableTexture();
			private:
				//! \brief 颜色表纹理
				UTexture2D* m_colorTableTexture;
				//! \brief 坡向箭头纹理
				UTexture2D* m_arrowTexture;
				//! \brief 对照表最大值
				double m_dCeil;
				//! \brief 对照表最小值
				double m_dFloor;
				//! \brief 坡向箭头是否运动
				bool m_bArrowMove;
				//! \brief UGC对象
				void* m_pSlopeSetting;
			};
		}
	}
}