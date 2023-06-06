#pragma once

#include "CoreMinimal.h"
#include "SceneType.h"
#include "Data/Vector3d.h"
#include "Data/Matrix4d.h"

using namespace SuperMapSDK::UnrealEngine::Data;
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			class SUPERMAP_API Georeference
			{
			public:
				Georeference();
				~Georeference();
			public:
				// ���õ���ο�ԭ��
				static void SetGeoreferenceOrigin(double dLongitude, double dLatitude, double dAltitude);

				// �����������
				static void SetWorld(UWorld* pWorld);

				static const Matrix4d& GetGeoreferenceToECEF();
				static const Matrix4d& GetECEFtoGeoreference();

				static const Matrix4d& GetUeAbsToECEF();
				static const Matrix4d& GetECEFtoUeAbs();

				// ��UE��ģ��ECEF�任����ת��Ϊģ�͵�UE����Ⱦ����ϵ�ľ���
				static Matrix4d TransformECEFToUERelative(const Matrix4d& localToECEF);

				// ��UE��ģ��ECEF�任����ת��Ϊģ�͵�UE����Ⱦ����ϵ�ľ���
				static void TransformECEFToUERelative(const Matrix4d& localToECEF, FTransform& transform);

				// ��UE�������ת����UE��������
				static Vector3d TransformUERelativeToUEAbs(Vector3d vUEPos);

				// ��UE��������ת����UE�������
				static Vector3d TransformUEAbsToUERelative(Vector3d vUEAbsPos);

				// ��UE����Ⱦ����ϵ��任������Ϊ(0,0,0) ECEF�������(�����λΪ��)
				static Vector3d TransformUERelativeToOriginECEF(Vector3d vUEPos);
				static void TransformUERelativeToOriginECEF(Vector3d &vUEPos, FRotator &rRotate);

				// ������Ϊ(0,0,0) ECEF������� ת����UE����Ⱦ����ϵ��
				static Vector3d TransformOriginECEFToUEReative(Vector3d vECEF);

				// ��UE����Ⱦ����ϵ��任������Ϊ����ԭ�� ECEF�������(����Ϊ���ף������λΪ��)
				static Vector3d TransformUERelativeToGeorefenceECEF(Vector3d vUEPos);

				// ��UE�ľ�������任������ԭ��ECEF �������(����Ϊ���ף������λΪ��)
				static Vector3d TransformUEAbsToGeorefenceECEF(Vector3d vUEAbsPos);

				// ������ԭ�� ECEF����ת��ΪUE����Ⱦ����ϵ�㣨����Ϊ�ף����Ϊ���ף�
				static Vector3d TransformGeorefenceECEFToUERelative(Vector3d vGeoECEF);

				// ��UE ECEF ����ϵ��任��UGC ECEF����ϵ
				static Vector3d TransformUEECEFToUGCECEF(Vector3d vUEPos);

				static void Reset();
			public:
				static double m_dLongitude;
				static double m_dLatitude;
				static double m_dAltitude;
			private:
				static Matrix4d m_georeferenceToECEF;
				static Matrix4d m_ECEFtoGeoreference;
				static Matrix4d m_ueAbsToECEF;
				static Matrix4d m_ECEFtoUeAbs;

				//! \brief ���糡������
				static UWorld* m_pWorld;
			};
		}
	}
}