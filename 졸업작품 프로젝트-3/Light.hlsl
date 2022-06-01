//--------------------------------------------------------------------------------------
#define MAX_LIGHTS			16 
#define MAX_MATERIALS		512 

#define POINT_LIGHT			1
#define SPOT_LIGHT			2
#define DIRECTIONAL_LIGHT	3

#define _WITH_LOCAL_VIEWER_HIGHLIGHTING
#define _WITH_THETA_PHI_CONES
//#define _WITH_REFLECT

Texture2D specTex : register(t2);

SamplerState gSamplerState : register(s0);

struct LIGHT
{
	float4					m_cAmbient;
	float4					m_cDiffuse;
	float4					m_cSpecular;
	float3					m_vPosition;
	float 					m_fFalloff;
	float3					m_vDirection;
	float 					m_fTheta; //cos(m_fTheta)
	float3					m_vAttenuation;
	float					m_fPhi; //cos(m_fPhi)
	bool					m_bEnable;
	int 					m_nType;
	float					m_fRange;
	float					padding;
};

struct MATERIAL
{
	float4				m_cAmbient;
	float4				m_cDiffuse;
	float4				m_cSpecular; //a = power
	float4				m_cEmissive;
};

cbuffer cbLights : register(b4)
{
	LIGHT					gLights[MAX_LIGHTS];
	float4					gcGlobalAmbientLight;
	int						gnLights;
};

cbuffer cbMaterial : register(b3)
{
	MATERIAL			gMaterials[8];
};

float4 DirectionalLight(int nIndex, float3 vNormal, float3 vToCamera, float2 uv)
{
	
	float3 vToLight = -gLights[nIndex].m_vDirection;
	float fDiffuseFactor = dot(vToLight, vNormal);
	float fSpecularFactor = 0.0f;
	if (fDiffuseFactor > 0.0f)
	{
		if (gMaterials[0].m_cSpecular.a != 0.0f)
		{
#ifdef _WITH_REFLECT
			float3 vReflect = reflect(-vToLight, vNormal);
			//fSpecularFactor = pow(max(dot(vReflect, vToCamera), 0.0f), gMaterials[0].m_cSpecular.a);
			fSpecularFactor = pow(max(dot(vReflect, vToCamera), 0.0f), 20.0f);
#else
#ifdef _WITH_LOCAL_VIEWER_HIGHLIGHTING
			float3 vHalf = normalize(vToCamera + vToLight);
#else
			float3 vHalf = float3(0.0f, 1.0f, 0.0f);
#endif
			//fSpecularFactor = pow(max(dot(vHalf, vNormal), 0.0f), gMaterials[0].m_cSpecular.a);
			fSpecularFactor = pow(max(dot(vHalf, vNormal), 0.0f), 20.0f);
#endif
		}
	}
	
	float4 result = ((gLights[nIndex].m_cAmbient * gMaterials[0].m_cAmbient) + (gLights[nIndex].m_cDiffuse * fDiffuseFactor * gMaterials[0].m_cDiffuse) + (gLights[nIndex].m_cSpecular * fSpecularFactor * float4(0.0f,0.0f,0.0f,0.0f)));
	float rx = result.x;
	float ry = result.y;
	float rz = result.z;
	float ra = result.z;
	float weight = specTex.Sample(gSamplerState, uv).x * 2.0f - 1.0f;

	if (weight <= 0.0f)
	{
		rx = rx + rx * weight;
		ry = ry + ry * weight;
		rz = rz + rz * weight;
	}
	else
	{
		rx = rx + (1.0 - rx) * weight;
		ry = ry + (1.0 - ry) * weight;
		rz = rz + (1.0 - rz) * weight;
	}

	return float4(rx, ry, rz, 1.0f);
	//return((gLights[nIndex].m_cAmbient * gMaterials[0].m_cAmbient) + (gLights[nIndex].m_cDiffuse * fDiffuseFactor * gMaterials[0].m_cDiffuse) + (gLights[nIndex].m_cSpecular * fSpecularFactor * specTex.Sample(gSamplerState, uv)));
	
	
}

