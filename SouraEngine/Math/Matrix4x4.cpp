#include "Matrix4x4.h"

namespace Reyadhah
{
	Matrix4x4::Matrix4x4()
	{
		for (int i = 0; i < 4; i++)
		{
			vectors[i] = Vector4();
		}
	}
	Matrix4x4::Matrix4x4(float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13, float m20, float m21, float m22, float m23, float m30, float m31, float m32, float m33)
	{
		vectors[0] = Vector4(m00, m01, m02, m03);
		vectors[1] = Vector4(m10, m11, m12, m13);
		vectors[2] = Vector4(m20, m21, m22, m23);
		vectors[3] = Vector4(m30, m31, m32, m33);
	}
	Matrix4x4::Matrix4x4(Vector4 row1, Vector4 row2, Vector4 row3, Vector4 row4)
	{
		vectors[0] = row1;
		vectors[1] = row2;
		vectors[2] = row3;
		vectors[3] = row4;
	}
	Vector4 Matrix4x4::GetColumn(int index)
	{
		Vector4 temp = Vector4();
		switch (index)
		{
		case 0:
			temp = Vector4(vectors[0].x, vectors[1].x, vectors[2].x, vectors[3].x);
			break;
		case 1:
			temp = Vector4(vectors[0].y, vectors[1].y, vectors[2].y, vectors[3].y);
			break;
		case 2:
			temp = Vector4(vectors[0].z, vectors[1].z, vectors[2].z, vectors[3].z);
			break;
		case 3:
			temp = Vector4(vectors[0].w, vectors[1].w, vectors[2].w, vectors[3].w);
			break;
		default:
			break;
		}
		return temp;
	}
	Vector4 Matrix4x4::GetRow(int index)
	{
		return vectors[index];
	}
	void Matrix4x4::SetColumn(int index, const Vector4 & column)
	{
		switch (index)
		{
		case 0:
			vectors[0] = Vector4(column.x, vectors[0].y, vectors[0].z, vectors[0].w);
			vectors[1] = Vector4(column.y, vectors[1].y, vectors[1].z, vectors[1].w);
			vectors[2] = Vector4(column.z, vectors[2].y, vectors[2].z, vectors[2].w);
			vectors[3] = Vector4(column.w, vectors[3].y, vectors[3].z, vectors[3].w);
			break;
		case 1:
			vectors[0] = Vector4(vectors[0].x, column.x, vectors[0].z, vectors[0].w);
			vectors[1] = Vector4(vectors[1].x, column.y, vectors[1].z, vectors[1].w);
			vectors[2] = Vector4(vectors[2].x, column.z, vectors[2].z, vectors[2].w);
			vectors[3] = Vector4(vectors[3].x, column.w, vectors[3].z, vectors[3].w);
			break;
		case 2:
			vectors[0] = Vector4(vectors[0].x, vectors[0].y, column.x, vectors[0].w);
			vectors[1] = Vector4(vectors[1].x, vectors[1].y, column.y, vectors[1].w);
			vectors[2] = Vector4(vectors[2].x, vectors[2].y, column.z, vectors[2].w);
			vectors[3] = Vector4(vectors[3].x, vectors[3].y, column.w, vectors[3].w);
			break;
		case 3:
			vectors[0] = Vector4(vectors[0].x, vectors[0].y, vectors[0].z, column.x);
			vectors[1] = Vector4(vectors[1].x, vectors[1].y, vectors[1].z, column.y);
			vectors[2] = Vector4(vectors[2].x, vectors[2].y, vectors[2].z, column.z);
			vectors[3] = Vector4(vectors[3].x, vectors[3].y, vectors[3].z, column.w);
			break;
		default:
			break;
		}
	}
	void Matrix4x4::SetRow(int index, const Vector4 & row)
	{
		vectors[index] = row;
	}
	Vector4 Matrix4x4::operator[](int row)
	{
		return vectors[row];
	}
	Matrix4x4 Matrix4x4::operator+(const Matrix4x4 & target)
	{
		return Matrix4x4(
			
		);
	}
}