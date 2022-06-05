#include "Shaders.hlsl"

struct HealthInput
{
	float3 position : POSITION;
	float2 uvs : UV;
};

struct HealthOutput
{
	float4 position : SV_POSITION;
	float3 positionW : POSITION;
	float2 uvs : UV;
};

HealthOutput vsHealth(HealthInput input)
{
	HealthOutput output;

	output.position = mul(mul(mul(float4(input.position, 1.0f), gmtxGameObject), gmtxView), gmtxProjection);
	output.positionW = (float3)(mul(float4(input.position, 1.0f), gmtxGameObject));
	output.uvs = input.uvs;
	return(output);
}

float4 psHealth(HealthOutput input) : SV_TARGET
{
	float4 color = tex.Sample(gSamplerState, input.uvs);
	return color;
}