float4 PointLight(int nIndex, float3 vPosition, float3 vNormal, float3 vToCamera, float2 uv)
{
	float3 vToLight = gLights[nIndex].m_vPosition - vPosition;
	float fDistance = length(vToLight);
	if (fDistance <= gLights[nIndex].m_fRange)
	{
		float fSpecularFactor = 0.0f;
		vToLight /= fDistance;
		float fDiffuseFactor = dot(vToLight, vNormal);
		if (fDiffuseFactor > 0.0f)
		{
			if (gMaterials[0].m_cSpecular.a != 0.0f)
			{
#ifdef _WITH_REFLECT
				float3 vReflect = reflect(-vToLight, vNormal);
				//fSpecularFactor = pow(max(dot(vReflect, vToCamera), 0.0f), gMaterials[0].m_cSpecular.a);
				fSpecularFactor = pow(max(dot(vReflect, vToCamera), 0.0f), 20.0f);
#else
#ifdef _WITH_LOCAL_VIEWER_HIGHLIGHTING
				float3 vHalf = normalize(vToCamera + vToLight);
#else
				float3 vHalf = float3(0.0f, 1.0f, 0.0f);
#endif
				//fSpecularFactor = pow(max(dot(vHalf, vNormal), 0.0f), gMaterials[0].m_cSpecular.a);
				fSpecularFactor = pow(max(dot(vHalf, vNormal), 0.0f), 20.0f);
#endif
			}
		}
		float fAttenuationFactor = 1.0f / dot(gLights[nIndex].m_vAttenuation, float3(1.0f, fDistance, fDistance*fDistance));

		//return(((gLights[nIndex].m_cAmbient * gMaterials[0].m_cAmbient) + (gLights[nIndex].m_cDiffuse * fDiffuseFactor * gMaterials[0].m_cDiffuse) + (gLights[nIndex].m_cSpecular * fSpecularFactor * gMaterials[0].m_cSpecular)) * fAttenuationFactor);
		return(((gLights[nIndex].m_cAmbient * gMaterials[0].m_cAmbient) + (gLights[nIndex].m_cDiffuse * fDiffuseFactor * gMaterials[0].m_cDiffuse) + (gLights[nIndex].m_cSpecular * fSpecularFactor * specTex.Sample(gSamplerState, uv))) * fAttenuationFactor);
	}
	return(float4(0.0f, 0.0f, 0.0f, 0.0f));
}

