#pragma once
// Includes ===============================================================================
// From Other libraries -------------------------------------------------------------------
#include <string>
// In-project -----------------------------------------------------------------------------
#include "MathRoot.h"
#include "Math/Vector3.h"
#include "Math/Vector4.h"
// ========================================================================================

namespace Reyadhah
{
	class Vector2
	{
	public:
		// Constructors ===================================================================
		/// <summary>Constructs a Vector with (0.0f, 0.0f) values.</summary>
		Vector2();

		/// <summary>Constructs a Vector from another vector.</summary>
		/// <param name="vector">The vector to copy from.</param>
		Vector2(const Vector2& vector);

		/// <summary>Constructs a Vector with two float values.</summary>
		/// <param name="x">X component of the vector.</param>
		/// <param name="y">Y component of the vector.</param>
		Vector2(float x, float y);
		// ================================================================================

		//Destructor ======================================================================
		/// <summary>Destroys the vector.</summary>
		~Vector2() {}
		// ================================================================================

		//Methods =========================================================================
		/// <summary>Makes this vector have a magnitude of 1.</summary>
		void Normalize();

		/// <summary>Returns a formatted string for this vector.</summary>
		std::string ToString();

		//Vector3 ToVector3();
		//Vector4 ToVector4();
		// ================================================================================

		//Static Methods ==================================================================
		/// <summary>Returns the unsigned angle in degrees between from and to.</summary>
		/// <param name="from">The start vector.</param>
		/// <param name="to">The end vector.</param>
		static float Angle(const Vector2& from, const Vector2& to);

		/*
		/// <summary>Returns a copy of vector with its magnitude clamped to maxLength.</summary>
		/// <param name="target">The target vector.</param>
		/// <param name="maxLength">Length to be clamped to.</param>
		static Vector2 ClampMagnitude(const Vector2& target, float maxLength);
		*/

		/// <summary>Returns the distance between a and b.</summary>
		/// <param name="a">The first vector.</param>
		/// <param name="b">The second vector.</param>
		static float Distance(const Vector2& a, const Vector2& b);

		/// <summary>Dot Product of two vectors.</summary>
		/// <param name="leftHandSide">The left hand side vector.</param>
		/// <param name="rightHandSide">The right hand side vector.</param>
		static float Dot(const Vector2& leftHandSide, const Vector2& rightHandSide);

		/// <summary>Linearly interpolates between vectors a and b by t.</summary>
		/// <param name="a">The first vector.</param>
		/// <param name="b">The second vector.</param>
		/// <param name="t">Percentage of lerping. Must be between 0 and 1.</param>
		static Vector2 Lerp(const Vector2& a, const Vector2& b, float t);

		//static Vector2 LerpUnclamped(const Vector2& a, const Vector2& b, float t);

		/// <summary>Returns a vector that is made from the largest components of two vectors.</summary>
		/// <param name="leftHandSide">The left hand side vector.</param>
		/// <param name="rightHandSide">The right hand side vector.</param>
		static Vector2 Maximum(const Vector2& leftHandSide, const Vector2& rightHandSide);

		/// <summary>Returns a vector that is made from the smallest components of two vectors.</summary>
		/// <param name="leftHandSide">The left hand side vector.</param>
		/// <param name="rightHandSide">The right hand side vector.</param>
		static Vector2 Minimum(const Vector2& leftHandSide, const Vector2& rightHandSide);

		//MoveTowards
		//Perpendicular
		//Reflect
		//Scale
		//SignedAngle
		//SmoothDamp

		//Other methods to be added
		// ================================================================================

		//Operators =======================================================================
		//Addition ------------------------------------------------------------------------

		/// <summary>Adds two vectors.</summary>
		/// <param name="target">The target vector to be added to the original vector.</param>
		Vector2 operator+(const Vector2& target);

		/// <summary>Used for adding two vectors2 then put the output in the first one.</summary>
		/// <param name="target">The target vector to be added to the original vector.</param>
		void operator+=(const Vector2& target);

		//Subtraction ---------------------------------------------------------------------
		Vector2 operator-(const Vector2& target);
		void operator-=(const Vector2& target);

		//Multiplication ------------------------------------------------------------------
		Vector2 operator*(const Vector2& target);
		void operator*=(const Vector2& target);
		Vector2 operator*(const float value);
		void operator*=(const float value);

		//Division ------------------------------------------------------------------------
		Vector2 operator/(const Vector2& target);
		void operator/=(const Vector2& target);
		Vector2 operator/(const float value);
		void operator/=(const float value);

		//Equality ------------------------------------------------------------------------
		bool operator==(const Vector2& target);
		bool operator!=(const Vector2& target);

		//Assignment ----------------------------------------------------------------------
		Vector2 operator=(const Vector2& target);
		// ================================================================================

		//Static Properties ===============================================================
		static const Vector2 down;
		static const Vector2 left;
		static const Vector2 right;
		static const Vector2 up;
		static const Vector2 one;
		static const Vector2 zero;
		// ================================================================================

		//Properties ======================================================================
		float x;
		float y;
		float magnitude;
		float sqrMagnitude;
		Vector2 normalized() const;

		// Array approach to be added later
		// ================================================================================

	private:
		void CalculateFields();
	};
}