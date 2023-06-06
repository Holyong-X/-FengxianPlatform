#pragma once

#include "CoreMinimal.h"

namespace SuperMapSDK {
	// ע��: 
	//	���������������ʹ�õĲ��ʣ�����SDK����
	//	UE4��UE5����������ͬ����·����ͬ
	const FString MAT_PATH_PREFIX = TEXT("/Supermap/Materials/");
#if SM_FOR_UE_FIVE
	/*UE5*/
	const FString MAT_PATH_VERSION = TEXT("UE5/");
#else
	/*UE4*/
	const FString MAT_PATH_VERSION = TEXT("UE4/");
#endif
	//=================================================================================
	// ע�ͣ�
	//   ������Ҫ��������������ƵĲ��ʣ�
	//   �Ժ�Ӧ��Ǩ����Sample�Ĺ��̸��ʺ�
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
	// ע�ͣ�
	//   ������Ҫ�������UGC��Ⱦ������صĲ��� 
	/*��б��Ӱ*/
	const FString SM_OBLIQUEPHOTOGRAPHY_MAT = MAT_PATH_PREFIX + MAT_PATH_VERSION + FString(TEXT("SM_ObliquePhotography"));
	/*����*/
	const FString SM_TERRAIN_MAT = MAT_PATH_PREFIX + MAT_PATH_VERSION + FString(TEXT("SM_Terrain"));
	/*����*/
	const FString SM_POINTCLOUD_MAT = MAT_PATH_PREFIX + MAT_PATH_VERSION + FString(TEXT("SM_PointCloud"));
	/*ģ��PBR*/
	const FString SM_MODELPBR_MAT = MAT_PATH_PREFIX + MAT_PATH_VERSION + FString(TEXT("SM_ModelPBR"));
	/*ģ��*/
	const FString SM_MODEL_MAT = MAT_PATH_PREFIX + MAT_PATH_VERSION + FString(TEXT("SM_Model"));
	/*ģ��͸��PBR*/
	const FString SM_MODELTRANSPARENTPBR_MAT = MAT_PATH_PREFIX + MAT_PATH_VERSION + FString(TEXT("SM_ModelTransparentPBR"));
	/*ģ��͸��*/
	const FString SM_MODELTRANSPARENT_MAT = MAT_PATH_PREFIX + MAT_PATH_VERSION + FString(TEXT("SM_ModelTransparent"));
	/*ģ��Block*/
	const FString SM_MODELBLOCK_MAT = MAT_PATH_PREFIX + MAT_PATH_VERSION + FString(TEXT("SM_ModelBlock"));
	/*ģ��BlockTransparent*/
	const FString SM_MODELBLOCKTRANSPARENT_MAT = MAT_PATH_PREFIX + MAT_PATH_VERSION + FString(TEXT("SM_ModelBlockTransparent"));
	/*Billboard(KML��ǩר��ͼ)*/
	const FString SM_BILLBOARD_MAT = MAT_PATH_PREFIX + MAT_PATH_VERSION + FString(TEXT("SM_Billboard"));
	/*���ݼ�PBR*/
	const FString SM_MODELPROPBR_MAT = MAT_PATH_PREFIX + MAT_PATH_VERSION + FString(TEXT("SM_ModelProPBR"));
	/*���ݼ�*/
	const FString SM_MODELPRO_MAT = MAT_PATH_PREFIX + MAT_PATH_VERSION + FString(TEXT("SM_ModelPro"));
	/*ģ�ͱ߿���*/
	const FString SM_MODELEDGE_MAT = MAT_PATH_PREFIX + MAT_PATH_VERSION + FString(TEXT("SM_ModelEdge"));
	/*ʵ��������*/
	const FString SM_INSTANCEPIPE_MAT = MAT_PATH_PREFIX + MAT_PATH_VERSION + FString(TEXT("SM_InstancePipe"));
	/*ģ��ʵ����*/
	const FString SM_MODELINSTANCE_MAT = MAT_PATH_PREFIX + MAT_PATH_VERSION + FString(TEXT("SM_ModelInstance"));
	/*?*/
	const FString SM_POLYLINE_MAT = MAT_PATH_PREFIX + MAT_PATH_VERSION + FString(TEXT("SM_Polyline"));
	/*?*/
	const FString SM_MODIFYREGION_MAT = MAT_PATH_PREFIX + MAT_PATH_VERSION + FString(TEXT("SM_ModifyRegion"));
	//====================================================================================
	const FString GPU_SHARED_PARAM = MAT_PATH_PREFIX + MAT_PATH_VERSION + FString(TEXT("GPUParam/SM_GPUShareParam"));
	//====================================================================================
}