float4 SpotLight(int nIndex, float3 vPosition, float3 vNormal, float3 vToCamera, float2 uv)
{
	float3 vToLight = gLights[nIndex].m_vPosition - vPosition;
	float fDistance = length(vToLight);
	float cosAngle = dot(normalize(-vToLight), gLights[nIndex].m_vDirection);

	if (fDistance <= gLights[nIndex].m_fRange  && cosAngle <=1.0f && cosAngle>=cos(3.141592f/180.0f *20.0f))
	{
		float fSpecularFactor = 0.0f;
		vToLight /= fDistance;
		float fDiffuseFactor = dot(vToLight, vNormal);
		if (fDiffuseFactor > 0.0f)
		{
			if (gMaterials[0].m_cSpecular.a != 0.0f)
			{
#ifdef _WITH_REFLECT
				float3 vReflect = reflect(-vToLight, vNormal);
				//fSpecularFactor = pow(max(dot(vReflect, vToCamera), 0.0f), gMaterials[0].m_cSpecular.a);
				fSpecularFactor = pow(max(dot(vReflect, vToCamera), 0.0f), 20.0f);
#else
#ifdef _WITH_LOCAL_VIEWER_HIGHLIGHTING
				float3 vHalf = normalize(vToCamera + vToLight);
#else
				float3 vHalf = float3(0.0f, 1.0f, 0.0f);
#endif
				//fSpecularFactor = pow(max(dot(vHalf, vNormal), 0.0f), gMaterials[0].m_cSpecular.a);
				fSpecularFactor = pow(max(dot(vHalf, vNormal), 0.0f), 20.0f);
#endif
			}
		}
#ifdef _WITH_THETA_PHI_CONES
		float fAlpha = max(dot(-vToLight, gLights[nIndex].m_vDirection), 0.0f);
		float fSpotFactor = pow(max(((fAlpha - gLights[nIndex].m_fPhi) / (gLights[nIndex].m_fTheta - gLights[nIndex].m_fPhi)), 0.0f), gLights[nIndex].m_fFalloff);
#else
		float fSpotFactor = pow(max(dot(-vToLight, gLights[i].m_vDirection), 0.0f), gLights[i].m_fFalloff);
#endif
		float fAttenuationFactor = 1.0f / dot(gLights[nIndex].m_vAttenuation, float3(1.0f, fDistance, fDistance*fDistance));
		
		float4 result = ((gLights[nIndex].m_cAmbient * gMaterials[0].m_cAmbient) + (gLights[nIndex].m_cDiffuse * fDiffuseFactor * gMaterials[0].m_cDiffuse)+(gLights[nIndex].m_cSpecular * fSpecularFactor * float4(0.0f,0.0f,0.0f,1.0f))) * fAttenuationFactor * fSpotFactor;

		float rx = result.x;
		float ry = result.y;
		float rz = result.z;
		float ra = result.z;
		float weight = specTex.Sample(gSamplerState, uv).x * 2.0f - 1.0f;

		if (weight <= 0.0f)
		{
			rx = rx + rx * weight;
			ry = ry + ry * weight;
			rz = rz + rz * weight;
		}
		else
		{
			rx = rx + (1.0 - rx) * weight;
			ry = ry + (1.0 - ry) * weight;
			rz = rz + (1.0 - rz) * weight;
		}
		

		return float4(rx, ry, rz, ra);
		//return(((gLights[nIndex].m_cAmbient * gMaterials[0].m_cAmbient) + (gLights[nIndex].m_cDiffuse * fDiffuseFactor * gMaterials[0].m_cDiffuse) + (gLights[nIndex].m_cSpecular * fSpecularFactor * float4(0.0f,0.0f,0.0f,1.0f))) * fAttenuationFactor * fSpotFactor);
		//return(((gLights[nIndex].m_cAmbient * gMaterials[0].m_cAmbient) + (gLights[nIndex].m_cDiffuse * fDiffuseFactor * gMaterials[0].m_cDiffuse) + (gLights[nIndex].m_cSpecular * fSpecularFactor * specTex.Sample(gSamplerState, uv))) * fAttenuationFactor * fSpotFactor);
	}
	return(float4(0.0f, 0.0f, 0.0f, 0.0f));
}

float4 Lighting(float3 vPosition, float3 vNormal, float2 uv)
{
	float3 vCameraPosition = float3(gvCameraPosition.x, gvCameraPosition.y, gvCameraPosition.z);
	float3 vToCamera = normalize(vCameraPosition - vPosition);

	float4 cColor = float4(0.0f, 0.0f, 0.0f, 0.0f);



	[unroll(MAX_LIGHTS)] for (int i = 0; i < gnLights; i++)
	{
		if (gLights[i].m_bEnable)
		{
			if (gLights[i].m_nType == DIRECTIONAL_LIGHT)
			{
				cColor += DirectionalLight(i, vNormal, vToCamera, uv);
			}
			else if (gLights[i].m_nType == POINT_LIGHT)
			{
				cColor += PointLight(i, vPosition, vNormal, vToCamera, uv);
			}
			else if (gLights[i].m_nType == SPOT_LIGHT)
			{
				cColor += SpotLight(i, vPosition, vNormal, vToCamera, uv);
			}
		}
	}
	cColor += (gcGlobalAmbientLight * gMaterials[0].m_cAmbient);
	cColor.a = gMaterials[0].m_cDiffuse.a;

	return(cColor);
}

