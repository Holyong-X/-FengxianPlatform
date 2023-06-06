#pragma once

#include "CoreMinimal.h"
#include "Core/ROCache.h"
#include "Core/ClipMode.h"
#include "Base3D/CommonDefine.h"
#include "Graphics3D/GameStruct.h"
#include "DataExchange/MaterialConverter.h"
#include "map"
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			//===========CloudLicense API ============================
			typedef Gamebool(*UGLogin)(Gamechar* user, Gamechar* password, Gameint productType);
			typedef Gameint(*UGGetLicenseNum)();
			typedef Gamechar*(*UGGetLicenseID)(Gameint num);
			typedef Gamechar*(*UGGetLicenseRemainDays)(Gameint num);
			typedef Gamechar*(*UGGetLicenseVersion)(Gameint num);
			typedef Gamechar*(*UGGetLicenseUserId)(Gameint num);
			typedef Gamevoid(*UGLogout)();
			typedef Gameint(*UGConnect)(Gamechar* licId);
			typedef Gameint(*UGConnectTrial)();

			extern UGLogin _Login;
			extern UGGetLicenseNum	_GetLicenseNum;
			extern UGGetLicenseID _GetLicenseID ;
			extern UGGetLicenseRemainDays _GetLicenseRemainDays ;
			extern UGGetLicenseVersion _GetLicenseVersion ;
			extern UGGetLicenseUserId _GetLicenseUserId ;
			extern UGLogout _Logout ;
			extern UGConnect _Connect ;
			extern UGConnectTrial _ConnectTrial ;
			//=================================================================
			//===========License API=======================================
			typedef Gamebool(*UGLICENSEVERIFY_GAMEENGINE)();
			
			extern UGLICENSEVERIFY_GAMEENGINE _LicenseVerify_GameEngine;
			//=============================================================
			//===========Layer3D API=======================================
			typedef Gamevoid(*UGSETVISIBLE)(Gamebool bVisible, Gamechar* strLayerName);
			typedef Gamebool(*UGGETVISIBLE)(Gamechar* strLayerName);
			typedef Gamevoid(*UGHASCOMPRESSOPTIONS)(Gameint nCompressOptions, Gameint& bComp);
			typedef Gamechar* (*UGGETNODENAME)(Gamechar* strLayerName);
			typedef Gamelong (*UGGETLAYERNODENAMEHASHCODE)(Gamevoid* pUGLayer);
			typedef Gamevoid(*UGSETORIGINALPOSITION)(Gameint scenceType, Gamechar* strLayerName, Gamefloat x, Gamefloat y, Gamefloat z);
			typedef Gamevoid(*UGGETCENTREPOSITION)(Gamechar* strLayerName, Gamefloat& x, Gamefloat& y);
			typedef Gamevoid(*UGGETLAYERBOUNDS)(Gamechar* strLayerName, Gamefloat& left, Gamefloat& bottom, Gamefloat& right, Gamefloat& top);
			typedef Gamevoid(*UGSETINITIALIZED)(Gamevoid* pUGLayer, Gamebool bInitialized);
			
			typedef Gamevoid(*UGSETCUSTOMCLIPPLANE)(Gamevoid* pUGLayer, Gamedouble dFX, Gamedouble dFY, Gamedouble dFZ,
				Gamedouble dSX, Gamedouble dSY, Gamedouble dSZ,
				Gamedouble dTX, Gamedouble dTY, Gamedouble dTZ);
			typedef Gamevoid(*UGSETCUSTOMCLIPBOX)(Gamevoid* pUGLayer, Gamevoid* pGeoBox, Gameint clipPart);
			typedef Gamevoid(*UGGETCUSTOMCLIPBOX)(Gamevoid* pLayer, Gamevoid*& pGeoBox);
			typedef Gamevoid(*UGGETCLIPPLANEPARAMETER)(Gamevoid* pLayer, Gamedouble* pMat, Gamedouble*& pPlanes, Gameint& nCount);
			typedef Gamevoid(*UGISCLIP)(Gamevoid* pLayer);
			typedef Gamevoid(*UGSETCLIPLINECOLOR)(Gamevoid* pLayer, Gamefloat fR, Gamefloat fG, Gamefloat fB, Gamefloat fA);
			typedef Gamevoid(*UGGETCLIPLINECOLOR)(Gamevoid* pLayer, Gamefloat& fR, Gamefloat& fG, Gamefloat& fB, Gamefloat& fA);
			typedef Gamevoid(*UGGETPLANECLIPMODE)(Gamevoid* pLayer, PlaneClipMode& mode);
			typedef Gamevoid(*UGCLEARCUSTOMCLIPPLANE)(Gamevoid* pLayer);
			typedef Gamevoid(*UGSETSWIPEENABLED)(Gamevoid* pLayer, Gamebool bValue);
			typedef Gamebool(*UGGETSWIPEENABLED)(Gamevoid* pLayer);
			typedef Gamevoid(*UGSETSWIPEREGION)(Gamevoid* pLayer, Gamedouble dLeft, Gamedouble dTop, Gamedouble dRight, Gamedouble dBottom);
			typedef Gamevoid(*UGGETSWIPEREGION)(Gamevoid* pLayer, Gamedouble& dLeft, Gamedouble& dTop, Gamedouble& dRight, Gamedouble& dBottom);
			typedef Gamevoid(*UGLAYER3DADDSELECTEDID)(Gamevoid* pLayer, Gameint nID);
			typedef Gamevoid(*UGLAYER3DREMOVEALLSELECTEDID)(Gamevoid* pLayer);
			typedef Gamevoid(*UGLAYER3DSETOPAQUERATE)(Gamevoid* pLayer, Gamedouble value);
			typedef Gamedouble(*UGLAYER3DGETOPAQUERATE)(Gamevoid* pLayer);
			typedef Gamebool(*UGLayer3D_IsMarkerLayer)(Gamevoid* pLayer);
			typedef Gamevoid(*UGLayer3D_SetMarkerLayer)(Gamevoid* pLayer, Gamebool bIsMarkerLayer);
			typedef Gameint(*UGLayer3D_GetOSGBType)(Gamevoid* pLayer);
			typedef Gamevoid(*UGLAYER3DSETSELECTSTYLE)(Gamevoid* pLayer, Gamevoid* pStyle);
			typedef Gamevoid(*UGLAYER3DGETSELECTSTYLE)(Gamevoid* pLayer, Gamevoid*& pStyle);
			typedef Gameint(*UGLAYER3DGETID)(Gamevoid* pLayer);
			typedef Gameint(*UGLAYER3DGETTYPE)(Gamevoid* pLayer);
			typedef Gamevoid(*UGLAYER3DGETNAME)(Gamevoid* pLayer, Gamechar* &layerName);
			typedef Gamevoid(*UGLAYER3DSETSTYLE)(Gamevoid* pLayer, Gamevoid* pStyle);
			typedef Gamevoid(*UGLAYER3DGETSTYLE)(Gamevoid* pLayer, Gamevoid*& pStyle3D);
			typedef Gamevoid(*UGLAYER3DSETMAXOBJECTVISIBLEDISTANCE)(Gamevoid* pLayer, Gamedouble value);
			typedef Gamevoid(*UGLAYER3DSETMINOBJECTVISIBLEDISTANCE)(Gamevoid* pLayer, Gamedouble value);
			typedef Gamevoid(*UGLAYER3DGETMAXMINOBJECTVISIBLEDISTANCE)(Gamevoid* pLayer, Gamedouble& dmax, Gamedouble& dmin);
			typedef Gamevoid(*UGLAYER3DGETDATAPATH)(Gamevoid* pLayer, Gamechar*& filePath);
			typedef Gamevoid(*UGLAYER3DREMOVEGPUSHAREDPARAMETERS)(Gameint nLayerID);

			extern UGLayer3D_IsMarkerLayer          _Layer3D_IsMarkerLayer;
			extern UGLayer3D_SetMarkerLayer          _Layer3D_SetMarkerLayer;
			extern UGSETVISIBLE          _SetVisible;
			extern UGGETVISIBLE  _GetVisible;
			extern UGHASCOMPRESSOPTIONS  _HasCompressOptions;
			extern UGGETNODENAME         _GetNodeName       ;
			extern UGGETLAYERNODENAMEHASHCODE _GetLayerNodeNameHashCode ;
			extern UGSETORIGINALPOSITION _SetOriginalPosition ;
			extern UGGETCENTREPOSITION   _GetCentrePosition   ;
			extern UGGETLAYERBOUNDS      _GetLayerBounds      ;
			extern UGSETINITIALIZED      _SetInitialized      ;

			extern UGSETCUSTOMCLIPPLANE  _SetCustomClipPlane      ;
			extern UGSETCUSTOMCLIPBOX    _SetCustomClipBox        ;
			extern UGGETCUSTOMCLIPBOX    _GetCustomClipBox        ;
			extern UGGETCLIPPLANEPARAMETER _GetClipPlaneParameter ;
			extern UGISCLIP			    _IsClip                ;
			extern UGSETCLIPLINECOLOR      _SetClipLineColor      ;
			extern UGGETCLIPLINECOLOR      _GetClipLineColor      ;
			extern UGGETPLANECLIPMODE      _GetPlaneClipMode      ;
			extern UGCLEARCUSTOMCLIPPLANE  _ClearCustomClipPlane  ;
			extern UGSETSWIPEENABLED		_SetSwipeEnabled	   ;
			extern UGGETSWIPEENABLED		_GetSwipeEnabled	   ;
			extern UGSETSWIPEREGION		_SetSwipeRegion		   ;
			extern UGGETSWIPEREGION		_GetSwipeRegion		   ;
			extern UGLAYER3DADDSELECTEDID  _Layer3D_AddSelectedID ;
			extern UGLAYER3DREMOVEALLSELECTEDID _Layer3D_RemoveAllSelectedID ;
			extern UGLAYER3DSETOPAQUERATE _Layer3D_SetOpaqueRate	;
			extern UGLAYER3DGETOPAQUERATE _Layer3D_GetOpaqueRate	;
			extern UGLayer3D_GetOSGBType  _Layer3D_GetOSGBType;
			extern UGLAYER3DSETSELECTSTYLE _Layer3D_SetSelectStyle;
			extern UGLAYER3DGETSELECTSTYLE _Layer3D_GetSelectStyle;
			extern UGLAYER3DGETID			_Layer3D_GetID;
			extern UGLAYER3DGETTYPE			_Layer3D_GetType;
			extern UGLAYER3DGETNAME			_Layer3D_GetName;
			extern UGLAYER3DSETSTYLE        _Layer3D_SetStyle;
			extern UGLAYER3DGETSTYLE		_Layer3D_GetStyle;
			extern UGLAYER3DSETMAXOBJECTVISIBLEDISTANCE		_SetMaxObjectVisibleDistance;
			extern UGLAYER3DSETMINOBJECTVISIBLEDISTANCE		_SetMinObjectVisibleDistance;
			extern UGLAYER3DGETMAXMINOBJECTVISIBLEDISTANCE	_GetMaxMinObjectVisibleDistance;
			extern UGLAYER3DGETDATAPATH						_Layer3D_GetDataPath;
			extern UGLAYER3DREMOVEGPUSHAREDPARAMETERS		_Layer3D_RemoveGPUSharedParameters;
			//===============================================================

			//========Layer3DS3MFile========================================
			typedef Gamevoid(*UGGetFieldInfosObject)(Gameint nID, Gameint nLayerID, ObjectFieldInfo*** & result, Gameint & nCount);
			typedef Gamevoid(*UGGetAllFieldValueObject)(Gameint nID, Gameint nLayerID, ObjectFieldInfo*** &result, Gameint &nCount);
			typedef Gamevoid(*UGFreeArrayObjectFieldNode)(ObjectFieldInfo*** &result, Gameint nCount);
			typedef Gamevoid(*UGGetFieldInfos)(Gameint nLayerID, ObjectFieldInfo***& result, Gameint& nCount);
			typedef Gamevoid(*UGSetLODRangeScale)(Gameint nLayerID, Gamefloat values);
			typedef Gamefloat(*UGGetLODRangeScale)(Gameint nLayerID);
			typedef Gamevoid(*UGGETSCENENODENAME)(Gameint nLayerID, Gamechar* &strSceneNodeName);
			typedef Gamevoid (*UGCALFLATTENPARAM)(Gameint nLayerID, Gamebool bIsPlane,
										Gamedouble * pPoints, Gamedouble* pUV, Gameint nPointCount,
										Gamedouble* pMatrixWorldView, Gamedouble &dFlattenRadius);
			
			typedef Gameint(*UGADDFLATTENREGION)(Gameint nLayerID, Gamevoid* pGeometry, Gamechar* strName);
			typedef Gamevoid(*UGRELEASEALLFLATTENREGIONS)(Gameint nLayerID);
			typedef Gamebool(*UGDELETEATFLATTENREGION)(Gameint nLayerID, Gameint nIndex);
			typedef Gameint(*UGINDEXOFFLATTENREGION)(Gameint nLayerID, Gamechar* strName);
			typedef Gamevoid(*UGGETFLATTENREGION)(Gameint nLayerID, Gameint nIndex, Gamevoid*& pGeometry);
			typedef Gameint(*UGGETFLATTENREGIONCOUNT)(Gameint nLayerID);
			typedef Gamechar* (*UGGETFLATTENREGIONTAG)(Gameint nLayerID, Gameint nIndex);
			typedef Gamebool(*UGSETFLATTENREGIONTAG)(Gameint nLayerID, Gameint nIndex, Gamechar* tag);
			typedef Gamevoid(*UGGETFLATTENSHADERPARAMTER)(
				Gameint nLayerID, Gameint& flattenMode,
				Gamedouble& minX, Gamedouble& maxX, Gamedouble& minY, Gamedouble& maxY,
				Gamedouble* pFlattenWorldMatrix, Gamevoid*& pFlattenTextureHandle);
			typedef Gamedouble(*UGGetMaxDataValue)(Gameint nLayerID);
			typedef Gamedouble(*UGGetMinDataValue)(Gameint nLayerID);
			typedef Gamevoid(*UGSETOBJECTSVISIBLE)(Gamevoid* pLayer, Gameint* pIDs, Gameint nCount, Gamebool bVisible);
			typedef Gamevoid(*UGSETOBJECTSCOLOR)(Gamevoid* pLayer, Gameint* pIDs, Gameint nCount, Gamedouble dR, Gamedouble dG, Gamedouble dB, Gamedouble dA);
			typedef Gamevoid(*UGGETOBJECTSCOLOR)(Gamevoid* pLayer, Gameint*& ids, Gameint& nCount, Gamedouble*& dRGBA);
			typedef Gamevoid(*UGREMOVEOBJECTSCOLOR)(Gamevoid* pLayer, Gameint* ids, Gameint nCount);
			typedef Gamevoid(*UGRESETOBJECTSCOLOR)(Gamevoid* pLayer);
			typedef Gamevoid(*UGSETOBJECTSMATERIAL)(Gamevoid* pLayer, Gameint* pIDs, Gameint nCount, Gamechar* strMaterialName);
			typedef Gamevoid(*UGSETEXCAVATION)(Gamevoid* pLayer, Gamebool bValue);
			typedef Gamevoid(*UGSETMODIFYREGIONS)(Gamevoid* pLayer, Gamevoid** pGeometry, Gameint nCount, Gameint type);
			typedef Gamevoid(*UGCLEARMODIFYREGIONS)(Gamevoid* pLayer);
			typedef Gamevoid(*UGGETEXCAVATIONSHADERPARAMTER)(Gamevoid* pLayer,
				Gamedouble& minX, Gamedouble& maxX, Gamedouble& minY, Gamedouble& maxY, Gamedouble* pExcavationWorldMatrix, Gamevoid*& pExcavationTextureHandle);
			typedef Gamevoid(*UGADDMATERIALASSOCIATEWITHSCP)(Gamevoid* pLayer, Gamechar*& strMaterialJsonFilePath, Gamechar*& strScpFilePath);
			typedef Gamevoid(*UGSETDECODEMESHOPT)(Gamevoid* pLayer, Gamebool value);
			typedef Gamebool(*UGGETDECODEMESHOPT)(Gamevoid* pLayer);
			typedef Gamevoid(*UGSETLOADINGPRIORITY)(Gamevoid* pLayer, Gameint type);
			typedef Gameint(*UGGETLOADINGPRIORITY)(Gamevoid* pLayer);
			typedef Gamedouble(*UGS3MLAYERGETDATAMAXVALUE)(Gamevoid* pLayer);
			typedef Gamedouble(*UGS3MLAYERGETDATAMINVALUE)(Gamevoid* pLayer);
			typedef Gamevoid(*UGS3MLAYERSETCOVERIMAGERYLAYER)(void* pLayer, void** pImageLayer, int nCount);
		
			// 获取属性名字
			extern UGGetFieldInfosObject      _GetFieldInfosObject      ;
			// 获取属性
			extern UGGetAllFieldValueObject   _GetAllFieldValueObject   ;
			// 删除属性
			extern UGFreeArrayObjectFieldNode _FreeArrayObjectFieldNode ;
			// 获取属性字段名字
			extern UGGetFieldInfos            _GetFieldInfos            ;
			// 获取设置图层LOD层级
			extern UGSetLODRangeScale         _SetLODRangeScale         ;
			// 获取图层LOD层级
			extern UGGetLODRangeScale         _GetLODRangeScale         ;
			// 获取图层渲染节点名字
			extern UGGETSCENENODENAME		   _GetSceneNodeName         ;
			extern UGCALFLATTENPARAM		   _CalFlattenParam          ;

			extern UGADDFLATTENREGION		   _AddFlattenRegion		 ;
			extern UGRELEASEALLFLATTENREGIONS _ReleaseAllFlattenRegions ;
			extern UGDELETEATFLATTENREGION    _DeleteAtFlattenRegion    ;
			extern UGINDEXOFFLATTENREGION     _IndexOfFlattenRegion     ;
			extern UGGETFLATTENREGION         _GetFlattenRegion         ;
			extern UGGETFLATTENREGIONCOUNT    _GetFlattenRegionCount    ;
			extern UGGETFLATTENREGIONTAG      _GetFlattenRegionTag      ;
			extern UGSETFLATTENREGIONTAG      _SetFlattenRegionTag      ;
			extern UGGETFLATTENSHADERPARAMTER _GetFlattenShaderParamter ;
			extern UGGetMaxDataValue		   _GetMaxDataValue			 ;
			extern UGGetMinDataValue		   _GetMinDataValue			 ;
			extern UGSETOBJECTSVISIBLE	       _SetObjectsVisible ;
			extern UGSETOBJECTSCOLOR		   _SetObjectsColor ;
			extern UGGETOBJECTSCOLOR							_GetObjectsColor;
			extern UGREMOVEOBJECTSCOLOR							_RemoveObjectsColor;
			extern UGRESETOBJECTSCOLOR							_ResetObjectsColor;
			extern UGSETOBJECTSMATERIAL		   _SetObjectsMaterial;
			extern UGSETMODIFYREGIONS		   _SetModifyRegions;
			extern UGCLEARMODIFYREGIONS		   _ClearModifyRegions;
			extern UGSETEXCAVATION			   _SetExcavation;
			extern UGGETEXCAVATIONSHADERPARAMTER _GetExcavationShaderParamter;
			extern UGADDMATERIALASSOCIATEWITHSCP _AddMaterialAssociateWithScp;
			extern UGSETDECODEMESHOPT			_SetDecodeMeshopt;
			extern UGGETDECODEMESHOPT			_GetDecodeMeshopt;
			extern UGSETLOADINGPRIORITY			_SetLoadingPriority;
			extern UGGETLOADINGPRIORITY			_GetLoadingPriority;
			extern UGS3MLAYERGETDATAMAXVALUE	_S3MLayer_GetDataMaxValue;
			extern UGS3MLAYERGETDATAMINVALUE	_S3MLayer_GetDataMinValue;
			extern UGS3MLAYERSETCOVERIMAGERYLAYER	_S3MLayer_SetCoverImageryLayer;

			//===============================================================

			//=======Layer3Ds================================================

			typedef Gameint(*UGADDLAYER)(Gamevoid* & pLayer3D , Gamechar* strDataName, Gameint nType, Gamebool bAddToHead, Gamechar* strName);
			typedef Gameint(*UGADD)(Gamevoid* & pLayer3D, Gamechar* iserverURL, Gameint layerType, Gamechar* layerName, Gamechar* dataName, Gamebool addToHead);
			typedef Gameint(*UGADDDATASETLAYER)(Gamechar* strDatasetName);
			typedef Gamechar*(*UGGETLAYERNODENAME)(Gameint index);
			typedef Gamebool(*UGGETISVISIBLE)();
			typedef Gamevoid(*UGSETISVISIBLE)(Gamebool bVisible);
			typedef Gameint(*UGADDONLINEMAP)(Gamevoid* & pLayer3D, Gamechar* strStdLayerName, Gameint layerType, Gamechar* strStdUserName, Gamechar* strStdPassWord);
			typedef Gameint(*UGADDARCGISMAP)(Gamevoid* & pLayer3D, Gamechar* strServerRootUrl, Gamechar* layerName);
			typedef Gamebool(*UGREMOVELAYERS)(Gamechar* layerName);
			typedef Gameint(*UGADDTIANDITU)(Gamevoid* & pLayer3D, Gamechar* iserverURL, Gamechar* layerName, Gamechar* dataName, Gamefloat fDPI, Gameint imageType, Gamebool addToHead);
			typedef Gameint(*UGADDOSGBLAYER)(Gamevoid*& pLayer, Gamechar* strXMLFile, Gamechar* strRootPath, Gamechar* strName, Gamechar* strKeyWord);
			typedef Gameint(*UGADDDATASETMODEL)(Gamevoid* & pLayer3D, Gamechar* strDataName, Gamechar* strName);

			extern UGADDLAYER           _AddLayer			;
			extern UGADD                _Add				;
			extern UGADDDATASETLAYER    _AddDatasetLayer	;
			extern UGGETLAYERNODENAME   _GetLayerNodeName	;
			extern UGGETISVISIBLE       _GetIsVisible		;
			extern UGSETISVISIBLE		 _SetIsVisible		;
			extern UGADDONLINEMAP		 _AddOnlineMap		;
			extern UGADDARCGISMAP		 _AddArcgisMap		;
			extern UGREMOVELAYERS		 _RemoveLayers		;
			extern UGADDTIANDITU        _AddTianditu		;
			extern UGADDOSGBLAYER		_AddOSGBLayer		;
			extern UGADDDATASETMODEL    _AddDatasetModel	;
			//===============================================================
			//==============GeoBox API=======================================
			typedef Gamevoid(*UGGEOBOXCREATE)(Gamevoid* &pUGGeoBox);
			typedef Gamevoid(*UGGEOBOXDESTROY)(Gamevoid* &pUGGeoBox);
			typedef Gamedouble(*UGGEOBOXGETBOXHEIGHT)(Gamevoid*pUGGeoBox);
			typedef Gamedouble(*UGGEOBOXGETBOXWIDTH)(Gamevoid*pUGGeoBox);
			typedef Gamedouble(*UGGEOBOXGETBOXLENGTH)(Gamevoid*pUGGeoBox);
			typedef bool(*UGGEOBOXSETBOXHEIGHT)(Gamevoid*pUGGeoBox, Gamedouble dHeight);
			typedef bool(*UGGEOBOXSETBOXWIDTH)(Gamevoid*pUGGeoBox, Gamedouble dWidth);
			typedef bool(*UGGEOBOXSETBOXLENGTH)(Gamevoid*pUGGeoBox, Gamedouble dLength);
			typedef Gamevoid(*UGGEOBOXGETCENTERPOINT)(Gamevoid*pUGGeoBox, Gamedouble& dx, Gamedouble& dy, Gamedouble& dz);
			typedef Gamevoid(*UGGEOBOXCOPY)(Gamevoid* pGeometry, Gamevoid*& pNewGeometry);

			extern UGGEOBOXCREATE			_GeoBox_Create			;
			extern UGGEOBOXDESTROY			_GeoBox_Destroy			;
			extern UGGEOBOXGETBOXHEIGHT	_GeoBox_GetBoxHeight	;
			extern UGGEOBOXGETBOXWIDTH		_GeoBox_GetBoxWidth		;
			extern UGGEOBOXGETBOXLENGTH	_GeoBox_GetBoxLength	;
			extern UGGEOBOXSETBOXHEIGHT	_GeoBox_SetBoxHeight	;
			extern UGGEOBOXSETBOXWIDTH		_GeoBox_SetBoxWidth		;
			extern UGGEOBOXSETBOXLENGTH	_GeoBox_SetBoxLength	;
			extern UGGEOBOXGETCENTERPOINT  _GeoBox_GetCenterPoint  ;
			extern UGGEOBOXCOPY				_GeoBox_Copy;
			//==============ROCacheManager===================================

			//! \brief 获取所有的更新数据包函数指针
			typedef Gamevoid(*UGGETALLUPDATE)(
				RONode***      &pAddNodes            , Gameint & nAddCount, 
				RONode***      &pUpdateNodes         , Gameint & nUpdateCount, 
				ROEmptyNode*** &pDeleteNodes         , Gameint & nDeleteCount,
				ROMaterial***  &pAddMaterials        , Gameint & nAddMaterialCount,
				ROMaterial***  &pUpdateMaterials     , Gameint & nUpdateMaterialCount,
				Gamelong***     &pDeleteMaterials     , Gameint & nDeleteMaterialCount,
				ROTexture***   &pAddTextures         , Gameint & nAddTextureCount,
				ROTexture***   &pUpdateTextures      , Gameint & nUpdateTextureCount,
				Gamelong***     &pDeleteTextures      , Gameint & nDeleteTextureCount,
				bool bNeedReverse);

			//! \brief 释放空场景节点
			typedef Gamevoid(*UGFREEARRAYROEMPTYNODE)(ROEmptyNode*** & pEmptyNodes, Gameint nCount);

			//! \brief 释放场景节点
			typedef Gamevoid(*UGFREEARRAYRONODE)(RONode*** & pEmptyNodes, Gameint nCount);

			//! \brief 释放材质
			typedef Gamevoid(*UGFREEARRAYROMATERIAL)(ROMaterial*** & pROMaterials, Gameint nCount);

			//! \brief 释放纹理
			typedef Gamevoid(*UGFREEARRAYROTEXTURE)(ROTexture*** & pROTextures, Gameint nCount);

			//! \brief 释放HashCode
			typedef Gamevoid(*UGFREEARRAYHASHCODE)(Gamelong *** & pHashCodes, Gameint nCount);

			//! \brief 释放buffer
			typedef Gamevoid(*UGFREEBYTE)(Gamechar* & pByte);

			//! \brief 释放buffer
			typedef Gamevoid(*UGFREE_UCHAR)(Gameuchar* pUChar);

			//! \broef 拆分矩阵
			typedef Gamevoid(*UGDECOMPOSEVIEWMATRIX)(
				Gamedouble* & mat         ,
				Gamedouble  & fPostionX   , Gamedouble &fPostionY   , Gamedouble &fPostionZ,
				Gamedouble  & fScaleX     , Gamedouble &fScaleY     , Gamedouble &fSceleZ,
				Gamedouble  & fQuaternionX, Gamedouble &fQuaternionY, Gamedouble &fQuaternionZ,
				Gamedouble  & fQuaternionW);

			typedef Gamevoid(*UGDECOMPOSEVIEWMATRIX2)(
				Gamedouble* & mat,
				Gamedouble & dPostionX, Gamedouble &dPostionY, Gamedouble &dPostionZ,
				Gamedouble & dAxisUpX, Gamedouble &dAxisUpY, Gamedouble &dAxisUpZ,
				Gamedouble & dAxisRightX, Gamedouble &dAxisRightY, Gamedouble &dAxisRightZ);

			typedef Gamevoid(*UGINITDATABUFFERCALLBACKHANDLE)(Gamevoid* deleteFramebufferCallBackHandler);

			typedef Gamevoid(*UGINITRENDERTEXTURECALLBACKHANDLE)(Gamevoid* createCallbackHandler, Gamevoid* destroyCallbackHandler,
				Gamevoid* getFramebufferCallbackHandler, Gamevoid* updateSceneCallbackHandler, Gamevoid* setRenderDepthHandler,Gamevoid* getCamCallbackHandler, Gamevoid* clearFramebufferCallbackHandler);

			typedef Gamevoid(*UGINITCAMERACALLBACKHANDLE)(Gamevoid* setViewMatrix, Gamevoid* setProjectionMatrix, Gamevoid* setCameraParam, Gamevoid* setPosition, Gamevoid* setLookAt,
				Gamevoid* setViewportRect, Gamevoid* setOrthoWindow);

			typedef Gamevoid(*UGINITSCENENODECALLBACKHANDLE)(Gamevoid* createSceneNodeHandler, Gamevoid* destroySceneNodeHandler,
				Gamevoid* setVisibleHandler, Gamevoid* setSceneNodeVisibleHandler, Gamevoid* setObjectMatrixHandler, Gamevoid* attachMeshHandler,
				Gamevoid* getSceneNodeHandler, Gamevoid* getRootSceneNodeHandler, Gamevoid* destroyRootSceneNodeHandler, 
				Gamevoid* createChildSceneNodeHandler);

			typedef Gamevoid(*UGINITENTITYCALLBACKHANDLE)(Gamevoid* createMeshHandler, Gamevoid* destroyMeshHandler,
				Gamevoid* setVertexDataPackage, Gamevoid* setVertexDataPackageSharedBuffer, Gamevoid* createSubMesh, Gamevoid* getAttachSceneNode, Gamevoid* addMaterial, Gamevoid* appendMaterial, Gamevoid* removeMaterial, Gamevoid* setRenderState, Gamevoid* setBoundingBox,
				Gamevoid* removeAllSubMesh, Gamevoid* isMeshInitialGPU, Gamevoid* arrSubMeshMaterial, Gamevoid* updateSubMeshes);
			typedef Gamevoid(*UGINITTEXTURECALLBACKHANDLE)(Gamevoid* createTexture, Gamevoid* destroyTexture, Gamevoid* updateTexture, Gamevoid* isInitialGPU);
			typedef Gamevoid(*UGINITMATERIALMANAGERCALLBACKHANDLE)(Gamevoid* getMaterial, Gamevoid* createMaterial, Gamevoid* removeMaterial, Gamevoid* fillMaterial, Gamevoid* fillTechnique,
				Gamevoid* setMaterialIntParam, Gamevoid* setMaterialFloatParam, Gamevoid* setMaterialVector3dParam,
				Gamevoid* setMaterialVector4dParam, Gamevoid* setMaterialMatrix4dParam, Gamevoid* setMaterialTextureParam);
			typedef Gamevoid(*UGINITMATERIALMANAGERSHARECALLBACKHANDLE)(Gamevoid* setMaterialIntShareParam, Gamevoid* setMaterialfloatShareParam, 
				Gamevoid* setMaterialVector3dShareParam, Gamevoid* setMaterialVector4dShareParam, Gamevoid* setMaterialMatrix4dShareParam);

			typedef Gamevoid(*UGINITINSTANCEMESHCALLBACKHANDLE)(Gamevoid* collector);

			typedef Gamevoid(*UGINITMAINCAMERACALLBACKHANDLE)(Gamevoid* setViewMatrix);
			typedef Gamevoid(*UGINITGRAPHICSCALLBACKHANDLE)(Gamevoid* getShadowBound, Gamevoid* getGameViewPrjMatrix, Gamevoid* getProjMatrixforUE);
			
			extern UGGETALLUPDATE						_GetAllUpdata					 ;
			extern UGFREEARRAYROEMPTYNODE				_FreeArrayROEmptyNode			 ;
			extern UGFREEARRAYRONODE					_FreeArrayRONode				 ;
			extern UGFREEBYTE							_FreeByte						 ;
			extern UGFREE_UCHAR							_FreeUChar						 ;
			extern UGFREEARRAYROMATERIAL				_FreeArrayROMaterial			 ;
			extern UGFREEARRAYROTEXTURE				_FreeArrayROTexture				 ;
			extern UGFREEARRAYHASHCODE					_FreeArrayHashCode				 ;
			extern UGDECOMPOSEVIEWMATRIX				_DecomposeViewMatrix			 ;
			extern UGDECOMPOSEVIEWMATRIX2				_DecomposeViewMatrix2			 ;
			extern UGINITDATABUFFERCALLBACKHANDLE		_InitDataBufferCallbackHandle    ;
			extern UGINITRENDERTEXTURECALLBACKHANDLE	_InitRenderTextureCallbackHandle ;
			extern UGINITCAMERACALLBACKHANDLE			_InitCameraCallbackHandle        ;
			extern UGINITSCENENODECALLBACKHANDLE		_InitSceneNodeCallbackHandle     ;
			extern UGINITENTITYCALLBACKHANDLE          _InitEntityCallbackHandle        ;
			extern UGINITTEXTURECALLBACKHANDLE		    _InitTextureCallbackHandle       ;
			extern UGINITMATERIALMANAGERCALLBACKHANDLE _InitMaterialManagerCallbackHandle      ;
			extern UGINITMATERIALMANAGERSHARECALLBACKHANDLE  _InitMaterialManagerShareCallbackHandle;
			extern UGINITINSTANCEMESHCALLBACKHANDLE    _InitInstanceMeshCallbackHandle  ;
			extern UGINITMAINCAMERACALLBACKHANDLE		_InitMainCameraCallbackHandle    ;
			extern UGINITGRAPHICSCALLBACKHANDLE		_InitGraphicsCallbackHandle		 ;
			//===============================================================

			//===============Scene===========================================
			typedef Gamevoid(*UGSETCAMERA)(Gamefloat * & mat, Gamefloat fNearDist, Gamefloat fFarDist, Gamefloat fFov, Gamefloat fAspect);
			typedef Gamevoid(*UGSCENE_GETCAMERA)(Gamevoid* pScene, Gamevoid*& pCamera);
			typedef Gamebool(*UGSCENE_GETCREATESKIRT)();
			typedef Gamevoid(*UGSCENE_SETCREATESKIRT)(Gamebool  bIsCreateSkirt);
			typedef Gamevoid(*UGSCENE_SETSKIRTHEIGHT)(Gamefloat fHeight);
			typedef Gamevoid(*UGLONGITUDELATITUDETOGAMEENGINE)(Gamedouble & dLon, Gamedouble & dLat, Gamedouble & dAltitude,
				Gamedouble & dQuaternionX, Gamedouble & dQuaternionY, Gamedouble & dQuaternionZ, Gamedouble & dQuaternionW);
			typedef Gamevoid(*UGTOXML)(Gamechar* strFileAddress);
			typedef Gamevoid(*UGSCENE_SETSHOWINVALIDATION)(Gamebool bShow);
			typedef Gamevoid(*UGSCENE_FLYTOCAMERA)(Gamevoid * pScene, Gamevoid * pCamera, Gameint nMilliseconds);
			typedef Gamevoid(*UGSCENE_SETTERRAINEXAGGERATION)(Gamevoid* pScene, Gamedouble dValue);
			typedef Gamevoid(*UGSCENE_GETTERRAINEXAGGERATION)(Gamevoid* pScene, Gamedouble & dValue);
			typedef Gamevoid(*UGSCENE_SETENDFLYFUNC)(Gamevoid* pUGScene, Gamevoid* pScene, Gamevoid* flownCallBack);
			typedef Gamevoid(*UGSCENE_SETSTEREOMODE)(Gamevoid* pScene, Gameint type);
			typedef Gameint(*UGSCENE_GETSTEREOMODE)(Gamevoid* pScene);
			typedef Gamebool(*UGSCENE_FROMXMLFORPATH)(Gamevoid* pScene, Gamechar* path);
			typedef Gamevoid(*UGSCENE_GETLAYER3DS)(Gamevoid* pScene, Gamevoid**& pUGLayers, Gameint& nCount);
			typedef Gamevoid(*UGSCENE_GETTERRAINLAYERS)(Gamevoid* pScene, Gamevoid**& pUGTerrainLayers, Gameint& nCount);
			typedef Gamevoid(*UGSCENE_UPDATA)(Gamevoid* pScene);
			typedef Gamevoid(*UGSCENE_GETGLOBALIMAGE)(Gamevoid* pScene, Gamevoid* & pUGCGlobalImage);
			typedef Gamevoid(*UGSCENE_GLOBALREFRESHRASTER)(Gamevoid* pScene, Gamedouble dLeft, Gamedouble dTop, Gamedouble dRight, Gamedouble dBottom);

			extern UGSETCAMERA                      _SetCamera         ;
			extern UGSCENE_GETCAMERA				 _Scene_GetCamera	;
			extern UGSCENE_GETCREATESKIRT			 _GetCreateSkirt	;
			extern UGSCENE_SETCREATESKIRT			 _SetCreateSkirt    ;
			extern UGSCENE_SETSKIRTHEIGHT           _SetSkirtHeight    ;
			extern UGLONGITUDELATITUDETOGAMEENGINE  _LongitudeLatitudeToGameEngine ;
			extern UGTOXML							 _ToXML							;
			extern UGSCENE_SETSHOWINVALIDATION		 _Scene_SetShowInvalidation		;
			extern UGSCENE_FLYTOCAMERA				 _Scene_FlyToCamera ;
			extern UGSCENE_SETTERRAINEXAGGERATION	 _Scene_SetTerrainExaggeration ;
			extern UGSCENE_GETTERRAINEXAGGERATION	 _Scene_GetTerrainExaggeration ;
			extern UGSCENE_SETENDFLYFUNC			 _Scene_SetEndFlyFunc ;
			extern UGSCENE_SETSTEREOMODE			 _Scene_SetStereoMode ;
			extern UGSCENE_GETSTEREOMODE			 _Scene_GetStereoMode ;
			extern UGSCENE_FROMXMLFORPATH			 _Scene_FromXML;
			extern UGSCENE_GETLAYER3DS				 _Scene_GetLayer3Ds;
			extern UGSCENE_GETTERRAINLAYERS			 _Scene_GetTerrainLayers;
			extern UGSCENE_UPDATA					 _Scene_Updata;
			extern UGSCENE_GETGLOBALIMAGE            _Scene_GetGlobalImage;
			extern UGSCENE_GLOBALREFRESHRASTER		 _Scene_GlobalRefreshRaster;

			typedef Gameint(*UGSCENE_GETTILEBOUNDS)(Gamevoid* pScene, Gamedouble dLon, Gamedouble dLat, Gamedouble &left, Gamedouble &bottom, Gamedouble &right, Gamedouble &top);
			extern UGSCENE_GETTILEBOUNDS			 _Scene_GetTileBounds;

			typedef Gameint(*UGSCENE_REFRESHRASTER)(Gamevoid* pScene);
			extern UGSCENE_REFRESHRASTER			 _Scene_RefreshRaster;
			//===============================================================
			//==================SceneControl=================================

			typedef bool(*UGINITIALSCENE)(Gameint nWidth, Gameint nHeight, Gameint nType, Gameint nDpix, Gameint nDpiy, Gamevoid* &pScene);
			typedef Gamevoid(*UGDESTROYSCENE)();
			typedef Gamevoid(*UGKILL)();
			typedef Gamevoid(*UGSETPOSITION)(Gamefloat x, Gamefloat y, Gamefloat z);
			typedef Gamevoid(*UGRENDER)();
			typedef Gamevoid(*UGSceneControl_GetWorkspace)(Gamevoid* &pWorkspace);
			typedef Gamevoid(*UGSceneControl_Onsize)(Gameint cx, Gameint cy);
			typedef Gamevoid(*UGSceneControl_SetMultiTexture)(bool bMultiTexture);
			
			extern UGINITIALSCENE _InitialScene ;
			extern UGDESTROYSCENE _DestroyScene ;
			extern UGKILL         _Kill         ;
			extern UGSETPOSITION  _SetPosition  ;
			extern UGRENDER       _Render       ;
			extern UGSceneControl_GetWorkspace _SceneControl_GetWorkspace ;
			extern UGSceneControl_Onsize _SceneControl_OnSize ;
			extern UGSceneControl_SetMultiTexture _SceneControl_SetMultiTexture ;
			//===============================================================


			//==================Workspace=================================

			typedef bool(*UGWorkspace_GetDataSources)(Gamevoid* pWorkspace, Gamevoid* &pDataSources);

			extern UGWorkspace_GetDataSources _Workspace_GetDataSources ;


			//===============================================================



			//==================DataSources=================================

			typedef bool(*UGDataSources_GetAt)(Gameint nIndex, Gamechar** &strDataSourceAlias, Gamevoid* pDataSources, Gamevoid*& pDataSource);
			typedef bool(*UGDataSources_SetAt)(Gamechar* strDataSourceAlias, Gamevoid* pDataSources, Gamevoid* pDataSource);
			typedef bool(*UGDataSources_ReleaseAt)(Gamechar* strDataSourceAlias, Gamevoid* pDataSources);
			typedef bool(*UGDataSources_GetAtByAlias)(Gamechar* cAlias, Gamevoid* pDataSources, Gamevoid*& pDataSource);

			extern UGDataSources_GetAt _DataSources_GetAt ;
			extern UGDataSources_SetAt _DataSources_SetAt ;
			extern UGDataSources_ReleaseAt _DataSources_ReleaseAt ;
			extern UGDataSources_GetAtByAlias _DataSources_GetAtByAlias ;

			//===============================================================


			//===============TerrainLayer====================================
			typedef Gamevoid(*UGGETTERRAINBOUNDS)(Gamefloat &left, Gamefloat &bottom, Gamefloat &right, Gamefloat &top);
			typedef Gamevoid(*UGSETTERRAINVISIBLE)(Gamebool bVisible, Gamechar* strLayerName);
			typedef Gamebool(*UGGETTERRAINVISIBLE)(Gamechar* strLayerName);
			typedef Gamedouble(*UGGETMINHEIGHT)();
			typedef Gamedouble(*UGGETMAXHEIGHT)();
			typedef Gamebool(*UGGETSHOWINVALIDATION)();
			typedef Gamevoid(*UGSETSHOWINVALIDATION)(Gamebool bShow);
			typedef Gamevoid(*UGSETTERRAINLODRANGESCALE)(Gamefloat values);
			typedef Gamefloat(*UGGETTERRAINLODRANGESCALE)();
			typedef Gamefloat(*UGTerrainLayer_GetTopLevel)();
			typedef Gamevoid(*UGTerrainLayer_SetSlopeSetting)(Gamevoid* pSlopeSetting);
			typedef Gamevoid(*UGTERRAINLAYER_GETNAME)(Gamechar* &layerName);
			typedef Gamedouble(*UGTERRAINLAYER_GETHEIGHT)(Gamedouble dLon, Gamedouble dLat);

			extern UGGETTERRAINBOUNDS        _GetTerrainBounds        ;
			extern UGSETTERRAINVISIBLE       _SetTerrainVisible       ;
			extern UGGETTERRAINVISIBLE       _GetTerrainVisible       ;
			extern UGGETMINHEIGHT            _GetMinHeight            ;
			extern UGGETMAXHEIGHT            _GetMaxHeight            ;
			extern UGGETSHOWINVALIDATION     _GetShowInvalidation     ;
			extern UGSETSHOWINVALIDATION     _SetShowInvalidation     ;
			extern UGSETTERRAINLODRANGESCALE _SetTerrainLODRangeScale ;
			extern UGGETTERRAINLODRANGESCALE _GetTerrainLODRangeScale ;
			extern UGTerrainLayer_GetTopLevel _TerrainLayer_GetTopLevel ;
			extern UGTerrainLayer_SetSlopeSetting _TerrainLayer_SetSlopeSetting ;
			extern UGTERRAINLAYER_GETNAME		_TerrainLayer_GetName;
			extern UGTERRAINLAYER_GETHEIGHT		_TerrainLayer_GetHeight;
			//===============================================================
			//============TerrainLayers======================================

			typedef Gamebool(*UGHASTIN)();
			typedef Gamebool(*UGADDTERRAINLAYER)(Gamechar* strSCTFileName);
			typedef Gamebool(*UGADDWEBTERRAIN)(Gamechar* iserverURL, Gamechar* customLayerName);
			typedef Gamebool(*UGREMOVETERRAINLAYERS)(Gameint Index);
			typedef Gamevoid(*UGADDSTK)(Gamechar* stkURL, Gamechar* customLayerName);
			typedef Gamevoid(*UGADDTIANDITUTERRAIN)(Gamechar* tianURL, Gamechar* customLayerName);
			typedef Gamevoid(*UGGETMODIFYTERRAINSETTING)(Gamevoid*& pModifyTerrain);
			
			extern UGHASTIN              _HasTIN              ;
			extern UGADDTERRAINLAYER     _AddTerrainLayer     ;
			extern UGADDWEBTERRAIN       _AddWebTerrain       ;
			extern UGREMOVETERRAINLAYERS _RemoveTerrainLayers ;
			extern UGADDSTK              _AddSTK              ;
			extern UGADDTIANDITUTERRAIN  _AddTiandituTerrain  ;
			extern UGGETMODIFYTERRAINSETTING  _GetModifyTerrainSetting;

			//===============================================================
			//==============CameraControl API====================================
			typedef Gamevoid(*UGRAYINTERSECTIONWITHSPHERE) (
				Gamedouble dStartX      , Gamedouble dStartY      , Gamedouble dStartZ,
				Gamedouble dDirectionX  , Gamedouble dDirectionY  , Gamedouble dDirectionZ,
				Gamedouble & dIntersectX, Gamedouble & dIntersectY, Gamedouble & dIntersectZ);

			typedef Gamevoid(*UGRAYINTERSECTIONWITHSPHEREADNRADIUS) (
				Gamedouble dStartX, Gamedouble dStartY, Gamedouble dStartZ,
				Gamedouble dDirectionX, Gamedouble dDirectionY, Gamedouble dDirectionZ,
				Gamedouble & dIntersectX, Gamedouble & dIntersectY, Gamedouble & dIntersectZ,
				Gamedouble dRadius);

			typedef Gamevoid(*UGRAYINTERSECTIONWITHELLIPSOIDADNRADIUS) (
				Gamedouble dStartX, Gamedouble dStartY, Gamedouble dStartZ,
				Gamedouble dDirectionX, Gamedouble dDirectionY, Gamedouble dDirectionZ,
				Gamedouble& dIntersectX, Gamedouble& dIntersectY, Gamedouble& dIntersectZ,
				Gamedouble dRadius);

			typedef Gamevoid(*UGCALLOCATIONANDROTATION)(
				Gamedouble vStartX , Gamedouble vStartY , Gamedouble vStartZ,
				Gamedouble vEndX   , Gamedouble vEndY   , Gamedouble vEndZ,
				Gamedouble vOriginX, Gamedouble vOriginY, Gamedouble vOriginZ,
				Gamedouble qOriginX, Gamedouble qOriginY, Gamedouble qOriginZ, Gamedouble qOriginW,
				Gamedouble &vOutX  , Gamedouble &vOutY  , Gamedouble & vOutZ,
				Gamedouble &qOutX  , Gamedouble &qOutY  , Gamedouble & qOutZ, Gamedouble & qOutW);

			typedef Gamevoid(*UGCALPITCHANDHEADING)(
				Gamedouble vecRotateAxisX  , Gamedouble vecRotateAxisY  , Gamedouble vecRotateAxisZ    ,
				Gamedouble vEyeToTargetX   , Gamedouble vEyeToTargetY   , Gamedouble vEyeToTargetZ     ,
				Gamedouble cameraQuaX      , Gamedouble cameraQuaY      , Gamedouble cameraQuaZ        , Gamedouble cameraQuaW,
				Gamedouble vCameraLocationX, Gamedouble vCameraLocationY, Gamedouble vCameraLocationZ  ,
				Gamedouble fWidthRadio     , Gamedouble fHeightRadio    ,
				Gamedouble& quaX           , Gamedouble& quaY           , Gamedouble& quaZ, Gamedouble& quaW,
				Gamedouble& transsX        , Gamedouble& transsY        , Gamedouble& transsZ);

			typedef Gamevoid(*UGCALPITCHANDHEADINGWITHWORLDOFFSET)(
				Gamedouble vecRotateAxisX, Gamedouble vecRotateAxisY, Gamedouble vecRotateAxisZ,
				Gamedouble vEyeToTargetX, Gamedouble vEyeToTargetY, Gamedouble vEyeToTargetZ,
				Gamedouble cameraQuaX, Gamedouble cameraQuaY, Gamedouble cameraQuaZ, Gamedouble cameraQuaW,
				Gamedouble vCameraLocationX, Gamedouble vCameraLocationY, Gamedouble vCameraLocationZ,
				Gamedouble vWorldOffsetX, Gamedouble vWorldOffsetY, Gamedouble vWorldOffsetZ,
				Gamedouble fWidthRadio, Gamedouble fHeightRadio,
				Gamedouble& quaX, Gamedouble& quaY, Gamedouble& quaZ, Gamedouble& quaW,
				Gamedouble& transsX, Gamedouble& transsY, Gamedouble& transsZ);

			extern UGRAYINTERSECTIONWITHSPHERE          _RayIntersectionWithSphere       ;
			extern UGCALLOCATIONANDROTATION             _CalLocationAndRotation          ;
			extern UGCALPITCHANDHEADING                 _CalPitchAndHeading              ;
			extern UGCALPITCHANDHEADINGWITHWORLDOFFSET  _CalPitchAndHeadingWithWorldOffset;
			extern UGRAYINTERSECTIONWITHSPHEREADNRADIUS _RayIntersectionWithSphereAndRadius ;
			extern UGRAYINTERSECTIONWITHELLIPSOIDADNRADIUS	_RayIntersectionWithEllipsoidAndRadius;
			//===============================================================
			//======================Camera API===================================
			typedef Gamevoid(*UGCAMERACREATE)(Gamevoid* &pUGCamera);
			typedef Gamevoid(*UGCAMERADESTORY)(Gamevoid* &pUGCamera);
			typedef Gamedouble(*UGCAMERAGETHEADING)(Gamevoid* pUGCamera);
			typedef Gamedouble(*UGCAMERAGETTILT)(Gamevoid* pUGCamera);
			typedef Gamedouble(*UGCAMERAGETROLL)(Gamevoid* pUGCamera);
			typedef Gamedouble(*UGCAMERAGETLONGTITUDE)(Gamevoid* pUGCamera);
			typedef Gamedouble(*UGCAMERAGETLATITUDE)(Gamevoid* pUGCamera);
			typedef Gamedouble(*UGCAMERAGETALTITUDE)(Gamevoid* pUGCamera);
			typedef Gamevoid(*UGCAMERASETVIEWMATRIXDOUBLE)(Gamevoid* pUGCamera, Gamedouble* mat);
			typedef Gamevoid(*UGCAMERAGETVIEWPROJECTMATRIX)(Gamevoid* pUGCamera, Gamedouble*& viewMatrix, Gamedouble*&pProjectMatrix);
			typedef Gamevoid(*UGCAMERAGETPOSITION)(Gamevoid* pCamera, Gamedouble& dx, Gamedouble& dy, Gamedouble& dz);
			typedef Gamevoid(*UGCAMEARGETROTATION)(Gamevoid* pCamera, Gamedouble& dx, Gamedouble& dy, Gamedouble& dz, Gamedouble& dw);
			typedef Gamevoid(*UGCAMERAGETDIRECTION)(Gamevoid* pCamera, Gamedouble& dx, Gamedouble& dy, Gamedouble& dz);
			typedef Gamevoid(*UGCAMERAGETUP)(Gamevoid* pCamera, Gamedouble& dx, Gamedouble& dy, Gamedouble& dz);
			typedef Gamevoid(*UGCAMERAGETRIGHT)(Gamevoid* pCamera, Gamedouble& dx, Gamedouble& dy, Gamedouble& dz);
			typedef Gamevoid(*UGCAMERAGETPROJECTPARAMETER)(Gamevoid* pCamera, Gamedouble& dFov, Gamedouble& dAspect, Gamedouble& dNear, Gamedouble& dFar);
			typedef Gamevoid(*UGCAMERASETUGCSTATE)(Gamevoid* pCamera, Gamedouble dx, Gamedouble dy, Gamedouble dz, Gamedouble dPitch, Gamedouble dHeading, Gamedouble dRoll);

			extern UGCAMERACREATE           _CameraCreate     ;
			extern UGCAMERADESTORY          _CameraDestory    ;
			extern UGCAMERAGETHEADING       _CameraGetHeading ;
			extern UGCAMERAGETTILT             _CameraGetTilt ;
			extern UGCAMERAGETROLL             _CameraGetRoll ;
			extern UGCAMERAGETLONGTITUDE	_Camera_GetLongitude ;
			extern UGCAMERAGETLATITUDE		_Camera_GetLatitude ;
			extern UGCAMERAGETALTITUDE		_Camera_GetAltitude ;
			extern UGCAMERASETVIEWMATRIXDOUBLE _CameraSetViewMatrix ;
			extern UGCAMERAGETVIEWPROJECTMATRIX _CameraGetViewProjectMatrix ;
			extern UGCAMERAGETPOSITION                _CameraGetPosition ;
			extern UGCAMEARGETROTATION                _CameraGetRotation ;
			extern UGCAMERAGETDIRECTION	          _CameraGetDirection ;
			extern UGCAMERAGETUP                            _CameraGetUp ;
			extern UGCAMERAGETRIGHT                      _CameraGetRight ;
			extern UGCAMERAGETPROJECTPARAMETER _CameraGetProjectParamter ;
			extern UGCAMERASETUGCSTATE				   _CameraSetUGCState ;
			//===============RealspaceView===================================
			typedef Gamevoid(*UGRGBAID)(Gamefloat fR, Gamefloat fG, Gamefloat fB, Gamefloat fA, Gameuint  & id);
			typedef Gamevoid(*UGRGBAObjectID)(Gamefloat fR, Gamefloat fG, Gamefloat fB, Gamefloat fA, Gameint& nID, Gameint& nLayerID);
			typedef Gamevoid(*UGIDRGBA)(Gameuint id, Gamefloat & fR, Gamefloat & fG, Gamefloat &fB, Gamefloat &fA);

			extern UGRGBAID       _RGBAID       ;
			extern UGRGBAObjectID _RGBAObjectID ;
			extern UGIDRGBA       _IDRGBA       ;

			//===============================================================
			//================MathEngine=====================================
			typedef Gamevoid(*UGTRIANGULATE)(Gamefloat*& pPoint3Ds, Gameint nPointCount, Gameint nSubCount, Gameint* nPolyCounts, Gameint*& arrIntIndex, Gameint& nCount);
			typedef Gamevoid(*UGFREEUGINT)(Gameint*& pIndex);
			typedef Gamevoid(*UGFREE_UG_UINT)(Gameuint*& p);
			typedef Gamevoid(*UGFREE_UG_USHORT)(unsigned short*& p);
			typedef Gamevoid(*UGFREEUGFLOAT)(Gamefloat*& pData);
			typedef Gamevoid(*UGCALHEADINGANDPITCH)(bool bIsSphere, 
				Gamedouble dPosX, Gamedouble dPosY, Gamedouble dPosZ, 
				Gamedouble dDirectionX, Gamedouble dDirectionY, Gamedouble dDirectionZ,
				Gamedouble &dHeading, Gamedouble &dPitch);

			typedef Gamelong(*UGCALHASHCODE)(Gamevoid* &pVoid);
			typedef Gamelong(*UGCALHASHCODEBYCHAR)(Gamechar* pChar);
			typedef Gamevoid(*UGFREEDOUBLEARRAY)(Gamedouble** pDouble, Gameint nCount);
			typedef Gamevoid(*UGFREELONG)(Gamelong* pLong);
			typedef Gamevoid(*UGFREE_CHAR_POINTER_ARRAY)(Gamechar** pCharArray, Gameint nCount);
			typedef Gamevoid(*UGCHAMFER)(Gamedouble*& dCurved, Gamedouble*& dLine, Gameint& nCount, Gameint uFactor, Gamebool bIsSym, Gameint nSlice);
			typedef Gamevoid(*UGFREEUGDOUBLE)(Gamedouble*& pData);
			typedef Gamebool(*UGKDTREE_CREATE)(Gamevoid*& pKdTree, Gamedouble*& dPointArray, Gameint nPtCount, Gameint*& nIndexPack, Gameint nBucketSize);
			typedef Gamevoid(*UGKDTREE_SEARCHKDTREEDIS2)(Gamevoid* pKdTree, Gamedouble dx, Gamedouble dy, Gamedouble dz, Gamedouble dRadius,
				Gameint& nPointSearched, Gameint*& arrPointIndex, Gamedouble*& arrPointDist);
			typedef Gamevoid(*UGKDTREE_DISPOSE)(Gamevoid*& pKdTree);
			typedef Gamevoid(*UGCALMATRIX)(Gamedouble dLon, Gamedouble dLat, Gamedouble dAltitude, Gamedouble* pMatrix);

			extern UGTRIANGULATE        _Triangulate         ;
			extern UGFREEUGINT			 _FreeUGInt           ;
			extern UGFREE_UG_UINT	     _FreeUGUint;
			extern UGFREE_UG_USHORT	     _FreeUGUshort		  ;
			extern UGFREEUGFLOAT		 _FreeUGFloat         ;
			extern UGCALHEADINGANDPITCH _CalHeadingAndPitch  ;
			extern UGCALHASHCODE		 _CalHashCode         ;
			extern UGCALHASHCODEBYCHAR  _CalHashCodeByChar   ;
			extern UGFREEDOUBLEARRAY	 _FreeDoubleArray     ;
			extern UGFREELONG			 _FreeLong            ;
			extern UGFREE_CHAR_POINTER_ARRAY	_FreeCharPointerArray;
			extern UGCHAMFER					_Chamfer;
			extern UGFREEUGDOUBLE				_FreeUGDouble;
			extern UGKDTREE_CREATE				_KDTree_Create;
			extern UGKDTREE_SEARCHKDTREEDIS2	_KDTree_SearchKdTreeDis2;
			extern UGKDTREE_DISPOSE				_KDTree_Dispose;
			extern UGCALMATRIX					_CalMatrix;
			//===============================================================
			//============Sightline API======================================
			typedef Gamevoid(*UGCARTESIANTOSPHERICALLD)(Gamefloat fX, Gamefloat fY, Gamefloat fZ,
				Gamefloat &fLon, Gamefloat &fLat, Gamefloat &fAltitude);
			typedef Gamevoid(*UGSPHERICALTOCARTESIAN)(Gamedouble fLon, Gamedouble fLat, Gamedouble fAltitude,
				Gamedouble &fX, Gamedouble &fY, Gamedouble &fZ);

			typedef Gamevoid(*UGCREATSIGHTLINE)(Gamevoid* & pSightline);
			typedef Gamevoid(*UGDESTROYSOGHTLINE)(Gamevoid*& pSightline);
			typedef bool(*UGSIGHTLINEBUILD)(Gamevoid* pSightline);
			typedef Gamevoid(*UGSETSIGHTLINEVISIBLECOLOR)(Gamevoid* pSightline, Gamefloat fR, Gamefloat fG, Gamefloat fB, Gamefloat fA);
			typedef Gamevoid(*UGGETSIGHTLINEVISIBLECOLOR)(Gamevoid* pSightline, Gamefloat &fR, Gamefloat &fG, Gamefloat &fB, Gamefloat &fA);
			typedef Gamevoid(*UGSETSIGHTLINEHIDDENCOLOR)(Gamevoid* pSightline, Gamefloat fR, Gamefloat fG, Gamefloat fB, Gamefloat fA);
			typedef Gamevoid(*UGGETSIGHTLINEHIDDENCOLOR)(Gamevoid* pSightline, Gamefloat &fR, Gamefloat &fG, Gamefloat &fB, Gamefloat &fA);
			typedef Gamevoid(*UGGETSIGHTLINEVIEWERPOSITION)(Gamevoid* pSightline, Gamedouble& dX, Gamedouble& dY, Gamedouble& dZ);
			typedef Gamevoid(*UGSETSIGHTLINEVIEWERPOSITION)(Gamevoid* pSightline, Gamedouble dX, Gamedouble dY, Gamedouble dZ);
			typedef Gamevoid(*UGGETSIGHTLINETARGETPOINT)(Gamevoid* pSightline, Gameint index, Gamedouble& dX, Gamedouble& dY, Gamedouble& dZ);
			typedef Gamevoid(*UGSETSIGHTLINETARGETPOINT)(Gamevoid* pSightline, Gameint index, Gamedouble dX, Gamedouble dY, Gamedouble dZ);
			typedef Gameint(*UGADDSIGHTLINETARGETPOINT)(Gamevoid* pSightline, Gamedouble dX, Gamedouble dY, Gamedouble dZ);
			typedef Gameint(*UGGETSIGHTLINETARGETPOINTCOUNT)(Gamevoid* pSightline);
			typedef Gamevoid(*UGREMOVESIGHTLINETARGETPOINT)(Gamevoid* pSightline, Gameint index);
			typedef Gamevoid(*UGREMOVESIGHTLINEALLTARGETPOINT)(Gamevoid* pSightline);
			typedef Gamevoid(*UGGETALLSIGHTLINERESULTFORUE)(
				Gamevoid* pSightline,
				Gamedouble* viewMatrix,
				Gamedouble* prjMatrix,
				Gamefloat* depthBuffer,
				Gameint nWidth,
				Gameint nHeight,
				Sightline_Result***& result);

			typedef bool (*UGGETBARRIERPOINTANDREFLECTIONPOINT)(Gamevoid* pSightline, Gameint index,
				Gamedouble& barrierPointX, Gamedouble& barrierPointY, Gamedouble& barrierPointZ,
				Gamedouble& reflectionPointX, Gamedouble& reflectionPointY, Gamedouble& reflectionPointZ);
			typedef bool(*UGISINSIDEVIEW)(Gamevoid* pSightline, Gameint nIndex);

			extern UGCREATSIGHTLINE			     _CreateSightline               ;
			extern UGDESTROYSOGHTLINE				 _DestroySightline              ;
			extern UGSIGHTLINEBUILD				 _SightlineBuild                ;
			extern UGSETSIGHTLINEVISIBLECOLOR	     _SetSightlineVisibleColor      ;
			extern UGGETSIGHTLINEVISIBLECOLOR	     _GetSightlineVisibleColor      ;
			extern UGSETSIGHTLINEHIDDENCOLOR	     _SetSightlineHiddenColor       ;
			extern UGGETSIGHTLINEHIDDENCOLOR	     _GetSightlineHiddenColor       ;
			extern UGGETSIGHTLINEVIEWERPOSITION     _GetSightlineViewerPosition    ;
			extern UGSETSIGHTLINEVIEWERPOSITION     _SetSightlineViewerPosition    ;
			extern UGGETSIGHTLINETARGETPOINT        _GetSightlineTargetPoint       ;
			extern UGSETSIGHTLINETARGETPOINT	     _SetSightlineTargetPoint       ;
			extern UGADDSIGHTLINETARGETPOINT	     _AddSightlineTargetPoint       ;
			extern UGGETSIGHTLINETARGETPOINTCOUNT   _GetSightlineTargetPointCount  ;
			extern UGREMOVESIGHTLINETARGETPOINT     _RemoveSightlineTargetPoint    ;
			extern UGREMOVESIGHTLINEALLTARGETPOINT  _RemoveSightlineAllTargetPoint ;
			extern UGGETALLSIGHTLINERESULTFORUE     _GetAllSightlineResultForUE    ;
			extern UGISINSIDEVIEW					 _IsInsideView                  ;
			extern UGGETBARRIERPOINTANDREFLECTIONPOINT _GetBarrierPointAndReflectionPoint ;
			//===============================================================
			//==========Skyline API==========================================
			typedef Gamevoid(*UGCARTESIANTOSPHERICALLD)(Gamefloat fX, Gamefloat fY, Gamefloat fZ,
				Gamefloat &fLon, Gamefloat &fLat, Gamefloat &fAltitude);
			typedef Gamevoid(*UGSPHERICALTOCARTESIAN)(Gamedouble fLon, Gamedouble fLat, Gamedouble fAltitude,
				Gamedouble &fX, Gamedouble &fY, Gamedouble &fZ);
			typedef Gamevoid(*UGCREATESKYLINE)(Gamevoid* & pSkyline);
			typedef Gamevoid(*UGSETSKYLINEVIEWERPITCH)(Gamevoid* pSkyline, Gamedouble dPitch);
			typedef Gamevoid(*UGGETSKYLINEVIEWERPITCH)(Gamevoid* pSkyline, Gamedouble & dPitch);
			typedef Gamevoid(*UGSETSKYLINEVIEWERDIRECTION)(Gamevoid* pSkyline, Gamedouble dDriection);
			typedef Gamevoid(*UGGETSKYLINEVIEWERDIRECTION)(Gamevoid* pSkyline, Gamedouble & dDriection);
			typedef Gamevoid(*UGSETSKYLINEVIEWERPOSITION)(Gamevoid* pSkyline, Gamedouble dPosX, Gamedouble dPosY, Gamedouble dPosZ);
			typedef Gamevoid(*UGGETSKYLINEVIEWERPOSITION)(Gamevoid* pSkyline, Gamedouble &dPosX, Gamedouble &dPosY, Gamedouble &dPosZ);
			typedef Gamevoid(*UGGETSKYLINE3DFORGAMEENGINE)(Gamevoid* pSkyline, Gamefloat* matView, Gamefloat* matProjection,
				Gamevoid* pDepthBuffer, DataVertex* & pDataVertex, DataIndice* &pDataIndex);
			typedef Gamevoid(*UGGETSKYLINERADIUS)(Gamevoid* pSkyline, Gamedouble &dRadius);
			typedef Gamevoid(*UGSETSKYLINERADIUS)(Gamevoid* pSkyline, Gamedouble dRadius);
			typedef Gamevoid(*UGGETSKYLINE)(Gamevoid* pSkyline, Gamevoid*& pGeoLine3D);
			typedef Gamevoid(*UGGETSKYLINE2D)(Gamevoid* pSkyline, Gamevoid*& pGeoLine2D);
			typedef Gamevoid(*UGBUILDSKYLINE)(Gamevoid* pSkyline);
			typedef Gamevoid(*UGDESTROYSKYLINE)(Gamevoid* &pSkyline);
			typedef Gamevoid(*UGGETSKYLINESECTORBODY)(Gamevoid* pSkyline, Gamedouble dHeight, Gamevoid*& pGeo);
			typedef Gamevoid(*UGSKYLINEGETOBJECTIDS)(Gamevoid* pSkyline, std::map<Gameint, Gameint*>& mapGameObject, Gameint*& nIdCount);

			extern UGCREATESKYLINE              _CreateSkyline             ;
			extern UGDESTROYSKYLINE             _DestroySkyline            ;
			extern UGSETSKYLINEVIEWERPITCH      _SetSkylineViewerPitch     ;
			extern UGGETSKYLINEVIEWERPITCH      _GetSkylineViewerPitch     ;
			extern UGSETSKYLINEVIEWERDIRECTION  _SetSkylineViewerDirection ;
			extern UGGETSKYLINEVIEWERDIRECTION  _GetSkylineViewerDirection ;
			extern UGSETSKYLINEVIEWERPOSITION	 _SetSkylineViewerPosition  ;
			extern UGGETSKYLINEVIEWERPOSITION   _GetSkylineViewerPosition  ;
			extern UGGETSKYLINE3DFORGAMEENGINE  _GetSkyline3DForGameEngine ;
			extern UGGETSKYLINERADIUS			 _GetSkylineRadius          ;
			extern UGSETSKYLINERADIUS			 _SetSkylineRadius          ;
			extern UGGETSKYLINE				 _GetSkyline   ;
			extern UGBUILDSKYLINE			     _BuildSkyline ;
			extern UGGETSKYLINE2D               _GetSkyline2D ;
			extern UGGETSKYLINESECTORBODY       _GetSkylineSectorBody;
			extern UGSKYLINEGETOBJECTIDS		_Skyline_GetObjectIDs;
			//===============================================================
			//============================ProjectionImage API================
			typedef Gamevoid(*UGCREATEPROJECTIONIMAGE)(Gamevoid*& pProjectionImage);
			typedef Gamevoid(*UGDESTROYPROJECTIONIMAGE)(Gamevoid*& pProjectionImage);
			typedef Gamevoid(*UGBUILDPROJECTIONIMAGE)(Gamevoid* pProjectionImage);
			typedef Gamevoid(*UGSETPROJECTIONIMAGEPITCH)(Gamevoid* pProjectionImage, Gamedouble pitch);
			typedef Gamedouble(*UGGETPROJECTIONIMAGEPITCH)(Gamevoid* pProjectionImage);
			typedef Gamevoid(*UGSETPROJECTIONIMAGEHEADING)(Gamevoid* pProjectionImage, Gamedouble dDriection);
			typedef Gamedouble(*UGGETPROJECTIONIMAGEHEADING)(Gamevoid* pProjectionImage);
			typedef Gamevoid(*UGSETPROJECTIONIMAGEVIEWPOSITION)(Gamevoid* pProjectionImage, Gamedouble dPosX, Gamedouble dPosY, Gamedouble dPosZ);
			typedef Gamevoid(*UGGETPROJECTIONIMAGEVIEWPOSITION)(Gamevoid* pProjectionImage, Gamedouble& dPosX, Gamedouble& dPosY, Gamedouble& dPosZ);
			typedef Gamevoid* (*UGGETPROJECTIONIMAGEDEPTHHANDLE)(Gamevoid* pProjectionImage);
			typedef Gamevoid(*UGGETPROJECTIONIMAGECAMERA)(Gamevoid* pProjectionImage, Gamedouble& dFov, Gamedouble& dAspect, Gamedouble& dNear, Gamedouble& dFar, Gamedouble* pViewMatrix, Gamedouble* pProjectionMatrix);
			typedef Gamevoid(*UGPROJECTIONIMAGERENDER)(Gamevoid* pProjectionImage);
			typedef Gamevoid(*UGSETPROJECTIONIMAGEAFFINEMATRIX)(Gamevoid* pProjectionImage, Gamedouble dX1, Gamedouble dY1, Gamedouble dZ1, Gamedouble dX2, Gamedouble dY2, Gamedouble dZ2);
			typedef Gamevoid(*UGGETPROJECTIONIMAGEAFFINEMATRIX)(Gamevoid* pProjectionImage, Gamedouble& dX1, Gamedouble& dY1, Gamedouble& dZ1, Gamedouble& dX2, Gamedouble& dY2, Gamedouble& dZ2);
			typedef Gamevoid(*UGSETPROJECTIONIMAGEISHOMONYMYPOINTS)(Gamevoid* pProjectionImage, Gamebool bUsed);
			typedef Gamebool(*UGGETPROJECTIONIMAGEISHOMONYMYPOINTS)(Gamevoid* pProjectionImage);
			typedef Gamebool(*UGPROJECTIONIMAGETOXML)(Gamevoid* pProjectionImage, Gamechar* strFileName);
			typedef Gamebool(*UGPROJECTIONIMAGEFROMXML)(Gamevoid* pProjectionImage, Gamechar* strFileName);
			typedef Gamebool(*UGPROJECTIONIMAGESETHINLINELENGTH)(Gamevoid* pProjectionImage, Gamedouble length);

			extern UGCREATEPROJECTIONIMAGE                _CreateProjectionImage     ;
			extern UGDESTROYPROJECTIONIMAGE               _DestroyProjectionImage    ;
			extern UGBUILDPROJECTIONIMAGE				   _BuildProjectionImage      ;
			extern UGSETPROJECTIONIMAGEPITCH              _SetProjectionImagePitch   ;
			extern UGGETPROJECTIONIMAGEPITCH			   _GetProjectionImagePitch   ;
			extern UGSETPROJECTIONIMAGEHEADING            _SetProjectionImageHeading ;
			extern UGGETPROJECTIONIMAGEHEADING			   _GetProjectionImageHeading ;
			extern UGSETPROJECTIONIMAGEVIEWPOSITION       _SetProjectionImageViewPosition ;
			extern UGGETPROJECTIONIMAGEVIEWPOSITION       _GetProjectionImageViewPosition ;
			extern UGGETPROJECTIONIMAGEDEPTHHANDLE		   _GetProjectionImageDepthHandle  ;
			extern UGGETPROJECTIONIMAGECAMERA             _GetProjectionImageGetCamera    ;
			extern UGPROJECTIONIMAGERENDER				   _ProjectionImageRender          ;
			extern UGSETPROJECTIONIMAGEAFFINEMATRIX	   _SetProjectionImageAffineMatrix ;
			extern UGGETPROJECTIONIMAGEAFFINEMATRIX	   _GetProjectionImageAffineMatrix ;
			extern UGSETPROJECTIONIMAGEISHOMONYMYPOINTS   _SetProjectionImageIsHomonymyPoints ;
			extern UGGETPROJECTIONIMAGEISHOMONYMYPOINTS   _GetProjectionImageIsHomonymyPoints ;
			extern UGPROJECTIONIMAGETOXML				   _ProjectionImageToXML ;
			extern UGPROJECTIONIMAGEFROMXML			   _ProjectionImageFromXML ;
			extern UGPROJECTIONIMAGESETHINLINELENGTH	_ProjectionImageSetHintLineLength;

			//===============ViewShed API====================================
			typedef Gamevoid(*UGCREATEVIEWSHED)(Gamevoid*& pViewShed);
			typedef Gamevoid(*UGDESTROYVIEWSHED)(Gamevoid*& pViewShed);
			typedef Gamevoid(*UGBUILDVIEWSHED)(Gamevoid* pViewShed);
			typedef Gamevoid(*UGSETVIEWSHEDPITCH)(Gamevoid* pViewShed, Gamedouble pitch);
			typedef Gamedouble(*UGGETVIEWSHEDPITCH)(Gamevoid* pViewShed);
			typedef Gamevoid(*UGSETVIEWSHEDHEADING)(Gamevoid* pViewShed, Gamedouble dDriection);
			typedef Gamedouble(*UGGETVIEWSHEDHEADING)(Gamevoid* pViewShed);
			typedef Gamevoid(*UGSETVIEWSHEDHORIZONTALFOV)(Gamevoid* pViewShed, Gamedouble fov);
			typedef Gamedouble(*UGGETVIEWSHEDHORIZONTALFOV)(Gamevoid* pViewShed);
			typedef Gamevoid(*UGSETVIEWSHEDVERTICALFOV)(Gamevoid* pViewShed, Gamedouble fov);
			typedef Gamedouble(*UGGETVIEWSHEDVERTICALFOV)(Gamevoid* pViewShed);
			typedef Gamevoid(*UGSETVIEWSHEDDISTANCE)(Gamevoid* pViewShed, Gamedouble fov);
			typedef Gamedouble(*UGGETVIEWSHEDDISTANCE)(Gamevoid* pViewShed);
			typedef Gamevoid(*UGSETVIEWSHEDVIEWPOSITION)(Gamevoid* pViewShed, Gamedouble dPosX, Gamedouble dPosY, Gamedouble dPosZ);
			typedef Gamevoid(*UGGETVIEWSHEDVIEWPOSITION)(Gamevoid* pViewShed, Gamedouble &dPosX, Gamedouble &dPosY, Gamedouble &dPosZ);
			typedef Gamevoid(*UGSET_DIST_DIR_BY_POINT_BY_UGC)(Gamevoid* pViewShed, Gamedouble targetPosX, Gamedouble targetPosY, Gamedouble targetPosZ);

			typedef Gamevoid (*UGSETVIEWSHEDVISIBLEAREACOLOR)(Gamevoid* pViewShed, Gamefloat fR, Gamefloat fG, Gamefloat fB, Gamefloat fA);
			typedef Gamevoid (*UGGETVIEWSHEDVISIBLEAREACOLOR)(Gamevoid* pViewShed, Gamefloat& fR, Gamefloat& fG, Gamefloat& fB, Gamefloat& fA);
			typedef Gamevoid (*UGSETVIEWSHEDHIDDENAREACOLOR)(Gamevoid* pViewShed, Gamefloat fR, Gamefloat fG, Gamefloat fB, Gamefloat fA);
			typedef Gamevoid (*UGGETVIEWSHEDHIDDENAREACOLOR)(Gamevoid* pViewShed, Gamefloat &fR, Gamefloat &fG, Gamefloat &fB, Gamefloat &fA);
			typedef Gamevoid (*UGGETCAMERAFORUE)(Gamevoid* pViewShed, Gamedouble &dFov, Gamedouble &dAspect, Gamedouble& dNear, Gamedouble& dFar, Gamedouble* pViewMatrix);
			typedef Gamevoid* (*UGGETDEPTHRENDERTEXTUREHANDLE)(Gamevoid* pViewShed);
			typedef Gamevoid (*UGGETVIEWSHEDVISIBLEBODY)(Gamevoid* pViewShed, Gamevoid*& pGeoModel);
			typedef Gamevoid (*UGGETVIEWSHEDHIDDENBODY)(Gamevoid* pViewShed, Gamevoid*& pGeoModel);
			typedef Gameint (*UGVIEWSHED_GETQUALITY)(Gamevoid* pViewShed);
			typedef Gamevoid (*UGVIEWSHED_SETQUALITY)(Gamevoid* pViewShed, Gameint nQuality);
			typedef Gameint (*UGVIEWSHED_GETBARRIERPOINTS)(Gamevoid* pViewShed, Gamedouble*& dPointArray);
			typedef Gamechar* (*UGVIEWSHED_GETNAME)(Gamevoid* pViewShed);
			typedef Gamevoid (*UGVIEWSHED_SETNAME)(Gamevoid* pViewShed, Gamechar* cName);
			typedef Gamevoid (*UGVIEWSHED_REMOVEFROMANALYST3DLIST)(Gamevoid* pViewShed);

			extern UGCREATEVIEWSHED                _CreateViewShed            ;
			extern UGDESTROYVIEWSHED               _DestroyViewShed           ;
			extern UGBUILDVIEWSHED					_BuildViewShed             ;
			extern UGSETVIEWSHEDPITCH              _SetViewShedPitch          ;
			extern UGGETVIEWSHEDPITCH				_GetViewShedPitch          ;
			extern UGSETVIEWSHEDHEADING            _SetViewShedHeading        ;
			extern UGGETVIEWSHEDHEADING			_GetViewShedHeading        ;
			extern UGSETVIEWSHEDHORIZONTALFOV      _SetViewShedHorizontalFov  ;
			extern UGGETVIEWSHEDHORIZONTALFOV      _GetViewShedHorizontalFov    ;
			extern UGSETVIEWSHEDVERTICALFOV        _SetViewShedVerticalFov      ;
			extern UGGETVIEWSHEDVERTICALFOV        _GetViewShedVerticalFov      ;
			extern UGSETVIEWSHEDDISTANCE           _SetViewShedDistance         ;
			extern UGGETVIEWSHEDDISTANCE           _GetViewShedDistance         ;
			extern UGSETVIEWSHEDVIEWPOSITION       _SetViewShedViewerPosition   ;
			extern UGGETVIEWSHEDVIEWPOSITION       _GetViewShedViewerPosition   ;
			extern UGSET_DIST_DIR_BY_POINT_BY_UGC  _SetDistDirByPoint           ;
			extern UGSETVIEWSHEDVISIBLEAREACOLOR   _SetViewShedVisibleAreaColor ;
			extern UGGETVIEWSHEDVISIBLEAREACOLOR   _GetViewShedVisibleAreaColor ;
			extern UGSETVIEWSHEDHIDDENAREACOLOR    _SetViewShedHiddenAreaColor  ;
			extern UGGETVIEWSHEDHIDDENAREACOLOR    _GetViewShedHiddenAreaColor  ;
			extern UGGETCAMERAFORUE				_GetCamera                   ;
			extern UGGETDEPTHRENDERTEXTUREHANDLE   _GetDepthRenderTextureHandle ;
			extern UGGETVIEWSHEDVISIBLEBODY		_GetViewShedVisibleBody      ;
			extern UGGETVIEWSHEDHIDDENBODY         _GetViewShedHiddenBody       ;
			extern UGVIEWSHED_GETQUALITY			_Viewshed_GetQuality		;
			extern UGVIEWSHED_SETQUALITY			_Viewshed_SetQuality		;
			extern UGVIEWSHED_GETBARRIERPOINTS	_ViewShed_GetBarrierPoints		;
			extern UGVIEWSHED_GETNAME			_ViewShed_GetName;
			extern UGVIEWSHED_SETNAME			_ViewShed_SetName;
			extern UGVIEWSHED_REMOVEFROMANALYST3DLIST	_ViewShed_RemoveFromAnalyst3DList;
			//===============================================================
			//==============MultiViewShed3D API==============================
			typedef Gamevoid(*UGMULTIVIEWSHED3D_CREATE)(Gamevoid*& pMultiViewShed3D);
			typedef Gamevoid(*UGMULTIVIEWSHED3D_DESTROY)(Gamevoid*& pMultiViewShed3D);
			typedef Gamevoid(*UGMULTIVIEWSHED3D_ADDVIEWSHED)(Gamevoid* pMultiViewShed3D, Gamevoid* pViewShed3D);
			typedef Gamevoid(*UGMULTIVIEWSHED3D_REMOVEVIEWSHED)(Gamevoid* pMultiViewShed3D, Gamevoid* pViewShed3D);
			typedef Gamevoid(*UGMULTIVIEWSHED3D_BUILD)(Gamevoid* pMultiViewShed3D);

			extern UGMULTIVIEWSHED3D_CREATE				_MultiViewShed3D_Create;
			extern UGMULTIVIEWSHED3D_DESTROY			_MultiViewShed3D_Destroy;
			extern UGMULTIVIEWSHED3D_ADDVIEWSHED		_MultiViewShed3D_AddViewShed;
			extern UGMULTIVIEWSHED3D_REMOVEVIEWSHED		_MultiViewShed3D_RemoveViewShed;
			extern UGMULTIVIEWSHED3D_BUILD				_MultiViewShed3D_Build;
			//===============================================================
			//==============ViewDome API=====================================
			typedef Gamevoid(*UGVIEWDOME_CREATE)(Gamevoid* & pViewDome);
			typedef Gamevoid(*UGVIEWDOME_DESTROY)(Gamevoid* & pViewDome);
			typedef Gamevoid(*UGVIEWDOME_GETCOLOR)(Gamevoid* pViewDome, Gamefloat& fR, Gamefloat& fG, Gamefloat& fB, Gamefloat& fA);
			typedef Gamevoid(*UGVIEWDOME_SETCOLOR)(Gamevoid* pViewDome, Gamefloat fR, Gamefloat fG, Gamefloat fB, Gamefloat fA);
			typedef Gamevoid(*UGVIEWDOME_GETLINECOLOR)(Gamevoid* pViewDome, Gamefloat& fR, Gamefloat& fG, Gamefloat& fB, Gamefloat& fA);
			typedef Gamevoid(*UGVIEWDOME_SETLINECOLOR)(Gamevoid* pViewDome, Gamefloat fR, Gamefloat fG, Gamefloat fB, Gamefloat fA);
			typedef Gamevoid(*UGVIEWDOME_GETVIEWERPOSITION)(Gamevoid* pViewDome, Gamedouble& viewX, Gamedouble& viewY, Gamedouble& viewZ);
			typedef Gamevoid(*UGVIEWDOME_SETVIEWERPOSITION)(Gamevoid* pViewDome, Gamedouble viewX, Gamedouble viewY, Gamedouble viewZ);
			typedef Gamedouble(*UGVIEWDOME_GETDISTANCE)(Gamevoid* pViewDome);
			typedef Gamevoid(*UGVIEWDOME_SETDISTANCE)(Gamevoid* pViewDome, Gamedouble viewDistance);
			typedef Gameint(*UGVIEWDOME_GETDOMETYPE)(Gamevoid* pViewDome);
			typedef Gamevoid(*UGVIEWDOME_SETDOMETYPE)(Gamevoid* pViewDome, Gameint modeType);
			typedef Gameint(*UGVIEWDOME_GETDISPLAYSTYLE)(Gamevoid* pViewDome);
			typedef Gamevoid(*UGVIEWDOME_SETDISPLAYSTYLE)(Gamevoid* pViewDome, Gameint displayStyle);
			typedef Gamedouble(*UGVIEWDOME_GETRATIO)(Gamevoid* pViewDome, Gameint modeType);
			typedef Gamevoid(*UGVIEWDOME_GETDEPTHRENDERTEXTUREPTRHANDLE)(Gamevoid* pViewDome, Gamevoid** & pArrRenderTexturePtr, Gameint & nCount);
			typedef Gamevoid(*UGVIEWDOME_GETCAMERA)(Gamevoid* pViewDome, Gamedouble**& pViewMatrix, Gamedouble &dFov, Gamedouble &dAspect, Gamedouble &dNear, Gamedouble &dFar, Gameint& nCount);
			typedef Gamevoid(*UGVIEWDOME_BUILD)(Gamevoid* pViewDome);

			extern UGVIEWDOME_CREATE							_ViewDome_Create;
			extern UGVIEWDOME_DESTROY							_ViewDome_Destroy;
			extern UGVIEWDOME_GETCOLOR							_ViewDome_GetColor;
			extern UGVIEWDOME_SETCOLOR							_ViewDome_SetColor;
			extern UGVIEWDOME_GETLINECOLOR						_ViewDome_GetLineColor;
			extern UGVIEWDOME_SETLINECOLOR						_ViewDome_SetLineColor;
			extern UGVIEWDOME_GETVIEWERPOSITION					_ViewDome_GetViewerPosition;
			extern UGVIEWDOME_SETVIEWERPOSITION					_ViewDome_SetViewerPosition;
			extern UGVIEWDOME_GETDISTANCE						_ViewDome_GetDistance;
			extern UGVIEWDOME_SETDISTANCE						_ViewDome_SetDistance;
			extern UGVIEWDOME_GETDOMETYPE						_ViewDome_GetDomeType;
			extern UGVIEWDOME_SETDOMETYPE						_ViewDome_SetDomeType;
			extern UGVIEWDOME_GETDISPLAYSTYLE					_ViewDome_GetDisplayStyle;
			extern UGVIEWDOME_SETDISPLAYSTYLE					_ViewDome_SetDisplayStyle;
			extern UGVIEWDOME_GETRATIO							_ViewDome_GetRatio;
			extern UGVIEWDOME_GETDEPTHRENDERTEXTUREPTRHANDLE	_ViewDome_GetDepthRenderTexturePtrHandle;
			extern UGVIEWDOME_GETCAMERA							_ViewDome_GetCamera;
			extern UGVIEWDOME_BUILD								_ViewDome_Build;
			//===============================================================
			//=============CalculationTerrain API============================
			typedef Gamebool(*UGCUTFILL)(void* geoRegin, Gamedouble dperPixel, Gamedouble baseAltitude,
				Gamedouble& dFillVolume, Gamedouble& dCutVolume, Gamedouble& dFillArea, Gamedouble& dCutArea, Gamedouble& dNoChangeArea);

			extern UGCUTFILL				_CutFill;
			//===============================================================
			//==============Profile API======================================
			typedef Gamevoid(*UGPROFILE_CREATE)(Gamevoid*& pProfile);
			typedef Gamevoid(*UGPROFILE_DESTROY)(Gamevoid*& pProfile);
			typedef Gamevoid(*UGPROFILE_SETEXTENDHEIGHT)(Gamevoid* pProfile, Gamedouble height);
			typedef Gamedouble(*UGPROFILE_GETEXTENDHEIGHT)(Gamevoid* pProfile);
			typedef Gamevoid(*UGPROFILE_SETSTARTPOINT3D)(Gamevoid* pProfile, Gamedouble x, Gamedouble y, Gamedouble z);
			typedef Gamevoid(*UGPROFILE_GETSTARTPOINT3D)(Gamevoid* pProfile, Gamedouble& x, Gamedouble& y, Gamedouble& z);
			typedef Gamevoid(*UGPROFILE_SETENDPOINT3D)(Gamevoid* pProfile, Gamedouble x, Gamedouble y, Gamedouble z);
			typedef Gamevoid(*UGPROFILE_GETENDPOINT3D)(Gamevoid* pProfile, Gamedouble& x, Gamedouble& y, Gamedouble& z);
			typedef Gamevoid(*UGPROFILE_GETLEFTTOPPOSITION)(Gamevoid* pProfile, Gamedouble& x, Gamedouble& y, Gamedouble& z);
			typedef Gamevoid(*UGPROFILE_GETRIGHTBOTTOMPOSITION)(Gamevoid* pProfile, Gamedouble& x, Gamedouble& y, Gamedouble& z);
			typedef Gamevoid(*UGPROFILE_OUTPUTPROFILETOIMAGEDATA)(Gamevoid* pProfile, Gameint& nWidth, Gameint& nHeight, Gameint& nFormat, Gameint& nTextureCodecType, Gameint& nWidthBytes, Gamevoid*& pBits);
			typedef Gamevoid(*UGPROFILE_BUILD)(Gamevoid* pProfile);

			extern UGPROFILE_CREATE							_Profile_Create;
			extern UGPROFILE_DESTROY						_Profile_Destroy;
			extern UGPROFILE_SETEXTENDHEIGHT				_Profile_SetExtendHeight;
			extern UGPROFILE_GETEXTENDHEIGHT				_Profile_GetExtendHeight;
			extern UGPROFILE_SETSTARTPOINT3D				_Profile_SetStartPoint3D;
			extern UGPROFILE_GETSTARTPOINT3D				_Profile_GetStartPoint3D;
			extern UGPROFILE_SETENDPOINT3D					_Profile_SetEndPoint3D;
			extern UGPROFILE_GETENDPOINT3D					_Profile_GetEndPoint3D;
			extern UGPROFILE_GETLEFTTOPPOSITION				_Profile_GetLeftTopPosition;
			extern UGPROFILE_GETRIGHTBOTTOMPOSITION			_Profile_GetRightBottomPosition;
			extern UGPROFILE_OUTPUTPROFILETOIMAGEDATA		_Profile_OutputProfileToImageData;
			extern UGPROFILE_BUILD							_Profile_Build;
			//===============================================================
			//==============Common API=======================================
			typedef Gamevoid(*UGFREEDATAINDICE)(DataIndice* pDataIndice);
			typedef Gamevoid(*UGFREEDATAVERTEX)(DataVertex* pDataVertex);
			typedef Gamevoid(*UGCALCMERCATORFROMSPHERICALFLOAT)(Gamefloat dLat, Gamefloat dLon, Gamefloat& x, Gamefloat& y, Gamefloat& z);
			typedef Gamevoid(*UGCARTESIANTOSPHERICALD)(
				Gamedouble dX, Gamedouble dY, Gamedouble dZ,
				Gamedouble &dLon, Gamedouble &dLat, Gamedouble &dAltitude);
			typedef Gamevoid(*UGSPHERICALTOCARTESIAN)(
				Gamedouble dLon, Gamedouble dLat, Gamedouble dAltitude,
				Gamedouble &dX, Gamedouble &dY, Gamedouble &dZ);
			typedef Gamevoid(*UGGETROTATIONMATRIX)(Gamedouble dX, Gamedouble dY, Gamedouble dZ, Gamedouble* pMat);
			typedef Gamevoid(*UGROTATIONMATRIX)(Gamedouble dLon, Gamedouble dLat, Gamedouble dAltitude, Gamedouble*& pRotationMat);

			typedef Gamevoid(*UGReleaseCharArray)(Gamechar*** arrChars, Gameint nCount);
			typedef Gamevoid(*UGReleaseIntArray)(Gameint** arrInts);
			typedef Gamevoid(*UGReleaseDoubleArray)(Gamedouble** arrDoubles);

			extern UGReleaseCharArray				  _ReleaseCharArray               ;
			extern UGReleaseIntArray				  _ReleaseIntArray                ;
			extern UGReleaseDoubleArray			  _ReleaseDoubleArray			  ;
			extern UGFREEDATAINDICE                  _FreeDataIndice                 ;
			extern UGFREEDATAVERTEX                  _FreeDataVertex                 ;
			extern UGCALCMERCATORFROMSPHERICALFLOAT  _CalcMercatorFromSphericalFloat ;
			extern UGCARTESIANTOSPHERICALD           _CartesianToSphericalD          ;
			extern UGSPHERICALTOCARTESIAN            _SphericalToCartesian           ;
			extern UGGETROTATIONMATRIX				  _GetRotationMatrix              ;
			extern UGROTATIONMATRIX				  _RotationMatrix				  ;
			//===============================================================
			//=====================Dataset===================================

			typedef Gamevoid(*UGDATASET_GETBOUNDS)(Gamevoid* pUGDataset, Gamefloat &left,
				Gamefloat &bottom, Gamefloat &right, Gamefloat &top);
			typedef Gamevoid(*UGDATASET_GETBOUNDS2)(Gamevoid* pUGDataset, Gamefloat &left,
				Gamefloat &bottom, Gamefloat &right, Gamefloat &top, Gamefloat & maxz, Gamefloat &minz);
			typedef Gamevoid(*UGDATASET_GETTYPE)(Gamevoid* pUGDataset, Gameint &type);
			typedef Gamevoid(*UGDATASET_QUERY)(Gamevoid* pUGDataset, Gamevoid*** & pPoint3D, Gameint &nCount);
			typedef Gamevoid(*UGDATASET_QUERYBYSQL)(Gamevoid* pUGDataset, Gamechar* sql, Gamevoid*** & pPoint3D, Gameint &nCount);
			typedef Gamevoid(*UGDATASET_GETFIELDINFOS)(Gamevoid* pUGDataset, Gamechar*** &arrFieldNames, Gameint** &arrTypes, Gameint &nCount);

			typedef Gamevoid(*UGDATASET_QUERYFIELD)(Gamevoid* pUGDataset, Gamechar* strFieldName, Gamechar*** &arrFieldNames, Gameint &nCount);
			typedef Gamevoid(*UGDATASET_QUERYATTRIBUTEBYID)(Gamevoid* pUGDataset, Gameint nId, Gamechar*** &arrValues, Gameint &nCount);

			extern UGDATASET_GETBOUNDS				_Dataset_GetBounds  ;
			extern UGDATASET_GETTYPE				_Dataset_GetType    ;
			extern UGDATASET_QUERY					_Dataset_Query ;
			extern UGDATASET_QUERYBYSQL            _Dataset_QueryBySql ;
			extern UGDATASET_GETFIELDINFOS			_Dataset_GetFieldInfos ;

			extern UGDATASET_QUERYFIELD			_Dataset_QueryField ;
			extern UGDATASET_QUERYATTRIBUTEBYID	_Dataset_QueryAttributeById ;
			//==================DataSource API===============================
			typedef bool(*UGOPENDATASOURCE)(Gamevoid*& pDataSource, Gamechar* strDataSourceName);
			typedef Gamevoid(*UGCLOSEDATASOURCE)(Gamevoid* pDatasource);
			typedef bool(*UGISOPENEDDATASOURCE)(Gamevoid* pDatasource);
			typedef bool(*UGOPENDATASET)(Gamevoid* pDataset);
			typedef bool(*UGISOPENEDDATASET)(Gamevoid* pDataset);
			typedef Gamevoid(*UGGETDATASETNAME)(Gamevoid* pDataset, Gamechar* &strDataName);
			typedef Gamevoid(*UGGETDATASETBYNAME)(Gamevoid* pDatasource, Gamechar* name, Gamevoid*& pDataset);

			typedef bool(*UGGETDATASETMODELDATA)(Gamevoid* pDataset,
				DataSetGeometry*** & pGeometrys, Gameint & nGeometryCount,
				DataSetSkeleton*** & pSkeletons, Gameint & nSkeletonCount,
				DataSetInstanceSkeleton*** & pInstanceSkeletons, Gameint & nInstanceSkeletonCount,
				DataSetMaterial*** & pMaterials, Gameint & nMaterialCount,
				DataSetTexture***  & pTextures, Gameint & nTextureCount);
			
			typedef bool(*UGDATASOURCE_OPEN)(Gamechar* strDataSourcePath, Gamevoid* &pUGDataSource, Gamechar* &strDataSourceName,
				Gamevoid*** &pDatasets, Gameint &nCount);
			typedef Gamevoid(*UGDATASOURCE_CLOSE)(Gamevoid* pUGDataSource);

			typedef Gamevoid(*UGFREEMODELMESH)(DataSetGeometry*** & pDatasetModels, Gameint nCount);
			typedef Gamevoid(*UGFREEMODELMATERIAL)(DataSetMaterial*** & pDatasetModelMaterials, Gameint nCount);
			typedef Gamevoid(*UGFREEMODELTEXTURE)(DataSetTexture*** & pDatasetModelTextures, Gameint nCount);
			typedef Gamevoid(*UGFREEDATASETSKELETONS)(DataSetSkeleton*** pDataSetSkeletons, Gameint nCount);
			typedef Gamevoid(*UGFREEDATASETINSTANCESKELETONS)(DataSetInstanceSkeleton*** pDatasetInstanceSkeletons, Gameint nCount);
			typedef Gamevoid(*UGDATASOURCE_GETDATASET)(Gamevoid* pDataSource, Gamevoid*** & pDatasets, Gameint &nCount);
			
			extern UGOPENDATASOURCE				_OpenDataSource					;
			extern UGGETDATASETBYNAME				_GetDatasetByName				;
			extern UGGETDATASETNAME				_GetDatasetName					;
			extern UGCLOSEDATASOURCE				_CloseDataSource				;
			extern UGISOPENEDDATASOURCE			_IsOpenedDataSource				;
			extern UGOPENDATASET					_OpenDataset					;
			extern UGISOPENEDDATASET				_IsOpenedDataset				;
			extern UGGETDATASETMODELDATA			_GetDatasetModelData            ;
			extern UGFREEMODELMESH					_FreeModelMesh					;
			extern UGFREEMODELMATERIAL				_FreeModelMaterial				;
			extern UGFREEMODELTEXTURE				_FreeModelTexture				;
			extern UGFREEDATASETSKELETONS          _FreeDataSetSkeletons           ;
			extern UGFREEDATASETINSTANCESKELETONS  _FreeDataSetInstanceSkeletons   ;
			extern UGDATASOURCE_OPEN				_DataSource_Open				;
			extern UGDATASOURCE_CLOSE				_DataSource_Close				;
			extern UGDATASOURCE_GETDATASET			_DataSource_GetDataset			;
			//===============================================================
			//===================GeoPoint3D==================================
			typedef Gamevoid(*UGGeoPoint3D_Create)(Gamevoid* & pPoint3D);
			typedef Gamevoid(*UGGeoPoint3D_Destroy)(Gamevoid* & pPoint3D);
			typedef Gamevoid(*UGGeoPoint3D_SetPoint3D)(Gamevoid* pPoint3D, Gamedouble dX, Gamedouble dY, Gamedouble dZ);
			typedef Gamevoid(*UGGeoPoint3D_GetPoint3D)(Gamevoid* pPoint3D, Gamedouble &dX, Gamedouble &dY, Gamedouble &dZ);
			typedef Gamevoid(*UGGeoPoint3D_Copy)(Gamevoid* pGeometry, Gamevoid*& pNewGeometry);

			extern UGGeoPoint3D_Create				_GeoPoint3D_Create ;
			extern UGGeoPoint3D_Destroy			_GeoPoint3D_Destroy ;
			extern UGGeoPoint3D_SetPoint3D			_GeoPoint3D_SetPoint3D ;
			extern UGGeoPoint3D_GetPoint3D			_GeoPoint3D_GetPoint3D ;
			extern UGGeoPoint3D_Copy				_GeoPoint3D_Copy;
			//===============================================================
			//===================GeoLine3D==================================
			typedef Gamevoid(*UGGeoLine3D_Create)(Gamevoid* & pLine3D);
			typedef Gamevoid(*UGGeoLine3D_Destroy)(Gamevoid* & pLine3D);
			typedef Gamevoid(*UGGeoLine3D_GetPoints)(Gamevoid* pLine3D, Gamedouble** &pPoints);
			typedef Gamevoid(*UGGeoLine3D_GetPointCount)(Gamevoid* pLine3D, Gameint &nPointCount);
			typedef Gamevoid(*UGGeoLine3D_GetSubCount)(Gamevoid* pLine3D, Gameint &nSubCount);
			typedef Gamevoid(*UGGeoLine3D_GetPolyCounts)(Gamevoid* pLine3D, Gameint** &pPolyCount);
			typedef Gamevoid(*UGGeoLine3D_Make)(Gamevoid* pLine3D, Gamedouble** pPoints, Gameint nPointsCount);
			typedef Gameint(*UGGeoLine3D_AddPart)(Gamevoid* pLine3D, Gamedouble*& dPoints, Gameint nPointsCount);
			typedef Gamebool(*UGGeoLine3D_RemovePart)(Gamevoid* pLine3D, Gameint nPartIndex);
			typedef Gamevoid(*UGGeoLine3D_Copy)(Gamevoid* pGeometry, Gamevoid*& pNewGeometry);
			
			extern UGGeoLine3D_Create					_GeoLine3D_Create        ;
			extern UGGeoLine3D_Destroy					_GeoLine3D_Destroy       ;
			extern UGGeoLine3D_GetPoints				_GeoLine3D_GetPoints     ;
			extern UGGeoLine3D_GetPointCount			_GeoLine3D_GetPointCount ;
			extern UGGeoLine3D_GetSubCount				_GeoLine3D_GetSubCount   ;
			extern UGGeoLine3D_GetPolyCounts			_GeoLine3D_GetPolyCounts ;
			extern UGGeoLine3D_Make                    _GeoLine3D_Make          ;
			extern UGGeoLine3D_AddPart					_GeoLine3D_AddPart		;
			extern UGGeoLine3D_RemovePart				_GeoLine3D_RemovePart	;
			extern UGGeoLine3D_Copy						_GeoLine3D_Copy;
			//===============================================================
			//===================GeoRegion3D==================================
			typedef Gamevoid(*UGGeoRegion3D_Create)(Gamevoid* & pRegion3D);
			typedef Gamevoid(*UGGeoRegion3D_Destroy)(Gamevoid* & pRegion3D);
			typedef Gamevoid(*UGGeoRegion3D_GetPoints)(Gamevoid* pRegion3D, Gamedouble** &pPoints);
			typedef Gamevoid(*UGGeoRegion3D_GetPointCount)(Gamevoid* pRegion3D, Gameint &nPointCount);
			typedef Gamevoid(*UGGeoRegion3D_GetSubCount)(Gamevoid* pRegion3D, Gameint &nSubCount);
			typedef Gamevoid(*UGGeoRegion3D_GetPolyCounts)(Gamevoid* pRegion3D, Gameint** &pPolyCount);
			typedef Gamevoid(*UGGeoRegion3D_CreateRegion)(Gamevoid* &pRegion3D, Gamedouble*& pPoint3Ds, Gameint nPointCount);
			typedef Gamevoid(*UGGeoRegion3D_MakeWithPoints)(Gamevoid* pRegion3D, Gamedouble*& pPoint3Ds, Gameint nPointCount);
			typedef Gamevoid(*UGGeoRegion3D_AddPart)(Gamevoid*& pRegion3D, Gamedouble*& pPoint3Ds, Gameint nCount);
			typedef Gamebool(*UGGeoRegion3D_InsertPart)(Gamevoid*& pRegion3D, Gameint nIndex, Gamedouble*& pPoint3Ds, Gameint nCount);
			typedef Gamebool(*UGGeoRegion3D_RemovePart)(Gamevoid*& pRegion3D, Gameint nIndex);
			typedef Gamevoid(*UGGeoRegion3D_Copy)(Gamevoid* pGeometry, Gamevoid*& pNewGeometry);
			typedef Gamevoid(*UGGeoRegion3D_GetInnerPoint3D)(Gamevoid* pRegion3D, Gamedouble& dx, Gamedouble& dy, Gamedouble& dz);

			extern UGGeoRegion3D_Create				_GeoRegion3D_Create ;
			extern UGGeoRegion3D_Destroy				_GeoRegion3D_Destroy ;
			extern UGGeoRegion3D_GetPoints				_GeoRegion3D_GetPoints ;
			extern UGGeoRegion3D_GetPointCount			_GeoRegion3D_GetPointCount ;
			extern UGGeoRegion3D_GetSubCount			_GeoRegion3D_GetSubCount ;
			extern UGGeoRegion3D_GetPolyCounts			_GeoRegion3D_GetPolyCounts ;
			extern UGGeoRegion3D_CreateRegion			_GeoRegion3D_CreateRegion ;
			extern UGGeoRegion3D_MakeWithPoints			_GeoRegion3D_MakeWithPoints;
			extern UGGeoRegion3D_AddPart				_GeoRegion3D_AddPart ;
			extern UGGeoRegion3D_InsertPart			_GeoRegion3D_InsertPart ;
			extern UGGeoRegion3D_RemovePart			_GeoRegion3D_RemovePart ;
			extern UGGeoRegion3D_Copy				_GeoRegion3D_Copy;
			extern UGGeoRegion3D_GetInnerPoint3D	_GeoRegion3D_GetInnerPoint3D;
			//===============================================================
			//===================GeoRegion===================================
			typedef Gamevoid(*UGGeoRegion_Create)(Gamevoid*& pRegion);
			typedef Gamevoid(*UGGeoRegion_MakeWithPoints)(Gamevoid* pRegion, Gamedouble*& pPoint2Ds, Gameint nPointCount);
			typedef Gamevoid(*UGGeoRegion_Destroy)(Gamevoid*& pRegion);
			typedef Gamevoid(*UGGeoRegion_Copy)(Gamevoid* pGeometry, Gamevoid*& pNewGeometry);

			extern UGGeoRegion_Create				_GeoRegion_Create;
			extern UGGeoRegion_MakeWithPoints		_GeoRegion_MakeWithPoints;
			extern UGGeoRegion_Destroy				_GeoRegion_Destroy;
			extern UGGeoRegion_Copy					_GeoRegion_Copy;
			//===============================================================
			//===================GeoModel3D==================================
			typedef Gamevoid(*UGGeoModel3D_Create)(Gamevoid* & pGeoModel3D);
			typedef Gamevoid(*UGGeoModel3D_Destroy)(Gamevoid* & pGeoModel3D);
			typedef bool(*UGGeoModel3D_IsLonLat)(Gamevoid* pGeoModel3D);
			typedef Gamedouble(*UGGeoModel3D_Area)(Gamevoid* pGeoModel3D);
			typedef Gamedouble(*UGGeoModel3D_MinZ)(Gamevoid* pGeoModel3D);
			typedef Gamedouble(*UGGeoModel3D_MaxZ)(Gamevoid* pGeoModel3D);
			typedef Gamedouble(*UGGeoModel3D_GetDataVertex)(Gamevoid* pGeoModel3D, DataSetGeometry* & pGeometrys,
				DataSetSkeleton*** & pSkeletons, Gameint & nSkeletonCount, 
				DataSetInstanceSkeleton*** & pInstanceSkeletons, Gameint & nInstanceSkeletonCount,
				DataSetMaterial*** & pMaterials, Gameint & nMaterialCount,
				DataSetTexture***  & pTextures, Gameint & nTextureCount);
			typedef Gamevoid (*UGGetDataTexture)(Gameint nIndex, DataSetTexture*** & pMaterials, DataSetTexture* & pOut);
			typedef Gamevoid (*UGGetDataMaterial)(Gameint nIndex, DataSetMaterial*** & pMaterials, DataSetMaterial* & pOut);
			typedef Gamevoid (*UGGetDataPatch)(Gameint nIndex, DataSetPatch*** & pMaterials, DataSetPatch* & pOut);
			typedef Gamevoid (*UGGetDataGeode)(Gameint nIndex, DataSetGeode*** & pMaterials, DataSetGeode* & pOut);
			typedef Gamevoid(*UGGetDataSkeleton)(Gameint nIndex, DataSetSkeleton*** & pMaterials, DataSetSkeleton* & pOut);
			typedef Gamevoid(*UGGeoModel3D_Copy)(Gamevoid* pGeometry, Gamevoid*& pNewGeometry);

			extern UGGeoModel3D_Create					_GeoModel3D_Create ;
			extern UGGeoModel3D_Destroy				_GeoModel3D_Destroy ;
			extern UGGeoModel3D_IsLonLat				_GeoModel3D_IsLonLat ;
			extern UGGeoModel3D_Area					_GeoModel3D_Area ;
			extern UGGeoModel3D_MinZ					_GeoModel3D_MinZ ;
			extern UGGeoModel3D_MaxZ					_GeoModel3D_MaxZ ;
			extern UGGeoModel3D_GetDataVertex			_GeoModel3D_GetDataVertex ;
			extern UGGetDataTexture					_GetDataTexture ;
			extern UGGetDataMaterial					_GetDataMaterial ;
			extern UGGetDataPatch						_GetDataPatch ;
			extern UGGetDataGeode						_GetDataGeode ;
			extern UGGetDataSkeleton					_GetDataSkeleton ;
			extern UGGeoModel3D_Copy					_GeoModel3D_Copy;
			//===============================================================
			//=======================GeoLine API=============================
			typedef Gamevoid(*UGGeoLine_Create)(Gamevoid* & pLine);
			typedef Gamevoid(*UGGeoLine_Destroy)(Gamevoid* & pLine);
			typedef Gamevoid(*UGGeoLine_GetPoints)(Gamevoid* pLine, Gamedouble** &pPoints);
			typedef Gamevoid(*UGGeoLine_GetPointCount)(Gamevoid* pLine, Gameint &nPointCount);
			typedef Gamevoid(*UGGeoLine_GetSubCount)(Gamevoid* pLine, Gameint &nSubCount);
			typedef Gamevoid(*UGGeoLine_GetPolyCounts)(Gamevoid* pLine, Gameint** &pPolyCount);
			typedef Gamevoid(*UGGeoLine_Copy)(Gamevoid* pGeometry, Gamevoid*& pNewGeometry);

			extern UGGeoLine_Create					_GeoLine_Create        ;
			extern UGGeoLine_Destroy					_GeoLine_Destroy       ;
			extern UGGeoLine_GetPoints				    _GeoLine_GetPoints     ;
			extern UGGeoLine_GetPointCount			    _GeoLine_GetPointCount ;
			extern UGGeoLine_GetSubCount				_GeoLine_GetSubCount   ;
			extern UGGeoLine_GetPolyCounts			    _GeoLine_GetPolyCounts ;
			extern UGGeoLine_Copy						_GeoLine_Copy;
			//==================================================================
			//=======================TrackingLayer API==========================
			typedef Gamevoid(*UGTRACKINGLAYER3DGETLAYERPTR)(Gamevoid*& pLayerPtr);
			typedef Gameint(*UGTRACKINGLAYER3DGETCOUNT)();
			typedef Gameint(*UGTRACKINGLAYER3DADD)(Gamevoid* pGeometry, Gamechar* tag, Gamevoid*& pRenderFeature);
			typedef Gamebool (*UGTRACKINGLAYER3DREMOVE)(Gameint nIndex);
			typedef Gamevoid (*UGTRACKINGLAYERGET)(Gameint index, Gamevoid*& pGeometry);
			typedef Gamechar*(*UGTRACKINGLAYERGETTAG)(Gameint nIndex);
			typedef Gamebool (*UGTRACKINGLAYERCLEAR)();
			typedef Gameint (*UGTRACKINGLAYERINDEXOF)(Gamechar* tag);

			extern UGTRACKINGLAYER3DGETLAYERPTR	_TrackingLayer3D_GetLayerPtr;
			extern UGTRACKINGLAYER3DGETCOUNT _TrackingLayer3D_GetCount ;
			extern UGTRACKINGLAYER3DADD      _TrackingLayer3D_Add      ;
			extern UGTRACKINGLAYER3DREMOVE   _TrackingLayer3D_Remove   ;
			extern UGTRACKINGLAYERGET        _TrackingLayer3D_Get      ;
			extern UGTRACKINGLAYERGETTAG   _TrackingLayer3D_GetTag   ;
			extern UGTRACKINGLAYERCLEAR      _TrackingLayer3D_SetTag   ;
			extern UGTRACKINGLAYERCLEAR    _TrackingLayer3D_Clear    ;
			extern UGTRACKINGLAYERINDEXOF    _TrackingLayer3D_IndexOf  ;
			//===================================================================
			//==========================Geometry API=============================
			typedef Gameint(*UGGEOMETRYGETTYPE)(Gamevoid* pGeometry);
			typedef Gamevoid(*UGGEOMETRY3DSETPOSITION)(Gamevoid* pGeometry, Gamedouble  dx, Gamedouble  dy, Gamedouble dz);
			typedef Gamevoid(*UGGEOMETRY3DGETPOSITION)(Gamevoid* pGeometry, Gamedouble & dx, Gamedouble & dy, Gamedouble &dz);
			typedef Gamevoid(*UGGEOMETRY3DSETSCALE)(Gamevoid* pGeometry, Gamedouble dx, Gamedouble dy, Gamedouble dz);
			typedef Gamevoid(*UGGEOMETRY3DGETSCALE)(Gamevoid* pGeometry, Gamedouble& dx, Gamedouble& dy, Gamedouble& dz);
			typedef Gamevoid(*UGGEOMETRY3DSETROTATION)(Gamevoid* pGeometry, Gamedouble& dx, Gamedouble& dy, Gamedouble& dz);
			typedef Gamevoid(*UGGEOMETRY3DGETROTATION)(Gamevoid* pGeometry, Gamedouble dx, Gamedouble dy, Gamedouble dz);
			typedef Gamevoid(*UGGEOMETRY_GETSTYLE)(Gamevoid* pGeometry, Gamevoid*& pStyle);
			typedef Gamevoid(*UGGEOMETRY_SETSTYLE)(Gamevoid* pGeometry, Gamevoid* pStyle);
			typedef Gamevoid(*UGGEOMETRY_CLEAR)(Gamevoid* pGeometry);
			typedef Gamevoid(*UGGEOMETRY_GETBOUNDS)(Gamevoid* pGeometry, Gamedouble& left, Gamedouble& right, Gamedouble& top, Gamedouble& bottom);

			extern UGGEOMETRYGETTYPE           _Geometry_GetType       ;
			extern UGGEOMETRY3DSETPOSITION     _Geometry3D_SetPosition ;
			extern UGGEOMETRY3DGETPOSITION     _Geometry3D_GetPosition ;
			extern UGGEOMETRY3DSETSCALE		_Geometry3D_SetScale    ;
			extern UGGEOMETRY3DGETSCALE		_Geometry3D_GetScale    ;
			extern UGGEOMETRY3DSETROTATION     _Geometry3D_SetRotation ;
			extern UGGEOMETRY3DGETROTATION     _Geometry3D_GetRotation ;
			extern UGGEOMETRY_GETSTYLE			_Geometry_GetStyle;
			extern UGGEOMETRY_SETSTYLE			_Geometry_SetStyle;
			extern UGGEOMETRY_CLEAR				_Geometry_Clear	;
			extern UGGEOMETRY_GETBOUNDS			_Geometry_GetBounds;

			//===================================================================
			//======================Render API=======================
			typedef Gamevoid(*UGRenderFeature_SetGeometry)(Gamevoid* pRenderFeature, Gamevoid* pGeometry);

			extern UGRenderFeature_SetGeometry	_RenderFeature_SetGeometry ;
			//===================================================================
			//======================HypsometricSetting API=======================
			typedef Gamevoid(*UGCreateHypsometricSetting)(Gamevoid* & pHypsometricSetting);
			typedef Gamevoid(*UGDestroyHypsometricSetting)(Gamevoid* & pHypsometricSetting);
			typedef Gamevoid(*UGSetDisplayMode)(Gamevoid* pHypsometricSetting, Gameint mode);
			typedef Gameint(*UGGetDisplayMode)(Gamevoid* pHypsometricSetting);
			typedef Gamevoid(*UGSetMinVisibleValue)(Gamevoid* pHypsometricSetting, Gamedouble minValue);
			typedef Gamedouble(*UGGetMinVisibleValue)(Gamevoid* pHypsometricSetting);
			typedef Gamevoid(*UGSetMaxVisibleValue)(Gamevoid* pHypsometricSetting, Gamedouble maxValue);
			typedef Gamedouble(*UGGetMaxVisibleValue)(Gamevoid* pHypsometricSetting);
			typedef Gamevoid(*UGSetAnalysisMode)(Gamevoid* pHypsometricSetting, Gameint mode);
			typedef Gameint(*UGGetAnalysisMode)(Gamevoid* pHypsometricSetting);
			typedef Gamevoid(*UGSetLinesInterval)(Gamevoid* pHypsometricSetting, Gamedouble dLinesInterval);
			typedef Gamedouble(*UGGetLinesInterval)(Gamevoid* pHypsometricSetting);
			typedef Gamevoid(*UGSetLineColor)(Gamevoid* pHypsometricSetting, Gamefloat fR, Gamefloat fG, Gamefloat fB, Gamefloat fA);
			typedef Gamevoid(*UGGetLineColor)(Gamevoid* pHypsometricSetting, Gamefloat& fR, Gamefloat& fG, Gamefloat& fB, Gamefloat& fA);

			typedef Gamevoid(*UGModifyTerrainObject_Create)(Gamevoid*& pModifyTerrainObject);
			typedef Gamevoid(*UGModifyTerrainObject_Destroy)(Gamevoid*& pModifyTerrainObject);
			typedef Gamevoid(*UGModifyTerrainObject_SetRegion)(Gamevoid* pModifyTerrainObject, Gamevoid* pGeoRegion3D);
			typedef Gamevoid(*UGModifyTerrainObject_SetHeight)(Gamevoid* pModifyTerrainObject, Gamedouble dHeight);
			typedef Gamevoid(*UGModifyTerrainSetting_Add)(Gamevoid* pModifyTerrainSetting, Gamevoid* pModifyTerrainObject, Gamechar* tag);
			typedef Gamevoid(*UGModifyTerrainSetting_Clear)(Gamevoid* pModifyTerrainSetting);

			extern UGCreateHypsometricSetting _CreateHypsometricSetting ;
			extern UGDestroyHypsometricSetting _DestroyHypsometricSetting ;
			extern UGSetDisplayMode _SetDisplayMode ;
			extern UGGetDisplayMode _GetDisplayMode ;
			extern UGSetMinVisibleValue _SetMinVisibleValue ;
			extern UGGetMinVisibleValue _GetMinVisibleValue ;
			extern UGSetMaxVisibleValue _SetMaxVisibleValue ;
			extern UGGetMaxVisibleValue _GetMaxVisibleValue ;
			extern UGSetAnalysisMode _SetAnalysisMode ;
			extern UGGetAnalysisMode _GetAnalysisMode ;
			extern UGSetLinesInterval _SetLinesInterval ;
			extern UGGetLinesInterval _GetLinesInterval ;
			extern UGSetLineColor _SetLineColor ;
			extern UGGetLineColor _GetLineColor ;

			extern UGModifyTerrainObject_Create		_ModifyTerrainObject_Create;
			extern UGModifyTerrainObject_Destroy	_ModifyTerrainObject_Destroy;
			extern UGModifyTerrainObject_SetRegion	_ModifyTerrainObject_SetRegion;
			extern UGModifyTerrainObject_SetHeight	_ModifyTerrainObject_SetHeight;
			extern UGModifyTerrainSetting_Add		_ModifyTerrainSetting_Add;
			extern UGModifyTerrainSetting_Clear		_ModifyTerrainSetting_Clear;
			//===================================================================
			//======================SlopeSetting API=======================
			typedef Gamevoid(*UGSlopeSetting_Create)(Gamevoid* & pSlopeSetting);
			typedef Gamevoid(*UGSlopeSetting_Destroy)(Gamevoid*& pSlopeSetting);
			typedef Gamevoid(*UGSlopeSetting_SetDisplayMode)(Gamevoid* pSlopeSetting, Gameint slopemode);
			typedef Gameint(*UGSlopeSetting_GetDisplayMode)(Gamevoid* pSlopeSetting);
			typedef Gamevoid(*UGSlopeSetting_SetMinVisibleValue)(Gamevoid* pSlopeSetting, Gamedouble minSlopeValue);
			typedef Gamedouble(*UGSlopeSetting_GetMinVisibleValue)(Gamevoid* pSlopeSetting);
			typedef Gamevoid(*UGSlopeSetting_SetMaxVisibleValue)(Gamevoid* pSlopeSetting, Gamedouble maxSlopeValue);
			typedef Gamedouble(*UGSlopeSetting_GetMaxVisibleValue)(Gamevoid* pSlopeSetting);

			extern UGSlopeSetting_Create _SlopeSetting_Create ;
			extern UGSlopeSetting_Destroy _SlopeSetting_Destroy ;
			extern UGSlopeSetting_SetDisplayMode _SlopeSetting_SetDisplayMode ;
			extern UGSlopeSetting_GetDisplayMode _SlopeSetting_GetDisplayMode ;
			extern UGSlopeSetting_SetMinVisibleValue _SlopeSetting_SetMinVisibleValue ;
			extern UGSlopeSetting_GetMinVisibleValue _SlopeSetting_GetMinVisibleValue ;
			extern UGSlopeSetting_SetMaxVisibleValue _SlopeSetting_SetMaxVisibleValue ;
			extern UGSlopeSetting_GetMaxVisibleValue _SlopeSetting_GetMaxVisibleValue ;
			//===================================================================
			//=========================JsonFile==================================
			typedef Gamevoid(*UGCREATEJSON)(Gamevoid* & pJson);
			typedef Gamevoid(*UGREMOVEALL)(Gamevoid* & pJson);
			typedef Gamevoid(*UGCREATEJSONWITHTYPE)(Gamevoid* & pJson, Gameint jsonValueType);
			typedef Gameint(*UGJSON_GETARRARYSIZE)(Gamevoid* pJson);
			typedef Gamebool(*UGJSON_GETAT)(Gamevoid* pJson, Gameint nIndex, Gamevoid*& jValue);
			typedef Gamebool(*UGJSON_GETATSTRING)(Gamevoid* pJson, Gameint nIndex, Gamechar*& sValue);
			typedef Gamevoid(*UGJSONADDSTRING)(Gamevoid* pJson, Gamechar* strFiled, Gamechar* strValue);
			typedef Gamevoid(*UGJSONADDDOUBLE)(Gamevoid* pJson, Gamechar* strFiled, Gamedouble dValue);
			typedef Gamevoid(*UGJSONADDINT)(Gamevoid* pJson, Gamechar* strFiled, Gameint nValue);
			typedef Gamevoid(*UGJSONADDFLOAT)(Gamevoid* pJson, Gamechar* strFiled, Gamefloat fValue);
			typedef Gamevoid(*UGJSONARRAYADDJSON)(Gamevoid* pJson, Gamevoid* pTargetJson);
			typedef Gamevoid(*UGJSONADDJSON)(Gamevoid* pJson, Gamechar* strFiled, Gamevoid* pTargetJson);
			typedef Gamevoid(*UGJSONADDBOOL)(Gamevoid* pJson, Gamechar* strFiled, Gamebool bValue);
			typedef Gamebool(*UGJSONGETVALUEBOOL)(Gamevoid* pJson, Gamechar* strFiled, Gamebool& bValue);
			typedef Gamebool(*UGJSONGETVALUEINT)(Gamevoid* pJson, Gamechar* strFiled, Gameint& iValue);
			typedef Gamebool(*UGJSONGETVALUEFLOAT)(Gamevoid* pJson, Gamechar* strFiled, Gamefloat& fValue);
			typedef Gamebool(*UGJSONGETVALUEDOUBLE)(Gamevoid* pJson, Gamechar* strFiled, Gamedouble& dValue);
			typedef Gamebool(*UGJSONGETVALUESTRING)(Gamevoid* pJson, Gamechar* strFiled, Gamechar*& fValue);
			typedef Gamebool(*UGJSONGETVALUEJSON)(Gamevoid* pJson, Gamechar* strFiled, Gamevoid*& jValue);
			typedef Gamebool(*UGCONTAINS)(Gamevoid* pJson, Gamechar* strFiled);
			typedef Gamevoid(*UGSAVETOSTDFILE)(Gamevoid* pJson, Gamechar* strName);
			typedef Gamevoid(*UGJSON_SAVETOSTRING)(Gamevoid* pJson, Gamechar*& strJson);
			typedef Gamevoid(*UGLOADFROMSTDFILE)(Gamechar* strName, Gamevoid*& pJson);
			typedef Gamevoid(*UGLOADFROMSTRING)(Gamechar* strName, Gamevoid*& pJson);
			typedef Gamebool(*UGJSONGETALLKEYS)(Gamevoid* pJson, Gameint & nCount, Gamechar*** & arrAllKey);

			extern UGCREATEJSON		   _CreateJson ;
			extern UGREMOVEALL			   _RemoveAll ;
			extern UGCREATEJSONWITHTYPE   _CreateJsonWithType ;
			extern UGJSON_GETARRARYSIZE   _Json_GetArrarySize ;
			extern UGJSON_GETAT		   _Json_GetAt ;
			extern UGJSON_GETATSTRING	   _Json_GetAtString ;
			extern UGJSONADDSTRING		   _JsonAddString ;
			extern UGJSONADDDOUBLE		   _JsonAddDouble ;
			extern UGJSONADDINT		   _JsonAddInt ;
			extern UGJSONADDFLOAT		   _JsonAddFloat ;
			extern UGJSONARRAYADDJSON	   _JsonArrayAddJson ;
			extern UGJSONADDJSON		   _JsonAddJson ;
			extern UGJSONADDBOOL		   _JsonAddBool ;
			extern UGJSONGETVALUEBOOL	   _JsonGetValueBool ;
			extern UGJSONGETVALUEINT	   _JsonGetValueInt ;
			extern UGJSONGETVALUEFLOAT	   _JsonGetValueFloat ;
			extern UGJSONGETVALUEDOUBLE   _JsonGetValueDouble ;
			extern UGJSONGETVALUESTRING   _JsonGetValueString ;
			extern UGJSONGETVALUEJSON	   _JsonGetValueJson ;
			extern UGCONTAINS			   _Contains ;
			extern UGSAVETOSTDFILE		   _SaveToStdFile ;
			extern UGJSON_SAVETOSTRING	   _Json_SaveToString ;
			extern UGLOADFROMSTDFILE	   _LoadFromStdFile ;
			extern UGLOADFROMSTRING	   _LoadFromString ;
			extern UGJSONGETALLKEYS	   _JsonGetAllKeys ;
			//===================================================================
			//=====================Query3D API===============================
			typedef Gamevoid(*UGQUERY3DCREATE)(Gamevoid* &pQuery3D);
			typedef Gamevoid(*UGQUERY3DREALSESPATIALQUERY)(Gamevoid* pQuery3D);
			typedef Gamevoid(*UGQUERY3DSETGEOMETRY)(Gamevoid* pQuery3D, Gamevoid* pGeometry3D);
			typedef Gamevoid(*UGQUERY3DSETPICKRECT)(Gamevoid* pQuery3D, Gamefloat fStartX, Gamefloat fStartY, Gamefloat fEndX, Gamefloat fEndY);
			typedef Gamevoid(*UGQUERY3DSETPOSITIONMODE)(Gamevoid* pQuery3D, Gameint nMode);
			typedef Gameint(*UGQUERY3DGETPOSITIONMODE)(Gamevoid* pQuery3D);
			typedef Gamevoid(*UGQUERY3DADDLAYERID)(Gamevoid* pQuery3D, Gameint nLayerID);
			typedef Gamevoid(*UGQUERY3DREMOVELAYERID)(Gamevoid* pQuery3D, Gameint nLayerID);
			typedef Gamevoid(*UGQUERY3DUPDATERECTSELECT)(Gamevoid* pQuery3D);
			typedef Gamevoid(*UGQUERY3DGETSPATIALQUERYIDS)(Gamevoid* pQuery3D, Gameint*& pLayerIDs, Gameint& nCount, Gameint**& pSelectionIDs, Gameint*& pIDCount);
			typedef Gamevoid(*UGQUERY3DGETQUERYIDS)(Gamevoid* pQuery3D, Gamechar**& pLayerNames, Gameint& nCount, Gameint**& ids, Gameint*& idCount);

			extern UGQUERY3DCREATE				 _Query3D_Create;
			extern UGQUERY3DREALSESPATIALQUERY	_Query3D_RealseSpatialQuery;
			extern UGQUERY3DSETGEOMETRY	       _Query3D_SetGeometry;
			extern UGQUERY3DSETPICKRECT        _Query3D_SetPickRect      ;
			extern UGQUERY3DSETPOSITIONMODE    _Query3D_SetPositionMode  ;
			extern UGQUERY3DGETPOSITIONMODE    _Query3D_GetPositionMode  ;
			extern UGQUERY3DADDLAYERID         _Query3D_AddLayerID       ;
			extern UGQUERY3DREMOVELAYERID	    _Query3D_RemoveLayerID    ;
			extern UGQUERY3DUPDATERECTSELECT   _Query3D_UpdateRectSelect ;
			extern UGQUERY3DGETSPATIALQUERYIDS _Query3D_GetSpatialQueryIDs ;
			extern UGQUERY3DGETQUERYIDS		_Query3D_GetQueryIDs        ;
			//===================================================================
			//=========================Facade API================================
			typedef Gamevoid(*UGOUTPUTSTREETFACADE)(Gamechar* strPath, Gamevoid* pGeoLine3D, Gamedouble dResoultion, 
				Gamedouble dFarDist, Gamedouble dMinHeight, Gamedouble dMaxHeight);
			extern UGOUTPUTSTREETFACADE _OutputStreetFacade ;
			//===============================================================
			//=========================FlyManager API========================
			typedef Gamevoid(*UGFLYMANAGER_CREATE)(Gamevoid*& pFlyManager);
			typedef Gamevoid(*UGFLYMANAGER_DESTROY)(Gamevoid*& pFlyManager);
			typedef Gamevoid(*UGFLYMANAGER_PLAY)(Gamevoid* pFlyManager);
			typedef Gamevoid(*UGFLYMANAGER_STOP)(Gamevoid* pFlyManager);
			typedef Gamevoid(*UGFLYMANAGER_PAUSE)(Gamevoid* pFlyManager);
			typedef Gameint(*UGFLYMANAGER_GETSTATUS)(Gamevoid* pFlyManager);
			typedef Gamevoid(*UGFLYMANAGER_UPDATE)(Gamevoid* pFlyManager);
			typedef Gamevoid(*UGFLYMANAGER_GETROUTES)(Gamevoid* pFlyManager, Gamevoid*& pRoutes);
			typedef Gamedouble(*UGFLYMANAGER_CALCGLOBALPROGRESSTIME)(Gamevoid* pFlyManager);
			typedef Gamevoid(*UGFLYMANAGER_SETGLOBALPROGRESSTIME)(Gamevoid* pFlyManager, Gamedouble duration);
			typedef Gamedouble(*UGFLYMANAGER_GETPLAYRATE)(Gamevoid* pFlyManager);
			typedef Gamevoid(*UGFLYMANAGER_SETPLAYRATE)(Gamevoid* pFlyManager, Gamedouble dRate);
			typedef Gameint(*UGFLYMANAGER_GETTURNINGMODE)(Gamevoid* pFlyManager);
			typedef Gamevoid(*UGFLYMANAGER_SETTURNINGMODE)(Gamevoid* pFlyManager, Gameint nTurningMode);
			typedef Gameint(*UGFLYMANAGER_GETCURRENTSTOPINDEX)(Gamevoid* pFlyManager);
			typedef Gamevoid(*UGFLYMANAGER_SETCURRENTSTOPINDEX)(Gamevoid* pFlyManager, Gameint nIndex);
			typedef Gameint(*UGFLYMANAGER_GETARRIVEDNEWSTOPINDEX)(Gamevoid* pFlyManager);
			typedef Gamevoid(*UGFLYMANAGER_SETORIGINALPOSITION)(Gamevoid* pFlyManager, Gamedouble x, Gamedouble y, Gamedouble z);
			typedef Gamedouble(*UGFLYMANAGER_GETCURRENTPROGRESS)(Gamevoid* pFlyManager);

			extern UGFLYMANAGER_CREATE					_FlyManager_Create ;
			extern UGFLYMANAGER_DESTROY				_FlyManager_Destroy ;
			extern UGFLYMANAGER_PLAY					_FlyManager_Play ;
			extern UGFLYMANAGER_STOP					_FlyManager_Stop ;
			extern UGFLYMANAGER_PAUSE					_FlyManager_Pause ;
			extern UGFLYMANAGER_GETSTATUS				_FlyManager_GetStatus ;
			extern UGFLYMANAGER_UPDATE					_FlyManager_Update ;
			extern UGFLYMANAGER_GETROUTES				_FlyManager_GetRoutes ;
			extern UGFLYMANAGER_CALCGLOBALPROGRESSTIME _FlyManager_CalcGlobalProgressTime ;
			extern UGFLYMANAGER_SETGLOBALPROGRESSTIME	_FlyManager_SetGlobalProgressTime ;
			extern UGFLYMANAGER_GETPLAYRATE			_FlyManager_GetPlayRate ;
			extern UGFLYMANAGER_SETPLAYRATE			_FlyManager_SetPlayRate ;
			extern UGFLYMANAGER_GETTURNINGMODE			_FlyManager_GetTurningMode ;
			extern UGFLYMANAGER_SETTURNINGMODE			_FlyManager_SetTurningMode ;
			extern UGFLYMANAGER_GETCURRENTSTOPINDEX		_FlyManager_GetCurrentStopIndex;
			extern UGFLYMANAGER_SETCURRENTSTOPINDEX		_FlyManager_SetCurrentStopIndex;
			extern UGFLYMANAGER_GETARRIVEDNEWSTOPINDEX	_FlyManager_GetArrivedNewStopIndex;
			extern UGFLYMANAGER_SETORIGINALPOSITION		_FlyManager_SetOriginalPosition;
			extern UGFLYMANAGER_GETCURRENTPROGRESS		_FlyManager_GetCurrentProgress;
			//===============================================================
			//=========================Routes API============================
			typedef Gamebool(*UGROUTES_FROMFILE)(Gamevoid* pRoutes, Gamechar* strFile);
			typedef Gameint(*UGROUTES_GETCOUNT)(Gamevoid* pRoutes);
			typedef Gamevoid(*UGROUTES_GETITEM)(Gamevoid* pRoutes, Gameint index, Gamevoid*& pRoute);
			typedef Gameint(*UGROUTES_INDEXOF)(Gamevoid* pRoutes, Gamechar* RouteName);
			typedef Gamebool(*UGROUTES_SETCURRENTROUTEINDEX)(Gamevoid* pRoutes, Gameint nIndex);
			typedef Gameint(*UGROUTES_GETCURRENTROUTEINDEX)(Gamevoid* pRoutes);
			typedef Gamebool(*UGROUTES_TOFILE)(Gamevoid* pRoutes, Gamechar* strFile);
			typedef Gamebool(*UGROUTES_REMOVE)(Gamevoid* pRoutes, Gameint nIndex);
			typedef Gamevoid(*UGROUTE_GETNAME)(Gamevoid* pRoute, Gamechar*& strName);
			typedef Gamevoid(*UGROUTE_SETNAME)(Gamevoid* pRoute, Gamechar* strName);
			typedef Gamevoid(*UGROUTE_SETISFLYINGLOOP)(Gamevoid* pRoute, Gamebool bloop);
			typedef Gamebool(*UGROUTE_GETISFLYINGLOOP)(Gamevoid* pRoute);
			typedef Gamebool(*UGROUTE_CREATE)(Gamevoid* pRoutes, Gamevoid*& pRoute);
			typedef Gamevoid(*UGROUTE_GETSTOPS)(Gamevoid* pRoute, Gamevoid*& pStops);
			typedef Gamevoid(*UGROUTE_SETHEADINGFIXED)(Gamevoid* pRoute, bool bSet);
			typedef Gamebool(*UGROUTE_ISHEADINGFIXED)(Gamevoid* pRoute);
			typedef Gamevoid(*UGROUTE_SETTILTFIXED)(Gamevoid* pRoute, bool bSet);
			typedef Gamebool(*UGROUTE_ISTILTFIXED)(Gamevoid* pRoute);
			typedef Gamevoid(*UGROUTESTOPS_GETSTOP)(Gamevoid* pStops, Gameint nIndex, Gamevoid*& pStop);
			typedef Gameint(*UGROUTESTOPS_GETCOUNT)(Gamevoid* pStops);
			typedef Gamebool(*UGROUTESTOPS_INSERTSTOP)(Gamevoid* pStops, Gamevoid* pStop, Gameint nIndex);
			typedef Gamebool(*UGROUTESTOPS_REMOVE)(Gamevoid* pStops, Gameint nIndex);
			typedef Gamevoid(*UGROUTESTOP_CREATE)(Gamevoid*& pStop);
			typedef Gamevoid(*UGROUTESTOP_DESTORY)(Gamevoid*& pStop);
			typedef Gamevoid(*UGROUTESTOP_GETNAME)(Gamevoid* pStop, Gamechar*& strName);
			typedef Gamevoid(*UGROUTESTOP_SETNAME)(Gamevoid* pStop, Gamechar* strName);
			typedef Gamevoid(*UGROUTESTOP_SETCAMERA)(Gamevoid* pStop, Gamevoid* pCamera);
			typedef Gamevoid(*UGROUTESTOP_GETCAMERASTATE)(Gamevoid* pStop, Gamedouble& dx, Gamedouble& dy, Gamedouble& dz, Gamedouble& dTilt, Gamedouble& dHeading, Gamedouble& dRoll);
			typedef Gamedouble(*UGROUTESTOP_GETDURATION)(Gamevoid* pStop);
			typedef Gamevoid(*UGROUTESTOP_SETDURATION)(Gamevoid* pStop, Gamedouble dDuration);

			extern UGROUTES_FROMFILE				_Routes_FromFile ;
			extern UGROUTES_GETCOUNT				_Routes_GetCount ;
			extern UGROUTES_GETITEM				_Routes_GetItem ;
			extern UGROUTES_INDEXOF				_Routes_IndexOf ;
			extern UGROUTES_SETCURRENTROUTEINDEX	_Routes_SetCurrentRouteIndex ;
			extern UGROUTES_GETCURRENTROUTEINDEX	_Routes_GetCurrentRouteIndex ;
			extern UGROUTES_TOFILE					_Routes_ToFile;
			extern UGROUTES_REMOVE					_Routes_Remove;
			extern UGROUTE_GETNAME					_Route_GetName ;
			extern UGROUTE_SETNAME					_Route_SetName ;
			extern UGROUTE_SETISFLYINGLOOP			_Route_SetIsFlyingLoop ;
			extern UGROUTE_GETISFLYINGLOOP			_Route_GetIsFlyingLoop ;
			extern UGROUTE_CREATE					_Route_Create;
			extern UGROUTE_GETSTOPS					_Route_GetStops;
			extern UGROUTE_SETHEADINGFIXED			_Route_SetHeadingFixed;
			extern UGROUTE_ISHEADINGFIXED			_Route_IsHeadingFixed;
			extern UGROUTE_SETTILTFIXED				_Route_SetTiltFixed;
			extern UGROUTE_ISTILTFIXED				_Route_IsTiltFixed;
			extern UGROUTESTOPS_GETSTOP				_RouteStops_GetStop;
			extern UGROUTESTOPS_GETCOUNT			_RouteStops_GetCount;
			extern UGROUTESTOPS_INSERTSTOP			_RouteStops_InsertStop;
			extern UGROUTESTOPS_REMOVE				_RouteStops_Remove;
			extern UGROUTESTOP_CREATE				_RouteStop_Create;
			extern UGROUTESTOP_DESTORY				_RouteStop_Destory;
			extern UGROUTESTOP_GETNAME				_RouteStop_GetName;
			extern UGROUTESTOP_SETNAME				_RouteStop_SetName;
			extern UGROUTESTOP_SETCAMERA			_RouteStop_SetCamera;
			extern UGROUTESTOP_GETCAMERASTATE		_RouteStop_GetCameraState;
			extern UGROUTESTOP_GETDURATION			_RouteStop_GetDuration;
			extern UGROUTESTOP_SETDURATION			_RouteStop_SetDuration;
			//===============================================================
			//=========================Selection3D API=============================
			typedef Gamevoid(*UGSELECTION3DCREATEBYLAYER3D)(Gamevoid*& pSelection, Gamevoid* pLayer3D);
			typedef Gamevoid(*UGSELECTION3DDESTROY)(Gamevoid*& pSelection);
			typedef Gamevoid(*UGSELECTION3DGETSTYLE3D)(Gamevoid* pSelection, Gamevoid*& pStyle);
			typedef Gameint(*UGSELECTION3DGETCOUNT)(Gamevoid* pSelection);
			typedef Gameint(*UGSELECTION3DADD)(Gamevoid* pSelection, Gameint nID);
			typedef Gamebool(*UGSELECTION3DREMOVEAT)(Gamevoid* pSelection, Gameint nID);
			typedef Gamevoid(*UGSELECTION3DCLEAR)(Gamevoid* pSelection);
			typedef Gameint(*UGSELECTION3DGETAT)(Gamevoid* pSelection, Gameint nIndex);
			typedef Gamebool(*UGSELECTION3DFINDID)(Gamevoid* pSelection, Gameint nID);

			extern UGSELECTION3DCREATEBYLAYER3D     _Selection3D_CreateByLayer      ;
			extern UGSELECTION3DDESTROY    _Selection3D_Destroy     ;
			extern UGSELECTION3DGETSTYLE3D _Selection3D_GetStyle3D  ;
			extern UGSELECTION3DGETCOUNT	_Selection3D_GetCount    ;
			extern UGSELECTION3DADD		_Selection3D_Add         ;
			extern UGSELECTION3DREMOVEAT	_Selection3D_RemoveAt    ;
			extern UGSELECTION3DCLEAR      _Selection3D_Clear       ;
			extern UGSELECTION3DGETAT		_Selection3D_GetAt       ;
			extern UGSELECTION3DFINDID     _Selection3D_FindID      ;
			
			//===============================================================
			//=========================PrjCoordSys API=============================
			typedef Gamevoid(*UGPRJCOORDSYS_CREATE)(Gamevoid*& pPrj);
			typedef Gamevoid(*UGPRJCOORDSYS_GETNAME)(Gamevoid* pPrj, Gamechar*& strName);
			typedef Gamebool(*UGPRJCOORDSYS_FROMEPSGCODE)(Gamevoid* pPrj, Gameint nEPSG);
			typedef Gamebool(*UGPRJCOORDSYS_FROMFILE)(Gamevoid* pPrj, Gamechar* strFile);
			typedef Gamevoid(*UGPRJCOORDSYS_DISPOSE)(Gamevoid* pPrj);
			typedef Gamebool(*UGPRJCOORDSYS_INVERSE)(Gamevoid* pPrj, Gamedouble*& pPoint3Ds, Gameint nPtCount);
			typedef Gamebool(*UGPRJCOORDSYS_FORWARD)(Gamevoid* pPrj, Gamedouble*& pPoint3Ds, Gameint nPtCount);

			extern UGPRJCOORDSYS_CREATE	_PrjCoordSys_Create;
			extern UGPRJCOORDSYS_GETNAME	_PrjCoordSys_GetName;
			extern UGPRJCOORDSYS_FROMEPSGCODE	_PrjCoordSys_FromEPSGCode;
			extern UGPRJCOORDSYS_FROMFILE	_PrjCoordSys_FromFile;
			extern UGPRJCOORDSYS_DISPOSE	_PrjCoordSys_Dispose;
			extern UGPRJCOORDSYS_INVERSE	_PrjCoordSys_Inverse;
			extern UGPRJCOORDSYS_FORWARD	_PrjCoordSys_Forward;
			//=====================================================================
			//=========================Style3D API=================================
			typedef Gamevoid(*UGSTYLE3D_CREATE)(Gamevoid*& pStyle3D);
			typedef Gamevoid(*UGSTYLE3D_DESTROY)(Gamevoid*& pStyle3D);
			typedef Gamevoid(*UGSTYLE3D_SETALTITUDEMODE)(Gamevoid* pStyle3D, Gameint mode);
			typedef Gameint(*UGSTYLE3D_GETALTITUDEMODE)(Gamevoid* pStyle3D);
			typedef Gamevoid(*UGSTYLE3D_SETBOTTOMALTITUDE)(Gamevoid* pStyle3D, Gamedouble dAltitude);
			typedef Gamedouble(*UGSTYLE3D_GETBOTTOMALTITUDE)(Gamevoid* pStyle3D);
			typedef Gamevoid(*UGSTYLE3D_SETEXTENDHEIGHT)(Gamevoid* pStyle3D, Gamedouble dHeight);
			typedef Gamedouble(*UGSTYLE3D_GETEXTENDHEIGHT)(Gamevoid* pStyle3D);
			typedef Gamevoid(*UGSTYLE3D_SETFILLCOLOR)(Gamevoid* pStyle3D, Gamefloat fR, Gamefloat fG, Gamefloat fB, Gamefloat fA);
			typedef Gamevoid(*UGSTYLE3D_GETFILLCOLOR)(Gamevoid* pStyle3D, Gamefloat& fR, Gamefloat& fG, Gamefloat& fB, Gamefloat& fA);
			typedef Gamevoid(*UGSTYLE3D_SETFILL3DMODE)(Gamevoid* pStyle3D, Gameint mode);
			typedef Gameint(*UGSTYLE3D_GETFILL3DMODE)(Gamevoid* pStyle3D);
			typedef Gamevoid(*UGSTYLE3D_SETLINECOLOR3D)(Gamevoid* pStyle3D, Gamefloat fR, Gamefloat fG, Gamefloat fB, Gamefloat fA);
			typedef Gamevoid(*UGSTYLE3D_GETLINECOLOR3D)(Gamevoid* pStyle3D, Gamefloat& fR, Gamefloat& fG, Gamefloat& fB, Gamefloat& fA);
			typedef Gamevoid(*UGSTYLE3D_SETLINEWIDTH)(Gamevoid* pStyle3D, Gamedouble fLineWidth);
			typedef Gamedouble(*UGSTYLE3D_GETLINEWIDTH)(Gamevoid* pStyle3D);
			typedef Gamevoid(*UGSTYLE3D_SETMARKER3DSCALE)(Gamevoid* pStyle3D, Gamedouble dX, Gamedouble dY, Gamedouble dZ);
			typedef Gamevoid(*UGSTYLE3D_GETMARKER3DSCALE)(Gamevoid* pStyle3D, Gamedouble& dX, Gamedouble& dY, Gamedouble& dZ);
			typedef Gamevoid(*UGSTYLE3D_SETMARKER3DROTATE)(Gamevoid* pStyle3D, Gamedouble dX, Gamedouble dY, Gamedouble dZ);
			typedef Gamevoid(*UGSTYLE3D_GETMARKER3DROTATE)(Gamevoid* pStyle3D, Gamedouble& dX, Gamedouble& dY, Gamedouble& dZ);
			typedef Gamevoid(*UGSTYLE3D_SETMARKER3DTRANSLATION)(Gamevoid* pStyle3D, Gamedouble dX, Gamedouble dY, Gamedouble dZ);
			typedef Gamevoid(*UGSTYLE3D_GETMARKER3DTRANSLATION)(Gamevoid* pStyle3D, Gamedouble& dX, Gamedouble& dY, Gamedouble& dZ);
			
			typedef Gamevoid(*UGSTYLE3D_SETSIDETEXTURE)(Gamevoid* pStyle3D, Gamechar* filePath);
			typedef Gamevoid(*UGSTYLE3D_SETTILINGU)(Gamevoid* pStyle3D, Gamedouble dTilingU);
			typedef Gamevoid(*UGSTYLE3D_SETTILINGV)(Gamevoid* pStyle3D, Gamedouble dTilingV);
			typedef Gamevoid(*UGSTYLE3D_SETTOPTEXTURE)(Gamevoid* pStyle3D, Gamechar* filePath);
			typedef Gamevoid(*UGSTYLE3D_SETTOPTILINGU)(Gamevoid* pStyle3D, Gamedouble dTilingU);
			typedef Gamevoid(*UGSTYLE3D_SETTOPTILINGV)(Gamevoid* pStyle3D, Gamedouble dTilingV);

			extern UGSTYLE3D_SETSIDETEXTURE	_Style3D_SetSideTexture;
			extern UGSTYLE3D_SETTILINGU _Style3D_SetTilingU;
			extern UGSTYLE3D_SETTILINGV _Style3D_SetTilingV;
			extern UGSTYLE3D_SETTOPTEXTURE _Style3D_SetTopTexture;
			extern UGSTYLE3D_SETTOPTILINGU _Style3D_SetTopTilingU;
			extern UGSTYLE3D_SETTOPTILINGV _Style3D_SetTopTilingV;

			extern UGSTYLE3D_CREATE _Style3D_Create;
			extern UGSTYLE3D_DESTROY _Style3D_Destroy;
			extern UGSTYLE3D_SETALTITUDEMODE _Style3D_SetAltitudeMode;
			extern UGSTYLE3D_GETALTITUDEMODE _Style3D_GetAltitudeMode;
			extern UGSTYLE3D_SETBOTTOMALTITUDE _Style3D_SetBottomAltitude;
			extern UGSTYLE3D_GETBOTTOMALTITUDE _Style3D_GetBottomAltitude;
			extern UGSTYLE3D_SETEXTENDHEIGHT _Style3D_SetExtendHeight;
			extern UGSTYLE3D_GETEXTENDHEIGHT _Style3D_GetExtendHeight;
			extern UGSTYLE3D_SETFILLCOLOR _Style3D_SetFillColor;
			extern UGSTYLE3D_GETFILLCOLOR _Style3D_GetFillColor;
			extern UGSTYLE3D_SETFILL3DMODE _Style3D_SetFill3DMode;
			extern UGSTYLE3D_GETFILL3DMODE _Style3D_GetFill3DMode;
			extern UGSTYLE3D_SETLINECOLOR3D _Style3D_SetLineColor3D;
			extern UGSTYLE3D_GETLINECOLOR3D _Style3D_GetLineColor3D;
			extern UGSTYLE3D_SETLINEWIDTH _Style3D_SetLineWidth;
			extern UGSTYLE3D_GETLINEWIDTH _Style3D_GetLineWidth;
			extern UGSTYLE3D_SETMARKER3DSCALE _Style3D_SetMarker3DScale;
			extern UGSTYLE3D_GETMARKER3DSCALE _Style3D_GetMarker3DScale;
			extern UGSTYLE3D_SETMARKER3DROTATE _Style3D_SetMarker3DRotate;
			extern UGSTYLE3D_GETMARKER3DROTATE _Style3D_GetMarker3DRotate;
			extern UGSTYLE3D_SETMARKER3DTRANSLATION _Style3D_SetMarker3DTranslation;
			extern UGSTYLE3D_GETMARKER3DTRANSLATION _Style3D_GetMarker3DTranslation;
			//=====================================================================
			//=========================UDB API=================================
			typedef Gamebool(*UGUDB_SAVEMATERIALTOJSON)(Gamevoid* pMtlData, Gamechar* Json_Path);

			extern UGUDB_SAVEMATERIALTOJSON _SaveMaterialToJson;
			//=====================================================================
			//=============================GlobalImage API ========================
			typedef Gameint(*UGGLOBALIMAGE_ADDEXCAVATIONREGION)(Gamevoid* pUGCGlobalImage,Gamevoid* pGeometry, Gamechar* strTag);
			typedef Gamevoid(*UGGLOBALIMAGE_CLEAREXCAVATIONREGIONS)(Gamevoid* pUGCGlobalImage);
			typedef Gamevoid(*UGGLOBALIMAGE_GETEXCAVATIONREGION)(Gamevoid* pUGCGlobalImage, Gameint nIndex,Gamevoid* &pGeometry);
			typedef Gamevoid(*UGGLOBALIMAGE_GETEXCAVATIONREGIONTAG)(Gamevoid* pUGCGlobalImage, Gameint nIndex, Gamechar*& strTag);
			typedef Gameint(*UGGLOBALIMAGE_INDEXOFEXCAVATIONREGION)(Gamevoid* pUGCGlobalImage, Gamechar* strTag);
			typedef Gamebool(*UGGLOBALIMAGE_REMOVEEXCAVATIONREGION)(Gamevoid* pUGCGlobalImage, Gameint nIndex);
			typedef Gamebool(*UGGLOBALIMAGE_SETEXCAVATIONREGION)(Gamevoid* pUGCGlobalImage, Gameint nIndex, Gamechar* strTag);
			typedef Gamevoid(*UGGLOBALIMAGE_SETVISIBLE)(Gamevoid* pUGCGlobalImage, Gamebool bVisible);
			typedef Gamebool(*UGGLOBALIMAGE_GETVISIBLE)(Gamevoid* pUGCGlobalImage);

			extern UGGLOBALIMAGE_ADDEXCAVATIONREGION _GlobalImage_AddExcavationRegion;
			extern UGGLOBALIMAGE_CLEAREXCAVATIONREGIONS _GlobalImage_ClearExcavationRegions;
			extern UGGLOBALIMAGE_GETEXCAVATIONREGION _GlobalImage_GetExcavationRegion;
			extern UGGLOBALIMAGE_GETEXCAVATIONREGIONTAG _GlobalImage_GetExcavationRegionTag;
			extern UGGLOBALIMAGE_INDEXOFEXCAVATIONREGION _GlobalImage_IndexOfExcavationRegion;
			extern UGGLOBALIMAGE_REMOVEEXCAVATIONREGION _GlobalImage_RemoveExcavationRegion;
			extern UGGLOBALIMAGE_SETEXCAVATIONREGION _GlobalImage_SetExcavationRegionTag;
			extern UGGLOBALIMAGE_SETVISIBLE		_GlobalImage_SetVisible;
			extern UGGLOBALIMAGE_GETVISIBLE		_GlobalImage_GetVisible;
			//=================================================================
			extern TArray<TPair<FString, Gamevoid**> > arrAPIs;

			extern TArray<TPair<FString, Gamevoid**> > arrCloudLicenseAPIs;
			//=================================================================
			class SUPERMAP_API RealspaceDLL
			{
			public:
				//! \brief 加载所有的函数方法
				static bool LoadAllAPI();

			public:
				//! \brief 是否所有的函数都已经加载
				static bool m_bLoadAllAPI;
			};
		}
	}
}
