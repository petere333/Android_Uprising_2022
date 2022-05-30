cbuffer cbCameraInfo : register(b1)
{
	matrix					gmtxView : packoffset(c0);
	matrix					gmtxProjection : packoffset(c4);
	float3					gvCameraPosition : packoffset(c8);
};

cbuffer cbGameObjectInfo : register(b2)
{
	matrix					gmtxGameObject : packoffset(c0);
	uint					matID : packoffset(c4);
};

cbuffer transparent : register(b6)
{
	float alpha : packoffset(c0);
}

#include "Light.hlsl"
Texture2D tex : register(t0);
Texture2D normTex : register(t1);


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
struct VS_WIREFRAME_INPUT
{
	float3 position : POSITION;
	float2 uvs : UV;
};

struct VS_WIREFRAME_OUTPUT
{
	float4 position : SV_POSITION;
	float3 positionW : POSITION;
	float2 uvs : UV;
};

VS_WIREFRAME_OUTPUT VSWireFrame(VS_WIREFRAME_INPUT input)
{
	VS_WIREFRAME_OUTPUT output;

	output.position = mul(mul(mul(float4(input.position, 1.0f), gmtxGameObject), gmtxView), gmtxProjection);
	output.positionW = (float3)(mul(float4(input.position, 1.0f), gmtxGameObject));
	output.uvs = input.uvs;
	return(output);
}

float4 PSWireFrame(VS_WIREFRAME_OUTPUT input) : SV_TARGET
{
	float4 color = tex.Sample(gSamplerState, input.uvs);
	float3 norm = normalize(float3(normTex.Sample(gSamplerState, input.uvs).rgb));

	
	float4 n = float4(norm, 1.0f);

	norm = 2.0f * norm - 1.0f;

	float4 cLight = Lighting(input.positionW, norm, input.uvs);

	float4 result = color * cLight;
	//result.a = result.a*alpha;

	return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
#define MAX_VERTEX_INFLUENCES			4
#define SKINNED_ANIMATION_BONES			128

cbuffer cbBoneOffsets : register(b7)
{
	float4x4 gpmtxBoneOffsets[SKINNED_ANIMATION_BONES];
};

cbuffer cbBoneTransforms : register(b8)
{
	float4x4 gpmtxBoneTransforms[SKINNED_ANIMATION_BONES];
};

struct VS_SKINNED_WIREFRAME_INPUT
{
	float3 position : POSITION;
	int4 indices : BONEINDEX;
	float4 weights : BONEWEIGHT;
	float2 uvs : UV;
};

struct VS_SKINNED_WIREFRAME_OUTPUT
{
	float4 position : SV_POSITION;
	float3 positionW : POSITION;
	float2 uvs : UV;
};

VS_SKINNED_WIREFRAME_OUTPUT VSSkinnedAnimationWireFrame(VS_SKINNED_WIREFRAME_INPUT input)
{
	VS_SKINNED_WIREFRAME_OUTPUT output;

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

float4 PSSkinnedAnimationWireFrame(VS_SKINNED_WIREFRAME_OUTPUT input) : SV_TARGET
{
	float4 color = tex.Sample(gSamplerState, input.uvs);
	float3 norm = normalize(float3(normTex.Sample(gSamplerState, input.uvs).rgb));
	
	float4 n = float4(norm, 1.0f);

	norm = 2.0f * norm - 1.0f;
	float4 cLight = Lighting(input.positionW, norm, input.uvs);

	return color*cLight;
}


