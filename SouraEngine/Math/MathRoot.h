#pragma once
#include <cmath>
#include <limits>
#include "Math/Vector2.h"
#include "Math/Vector3.h"
#include "Math/Vector4.h"

namespace Reyadhah
{
	//Static Properties ======================================
	static const float PI = 3.14159265358979;
	static const float DEGREE_TO_RADIAN = PI / 180.0f;
	static const float RADIAN_TO_DEGREE = 180.0f / PI;
	static const float Infinity = std::numeric_limits<float>::infinity();
	static const float NegatvieInfinity = -Infinity;
	static const float EPSILON = std::numeric_limits<float>::epsilon();

	//Inline Methods =========================================

	inline double Acos(float value) { return acos(value); }
	inline float AcosF(float value) { return acosf(value); }
	inline double Asin(float value) { return asin(value); }
	inline float AsinF(float value) { return asinf(value); }
	inline double Atan(float value) { return atan(value); }
	inline float AtanF(float value) { return atanf(value); }
	
	inline double Cotan(float value) { return cos(value) / sin(value); }
	inline float CotanF(float value) { return cosf(value) / sinf(value); }
	constexpr float DegreesToRadians(const float degrees) { return degrees * DEGREE_TO_RADIAN; }
	constexpr float RadiansToDegrees(const float radians) { return radians * RADIAN_TO_DEGREE; }

	//Template Methods =======================================
	template <class T> constexpr T Abs(T value) { return value >= 0.0 ? value : -value; }

	template <class T> constexpr T Ceil(T value) { return ceil(value); }

	template <class T> constexpr T Clamp(T x, T a, T b) { return x < a ? a : (x > b ? b : x); }

	template <class T> constexpr bool Equals(T leftHandSide, T rightHandSide, T error = std::numeric_limits<T>::epsilon()) { return leftHandSide + error >= rightHandSide && leftHandSide - error <= rightHandSide; }

	template <class T, class U> constexpr T Lerp(T lhs, T rhs, U t) { return lhs * ((U)1.0 - t) + rhs * t; }

	template <class T> constexpr T Maximum(T a, T b) { return a > b ? a : b; }

	template <class T> constexpr T Minimum(T a, T b) { return a < b ? a : b; }

	template <class T> constexpr T Pow(T a, T b) { return pow(a, b); }

	template <class T> constexpr T SqRt(T target) { return sqrt(target); }
}