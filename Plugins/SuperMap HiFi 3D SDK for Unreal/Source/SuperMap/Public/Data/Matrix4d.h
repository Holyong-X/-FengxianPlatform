#pragma once

#include "Data/Vector3d.h"

//! \brief   4X4˫���Ⱦ�����
//! \remarks ά��4X4����
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{
			class SUPERMAP_API Matrix4d
			{

			public:

				//! \brief ȱʡ���캯����
				Matrix4d();

				//! \brief ��16�����������������Ĺ��캯����
				//! \param m00 [in]��
				//! \param m01 [in]��
				//! \param m02 [in]��
				//! \param m03 [in]��
				//! \param m10 [in]��
				//! \param m11 [in]��
				//! \param m12 [in]��
				//! \param m13 [in]��
				//! \param m20 [in]��
				//! \param m21 [in]��
				//! \param m22 [in]��
				//! \param m23 [in]��
				//! \param m30 [in]��
				//! \param m31 [in]��
				//! \param m32 [in]��
				//! \param m33 [in]��
				Matrix4d(
					double m00, double m01, double m02, double m03,
					double m10, double m11, double m12, double m13,
					double m20, double m21, double m22, double m23,
					double m30, double m31, double m32, double m33);

				//! \brief �����ʼ��Matrix4d
				//! \param pMatrix [in] 
				Matrix4d(double * pMatrix);
				Matrix4d(float * pMatrix);

				//! \brief ��FMatrix��ʼ��Matrix4d
				Matrix4d(FMatrix fMatrix);

				//! \brief ����������
				virtual ~Matrix4d();

				//! \brief ����*����������ֵ��ˡ�
				//! \param scalar ��ֵ[in]��
				//! \return ������ɺ�4x4����
				Matrix4d operator*(double scalar);

				//! \brief ����*����ɾ����������ˡ�
				//! \param &m2 ��������[in]��
				//! \return ������ɺ����
				Matrix4d operator * (const Matrix4d& m2) const;

				//! \brief ����=����ɾ���ĸ�ֵ
				//! \brief &m2,��ֵ����	
				Matrix4d& operator = (const Matrix4d& m2);

				//! \brief ������ˡ�
				//! \param &m2 ����һ��4X4����[in]��
				//! \return ��������4X4����
				Matrix4d Concatenate(const Matrix4d& m2) const;

				//! \brief ����[]��ȡ����Ӧ�С�
				//! \param iRow �кţ���Ч��ΧΪ�㵽��[in]��
				//! \return ����ָ��һ�����ݣ�����������ָ�롣
				double* operator[] (int iRow);

				//! \brief �ж����������Ƿ���ȡ�
				//! \param &m2 ����һ������[in]��
				//! \return ����ȷ���ΪTRUE����������򷵻�ΪFALSE��
				bool operator == (const Matrix4d& m2) const;

				//! \brief �ж����������Ƿ���ȡ�
				//! \param &m2 ����һ������[in]��
				//! \return ������ȷ���ΪTRUE�����򷵻�FALSE��
				bool operator != (const Matrix4d& m2) const;

				//! \brief ȡ��ֻ�����������ݡ�
				//! \param iRow �кţ���Ч��ΧΪ�㵽��[in]��
				//! \return �����ݡ�
				const double* const operator [] (int iRow) const;

				//! \brief ȡ������ĳ��ĳ�е�ֵ��
				//! \param iRow ����[in]��
				//! \param iCol ����[in]
				double operator () (int iRow, int iCol);

				//! \brief �������İ������
				//! \return ����İ������
				//! \remarks ��	
				Matrix4d Adjoint() const;

				//! \brief �����������ʽֵ��
				//! \return ����ʽֵ����
				double Determinant() const;

				//! \brief ��������������
				//! \return ���������
				Matrix4d Invert() const;

				//! \brief ����4x4������3x3�Ӿ�������ʽ��
			//! \param m 4x4����[in]��
			//! \param r0 ��һ���к�[in]��
			//! \param r1 �ڶ����к�[in]��
			//! \param r2 �������к�[in]��
			//! \param c0 ��һ���к�[in]��
			//! \param c1 �ڶ����к�[in]��
			//! \param c2 �������к�[in]��
				double MINOR(const Matrix4d& t, int r0, int r1, int r2,
					int c0, int c1, int c2) const;

				//! \brief ���þ���ƽ�Ʋ���, [3][0], [3][1], [3][2]��ֵ��
				//! \param v ƽ������[in]��
				void SetTrans(const Vector3d& v);

				//! \brief ��ȡ����ƽ�Ʋ���, [3][0], [3][1], [3][2]��ֵ��
				//! \param v ƽ������[in]��
				Vector3d GetTrans() const;

				Vector3d GetScale() const;
				
				//! \brief ����һ�����ž���
				//! param x X�����Ŵ�С[in]��
				//! param y Y�����Ŵ�С[in]��
				//! param z Z�����Ŵ�С[in]��
				//! return ���ž���
				static Matrix4d Scaling(double x, double y, double z);

				//! \brief ���������ת�þ���
				//! \return ����ת�þ���
				Matrix4d Transpose() const;

				//! \brief ����
				//! \params Scale [in]
				void ApplyScale(double dScale);

				//! \brief 4X4�����
				//! \remarks ����Ԫ��Ϊ��
				static const Matrix4d ZERO;
				//! \brief 4X4 ��λ����
				//! \remarks �Խ���Ԫ��Ϊ1������Ϊ0
				static const Matrix4d IDENTITY;

				//! \brief ��������XY��ľ���
				static const Matrix4d XY_REVERSE;

				//! \brief ����ת��
				//! \params srcMatrix [in]  ԭʼ����
				//! \params dstMatrix [out] UE����
				static void ToFMatrix(const Matrix4d& srcMatrix, FMatrix& dstMatrix);

				//! \brief ת��Ϊdoubleָ��
				//! \params srcMatrix [in]  ԭʼ����
				//! \params pOutDouble [out] ���double����
				static void ToDoublePointer(const Matrix4d& srcMatrix, double*& pOutDouble);
			protected:

				//! \brief ����������
				//! \remarks ���������ݱ����ڸñ����С�
				double m[4][4];
			};
		}
	}
}