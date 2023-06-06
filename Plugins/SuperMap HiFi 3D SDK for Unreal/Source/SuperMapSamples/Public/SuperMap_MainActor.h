// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "ControlUE/RealspaceView.h"
#include "FSuperMap_MouseControl.h"
#include "Core/SceneType.h"
#include "Core/Selection3D.h"
#include "Engine/World.h"
#include "Engine/Engine.h"
#include "Data/DataSource.h"
#include "Data/Dataset.h"
#include "Core/Layer3DDatasetVectorPoint.h"
#include "Runtime/Engine/Classes/Engine/DataTable.h"
#include "GameFramework/Actor.h"
#include "SuperMap_MainActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMainActorDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOpenMultiFileDelegate);
static std::map<FName, FSuperMap_MouseControl*> m_mapMouseControl;

void OnSelectedInfoCallBack(void* pActor, SelectedInfo info);

USTRUCT(BlueprintType)
struct SUPERMAPSAMPLES_API FSuperMapTable : public FTableRowBase
{

	GENERATED_USTRUCT_BODY()

	//! \brief 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FSuperMapTable")
	FString InterfaceType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FSuperMapTable")
	FString Abbreviation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FSuperMapTable")
	FString Chinese;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FSuperMapTable")
	FString English;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FSuperMapTable")
	FString Japanese;
};

USTRUCT(BlueprintType)
struct SUPERMAPSAMPLES_API FSuperMap_LayerInfo {

	GENERATED_BODY()

	//! \brief 图层数据名字
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_MainActor")
	FString m_strName;

	//! \brief 图层数据路径
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_MainActor")
	FString m_strPath;

	//! \brief 数据集名称 or XML关键字
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_MainActor")
	FString m_strDatasetName;

	//! \brief iserver、本地 数据真实名称（在重名情况下，此名称为真实名称，m_strName 为“名称#Num”）
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_MainActor")
	FString m_strDataName;

	//! \brief 图层是否用于地形纹理蒙板
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_MainActor")
	bool m_bMarkerLayer;

	//! \brief 0:本地 1:iserver 2:公共
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_MainActor")
	int m_nType;

	//! \brief iserver : 图层类型(0:三维切片, 1: 地形, 2: 影像, 3: 其他服务)
	//! \brief 公共 : 地图服务类型(0: SuperMapTerrain 1 : STK地形 2 : 天地图地形 3 : 天地图 4:Bing Maps 5 : Open Street Map)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_MainActor")
	int32 m_nLayerType;

	//! \brief 公共服务
	//! \brief 账号
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_MainActor")
	FString m_strUserName;

	//! \brief 密码
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_MainActor")
	FString m_strPassWord;

	//! \brief 天地图
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_MainActor")
	int32 m_ImageType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_MainActor")
	float m_DPI;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_MainActor")
	FString m_Key;
};

USTRUCT(BlueprintType)
struct SUPERMAPSAMPLES_API FRealPosition
{
	GENERATED_BODY()

	//! \brief 经度 X
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_MainActor")
	FString m_strX;

	//! \brief 纬度 Y
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_MainActor")
	FString m_strY;

	//! \brief 高度 Z
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_MainActor")
	FString m_strZ;

	//! \brief 相机高度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_MainActor")
	FString m_strCameraHeight;
};

USTRUCT(BlueprintType)
struct SUPERMAPSAMPLES_API FMaterialInfo
{
	GENERATED_BODY()

	//! \brief 选择数据集模型的材质名称
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_MainActor")
	FString m_strMaterialName;

	//! \brief 选择数据集模型的图层名
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_MainActor")
	FString m_strLayerName;

	//! \brief 选择的材质
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_MainActor")
	UMaterialInterface* m_pSelectedMatInstance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_MainActor")
	bool m_bHsDeafaultParam;

	//! \brief 选择的材质UV缩放
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_MainActor")
	FVector4 m_vUVTiling;


	FMaterialInfo()
	{
		m_pSelectedMatInstance = nullptr;
		m_vUVTiling = FVector4(1, 1, 1, 1);
		m_bHsDeafaultParam = false;
	}
	~FMaterialInfo()
	{
		m_pSelectedMatInstance = nullptr;
		m_vUVTiling = FVector4(1, 1, 1, 1);
		m_bHsDeafaultParam = false;
	}
};

UCLASS(BlueprintType, Blueprintable)
class SUPERMAPSAMPLES_API ASuperMap_MainActor : public ACameraActor
{
	GENERATED_BODY()
public:
	ASuperMap_MainActor();
	~ASuperMap_MainActor();
protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void BeginDestroy() override;

	virtual bool ShouldTickIfViewportsOnly() const override;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//! \brief 鼠标左键按下
	void MouseLeftButtonDown();

