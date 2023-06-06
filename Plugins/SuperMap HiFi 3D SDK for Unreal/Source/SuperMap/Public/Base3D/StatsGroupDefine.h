#pragma once

#include "CoreMinimal.h"
#include "Stats/Stats.h"

#if SM_ENABLE_STATS
	#define STATS_SM(FunctionName, StatName, GroupName) \
		    DECLARE_SCOPE_CYCLE_COUNTER(FunctionName, StatName, GroupName);
#else 
	#define STATS_SM(FunctionName, StatName, GroupName)
#endif

/*Entity*/
DECLARE_STATS_GROUP(TEXT("Entity"), STATGROUP_SMEntity, STATCAT_Advanced);
#define STATS_SM_SETVERTEXDATAPACKAGE \
		STATS_SM(TEXT("SetVertexDataPackage"), STAT_SetVertexDataPackage, STATGROUP_SMEntity) 
#define STATS_SM_CREATEENTITY \
		STATS_SM(TEXT("CreateEntity") , STAT_CreateEntity, STATGROUP_SMEntity);
#define STATS_SM_DESTROYENTITY \
		STATS_SM(TEXT("DestroyEntity"), STAT_DestroyEntity, STATGROUP_SMEntity);
#define STATS_SM_CREATESUBMESH \
		STATS_SM(TEXT("CreateSubMesh"), STAT_CreateSubMesh, STATGROUP_SMEntity);
#define STATS_SM_ADDMATERIAL \
		STATS_SM(TEXT("AddMaterial")  , STAT_AddMaterial, STATGROUP_SMEntity);
#define STATS_SM_SETVERTEXDATAPACKAGESHAREDBUFFER \
		STATS_SM(TEXT("SetVertexDataPackageSharedBuffer"), STAT_SetVertexDataPackageSharedBuffer, STATGROUP_SMEntity);
#define STATS_SM_GETATTACHCOMPONENT \
		STATS_SM(TEXT("GetAttachComponent"), STAT_GetAttachComponent, STATGROUP_SMEntity)
#define STATS_SM_SETRENDERSTATE \
		STATS_SM(TEXT("SetRenderState"), STAT_SetRenderState, STATGROUP_SMEntity)
#define STATS_SM_SETBOUNDINGBOX \
		STATS_SM(TEXT("SetBoundingBox"), STAT_SetBoundingBox, STATGROUP_SMEntity)
#define STATS_SM_REMOVEALLMESH \
		STATS_SM(TEXT("RemoveAllSubMesh"), STAT_RemoveAllSubMesh, STATGROUP_SMEntity)
#define STATS_SM_ISMESHINITIALGPU \
		STATS_SM(TEXT("IsMeshInitialGPU"), STAT_IsMeshInitialGPU, STATGROUP_SMEntity)
#define STATS_SM_ASYNCUPLOADENTITY \
		STATS_SM(TEXT("AsyncUploadEntity"), STAT_AsyncUploadEntity, STATGROUP_SMEntity)



/*InstanceEntity*/
DECLARE_STATS_GROUP(TEXT("InstanceEntity"), STATGROUP_SMInstanceEntity, STATCAT_Advanced)
#define STATS_SM_CREATEINSTANCEENTITY \
		STATS_SM(TEXT("CreateInstanceEntity"), STAT_CreateInstanceEntity, STATGROUP_SMInstanceEntity) 
#define STATS_SM_GETINSTANCEMESHATTACHCOMPONENT \
		STATS_SM(TEXT("GetInstanceMeshAttachComponent"), STAT_GetInstanceMeshAttachComponent, STATGROUP_SMInstanceEntity) 
#define STATS_SM_WRITEINSTANCEBUFFER \
		STATS_SM(TEXT("WriteInstanceBuffer"), STAT_WriteInstanceBuffer, STATGROUP_SMInstanceEntity) 
#define STATS_SM_DESTROYINSTANCEENTITY \
		STATS_SM(TEXT("DestroyInstanceEntity"), STAT_DestroyInstanceEntity, STATGROUP_SMInstanceEntity) 
#define STATS_SM_SETINSTANCEBOUNDINGBOX \
		STATS_SM(TEXT("SetInstanceBoundingBox"), STAT_SetInstanceBoundingBox, STATGROUP_SMInstanceEntity) 

