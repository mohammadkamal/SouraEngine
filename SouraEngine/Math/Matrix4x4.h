#pragma once
#include "MathRoot.h"

namespace Reyadhah
{
	class Matrix4x4
	{
	public:
		// Constructors ================================================================
		Matrix4x4();
		Matrix4x4(float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13, float m20, float m21, float m22, float m23, float m30, float m31, float m32, float m33);
		Matrix4x4(Vector4 row1, Vector4 row2, Vector4 row3, Vector4 row4);

		// Destructor ==================================================================
		~Matrix4x4(){}

		// Public Methods ==============================================================
		Vector4 GetColumn(int index);
		Vector4 GetRow(int index);
		void SetColumn(int index, const Vector4& column);
		void SetRow(int index, const Vector4& row);
		std::string ToString();

		// Static Methods ==============================================================
		static Matrix4x4 LookAt(const Vector3& from, const Vector3& to, const Vector3& up);
		static Matrix4x4 Ortho(float left, float right, float bottom, float top, float zNear, float zFar);
		static Matrix4x4 Perspective(float fieldOfView, float aspect, float zNear, float zFar);
		//Rotation
		//Scale

		//Operators =======================================================================
		//Addition ------------------------------------------------------------------------
		Matrix4x4 operator+(const Matrix4x4& target);
		void operator+=(const Matrix4x4& target);
		void operator++(); //prefix i.e: ++i
		void operator++(int); //postfix i.e: i++

		//Subtraction ---------------------------------------------------------------------
		Matrix4x4 operator-(const Matrix4x4& target);
		void operator-=(const Matrix4x4& target);
		void operator--(); //prefix i.e: --i
		void operator--(int); //postfix i.e: i--

		//Multiplication ------------------------------------------------------------------
		Matrix4x4 operator*(const Matrix4x4& target);
		void operator*=(const Matrix4x4& target);
		Matrix4x4 operator*(const float value);
		void operator*=(const float value);

		//Division ------------------------------------------------------------------------

		//Boolean -------------------------------------------------------------------------
		bool operator==(const Matrix4x4& target);
		bool operator!=(const Matrix4x4& target);

		//Logical -------------------------------------------------------------------------

		//Assignment ----------------------------------------------------------------------
		Matrix4x4 operator=(const Matrix4x4& target);

		//Array ---------------------------------------------------------------------------
		Vector4 operator[](int row);

		// Static Properties ===========================================================
		static const Matrix4x4 identity, zero;

		// Properties ==================================================================
		float determinant;
		Matrix4x4 inversed() const;
		bool isIdentity;
		Matrix4x4 transposed() const;

	private:
		Vector4 vectors[4];

	};
}