	//! \brief 鼠标左键抬起
	void MouseLeftButtonUp();

	//! \brief 鼠标左键双击
	void MouseLeftButtonDoubleClick();

	//! \brief 鼠标右键抬起
	void MouseRightButtonUp();

	//! \brief 鼠标右键按下
	void MouseRightButtonDown();

	//! \brief 鼠标中键滚动
	void MouseMiddleButtonMove(float Value);

	//! \brief 鼠标中键按下
	void MouseMiddleButtonUp();

	//! \brief 鼠标中键抬起
	void MouseMiddleButtonDown();

	//! \brief 执行多播
	void ExecuteBroadcast();

	//! \brief 选择文件
	//! \return 如果选择文件成功返回true
	UFUNCTION(BlueprintCallable, Category = "SuperMap_MainActor")
	bool OpenFileDialog(FString strFileTypes);

	//! \brief 选择文件夹
	//! \return 如果选择文件夹成功返回true
	UFUNCTION(BlueprintCallable, Category = "SuperMap_MainActor")
	bool OpenFileFolderDialog();

	//! \brief 选择创建的场景类型
	//! \param nSceneType [in] 场景类型
	UFUNCTION(BlueprintCallable, Category = "SuperMap_MainActor")
	void SetSceneType(const int32 nSceneType);

	//! \biref 设置是否显示真实地理位置
	//! \param bShowRealPosition [in] true显示真实坐标
	UFUNCTION(BlueprintCallable, Category = "SuperMap_MainActor")
	void SetIsShowRealPosition(bool bShowRealPosition);

	//! \brief 获取文件类型
	//! \param layer [in] 图层名称
	//! \return 1：普通图层 2：地形图层
	UFUNCTION(BlueprintCallable, Category = "SuperMap_MainActor")
	int32 GetLayerType(FString layer, bool bBaseFile);

	//! \brief 添加本地图层
	UFUNCTION(BlueprintCallable, Category = "SuperMap_MainActor")
	bool AddLocalLayers(FSuperMap_LayerInfo strLayers);

	//! \brief 添加在线图层
	UFUNCTION(BlueprintCallable, Category = "SuperMap_MainActor")
	bool AddUrlLayers(FSuperMap_LayerInfo strLayers);

	//! \brief 添加arcgis服务
	UFUNCTION(BlueprintCallable, Category = "SuperMap_MainActor")
	bool AddWMTSMap(FSuperMap_LayerInfo strLayers);

	//! \brief 移除指定图层
	//! \param layer [in] 图层名称
	UFUNCTION(BlueprintCallable, Category = "SuperMap_MainActor")
	bool RemoveLayer(FString layerName);

	//! \brief 移除指定地形图层
	UFUNCTION(BlueprintCallable, Category = "SuperMap_MainActor")
	bool RemoveTerrainLayer();

	//! \brief Web端移除图层数组
	UFUNCTION(BlueprintCallable, Category = "SuperMap_MainActor")
	void RemoveLayer_Web(FString layerName);

	//! \brief 获取地形图层数量
	//! \return 图层数量
	UFUNCTION(BlueprintCallable, Category = "SuperMap_MainActor")
	int GetTerrainLayersCount();

	//! \brief 判断是否为多余地形图层
	//! \return false是多余地形图层
	UFUNCTION(BlueprintCallable, Category = "SuperMap_MainActor")
	bool IsSecondTerrainLayer();

	//! \brief 获取当前鼠标位置
	UFUNCTION(BlueprintCallable, Category = "SuperMap_MainActor")
	FRealPosition GetLocalPosition();

	//! \brief 获取鼠标位置，相机高度（实时）
	UFUNCTION(BlueprintCallable, Category = "SuperMap_MainActor")
	FRealPosition GetRealPosition();

	//! \brief 转xml
	UFUNCTION(BlueprintCallable, Category = "SuperMap_MainActor")
	void ToXML(FString strPath);

	//! \brief 添加XML中记录的图层
	UFUNCTION(BlueprintCallable, Category = "SuperMap_MainActor")
	void FromXML(FString strPath);

	//! \brief 图层外挂资材设置
	UFUNCTION(BlueprintCallable, Category = "SuperMap_MainActor")
	bool SetLayerMaterial(FName strName, FString strPath);

	//! \brief 图层对象外挂资材设置
	UFUNCTION(BlueprintCallable, Category = "SuperMap_MainActor")
	bool SetLayerObjectMaterial(FName strName, TMap<FString, FString> m_mapMaterialNameChanges);

	//! \brief 关闭编辑模式
	UFUNCTION(BlueprintCallable, Category = "SuperMap_MainActor")
	void SetEditorState(bool isTick);

	//! \brief 是否是运行模式
	UFUNCTION(BlueprintCallable, Category = "SuperMap_MainActor")
	bool PlayingActor();

