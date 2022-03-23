cbuffer cbCameraInfo : register(b1)
{
	matrix		gmtxView : packoffset(c0);
	matrix		gmtxProjection : packoffset(c4);
};

cbuffer cbGameObjectInfo : register(b2)
{
	matrix		gmtxGameObject : packoffset(c0);
};

//SamplerState gSamplerState : register(s0);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
struct VS_DIFFUSED_INPUT
{
	float3 position : POSITION;
	float4 color : COLOR;
};

struct VS_DIFFUSED_OUTPUT
{
	float4 position : SV_POSITION;
	float4 color : COLOR;
};

/**/
/*
VS_DIFFUSED_OUTPUT VSPlayer(VS_DIFFUSED_INPUT input)
{
	VS_DIFFUSED_OUTPUT output;

	output.position = mul(mul(mul(float4(input.position, 1.0f), gmtxPlayerWorld), gmtxView), gmtxProjection);
	output.color = input.color;

	return(output);
}

float4 PSPlayer(VS_DIFFUSED_OUTPUT input) : SV_TARGET
{
	return(input.color);
}
*/

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//


Texture2D gtxtTexture : register(t0);

SamplerState samp1 : register(s0);

struct VS_TEXTURED_INPUT
{
	float3 position : POSITION;
	float2 uv : TEXCOORD;
};

struct VS_TEXTURED_OUTPUT
{
	float4 position : SV_POSITION;
	float2 uv : TEXCOORD;
};

VS_TEXTURED_OUTPUT VSTextured(VS_TEXTURED_INPUT input)
{
	VS_TEXTURED_OUTPUT output;

	output.position = mul(mul(mul(float4(input.position, 1.0f), gmtxGameObject), gmtxView), gmtxProjection);
	output.uv = input.uv;

	return(output);
}

float4 PSTextured(VS_TEXTURED_OUTPUT input) : SV_TARGET
{
	float4 cColor = gtxtTexture.Sample(samp1, input.uv);

	return(cColor);
}

/////////////////////////////////////////

Texture2D billtex : register(t1);
cbuffer cbGameObjectInfoBill : register(b3)
{
	matrix		gmtxGameObjectBill : packoffset(c0);
};


VS_TEXTURED_OUTPUT VSBill(VS_TEXTURED_INPUT input)
{
	VS_TEXTURED_OUTPUT output;

	output.position = mul(mul(mul(float4(input.position, 1.0f), gmtxGameObjectBill), gmtxView), gmtxProjection);

	output.uv = input.uv;

	return(output);
}
float4 PSBill(VS_TEXTURED_OUTPUT input) : SV_TARGET
{
	float4 cColor = billtex.Sample(samp1, input.uv);

	

	return(cColor);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
struct VS_FBX_MODEL_INPUT
{
	float4 position : POSITION;
};

struct VS_FBX_MODEL_OUTPUT
{
	float4	position : SV_POSITION;
};

VS_FBX_MODEL_OUTPUT VSFbxModel(VS_FBX_MODEL_INPUT input)
{
	VS_FBX_MODEL_OUTPUT output;

	float4 positionW = mul(input.position, gmtxGameObject);
	output.position = mul(mul(positionW, gmtxView), gmtxProjection);

	return(output);
}

float4 PSFbxModel(VS_FBX_MODEL_OUTPUT input) : SV_TARGET
{
	float4 cColor = float4(1.0f, 0.0f, 0.0f, 1.0f);

	return(cColor);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
#define MAX_VERTEX_INFLUENCES			4
#define SKINNED_ANIMATION_BONES			128

cbuffer cbBoneOffsets : register(b6)
{
	float4x4 gpmtxBoneOffsets[SKINNED_ANIMATION_BONES];
};

cbuffer cbBoneTransforms : register(b7)
{
	float4x4 gpmtxBoneTransforms[SKINNED_ANIMATION_BONES];
};

struct VS_FBX_SKINNED_MODEL_INPUT
{
	float4 position : POSITION;
	uint4 indices : BONEINDEX;
	float4 weights : BONEWEIGHT;
	float2 uvs : UV;
};

struct VS_FBX_SKINNED_MODEL_OUTPUT
{
	float4	position : SV_POSITION;
	float2 uvs : UV;
};

VS_FBX_SKINNED_MODEL_OUTPUT VSFbxSkinnedModel(VS_FBX_SKINNED_MODEL_INPUT input)
{
	VS_FBX_SKINNED_MODEL_OUTPUT output;

	float4x4 mtxVertexToBoneWorld = (float4x4)0.0f;
	for (int i = 0; i < MAX_VERTEX_INFLUENCES; i++)
	{
		mtxVertexToBoneWorld += input.weights[i] * mul(gpmtxBoneOffsets[input.indices[i]], gpmtxBoneTransforms[input.indices[i]]);
	}
	float3 positionW = mul(input.position, mtxVertexToBoneWorld).xyz;
	output.position = mul(mul(float4(positionW, 1.0f), gmtxView), gmtxProjection);
	output.uvs = input.uvs;

	return(output);
}

float4 PSFbxSkinnedModel(VS_FBX_SKINNED_MODEL_OUTPUT input) : SV_TARGET
{
	//float4 cColor = float4(input.position.x / 500.0f, input.position.y / 500.0f, input.position.z/500.0f, 1.0f);
	float4 cColor = billtex.Sample(samp1, input.uvs);
	return(cColor);
}
