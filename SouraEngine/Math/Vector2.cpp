#include "Math/Vector2.h"

namespace Reyadhah
{
	const Vector2 Vector2::down(0.0f, -1.0f);
	const Vector2 Vector2::left(-1.0f, 0.0f);
	const Vector2 Vector2::right(1.0f, 0.0f);
	const Vector2 Vector2::up(0.0f, 1.0f);
	const Vector2 Vector2::one(1.0f, 1.0f);
	const Vector2 Vector2::zero(0.0f, 0.0f);
	
	Vector2::Vector2()
	{
		x = 0;
		y = 0;
		CalculateFields();
	}

	Vector2::Vector2(const Vector2 & vector)
	{
		this->x = vector.x;
		this->y = vector.y;
		CalculateFields();
	}

	Vector2::Vector2(float x, float y)
	{
		this->x = x;
		this->y = y;
		CalculateFields();
	}

	void Vector2::Normalize()
	{
		x /= magnitude;
		y /= magnitude;
		CalculateFields();
	}

	std::string Vector2::ToString()
	{
		char temp[200];
		sprintf_s(temp, "X:%f, Y:%f", x, y);
		return std::string(temp);
	}

	/*Vector3 Vector2::ToVector3()
	{
		return Vector3(this->x, this->y, 0.0f);
	}

	Vector4 Vector2::ToVector4()
	{
		return Vector4(this->x, this->y, 0.0f, 0.0f);
	}*/

	float Vector2::Angle(const Vector2 & from, const Vector2 & to)
	{
		return Dot(from, to) / (from.magnitude * to.magnitude);
	}

	float Vector2::Distance(const Vector2 & a, const Vector2 & b)
	{
		return sqrtf(powf(a.x - b.x, 2) + powf(a.y - b.y, 2));
	}

	float Vector2::Dot(const Vector2 & leftHandSide, const Vector2 & rightHandSide)
	{
		return leftHandSide.x * rightHandSide.x + leftHandSide.y * rightHandSide.y;
	}

	Vector2 Vector2::Lerp(const Vector2 & a, const Vector2 & b, float t)
	{
		return Vector2((1.0f - t) * a.x + t * b.x, (1.0f - t) * a.y + t * b.y);
	}

	Vector2 Vector2::Maximum(const Vector2 & leftHandSide, const Vector2 & rightHandSide)
	{
		float tempX = leftHandSide.x >= rightHandSide.x ? leftHandSide.x : rightHandSide.x;
		float tempY = leftHandSide.y >= rightHandSide.y ? leftHandSide.y : rightHandSide.y;
		return Vector2(tempX, tempY);
	}

	Vector2 Vector2::Minimum(const Vector2 & leftHandSide, const Vector2 & rightHandSide)
	{
		float tempX = leftHandSide.x <= rightHandSide.x ? leftHandSide.x : rightHandSide.x;
		float tempY = leftHandSide.y <= rightHandSide.y ? leftHandSide.y : rightHandSide.y;
		return Vector2(tempX, tempY);
	}

	Vector2 Vector2::operator+(const Vector2 & target)
	{
		return Vector2(this->x + target.x, this->y + target.y);
	}

	void Vector2::operator+=(const Vector2 & target)
	{
		this->x += target.x;
		this->y += target.y;
		CalculateFields();
	}

	void Vector2::operator++()
	{
		++this->x;
		++this->y;
		CalculateFields();
	}

	void Vector2::operator++(int)
	{
		this->x++;
		this->y++;
		CalculateFields();
	}

	Vector2 Vector2::operator-(const Vector2 & target)
	{
		return Vector2(this->x - target.x, this->y - target.y);
	}

	void Vector2::operator-=(const Vector2 & target)
	{
		this->x -= target.x;
		this->y -= target.y;
		CalculateFields();
	}

	void Vector2::operator--()
	{
		this->x--;
		this->y--;
		CalculateFields();
	}

	void Vector2::operator--(int)
	{
		--this->x;
		--this->y;
		CalculateFields();
	}

	Vector2 Vector2::operator*(const Vector2 & target)
	{
		return Vector2(this->x * target.x, this->y * target.y);
	}

	void Vector2::operator*=(const Vector2 & target)
	{
		this->x *= target.x;
		this->y *= target.y;
		CalculateFields();
	}

	Vector2 Vector2::operator*(const float value)
	{
		return Vector2(this->x * value, this->y * value);
	}

	void Vector2::operator*=(const float value)
	{
		this->x *= value;
		this->y *= value;
		CalculateFields();
	}

	Vector2 Vector2::operator/(const Vector2 & target)
	{
		return Vector2(this->x / target.x, this->y / target.y);
	}

	void Vector2::operator/=(const Vector2 & target)
	{
		this->x /= target.x;
		this->y /= target.y;
		CalculateFields();
	}

	Vector2 Vector2::operator/(const float value)
	{
		return Vector2(this->x / value, this->y / value);
	}

	void Vector2::operator/=(const float value)
	{
		this->x /= value;
		this->y /= value;
		CalculateFields();
	}

	bool Vector2::operator==(const Vector2 & target)
	{
		return this->x == target.x && this->y == target.y;
	}

	bool Vector2::operator!=(const Vector2 & target)
	{
		return this->x != target.x || this->y != target.y;
	}

	Vector2 Vector2::operator&&(const Vector2 & target)
	{
		return Vector2(this->x && target.x, this->y && target.y);
	}

	Vector2 Vector2::operator||(const Vector2 & target)
	{
		return Vector2(this->x || target.x, this->y || target.y);
	}

	Vector2 Vector2::operator=(const Vector2 & target)
	{
		return Vector2(this->x = target.x, this->y = target.y);
	}

	float Vector2::operator[](int index)
	{
		switch (index)
		{
		default:
		case 0:
			return x;
		case 1:
			return y;
		}
	}

	Vector2 Vector2::normalized() const
	{
		return Vector2(this->x / magnitude, this->y / magnitude);
	}

	void Vector2::CalculateFields()
	{
		sqrMagnitude = (x * x) + (y * y);
		magnitude = sqrtf(sqrMagnitude);
	}

}