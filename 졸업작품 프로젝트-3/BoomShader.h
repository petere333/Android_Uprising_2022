#pragma once
#pragma once
#pragma once

#include "Shader.h"
#include "ResourceManager.h"
#include "LevelLoader.h"
#include "ParticleShader.h"
#include "EnemyShader.h"
#include "InterfaceShader.h"
#include "CNet.h"
class BoomShader : public CShader
{
public:
	BoomShader(ResourceManager* r, ParticleShader* p, EnemyShader* e);
	virtual ~BoomShader();

	virtual void BuildObjects(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList);
	virtual void ReleaseObjects();
	virtual void ReleaseUploadBuffers();
	virtual void ReleaseShaderVariables();
	virtual void Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera);

	virtual D3D12_INPUT_LAYOUT_DESC CreateInputLayout();
	virtual D3D12_RASTERIZER_DESC CreateRasterizerState();

	virtual D3D12_SHADER_BYTECODE CreateVertexShader();
	virtual D3D12_SHADER_BYTECODE CreatePixelShader();


public:

	CLoadedMesh* boomMesh = NULL;

	ParticleShader* part;
	EnemyShader* enemy;
	std::vector<BoomObject*>	objects;

	ResourceManager* rm;

	void animate(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList, ParticleShader* part, PlayerShader* pl, InterfaceShader* interShader, int pid)
	{
		for (int i = 0; i < objects.size(); ++i)
		{
			bool erased = false;
			chrono::time_point<chrono::system_clock> moment = chrono::system_clock::now();
			chrono::duration<double> dt = moment - objects[i]->created;

			//생성된지 1초가 지났거나, 그사이에 물체 혹은 적에게 박힌 경우 객체 제거.

			
				float tx = objects[i]->origin.x + objects[i]->direction.x * objects[i]->speed * (float)dt.count();
				float tz = objects[i]->origin.z + objects[i]->direction.z * objects[i]->speed * (float)dt.count();

				int ix, iz;
				if (tx > 0.0f && tx < 200.0f && tz>0.0f && tz < 200.0f)
				{
					ix = (int)(tx / 0.5f);
					iz = (int)(tz / 0.5f);

					//높이맵에서의 높이가 더 높은경우, 즉 물체 옆면에 충돌한 경우
					if (enemy->height11[ix][iz] >= objects[i]->origin.y)
					{
						if (objects[i]->owner == pid)
						{
							CS_PARTICLE_PACKET p;
							p.size = sizeof(CS_PARTICLE_PACKET);
							p.type = PACKET_TYPE::CS_PARTICLE;
							p.id = pid;
							p.particleType = 1;
							p.count = 100;
							p.x = objects[i]->GetPosition().x;
							p.y = objects[i]->GetPosition().y;
							p.z = objects[i]->GetPosition().z;

							SendPacket(&p);
						}
						// 폭발 반경 인근의 적들에게 피해
						for (int k = 0; k < enemy->objects.size(); ++k)
						{
							XMFLOAT3 op = objects[i]->GetPosition();
							XMFLOAT3 enp = enemy->objects[k]->GetPosition();

							if (Vector3::Length(XMFLOAT3(op.x - enp.x, 0.0f, op.z - enp.z)) <= 1.0f)
							{


								
								if (objects[i]->owner == pid)
								{
									CS_ATTACK_PACKET ap;
									ap.size = sizeof(CS_ATTACK_PACKET);
									ap.type = PACKET_TYPE::CS_ATTACK;
									ap.id = 1;
									ap.target = i;
									ap.damage = pl->objects[k]->info->getMeleeDamage() * pl->objects[k]->amp_melee;
									ap.stuntime = 1.0f;

									SendPacket(&ap);
								}

							}
						}

						//delete objects[i];
						objects.erase(objects.begin() + i);
						erased = true;
					}

					//물체랑은 충돌하지 않았지만 적과 박은 경우
					else
					{

						for (int k = 0; k < enemy->objects.size(); ++k)
						{
							XMFLOAT3 pos = objects[i]->GetPosition();
							//적과의 거리가 xz평면에서 0.6미터 이내이고, y좌표도 적의 y범위 내에 있는 경우, 즉 적과 부딫친 경우
							XMFLOAT3 ep = enemy->objects[k]->GetPosition();
							XMFLOAT3 dst = XMFLOAT3(ep.x - pos.x, 0.0f, ep.z - pos.z);
							if (Vector3::Length(dst) <= 0.6f && (pos.y > ep.y && pos.y < ep.y + 1.7f))
							{
								if (objects[i]->owner == pid)
								{
									CS_PARTICLE_PACKET p;
									p.size = sizeof(CS_PARTICLE_PACKET);
									p.type = PACKET_TYPE::CS_PARTICLE;
									p.id = pid;
									p.particleType = 1;
									p.count = 100;
									p.x = objects[i]->GetPosition().x;
									p.y = objects[i]->GetPosition().y;
									p.z = objects[i]->GetPosition().z;

									SendPacket(&p);
								}
								//그 적을 포함한 충돌 반경 1미터 내의 적들에게 피해, 직격은 두 배
								//또한 그 적들을 1초간 기절.
								for (int a = 0; a < enemy->objects.size(); ++a)
								{
									XMFLOAT3 enp = enemy->objects[a]->GetPosition();
									XMFLOAT3 ds = XMFLOAT3(enp.x - pos.x, 0.0f, enp.z - pos.z);
									if (Vector3::Length(ds) <= 1.0f)
									{

										if (objects[i]->owner == pid)
										{
											CS_ATTACK_PACKET ap;
											ap.size = sizeof(CS_ATTACK_PACKET);
											ap.type = PACKET_TYPE::CS_ATTACK;
											ap.id = 1;
											ap.target = i;
											ap.damage = pl->objects[k]->info->getMeleeDamage() * pl->objects[k]->amp_melee;
											ap.stuntime = 1.0f;

											SendPacket(&ap);
										}
									}
								}

							//	delete objects[i];
								objects.erase(objects.begin() + i);

								erased = true;
								break;
							}
						}
					}
				}
				else if (tx > 200.0f && tx < 600.0f && tz>0.0f && tz < 200.0f)
				{
					ix = (int)((tx - 200.0f) / 0.5f);
					iz = (int)((tz) / 0.5f);
					//높이맵에서의 높이가 더 높은경우, 즉 물체 옆면에 충돌한 경우
					if (enemy->height12[ix][iz] >= objects[i]->origin.y)
					{
					// 폭발 반경 인근의 적들에게 피해
						if (objects[i]->owner == pid)
						{
							CS_PARTICLE_PACKET p;
							p.size = sizeof(CS_PARTICLE_PACKET);
							p.type = PACKET_TYPE::CS_PARTICLE;
							p.id = pid;
							p.particleType = 1;
							p.count = 100;
							p.x = objects[i]->GetPosition().x;
							p.y = objects[i]->GetPosition().y;
							p.z = objects[i]->GetPosition().z;

							SendPacket(&p);
						}
					for (int k = 0; k < enemy->objects.size(); ++k)
					{
						XMFLOAT3 op = objects[i]->GetPosition();
						XMFLOAT3 enp = enemy->objects[k]->GetPosition();

						if (Vector3::Length(XMFLOAT3(op.x - enp.x, 0.0f, op.z - enp.z)) <= 1.0f)
						{


							if (objects[i]->owner == pid)
							{
								CS_ATTACK_PACKET ap;
								ap.size = sizeof(CS_ATTACK_PACKET);
								ap.type = PACKET_TYPE::CS_ATTACK;
								ap.id = 1;
								ap.target = i;
								ap.damage = pl->objects[k]->info->getMeleeDamage() * pl->objects[k]->amp_melee;
								ap.stuntime = 1.0f;

								SendPacket(&ap);
							}

						}


					}
				

				//delete objects[i];
				objects.erase(objects.begin() + i);
				erased = true;
				}

					//물체랑은 충돌하지 않았지만 적과 박은 경우
					else
					{

						for (int k = 0; k < enemy->objects.size(); ++k)
						{
							XMFLOAT3 pos = objects[i]->GetPosition();
							//적과의 거리가 xz평면에서 0.6미터 이내이고, y좌표도 적의 y범위 내에 있는 경우, 즉 적과 부딫친 경우
							XMFLOAT3 ep = enemy->objects[k]->GetPosition();
							XMFLOAT3 dst = XMFLOAT3(ep.x - pos.x, 0.0f, ep.z - pos.z);

							if (Vector3::Length(dst) <= 0.6f && (pos.y > ep.y && pos.y < ep.y + 1.7f))
							{
								//그 적을 포함한 충돌 반경 1미터 내의 적들에게 피해, 직격은 두 배
								//또한 그 적들을 1초간 기절.

								if (objects[i]->owner == pid)
								{
									CS_PARTICLE_PACKET p;
									p.size = sizeof(CS_PARTICLE_PACKET);
									p.type = PACKET_TYPE::CS_PARTICLE;
									p.id = pid;
									p.particleType = 1;
									p.count = 100;
									p.x = objects[i]->GetPosition().x;
									p.y = objects[i]->GetPosition().y;
									p.z = objects[i]->GetPosition().z;

									SendPacket(&p);
								}
								for (int a = 0; a < enemy->objects.size(); ++a)
								{
									XMFLOAT3 enp = enemy->objects[a]->GetPosition();
									XMFLOAT3 ds = XMFLOAT3(enp.x - pos.x, 0.0f, enp.z - pos.z);
									if (Vector3::Length(ds) <= 1.0f)
									{
										
									

										if (objects[i]->owner == pid)
										{
											CS_ATTACK_PACKET ap;
											ap.size = sizeof(CS_ATTACK_PACKET);
											ap.type = PACKET_TYPE::CS_ATTACK;
											ap.id = 1;
											ap.target = i;
											ap.damage = pl->objects[k]->info->getMeleeDamage() * pl->objects[k]->amp_melee;
											ap.stuntime = 1.0f;

											SendPacket(&ap);
										}


									}
								}
								
							//	delete objects[i];
								objects.erase(objects.begin() + i);

								erased = true;
								break;
							}
						}
					}
				}
			
			if (erased == true)
			{
				continue;
			}
			else
			{
				//여기까지 오면 충돌하지 않았다는 것이므로 이동.

				XMFLOAT3 pos = objects[i]->GetPosition();

				chrono::time_point<chrono::system_clock> mom = chrono::system_clock::now();
				chrono::duration<double> dt2 = mom - objects[i]->lastMove;


				float tx = pos.x + objects[i]->direction.x * objects[i]->speed * (float)dt2.count();
				float tz = pos.z + objects[i]->direction.z * objects[i]->speed * (float)dt2.count();

				objects[i]->SetPosition(tx, pos.y, tz);
				objects[i]->lastMove = chrono::system_clock::now();
			}
		}
	}


};