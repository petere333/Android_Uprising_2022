#include "Shaders.hlsl"

struct InterInput
{
	float3 position : POSITION;
	float2 uvs : UV;
};

struct InterOutput
{
	float4 position : SV_POSITION;
	float3 positionW : POSITION;
	float2 uvs : UV;
};

InterOutput vsInterface(InterInput input)
{
	InterOutput output;

	output.position = mul(mul(mul(float4(input.position, 1.0f), gmtxGameObject), gmtxView), gmtxProjection);
	output.positionW = (float3)(mul(float4(input.position, 1.0f), gmtxGameObject));
	output.uvs = input.uvs;
	return(output);
}

float4 psInterface(InterOutput input) : SV_TARGET
{
	//float4 color = tex.Sample(gSamplerState, input.uvs);
	float4 color = float4(1.0f,0.0f,0.0f,1.0f);
	return color;
}