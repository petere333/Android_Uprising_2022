#pragma once

#include "Shaders.hlsl"

struct ShadowInput
{
	float3 position : POSITION;
	float2 uvs : UV;
};

struct ShadowOutput
{
	float4 position : SV_POSITION;
	float3 positionW : POSITION;
	float2 uvs : UV;
};

ShadowOutput vsShadow(ShadowInput input)
{
	ShadowOutput output;

	output.position = mul(mul(mul(float4(input.position, 1.0f), gmtxGameObject), gmtxView), gmtxProjection);
	output.positionW = (float3)(mul(float4(input.position, 1.0f), gmtxGameObject));
	output.uvs = input.uvs;
	return(output);
}

float4 psShadow(ShadowOutput input) : SV_TARGET
{
	float4 color = tex.Sample(gSamplerState, input.uvs);
	
	float4 result=color;
	
	if (color.x == 0.0f && color.y == 0.0f && color.z == 0.0f)
	{
		result.a = 0.5f;
	}
	else
	{
		result.a = 0.0f;
	}

	return result;
}