/*Texture*/
DECLARE_STATS_GROUP(TEXT("Texture"), STATGROUP_SMTexture, STATCAT_Advanced);
#define STATS_SM_CREATETEXTURE \
		STATS_SM(TEXT("CreateTexture"), STAT_CreateTexture, STATGROUP_SMTexture);
#define STATS_SM_DESTROYTEXTURE \
		STATS_SM(TEXT("DestroyTexture"), STAT_DestroyTexture, STATGROUP_SMTexture);
#define STATS_SM_UPDATETEXTURE \
		STATS_SM(TEXT("UpdateTexture"), STAT_UpdateTexture, STATGROUP_SMTexture);
#define STATS_SM_ISINITIALGPU \
		STATS_SM(TEXT("IsInitialGPU"), STAT_IsInitialGPU, STATGROUP_SMTexture);

/*Material*/
DECLARE_STATS_GROUP(TEXT("Material"), STATGROUP_SMMaterial, STATCAT_Advanced);
#define STATS_SM_CREATMATERIAL \
		STATS_SM(TEXT("CreateMaterial"), STAT_CreateMaterial, STATGROUP_SMMaterial);
#define STATS_SM_GETMATERIAL \
		STATS_SM(TEXT("GetMaterial"), STAT_GetMaterial, STATGROUP_SMMaterial);
#define STATS_SM_REMOVEMATERIAL \
		STATS_SM(TEXT("RemoveMaterial"), STAT_RemoveMaterial, STATGROUP_SMMaterial);
#define STATS_SM_FILLMATERIAL \
		STATS_SM(TEXT("FillMaterial"), STAT_FillMaterial, STATGROUP_SMMaterial);
#define STATS_SM_SETMATERIALPARAM_INT \
		STATS_SM(TEXT("SetMaterialIntParam"), STAT_SetMaterialIntParam, STATGROUP_SMMaterial);
#define STATS_SM_SETMATERIALPARAM_FLOAT \
		STATS_SM(TEXT("SetMaterialFloatParam"), STAT_SetMaterialFloatParam, STATGROUP_SMMaterial);
#define STATS_SM_SETMATERIALPARAM_VECTOR3D \
		STATS_SM(TEXT("SetMaterialVector3dParam"), STAT_SetMaterialVector3dParam, STATGROUP_SMMaterial);
#define STATS_SM_SETMATERIALPARAM_VECTOR4D \
		STATS_SM(TEXT("SetMaterialVector4dParam"), STAT_SetMaterialVector4dParam, STATGROUP_SMMaterial);
#define STATS_SM_SETMATERIALPARAM_MATRIX4D \
		STATS_SM(TEXT("SetMaterialMatrix4dParam"), STAT_SetMaterialMatrix4dParam, STATGROUP_SMMaterial);
#define STATS_SM_SETMATERIALPARAM_TEXTURE \
		STATS_SM(TEXT("SetMaterialTextureParam"), STAT_SetMaterialTextureParam, STATGROUP_SMMaterial);
#define STATS_SM_FILLTECHNIQUE \
		STATS_SM(TEXT("FillTechnique"), STAT_FillTechnique, STATGROUP_SMMaterial);

/*Camera*/
DECLARE_STATS_GROUP(TEXT("Camera"), STATGROUP_SMCamera, STATCAT_Advanced);
#define STATS_SM_SETVIEWMATRIX \
		STATS_SM(TEXT("SetViewMatrix"), STAT_SetViewMatrix, STATGROUP_SMCamera);
#define STATS_SM_SETPROJMATRIX \
		STATS_SM(TEXT("SetProjMatrix"), STAT_SetProjMatrix, STATGROUP_SMCamera);
#define STATS_SM_SETCAMERAPARAM \
		STATS_SM(TEXT("SetCameraParam"), STAT_SetCameraParam, STATGROUP_SMCamera);
#define STATS_SM_SETUGCPOSITION \
		STATS_SM(TEXT("SetUGCPosition"), STAT_SetUGCPosition, STATGROUP_SMCamera);
#define STATS_SM_SETLOOKAT \
		STATS_SM(TEXT("SetLookAt"), STAT_SetLookAt, STATGROUP_SMCamera);
#define STATS_SM_SETVIEWPORTRECT \
		STATS_SM(TEXT("SetViewportRect"), STAT_SetViewportRect, STATGROUP_SMCamera);
