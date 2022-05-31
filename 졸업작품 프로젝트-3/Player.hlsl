#include "Shaders.hlsl"

struct PlayerInput
{
	float3 position : POSITION;
	int4 indices : BONEINDEX;
	float4 weights : BONEWEIGHT;
	float2 uvs : UV;
};

struct PlayerOutput
{
	float4 position : SV_POSITION;
	float3 positionW : POSITION;
	float2 uvs : UV;
};

PlayerOutput vsPlayer(PlayerInput input)
{
	PlayerOutput output;

	output.positionW = float3(0.0f, 0.0f, 0.0f);
	matrix mtxVertexToBoneWorld;
	for (int i = 0; i < MAX_VERTEX_INFLUENCES; i++)
	{
		mtxVertexToBoneWorld = mul(gpmtxBoneOffsets[input.indices[i]], gpmtxBoneTransforms[input.indices[i]]);
		output.positionW += input.weights[i] * mul(float4(input.position, 1.0f), mtxVertexToBoneWorld).xyz;
	}

	output.position = mul(mul(float4(output.positionW, 1.0f), gmtxView), gmtxProjection);

	output.uvs = input.uvs;
	return(output);
}

float4 psPlayer(PlayerOutput input) : SV_TARGET
{
	float4 color = tex.Sample(gSamplerState, input.uvs);
	//float4 color = float4(0.0f,0.0f,0.0f,1.0f);
	float3 norm = normalize(float3(normTex.Sample(gSamplerState, input.uvs).rgb));

	float4 n = float4(norm, 1.0f);

	norm = 2.0f * norm - 1.0f;
	float4 cLight = Lighting(input.positionW, norm, input.uvs);

	return color * cLight;
}