	//! \brief 图层名修改
	UFUNCTION(BlueprintCallable, Category = "SuperMap_MainActor")
	FString ModificationLayerName(FString strName,int num);

	//! \brief 获取HypsometricSetting图层
	UFUNCTION(BlueprintCallable, Category = "SuperMap_MainActor")
	TArray<FString> GetHypsometricSettingLayers();

	//! \brief 获取S3M图层
	UFUNCTION(BlueprintCallable, Category = "SuperMap_MainActor")
	TArray<FString> GetS3MLayers();

	//! \brief 获取可分屏图层
	UFUNCTION(BlueprintCallable, Category = "SuperMap_MainActor")
	TArray<FString> GetRestoreLayers();

	//! \brief 获取选中对象的材质名称
	UFUNCTION(BlueprintCallable, Category = "SuperMap_MainActor")
	FMaterialInfo GetSelectMaterialInfo();

	//! \brief 设置美化材质
	UFUNCTION(BlueprintCallable, Category = "SuperMap_MainActor")
	void SetObjectMaterialInfo(FString LayerName, FString Key, FString materialName, FString materialPath);
	//! \brief 删除美化材质
	UFUNCTION(BlueprintCallable, Category = "SuperMap_MainActor")
	void DeleteObjectMaterialInfo(FString LayerName, FString Key);

	//! \brief 设置编辑方式
	UFUNCTION(BlueprintCallable, Category = "SuperMap_MainActor")
	void SetEditorAction(int mode);

	//! \brief 设置玩家操作方式
	UFUNCTION(BlueprintCallable, Category = "SuperMap_MainActor")
	void SetUserAction(int mode);

	//! \brief 设置相机Fov
	UFUNCTION(BlueprintCallable, Category = "SuperMap_MainActor")
	void SetCameraFov(float fFov);

	//! \brief 获取相机Fov
	UFUNCTION(BlueprintCallable, Category = "SuperMap_MainActor")
	float GetCameraFov();

	//! \brief 设置地理原点
	UFUNCTION(BlueprintCallable, Category = "SuperMap_MainActor")
	void SetGeoreferenceOrigin(float fLongitude, float fLatitude, float fAltitude);

	//! \brief 设置地理原点
	UFUNCTION(BlueprintCallable, Category = "SuperMap_MainActor")
	FVector GetGeoreferenceOrigin();

	//! \brief 设置是否计算法线
	UFUNCTION(BlueprintCallable, Category = "SuperMap_MainActor")
	void SetEnableComputeNormal(bool bEnable);

	//! \brief 设置碰撞检测
	UFUNCTION(BlueprintCallable, Category = "SuperMap_MainActor")
	void SetEnableCollision(bool bEnable);

	//===============================================================
	//! \brief 外挂资产获取
	UFUNCTION(BlueprintCallable, Category = "SuperMap_Dataset")
	bool SetFieldAssetResoure(FString strName, FString strFieldInfo, int nAssetType);

	//! \brief 获取数据源所有数据集
	UFUNCTION(BlueprintCallable, Category = "SuperMap_Dataset")
	TArray<FString> GetDatasetList(FString strFileName);

	//! \brief 获取数据源路径
	UFUNCTION(BlueprintCallable, Category = "SuperMap_Dataset")
	FString GetDatasourcePath(FString strName);

	//! \brief 设置数据集加载方式
	UFUNCTION(BlueprintCallable, Category = "SuperMap_Dataset")
	void SetImportAsset(bool bImportAsset);

	//! \brief 获取数据集名称
	UFUNCTION(BlueprintCallable, Category = "SuperMap_Dataset")
	FString GetDatasetName(FString strLayerName);

	//! \brief 获取数据集类型
	UFUNCTION(BlueprintCallable, Category = "SuperMap_Dataset")
	TArray<FString> GetFieldInfos(FString strName);

	//! \brief 获取数据集类型所含参数
	UFUNCTION(BlueprintCallable, Category = "SuperMap_Dataset")
	TArray<FString> QueryField(FString strName, FString strFieldInfo);

	//! \brief 添加点数据资产路径
	UFUNCTION(BlueprintCallable, Category = "SuperMap_Dataset")
	void AddAssetResoure(FString nIndex, FString strAssetResourePath);

	//! \brief 清空资产路径
	UFUNCTION(BlueprintCallable, Category = "SuperMap_Dataset")
	void ClearAssetResoure();

	//! \brief 模型数据集材质保存Json
	UFUNCTION(BlueprintCallable, Category = "SuperMap_Dataset")
	void DatasetMaterialToJson(FString strDataset);

	//! \brief 设置场景模式
	UFUNCTION(BlueprintCallable, Category = "SuperMap_Dataset")
	void SetStereoMode(int type);

