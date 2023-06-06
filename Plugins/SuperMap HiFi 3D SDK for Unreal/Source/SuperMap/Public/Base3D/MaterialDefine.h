#pragma once

#include "CoreMinimal.h"

namespace SuperMapSDK {
	// 注释: 
	//	这里声明插件所有使用的材质，对于SDK而言
	//	UE4、UE5材质名字相同，但路径不同
	const FString MAT_PATH_PREFIX = TEXT("/Supermap/Materials/");
#if SM_FOR_UE_FIVE
	/*UE5*/
	const FString MAT_PATH_VERSION = TEXT("UE5/");
#else
	/*UE4*/
	const FString MAT_PATH_VERSION = TEXT("UE4/");
#endif
	//=================================================================================
	// 注释：
	//   这里主要声明针对与对象绘制的材质，
	//   以后应该迁移至Sample的工程更适合
	const FString SM_EXCAVATION_SIDEFACE_MAT = MAT_PATH_PREFIX + MAT_PATH_VERSION + FString(TEXT("ObjectRender/SM_ExcavationSideFace"));
	const FString SM_LINERENDER_MAT          = MAT_PATH_PREFIX + MAT_PATH_VERSION + FString(TEXT("ObjectRender/SM_LineRender"));
	const FString SM_SPHERERENDER_MAT        = MAT_PATH_PREFIX + MAT_PATH_VERSION + FString(TEXT("ObjectRender/SM_SphereRender"));
	const FString SM_BILLBOARDRENDER_MAT     = MAT_PATH_PREFIX + MAT_PATH_VERSION + FString(TEXT("ObjectRender/SM_BillboardRender"));
	const FString SM_BARRIERSPHERERENDER_MAT = MAT_PATH_PREFIX + MAT_PATH_VERSION + FString(TEXT("ObjectRender/SM_BarrierSphereRender"));
	const FString SM_VIEWSPHERERENDER_MAT    = MAT_PATH_PREFIX + MAT_PATH_VERSION + FString(TEXT("ObjectRender/SM_ViewSphereRender"));
	const FString SM_SKYRENDER_MAT           = MAT_PATH_PREFIX + MAT_PATH_VERSION + FString(TEXT("ObjectRender/SM_SkyRender"));
	const FString SM_GEORENDER_MAT           = MAT_PATH_PREFIX + MAT_PATH_VERSION + FString(TEXT("ObjectRender/SM_Geometry"));
	const FString SM_GEO_TEX_RENDER_MAT      = MAT_PATH_PREFIX + MAT_PATH_VERSION + FString(TEXT("ObjectRender/SM_GeometryWithTexture"));
	const FString SM_VIEWDOMERENDER_MAT      = MAT_PATH_PREFIX + MAT_PATH_VERSION + FString(TEXT("ObjectRender/SM_ViewDome"));
	const FString SM_GEO_NODOUBLESIDE_RENDER_MAT = MAT_PATH_PREFIX + MAT_PATH_VERSION + FString(TEXT("ObjectRender/SM_GeometryNoDoubleSide"));
	const FString SM_IDRENDER_MAT            = MAT_PATH_PREFIX + MAT_PATH_VERSION + FString(TEXT("ObjectRender/SM_IDRender"));
	const FString SM_SPATIALQUERY_MAT        = MAT_PATH_PREFIX + MAT_PATH_VERSION + FString(TEXT("ObjectRender/SM_SpatialQuery"));

	//===================================================================================
	// 注释：
	//   这里主要声明针对UGC渲染对象相关的材质 
	/*倾斜摄影*/
	const FString SM_OBLIQUEPHOTOGRAPHY_MAT = MAT_PATH_PREFIX + MAT_PATH_VERSION + FString(TEXT("SM_ObliquePhotography"));
	/*地形*/
	const FString SM_TERRAIN_MAT = MAT_PATH_PREFIX + MAT_PATH_VERSION + FString(TEXT("SM_Terrain"));
	/*点云*/
	const FString SM_POINTCLOUD_MAT = MAT_PATH_PREFIX + MAT_PATH_VERSION + FString(TEXT("SM_PointCloud"));
	/*模型PBR*/
	const FString SM_MODELPBR_MAT = MAT_PATH_PREFIX + MAT_PATH_VERSION + FString(TEXT("SM_ModelPBR"));
	/*模型*/
	const FString SM_MODEL_MAT = MAT_PATH_PREFIX + MAT_PATH_VERSION + FString(TEXT("SM_Model"));
	/*模型透明PBR*/
	const FString SM_MODELTRANSPARENTPBR_MAT = MAT_PATH_PREFIX + MAT_PATH_VERSION + FString(TEXT("SM_ModelTransparentPBR"));
	/*模型透明*/
	const FString SM_MODELTRANSPARENT_MAT = MAT_PATH_PREFIX + MAT_PATH_VERSION + FString(TEXT("SM_ModelTransparent"));
	/*模型Block*/
	const FString SM_MODELBLOCK_MAT = MAT_PATH_PREFIX + MAT_PATH_VERSION + FString(TEXT("SM_ModelBlock"));
	/*模型BlockTransparent*/
	const FString SM_MODELBLOCKTRANSPARENT_MAT = MAT_PATH_PREFIX + MAT_PATH_VERSION + FString(TEXT("SM_ModelBlockTransparent"));
	/*Billboard(KML标签专题图)*/
	const FString SM_BILLBOARD_MAT = MAT_PATH_PREFIX + MAT_PATH_VERSION + FString(TEXT("SM_Billboard"));
	/*数据集PBR*/
	const FString SM_MODELPROPBR_MAT = MAT_PATH_PREFIX + MAT_PATH_VERSION + FString(TEXT("SM_ModelProPBR"));
	/*数据集*/
	const FString SM_MODELPRO_MAT = MAT_PATH_PREFIX + MAT_PATH_VERSION + FString(TEXT("SM_ModelPro"));
	/*模型边框线*/
	const FString SM_MODELEDGE_MAT = MAT_PATH_PREFIX + MAT_PATH_VERSION + FString(TEXT("SM_ModelEdge"));
	/*实例化管线*/
	const FString SM_INSTANCEPIPE_MAT = MAT_PATH_PREFIX + MAT_PATH_VERSION + FString(TEXT("SM_InstancePipe"));
	/*模型实例化*/
	const FString SM_MODELINSTANCE_MAT = MAT_PATH_PREFIX + MAT_PATH_VERSION + FString(TEXT("SM_ModelInstance"));
	/*?*/
	const FString SM_POLYLINE_MAT = MAT_PATH_PREFIX + MAT_PATH_VERSION + FString(TEXT("SM_Polyline"));
	/*?*/
	const FString SM_MODIFYREGION_MAT = MAT_PATH_PREFIX + MAT_PATH_VERSION + FString(TEXT("SM_ModifyRegion"));
	//====================================================================================
	const FString GPU_SHARED_PARAM = MAT_PATH_PREFIX + MAT_PATH_VERSION + FString(TEXT("GPUParam/SM_GPUShareParam"));
	//====================================================================================
}