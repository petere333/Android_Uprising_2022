#include "Shaders.hlsl"

struct ParticleInput
{
	float3 position : POSITION;
	float2 uvs : UV;
};

struct ParticleOutput
{
	float4 position : SV_POSITION;
	float3 positionW : POSITION;
	float2 uvs : UV;
};

ParticleOutput vsParticle(ParticleInput input)
{
	ParticleOutput output;

	output.position = mul(mul(mul(float4(input.position, 1.0f), gmtxGameObject), gmtxView), gmtxProjection);
	output.positionW = (float3)(mul(float4(input.position, 1.0f), gmtxGameObject));
	output.uvs = input.uvs;
	return(output);
}

float4 psParticle(ParticleOutput input) : SV_TARGET
{
	float4 color = tex.Sample(gSamplerState, input.uvs);
	float3 norm = normalize(float3(normTex.Sample(gSamplerState, input.uvs).rgb));


	float4 n = float4(norm, 1.0f);

	norm = 2.0f * norm - 1.0f;

	float4 cLight = Lighting(input.positionW, norm, input.uvs);

	float4 result = color * cLight;
	//float4 result = color;
	//result.a = result.a*alpha;

	return result;
}