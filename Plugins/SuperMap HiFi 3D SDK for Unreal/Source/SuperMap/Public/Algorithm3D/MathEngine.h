#pragma once

#include "CoreMinimal.h"
#include "Data/Matrix4d.h"
#include "Core/ROCache.h"
#include "Graphics3D/GameEnum.h"
#include "Core/RealspaceDLL.h"
#include "Base3D/CommonDefine.h"
#include "Core/SceneType.h"
using namespace SuperMapSDK::UnrealEngine::Data;
using namespace SuperMapSDK::UnrealEngine::Core;

class UMaterialInstanceDynamic;
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Algorithm3D
		{
			class SUPERMAP_API MathEngine
			{
			public:
				MathEngine();
				~MathEngine();

				//! \brief �������굽�ѿ�������
				static FVector SphericalToCartesian(Gamedouble dLongitude, Gamedouble dLatitude, Gamedouble dHeight);
				static Vector3d SphericalToCartesian2(Gamedouble dLongitude, Gamedouble dLatitude, Gamedouble dHeight);

				//! \brief �Ͽ����������������
				static Vector3d CartesianToSpherical(Gamedouble dX, Gamedouble dY, Gamedouble dZ);

				//! \brief ������ת����
				static Matrix4d CalRotation(Gamedouble dLongitude, Gamedouble dLatitude, Gamedouble dAltitude);

				//! \brief �����ʷ�
				static Gamebool Triangulate(Gamefloat*& pPoint3Ds, Gameint nPointCount, Gameint nSubCount, Gameint* nPolyCounts, Gameint*& arrIntIndex, Gameint& nCount);

				//! \brief �ͷ�Int
				static Gamevoid FreeUGInt(Gameint*& pIndex);

				//! \brief �ͷ�Gamefloat
				static Gamevoid FreeUGFloat(Gamefloat*& pData);

				//! \brief �ͷ�Gamedouble
				static Gamevoid FreeUGDouble(Gamedouble*& pData);

				//! \brief ˮƽ�ӳ����봹ֱ�ӳ���ת��
				static Gamedouble HorizontalToVerticalFOV(Gamedouble dHFov, Gamedouble dAspect);
				static Gamedouble VerticalToHorizontalFOV(Gamedouble dVFov, Gamedouble dAspect);

				//! \brief UGC��ͼ����ת��ΪUE��ͼ����
				static Gamevoid UGCViewMatrixToUEViewMatrix(Matrix4d &ugcViewMatrix, Matrix4d &ueViewMatrix);
				//! \brief ����Location��Rotator
				static Gamevoid UpdateRotationAndLocation(FVector &vLocation, FRotator &vRotator, Matrix4d mat4d);
				//! \brief UGC��ͼ����ת��ΪUE���꼰��ת��
				static Gamevoid UGCViewMatrixToUERotationAndLocation(Matrix4d ugcViewMatrix, Vector3d &vLocation, FRotator &vRotator);
				//! \brief ����Shader����
				static Gamevoid SetShaderMatrixParamter(UMaterialInstanceDynamic* pMID, Matrix4d mat, FString strName);

				//! \brief ��������
				static SceneManagerType ConvertToSceneManagerType(int32 nType);
			
				//! \brief ����Heading��Pitch
				static Gamevoid CalHeadingAndPitch(Gamebool bIsSphere, 
					Gamedouble dPosX, Gamedouble dPosY, Gamedouble dPosZ,
					Gamedouble dDirectionX, Gamedouble dDirectionY, Gamedouble dDirectionZ,
					Gamedouble &dHeading, Gamedouble &dPitch);

				//! \brief ��UGC�ľ����ֵ��ָ��ת��ΪUE�ľ���,(XY��ת�����ŵ�����)
				static Matrix4d UGCMatrixPtrToUEMatrix4d(Gamedouble* pDoubleObjectMat);

				//! \brief �ַ���תGamelong
				static Gamelong CalHashCodeByChar(FString strName);

				//! \brief �������굽�ѿ������꣬�漰����ԭ�����
				static FVector SphericalToCartesian_GeoOrigin(FVector vPos);

				//! \brief FStringתChar(��Գ�·���ַ���)��pChar����Ķ�̬�ڴ���Ҫ�ⲿɾ��
				static Gamevoid FStringToANSIChar(FString Str, ANSICHAR* &pChar);

				//! \brief ���߹ս�ƽ������
				//! \brief nFactorƽ������ nSlice ��Ƭ��
				//! \brief bIsSym FALSE ��Բ�� TRUE Բ��
				static Gamevoid Chamfer(TArray<Vector3d>& vCurveds, TArray<Vector3d>& vLines, Gameint nFactor, Gamebool bIsSym, Gameint nSlice);

				//! \brief ϸ�ֲ�ֵ��
				//! \brief arrPoints ��ԭʼ��
				//! \brief arrLocations ��ֵ���
				static Gamevoid GetSubdivisionPoints(TArray<FVector>& arrPoints, TArray<FVector>& arrLocations, Gamefloat fDistance);
				static Gamevoid GetSubdivisionPoints2(TArray<Vector3d>& arrPoints, TArray<Vector3d>& arrLocations, Gamefloat fDistance);

				//! \brief �����������ཻ��
				//! \param vecStart �������[in]��
				//! \param vecDirection ���߷���in]��
				//! \param dRadius ��뾶[in]��
				//! \return �����ཻ����TRUE, ���򷵻�FALSE��
				static Gamebool RayIntersectionWithGlobe(Vector3d vStart, Vector3d vDirection, Vector3d& vIntersect, SceneType sceneType, Gamedouble dRadius);
				
				//! \brief �����ȡ��γ�����Ӧ������뾶
				static Gamedouble GetEllipsoidRadius(Gamedouble dLongitude, Gamedouble dLatitude, Gamedouble dAltitude);

				//! \brief ����ƫ�ơ�
				static FVector m_vWorldOffset;
			};
		}
	}
}