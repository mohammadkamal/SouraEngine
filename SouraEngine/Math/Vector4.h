#pragma once
#include <string>
#include "MathRoot.h"
#include "Math/Vector2.h"
#include "Math/Vector3.h"

namespace Reyadhah
{
	class Vector4
	{
	public:
		//Constructors =======================
		Vector4();
		Vector4(const Vector4& target);
		Vector4(float x, float y, float z, float w);

		//Destructor =========================
		~Vector4() {}

		//Methods ============================
		void Normalize();
		std::string ToString();
		//Vector2 ToVector2();
		//Vector3 ToVector3();

		//Static Methods =====================
		static float Distance(const Vector4& a, const Vector4& b);
		static float Dot(const Vector4& leftHandSide, const Vector4& rightHandSide);
		//Other methods to be added

		//Operators ==========================
		//Addition ---------------------------

		/// <summary>Used for adding two vectors</summary>
		Vector4 operator+(const Vector4& target);
		void operator+=(const Vector4& target);

		//Subtraction ------------------------
		Vector4 operator-(const Vector4& target);
		void operator-=(const Vector4& target);

		//Multiplication ---------------------
		Vector4 operator*(const Vector4& target);
		void operator*=(const Vector4& target);
		Vector4 operator*(const float value);
		void operator*=(const float value);

		//Division ---------------------------
		Vector4 operator/(const Vector4& target);
		void operator/=(const Vector4& target);
		Vector4 operator/(const float value);
		void operator/=(const float value);

		//Equality ---------------------------
		bool operator==(const Vector4& target);
		bool operator!=(const Vector4& target);

		//Assignment -------------------------
		Vector4 operator=(const Vector4& target);

		//Static Properties ==================
		static const Vector4 one;
		static const Vector4 zero;

		//Properties =========================
		float x;
		float y;
		float z;
		float w;
		float magnitude;
		float sqrMagnitude;
		Vector4 normalized() const;

		// Array approach to be added later

	private:
		void CalculateFields();
	};
}