	//! \brief 导出S3M图层关联UE材质
	//! 使用接口添加对应插件：
	//!"MtlAnalyzer",
	//!"MtlBaking",
	UFUNCTION(BlueprintCallable, Category = "SuperMap_MainActor")
	void ExportMaterialFromS3MLayer(FString ScpFilePath, FName LayerName);

	//! \brief 从Json文件中读取场景信息
	UFUNCTION(BlueprintCallable, Category = "SuperMap_MainActor")
	void SetSceneParamsFromJson();

	//! \brief 设置导出场景信息
	UFUNCTION(BlueprintCallable, Category = "SuperMap_MainActor")
	void SetSceneParams();

	//! \brief 设置导出替换材质信息
	UFUNCTION(BlueprintCallable, Category = "SuperMap_MainActor")
	void SetMaterialParams();

	//! \brief 获取数据集类型
	UFUNCTION(BlueprintCallable, Category = "SuperMap_MainActor")
	int GetDataSetType(FString layerName);
private:

	//! \brief 添加图层
	void AddLayers();

	//! \brief playstar初始点(默认球面高度3x10^9，平面8x10^4)
	void InitialPosition();

	//! \brief 初始化定位
	void InitialEnsureVisible();

	//! \brief 初始化无效区域
	void InitialShowInvalidation(bool bShow);

	//! \brief 读取xml文件
	void ParseFile(FString strFileDir);

	//! \brief 存储图层信息
	void ToJson();

	//! \brief 读取图层信息
	void FromJson();

	bool SetConditionAssetResoure(FString strName, TMap<FString, FString> mapConditionAssetResourePath, int nType);

	bool OpenDataset(FString strName, DataSource &dataSource, Dataset* &pDataset);

	void GetPosition();

	//! \brief 初始化加载种树
	void InitialAssetResoure(FString name);

	void SetInitialAsset(FString strKey);

	void GetDatasetGeoAttribute(Dataset* dateset, TArray<Geometry*>& arrGeometry, TArray<TMap<FString, FString>>& arrAttributes);

	//! \brief 读取S3M图层导出材质映射表的Json文件
	void LoadLayerS3MMaterialMapping(FString strPath);
public:
	UPROPERTY(BlueprintAssignable)
	FMainActorDelegate CallEvent;

	UPROPERTY(BlueprintAssignable)
	FOpenMultiFileDelegate CallFOpenMultiFile;

	//! \breif 添加的图层
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_MainActor")
	TArray<FSuperMap_LayerInfo> m_arrLayers;

	//! \breif 坐标信息
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_MainActor")
	FString m_strPosition;

	//! \breif 场景类型
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_MainActor")
	int32 m_nSceneType;

	//! \brief 插入点
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_MainActor")
	FVector m_vPosition;

	//! \brief 地理原点
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_MainActor")
	FVector m_vGeoreferenceOrigin;

	//是否显示真实坐标
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_MainActor")
	bool m_bShowRealPosition;

	//! \brief 是否存在S3M图层
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_MainActor")
	bool m_bIncludeS3M;

	//! \brief 是否存在地形图层
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_MainActor")
	bool m_bIncludeTerrain;

	//! \brief 本地选择图层地址
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_MainActor")
	FString m_strLayerAddress;

	//! \brief 是否显示无效区域
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_MainActor")
	bool m_bIsShowGlobe;

	//! \brief 是否显示当前点
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_MainActor")
	bool m_bShowMousePosition;

	//! \brief 是否获取当前点
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_MainActor")
	bool m_bGetMousePosition;

	//! \brief 是否删除默认球皮影像
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_MainActor")
	bool m_bDeleteDefaultGlobalImage;

	//! \brief 是否启用法线计算
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_MainActor")
	bool m_bComputeNormal;

	//! \brief 是否启用碰撞检测
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_MainActor")
	bool m_bEnableCollision;
	
	//! \brief 每次更新RO个数
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_MainActor")
	int32 m_nUpdateCount;

	//! \brief 是否批量加载图层
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_MainActor")
	bool m_bIsMultifile;

	//! \brief 使用语言
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_MainActor")
	FString m_strLanguage;

	//! \brief 编辑模式下的地理远点保存
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_MainActor")
	bool m_bEditorSaveGeoreference;
public:
	FMaterialInfo m_struMaterialInfo;

private:

	//! \brief 场景是否初始化
	Gamebool m_bInitialize;

	TArray<FString> m_arrFileAddress;

	std::map<FString, FString> m_mapFieldInfos;

	Gamebool m_bShouldTick;

	Workspace* m_pWorkspace;

	DataSources* m_pDataSources;

	Gamebool m_bImportAsset;

	FVector m_vMouse;

	//! \brief 当前点
	FRealPosition m_vMousePosition;

	FRealPosition m_vRealPosition;
};