#define STATS_SM_SETORTHOWINDOW \
		STATS_SM(TEXT("SetOrthoWindow"), STAT_SetOrthoWindow, STATGROUP_SMCamera);
#define STATS_SM_SETMAINCAMERAVIEWMATRIX\
		STATS_SM(TEXT("SetMainCameraViewMatrix"), STAT_SetMainCameraViewMatrix, STATGROUP_SMCamera);

/*Component*/
DECLARE_STATS_GROUP(TEXT("Component"), STATGROUP_SMComponent, STATCAT_Advanced);
#define STATS_SM_CREATESCENENODE \
		STATS_SM(TEXT("CreateSceneNode"), STAT_CreateSceneNode, STATGROUP_SMComponent);
#define STATS_SM_DESTROYSCENENODE \
		STATS_SM(TEXT("DestroySceneNode"), STAT_DestroySceneNode, STATGROUP_SMComponent);
#define STATS_SM_SETUGCOBJECTMATRIX \
		STATS_SM(TEXT("SetUGCObjectMatrix"), STAT_SetUGCObjectMatrix, STATGROUP_SMComponent);
#define STATS_SM_SETVISIBLE \
		STATS_SM(TEXT("SetVisible"), STAT_SetVisible, STATGROUP_SMComponent);
#define STATS_SM_ATTACHENTITY \
		STATS_SM(TEXT("AttachEntity"), STAT_AttachEntity, STATGROUP_SMComponent);
#define STATS_SM_GETGAMEOBJECT \
		STATS_SM(TEXT("GetGameObject"), STAT_GetGameObject, STATGROUP_SMComponent);
#define STATS_SM_GETORCREATEROOTSCENENODE \
		STATS_SM(TEXT("GetOrCreateRootSceneNode"), STAT_GetOrCreateRootSceneNode, STATGROUP_SMComponent);
#define STATS_SM_DESTROYROOTSCENENODE \
		STATS_SM(TEXT("DestroyRootSceneNode"), STAT_DestroyRootSceneNode, STATGROUP_SMComponent);
#define STATS_SM_CREATECHILDSCENENODE \
		STATS_SM(TEXT("CreateChildSceneNode"), STAT_CreateChildSceneNode, STATGROUP_SMComponent);

/*RenderTexture*/
DECLARE_STATS_GROUP(TEXT("RenderTexture"), STATGROUP_SMRenderTexture, STATCAT_Advanced);
#define STATS_SM_CREATERENDERTEXTURE \
		STATS_SM(TEXT("CreateRenderTexture"), STAT_CreateRenderTexture, STATGROUP_SMRenderTexture);
#define STATS_SM_DESTROYRENDERTEXTURE \
		STATS_SM(TEXT("DestroyRenderTexture"), STAT_DestroyRenderTexture, STATGROUP_SMRenderTexture);
#define STATS_SM_GETFRAMEBUFFER \
		STATS_SM(TEXT("GetFrameBuffer"), STAT_GetFrameBuffer, STATGROUP_SMRenderTexture);
#define STATS_SM_DETELEFRAMEBUFFER \
		STATS_SM(TEXT("DeleteFrameBuffer"), STAT_DeleteFrameBuffer, STATGROUP_SMRenderTexture);
#define STATS_SM_UPDATESCENE \
		STATS_SM(TEXT("UpdateScene"), STAT_UpdateScene, STATGROUP_SMRenderTexture);
#define STATS_SM_GETCAMERA \
		STATS_SM(TEXT("GetCamera"), STAT_GetCamera, STATGROUP_SMRenderTexture);
#define STATS_SM_SETRENDERDEPTH \
		STATS_SM(TEXT("SetRenderDepth"), STAT_SetRenderDepth, STATGROUP_SMRenderTexture);
#define STATS_SM_CLEARFRAMEBUFFER \
		STATS_SM(TEXT("ClearFramebuffer"), STAT_ClearFramebuffer, STATGROUP_SMRenderTexture);

/*CustomVertexBuffer*/
DECLARE_STATS_GROUP(TEXT("CustomVertexBuffer"), STATGROUP_SMCustomVertexBuffer, STATCAT_Advanced);
#define STATS_SM_CREATERENDERRESOURCE \
		STATS_SM(TEXT("CreateRenderSources_RenderThread"), CreateRenderSources_RenderThread, STATGROUP_SMCustomVertexBuffer);

