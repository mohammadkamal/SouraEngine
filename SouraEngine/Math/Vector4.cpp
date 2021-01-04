#include "Math/Vector4.h"

namespace Reyadhah
{
	Vector4::Vector4()
	{
		x = 0;
		y = 0;
		z = 0;
		w = 0;
		CalculateFields();
	}
	Vector4::Vector4(const Vector4 & target)
	{
		this->x = target.x;
		this->y = target.y;
		this->z = target.z;
		this->w = target.w;
		CalculateFields();
	}
	Vector4::Vector4(float x, float y, float z, float w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
		CalculateFields();
	}
	void Vector4::Normalize()
	{
		x /= magnitude;
		y /= magnitude;
		z /= magnitude;
		w /= magnitude;
		CalculateFields();
	}
	std::string Vector4::ToString()
	{
		char temp[200];
		sprintf_s(temp, "X:%f, Y:%f, Z:%f, W:%f", x, y, z, w);
		return std::string(temp);
	}
	/*Vector2 Vector4::ToVector2()
	{
		return Vector2(this->x, this->y);
	}
	Vector3 Vector4::ToVector3()
	{
		return Vector3(this->x, this->y, this->z);
	}*/
	float Vector4::Distance(const Vector4 & a, const Vector4 & b)
	{
		return sqrtf(powf(a.x - b.x, 2) + powf(a.y - b.y, 2) + powf(a.z - b.z, 2) + powf(a.w - b.w, 2));
	}
	float Vector4::Dot(const Vector4 & leftHandSide, const Vector4 & rightHandSide)
	{
		return leftHandSide.x * rightHandSide.x + leftHandSide.y * rightHandSide.y + leftHandSide.z * rightHandSide.z + leftHandSide.w * rightHandSide.w;
	}
	Vector4 Vector4::Lerp(const Vector4 & a, const Vector4 & b, float t)
	{
		return Vector4((1.0f - t) * a.x + t * b.x, (1.0f - t) * a.y + t * b.y, (1.0f - t) * a.z + t * b.z, (1.0f - t) * a.w + t * b.w);
	}
	Vector4 Vector4::Maximum(const Vector4 & leftHandSide, const Vector4 & rightHandSide)
	{
		float tempX = leftHandSide.x >= rightHandSide.x ? leftHandSide.x : rightHandSide.x;
		float tempY = leftHandSide.y >= rightHandSide.y ? leftHandSide.y : rightHandSide.y;
		float tempZ = leftHandSide.z >= rightHandSide.z ? leftHandSide.z : rightHandSide.z;
		float tempW = leftHandSide.w >= rightHandSide.w ? leftHandSide.w : rightHandSide.w;
		return Vector4(tempX, tempY, tempZ, tempW);
	}
	Vector4 Vector4::Minimum(const Vector4 & leftHandSide, const Vector4 & rightHandSide)
	{
		float tempX = leftHandSide.x <= rightHandSide.x ? leftHandSide.x : rightHandSide.x;
		float tempY = leftHandSide.y <= rightHandSide.y ? leftHandSide.y : rightHandSide.y;
		float tempZ = leftHandSide.z <= rightHandSide.z ? leftHandSide.z : rightHandSide.z;
		float tempW = leftHandSide.w <= rightHandSide.w ? leftHandSide.w : rightHandSide.w;
		return Vector4(tempX, tempY, tempZ, tempW);
	}
	Vector4 Vector4::operator+(const Vector4 & target)
	{
		return Vector4(this->x + target.x, this->y + target.y, this->z + target.z, this->w + target.w);
	}
	void Vector4::operator+=(const Vector4 & target)
	{
		this->x += target.x;
		this->y += target.y;
		this->z += target.z;
		this->w += target.w;
	}
	Vector4 Vector4::operator-(const Vector4 & target)
	{
		return Vector4(this->x - target.x, this->y - target.y, this->z - target.z, this->w - target.w);
	}
	void Vector4::operator-=(const Vector4 & target)
	{
		this->x -= target.x;
		this->y -= target.y;
		this->z -= target.z;
		this->w -= target.w;
	}
	Vector4 Vector4::operator*(const Vector4 & target)
	{
		return Vector4(this->x * target.x, this->y * target.y, this->z * target.z, this->w * target.w);
	}
	void Vector4::operator*=(const Vector4 & target)
	{
		this->x *= target.x;
		this->y *= target.y;
		this->z *= target.z;
		this->w *= target.w;
	}
	Vector4 Vector4::operator*(const float value)
	{
		return Vector4(this->x * value, this->y * value, this->z * value, this->w * value);
	}
	void Vector4::operator*=(const float value)
	{
		this->x *= value;
		this->y *= value;
		this->z *= value;
		this->w *= value;
	}
	Vector4 Vector4::operator/(const Vector4 & target)
	{
		return Vector4(this->x / target.x, this->y / target.y, this->z / target.z, this->w / target.w);
	}
	void Vector4::operator/=(const Vector4 & target)
	{
		this->x /= target.x;
		this->y /= target.y;
		this->z /= target.z;
		this->w /= target.w;
	}
	Vector4 Vector4::operator/(const float value)
	{
		return Vector4(this->x / value, this->y / value, this->z / value, this->w / value);
	}
	void Vector4::operator/=(const float value)
	{
		this->x /= value;
		this->y /= value;
		this->z /= value;
		this->w /= value;
	}
	bool Vector4::operator==(const Vector4 & target)
	{
		return this->x == target.x && this->y == target.y && this->z == target.z && this->w == target.w;
	}
	bool Vector4::operator!=(const Vector4 & target)
	{
		return this->x != target.x || this->y != target.y || this->z != target.z || this->w != target.w;
	}
	Vector4 Vector4::operator=(const Vector4 & target)
	{
		return Vector4(target.x, target.y, target.z, target.w);
	}
	Vector4 Vector4::normalized() const
	{
		return Vector4(this->x / magnitude, this->y / magnitude, this->z / magnitude, this->w / magnitude);
	}
	void Vector4::CalculateFields()
	{
		sqrMagnitude = powf(x, 2) + powf(y, 2) + powf(z, 2) + powf(w, 2);
		magnitude = sqrtf(sqrMagnitude);
	}
}