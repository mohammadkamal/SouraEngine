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

	inline double Cotan(float value) { return cos(value) / sin(value); }
	inline float CotanF(float value) { return cosf(value) / sinf(value); }
	constexpr float DegreesToRadians(const float degrees) { return degrees * DEGREE_TO_RADIAN; }
	constexpr float RadiansToDegrees(const float radians) { return radians * RADIAN_TO_DEGREE; }

	template <class T>
	constexpr T Abs(T value) { return value >= 0.0 ? value : -value; }

	template <class T>
	constexpr bool Equals(T leftHandSide, T rightHandSide, T error = std::numeric_limits<T>::epsilon()) { return leftHandSide + error >= rightHandSide && leftHandSide - error <= rightHandSide; }

	template <class T>
	constexpr T Maximum(T a, T b) { return a > b ? a : b; }

	template <class T>
	constexpr T Pow(T a, T b) { return pow(a, b); }

	template <class T>
	constexpr T SqRt(T target) { return sqrt(target); }
}