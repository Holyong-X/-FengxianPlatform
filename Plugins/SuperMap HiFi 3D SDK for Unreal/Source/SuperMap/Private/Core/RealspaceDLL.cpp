#include "Core/RealspaceDLL.h"
#include "SuperMap.h"
#if PLATFORM_WINDOWS
#include "Windows/WindowsPlatformProcess.h"
#endif

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			bool RealspaceDLL::m_bLoadAllAPI = false;

			UGLogin _Login = nullptr;
			UGGetLicenseNum	_GetLicenseNum = nullptr;
			UGGetLicenseID _GetLicenseID = nullptr;
			UGGetLicenseRemainDays _GetLicenseRemainDays = nullptr;
			UGGetLicenseVersion _GetLicenseVersion = nullptr;
			UGGetLicenseUserId _GetLicenseUserId = nullptr;
			UGLogout _Logout = nullptr;
			UGConnect _Connect = nullptr;
			UGConnectTrial _ConnectTrial = nullptr;

			UGLICENSEVERIFY_GAMEENGINE _LicenseVerify_GameEngine = nullptr;

			UGLayer3D_GetOSGBType			_Layer3D_GetOSGBType = nullptr;
			UGLayer3D_IsMarkerLayer          _Layer3D_IsMarkerLayer = nullptr;
			UGLayer3D_SetMarkerLayer          _Layer3D_SetMarkerLayer = nullptr;
			UGSETVISIBLE _SetVisible = nullptr;
			UGGETVISIBLE _GetVisible = nullptr;
			UGHASCOMPRESSOPTIONS  _HasCompressOptions = nullptr;
			UGGETNODENAME         _GetNodeName = nullptr;
			UGGETLAYERNODENAMEHASHCODE _GetLayerNodeNameHashCode = nullptr;
			UGSETORIGINALPOSITION _SetOriginalPosition = nullptr;
			UGGETCENTREPOSITION   _GetCentrePosition = nullptr;
			UGGETLAYERBOUNDS      _GetLayerBounds = nullptr;
			UGSETINITIALIZED      _SetInitialized = nullptr;

			UGSETCUSTOMCLIPPLANE  _SetCustomClipPlane = nullptr;
			UGSETCUSTOMCLIPBOX    _SetCustomClipBox = nullptr;
			UGGETCUSTOMCLIPBOX    _GetCustomClipBox = nullptr;
			UGGETCLIPPLANEPARAMETER _GetClipPlaneParameter = nullptr;
			UGISCLIP			    _IsClip = nullptr;
			UGSETCLIPLINECOLOR      _SetClipLineColor = nullptr;
			UGGETCLIPLINECOLOR      _GetClipLineColor = nullptr;
			UGGETPLANECLIPMODE      _GetPlaneClipMode = nullptr;
			UGCLEARCUSTOMCLIPPLANE  _ClearCustomClipPlane = nullptr;
			UGSETSWIPEENABLED		_SetSwipeEnabled = nullptr;
			UGGETSWIPEENABLED		_GetSwipeEnabled = nullptr;
			UGSETSWIPEREGION		_SetSwipeRegion = nullptr;
			UGGETSWIPEREGION		_GetSwipeRegion = nullptr;
			UGLAYER3DADDSELECTEDID  _Layer3D_AddSelectedID = nullptr;
			UGLAYER3DREMOVEALLSELECTEDID _Layer3D_RemoveAllSelectedID = nullptr;
			UGLAYER3DSETOPAQUERATE   _Layer3D_SetOpaqueRate = nullptr;
			UGLAYER3DGETOPAQUERATE   _Layer3D_GetOpaqueRate = nullptr;
			UGLAYER3DSETSELECTSTYLE  _Layer3D_SetSelectStyle = nullptr;
			UGLAYER3DGETSELECTSTYLE  _Layer3D_GetSelectStyle = nullptr;
			UGLAYER3DGETID		     _Layer3D_GetID = nullptr;
			UGLAYER3DGETTYPE		 _Layer3D_GetType = nullptr;
			UGLAYER3DGETNAME		 _Layer3D_GetName = nullptr;
			UGLAYER3DSETSTYLE        _Layer3D_SetStyle = nullptr;
			UGLAYER3DGETSTYLE		 _Layer3D_GetStyle = nullptr;
			UGLAYER3DSETMAXOBJECTVISIBLEDISTANCE		_SetMaxObjectVisibleDistance = nullptr;
			UGLAYER3DSETMINOBJECTVISIBLEDISTANCE		_SetMinObjectVisibleDistance = nullptr;
			UGLAYER3DGETMAXMINOBJECTVISIBLEDISTANCE		_GetMaxMinObjectVisibleDistance = nullptr;
			UGLAYER3DGETDATAPATH						_Layer3D_GetDataPath = nullptr;
			UGLAYER3DREMOVEGPUSHAREDPARAMETERS			_Layer3D_RemoveGPUSharedParameters = nullptr;

			// 获取属性名字
			UGGetFieldInfosObject      _GetFieldInfosObject = nullptr;
			// 获取属性
			UGGetAllFieldValueObject   _GetAllFieldValueObject = nullptr;
			// 删除属性
			UGFreeArrayObjectFieldNode _FreeArrayObjectFieldNode = nullptr;
			// 获取属性字段名字
			UGGetFieldInfos            _GetFieldInfos = nullptr;
			// 获取设置图层LOD层级
			UGSetLODRangeScale         _SetLODRangeScale = nullptr;
			// 获取图层LOD层级
			UGGetLODRangeScale         _GetLODRangeScale = nullptr;
			// 获取图层渲染节点名字
			UGGETSCENENODENAME		   _GetSceneNodeName = nullptr;
			UGCALFLATTENPARAM		   _CalFlattenParam = nullptr;

			UGADDFLATTENREGION		   _AddFlattenRegion = nullptr;
			UGRELEASEALLFLATTENREGIONS _ReleaseAllFlattenRegions = nullptr;
			UGDELETEATFLATTENREGION    _DeleteAtFlattenRegion = nullptr;
			UGINDEXOFFLATTENREGION     _IndexOfFlattenRegion = nullptr;
			UGGETFLATTENREGION         _GetFlattenRegion = nullptr;
			UGGETFLATTENREGIONCOUNT    _GetFlattenRegionCount = nullptr;
			UGGETFLATTENREGIONTAG      _GetFlattenRegionTag = nullptr;
			UGSETFLATTENREGIONTAG      _SetFlattenRegionTag = nullptr;
			UGGETFLATTENSHADERPARAMTER _GetFlattenShaderParamter = nullptr;
			UGGetMaxDataValue		   _GetMaxDataValue = nullptr;
			UGGetMinDataValue		   _GetMinDataValue = nullptr;
			UGSETOBJECTSVISIBLE	       _SetObjectsVisible = nullptr;
			UGSETOBJECTSCOLOR		   _SetObjectsColor = nullptr;
			UGGETOBJECTSCOLOR								_GetObjectsColor = nullptr;
			UGREMOVEOBJECTSCOLOR							_RemoveObjectsColor = nullptr;
			UGRESETOBJECTSCOLOR								_ResetObjectsColor = nullptr;
			UGSETOBJECTSMATERIAL	   _SetObjectsMaterial = nullptr;

			UGSETMODIFYREGIONS		   _SetModifyRegions = nullptr;
			UGCLEARMODIFYREGIONS	   _ClearModifyRegions = nullptr;
			UGSETEXCAVATION			   _SetExcavation = nullptr;
			UGGETEXCAVATIONSHADERPARAMTER _GetExcavationShaderParamter = nullptr;
			UGADDMATERIALASSOCIATEWITHSCP _AddMaterialAssociateWithScp = nullptr;
			UGSETDECODEMESHOPT			_SetDecodeMeshopt = nullptr;
			UGGETDECODEMESHOPT			_GetDecodeMeshopt = nullptr;
			UGSETLOADINGPRIORITY			_SetLoadingPriority = nullptr;
			UGGETLOADINGPRIORITY			_GetLoadingPriority = nullptr;
			UGS3MLAYERGETDATAMAXVALUE	_S3MLayer_GetDataMaxValue = nullptr;
			UGS3MLAYERGETDATAMINVALUE	_S3MLayer_GetDataMinValue = nullptr;
			UGS3MLAYERSETCOVERIMAGERYLAYER	_S3MLayer_SetCoverImageryLayer = nullptr;

			UGADDLAYER           _AddLayer = nullptr;
			UGADD                _Add = nullptr;
			UGADDDATASETLAYER    _AddDatasetLayer = nullptr;
			UGGETLAYERNODENAME   _GetLayerNodeName = nullptr;
			UGGETISVISIBLE       _GetIsVisible = nullptr;
			UGSETISVISIBLE		 _SetIsVisible = nullptr;
			UGADDONLINEMAP		 _AddOnlineMap = nullptr;
			UGADDARCGISMAP		 _AddArcgisMap = nullptr;
			UGREMOVELAYERS		 _RemoveLayers = nullptr;
			UGADDTIANDITU        _AddTianditu = nullptr;
			UGADDOSGBLAYER		 _AddOSGBLayer = nullptr;
			UGADDDATASETMODEL    _AddDatasetModel = nullptr;

			UGGEOBOXCREATE			_GeoBox_Create = nullptr;
			UGGEOBOXDESTROY			_GeoBox_Destroy = nullptr;
			UGGEOBOXGETBOXHEIGHT	_GeoBox_GetBoxHeight = nullptr;
			UGGEOBOXGETBOXWIDTH		_GeoBox_GetBoxWidth = nullptr;
			UGGEOBOXGETBOXLENGTH	_GeoBox_GetBoxLength = nullptr;
			UGGEOBOXSETBOXHEIGHT	_GeoBox_SetBoxHeight = nullptr;
			UGGEOBOXSETBOXWIDTH		_GeoBox_SetBoxWidth = nullptr;
			UGGEOBOXSETBOXLENGTH	_GeoBox_SetBoxLength = nullptr;
			UGGEOBOXGETCENTERPOINT  _GeoBox_GetCenterPoint = nullptr;
			UGGEOBOXCOPY				_GeoBox_Copy = nullptr;

			UGGETALLUPDATE						_GetAllUpdata = nullptr;
			UGFREEARRAYROEMPTYNODE				_FreeArrayROEmptyNode = nullptr;
			UGFREEARRAYRONODE					_FreeArrayRONode = nullptr;
			UGFREEBYTE							_FreeByte = nullptr;
			UGFREE_UCHAR						_FreeUChar = nullptr;
			UGFREEARRAYROMATERIAL				_FreeArrayROMaterial = nullptr;
			UGFREEARRAYROTEXTURE				_FreeArrayROTexture = nullptr;
			UGFREEARRAYHASHCODE					_FreeArrayHashCode = nullptr;
			UGDECOMPOSEVIEWMATRIX				_DecomposeViewMatrix = nullptr;
			UGDECOMPOSEVIEWMATRIX2				_DecomposeViewMatrix2 = nullptr;
			UGINITDATABUFFERCALLBACKHANDLE		_InitDataBufferCallbackHandle = nullptr;
			UGINITRENDERTEXTURECALLBACKHANDLE	_InitRenderTextureCallbackHandle = nullptr;
			UGINITCAMERACALLBACKHANDLE			_InitCameraCallbackHandle = nullptr;
			UGINITSCENENODECALLBACKHANDLE		_InitSceneNodeCallbackHandle = nullptr;
			UGINITENTITYCALLBACKHANDLE          _InitEntityCallbackHandle = nullptr;
			UGINITTEXTURECALLBACKHANDLE		    _InitTextureCallbackHandle = nullptr;
			UGINITMATERIALMANAGERCALLBACKHANDLE _InitMaterialManagerCallbackHandle = nullptr;
			UGINITMATERIALMANAGERSHARECALLBACKHANDLE _InitMaterialManagerShareCallbackHandle = nullptr;
			UGINITINSTANCEMESHCALLBACKHANDLE    _InitInstanceMeshCallbackHandle = nullptr;
			UGINITMAINCAMERACALLBACKHANDLE		_InitMainCameraCallbackHandle = nullptr;
			UGINITGRAPHICSCALLBACKHANDLE		_InitGraphicsCallbackHandle = nullptr;

			UGSETCAMERA                      _SetCamera = nullptr;
			UGSCENE_GETCAMERA				 _Scene_GetCamera = nullptr;
			UGSCENE_GETCREATESKIRT			 _GetCreateSkirt = nullptr;
			UGSCENE_SETCREATESKIRT			 _SetCreateSkirt = nullptr;
			UGSCENE_SETSKIRTHEIGHT           _SetSkirtHeight = nullptr;
			UGSCENE_FLYTOCAMERA				 _Scene_FlyToCamera = nullptr;
			UGSCENE_SETTERRAINEXAGGERATION	 _Scene_SetTerrainExaggeration = nullptr;
			UGSCENE_GETTERRAINEXAGGERATION	 _Scene_GetTerrainExaggeration = nullptr;
			UGSCENE_SETENDFLYFUNC			 _Scene_SetEndFlyFunc = nullptr;
			UGLONGITUDELATITUDETOGAMEENGINE  _LongitudeLatitudeToGameEngine = nullptr;
			UGTOXML							 _ToXML = nullptr;
			UGSCENE_SETSHOWINVALIDATION		 _Scene_SetShowInvalidation = nullptr;
			UGSCENE_SETSTEREOMODE			 _Scene_SetStereoMode = nullptr;
			UGSCENE_GETSTEREOMODE			 _Scene_GetStereoMode = nullptr;

			UGSCENE_GETTILEBOUNDS			_Scene_GetTileBounds = nullptr;
			UGSCENE_REFRESHRASTER			_Scene_RefreshRaster = nullptr;
			UGSCENE_FROMXMLFORPATH			_Scene_FromXML = nullptr;
			UGSCENE_GETLAYER3DS				_Scene_GetLayer3Ds = nullptr;
			UGSCENE_GETTERRAINLAYERS		_Scene_GetTerrainLayers = nullptr;
			UGSCENE_UPDATA					_Scene_Updata = nullptr;
			UGSCENE_GETGLOBALIMAGE			_Scene_GetGlobalImage = nullptr;
			UGSCENE_GLOBALREFRESHRASTER		_Scene_GlobalRefreshRaster = nullptr;
			UGINITIALSCENE _InitialScene = nullptr;
			UGDESTROYSCENE _DestroyScene = nullptr;
			UGKILL         _Kill = nullptr;
			UGSETPOSITION  _SetPosition = nullptr;
			UGRENDER       _Render = nullptr;
			UGSceneControl_GetWorkspace    _SceneControl_GetWorkspace = nullptr;
			UGSceneControl_Onsize          _SceneControl_OnSize = nullptr;
			UGSceneControl_SetMultiTexture _SceneControl_SetMultiTexture = nullptr;

			UGWorkspace_GetDataSources _Workspace_GetDataSources = nullptr;

			UGDataSources_GetAt _DataSources_GetAt = nullptr;
			UGDataSources_SetAt _DataSources_SetAt = nullptr;
			UGDataSources_ReleaseAt _DataSources_ReleaseAt = nullptr;
			UGDataSources_GetAtByAlias _DataSources_GetAtByAlias = nullptr;

			UGGETTERRAINBOUNDS        _GetTerrainBounds = nullptr;
			UGSETTERRAINVISIBLE       _SetTerrainVisible = nullptr;
			UGGETTERRAINVISIBLE       _GetTerrainVisible = nullptr;
			UGGETMINHEIGHT            _GetMinHeight = nullptr;
			UGGETMAXHEIGHT            _GetMaxHeight = nullptr;
			UGGETSHOWINVALIDATION     _GetShowInvalidation = nullptr;
			UGSETSHOWINVALIDATION     _SetShowInvalidation = nullptr;
			UGSETTERRAINLODRANGESCALE _SetTerrainLODRangeScale = nullptr;
			UGGETTERRAINLODRANGESCALE _GetTerrainLODRangeScale = nullptr;
			UGTerrainLayer_GetTopLevel _TerrainLayer_GetTopLevel = nullptr;
			UGTerrainLayer_SetSlopeSetting _TerrainLayer_SetSlopeSetting = nullptr;
			UGTERRAINLAYER_GETNAME		_TerrainLayer_GetName = nullptr;
			UGTERRAINLAYER_GETHEIGHT		_TerrainLayer_GetHeight = nullptr;
			UGHASTIN              _HasTIN = nullptr;
			UGADDTERRAINLAYER     _AddTerrainLayer = nullptr;
			UGADDWEBTERRAIN       _AddWebTerrain = nullptr;
			UGREMOVETERRAINLAYERS _RemoveTerrainLayers = nullptr;
			UGADDSTK              _AddSTK = nullptr;
			UGADDTIANDITUTERRAIN  _AddTiandituTerrain = nullptr;
			UGGETMODIFYTERRAINSETTING  _GetModifyTerrainSetting = nullptr;

			UGRAYINTERSECTIONWITHSPHERE          _RayIntersectionWithSphere = nullptr;
			UGCALLOCATIONANDROTATION             _CalLocationAndRotation    = nullptr;
			UGCALPITCHANDHEADING                 _CalPitchAndHeading        = nullptr;
			UGCALPITCHANDHEADINGWITHWORLDOFFSET  _CalPitchAndHeadingWithWorldOffset  = nullptr;
			UGRAYINTERSECTIONWITHSPHEREADNRADIUS _RayIntersectionWithSphereAndRadius = nullptr;
			UGRAYINTERSECTIONWITHELLIPSOIDADNRADIUS	_RayIntersectionWithEllipsoidAndRadius = nullptr;

			UGCAMERACREATE           _CameraCreate = nullptr;
			UGCAMERADESTORY          _CameraDestory = nullptr;
			UGCAMERAGETHEADING       _CameraGetHeading = nullptr;
			UGCAMERAGETTILT             _CameraGetTilt = nullptr;
			UGCAMERAGETROLL             _CameraGetRoll = nullptr;
			UGCAMERAGETLONGTITUDE	_Camera_GetLongitude = nullptr;
			UGCAMERAGETLATITUDE		_Camera_GetLatitude = nullptr;
			UGCAMERAGETALTITUDE		_Camera_GetAltitude = nullptr;
			UGCAMERASETVIEWMATRIXDOUBLE _CameraSetViewMatrix = nullptr;
			UGCAMERAGETVIEWPROJECTMATRIX _CameraGetViewProjectMatrix = nullptr;
			UGCAMERAGETPOSITION                _CameraGetPosition = nullptr;
			UGCAMEARGETROTATION                _CameraGetRotation = nullptr;
			UGCAMERAGETDIRECTION	          _CameraGetDirection = nullptr;
			UGCAMERAGETUP                            _CameraGetUp = nullptr;
			UGCAMERAGETRIGHT                      _CameraGetRight = nullptr;
			UGCAMERAGETPROJECTPARAMETER _CameraGetProjectParamter = nullptr;
			UGCAMERASETUGCSTATE				   _CameraSetUGCState = nullptr;

			UGRGBAID       _RGBAID = nullptr;
			UGRGBAObjectID _RGBAObjectID = nullptr;
			UGIDRGBA       _IDRGBA = nullptr;

			UGTRIANGULATE        _Triangulate = nullptr;
			UGFREEUGINT			 _FreeUGInt = nullptr;
			UGFREE_UG_UINT       _FreeUGUint = nullptr;
			UGFREE_UG_USHORT     _FreeUGUshort = nullptr;
			UGFREEUGFLOAT		 _FreeUGFloat = nullptr;
			UGCALHEADINGANDPITCH _CalHeadingAndPitch = nullptr;
			UGCALHASHCODE		 _CalHashCode = nullptr;
			UGCALHASHCODEBYCHAR  _CalHashCodeByChar = nullptr;
			UGFREEDOUBLEARRAY	 _FreeDoubleArray = nullptr;
			UGFREELONG			 _FreeLong = nullptr;
			UGFREE_CHAR_POINTER_ARRAY _FreeCharPointerArray = nullptr;
			UGCHAMFER			_Chamfer = nullptr;
			UGFREEUGDOUBLE		_FreeUGDouble = nullptr;
			UGKDTREE_CREATE				_KDTree_Create = nullptr;
			UGKDTREE_SEARCHKDTREEDIS2	_KDTree_SearchKdTreeDis2 = nullptr;
			UGKDTREE_DISPOSE			_KDTree_Dispose = nullptr;
			UGCALMATRIX					_CalMatrix = nullptr;

			UGCREATSIGHTLINE			     _CreateSightline = nullptr;
			UGDESTROYSOGHTLINE				 _DestroySightline = nullptr;
			UGSIGHTLINEBUILD				 _SightlineBuild = nullptr;
			UGSETSIGHTLINEVISIBLECOLOR	     _SetSightlineVisibleColor = nullptr;
			UGGETSIGHTLINEVISIBLECOLOR	     _GetSightlineVisibleColor = nullptr;
			UGSETSIGHTLINEHIDDENCOLOR	     _SetSightlineHiddenColor = nullptr;
			UGGETSIGHTLINEHIDDENCOLOR	     _GetSightlineHiddenColor = nullptr;
			UGGETSIGHTLINEVIEWERPOSITION     _GetSightlineViewerPosition = nullptr;
			UGSETSIGHTLINEVIEWERPOSITION     _SetSightlineViewerPosition = nullptr;
			UGGETSIGHTLINETARGETPOINT        _GetSightlineTargetPoint = nullptr;
			UGSETSIGHTLINETARGETPOINT	     _SetSightlineTargetPoint = nullptr;
			UGADDSIGHTLINETARGETPOINT	     _AddSightlineTargetPoint = nullptr;
			UGGETSIGHTLINETARGETPOINTCOUNT   _GetSightlineTargetPointCount = nullptr;
			UGREMOVESIGHTLINETARGETPOINT     _RemoveSightlineTargetPoint = nullptr;
			UGREMOVESIGHTLINEALLTARGETPOINT  _RemoveSightlineAllTargetPoint = nullptr;
			UGGETALLSIGHTLINERESULTFORUE     _GetAllSightlineResultForUE = nullptr;
			UGISINSIDEVIEW					 _IsInsideView = nullptr;
			UGGETBARRIERPOINTANDREFLECTIONPOINT _GetBarrierPointAndReflectionPoint = nullptr;

			UGCREATESKYLINE              _CreateSkyline = nullptr;
			UGDESTROYSKYLINE             _DestroySkyline = nullptr;
			UGSETSKYLINEVIEWERPITCH      _SetSkylineViewerPitch = nullptr;
			UGGETSKYLINEVIEWERPITCH      _GetSkylineViewerPitch = nullptr;
			UGSETSKYLINEVIEWERDIRECTION  _SetSkylineViewerDirection = nullptr;
			UGGETSKYLINEVIEWERDIRECTION  _GetSkylineViewerDirection = nullptr;
			UGSETSKYLINEVIEWERPOSITION	 _SetSkylineViewerPosition = nullptr;
			UGGETSKYLINEVIEWERPOSITION   _GetSkylineViewerPosition = nullptr;
			UGGETSKYLINE3DFORGAMEENGINE  _GetSkyline3DForGameEngine = nullptr;
			UGGETSKYLINERADIUS			 _GetSkylineRadius = nullptr;
			UGSETSKYLINERADIUS			 _SetSkylineRadius = nullptr;
			UGGETSKYLINE				 _GetSkyline = nullptr;
			UGBUILDSKYLINE			     _BuildSkyline = nullptr;
			UGGETSKYLINE2D               _GetSkyline2D = nullptr;
			UGGETSKYLINESECTORBODY       _GetSkylineSectorBody = nullptr;
			UGSKYLINEGETOBJECTIDS		 _Skyline_GetObjectIDs = nullptr;
			UGCREATEPROJECTIONIMAGE                _CreateProjectionImage = nullptr;
			UGDESTROYPROJECTIONIMAGE               _DestroyProjectionImage = nullptr;
			UGBUILDPROJECTIONIMAGE				   _BuildProjectionImage = nullptr;
			UGSETPROJECTIONIMAGEPITCH              _SetProjectionImagePitch = nullptr;
			UGGETPROJECTIONIMAGEPITCH			   _GetProjectionImagePitch = nullptr;
			UGSETPROJECTIONIMAGEHEADING            _SetProjectionImageHeading = nullptr;
			UGGETPROJECTIONIMAGEHEADING			   _GetProjectionImageHeading = nullptr;
			UGSETPROJECTIONIMAGEVIEWPOSITION       _SetProjectionImageViewPosition = nullptr;
			UGGETPROJECTIONIMAGEVIEWPOSITION       _GetProjectionImageViewPosition = nullptr;
			UGGETPROJECTIONIMAGEDEPTHHANDLE		   _GetProjectionImageDepthHandle = nullptr;
			UGGETPROJECTIONIMAGECAMERA             _GetProjectionImageGetCamera = nullptr;
			UGPROJECTIONIMAGERENDER				   _ProjectionImageRender = nullptr;
			UGSETPROJECTIONIMAGEAFFINEMATRIX	   _SetProjectionImageAffineMatrix = nullptr;
			UGGETPROJECTIONIMAGEAFFINEMATRIX	   _GetProjectionImageAffineMatrix = nullptr;
			UGSETPROJECTIONIMAGEISHOMONYMYPOINTS   _SetProjectionImageIsHomonymyPoints = nullptr;
			UGGETPROJECTIONIMAGEISHOMONYMYPOINTS   _GetProjectionImageIsHomonymyPoints = nullptr;
			UGPROJECTIONIMAGETOXML				   _ProjectionImageToXML = nullptr;
			UGPROJECTIONIMAGEFROMXML			   _ProjectionImageFromXML = nullptr;
			UGPROJECTIONIMAGESETHINLINELENGTH	   _ProjectionImageSetHintLineLength = nullptr;

			UGCREATEVIEWSHED                _CreateViewShed = nullptr;
			UGDESTROYVIEWSHED               _DestroyViewShed = nullptr;
			UGBUILDVIEWSHED					_BuildViewShed = nullptr;
			UGSETVIEWSHEDPITCH              _SetViewShedPitch = nullptr;
			UGGETVIEWSHEDPITCH				_GetViewShedPitch = nullptr;
			UGSETVIEWSHEDHEADING            _SetViewShedHeading = nullptr;
			UGGETVIEWSHEDHEADING			_GetViewShedHeading = nullptr;
			UGSETVIEWSHEDHORIZONTALFOV      _SetViewShedHorizontalFov = nullptr;
			UGGETVIEWSHEDHORIZONTALFOV      _GetViewShedHorizontalFov = nullptr;
			UGSETVIEWSHEDVERTICALFOV        _SetViewShedVerticalFov = nullptr;
			UGGETVIEWSHEDVERTICALFOV        _GetViewShedVerticalFov = nullptr;
			UGSETVIEWSHEDDISTANCE           _SetViewShedDistance = nullptr;
			UGGETVIEWSHEDDISTANCE           _GetViewShedDistance = nullptr;
			UGSETVIEWSHEDVIEWPOSITION       _SetViewShedViewerPosition = nullptr;
			UGGETVIEWSHEDVIEWPOSITION       _GetViewShedViewerPosition = nullptr;
			UGSET_DIST_DIR_BY_POINT_BY_UGC  _SetDistDirByPoint = nullptr;
			UGSETVIEWSHEDVISIBLEAREACOLOR   _SetViewShedVisibleAreaColor = nullptr;
			UGGETVIEWSHEDVISIBLEAREACOLOR   _GetViewShedVisibleAreaColor = nullptr;
			UGSETVIEWSHEDHIDDENAREACOLOR    _SetViewShedHiddenAreaColor = nullptr;
			UGGETVIEWSHEDHIDDENAREACOLOR    _GetViewShedHiddenAreaColor = nullptr;
			UGGETCAMERAFORUE				_GetCamera = nullptr;
			UGGETDEPTHRENDERTEXTUREHANDLE   _GetDepthRenderTextureHandle = nullptr;
			UGGETVIEWSHEDVISIBLEBODY		_GetViewShedVisibleBody = nullptr;
			UGGETVIEWSHEDHIDDENBODY         _GetViewShedHiddenBody = nullptr;
			UGVIEWSHED_GETQUALITY			_Viewshed_GetQuality = nullptr;
			UGVIEWSHED_SETQUALITY			_Viewshed_SetQuality = nullptr;
			UGVIEWSHED_GETBARRIERPOINTS		_ViewShed_GetBarrierPoints = nullptr;
			UGVIEWSHED_GETNAME				_ViewShed_GetName = nullptr;
			UGVIEWSHED_SETNAME				_ViewShed_SetName = nullptr;
			UGVIEWSHED_REMOVEFROMANALYST3DLIST	_ViewShed_RemoveFromAnalyst3DList = nullptr;

			UGMULTIVIEWSHED3D_CREATE				_MultiViewShed3D_Create = nullptr;
			UGMULTIVIEWSHED3D_DESTROY				_MultiViewShed3D_Destroy = nullptr;
			UGMULTIVIEWSHED3D_ADDVIEWSHED			_MultiViewShed3D_AddViewShed = nullptr;
			UGMULTIVIEWSHED3D_REMOVEVIEWSHED		_MultiViewShed3D_RemoveViewShed = nullptr;
			UGMULTIVIEWSHED3D_BUILD					_MultiViewShed3D_Build = nullptr;

			UGReleaseCharArray				  _ReleaseCharArray = nullptr;
			UGReleaseIntArray				  _ReleaseIntArray = nullptr;
			UGReleaseDoubleArray			  _ReleaseDoubleArray = nullptr;
			UGFREEDATAINDICE                  _FreeDataIndice = nullptr;
			UGFREEDATAVERTEX                  _FreeDataVertex = nullptr;
			UGCALCMERCATORFROMSPHERICALFLOAT  _CalcMercatorFromSphericalFloat = nullptr;
			UGCARTESIANTOSPHERICALD           _CartesianToSphericalD = nullptr;
			UGSPHERICALTOCARTESIAN            _SphericalToCartesian = nullptr;
			UGGETROTATIONMATRIX				  _GetRotationMatrix = nullptr;
			UGROTATIONMATRIX				  _RotationMatrix = nullptr;

			UGDATASET_GETBOUNDS				_Dataset_GetBounds = nullptr;
			UGDATASET_GETTYPE				_Dataset_GetType = nullptr;
			UGDATASET_QUERY					_Dataset_Query = nullptr;
			UGDATASET_QUERYBYSQL            _Dataset_QueryBySql = nullptr;
			UGDATASET_GETFIELDINFOS			_Dataset_GetFieldInfos = nullptr;

			UGDATASET_QUERYFIELD			_Dataset_QueryField = nullptr;
			UGDATASET_QUERYATTRIBUTEBYID	_Dataset_QueryAttributeById = nullptr;

			UGOPENDATASOURCE				_OpenDataSource = nullptr;
			UGGETDATASETBYNAME				_GetDatasetByName = nullptr;
			UGGETDATASETNAME				_GetDatasetName = nullptr;
			UGCLOSEDATASOURCE				_CloseDataSource = nullptr;
			UGISOPENEDDATASOURCE			_IsOpenedDataSource = nullptr;
			UGOPENDATASET					_OpenDataset = nullptr;
			UGISOPENEDDATASET				_IsOpenedDataset = nullptr;
			UGGETDATASETMODELDATA			_GetDatasetModelData = nullptr;
			UGFREEMODELMESH					_FreeModelMesh = nullptr;
			UGFREEMODELMATERIAL				_FreeModelMaterial = nullptr;
			UGFREEMODELTEXTURE				_FreeModelTexture = nullptr;
			UGFREEDATASETSKELETONS          _FreeDataSetSkeletons = nullptr;
			UGFREEDATASETINSTANCESKELETONS  _FreeDataSetInstanceSkeletons = nullptr;
			UGDATASOURCE_OPEN				_DataSource_Open = nullptr;
			UGDATASOURCE_CLOSE				_DataSource_Close = nullptr;
			UGDATASOURCE_GETDATASET			_DataSource_GetDataset = nullptr;

			UGGeoPoint3D_Create				_GeoPoint3D_Create = nullptr;
			UGGeoPoint3D_Destroy			_GeoPoint3D_Destroy = nullptr;
			UGGeoPoint3D_SetPoint3D			_GeoPoint3D_SetPoint3D = nullptr;
			UGGeoPoint3D_GetPoint3D			_GeoPoint3D_GetPoint3D = nullptr;
			UGGeoPoint3D_Copy				_GeoPoint3D_Copy = nullptr;

			UGGeoLine3D_Create					_GeoLine3D_Create = nullptr;
			UGGeoLine3D_Destroy					_GeoLine3D_Destroy = nullptr;
			UGGeoLine3D_GetPoints				_GeoLine3D_GetPoints = nullptr;
			UGGeoLine3D_GetPointCount			_GeoLine3D_GetPointCount = nullptr;
			UGGeoLine3D_GetSubCount				_GeoLine3D_GetSubCount = nullptr;
			UGGeoLine3D_GetPolyCounts			_GeoLine3D_GetPolyCounts = nullptr;
			UGGeoLine3D_Make                    _GeoLine3D_Make = nullptr;
			UGGeoLine3D_AddPart					_GeoLine3D_AddPart = nullptr;
			UGGeoLine3D_RemovePart				_GeoLine3D_RemovePart = nullptr;
			UGGeoLine3D_Copy					_GeoLine3D_Copy = nullptr;

			UGGeoRegion3D_Create				_GeoRegion3D_Create = nullptr;
			UGGeoRegion3D_Destroy				_GeoRegion3D_Destroy = nullptr;
			UGGeoRegion3D_GetPoints				_GeoRegion3D_GetPoints = nullptr;
			UGGeoRegion3D_GetPointCount			_GeoRegion3D_GetPointCount = nullptr;
			UGGeoRegion3D_GetSubCount			_GeoRegion3D_GetSubCount = nullptr;
			UGGeoRegion3D_GetPolyCounts			_GeoRegion3D_GetPolyCounts = nullptr;
			UGGeoRegion3D_CreateRegion			_GeoRegion3D_CreateRegion = nullptr;
			UGGeoRegion3D_MakeWithPoints		_GeoRegion3D_MakeWithPoints = nullptr;
			UGGeoRegion3D_AddPart				_GeoRegion3D_AddPart = nullptr;
			UGGeoRegion3D_InsertPart			_GeoRegion3D_InsertPart = nullptr;
			UGGeoRegion3D_RemovePart			_GeoRegion3D_RemovePart = nullptr;
			UGGeoRegion3D_Copy					_GeoRegion3D_Copy = nullptr;
			UGGeoRegion3D_GetInnerPoint3D		_GeoRegion3D_GetInnerPoint3D = nullptr;

			UGGeoRegion_Create				_GeoRegion_Create = nullptr;
			UGGeoRegion_MakeWithPoints		_GeoRegion_MakeWithPoints = nullptr;
			UGGeoRegion_Destroy				_GeoRegion_Destroy = nullptr;
			UGGeoRegion_Copy				_GeoRegion_Copy = nullptr;

			UGGeoModel3D_Create					_GeoModel3D_Create = nullptr;
			UGGeoModel3D_Destroy				_GeoModel3D_Destroy = nullptr;
			UGGeoModel3D_IsLonLat				_GeoModel3D_IsLonLat = nullptr;
			UGGeoModel3D_Area					_GeoModel3D_Area = nullptr;
			UGGeoModel3D_MinZ					_GeoModel3D_MinZ = nullptr;
			UGGeoModel3D_MaxZ					_GeoModel3D_MaxZ = nullptr;
			UGGeoModel3D_GetDataVertex			_GeoModel3D_GetDataVertex = nullptr;
			UGGetDataTexture					_GetDataTexture = nullptr;
			UGGetDataMaterial					_GetDataMaterial = nullptr;
			UGGetDataPatch						_GetDataPatch = nullptr;
			UGGetDataGeode						_GetDataGeode = nullptr;
			UGGetDataSkeleton					_GetDataSkeleton = nullptr;
			UGGeoModel3D_Copy					_GeoModel3D_Copy = nullptr;

			UGGeoLine_Create					_GeoLine_Create = nullptr;
			UGGeoLine_Destroy					_GeoLine_Destroy = nullptr;
			UGGeoLine_GetPoints				    _GeoLine_GetPoints = nullptr;
			UGGeoLine_GetPointCount			    _GeoLine_GetPointCount = nullptr;
			UGGeoLine_GetSubCount				_GeoLine_GetSubCount = nullptr;
			UGGeoLine_GetPolyCounts			    _GeoLine_GetPolyCounts = nullptr;
			UGGeoLine_Copy						_GeoLine_Copy = nullptr;

			UGTRACKINGLAYER3DGETLAYERPTR	_TrackingLayer3D_GetLayerPtr = nullptr;
			UGTRACKINGLAYER3DGETCOUNT _TrackingLayer3D_GetCount = nullptr;
			UGTRACKINGLAYER3DADD      _TrackingLayer3D_Add = nullptr;
			UGTRACKINGLAYER3DREMOVE   _TrackingLayer3D_Remove = nullptr;
			UGTRACKINGLAYERGET        _TrackingLayer3D_Get = nullptr;
			UGTRACKINGLAYERGETTAG     _TrackingLayer3D_GetTag = nullptr;
			UGTRACKINGLAYERCLEAR      _TrackingLayer3D_SetTag = nullptr;
			UGTRACKINGLAYERCLEAR      _TrackingLayer3D_Clear = nullptr;
			UGTRACKINGLAYERINDEXOF    _TrackingLayer3D_IndexOf = nullptr;

			UGGEOMETRYGETTYPE           _Geometry_GetType = nullptr;
			UGGEOMETRY3DSETPOSITION     _Geometry3D_SetPosition = nullptr;
			UGGEOMETRY3DGETPOSITION     _Geometry3D_GetPosition = nullptr;
			UGGEOMETRY3DSETSCALE		_Geometry3D_SetScale = nullptr;
			UGGEOMETRY3DGETSCALE		_Geometry3D_GetScale = nullptr;
			UGGEOMETRY3DSETROTATION     _Geometry3D_SetRotation = nullptr;
			UGGEOMETRY3DGETROTATION     _Geometry3D_GetRotation = nullptr;
			UGGEOMETRY_GETSTYLE			_Geometry_GetStyle		= nullptr;
			UGGEOMETRY_SETSTYLE			_Geometry_SetStyle		= nullptr;
			UGGEOMETRY_CLEAR			_Geometry_Clear			= nullptr;
			UGGEOMETRY_GETBOUNDS		_Geometry_GetBounds		= nullptr;
			UGRenderFeature_SetGeometry	_RenderFeature_SetGeometry = nullptr;

			UGCreateHypsometricSetting  _CreateHypsometricSetting = nullptr;
			UGDestroyHypsometricSetting _DestroyHypsometricSetting = nullptr;
			UGSetDisplayMode            _SetDisplayMode = nullptr;
			UGGetDisplayMode            _GetDisplayMode = nullptr;
			UGSetMinVisibleValue        _SetMinVisibleValue = nullptr;
			UGGetMinVisibleValue        _GetMinVisibleValue = nullptr;
			UGSetMaxVisibleValue        _SetMaxVisibleValue = nullptr;
			UGGetMaxVisibleValue        _GetMaxVisibleValue = nullptr;
			UGSetAnalysisMode           _SetAnalysisMode = nullptr;
			UGGetAnalysisMode           _GetAnalysisMode = nullptr;
			UGSetLinesInterval          _SetLinesInterval = nullptr;
			UGGetLinesInterval          _GetLinesInterval = nullptr;
			UGSetLineColor              _SetLineColor = nullptr;
			UGGetLineColor              _GetLineColor = nullptr;

			UGModifyTerrainObject_Create		_ModifyTerrainObject_Create = nullptr;
			UGModifyTerrainObject_Destroy		_ModifyTerrainObject_Destroy = nullptr;
			UGModifyTerrainObject_SetRegion		_ModifyTerrainObject_SetRegion = nullptr;
			UGModifyTerrainObject_SetHeight		_ModifyTerrainObject_SetHeight = nullptr;
			UGModifyTerrainSetting_Add			_ModifyTerrainSetting_Add = nullptr;
			UGModifyTerrainSetting_Clear		_ModifyTerrainSetting_Clear = nullptr;

			UGSlopeSetting_Create         _SlopeSetting_Create         = nullptr;
			UGSlopeSetting_Destroy        _SlopeSetting_Destroy        = nullptr;
			UGSlopeSetting_SetDisplayMode _SlopeSetting_SetDisplayMode = nullptr;
			UGSlopeSetting_GetDisplayMode _SlopeSetting_GetDisplayMode = nullptr;
			UGSlopeSetting_SetMinVisibleValue _SlopeSetting_SetMinVisibleValue = nullptr;
			UGSlopeSetting_GetMinVisibleValue _SlopeSetting_GetMinVisibleValue = nullptr;
			UGSlopeSetting_SetMaxVisibleValue _SlopeSetting_SetMaxVisibleValue = nullptr;
			UGSlopeSetting_GetMaxVisibleValue _SlopeSetting_GetMaxVisibleValue = nullptr;

			UGCREATEJSON		   _CreateJson = nullptr;
			UGREMOVEALL			   _RemoveAll = nullptr;
			UGCREATEJSONWITHTYPE   _CreateJsonWithType = nullptr;
			UGJSON_GETARRARYSIZE   _Json_GetArrarySize = nullptr;
			UGJSON_GETAT		   _Json_GetAt = nullptr;
			UGJSON_GETATSTRING	   _Json_GetAtString = nullptr;
			UGJSONADDSTRING		   _JsonAddString = nullptr;
			UGJSONADDDOUBLE		   _JsonAddDouble = nullptr;
			UGJSONADDINT		   _JsonAddInt = nullptr;
			UGJSONADDFLOAT		   _JsonAddFloat = nullptr;
			UGJSONARRAYADDJSON	   _JsonArrayAddJson = nullptr;
			UGJSONADDJSON		   _JsonAddJson = nullptr;
			UGJSONADDBOOL		   _JsonAddBool = nullptr;
			UGJSONGETVALUEBOOL	   _JsonGetValueBool = nullptr;
			UGJSONGETVALUEINT	   _JsonGetValueInt = nullptr;
			UGJSONGETVALUEFLOAT	   _JsonGetValueFloat = nullptr;
			UGJSONGETVALUEDOUBLE   _JsonGetValueDouble = nullptr;
			UGJSONGETVALUESTRING   _JsonGetValueString = nullptr;
			UGJSONGETVALUEJSON	   _JsonGetValueJson = nullptr;
			UGCONTAINS			   _Contains = nullptr;
			UGSAVETOSTDFILE		   _SaveToStdFile = nullptr;
			UGJSON_SAVETOSTRING	   _Json_SaveToString = nullptr;
			UGLOADFROMSTDFILE	   _LoadFromStdFile = nullptr;
			UGLOADFROMSTRING	   _LoadFromString = nullptr;
			UGJSONGETALLKEYS	   _JsonGetAllKeys = nullptr;

			UGQUERY3DCREATE				_Query3D_Create = nullptr;
			UGQUERY3DREALSESPATIALQUERY	_Query3D_RealseSpatialQuery = nullptr;
			UGQUERY3DSETGEOMETRY		_Query3D_SetGeometry = nullptr;
			UGQUERY3DSETPICKRECT        _Query3D_SetPickRect = nullptr;
			UGQUERY3DSETPOSITIONMODE    _Query3D_SetPositionMode = nullptr;
			UGQUERY3DGETPOSITIONMODE    _Query3D_GetPositionMode = nullptr;
			UGQUERY3DADDLAYERID         _Query3D_AddLayerID = nullptr;
			UGQUERY3DREMOVELAYERID	    _Query3D_RemoveLayerID = nullptr;
			UGQUERY3DUPDATERECTSELECT   _Query3D_UpdateRectSelect = nullptr;
			UGQUERY3DGETSPATIALQUERYIDS _Query3D_GetSpatialQueryIDs = nullptr;
			UGQUERY3DGETQUERYIDS		_Query3D_GetQueryIDs = nullptr;

			UGOUTPUTSTREETFACADE _OutputStreetFacade = nullptr;

			UGFLYMANAGER_CREATE					_FlyManager_Create = nullptr;
			UGFLYMANAGER_DESTROY				_FlyManager_Destroy = nullptr;
			UGFLYMANAGER_PLAY					_FlyManager_Play = nullptr;
			UGFLYMANAGER_STOP					_FlyManager_Stop = nullptr;
			UGFLYMANAGER_PAUSE					_FlyManager_Pause = nullptr;
			UGFLYMANAGER_GETSTATUS				_FlyManager_GetStatus = nullptr;
			UGFLYMANAGER_UPDATE					_FlyManager_Update = nullptr;
			UGFLYMANAGER_GETROUTES				_FlyManager_GetRoutes = nullptr;
			UGFLYMANAGER_CALCGLOBALPROGRESSTIME _FlyManager_CalcGlobalProgressTime = nullptr;
			UGFLYMANAGER_SETGLOBALPROGRESSTIME	_FlyManager_SetGlobalProgressTime = nullptr;
			UGFLYMANAGER_GETPLAYRATE			_FlyManager_GetPlayRate = nullptr;
			UGFLYMANAGER_SETPLAYRATE			_FlyManager_SetPlayRate = nullptr;
			UGFLYMANAGER_GETTURNINGMODE			_FlyManager_GetTurningMode = nullptr;
			UGFLYMANAGER_SETTURNINGMODE			_FlyManager_SetTurningMode = nullptr;
			UGFLYMANAGER_GETCURRENTSTOPINDEX	_FlyManager_GetCurrentStopIndex = nullptr;
			UGFLYMANAGER_SETCURRENTSTOPINDEX	_FlyManager_SetCurrentStopIndex = nullptr;
			UGFLYMANAGER_GETARRIVEDNEWSTOPINDEX	_FlyManager_GetArrivedNewStopIndex = nullptr;
			UGFLYMANAGER_SETORIGINALPOSITION	_FlyManager_SetOriginalPosition = nullptr;
			UGFLYMANAGER_GETCURRENTPROGRESS		_FlyManager_GetCurrentProgress = nullptr;

			UGROUTES_FROMFILE				_Routes_FromFile = nullptr;
			UGROUTES_GETCOUNT				_Routes_GetCount = nullptr;
			UGROUTES_GETITEM				_Routes_GetItem = nullptr;
			UGROUTES_INDEXOF				_Routes_IndexOf = nullptr;
			UGROUTES_SETCURRENTROUTEINDEX	_Routes_SetCurrentRouteIndex = nullptr;
			UGROUTES_GETCURRENTROUTEINDEX	_Routes_GetCurrentRouteIndex = nullptr;
			UGROUTES_TOFILE					_Routes_ToFile = nullptr;
			UGROUTES_REMOVE					_Routes_Remove = nullptr;
			UGROUTE_GETNAME					_Route_GetName = nullptr;
			UGROUTE_SETNAME					_Route_SetName = nullptr;
			UGROUTE_SETISFLYINGLOOP			_Route_SetIsFlyingLoop = nullptr;
			UGROUTE_GETISFLYINGLOOP			_Route_GetIsFlyingLoop = nullptr;
			UGROUTE_CREATE					_Route_Create = nullptr;
			UGROUTE_GETSTOPS				_Route_GetStops = nullptr;
			UGROUTE_SETHEADINGFIXED			_Route_SetHeadingFixed = nullptr;
			UGROUTE_ISHEADINGFIXED			_Route_IsHeadingFixed = nullptr;
			UGROUTE_SETTILTFIXED			_Route_SetTiltFixed = nullptr;
			UGROUTE_ISTILTFIXED				_Route_IsTiltFixed = nullptr;
			UGROUTESTOPS_GETSTOP			_RouteStops_GetStop = nullptr;
			UGROUTESTOPS_GETCOUNT			_RouteStops_GetCount = nullptr;
			UGROUTESTOPS_INSERTSTOP			_RouteStops_InsertStop = nullptr;
			UGROUTESTOPS_REMOVE				_RouteStops_Remove = nullptr;
			UGROUTESTOP_CREATE				_RouteStop_Create = nullptr;
			UGROUTESTOP_DESTORY				_RouteStop_Destory = nullptr;
			UGROUTESTOP_GETNAME				_RouteStop_GetName = nullptr;
			UGROUTESTOP_SETNAME				_RouteStop_SetName = nullptr;
			UGROUTESTOP_SETCAMERA			_RouteStop_SetCamera = nullptr;
			UGROUTESTOP_GETCAMERASTATE		_RouteStop_GetCameraState = nullptr;
			UGROUTESTOP_GETDURATION			_RouteStop_GetDuration = nullptr;
			UGROUTESTOP_SETDURATION			_RouteStop_SetDuration = nullptr;

			UGSELECTION3DCREATEBYLAYER3D     _Selection3D_CreateByLayer = nullptr;
			UGSELECTION3DDESTROY    _Selection3D_Destroy = nullptr;
			UGSELECTION3DGETSTYLE3D _Selection3D_GetStyle3D = nullptr;
			UGSELECTION3DGETCOUNT	_Selection3D_GetCount = nullptr;
			UGSELECTION3DADD		_Selection3D_Add = nullptr;
			UGSELECTION3DREMOVEAT	_Selection3D_RemoveAt = nullptr;
			UGSELECTION3DCLEAR      _Selection3D_Clear = nullptr;
			UGSELECTION3DGETAT		_Selection3D_GetAt = nullptr;
			UGSELECTION3DFINDID     _Selection3D_FindID = nullptr;

			UGPRJCOORDSYS_CREATE	_PrjCoordSys_Create		= nullptr;
			UGPRJCOORDSYS_GETNAME	_PrjCoordSys_GetName	= nullptr;
			UGPRJCOORDSYS_FROMEPSGCODE	_PrjCoordSys_FromEPSGCode	= nullptr;
			UGPRJCOORDSYS_FROMFILE	_PrjCoordSys_FromFile	= nullptr;
			UGPRJCOORDSYS_DISPOSE	_PrjCoordSys_Dispose	= nullptr;
			UGPRJCOORDSYS_INVERSE	_PrjCoordSys_Inverse	= nullptr;
			UGPRJCOORDSYS_FORWARD	_PrjCoordSys_Forward	= nullptr;
			
			UGSTYLE3D_SETSIDETEXTURE	_Style3D_SetSideTexture = nullptr;
			UGSTYLE3D_SETTILINGU		_Style3D_SetTilingU = nullptr;
			UGSTYLE3D_SETTILINGV		_Style3D_SetTilingV = nullptr;
			UGSTYLE3D_SETTOPTEXTURE		_Style3D_SetTopTexture = nullptr;
			UGSTYLE3D_SETTOPTILINGU		_Style3D_SetTopTilingU = nullptr;
			UGSTYLE3D_SETTOPTILINGV		_Style3D_SetTopTilingV = nullptr;
			UGSTYLE3D_CREATE            _Style3D_Create = nullptr;
			UGSTYLE3D_DESTROY           _Style3D_Destroy = nullptr;
			UGSTYLE3D_SETALTITUDEMODE   _Style3D_SetAltitudeMode = nullptr;
			UGSTYLE3D_GETALTITUDEMODE   _Style3D_GetAltitudeMode = nullptr;
			UGSTYLE3D_SETBOTTOMALTITUDE _Style3D_SetBottomAltitude = nullptr;
			UGSTYLE3D_GETBOTTOMALTITUDE _Style3D_GetBottomAltitude = nullptr;
			UGSTYLE3D_SETEXTENDHEIGHT   _Style3D_SetExtendHeight = nullptr;
			UGSTYLE3D_GETEXTENDHEIGHT   _Style3D_GetExtendHeight = nullptr;
			UGSTYLE3D_SETFILLCOLOR      _Style3D_SetFillColor = nullptr;
			UGSTYLE3D_GETFILLCOLOR      _Style3D_GetFillColor = nullptr;
			UGSTYLE3D_SETFILL3DMODE     _Style3D_SetFill3DMode = nullptr;
			UGSTYLE3D_GETFILL3DMODE     _Style3D_GetFill3DMode = nullptr;
			UGSTYLE3D_SETLINECOLOR3D    _Style3D_SetLineColor3D = nullptr;
			UGSTYLE3D_GETLINECOLOR3D    _Style3D_GetLineColor3D = nullptr;
			UGSTYLE3D_SETLINEWIDTH      _Style3D_SetLineWidth = nullptr;
			UGSTYLE3D_GETLINEWIDTH      _Style3D_GetLineWidth = nullptr;
			UGSTYLE3D_SETMARKER3DSCALE			_Style3D_SetMarker3DScale = nullptr;
			UGSTYLE3D_GETMARKER3DSCALE			_Style3D_GetMarker3DScale = nullptr;
			UGSTYLE3D_SETMARKER3DROTATE			_Style3D_SetMarker3DRotate = nullptr;
			UGSTYLE3D_GETMARKER3DROTATE			_Style3D_GetMarker3DRotate = nullptr;
			UGSTYLE3D_SETMARKER3DTRANSLATION	_Style3D_SetMarker3DTranslation = nullptr;
			UGSTYLE3D_GETMARKER3DTRANSLATION	_Style3D_GetMarker3DTranslation = nullptr;
			
			UGVIEWDOME_CREATE							_ViewDome_Create = nullptr;
			UGVIEWDOME_DESTROY							_ViewDome_Destroy = nullptr;
			UGVIEWDOME_GETCOLOR							_ViewDome_GetColor = nullptr;
			UGVIEWDOME_SETCOLOR							_ViewDome_SetColor = nullptr;
			UGVIEWDOME_GETLINECOLOR						_ViewDome_GetLineColor = nullptr;
			UGVIEWDOME_SETLINECOLOR						_ViewDome_SetLineColor = nullptr;
			UGVIEWDOME_GETVIEWERPOSITION				_ViewDome_GetViewerPosition = nullptr;
			UGVIEWDOME_SETVIEWERPOSITION				_ViewDome_SetViewerPosition = nullptr;
			UGVIEWDOME_GETDISTANCE						_ViewDome_GetDistance = nullptr;
			UGVIEWDOME_SETDISTANCE						_ViewDome_SetDistance = nullptr;
			UGVIEWDOME_GETDOMETYPE						_ViewDome_GetDomeType = nullptr;
			UGVIEWDOME_SETDOMETYPE						_ViewDome_SetDomeType = nullptr;
			UGVIEWDOME_GETDISPLAYSTYLE					_ViewDome_GetDisplayStyle = nullptr;
			UGVIEWDOME_SETDISPLAYSTYLE					_ViewDome_SetDisplayStyle = nullptr;
			UGVIEWDOME_GETRATIO							_ViewDome_GetRatio = nullptr;
			UGVIEWDOME_GETDEPTHRENDERTEXTUREPTRHANDLE	_ViewDome_GetDepthRenderTexturePtrHandle = nullptr;
			UGVIEWDOME_GETCAMERA						_ViewDome_GetCamera = nullptr;
			UGVIEWDOME_BUILD							_ViewDome_Build = nullptr;

			UGCUTFILL									_CutFill = nullptr;

			UGPROFILE_CREATE						_Profile_Create = nullptr;
			UGPROFILE_DESTROY						_Profile_Destroy = nullptr;
			UGPROFILE_SETEXTENDHEIGHT				_Profile_SetExtendHeight = nullptr;
			UGPROFILE_GETEXTENDHEIGHT				_Profile_GetExtendHeight = nullptr;
			UGPROFILE_SETSTARTPOINT3D				_Profile_SetStartPoint3D = nullptr;
			UGPROFILE_GETSTARTPOINT3D				_Profile_GetStartPoint3D = nullptr;
			UGPROFILE_SETENDPOINT3D					_Profile_SetEndPoint3D = nullptr;
			UGPROFILE_GETENDPOINT3D					_Profile_GetEndPoint3D = nullptr;
			UGPROFILE_GETLEFTTOPPOSITION			_Profile_GetLeftTopPosition = nullptr;
			UGPROFILE_GETRIGHTBOTTOMPOSITION		_Profile_GetRightBottomPosition = nullptr;
			UGPROFILE_OUTPUTPROFILETOIMAGEDATA		_Profile_OutputProfileToImageData = nullptr;
			UGPROFILE_BUILD							_Profile_Build = nullptr;

			UGUDB_SAVEMATERIALTOJSON					_SaveMaterialToJson = nullptr;

			UGGLOBALIMAGE_ADDEXCAVATIONREGION     _GlobalImage_AddExcavationRegion = nullptr;
			UGGLOBALIMAGE_CLEAREXCAVATIONREGIONS   _GlobalImage_ClearExcavationRegions = nullptr;
			UGGLOBALIMAGE_GETEXCAVATIONREGION     _GlobalImage_GetExcavationRegion = nullptr;
			UGGLOBALIMAGE_GETEXCAVATIONREGIONTAG  _GlobalImage_GetExcavationRegionTag = nullptr;
			UGGLOBALIMAGE_INDEXOFEXCAVATIONREGION _GlobalImage_IndexOfExcavationRegion = nullptr;
			UGGLOBALIMAGE_REMOVEEXCAVATIONREGION  _GlobalImage_RemoveExcavationRegion = nullptr;
			UGGLOBALIMAGE_SETEXCAVATIONREGION     _GlobalImage_SetExcavationRegionTag = nullptr;
			UGGLOBALIMAGE_SETVISIBLE			_GlobalImage_SetVisible = nullptr;
			UGGLOBALIMAGE_GETVISIBLE			_GlobalImage_GetVisible = nullptr;

			TArray<TPair<FString, void**> > arrCloudLicenseAPIs =
			{
				TPair<FString, void**>("Login", (void**)(&_Login)),
				TPair<FString, void**>("GetLicenseNum", (void**)(&_GetLicenseNum)),
				TPair<FString, void**>("GetLicenseID", (void**)(&_GetLicenseID)),
				TPair<FString, void**>("GetLicenseRemainDays", (void**)(&_GetLicenseRemainDays)),
				TPair<FString, void**>("GetLicenseVersion", (void**)(&_GetLicenseVersion)),
				TPair<FString, void**>("GetLicenseUserId", (void**)(&_GetLicenseUserId)),
				TPair<FString, void**>("Logout", (void**)(&_Logout)),
				TPair<FString, void**>("Connect", (void**)(&_Connect)),
				TPair<FString, void**>("ConnectTrial", (void**)(&_ConnectTrial)),
			};

			TArray<TPair<FString, void**> > arrAPIs =
			{
				/*Camera*/
				TPair<FString, void**>("Camera_Create", (void**)(&_CameraCreate)),
				TPair<FString, void**>("Camera_Destory", (void**)(&_CameraDestory)),
				TPair<FString, void**>("Camera_GetHeading", (void**)(&_CameraGetHeading)),
				TPair<FString, void**>("Camera_GetTilt", (void**)(&_CameraGetTilt)),
				TPair<FString, void**>("Camera_GetRoll", (void**)(&_CameraGetRoll)),
				TPair<FString, void**>("Camera_GetLongitude", (void**)(&_Camera_GetLongitude)),
				TPair<FString, void**>("Camera_GetLatitude", (void**)(&_Camera_GetLatitude)),
				TPair<FString, void**>("Camera_GetAltitude", (void**)(&_Camera_GetAltitude)),
				TPair<FString, void**>("Camera_SetViewMatrixDouble", (void**)(&_CameraSetViewMatrix)),
				TPair<FString, void**>("GetViewProjectMatrix", (void**)(&_CameraGetViewProjectMatrix)),
				TPair<FString, void**>("Camera_GetPosition", (void**)(&_CameraGetPosition)),
				TPair<FString, void**>("Camera_GetRotation", (void**)(&_CameraGetRotation)),
				TPair<FString, void**>("Camera_GetDirection", (void**)(&_CameraGetDirection)),
				TPair<FString, void**>("Camera_GetUp", (void**)(&_CameraGetUp)),
				TPair<FString, void**>("Camera_GetRight", (void**)(&_CameraGetRight)),
				TPair<FString, void**>("Camera_GetProjectParamter", (void**)(&_CameraGetProjectParamter)),
				TPair<FString, void**>("Camera_SetUGCState", (void**)(&_CameraSetUGCState)),

				/*Layer3D*/
				TPair<FString, void**>("Layer3D_IsMarkerLayer", (void**)(&_Layer3D_IsMarkerLayer)),
				TPair<FString, void**>("Layer3D_SetMarkerLayer", (void**)(&_Layer3D_SetMarkerLayer)),
				TPair<FString, void**>("SetVisible", (void**)(&_SetVisible)),
				TPair<FString, void**>("GetVisible", (void**)(&_GetVisible)),
				TPair<FString, void**>("HasCompressOptions", (void**)(&_HasCompressOptions)),
				TPair<FString, void**>("GetNodeName", (void**)(&_GetNodeName)),
				TPair<FString, void**>("Layer3D_GetNodeNameHashCode", (void**)(&_GetLayerNodeNameHashCode)),
				TPair<FString, void**>("SetOriginalPosition", (void**)(&_SetOriginalPosition)),
				TPair<FString, void**>("GetCentrePosition", (void**)(&_GetCentrePosition)),
				TPair<FString, void**>("GetLayerBounds", (void**)(&_GetLayerBounds)),
				TPair<FString, void**>("SetInitialized_UNREAL", (void**)(&_SetInitialized)),
				
				TPair<FString, void**>("Layer3D_SetCustomClipPlane", (void**)(&_SetCustomClipPlane)),
				TPair<FString, void**>("Layer3D_SetCustomClipBox", (void**)(&_SetCustomClipBox)),
				TPair<FString, void**>("Layer3D_GetCustomClipBox", (void**)(&_GetCustomClipBox)),
				TPair<FString, void**>("Layer3D_GetClipPlaneParameter", (void**)(&_GetClipPlaneParameter)),
				TPair<FString, void**>("Layer3D_IsClip", (void**)(&_IsClip)),
				TPair<FString, void**>("Layer3D_SetClipLineColor", (void**)(&_SetClipLineColor)),
				TPair<FString, void**>("Layer3D_GetClipLineColor", (void**)(&_GetClipLineColor)),
				TPair<FString, void**>("Layer3D_GetPlaneClipMode", (void**)(&_GetPlaneClipMode)),
				TPair<FString, void**>("Layer3D_ClearCustomClipPlane", (void**)(&_ClearCustomClipPlane)),
				TPair<FString, void**>("Layer3D_SetSwipeEnabled", (void**)(&_SetSwipeEnabled)),
				TPair<FString, void**>("Layer3D_GetSwipeEnabled", (void**)(&_GetSwipeEnabled)),
				TPair<FString, void**>("Layer3D_SetSwipeRegion", (void**)(&_SetSwipeRegion)),
				TPair<FString, void**>("Layer3D_GetSwipeRegion", (void**)(&_GetSwipeRegion)),
				TPair<FString, void**>("Layer3D_AddSelectedID", (void**)(&_Layer3D_AddSelectedID)),
				TPair<FString, void**>("Layer3D_RemoveAllSelectedID", (void**)(&_Layer3D_RemoveAllSelectedID)),
				TPair<FString, void**>("Layer3D_SetOpaqueRate", (void**)(&_Layer3D_SetOpaqueRate)),
				TPair<FString, void**>("Layer3D_GetOpaqueRate", (void**)(&_Layer3D_GetOpaqueRate)),
				TPair<FString, void**>("Layer3D_GetOSGBType", (void**)(&_Layer3D_GetOSGBType)),
				TPair<FString, void**>("Layer3D_SetSelectStyle", (void**)(&_Layer3D_SetSelectStyle)),
				TPair<FString, void**>("Layer3D_GetSelectStyle", (void**)(&_Layer3D_GetSelectStyle)),
				TPair<FString, void**>("Layer3D_GetID", (void**)(&_Layer3D_GetID)),
				TPair<FString, void**>("Layer3D_GetType", (void**)(&_Layer3D_GetType)),
				TPair<FString, void**>("Layer3D_GetName", (void**)(&_Layer3D_GetName)),
				TPair<FString, void**>("Layer3D_SetStyle", (void**)(&_Layer3D_SetStyle)),
				TPair<FString, void**>("Layer3D_GetStyle", (void**)(&_Layer3D_GetStyle)),
				TPair<FString, void**>("Layer3D_SetMaxObjectVisibleDistance", (void**)(&_SetMaxObjectVisibleDistance)),
				TPair<FString, void**>("Layer3D_SetMinObjectVisibleDistance", (void**)(&_SetMinObjectVisibleDistance)),
				TPair<FString, void**>("Layer3D_GetMaxMinObjectVisibleDistance", (void**)(&_GetMaxMinObjectVisibleDistance)),
				TPair<FString, void**>("Layer3D_GetDataPath", (void**)(&_Layer3D_GetDataPath)),
				TPair<FString, void**>("Layer3D_RemoveGPUSharedParameters", (void**)(&_Layer3D_RemoveGPUSharedParameters)),

				/*Layer3DS3MFile*/
				TPair<FString, void**>("S3MLayer_GetFieldInfosObject", (void**)(&_GetFieldInfosObject)),
				TPair<FString, void**>("S3MLayer_FreeArrayObjectFieldNode", (void**)(&_FreeArrayObjectFieldNode)),
				TPair<FString, void**>("S3MLayer_GetAllFieldValueObject", (void**)(&_GetAllFieldValueObject)),
				TPair<FString, void**>("S3MLayer_GetFieldInfos", (void**)(&_GetFieldInfos)),
				TPair<FString, void**>("S3MLayer_SetLODRangeScale", (void**)(&_SetLODRangeScale)),
				TPair<FString, void**>("S3MLayer_GetLODRangeScale", (void**)(&_GetLODRangeScale)),
				TPair<FString, void**>("S3MLayer_GetSceneNodeName", (void**)(&_GetSceneNodeName)),
				TPair<FString, void**>("S3MLayer_CalFlattenParam", (void**)(&_CalFlattenParam)),
				TPair<FString, void**>("S3MLayer_AddFlattenRegion", (void**)(&_AddFlattenRegion)),
				TPair<FString, void**>("S3MLayer_ReleaseAllFlattenRegions", (void**)(&_ReleaseAllFlattenRegions)),
				TPair<FString, void**>("S3MLayer_DeleteAtFlattenRegion", (void**)(&_DeleteAtFlattenRegion)),
				TPair<FString, void**>("S3MLayer_IndexOfFlattenRegion", (void**)(&_IndexOfFlattenRegion)),
				TPair<FString, void**>("S3MLayer_GetFlattenRegion", (void**)(&_GetFlattenRegion)),
				TPair<FString, void**>("S3MLayer_GetFlattenRegionCount", (void**)(&_GetFlattenRegionCount)),
				TPair<FString, void**>("S3MLayer_GetFlattenRegionTag", (void**)(&_GetFlattenRegionTag)),
				TPair<FString, void**>("S3MLayer_SetFlattenRegionTag", (void**)(&_SetFlattenRegionTag)),
				TPair<FString, void**>("S3MLayer_GetFlattenShaderParamterForUnreal", (void**)(&_GetFlattenShaderParamter)),
				TPair<FString, void**>("S3MLayer_GetMinDataValue", (void**)(&_GetMinDataValue)),
				TPair<FString, void**>("S3MLayer_GetMaxDataValue", (void**)(&_GetMaxDataValue)),
				TPair<FString, void**>("S3MLayer_SetObjectsVisible", (void**)(&_SetObjectsVisible)),
				TPair<FString, void**>("S3MLayer_SetObjectsColor", (void**)(&_SetObjectsColor)),
				TPair<FString, void**>("S3MLayer_GetObjectsColor", (void**)(&_GetObjectsColor)),
				TPair<FString, void**>("S3MLayer_RemoveObjectsColor", (void**)(&_RemoveObjectsColor)),
				TPair<FString, void**>("S3MLayer_ResetObjectsColor", (void**)(&_ResetObjectsColor)),
				TPair<FString, void**>("S3MLayer_SetObjectsMaterial", (void**)(&_SetObjectsMaterial)),
				TPair<FString, void**>("S3MLayer_SetModifyRegions", (void**)(&_SetModifyRegions)),
				TPair<FString, void**>("S3MLayer_ClearModifyRegions", (void**)(&_ClearModifyRegions)),
				TPair<FString, void**>("S3MLayer_SetExcavation", (void**)(&_SetExcavation)),
				TPair<FString, void**>("S3MLayer_GetExcavationShaderParamter", (void**)(&_GetExcavationShaderParamter)),
				TPair<FString, void**>("S3MLayer_AddMaterialAssociateWithScp", (void**)(&_AddMaterialAssociateWithScp)),
				TPair<FString, void**>("S3MLayer_SetDecodeMeshopt", (void**)(&_SetDecodeMeshopt)),
				TPair<FString, void**>("S3MLayer_GetDecodeMeshopt", (void**)(&_GetDecodeMeshopt)),
				TPair<FString, void**>("S3MLayer_SetLoadingPriority", (void**)(&_SetLoadingPriority)),
				TPair<FString, void**>("S3MLayer_GetLoadingPriority", (void**)(&_GetLoadingPriority)),
				TPair<FString, void**>("S3MLayer_GetDataMaxValue", (void**)(&_S3MLayer_GetDataMaxValue)),
				TPair<FString, void**>("S3MLayer_GetDataMinValue", (void**)(&_S3MLayer_GetDataMinValue)),
				TPair<FString, void**>("S3MLayer_SetCoverImageryLayer", (void**)(&_S3MLayer_SetCoverImageryLayer)),
					
				/*Layer3Ds*/
				TPair<FString, void**>("AddLayer", (void**)(&_AddLayer)),
				TPair<FString, void**>("Add", (void**)(&_Add)),
				TPair<FString, void**>("AddDatasetLayer", (void**)(&_AddDatasetLayer)),
				TPair<FString, void**>("GetLayerNodeName", (void**)(&_GetLayerNodeName)),
				TPair<FString, void**>("GetIsVisible", (void**)(&_GetIsVisible)),
				TPair<FString, void**>("SetIsVisible", (void**)(&_SetIsVisible)),
				TPair<FString, void**>("AddOnlineMap", (void**)(&_AddOnlineMap)),
				TPair<FString, void**>("AddArcgisMap", (void**)(&_AddArcgisMap)),
				TPair<FString, void**>("RemoveLayers", (void**)(&_RemoveLayers)),
				TPair<FString, void**>("AddTianditu", (void**)(&_AddTianditu)),
				TPair<FString, void**>("AddOSGBLayer", (void**)(&_AddOSGBLayer)),
				TPair<FString, void**>("AddDatasetModel", (void**)(&_AddDatasetModel)),

				/*ROCacheManager*/
				TPair<FString, void**>("GetAllUpdate", (void**)(&_GetAllUpdata)),
				TPair<FString, void**>("FreeArrayROEmptyNode", (void**)(&_FreeArrayROEmptyNode)),
				TPair<FString, void**>("FreeArrayRONode", (void**)(&_FreeArrayRONode)),
				TPair<FString, void**>("FreeArrayROMaterial", (void**)(&_FreeArrayROMaterial)),
				TPair<FString, void**>("FreeArrayROTexture", (void**)(&_FreeArrayROTexture)),
				TPair<FString, void**>("FreeArrayHashCode", (void**)(&_FreeArrayHashCode)),
				TPair<FString, void**>("DecomposeViewMatrix", (void**)(&_DecomposeViewMatrix)),
				TPair<FString, void**>("DecomposeViewMatrix2", (void**)(&_DecomposeViewMatrix2)),
				TPair<FString, void**>("FreeByte", (void**)(&_FreeByte)),
				TPair<FString, void**>("FreeUChar", (void**)(&_FreeUChar)),
				TPair<FString, void**>("InitRenderTextureCallbackHandleForUnreal", (void**)(&_InitRenderTextureCallbackHandle)),
				TPair<FString, void**>("InitCameraCallbackHandleForUnreal", (void**)(&_InitCameraCallbackHandle)),
				TPair<FString, void**>("InitDataBufferCallbackHandle", (void**)(&_InitDataBufferCallbackHandle)),
				TPair<FString, void**>("InitSceneNodeCallbackHandleForUnreal", (void**)(&_InitSceneNodeCallbackHandle)),
				TPair<FString, void**>("InitEntityCallbackHandleForUnreal", (void**)(&_InitEntityCallbackHandle)),
				TPair<FString, void**>("InitTextureCallbackHandleForUnreal", (void**)(&_InitTextureCallbackHandle)),
				TPair<FString, void**>("InitMaterialManagerCallbackHandleForUnreal", (void**)(&_InitMaterialManagerCallbackHandle)),
				TPair<FString, void**>("InitMaterialManagerShareCallbackHandleForUnreal", (void**)(&_InitMaterialManagerShareCallbackHandle)),
				TPair<FString, void**>("InitInstanceMeshCallbackHandleForUnreal", (void**)(&_InitInstanceMeshCallbackHandle)),
				TPair<FString, void**>("InitMainCameraCallbackHandle", (void**)(&_InitMainCameraCallbackHandle)),
				TPair<FString, void**>("InitGraphicsCallbackHandle", (void**)(&_InitGraphicsCallbackHandle)),

				/*Scene*/
				TPair<FString, void**>("SetCamera", (void**)(&_SetCamera)),
				TPair<FString, void**>("Scene_GetCamera", (void**)(&_Scene_GetCamera)),
				TPair<FString, void**>("Scene_GetCreateSkirt", (void**)(&_GetCreateSkirt)),
				TPair<FString, void**>("Scene_SetCreateSkirt", (void**)(&_SetCreateSkirt)),
				TPair<FString, void**>("Scene_SetSkirtHeight", (void**)(&_SetSkirtHeight)),
				TPair<FString, void**>("LongitudeLatitudeToGameEngine", (void**)(&_LongitudeLatitudeToGameEngine)),
				TPair<FString, void**>("ToXML", (void**)(&_ToXML)),
				TPair<FString, void**>("Scene_SetShowInvalidation", (void**)(&_Scene_SetShowInvalidation)),
				TPair<FString, void**>("Scene_FlyToCamera", (void**)(&_Scene_FlyToCamera)),
				TPair<FString, void**>("Scene_SetTerrainExaggeration", (void**)(&_Scene_SetTerrainExaggeration)),
				TPair<FString, void**>("Scene_GetTerrainExaggeration", (void**)(&_Scene_GetTerrainExaggeration)),
				TPair<FString, void**>("Scene_SetEndFlyFunc", (void**)(&_Scene_SetEndFlyFunc)),
				TPair<FString, void**>("Scene_SetStereoMode", (void**)(&_Scene_SetStereoMode)),
				TPair<FString, void**>("Scene_GetStereoMode", (void**)(&_Scene_GetStereoMode)),
				TPair<FString, void**>("Scene_GetTileBounds", (void**)(&_Scene_GetTileBounds)),
				TPair<FString, void**>("Scene_RefreshRaster", (void**)(&_Scene_RefreshRaster)),
				TPair<FString, void**>("Scene_FromXMLForPath", (void**)(&_Scene_FromXML)),
				TPair<FString, void**>("Scene_GetLayer3Ds", (void**)(&_Scene_GetLayer3Ds)),
				TPair<FString, void**>("Scene_GetTerrainLayers", (void**)(&_Scene_GetTerrainLayers)),
				TPair<FString, void**>("Scene_Updata", (void**)(&_Scene_Updata)),
				TPair<FString, void**>("Scene_GetGlobalImage", (void**)(&_Scene_GetGlobalImage)),
				TPair<FString, void**>("Scene_GlobalRefreshRaster", (void**)(&_Scene_GlobalRefreshRaster)),
				/*SceneControl*/
				TPair<FString, void**>("InitialScene", (void**)(&_InitialScene)),
				TPair<FString, void**>("DestroyScene", (void**)(&_DestroyScene)),
				TPair<FString, void**>("Kill", (void**)(&_Kill)),
				TPair<FString, void**>("SetPosition", (void**)(&_SetPosition)),
				TPair<FString, void**>("Render", (void**)(&_Render)),
				TPair<FString, void**>("SceneControl_GetWorkspace", (void**)(&_SceneControl_GetWorkspace)),
				TPair<FString, void**>("SceneControl_OnSize", (void**)(&_SceneControl_OnSize)),
				TPair<FString, void**>("SceneControl_SetMultiTexture", (void**)(&_SceneControl_SetMultiTexture)),

				/*Workspace*/
				TPair<FString, void**>("Workspace_GetDataSources", (void**)(&_Workspace_GetDataSources)),

				/*DataSources*/
				TPair<FString, void**>("DataSources_GetAt", (void**)(&_DataSources_GetAt)),
				TPair<FString, void**>("DataSources_SetAt", (void**)(&_DataSources_SetAt)),
				TPair<FString, void**>("DataSources_ReleaseAt", (void**)(&_DataSources_ReleaseAt)),
				TPair<FString, void**>("DataSources_GetAtByAlias", (void**)(&_DataSources_GetAtByAlias)),

				/*TerrainLayer*/
				TPair<FString, void**>("GetTerrainBounds", (void**)(&_GetTerrainBounds)),
				TPair<FString, void**>("SetTerrainVisible", (void**)(&_SetTerrainVisible)),
				TPair<FString, void**>("GetTerrainVisible", (void**)(&_GetTerrainVisible)),
				TPair<FString, void**>("GetMinHeight", (void**)(&_GetMinHeight)),
				TPair<FString, void**>("GetMaxHeight", (void**)(&_GetMaxHeight)),
				TPair<FString, void**>("GetShowInvalidation", (void**)(&_GetShowInvalidation)),
				TPair<FString, void**>("SetShowInvalidation", (void**)(&_SetShowInvalidation)),
				TPair<FString, void**>("SetTerrainLODRangeScale", (void**)(&_SetTerrainLODRangeScale)),
				TPair<FString, void**>("GetTerrainLODRangeScale", (void**)(&_GetTerrainLODRangeScale)),
				TPair<FString, void**>("GetTerrainTopLevel", (void**)(&_TerrainLayer_GetTopLevel)),
				TPair<FString, void**>("SetSlopeSetting", (void**)(&_TerrainLayer_SetSlopeSetting)),
				TPair<FString, void**>("TerrainLayer_GetName", (void**)(&_TerrainLayer_GetName)),
				TPair<FString, void**>("TerrainLayer_GetHeight", (void**)(&_TerrainLayer_GetHeight)),

				/*TerrainLayers*/
				TPair<FString, void**>("HasTIN", (void**)(&_HasTIN)),
				TPair<FString, void**>("AddTerrainLayer", (void**)(&_AddTerrainLayer)),
				TPair<FString, void**>("AddWebTerrain", (void**)(&_AddWebTerrain)),
				TPair<FString, void**>("RemoveTerrainLayers", (void**)(&_RemoveTerrainLayers)),
				TPair<FString, void**>("AddSTK", (void**)(&_AddSTK)),
				TPair<FString, void**>("AddTiandituTerrain", (void**)(&_AddTiandituTerrain)),
				TPair<FString, void**>("GetModifyTerrainSetting", (void**)(&_GetModifyTerrainSetting)),
					
				/*CameraControl*/
				TPair<FString, void**>("RayIntersectionWithSphere", (void**)(&_RayIntersectionWithSphere)),
				TPair<FString, void**>("CalLocationAndRotation", (void**)(&_CalLocationAndRotation)),
				TPair<FString, void**>("CalPitchAndHeading", (void**)(&_CalPitchAndHeading)),
				TPair<FString, void**>("CalPitchAndHeadingWithWorldOffset", (void**)(&_CalPitchAndHeadingWithWorldOffset)),
				TPair<FString, void**>("RayIntersectionWithSphereAndRadius", (void**)(&_RayIntersectionWithSphereAndRadius)),
				TPair<FString, void**>("RayIntersectionWithEllipsoidAndRadius", (void**)(&_RayIntersectionWithEllipsoidAndRadius)),
					
				/*RealspaceView*/
				TPair<FString, void**>("RGBAID", (void**)(&_RGBAID)),
				TPair<FString, void**>("IDRGBA", (void**)(&_IDRGBA)),
				TPair<FString, void**>("RGBAObjectID", (void**)(&_RGBAObjectID)),

				/*MathEngine*/
				TPair<FString, void**>("Triangulate", (void**)(&_Triangulate)),
				TPair<FString, void**>("FreeUGInt", (void**)(&_FreeUGInt)),
				TPair<FString, void**>("FreeUGUint", (void**)(&_FreeUGUint)),
				TPair<FString, void**>("FreeUGUshort", (void**)(&_FreeUGUshort)),
				TPair<FString, void**>("FreeUGFloat", (void**)(&_FreeUGFloat)),
				TPair<FString, void**>("CalHeadingAndPitch", (void**)(&_CalHeadingAndPitch)),
				TPair<FString, void**>("CalHashCode", (void**)(&_CalHashCode)),
				TPair<FString, void**>("CalHashCodeByChar", (void**)(&_CalHashCodeByChar)),
				TPair<FString, void**>("FreeDoubleArray", (void**)(&_FreeDoubleArray)),
				TPair<FString, void**>("FreeLong", (void**)(&_FreeLong)),
				TPair<FString, void**>("FreeCharPointerArray", (void**)(&_FreeCharPointerArray)),
				TPair<FString, void**>("Chamfer", (void**)(&_Chamfer)),
				TPair<FString, void**>("FreeUGDouble", (void**)(&_FreeUGDouble)),
				TPair<FString, void**>("KDTree_Create", (void**)(&_KDTree_Create)),
				TPair<FString, void**>("KDTree_SearchKdTreeDis2", (void**)(&_KDTree_SearchKdTreeDis2)),
				TPair<FString, void**>("KDTree_Dispose", (void**)(&_KDTree_Dispose)),
				TPair<FString, void**>("CalMatrix", (void**)(&_CalMatrix)),

				/*Sightline*/
				TPair<FString, void**>("CreateSightline", (void**)(&_CreateSightline)),
				TPair<FString, void**>("DestroySightline", (void**)(&_DestroySightline)),
				TPair<FString, void**>("SightlineBuild", (void**)(&_SightlineBuild)),
				TPair<FString, void**>("SetSightlineVisibleColor", (void**)(&_SetSightlineVisibleColor)),
				TPair<FString, void**>("GetSightlineVisibleColor", (void**)(&_GetSightlineVisibleColor)),
				TPair<FString, void**>("SetSightlineHiddenColor", (void**)(&_SetSightlineHiddenColor)),
				TPair<FString, void**>("GetSightlineHiddenColor", (void**)(&_GetSightlineHiddenColor)),
				TPair<FString, void**>("SetSightlineViewerPosition", (void**)(&_SetSightlineViewerPosition)),
				TPair<FString, void**>("GetSightlineViewerPosition", (void**)(&_GetSightlineViewerPosition)),
				TPair<FString, void**>("GetSightlineTargetPoint", (void**)(&_GetSightlineTargetPoint)),
				TPair<FString, void**>("SetSightlineTargetPoint", (void**)(&_SetSightlineTargetPoint)),
				TPair<FString, void**>("SightlineAddTargetPoint", (void**)(&_AddSightlineTargetPoint)),
				TPair<FString, void**>("GetSightlineTargetPointCount", (void**)(&_GetSightlineTargetPointCount)),
				TPair<FString, void**>("SightlineRemoveTargetPoint", (void**)(&_RemoveSightlineTargetPoint)),
				TPair<FString, void**>("SightlineRemoveAllTargetPoints", (void**)(&_RemoveSightlineAllTargetPoint)),
				TPair<FString, void**>("GetAllSightlineResultForUE", (void**)(&_GetAllSightlineResultForUE)),
				TPair<FString, void**>("IsInsideView", (void**)(&_IsInsideView)),
				TPair<FString, void**>("GetBarrierPointAndReflectionPoint", (void**)(&_GetBarrierPointAndReflectionPoint)),

				/*Skyline*/
				TPair<FString, void**>("CreateSkyline", (void**)(&_CreateSkyline)),
				TPair<FString, void**>("DestorySkyline", (void**)(&_DestroySkyline)),
				TPair<FString, void**>("SetSkylineViewerPitch", (void**)(&_SetSkylineViewerPitch)),
				TPair<FString, void**>("GetSkylineViewerPitch", (void**)(&_GetSkylineViewerPitch)),
				TPair<FString, void**>("SetSkylineViewerDirection", (void**)(&_SetSkylineViewerDirection)),
				TPair<FString, void**>("GetSkylineViewerDirection", (void**)(&_GetSkylineViewerDirection)),
				TPair<FString, void**>("SetSkylineViewerPosition", (void**)(&_SetSkylineViewerPosition)),
				TPair<FString, void**>("GetSkylineViewerPosition", (void**)(&_GetSkylineViewerPosition)),
				TPair<FString, void**>("GetSkyline3DForGameEngine", (void**)(&_GetSkyline3DForGameEngine)),
				TPair<FString, void**>("SetSkylineRadius", (void**)(&_SetSkylineRadius)),
				TPair<FString, void**>("GetSkylineRadius", (void**)(&_GetSkylineRadius)),
				TPair<FString, void**>("GetSkyline3D", (void**)(&_GetSkyline)),
				TPair<FString, void**>("BuildSkyline", (void**)(&_BuildSkyline)),
				TPair<FString, void**>("GetSkyline2D", (void**)(&_GetSkyline2D)),
				TPair<FString, void**>("GetSkylineSectorBody", (void**)(&_GetSkylineSectorBody)),
				TPair<FString, void**>("Skyline_GetObjectIDs", (void**)(&_Skyline_GetObjectIDs)),

				/*ViewShed*/
				TPair<FString, void**>("CreateViewShed", (void**)(&_CreateViewShed)),
				TPair<FString, void**>("DestroyViewShed", (void**)(&_DestroyViewShed)),
				TPair<FString, void**>("BuildViewShed", (void**)(&_BuildViewShed)),
				TPair<FString, void**>("SetViewShedPitch", (void**)(&_SetViewShedPitch)),
				TPair<FString, void**>("GetViewShedPitch", (void**)(&_GetViewShedPitch)),
				TPair<FString, void**>("SetViewShedHeading", (void**)(&_SetViewShedHeading)),
				TPair<FString, void**>("GetViewShedHeading", (void**)(&_GetViewShedHeading)),
				TPair<FString, void**>("SetViewShedHorizontalFov", (void**)(&_SetViewShedHorizontalFov)),
				TPair<FString, void**>("GetViewShedHorizontalFov", (void**)(&_GetViewShedHorizontalFov)),
				TPair<FString, void**>("SetViewShedVerticalFov", (void**)(&_SetViewShedVerticalFov)),
				TPair<FString, void**>("GetViewShedVerticalFov", (void**)(&_GetViewShedVerticalFov)),
				TPair<FString, void**>("SetViewShedDistance", (void**)(&_SetViewShedDistance)),
				TPair<FString, void**>("GetViewShedDistance", (void**)(&_GetViewShedDistance)),
				TPair<FString, void**>("SetViewShedViewerPosition", (void**)(&_SetViewShedViewerPosition)),
				TPair<FString, void**>("GetViewShedViewerPosition", (void**)(&_GetViewShedViewerPosition)),
				TPair<FString, void**>("SetDistDirByPointByUGC", (void**)(&_SetDistDirByPoint)),
				TPair<FString, void**>("SetViewShedVisibleAreaColor", (void**)(&_SetViewShedVisibleAreaColor)),
				TPair<FString, void**>("GetViewShedVisibleAreaColor", (void**)(&_GetViewShedVisibleAreaColor)),
				TPair<FString, void**>("SetViewShedHiddenAreaColor", (void**)(&_SetViewShedHiddenAreaColor)),
				TPair<FString, void**>("GetViewShedHiddenAreaColor", (void**)(&_GetViewShedHiddenAreaColor)),
				TPair<FString, void**>("GetCameraForUE", (void**)(&_GetCamera)),
				TPair<FString, void**>("GetDepthRenderTexturePtrHandle", (void**)(&_GetDepthRenderTextureHandle)),
				TPair<FString, void**>("GetViewShedHiddenBody", (void**)(&_GetViewShedHiddenBody)),
				TPair<FString, void**>("GetViewShedVisibleBody", (void**)(&_GetViewShedVisibleBody)),
				TPair<FString, void**>("Viewshed_GetQuality", (void**)(&_Viewshed_GetQuality)),
				TPair<FString, void**>("Viewshed_SetQuality", (void**)(&_Viewshed_SetQuality)),
				TPair<FString, void**>("ViewShed_GetBarrierPoints", (void**)(&_ViewShed_GetBarrierPoints)),
				TPair<FString, void**>("ViewShed_GetName", (void**)(&_ViewShed_GetName)),
				TPair<FString, void**>("ViewShed_SetName", (void**)(&_ViewShed_SetName)),
				TPair<FString, void**>("ViewShed_RemoveFromAnalyst3DList", (void**)(&_ViewShed_RemoveFromAnalyst3DList)),

				/*MultiViewShed3D*/
				TPair<FString, void**>("MultiViewShed3D_Create", (void**)(&_MultiViewShed3D_Create)),
				TPair<FString, void**>("MultiViewShed3D_Destroy", (void**)(&_MultiViewShed3D_Destroy)),
				TPair<FString, void**>("MultiViewShed3D_AddViewShed", (void**)(&_MultiViewShed3D_AddViewShed)),
				TPair<FString, void**>("MultiViewShed3D_RemoveViewShed", (void**)(&_MultiViewShed3D_RemoveViewShed)),
				TPair<FString, void**>("MultiViewShed3D_Build", (void**)(&_MultiViewShed3D_Build)),

				/*ViewDome*/
				TPair<FString, void**>("ViewDome_Create", (void**)(&_ViewDome_Create)),
				TPair<FString, void**>("ViewDome_Destroy", (void**)(&_ViewDome_Destroy)),
				TPair<FString, void**>("ViewDome_GetColor", (void**)(&_ViewDome_GetColor)),
				TPair<FString, void**>("ViewDome_SetColor", (void**)(&_ViewDome_SetColor)),
				TPair<FString, void**>("ViewDome_GetLineColor", (void**)(&_ViewDome_GetLineColor)),
				TPair<FString, void**>("ViewDome_SetLineColor", (void**)(&_ViewDome_SetLineColor)),
				TPair<FString, void**>("ViewDome_GetViewerPosition", (void**)(&_ViewDome_GetViewerPosition)),
				TPair<FString, void**>("ViewDome_SetViewerPosition", (void**)(&_ViewDome_SetViewerPosition)),
				TPair<FString, void**>("ViewDome_GetDistance", (void**)(&_ViewDome_GetDistance)),
				TPair<FString, void**>("ViewDome_SetDistance", (void**)(&_ViewDome_SetDistance)),
				TPair<FString, void**>("ViewDome_GetDomeType", (void**)(&_ViewDome_GetDomeType)),
				TPair<FString, void**>("ViewDome_SetDomeType", (void**)(&_ViewDome_SetDomeType)),
				TPair<FString, void**>("ViewDome_GetDisplayStyle", (void**)(&_ViewDome_GetDisplayStyle)),
				TPair<FString, void**>("ViewDome_SetDisplayStyle", (void**)(&_ViewDome_SetDisplayStyle)),
				TPair<FString, void**>("ViewDome_GetRatio", (void**)(&_ViewDome_GetRatio)),
				TPair<FString, void**>("ViewDome_GetDepthRenderTexturePtrHandle", (void**)(&_ViewDome_GetDepthRenderTexturePtrHandle)),
				TPair<FString, void**>("ViewDome_GetCamera", (void**)(&_ViewDome_GetCamera)),
				TPair<FString, void**>("ViewDome_Build", (void**)(&_ViewDome_Build)),
				
				/*CalculationTerrain*/
				TPair<FString, void**>("CutFill", (void**)(&_CutFill)),
				
				/*Profile*/
				TPair<FString, void**>("Profile_Create", (void**)(&_Profile_Create)),
				TPair<FString, void**>("Profile_Destroy", (void**)(&_Profile_Destroy)),
				TPair<FString, void**>("Profile_SetExtendHeight", (void**)(&_Profile_SetExtendHeight)),
				TPair<FString, void**>("Profile_GetExtendHeight", (void**)(&_Profile_GetExtendHeight)),
				TPair<FString, void**>("Profile_SetStartPoint3D", (void**)(&_Profile_SetStartPoint3D)),
				TPair<FString, void**>("Profile_GetStartPoint3D", (void**)(&_Profile_GetStartPoint3D)),
				TPair<FString, void**>("Profile_SetEndPoint3D", (void**)(&_Profile_SetEndPoint3D)),
				TPair<FString, void**>("Profile_GetEndPoint3D", (void**)(&_Profile_GetEndPoint3D)),
				TPair<FString, void**>("Profile_GetLeftTopPosition", (void**)(&_Profile_GetLeftTopPosition)),
				TPair<FString, void**>("Profile_GetRightBottomPosition", (void**)(&_Profile_GetRightBottomPosition)),
				TPair<FString, void**>("Profile_OutputProfileToImageData", (void**)(&_Profile_OutputProfileToImageData)),
				TPair<FString, void**>("Profile_Build", (void**)(&_Profile_Build)),

				/*ProjectionImage*/
				TPair<FString, void**>("CreateProjectionImage", (void**)(&_CreateProjectionImage)),
				TPair<FString, void**>("DestroyProjectionImage", (void**)(&_DestroyProjectionImage)),
				TPair<FString, void**>("BuildProjectionImage", (void**)(&_BuildProjectionImage)),
				TPair<FString, void**>("SetProjectionImagePitch", (void**)(&_SetProjectionImagePitch)),
				TPair<FString, void**>("GetProjectionImagePitch", (void**)(&_GetProjectionImagePitch)),
				TPair<FString, void**>("SetProjectionImageHeading", (void**)(&_SetProjectionImageHeading)),
				TPair<FString, void**>("GetProjectionImageHeading", (void**)(&_GetProjectionImageHeading)),
				TPair<FString, void**>("SetProjectionImageViewerPosition", (void**)(&_SetProjectionImageViewPosition)),
				TPair<FString, void**>("GetProjectionImageViewerPosition", (void**)(&_GetProjectionImageViewPosition)),
				TPair<FString, void**>("ProjectionImage_GetDepthPtrHandle", (void**)(&_GetProjectionImageDepthHandle)),
				TPair<FString, void**>("ProjectionImage_GetCamera", (void**)(&_GetProjectionImageGetCamera)),
				TPair<FString, void**>("ProjectionImage_Render", (void**)(&_ProjectionImageRender)),
				TPair<FString, void**>("SetProjectionImageAffineMatrix", (void**)(&_SetProjectionImageAffineMatrix)),
				TPair<FString, void**>("GetProjectionImageAffineMatrix", (void**)(&_GetProjectionImageAffineMatrix)),
				TPair<FString, void**>("SetProjectionImageIsHomonymyPoints", (void**)(&_SetProjectionImageIsHomonymyPoints)),
				TPair<FString, void**>("GetProjectionImageIsHomonymyPoints", (void**)(&_GetProjectionImageIsHomonymyPoints)),
				TPair<FString, void**>("ProjectionImageToXML", (void**)(&_ProjectionImageToXML)),
				TPair<FString, void**>("ProjectionImageFromXML", (void**)(&_ProjectionImageFromXML)),
				TPair<FString, void**>("ProjectionImage_SetHintLineLength", (void**)(&_ProjectionImageSetHintLineLength)),


				/*Common*/
				TPair<FString, void**>("FreeDataIndice", (void**)(&_FreeDataIndice)),
				TPair<FString, void**>("FreeDataVertex", (void**)(&_FreeDataVertex)),
				TPair<FString, void**>("CalcMercatorFromSphericalFloat", (void**)(&_CalcMercatorFromSphericalFloat)),
				TPair<FString, void**>("CartesianToSphericalD", (void**)(&_CartesianToSphericalD)),
				TPair<FString, void**>("SphericalToCartesian", (void**)(&_SphericalToCartesian)),
				TPair<FString, void**>("ReleaseCharArray", (void**)(&_ReleaseCharArray)),
				TPair<FString, void**>("ReleaseIntArray", (void**)(&_ReleaseIntArray)),
				TPair<FString, void**>("ReleaseDoubleArray", (void**)(&_ReleaseDoubleArray)),
				TPair<FString, void**>("GetRotationMatrix", (void**)(&_GetRotationMatrix)),
				TPair<FString, void**>("RotationMatrix", (void**)(&_RotationMatrix)),

				/*GeoBox*/
				TPair<FString, void**>("GeoBox_Create", (void**)(&_GeoBox_Create)),
				TPair<FString, void**>("GeoBox_Destroy", (void**)(&_GeoBox_Destroy)),
				TPair<FString, void**>("GeoBox_GetBoxHeight", (void**)(&_GeoBox_GetBoxHeight)),
				TPair<FString, void**>("GeoBox_SetBoxHeight", (void**)(&_GeoBox_SetBoxHeight)),
				TPair<FString, void**>("GeoBox_GetBoxWidth", (void**)(&_GeoBox_GetBoxWidth)),
				TPair<FString, void**>("GeoBox_SetBoxWidth", (void**)(&_GeoBox_SetBoxWidth)),
				TPair<FString, void**>("GeoBox_GetBoxLength", (void**)(&_GeoBox_GetBoxLength)),
				TPair<FString, void**>("GeoBox_SetBoxLength", (void**)(&_GeoBox_SetBoxLength)),
				TPair<FString, void**>("GeoBox_GetCenterPoint", (void**)(&_GeoBox_GetCenterPoint)),
				TPair<FString, void**>("GeoBox_Copy", (void**)(&_GeoBox_Copy)),
					
				/*Dataset*/
				TPair<FString, void**>("Dataset_GetBounds", (void**)(&_Dataset_GetBounds)),
				TPair<FString, void**>("Dataset_GetType", (void**)(&_Dataset_GetType)),
				TPair<FString, void**>("Dataset_Query", (void**)(&_Dataset_Query)),
				TPair<FString, void**>("Dataset_QueryBySql", (void**)(&_Dataset_QueryBySql)),
				TPair<FString, void**>("Dataset_GetFieldInfos", (void**)(&_Dataset_GetFieldInfos)),
				TPair<FString, void**>("Dataset_QueryField", (void**)(&_Dataset_QueryField)),
				TPair<FString, void**>("Dataset_QueryAttributeById", (void**)(&_Dataset_QueryAttributeById)),

				/*GeoPoint3D*/
				TPair<FString, void**>("GeoPoint3D_Create", (void**)(&_GeoPoint3D_Create)),
				TPair<FString, void**>("GeoPoint3D_Destroy", (void**)(&_GeoPoint3D_Destroy)),
				TPair<FString, void**>("GeoPoint3D_SetPoint3D", (void**)(&_GeoPoint3D_SetPoint3D)),
				TPair<FString, void**>("GeoPoint3D_GetPoint3D", (void**)(&_GeoPoint3D_GetPoint3D)),
				TPair<FString, void**>("GeoPoint3D_Copy", (void**)(&_GeoPoint3D_Copy)),
					
				/*GeoLine3D*/
				TPair<FString, void**>("GeoLine3D_Create", (void**)(&_GeoLine3D_Create)),
				TPair<FString, void**>("GeoLine3D_Destroy", (void**)(&_GeoLine3D_Destroy)),
				TPair<FString, void**>("GeoLine3D_GetPoints", (void**)(&_GeoLine3D_GetPoints)),
				TPair<FString, void**>("GeoLine3D_GetPointCount", (void**)(&_GeoLine3D_GetPointCount)),
				TPair<FString, void**>("GeoLine3D_GetSubCount", (void**)(&_GeoLine3D_GetSubCount)),
				TPair<FString, void**>("GeoLine3D_GetPolyCounts", (void**)(&_GeoLine3D_GetPolyCounts)),
				TPair<FString, void**>("GeoLine3D_Make", (void**)(&_GeoLine3D_Make)),
				TPair<FString, void**>("GeoLine3D_AddPart", (void**)(&_GeoLine3D_AddPart)),
				TPair<FString, void**>("GeoLine3D_RemovePart", (void**)(&_GeoLine3D_RemovePart)),
				TPair<FString, void**>("GeoLine3D_Copy", (void**)(&_GeoLine3D_Copy)),
					
				/*GeoLine*/
				TPair<FString, void**>("GeoLine_Create", (void**)(&_GeoLine_Create)),
				TPair<FString, void**>("GeoLine_Destroy", (void**)(&_GeoLine_Destroy)),
				TPair<FString, void**>("GeoLine_GetPoints", (void**)(&_GeoLine_GetPoints)),
				TPair<FString, void**>("GeoLine_GetPointCount", (void**)(&_GeoLine_GetPointCount)),
				TPair<FString, void**>("GeoLine_GetSubCount", (void**)(&_GeoLine_GetSubCount)),
				TPair<FString, void**>("GeoLine_GetPolyCounts", (void**)(&_GeoLine_GetPolyCounts)),
				TPair<FString, void**>("GeoLine_Copy", (void**)(&_GeoLine_Copy)),
					
				/*GeoRegion3D*/
				TPair<FString, void**>("GeoRegion3D_Create", (void**)(&_GeoRegion3D_Create)),
				TPair<FString, void**>("GeoRegion3D_Destroy", (void**)(&_GeoRegion3D_Destroy)),
				TPair<FString, void**>("GeoRegion3D_GetPoints", (void**)(&_GeoRegion3D_GetPoints)),
				TPair<FString, void**>("GeoRegion3D_GetPointCount", (void**)(&_GeoRegion3D_GetPointCount)),
				TPair<FString, void**>("GeoRegion3D_GetSubCount", (void**)(&_GeoRegion3D_GetSubCount)),
				TPair<FString, void**>("GeoRegion3D_GetPolyCounts", (void**)(&_GeoRegion3D_GetPolyCounts)),
				TPair<FString, void**>("GeoRegion3D_CreateRegion", (void**)(&_GeoRegion3D_CreateRegion)),
				TPair<FString, void**>("GeoRegion3D_MakeWithPoints", (void**)(&_GeoRegion3D_MakeWithPoints)),
				TPair<FString, void**>("GeoRegion3D_AddPart", (void**)(&_GeoRegion3D_AddPart)),
				TPair<FString, void**>("GeoRegion3D_InsertPart", (void**)(&_GeoRegion3D_InsertPart)),
				TPair<FString, void**>("GeoRegion3D_RemovePart", (void**)(&_GeoRegion3D_RemovePart)),
				TPair<FString, void**>("GeoRegion3D_Copy", (void**)(&_GeoRegion3D_Copy)),
				TPair<FString, void**>("GeoRegion3D_GetInnerPoint3D", (void**)(&_GeoRegion3D_GetInnerPoint3D)),
					
				/*GeoRegion*/
				TPair<FString, void**>("GeoRegion_Create", (void**)(&_GeoRegion_Create)),
				TPair<FString, void**>("GeoRegion_MakeWithPoints", (void**)(&_GeoRegion_MakeWithPoints)),
				TPair<FString, void**>("GeoRegion_Destroy", (void**)(&_GeoRegion_Destroy)),
				TPair<FString, void**>("GeoRegion_Copy", (void**)(&_GeoRegion_Copy)),
					
				/*GeoModel3D*/
				TPair<FString, void**>("GeoModel3D_Create", (void**)(&_GeoModel3D_Create)),
				TPair<FString, void**>("GeoModel3D_Destroy", (void**)(&_GeoModel3D_Destroy)),
				TPair<FString, void**>("GeoModel3D_IsLonLat", (void**)(&_GeoModel3D_IsLonLat)),
				TPair<FString, void**>("GeoModel3D_Area", (void**)(&_GeoModel3D_Area)),
				TPair<FString, void**>("GeoModel3D_MinZ", (void**)(&_GeoModel3D_MinZ)),
				TPair<FString, void**>("GeoModel3D_MaxZ", (void**)(&_GeoModel3D_MaxZ)),
				TPair<FString, void**>("GeoModel3D_GetDataVertex", (void**)(&_GeoModel3D_GetDataVertex)),
				TPair<FString, void**>("GetDataTexture", (void**)(&_GetDataTexture)),
				TPair<FString, void**>("GetDataMaterial", (void**)(&_GetDataMaterial)),
				TPair<FString, void**>("GetDataPatch", (void**)(&_GetDataPatch)),
				TPair<FString, void**>("GetDataGeode", (void**)(&_GetDataGeode)),
				TPair<FString, void**>("GetDataSkeleton", (void**)(&_GetDataSkeleton)),
				TPair<FString, void**>("GeoModel3D_Copy", (void**)(&_GeoModel3D_Copy)),

				/*DataSource*/
				TPair<FString, void**>("OpenDatasource", (void**)(&_OpenDataSource)),
				TPair<FString, void**>("CloseDatasource", (void**)(&_CloseDataSource)),
				TPair<FString, void**>("IsOpenedDatasource", (void**)(&_IsOpenedDataSource)),
				TPair<FString, void**>("GetDatasetName", (void**)(&_GetDatasetName)),
				TPair<FString, void**>("GetDatasetByName", (void**)(&_GetDatasetByName)),
				TPair<FString, void**>("OpenDataset", (void**)(&_OpenDataset)),
				TPair<FString, void**>("IsOpenedDataset", (void**)(&_IsOpenedDataset)),
				TPair<FString, void**>("GetDatasetModelDataForUE", (void**)(&_GetDatasetModelData)),
				TPair<FString, void**>("FreeModelMesh", (void**)(&_FreeModelMesh)),
				TPair<FString, void**>("FreeModelMaterial", (void**)(&_FreeModelMaterial)),
				TPair<FString, void**>("FreeModelTexture", (void**)(&_FreeModelTexture)),
				TPair<FString, void**>("FreeDataSetSkeletons", (void**)(&_FreeDataSetSkeletons)),
				TPair<FString, void**>("FreeDataSetInstanceSkeletons", (void**)(&_FreeDataSetInstanceSkeletons)),
				TPair<FString, void**>("DataSource_Open", (void**)(&_DataSource_Open)),
				TPair<FString, void**>("DataSource_Close", (void**)(&_DataSource_Close)),
				TPair<FString, void**>("DataSource_GetDataset", (void**)(&_DataSource_GetDataset)),

				/*TrackingLayer*/
				TPair<FString, void**>("TrackingLayer3D_GetLayerPtr", (void**)(&_TrackingLayer3D_GetLayerPtr)),
				TPair<FString, void**>("TrackingLayer3D_GetCount", (void**)(&_TrackingLayer3D_GetCount)),
				TPair<FString, void**>("TrackingLayer3D_Add", (void**)(&_TrackingLayer3D_Add)),
				TPair<FString, void**>("TrackingLayer3D_Remove", (void**)(&_TrackingLayer3D_Remove)),
				TPair<FString, void**>("TrackingLayer3D_Get", (void**)(&_TrackingLayer3D_Get)),
				TPair<FString, void**>("TrackingLayer3D_GetTag", (void**)(&_TrackingLayer3D_GetTag)),
				TPair<FString, void**>("TrackingLayer3D_SetTag", (void**)(&_TrackingLayer3D_SetTag)),
				TPair<FString, void**>("TrackingLayer3D_Clear", (void**)(&_TrackingLayer3D_Clear)),
				TPair<FString, void**>("TrackingLayer3D_IndexOf", (void**)(&_TrackingLayer3D_IndexOf)),

				/*Gemetry*/
				TPair<FString, void**>("Geometry_GetType", (void**)(&_Geometry_GetType)),

				TPair<FString, void**>("Geometry3D_SetPosition", (void**)(&_Geometry3D_SetPosition)),
				TPair<FString, void**>("Geometry3D_GetPosition", (void**)(&_Geometry3D_GetPosition)),
				TPair<FString, void**>("Geometry3D_SetScale", (void**)(&_Geometry3D_SetScale)),
				TPair<FString, void**>("Geometry3D_GetScale", (void**)(&_Geometry3D_GetScale)),
				TPair<FString, void**>("Geometry3D_SetRotate", (void**)(&_Geometry3D_SetRotation)),
				TPair<FString, void**>("Geometry3D_GetRotate", (void**)(&_Geometry3D_GetRotation)),
				TPair<FString, void**>("Geometry_GetStyle", (void**)(&_Geometry_GetStyle)),
				TPair<FString, void**>("Geometry_SetStyle", (void**)(&_Geometry_SetStyle)),
				TPair<FString, void**>("Geometry_Clear", (void**)(&_Geometry_Clear)),
				TPair<FString, void**>("Geometry_GetBounds", (void**)(&_Geometry_GetBounds)),
					
				/*RenderFeature*/
				TPair<FString, void**>("RenderFeature_SetGeometry", (void**)(&_RenderFeature_SetGeometry)),

				/*HypsometricSetting*/
				TPair<FString, void**>("CreateHypsometricSetting", (void**)(&_CreateHypsometricSetting)),
				TPair<FString, void**>("DestroyHypsometricSetting", (void**)(&_DestroyHypsometricSetting)),
				TPair<FString, void**>("SetDisplayMode", (void**)(&_SetDisplayMode)),
				TPair<FString, void**>("GetDisplayMode", (void**)(&_GetDisplayMode)),
				TPair<FString, void**>("SetMinVisibleValue", (void**)(&_SetMinVisibleValue)),
				TPair<FString, void**>("GetMinVisibleValue", (void**)(&_GetMinVisibleValue)),
				TPair<FString, void**>("SetMaxVisibleValue", (void**)(&_SetMaxVisibleValue)),
				TPair<FString, void**>("GetMaxVisibleValue", (void**)(&_GetMaxVisibleValue)),
				TPair<FString, void**>("SetAnalysisMode", (void**)(&_SetAnalysisMode)),
				TPair<FString, void**>("GetAnalysisMode", (void**)(&_GetAnalysisMode)),
				TPair<FString, void**>("SetLinesInterval", (void**)(&_SetLinesInterval)),
				TPair<FString, void**>("GetLinesInterval", (void**)(&_GetLinesInterval)),
				TPair<FString, void**>("SetLineColor", (void**)(&_SetLineColor)),
				TPair<FString, void**>("GetLineColor", (void**)(&_GetLineColor)),

				TPair<FString, void**>("ModifyTerrainObject_Create", (void**)(&_ModifyTerrainObject_Create)),
				TPair<FString, void**>("ModifyTerrainObject_Destroy", (void**)(&_ModifyTerrainObject_Destroy)),
				TPair<FString, void**>("ModifyTerrainObject_SetRegion", (void**)(&_ModifyTerrainObject_SetRegion)),
				TPair<FString, void**>("ModifyTerrainObject_SetHeight", (void**)(&_ModifyTerrainObject_SetHeight)),
				TPair<FString, void**>("ModifyTerrainSetting_Add", (void**)(&_ModifyTerrainSetting_Add)),
				TPair<FString, void**>("ModifyTerrainSetting_Clear", (void**)(&_ModifyTerrainSetting_Clear)),

				/*SlopeSetting*/
				TPair<FString, void**>("SlopeSetting_Create", (void**)(&_SlopeSetting_Create)),
				TPair<FString, void**>("SlopeSetting_Destroy", (void**)(&_SlopeSetting_Destroy)),
				TPair<FString, void**>("SlopeSetting_SetDisplayMode", (void**)(&_SlopeSetting_SetDisplayMode)),
				TPair<FString, void**>("SlopeSetting_GetDisplayMode", (void**)(&_SlopeSetting_GetDisplayMode)),
				TPair<FString, void**>("SlopeSetting_SetMinVisibleValue", (void**)(&_SlopeSetting_SetMinVisibleValue)),
				TPair<FString, void**>("SlopeSetting_GetMinVisibleValue", (void**)(&_SlopeSetting_GetMinVisibleValue)),
				TPair<FString, void**>("SlopeSetting_SetMaxVisibleValue", (void**)(&_SlopeSetting_SetMaxVisibleValue)),
				TPair<FString, void**>("SlopeSetting_GetMaxVisibleValue", (void**)(&_SlopeSetting_GetMaxVisibleValue)),

				/*JsonFile*/
				TPair<FString, void**>("CreateJson", (void**)(&_CreateJson)),
				TPair<FString, void**>("RemoveAll", (void**)(&_RemoveAll)),
				TPair<FString, void**>("CreateJsonWithType", (void**)(&_CreateJsonWithType)),
				TPair<FString, void**>("Json_GetArrarySize", (void**)(&_Json_GetArrarySize)),
				TPair<FString, void**>("Json_GetAt", (void**)(&_Json_GetAt)),
				TPair<FString, void**>("Json_GetAtString", (void**)(&_Json_GetAtString)),
				TPair<FString, void**>("JsonAddString", (void**)(&_JsonAddString)),
				TPair<FString, void**>("JsonAddDouble", (void**)(&_JsonAddDouble)),
				TPair<FString, void**>("JsonAddInt", (void**)(&_JsonAddInt)),
				TPair<FString, void**>("JsonAddFloat", (void**)(&_JsonAddFloat)),
				TPair<FString, void**>("JsonArrayAddJson", (void**)(&_JsonArrayAddJson)),
				TPair<FString, void**>("JsonAddJson", (void**)(&_JsonAddJson)),
				TPair<FString, void**>("JsonAddBool", (void**)(&_JsonAddBool)),
				TPair<FString, void**>("JsonGetValueBool", (void**)(&_JsonGetValueBool)),
				TPair<FString, void**>("JsonGetValueInt", (void**)(&_JsonGetValueInt)),
				TPair<FString, void**>("JsonGetValueFloat", (void**)(&_JsonGetValueFloat)),
				TPair<FString, void**>("JsonGetValueDouble", (void**)(&_JsonGetValueDouble)),
				TPair<FString, void**>("JsonGetValueString", (void**)(&_JsonGetValueString)),
				TPair<FString, void**>("JsonGetValueJson", (void**)(&_JsonGetValueJson)),
				TPair<FString, void**>("Contains", (void**)(&_Contains)),
				TPair<FString, void**>("SaveToStdFile", (void**)(&_SaveToStdFile)),
				TPair<FString, void**>("Json_SaveToString", (void**)(&_Json_SaveToString)),
				TPair<FString, void**>("LoadFromStdFile", (void**)(&_LoadFromStdFile)),
				TPair<FString, void**>("LoadFromString", (void**)(&_LoadFromString)),
				TPair<FString, void**>("JsonGetAllKeys", (void**)(&_JsonGetAllKeys)),

				/*Query3D*/
				TPair<FString, void**>("Query3D_Create", (void**)(&_Query3D_Create)),
				TPair<FString, void**>("Query3D_RealseSpatialQuery", (void**)(&_Query3D_RealseSpatialQuery)),
				TPair<FString, void**>("Query3D_SetGeometry", (void**)(&_Query3D_SetGeometry)),
				TPair<FString, void**>("Query3D_SetPickRect", (void**)(&_Query3D_SetPickRect)),
				TPair<FString, void**>("Query3D_SetPositionMode", (void**)(&_Query3D_SetPositionMode)),
				TPair<FString, void**>("Query3D_GetPositionMode", (void**)(&_Query3D_GetPositionMode)),
				TPair<FString, void**>("Query3D_AddLayerID", (void**)(&_Query3D_AddLayerID)),
				TPair<FString, void**>("Query3D_RemoveLayerID", (void**)(&_Query3D_RemoveLayerID)),
				TPair<FString, void**>("Query3D_UpdateRectSelect", (void**)(&_Query3D_UpdateRectSelect)),
				TPair<FString, void**>("Query3D_GetSpatialQueryIDs", (void**)(&_Query3D_GetSpatialQueryIDs)),
				TPair<FString, void**>("Query3D_GetQueryIDs", (void**)(&_Query3D_GetQueryIDs)),

				/*Facade*/
				TPair<FString, void**>("OutputStreetFacade", (void**)(&_OutputStreetFacade)),

				/*FlyManager*/
				TPair<FString, void**>("FlyManager_Create", (void**)(&_FlyManager_Create)),
				TPair<FString, void**>("FlyManager_Destroy", (void**)(&_FlyManager_Destroy)),
				TPair<FString, void**>("FlyManager_Play", (void**)(&_FlyManager_Play)),
				TPair<FString, void**>("FlyManager_Stop", (void**)(&_FlyManager_Stop)),
				TPair<FString, void**>("FlyManager_Pause", (void**)(&_FlyManager_Pause)),
				TPair<FString, void**>("FlyManager_GetStatus", (void**)(&_FlyManager_GetStatus)),
				TPair<FString, void**>("FlyManager_Update", (void**)(&_FlyManager_Update)),
				TPair<FString, void**>("FlyManager_GetRoutes", (void**)(&_FlyManager_GetRoutes)),
				TPair<FString, void**>("FlyManager_CalcGlobalProgressTime", (void**)(&_FlyManager_CalcGlobalProgressTime)),
				TPair<FString, void**>("FlyManager_SetGlobalProgressTime", (void**)(&_FlyManager_SetGlobalProgressTime)),
				TPair<FString, void**>("FlyManager_GetPlayRate", (void**)(&_FlyManager_GetPlayRate)),
				TPair<FString, void**>("FlyManager_SetPlayRate", (void**)(&_FlyManager_SetPlayRate)),
				TPair<FString, void**>("FlyManager_GetTurningMode", (void**)(&_FlyManager_GetTurningMode)),
				TPair<FString, void**>("FlyManager_SetTurningMode", (void**)(&_FlyManager_SetTurningMode)),
				TPair<FString, void**>("FlyManager_GetCurrentStopIndex", (void**)(&_FlyManager_GetCurrentStopIndex)),
				TPair<FString, void**>("FlyManager_SetCurrentStopIndex", (void**)(&_FlyManager_SetCurrentStopIndex)),
				TPair<FString, void**>("FlyManager_GetArrivedNewStopIndex", (void**)(&_FlyManager_GetArrivedNewStopIndex)),
				TPair<FString, void**>("FlyManager_SetOriginalPosition", (void**)(&_FlyManager_SetOriginalPosition)),
				TPair<FString, void**>("FlyManager_GetCurrentProgress", (void**)(&_FlyManager_GetCurrentProgress)),

				/*Routes*/
				TPair<FString, void**>("Routes_FromFile", (void**)(&_Routes_FromFile)),
				TPair<FString, void**>("Routes_GetCount", (void**)(&_Routes_GetCount)),
				TPair<FString, void**>("Routes_GetItem", (void**)(&_Routes_GetItem)),
				TPair<FString, void**>("Routes_IndexOf", (void**)(&_Routes_IndexOf)),
				TPair<FString, void**>("Routes_SetCurrentRouteIndex", (void**)(&_Routes_SetCurrentRouteIndex)),
				TPair<FString, void**>("Routes_GetCurrentRouteIndex", (void**)(&_Routes_GetCurrentRouteIndex)),
				TPair<FString, void**>("Routes_ToFile", (void**)(&_Routes_ToFile)),
				TPair<FString, void**>("Routes_Remove", (void**)(&_Routes_Remove)),
				TPair<FString, void**>("Route_GetName", (void**)(&_Route_GetName)),
				TPair<FString, void**>("Route_SetName", (void**)(&_Route_SetName)),
				TPair<FString, void**>("Route_SetIsFlyingLoop", (void**)(&_Route_SetIsFlyingLoop)),
				TPair<FString, void**>("Route_GetIsFlyingLoop", (void**)(&_Route_GetIsFlyingLoop)),
				TPair<FString, void**>("Route_Create", (void**)(&_Route_Create)),
				TPair<FString, void**>("Route_SetHeadingFixed", (void**)(&_Route_SetHeadingFixed)),
				TPair<FString, void**>("Route_IsHeadingFixed", (void**)(&_Route_IsHeadingFixed)),
				TPair<FString, void**>("Route_SetTiltFixed", (void**)(&_Route_SetTiltFixed)),
				TPair<FString, void**>("Route_IsTiltFixed", (void**)(&_Route_IsTiltFixed)),
				TPair<FString, void**>("Route_GetStops", (void**)(&_Route_GetStops)),
				TPair<FString, void**>("RouteStops_GetStop", (void**)(&_RouteStops_GetStop)),
				TPair<FString, void**>("RouteStops_GetCount", (void**)(&_RouteStops_GetCount)),
				TPair<FString, void**>("RouteStops_InsertStop", (void**)(&_RouteStops_InsertStop)),
				TPair<FString, void**>("RouteStops_Remove", (void**)(&_RouteStops_Remove)),
				TPair<FString, void**>("RouteStop_Create", (void**)(&_RouteStop_Create)),
				TPair<FString, void**>("RouteStop_Destory", (void**)(&_RouteStop_Destory)),
				TPair<FString, void**>("RouteStop_GetName", (void**)(&_RouteStop_GetName)),
				TPair<FString, void**>("RouteStop_SetName", (void**)(&_RouteStop_SetName)),
				TPair<FString, void**>("RouteStop_SetCamera", (void**)(&_RouteStop_SetCamera)),
				TPair<FString, void**>("RouteStop_GetCameraState", (void**)(&_RouteStop_GetCameraState)),
				TPair<FString, void**>("RouteStop_GetDuration", (void**)(&_RouteStop_GetDuration)),
				TPair<FString, void**>("RouteStop_SetDuration", (void**)(&_RouteStop_SetDuration)),

				/*Selection3D*/
				TPair<FString, void**>("Selection3D_CreateByLayer", (void**)(&_Selection3D_CreateByLayer)),
				TPair<FString, void**>("Selection3D_Destroy", (void**)(&_Selection3D_Destroy)),
				TPair<FString, void**>("Selection3D_GetStyle3D", (void**)(&_Selection3D_GetStyle3D)),
				TPair<FString, void**>("Selection3D_GetCount", (void**)(&_Selection3D_GetCount)),
				TPair<FString, void**>("Selection3D_Add", (void**)(&_Selection3D_Add)),
				TPair<FString, void**>("Selection3D_RemoveAt", (void**)(&_Selection3D_RemoveAt)),
				TPair<FString, void**>("Selection3D_Clear", (void**)(&_Selection3D_Clear)),
				TPair<FString, void**>("Selection3D_GetAt", (void**)(&_Selection3D_GetAt)),
				TPair<FString, void**>("Selection3D_FindID", (void**)(&_Selection3D_FindID)),
				/*Style3D*/
				TPair<FString, void**>("Style3D_Create", (void**)(&_Style3D_Create)),
				TPair<FString, void**>("Style3D_Destroy", (void**)(&_Style3D_Destroy)),
				TPair<FString, void**>("Style3D_SetAltitudeMode", (void**)(&_Style3D_SetAltitudeMode)),
				TPair<FString, void**>("Style3D_GetAltitudeMode", (void**)(&_Style3D_GetAltitudeMode)),
				TPair<FString, void**>("Style3D_SetBottomAltitude", (void**)(&_Style3D_SetBottomAltitude)),
				TPair<FString, void**>("Style3D_GetBottomAltitude", (void**)(&_Style3D_GetBottomAltitude)),
				TPair<FString, void**>("Style3D_SetExtendHeight", (void**)(&_Style3D_SetExtendHeight)),
				TPair<FString, void**>("Style3D_GetExtendHeight", (void**)(&_Style3D_GetExtendHeight)),
				TPair<FString, void**>("Style3D_SetFillColor", (void**)(&_Style3D_SetFillColor)),
				TPair<FString, void**>("Style3D_GetFillColor", (void**)(&_Style3D_GetFillColor)),
				TPair<FString, void**>("Style3D_SetFill3DMode", (void**)(&_Style3D_SetFill3DMode)),
				TPair<FString, void**>("Style3D_GetFill3DMode", (void**)(&_Style3D_GetFill3DMode)),
				TPair<FString, void**>("Style3D_SetLineColor3D", (void**)(&_Style3D_SetLineColor3D)),
				TPair<FString, void**>("Style3D_GetLineColor3D", (void**)(&_Style3D_GetLineColor3D)),
				TPair<FString, void**>("Style3D_SetLineWidth", (void**)(&_Style3D_SetLineWidth)),
				TPair<FString, void**>("Style3D_GetLineWidth", (void**)(&_Style3D_GetLineWidth)),
				TPair<FString, void**>("Style3D_SetMarker3DScale", (void**)(&_Style3D_SetMarker3DScale)),
				TPair<FString, void**>("Style3D_GetMarker3DScale", (void**)(&_Style3D_GetMarker3DScale)),
				TPair<FString, void**>("Style3D_SetMarker3DRotate", (void**)(&_Style3D_SetMarker3DRotate)),
				TPair<FString, void**>("Style3D_GetMarker3DRotate", (void**)(&_Style3D_GetMarker3DRotate)),
				TPair<FString, void**>("Style3D_SetMarker3DTranslation", (void**)(&_Style3D_SetMarker3DTranslation)),
				TPair<FString, void**>("Style3D_GetMarker3DTranslation", (void**)(&_Style3D_GetMarker3DTranslation)),
				TPair<FString, void**>("Style3D_SetSideTexture", (void**)(&_Style3D_SetSideTexture)),
				TPair<FString, void**>("Style3D_SetTilingU", (void**)(&_Style3D_SetTilingU)),
				TPair<FString, void**>("Style3D_SetTilingV", (void**)(&_Style3D_SetTilingV)),
				TPair<FString, void**>("Style3D_SetTopTexture", (void**)(&_Style3D_SetTopTexture)),
				TPair<FString, void**>("Style3D_SetTopTilingU", (void**)(&_Style3D_SetTopTilingU)),
				TPair<FString, void**>("Style3D_SetTopTilingV", (void**)(&_Style3D_SetTopTilingV)),
				/*PrjCoordSys*/
				TPair<FString, void**>("PrjCoordSys_Create", (void**)(&_PrjCoordSys_Create)),
				TPair<FString, void**>("PrjCoordSys_GetName", (void**)(&_PrjCoordSys_GetName)),
				TPair<FString, void**>("PrjCoordSys_FromEPSGCode", (void**)(&_PrjCoordSys_FromEPSGCode)),
				TPair<FString, void**>("PrjCoordSys_FromFile", (void**)(&_PrjCoordSys_FromFile)),
				TPair<FString, void**>("PrjCoordSys_Dispose", (void**)(&_PrjCoordSys_Dispose)),
				TPair<FString, void**>("PrjCoordSys_Inverse", (void**)(&_PrjCoordSys_Inverse)),
				TPair<FString, void**>("PrjCoordSys_Forward", (void**)(&_PrjCoordSys_Forward)),

				/*LicenseVerify*/
				TPair<FString, void**>("LicenseVerify_GameEngine", (void**)(&_LicenseVerify_GameEngine)),

				/*UDB*/
				TPair<FString, void**>("SaveMaterialToJson", (void**)(&_SaveMaterialToJson)),
				
				/*GlobalImage*/
				TPair<FString, void**>("GlobalImage_AddExcavationRegion", (void**)(&_GlobalImage_AddExcavationRegion)),
				TPair<FString, void**>("GlobalImage_ClearExcavationRegions", (void**)(&_GlobalImage_ClearExcavationRegions)), 
				TPair<FString, void**>("GlobalImage_GetExcavationRegion", (void**)(&_GlobalImage_GetExcavationRegion)),
				TPair<FString, void**>("GlobalImage_GetExcavationRegionTag", (void**)(&_GlobalImage_GetExcavationRegionTag)),
				TPair<FString, void**>("GlobalImage_IndexOfExcavationRegion", (void**)(&_GlobalImage_IndexOfExcavationRegion)),
				TPair<FString, void**>("GlobalImage_RemoveExcavationRegion", (void**)(&_GlobalImage_RemoveExcavationRegion)),
				TPair<FString, void**>("GlobalImage_SetExcavationRegionTag", (void**)(&_GlobalImage_SetExcavationRegionTag)),
				TPair<FString, void**>("GlobalImage_SetVisible", (void**)(&_GlobalImage_SetVisible)),
				TPair<FString, void**>("GlobalImage_GetVisible", (void**)(&_GlobalImage_GetVisible)),
			};

			bool RealspaceDLL::LoadAllAPI()
			{
				if (RealspaceDLL::m_bLoadAllAPI)
				{
					return true;
				}

				void* pAPIDLL = FSuperMapModule::Get().GetDLLHandle();
				void* pCloudLicenseDLL = FSuperMapModule::Get().GetCloudLicenseDLLHandle();
#if PLATFORM_LINUX
				if (pAPIDLL == NULL || arrAPIs.Num() == 0)
#else
				if (pAPIDLL == NULL || arrAPIs.Num() == 0 || pCloudLicenseDLL == NULL
			|| arrCloudLicenseAPIs.Num() == 0)
#endif
				{
					return false;
				}

				TArray<TPair<FString, void**> >::TIterator itor = arrAPIs.CreateIterator();
				for (; itor; itor++)
				{
					FString strFuncName = itor->Key;
					void** function = itor->Value;
					(*function) = FPlatformProcess::GetDllExport(pAPIDLL, *strFuncName);
				}
//Linux下暂时不支持云许可
#if !PLATFORM_LINUX 
				// 云许可
				TArray<TPair<FString, void**> >::TIterator itorCloudLicense = arrCloudLicenseAPIs.CreateIterator();
				for (; itorCloudLicense; itorCloudLicense++)
				{
					FString strLicenseName = itorCloudLicense->Key;
					void** license = itorCloudLicense->Value;
					(*license) = FPlatformProcess::GetDllExport(pCloudLicenseDLL, *strLicenseName);
				}
#endif
				RealspaceDLL::m_bLoadAllAPI = true;

				return true;
			}
		}
	}
}
