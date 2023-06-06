#include "Data/Matrix4d.h"
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{
			const Matrix4d Matrix4d::ZERO(
				0, 0, 0, 0,
				0, 0, 0, 0,
				0, 0, 0, 0,
				0, 0, 0, 0);

			const Matrix4d Matrix4d::IDENTITY(
				1, 0, 0, 0,
				0, 1, 0, 0,
				0, 0, 1, 0,
				0, 0, 0, 1);

			const Matrix4d Matrix4d::XY_REVERSE(
				0, 1, 0, 0,
				1, 0, 0, 0,
				0, 0, 1, 0,
				0, 0, 0, 1);


			Matrix4d::Matrix4d()
			{
				*this = Matrix4d::IDENTITY;
			}
			Matrix4d::Matrix4d(
				double m00, double m01, double m02, double m03,
				double m10, double m11, double m12, double m13,
				double m20, double m21, double m22, double m23,
				double m30, double m31, double m32, double m33)
			{
				m[0][0] = m00;
				m[0][1] = m01;
				m[0][2] = m02;
				m[0][3] = m03;
				m[1][0] = m10;
				m[1][1] = m11;
				m[1][2] = m12;
				m[1][3] = m13;
				m[2][0] = m20;
				m[2][1] = m21;
				m[2][2] = m22;
				m[2][3] = m23;
				m[3][0] = m30;
				m[3][1] = m31;
				m[3][2] = m32;
				m[3][3] = m33;
			}

			Matrix4d::Matrix4d(double * pMatrix)
			{
				if (pMatrix == nullptr)
				{
					*this = Matrix4d::IDENTITY;
				}
				else
				{
					*this = Matrix4d(
						pMatrix[0], pMatrix[1], pMatrix[2], pMatrix[3],
						pMatrix[4], pMatrix[5], pMatrix[6], pMatrix[7],
						pMatrix[8], pMatrix[9], pMatrix[10], pMatrix[11],
						pMatrix[12], pMatrix[13], pMatrix[14], pMatrix[15]);
				}
			}

			Matrix4d::Matrix4d(float * pMatrix)
			{
				if (pMatrix == nullptr)
				{
					*this = Matrix4d::IDENTITY;
				}
				else
				{
					*this = Matrix4d(
						pMatrix[0], pMatrix[1], pMatrix[2], pMatrix[3],
						pMatrix[4], pMatrix[5], pMatrix[6], pMatrix[7],
						pMatrix[8], pMatrix[9], pMatrix[10], pMatrix[11],
						pMatrix[12], pMatrix[13], pMatrix[14], pMatrix[15]);
				}
			}

			Matrix4d::Matrix4d(FMatrix  fMatrix)
			{
				m[0][0] = fMatrix.M[0][0]; m[0][1] = fMatrix.M[0][1]; m[0][2] = fMatrix.M[0][2]; m[0][3] = fMatrix.M[0][3];
				m[1][0] = fMatrix.M[1][0]; m[1][1] = fMatrix.M[1][1]; m[1][2] = fMatrix.M[1][2]; m[1][3] = fMatrix.M[1][3];
				m[2][0] = fMatrix.M[2][0]; m[2][1] = fMatrix.M[2][1]; m[2][2] = fMatrix.M[2][2]; m[2][3] = fMatrix.M[2][3];
				m[3][0] = fMatrix.M[3][0]; m[3][1] = fMatrix.M[3][1]; m[3][2] = fMatrix.M[3][2]; m[3][3] = fMatrix.M[3][3];
			}

			Matrix4d::~Matrix4d()
			{

			}
			Matrix4d Matrix4d::operator*(double scalar)
			{
				return Matrix4d(
					scalar * m[0][0], scalar * m[0][1], scalar * m[0][2], scalar * m[0][3],
					scalar * m[1][0], scalar * m[1][1], scalar * m[1][2], scalar * m[1][3],
					scalar * m[2][0], scalar * m[2][1], scalar * m[2][2], scalar * m[2][3],
					scalar * m[3][0], scalar * m[3][1], scalar * m[3][2], scalar * m[3][3]);
			}

			//! \brief 重载*，完成矩阵与矩阵相乘。
			//! \param &m2 乘数矩阵[in]。
			//! \return 运算完成后矩阵。
			Matrix4d Matrix4d::operator * (const Matrix4d& m2) const
			{
				return Concatenate(m2);
			}
			//! \brief 重载=，完成矩阵的赋值
			//! \brief &m2,赋值矩阵
			Matrix4d& Matrix4d::operator =(const Matrix4d& m2)
			{
				memcpy(this->m, m2.m, 16 * sizeof(double));
				return *this;
			}

			//! \brief 矩阵相乘。
			//! \param &m2 另外一个4X4矩阵[in]。
			//! \return 完成运算后4X4矩阵。
			Matrix4d Matrix4d::Concatenate(const Matrix4d& multiplyM2) const
			{
				Matrix4d tempMatrix;
				tempMatrix.m[0][0] = m[0][0] * multiplyM2.m[0][0] + m[0][1] * multiplyM2.m[1][0] + m[0][2] * multiplyM2.m[2][0] + m[0][3] * multiplyM2.m[3][0];
				tempMatrix.m[0][1] = m[0][0] * multiplyM2.m[0][1] + m[0][1] * multiplyM2.m[1][1] + m[0][2] * multiplyM2.m[2][1] + m[0][3] * multiplyM2.m[3][1];
				tempMatrix.m[0][2] = m[0][0] * multiplyM2.m[0][2] + m[0][1] * multiplyM2.m[1][2] + m[0][2] * multiplyM2.m[2][2] + m[0][3] * multiplyM2.m[3][2];
				tempMatrix.m[0][3] = m[0][0] * multiplyM2.m[0][3] + m[0][1] * multiplyM2.m[1][3] + m[0][2] * multiplyM2.m[2][3] + m[0][3] * multiplyM2.m[3][3];

				tempMatrix.m[1][0] = m[1][0] * multiplyM2.m[0][0] + m[1][1] * multiplyM2.m[1][0] + m[1][2] * multiplyM2.m[2][0] + m[1][3] * multiplyM2.m[3][0];
				tempMatrix.m[1][1] = m[1][0] * multiplyM2.m[0][1] + m[1][1] * multiplyM2.m[1][1] + m[1][2] * multiplyM2.m[2][1] + m[1][3] * multiplyM2.m[3][1];
				tempMatrix.m[1][2] = m[1][0] * multiplyM2.m[0][2] + m[1][1] * multiplyM2.m[1][2] + m[1][2] * multiplyM2.m[2][2] + m[1][3] * multiplyM2.m[3][2];
				tempMatrix.m[1][3] = m[1][0] * multiplyM2.m[0][3] + m[1][1] * multiplyM2.m[1][3] + m[1][2] * multiplyM2.m[2][3] + m[1][3] * multiplyM2.m[3][3];

				tempMatrix.m[2][0] = m[2][0] * multiplyM2.m[0][0] + m[2][1] * multiplyM2.m[1][0] + m[2][2] * multiplyM2.m[2][0] + m[2][3] * multiplyM2.m[3][0];
				tempMatrix.m[2][1] = m[2][0] * multiplyM2.m[0][1] + m[2][1] * multiplyM2.m[1][1] + m[2][2] * multiplyM2.m[2][1] + m[2][3] * multiplyM2.m[3][1];
				tempMatrix.m[2][2] = m[2][0] * multiplyM2.m[0][2] + m[2][1] * multiplyM2.m[1][2] + m[2][2] * multiplyM2.m[2][2] + m[2][3] * multiplyM2.m[3][2];
				tempMatrix.m[2][3] = m[2][0] * multiplyM2.m[0][3] + m[2][1] * multiplyM2.m[1][3] + m[2][2] * multiplyM2.m[2][3] + m[2][3] * multiplyM2.m[3][3];

				tempMatrix.m[3][0] = m[3][0] * multiplyM2.m[0][0] + m[3][1] * multiplyM2.m[1][0] + m[3][2] * multiplyM2.m[2][0] + m[3][3] * multiplyM2.m[3][0];
				tempMatrix.m[3][1] = m[3][0] * multiplyM2.m[0][1] + m[3][1] * multiplyM2.m[1][1] + m[3][2] * multiplyM2.m[2][1] + m[3][3] * multiplyM2.m[3][1];
				tempMatrix.m[3][2] = m[3][0] * multiplyM2.m[0][2] + m[3][1] * multiplyM2.m[1][2] + m[3][2] * multiplyM2.m[2][2] + m[3][3] * multiplyM2.m[3][2];
				tempMatrix.m[3][3] = m[3][0] * multiplyM2.m[0][3] + m[3][1] * multiplyM2.m[1][3] + m[3][2] * multiplyM2.m[2][3] + m[3][3] * multiplyM2.m[3][3];

				return tempMatrix;
			}

			//! \brief 重载[]，取出对应行。
			//! \param iRow 行号，有效范围为零到三[in]。
			//! \return 矩阵指定一行数据，返回行数据指针。
			double* Matrix4d::operator[] (int iRow)
			{
				return (double*)m[iRow];
			}

			//! \brief 应用缩放
			//! \param Scale 
			void Matrix4d::ApplyScale(double dScale)
			{
				m[0][0] *= dScale;
				m[0][1] *= dScale;
				m[0][2] *= dScale;

				m[1][0] *= dScale;
				m[1][1] *= dScale;
				m[1][2] *= dScale;

				m[2][0] *= dScale;
				m[2][1] *= dScale;
				m[2][2] *= dScale;

				m[3][0] *= dScale;
				m[3][1] *= dScale;
				m[3][2] *= dScale;
			}

			bool UGIS0(double x) {
				return (((x) < 1e-10) && ((x) > -1e-10));
			}

			//! \brief 判断两个矩阵是否相等。
			//! \param &m2 另外一个矩阵[in]。
			//! \return 若相等返回为TRUE，若不相等则返回为FALSE。
			bool Matrix4d::operator == (const Matrix4d& m2) const
			{
				return
					(
						UGIS0(m[0][0] - m2.m[0][0]) &&
						UGIS0(m[0][1] - m2.m[0][1]) &&
						UGIS0(m[0][2] - m2.m[0][2]) &&
						UGIS0(m[0][3] - m2.m[0][3]) &&
						UGIS0(m[1][0] - m2.m[1][0]) &&
						UGIS0(m[1][1] - m2.m[1][1]) &&
						UGIS0(m[1][2] - m2.m[1][2]) &&
						UGIS0(m[1][3] - m2.m[1][3]) &&
						UGIS0(m[2][0] - m2.m[2][0]) &&
						UGIS0(m[2][1] - m2.m[2][1]) &&
						UGIS0(m[2][2] - m2.m[2][2]) &&
						UGIS0(m[2][3] - m2.m[2][3]) &&
						UGIS0(m[3][0] - m2.m[3][0]) &&
						UGIS0(m[3][1] - m2.m[3][1]) &&
						UGIS0(m[3][2] - m2.m[3][2]) &&
						UGIS0(m[3][3] - m2.m[3][3])
						);
			}

			//! \brief 判断两个矩阵是否不相等。
			//! \param &m2 另外一个矩阵[in]。
			//! \return 若不相等返回为TRUE，否则返回FALSE。
			bool Matrix4d::operator != (const Matrix4d& m2) const
			{
				return
					!(
						UGIS0(m[0][0] - m2.m[0][0]) &&
						UGIS0(m[0][1] - m2.m[0][1]) &&
						UGIS0(m[0][2] - m2.m[0][2]) &&
						UGIS0(m[0][3] - m2.m[0][3]) &&
						UGIS0(m[1][0] - m2.m[1][0]) &&
						UGIS0(m[1][1] - m2.m[1][1]) &&
						UGIS0(m[1][2] - m2.m[1][2]) &&
						UGIS0(m[1][3] - m2.m[1][3]) &&
						UGIS0(m[2][0] - m2.m[2][0]) &&
						UGIS0(m[2][1] - m2.m[2][1]) &&
						UGIS0(m[2][2] - m2.m[2][2]) &&
						UGIS0(m[2][3] - m2.m[2][3]) &&
						UGIS0(m[3][0] - m2.m[3][0]) &&
						UGIS0(m[3][1] - m2.m[3][1]) &&
						UGIS0(m[3][2] - m2.m[3][2]) &&
						UGIS0(m[3][3] - m2.m[3][3])
						);
			}

			//! \brief 取出只读矩阵行数据。
			//! \param iRow 行号，有效范围为零到三[in]。
			//! \return 行数据。
			const double* const Matrix4d::operator [] (int iRow) const
			{
				return m[iRow];
			}

			double Matrix4d::operator () (int iRow, int iCol)
			{
				return m[iRow][iCol];
			}

			Matrix4d Matrix4d::Adjoint() const
			{
				//计算矩阵的伴随矩阵
				return Matrix4d(
					//计算4x4中任意3x3子矩阵行列式	
					MINOR(*this, 1, 2, 3, 1, 2, 3), -MINOR(*this, 0, 2, 3, 1, 2, 3), MINOR(*this, 0, 1, 3, 1, 2, 3), -MINOR(*this, 0, 1, 2, 1, 2, 3),
					//计算4x4中任意3x3子矩阵行列式	
					-MINOR(*this, 1, 2, 3, 0, 2, 3), MINOR(*this, 0, 2, 3, 0, 2, 3), -MINOR(*this, 0, 1, 3, 0, 2, 3), MINOR(*this, 0, 1, 2, 0, 2, 3),
					//计算4x4中任意3x3子矩阵行列式		
					MINOR(*this, 1, 2, 3, 0, 1, 3), -MINOR(*this, 0, 2, 3, 0, 1, 3), MINOR(*this, 0, 1, 3, 0, 1, 3), -MINOR(*this, 0, 1, 2, 0, 1, 3),
					//计算4x4中任意3x3子矩阵行列式		
					-MINOR(*this, 1, 2, 3, 0, 1, 2), MINOR(*this, 0, 2, 3, 0, 1, 2), -MINOR(*this, 0, 1, 3, 0, 1, 2), MINOR(*this, 0, 1, 2, 0, 1, 2));
			}
			double Matrix4d::Determinant() const
			{
				return m[0][0] * MINOR(*this, 1, 2, 3, 1, 2, 3) - m[0][1] * MINOR(*this, 1, 2, 3, 0, 2, 3) + m[0][2] * MINOR(*this, 1, 2, 3, 0, 1, 3) - m[0][3] * MINOR(*this, 1, 2, 3, 0, 1, 2);
			}

			double Matrix4d::MINOR(const Matrix4d& t, int r0, int r1, int r2, int c0, int c1, int c2) const
			{
				return t[r0][c0] * (t[r1][c1] * t[r2][c2] - t[r2][c1] * t[r1][c2]) -
					t[r0][c1] * (t[r1][c0] * t[r2][c2] - t[r2][c0] * t[r1][c2]) +
					t[r0][c2] * (t[r1][c0] * t[r2][c1] - t[r2][c0] * t[r1][c1]);
			}

			void Matrix4d::SetTrans(const Data::Vector3d& v)
			{
				m[3][0] = v.X;
				m[3][1] = v.Y;
				m[3][2] = v.Z;
			}

			Data::Vector3d Matrix4d::GetTrans() const
			{
				return Data::Vector3d(m[3][0], m[3][1], m[3][2]);
			}

			Data::Vector3d Matrix4d::GetScale() const
			{
				return Data::Vector3d(m[0][0], m[1][1], m[2][2]);
			}

			Matrix4d Matrix4d::Scaling(double x, double y, double z)
			{
				Matrix4d solution
				(
					x, 0, 0, 0,
					0, y, 0, 0,
					0, 0, z, 0,
					0, 0, 0, 1
				);

				return solution;
			}

			Matrix4d Matrix4d::Transpose() const
			{
				int i = 0, j = 0;
				Matrix4d Mat;
				for (i = 0; i < 4; i++)
					for (j = 0; j < 4; j++)
						Mat[i][j] = m[j][i];
				return Mat;
			}

			Matrix4d Matrix4d::Invert() const
			{
				return Adjoint() * (1.0f / Determinant());
			}

			void Matrix4d::ToFMatrix(const Matrix4d& srcMatrix, FMatrix& dstMatrix)
			{
				dstMatrix.M[0][0] = srcMatrix[0][0]; dstMatrix.M[0][1] = srcMatrix[0][1]; dstMatrix.M[0][2] = srcMatrix[0][2]; dstMatrix.M[0][3] = srcMatrix[0][3];
				dstMatrix.M[1][0] = srcMatrix[1][0]; dstMatrix.M[1][1] = srcMatrix[1][1]; dstMatrix.M[1][2] = srcMatrix[1][2]; dstMatrix.M[1][3] = srcMatrix[1][3];
				dstMatrix.M[2][0] = srcMatrix[2][0]; dstMatrix.M[2][1] = srcMatrix[2][1]; dstMatrix.M[2][2] = srcMatrix[2][2]; dstMatrix.M[2][3] = srcMatrix[2][3];
				dstMatrix.M[3][0] = srcMatrix[3][0]; dstMatrix.M[3][1] = srcMatrix[3][1]; dstMatrix.M[3][2] = srcMatrix[3][2]; dstMatrix.M[3][3] = srcMatrix[3][3];
			}

			void Matrix4d::ToDoublePointer(const Matrix4d& srcMatrix, double*& pOutDouble)
			{
				pOutDouble[0] = srcMatrix.m[0][0];
				pOutDouble[1] = srcMatrix.m[0][1];
				pOutDouble[2] = srcMatrix.m[0][2];
				pOutDouble[3] = srcMatrix.m[0][3];
				pOutDouble[4] = srcMatrix.m[1][0];
				pOutDouble[5] = srcMatrix.m[1][1];
				pOutDouble[6] = srcMatrix.m[1][2];
				pOutDouble[7] = srcMatrix.m[1][3];
				pOutDouble[8] = srcMatrix.m[2][0];
				pOutDouble[9] = srcMatrix.m[2][1];
				pOutDouble[10] = srcMatrix.m[2][2];
				pOutDouble[11] = srcMatrix.m[2][3];
				pOutDouble[12] = srcMatrix.m[3][0];
				pOutDouble[13] = srcMatrix.m[3][1];
				pOutDouble[14] = srcMatrix.m[3][2];
				pOutDouble[15] = srcMatrix.m[3][3];
			}
		}
	}
}