#pragma once

#include "common.h"

float3 Multiply(matrix4x4 mat, float3 vec);

matrix4x4 matAdd(matrix4x4 m1, matrix4x4 m2);

matrix4x4 matMul(matrix4x4 a, matrix4x4 b);

matrix4x4 matMulFloat(float f, matrix4x4 mat);