#pragma once

#include "CoreMinimal.h"
#include "Base3D/CommonDefine.h"
#include "Base3D/MaterialDefine.h"
#include "Graphics3D/GameStruct.h"
#include "Graphics3D/GameEnum.h"
#include "Graphics3D/GameTexture.h"

class UMaterialInterface;
class UMaterialInstanceDynamic;
class UMaterialInstanceConstant;
namespace SuperMapSDK
{
	struct FSuperMapMaterialMacro
	{
	public:
		//! \brief 是否为多时序
		Gamebool m_bMultiTemporalWeight = false;
		//TO DO: 可以往这个结构体里面添加
	};

	class FSuperMapMaterialInterfaceCollection
	{
	public:
		FSuperMapMaterialInterfaceCollection();
		~FSuperMapMaterialInterfaceCollection();

		void SetMaterialByUseFlag(UseMaterialFlag useFlag, UMaterialInterface* pMaterialInterface);

		UMaterialInterface* GetMaterialByUseFlag(UseMaterialFlag useFlag) const;
		void SetMacros(GameMaterialParam* pMaterialParam);
		FSuperMapMaterialMacro& GetMacros() { return m_matMacros; }

	private:
		// 以类别划分的材质集合
		TMap<UseMaterialFlag, UMaterialInterface*> m_mapMaterialByFlag;
		//! \brief Normal材质的宏
		FSuperMapMaterialMacro m_matMacros;
	};


	class GameRenderTexture;
	class SUPERMAP_API GameMaterial
	{
	public:
		GameMaterial();
		GameMaterial(GameMaterialParam* pMaterialParam);
		~GameMaterial();

	public:

		//! \brief 获取材质参数
		GameMaterialParam* GetMaterialParam();

		//! \brief 获取UE动态材质
		UMaterialInstanceDynamic* GetMID();

		//! \brief 设置UE动态材质
		void SetMID(UMaterialInstanceDynamic* pMID);

		//! \brief 获取分屏材质
		UMaterialInstanceDynamic* GetViewportMID();

		//! \brief 获取选择使用的材质
		UMaterialInstanceDynamic* GetSelectionMaterial();

		//! \brief 获取框选使用的材质
		UMaterialInstanceDynamic* GetRectSelectMaterial();

		//! \brief 获取材质原始名称
		FString GetMaterialOrginName();

		//! \brief 更新材质
		void UpdateMaterial(GameMaterialParam* pMaterialParam);

		//! \brief 更新框选/空间查询材质
		void UpdateRectMaterial(GameMaterialParam* pMaterialParam);

		//! \brief 获取数据类型
		DataType GetDataType();

		//! \brief 设置shader参数
		void SetMaterialIntParam(Gamechar* strParamName, Gameint nValue);
		void SetMaterialfloatParam(Gamechar* strParamName, Gamefloat nValue);
		void SetMaterialVector3dParam(Gamechar* strParamName, GameVec3d vValue3d);
		void SetMaterialVector4dParam(Gamechar* strParamName, GameVec4d vValue4d);
		void SetMaterialMatrix4dParam(Gamechar* strParamName, void* pValue);
		void SetMaterialTextureParam(Gamechar* strParamName, Gameint nTexIndex);

		//! \brief 当纹理异步填好得时候才设置纹理参数
		void UpdateTextureParam();
		//! \brief 当纹理异步填好得时候才设置材质参数
		void UpdateShaderParam();
		//! \brief 纹理是否已经异步填完
		Gameint GetNumUnsetTexture();

		//! \brief 初始化材质
		void InitMaterial();

		//! \brief 获取单面渲染方式
		CullingMode GetCullingMode();
	private:

		//! \brief 初始化MID
		void InitMID();

		//! \brief 创建材质
		void CreateMID(bool bIsPBR, FString strShaderName);

		//! \brief 创建选择材质
		//! \brief pColorMaterial 用来进行颜色渲染的材质
		void CreateSelectionMaterial(UMaterialInterface* pColorMaterial);

		//! \brief 创建框选材质
		void CreateRectSelectMaterial(UMaterialInterface* pRectSelectMaterial);

		//! \brief 更新材质参数
		void UpdateMaterialParam();

		//! \brief 设置分析功能使用的材质参数
		void UpdateAnalyst(UMaterialInstanceDynamic* pMD);

		//! \brief 清除分屏分析
		void UpdateViewportMID(UMaterialInstanceDynamic* pMID);

		//! \brief 设置PBR纹理参数
		void SetPBRTextureParam(GamePBRParam* pPBRParam, FName & strTexture, int32 nTexCount);
		void SetPBRMaterialParam(UMaterialInstanceDynamic* pMID);

		//! \brief 判断是否需要创建选择材质
		bool IsNeedCreateSelectionMaterial(FString strShaderName);
		
		//! \brief 判断是否需要创建框选材质
		Gamebool IsNeedCreateRectSelectMaterial(FString strShaderName);

		//! \brief 添加因为没有填显卡而没有没付给材质的参数
		void AddMaterialIntParam(FName name, Gameint value);
		void AddMaterialFloatParam(FName name, Gamefloat value);
		void AddMaterialMatrix4dParam(FName name, void* value);
		void AddMaterialTextureParam(FName name, GameTexture* pTexture);
		void AddMaterialRenderTextureParam(FName name, GameRenderTexture* pTexture);
		void AddMaterialVec4dParam(FName name, GameVec4d vec);
	private:

		//! \brief 材质参数
		GameMaterialParam* m_pMaterialParam;

		//! \brief 动态材质
		UMaterialInstanceDynamic* m_pMID;

		//! \brief 分屏备份材质
		UMaterialInstanceDynamic* m_pViewportMID;

		//! \brief 与主材质对应的用来选择的材质
		UMaterialInstanceDynamic* m_pSelectionMaterial;

		//! \brief 与主材质对应的用来框选的材质
		UMaterialInstanceDynamic* m_pRectSelectMaterial;

		//! \brief 材质实例
		UMaterialInstanceConstant* m_pMIC;

		//! \brief 材质对应的数据类型
		DataType m_enDataType;

		//! \brief 未填int参数
		TMap<FName, Gameint> m_mapSetMaterialInt;

		//! \brief 未填float参数
		TMap<FName, Gamefloat> m_mapSetMaterialFloat;

		//! \brief 未填mat参数
		TMap<FName, void*> m_mapSetMaterialMatrix4d;

		//! \brief 未填得纹理参数
		TMap<FName, GameTexture*> m_mapSetMaterialTextures;


		//! \brief 未填得纹理参数
		TMap<FName, GameRenderTexture*> m_mapSetMaterialRenderTextures;

		//! \brief 未填FLinearColor参数
		TMap<FName, GameVec4d> m_mapSetMaterialVec4d;


		//! \brief 未填的纹理单元索引
		TMap<FName, Gameint> m_mapSetTextureIndex;

		//! \brief 网格单面渲染方式
		CullingMode m_eCullingMode;

		//! \brief 是否已经初始化
		Gamebool m_bInitial;
	};
}