#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <fbxsdk.h>
#include <vector>


#pragma comment(lib, "libfbxsdk-md.lib")
#pragma comment(lib, "libxml2-md.lib")
#pragma comment(lib, "zlib-md.lib")

typedef struct float2
{
	float x, y;
}float2;

typedef struct float3
{
	float x, y, z;
}float3;

typedef struct float4
{
	float x, y, z, a;
}float4;

typedef struct int4
{
	int x, y, z, a;
}int4;


typedef struct VertexUV
{
	float3 position;
	float2 uv;
};

typedef struct AnimationData
{
	long start;
	long end;
};

typedef struct matrix4x4
{
	float m00, m01, m02, m03,
		m10, m11, m12, m13,
		m20, m21, m22, m23,
		m30, m31, m32, m33;
}matrix4x4;