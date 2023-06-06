#pragma once

#include "Data/Vector3d.h"

//! \brief   4X4双精度矩阵类
//! \remarks 维护4X4矩阵
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{
			class SUPERMAP_API Matrix4d
			{

			public:

				//! \brief 缺省构造函数。
				Matrix4d();

				//! \brief 用16个浮点数构造矩阵类的构造函数。
				//! \param m00 [in]。
				//! \param m01 [in]。
				//! \param m02 [in]。
				//! \param m03 [in]。
				//! \param m10 [in]。
				//! \param m11 [in]。
				//! \param m12 [in]。
				//! \param m13 [in]。
				//! \param m20 [in]。
				//! \param m21 [in]。
				//! \param m22 [in]。
				//! \param m23 [in]。
				//! \param m30 [in]。
				//! \param m31 [in]。
				//! \param m32 [in]。
				//! \param m33 [in]。
				Matrix4d(
					double m00, double m01, double m02, double m03,
					double m10, double m11, double m12, double m13,
					double m20, double m21, double m22, double m23,
					double m30, double m31, double m32, double m33);

				//! \brief 数组初始化Matrix4d
				//! \param pMatrix [in] 
				Matrix4d(double * pMatrix);
				Matrix4d(float * pMatrix);

				//! \brief 用FMatrix初始化Matrix4d
				Matrix4d(FMatrix fMatrix);

				//! \brief 析构函数。
				virtual ~Matrix4d();

				//! \brief 重载*，矩阵与数值相乘。
				//! \param scalar 数值[in]。
				//! \return 运算完成后4x4矩阵。
				Matrix4d operator*(double scalar);

				//! \brief 重载*，完成矩阵与矩阵相乘。
				//! \param &m2 乘数矩阵[in]。
				//! \return 运算完成后矩阵。
				Matrix4d operator * (const Matrix4d& m2) const;

				//! \brief 重载=，完成矩阵的赋值
				//! \brief &m2,赋值矩阵	
				Matrix4d& operator = (const Matrix4d& m2);

				//! \brief 矩阵相乘。
				//! \param &m2 另外一个4X4矩阵[in]。
				//! \return 完成运算后4X4矩阵。
				Matrix4d Concatenate(const Matrix4d& m2) const;

				//! \brief 重载[]，取出对应行。
				//! \param iRow 行号，有效范围为零到三[in]。
				//! \return 矩阵指定一行数据，返回行数据指针。
				double* operator[] (int iRow);

				//! \brief 判断两个矩阵是否相等。
				//! \param &m2 另外一个矩阵[in]。
				//! \return 若相等返回为TRUE，若不相等则返回为FALSE。
				bool operator == (const Matrix4d& m2) const;

				//! \brief 判断两个矩阵是否不相等。
				//! \param &m2 另外一个矩阵[in]。
				//! \return 若不相等返回为TRUE，否则返回FALSE。
				bool operator != (const Matrix4d& m2) const;

				//! \brief 取出只读矩阵行数据。
				//! \param iRow 行号，有效范围为零到三[in]。
				//! \return 行数据。
				const double* const operator [] (int iRow) const;

				//! \brief 取出矩阵某行某列的值。
				//! \param iRow 行数[in]。
				//! \param iCol 列数[in]
				double operator () (int iRow, int iCol);

				//! \brief 计算矩阵的伴随矩阵。
				//! \return 矩阵的伴随矩阵。
				//! \remarks 。	
				Matrix4d Adjoint() const;

				//! \brief 计算矩阵行列式值。
				//! \return 行列式值。。
				double Determinant() const;

				//! \brief 计算机矩阵逆矩阵。
				//! \return 矩阵逆矩阵。
				Matrix4d Invert() const;

				//! \brief 计算4x4中任意3x3子矩阵行列式。
			//! \param m 4x4矩阵[in]。
			//! \param r0 第一行行号[in]。
			//! \param r1 第二行行号[in]。
			//! \param r2 第三行行号[in]。
			//! \param c0 第一列列号[in]。
			//! \param c1 第二列列号[in]。
			//! \param c2 第三列列号[in]。
				double MINOR(const Matrix4d& t, int r0, int r1, int r2,
					int c0, int c1, int c2) const;

				//! \brief 设置矩阵平移部分, [3][0], [3][1], [3][2]的值。
				//! \param v 平移向量[in]。
				void SetTrans(const Vector3d& v);

				//! \brief 获取矩阵平移部分, [3][0], [3][1], [3][2]的值。
				//! \param v 平移向量[in]。
				Vector3d GetTrans() const;

				Vector3d GetScale() const;
				
				//! \brief 构建一个缩放矩阵
				//! param x X轴缩放大小[in]。
				//! param y Y轴缩放大小[in]。
				//! param z Z轴缩放大小[in]。
				//! return 缩放矩阵。
				static Matrix4d Scaling(double x, double y, double z);

				//! \brief 计算机矩阵转置矩阵。
				//! \return 矩阵转置矩阵
				Matrix4d Transpose() const;

				//! \brief 缩放
				//! \params Scale [in]
				void ApplyScale(double dScale);

				//! \brief 4X4零矩阵
				//! \remarks 所有元素为零
				static const Matrix4d ZERO;
				//! \brief 4X4 单位矩阵
				//! \remarks 对角线元素为1，其他为0
				static const Matrix4d IDENTITY;

				//! \brief 用来交换XY轴的矩阵
				static const Matrix4d XY_REVERSE;

				//! \brief 矩阵转换
				//! \params srcMatrix [in]  原始矩阵
				//! \params dstMatrix [out] UE矩阵
				static void ToFMatrix(const Matrix4d& srcMatrix, FMatrix& dstMatrix);

				//! \brief 转换为double指针
				//! \params srcMatrix [in]  原始矩阵
				//! \params pOutDouble [out] 输出double数组
				static void ToDoublePointer(const Matrix4d& srcMatrix, double*& pOutDouble);
			protected:

				//! \brief 矩阵中数据
				//! \remarks 矩阵中数据保存在该变量中。
				double m[4][4];
			};
		}
	}
}