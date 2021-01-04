#pragma once
#include <string>
#include "MathRoot.h"
#include "Math/Vector2.h"
#include "Math/Vector4.h"

namespace Reyadhah
{
	class Vector3
	{
	public:
		//Constructors =======================
		Vector3();
		Vector3(const Vector3& target);
		Vector3(float x, float y, float z);

		//Destructor =========================
		~Vector3(){}

		//Methods ============================
		void Normalize();
		//OrthoNormalize
		std::string ToString();
		//Vector2 ToVector2();
		//Vector4 ToVector4();

		//Static Methods =====================
		static float Angle(const Vector3& from, const Vector3& to);
		//ClampMagnitude
		static Vector3 Cross(const Vector3& leftHandSize, const Vector3& rightHandSide);
		static float Distance(const Vector3& a, const Vector3& b);
		static float Dot(const Vector3& leftHandSide, const Vector3& rightHandSide);
		static Vector3 Lerp(const Vector3& a, const Vector3& b, float t);
		//static Vector3 LerpUnclamped(const Vector3& a, const Vector3& b, float t);
		static Vector3 Maximum(const Vector3& leftHandSide, const Vector3& rightHandSide);
		static Vector3 Minimum(const Vector3& leftHandSide, const Vector3& rightHandSide);
		//MoveTowards
		//Project
		//ProjectOnPlane
		//Reflect
		//RotateTowards
		//Scale
		//SignedAngle
		//Slerp
		//SlerpUnclamped
		//SmoothDamp

		//Operators ==========================
		//Addition ---------------------------

		/// <summary>Used for adding two vectors</summary>
		Vector3 operator+(const Vector3& target);
		void operator+=(const Vector3& target);

		//Subtraction ------------------------
		Vector3 operator-(const Vector3& target);
		void operator-=(const Vector3& target);

		//Multiplication ---------------------
		Vector3 operator*(const Vector3& target);
		void operator*=(const Vector3& target);
		Vector3 operator*(const float value);
		void operator*=(const float value);

		//Division ---------------------------
		Vector3 operator/(const Vector3& target);
		void operator/=(const Vector3& target);
		Vector3 operator/(const float value);
		void operator/=(const float value);

		//Equality ---------------------------
		bool operator==(const Vector3& target);
		bool operator!=(const Vector3& target);

		//Assignment -------------------------
		Vector3 operator=(const Vector3& target);

		//Static Properties ==================
		static const Vector3 back;
		static const Vector3 forward;
		static const Vector3 down;
		static const Vector3 left;
		static const Vector3 right;
		static const Vector3 up;
		static const Vector3 one;
		static const Vector3 zero;

		//Properties =========================
		float x;
		float y;
		float z;
		float magnitude;
		float sqrMagnitude;
		Vector3 normalized() const;

		// Array approach to be added later

	private:
		void CalculateFields();
	};
}