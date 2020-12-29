#pragma once
#include <string>
#include "MathRoot.h"
#include "Math/Vector3.h"
#include "Math/Vector4.h"

namespace Reyadhah
{
	class Vector2
	{
	public:
		//Constructors =======================
		Vector2();
		Vector2(const Vector2& vector);
		Vector2(float x, float y);
		
		//Destructor =========================
		~Vector2(){}

		//Methods ============================
		void Normalize();
		std::string ToString();
		//Vector3 ToVector3();
		//Vector4 ToVector4();

		//Static Methods =====================
		static float Angle(const Vector2& from, const Vector2& to);
		static float Distance(const Vector2& a, const Vector2& b);
		static float Dot(const Vector2& leftHandSide, const Vector2& rightHandSide);
		//Other methods to be added

		//Operators ==========================
		//Addition ---------------------------

		/// <summary>Used for adding two vectors</summary>
		Vector2 operator+(const Vector2& target);
		void operator+=(const Vector2& target);

		//Subtraction ------------------------
		Vector2 operator-(const Vector2& target);
		void operator-=(const Vector2& target);

		//Multiplication ---------------------
		Vector2 operator*(const Vector2& target);
		void operator*=(const Vector2& target);
		Vector2 operator*(const float value);
		void operator*=(const float value);

		//Division ---------------------------
		Vector2 operator/(const Vector2& target);
		void operator/=(const Vector2& target);
		Vector2 operator/(const float value);
		void operator/=(const float value);

		//Equality ---------------------------
		bool operator==(const Vector2& target);
		bool operator!=(const Vector2& target);

		//Assignment -------------------------
		Vector2 operator=(const Vector2& target);

		//Static Properties ==================
		static const Vector2 down;
		static const Vector2 left;
		static const Vector2 right;
		static const Vector2 up;
		static const Vector2 one;
		static const Vector2 zero;

		//Properties =========================
		float x;
		float y;
		float magnitude;
		float sqrMagnitude;
		Vector2 normalized() const;

		// Array approach to be added later

	private:
		void CalculateFields();
	};
}