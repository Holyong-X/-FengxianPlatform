#pragma once

#include "CoreMinimal.h"

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{

			// ��¼��ɫ����
			struct PBRFactor4d
			{
				double m_dFactorX;
				double m_dFactorY;
				double m_dFactorZ;
				double m_dFactorW;
			};

			struct PBRFactor3d
			{
				double m_dFactorX;
				double m_dFactorY;
				double m_dFactorZ;
			};

			// �����˶�����
			struct UVMotionParameter
			{
				//! \brief U������ٶ�
				float m_fSpeedU;
				//! \brief V������ٶ�
				float m_fSpeedV;
				//! \brief ����
				float m_fPeriod;
			};

			struct TextureMotionParam
			{
				//! \brief ����ƽ���˶��Ĳ���
				UVMotionParameter m_OffsetMotion;
				//! \brief �������ŵĲ���
				UVMotionParameter m_TilingMotion;
			};

			struct PBRMetallicRough
			{
				//! \brief ����Ļ�����ɫ����
				PBRFactor4d m_vec4BaseColor;
				//! \brief ���������ɫ�����������������е����
				int32 m_nBaseColorTextureIndex;
				//! \brief ���������ɫ�������������������������е����
				int32 m_nBaseColorTextureCoordIndex;
				//! \brief ��ɫ�����˶��Ĳ�������
				TextureMotionParam m_BaseColorTextureMotion;
				//! \brief �����Ⱥʹֲ������������������е����(Rͨ���洢�����ȣ�Gͨ���洢�ֲڶ�)
				int32 m_nMetallicRoughnessTextureIndex;
				//! \brief �����Ⱥʹֲ�����������������������е����
				int32 m_nMetallicRoughnessTextureCoordIndex;
				//! \brief ���ƽ�����ǿ��������
				float m_fMetallicFactor;
				//! \brief ���ƴֲ���ǿ��������
				float m_fRoughnessFactor;
			};

			struct PBRSpecularGlossy
			{
				//! \brief ɢ����ɫ
				PBRFactor4d m_vec4DiffuseFactor;
				//! \brief �������ɫ
				PBRFactor3d m_vec3SpecularFactor;
				//! \brief �߹�ǿ��
				float m_fGlossinessFactor;
				//! \brief ɢ����ɫ����
				char* m_strDiffuseTexture;
				//! \brief �����߹�ǿ������RGBͨ���澵�����ɫ��Aͨ����߹�ǿ��
				char* m_strSpecularGlossinessTexture;
			};

			// PBR����
			struct PBRParam
			{
				//! \brief �����Է���ǿ�ȵ�����
				PBRFactor3d m_vec3EmissiveFactor;
				//! \brief �Է������������������е���� RGB����
				int32 m_nEmissiveTextureIndex;
				//! \brief �Է�������������������������������е����
				int32 m_nEmissiveTextureCoordIndex;
				//! \brief �Է��������˶��Ĳ�������
				TextureMotionParam m_EmissiveTextureMotion;
				//! \brief �������������������е���ţ��������İ�͹ϸ�� float��ʽRGB����
				int32 m_nNormalTextureIndex;
				//! \brief ��������������������������������е����
				int32 m_nNormalTextureCoordIndex;
				//! \brief �����������������
				float m_fNormalTextureScale;
				//! \brief �ڵ�ͼ�����������е���ţ�����������氼͹�ԶԹ��յ�Ӱ�죬�����϶���Ͱ� float�Ҷ�����
				int32 m_nOcclusionTextureIndex;
				//! \brief �ڵ�ͼ�������������������������е����
				int32 m_nOcclusionTextureCoordIndex;
				//! \brief �ڵ�ͼ����������
				float m_fOcclusionTextureStrength;
				//! \brief UGAlphaMode
				int32	m_AlphaMode;
				//! \brief ��alphaModeΪMaskʱ����ɫ���������ֵ��baseColor��Alphaֵ���бȽϾ����Ƿ���
				float	m_fAlphaCutoff;
				//! \brief �Ƿ�˫����Ⱦ
				int32 m_bDoubleSided;

				//! \brief �����ֲڶ�ģ��
				PBRMetallicRough* m_pPBRMetallicRough;

				//! \brief �����߹�ģ��
				PBRSpecularGlossy* m_pPBRSpecularGlossy;
			};
		}
	}
}