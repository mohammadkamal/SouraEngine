#include "Math/Vector3.h"

namespace Reyadhah
{
	const Vector3 Vector3::back(0.0f, 0.0f, -1.0f);
	const Vector3 Vector3::forward(0.0f, 0.0f, 1.0f);
	const Vector3 Vector3::down(0.0f, -1.0f, 0.0f);
	const Vector3 Vector3::left(-1.0f, 0.0f, 0.0f);
	const Vector3 Vector3::right(1.0f, 0.0f, 0.0f);
	const Vector3 Vector3::up(0.0f, 1.0f, 0.0f);
	const Vector3 Vector3::one(1.0f, 1.0f, 1.0f);
	const Vector3 Vector3::zero(0.0f, 0.0f, 0.0f);

	Vector3::Vector3()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
		CalculateFields();
	}
	Vector3::Vector3(const Vector3 & target)
	{
		this->x = target.x;
		this->y = target.y;
		this->z = target.z;
		CalculateFields();
	}
	Vector3::Vector3(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		CalculateFields();
	}
	void Vector3::Normalize()
	{
		x /= magnitude;
		y /= magnitude;
		z /= magnitude;
		CalculateFields();
	}
	std::string Vector3::ToString()
	{
		char temp[200];
		sprintf_s(temp, "X:%f, Y:%f, Z:%f", x, y, z);
		return std::string(temp);
	}
	/*Vector2 Vector3::ToVector2()
	{
		return Vector2(this->x, this->y);
	}
	Vector4 Vector3::ToVector4()
	{
		return Vector4(this->x, this->y, this->z, 0.0f);
	}*/
	float Vector3::Angle(const Vector3 & from, const Vector3 & to)
	{
		return Dot(from, to) / (from.magnitude * to.magnitude);
	}
	Vector3 Vector3::Cross(const Vector3 & leftHandSize, const Vector3 & rightHandSide)
	{
		return Vector3(
			leftHandSize.y * rightHandSide.z - leftHandSize.z * rightHandSide.y,
			leftHandSize.z * rightHandSide.x - leftHandSize.x * rightHandSide.z,
			leftHandSize.x * rightHandSide.y - leftHandSize.y * rightHandSide.x
		);
	}
	float Vector3::Distance(const Vector3 & a, const Vector3 & b)
	{
		return sqrtf(powf(a.x - b.x, 2) + powf(a.y - b.y, 2) + powf(a.z - b.z, 2));
	}
	float Vector3::Dot(const Vector3 & leftHandSide, const Vector3 & rightHandSide)
	{
		return leftHandSide.x * rightHandSide.x + leftHandSide.y * rightHandSide.y + leftHandSide.z * rightHandSide.z;
	}
	Vector3 Vector3::operator+(const Vector3 & target)
	{
		return Vector3(this->x + target.x, this->y + target.y, this->z + target.z);
	}
	void Vector3::operator+=(const Vector3 & target)
	{
		this->x += target.x;
		this->y += target.y;
		this->z += target.z;
	}
	Vector3 Vector3::operator-(const Vector3 & target)
	{
		return Vector3(this->x - target.x, this->y - target.y, this->z - target.z);
	}
	void Vector3::operator-=(const Vector3 & target)
	{
		this->x -= target.x;
		this->y -= target.y;
		this->z -= target.z;
	}
	Vector3 Vector3::operator*(const Vector3 & target)
	{
		return Vector3(this->x * target.x, this->y * target.y, this->z * target.z);
	}
	void Vector3::operator*=(const Vector3 & target)
	{
		this->x *= target.x;
		this->y *= target.y;
		this->z *= target.z;
	}
	Vector3 Vector3::operator*(const float value)
	{
		return Vector3(this->x * value, this->y * value, this->z * value);
	}
	void Vector3::operator*=(const float value)
	{
		this->x *= value;
		this->y *= value;
		this->z *= value;
	}
	Vector3 Vector3::operator/(const Vector3 & target)
	{
		return Vector3(this->x / target.x, this->y / target.y, this->z / target.z);
	}
	void Vector3::operator/=(const Vector3 & target)
	{
		this->x /= target.x;
		this->y /= target.y;
		this->z /= target.z;
	}
	Vector3 Vector3::operator/(const float value)
	{
		return Vector3(this->x / value, this->y / value, this->z / value);
	}
	void Vector3::operator/=(const float value)
	{
		this->x /= value;
		this->y /= value;
		this->z /= value;
	}
	bool Vector3::operator==(const Vector3 & target)
	{
		return this->x == target.x && this->y == target.y && this->z == target.z;
	}
	bool Vector3::operator!=(const Vector3 & target)
	{
		return this->x != target.x || this->y != target.y || this->z != target.z;;
	}
	Vector3 Vector3::operator=(const Vector3 & target)
	{
		return Vector3(this->x = target.x, this->y = target.y, this->z = target.z);
	}
	Vector3 Vector3::normalized() const
	{
		return Vector3(this->x / magnitude, this->y / magnitude, this->z / magnitude);
	}
	void Vector3::CalculateFields()
	{
		sqrMagnitude = powf(x, 2) + powf(y, 2) + powf(z, 2);
		magnitude = sqrtf(sqrMagnitude);
	}
}