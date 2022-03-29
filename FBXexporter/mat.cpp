#include "mat.h"

float3 Multiply(matrix4x4 mat, float3 vec)
{
	float4 v;
	v.x = vec.x;
	v.y = vec.y;
	v.z = vec.z;
	v.a = 1.0f;

	float4 result;

	result.x = mat.m00 * v.x + mat.m01 * v.y * mat.m02 * v.z + mat.m03 * v.a;
	result.y = mat.m10 * v.x + mat.m11 * v.y * mat.m12 * v.z + mat.m13 * v.a;
	result.z = mat.m20 * v.x + mat.m21 * v.y * mat.m22 * v.z + mat.m23 * v.a;
	result.a = mat.m30 * v.x + mat.m31 * v.y * mat.m32 * v.z + mat.m33 * v.a;

	float3 res;
	res.x = result.x;
	res.y = result.y;
	res.z = result.z;
	return res;
}

matrix4x4 matAdd(matrix4x4 m1, matrix4x4 m2)
{
	matrix4x4 result;

	result.m00 = m1.m00 + m2.m00;
	result.m01 = m1.m01 + m2.m01;
	result.m02 = m1.m02 + m2.m02;
	result.m03 = m1.m03 + m2.m03;

	result.m10 = m1.m10 + m2.m10;
	result.m11 = m1.m11 + m2.m11;
	result.m12 = m1.m12 + m2.m12;
	result.m13 = m1.m13 + m2.m13;

	result.m20 = m1.m20 + m2.m20;
	result.m21 = m1.m21 + m2.m21;
	result.m22 = m1.m22 + m2.m22;
	result.m23 = m1.m23 + m2.m23;

	result.m30 = m1.m30 + m2.m30;
	result.m31 = m1.m31 + m2.m31;
	result.m32 = m1.m32 + m2.m32;
	result.m33 = m1.m33 + m2.m33;

	return result;
}

matrix4x4 matMul(matrix4x4 a, matrix4x4 b)
{
	matrix4x4 result;

	result.m00 = a.m00 * b.m00 + a.m01 * b.m10 + a.m02 * b.m20 + a.m03 * b.m30;
	result.m01 = a.m00 * b.m01 + a.m01 * b.m11 + a.m02 * b.m21 + a.m03 * b.m31;
	result.m02 = a.m00 * b.m02 + a.m01 * b.m12 + a.m02 * b.m22 + a.m03 * b.m32;
	result.m03 = a.m00 * b.m03 + a.m01 * b.m13 + a.m02 * b.m23 + a.m03 * b.m33;

	result.m10 = a.m10 * b.m00 + a.m11 * b.m10 + a.m12 * b.m20 + a.m13 * b.m30;
	result.m11 = a.m10 * b.m01 + a.m11 * b.m11 + a.m12 * b.m21 + a.m13 * b.m31;
	result.m12 = a.m10 * b.m02 + a.m11 * b.m12 + a.m12 * b.m22 + a.m13 * b.m32;
	result.m13 = a.m10 * b.m03 + a.m11 * b.m13 + a.m12 * b.m23 + a.m13 * b.m33;

	result.m20 = a.m20 * b.m00 + a.m21 * b.m10 + a.m22 * b.m20 + a.m23 * b.m30;
	result.m21 = a.m20 * b.m01 + a.m21 * b.m11 + a.m22 * b.m21 + a.m23 * b.m31;
	result.m22 = a.m20 * b.m02 + a.m21 * b.m12 + a.m22 * b.m22 + a.m23 * b.m32;
	result.m23 = a.m20 * b.m03 + a.m21 * b.m13 + a.m22 * b.m23 + a.m23 * b.m33;

	result.m30 = a.m30 * b.m00 + a.m31 * b.m10 + a.m32 * b.m20 + a.m33 * b.m30;
	result.m31 = a.m30 * b.m01 + a.m31 * b.m11 + a.m32 * b.m21 + a.m33 * b.m31;
	result.m32 = a.m30 * b.m02 + a.m31 * b.m12 + a.m32 * b.m22 + a.m33 * b.m32;
	result.m33 = a.m30 * b.m03 + a.m31 * b.m13 + a.m32 * b.m23 + a.m33 * b.m33;

	return result;
}

matrix4x4 matMulFloat(float f, matrix4x4 mat)
{
	matrix4x4 result;
	result.m00 = mat.m00 * f;
	result.m01 = mat.m01 * f;
	result.m02 = mat.m02 * f;
	result.m03 = mat.m03 * f;

	result.m10 = mat.m10 * f;
	result.m11 = mat.m11 * f;
	result.m12 = mat.m12 * f;
	result.m13 = mat.m13 * f;

	result.m20 = mat.m20 * f;
	result.m21 = mat.m21 * f;
	result.m22 = mat.m22 * f;
	result.m23 = mat.m23 * f;

	result.m30 = mat.m30 * f;
	result.m31 = mat.m31 * f;
	result.m32 = mat.m32 * f;
	result.m33 = mat.m33 * f;

	return result;
}