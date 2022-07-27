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

			//�������� 1�ʰ� �����ų�, �׻��̿� ��ü Ȥ�� ������ ���� ��� ��ü ����.

			
				float tx = objects[i]->origin.x + objects[i]->direction.x * objects[i]->speed * (float)dt.count();
				float tz = objects[i]->origin.z + objects[i]->direction.z * objects[i]->speed * (float)dt.count();

				int ix, iz;
				if (tx > 0.0f && tx < 200.0f && tz>0.0f && tz < 200.0f)
				{
					ix = (int)(tx / 0.5f);
					iz = (int)(tz / 0.5f);

					//���̸ʿ����� ���̰� �� �������, �� ��ü ���鿡 �浹�� ���
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
						// ���� �ݰ� �α��� ���鿡�� ����
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

					//��ü���� �浹���� �ʾ����� ���� ���� ���
					else
					{

						for (int k = 0; k < enemy->objects.size(); ++k)
						{
							XMFLOAT3 pos = objects[i]->GetPosition();
							//������ �Ÿ��� xz��鿡�� 0.6���� �̳��̰�, y��ǥ�� ���� y���� ���� �ִ� ���, �� ���� �΋Hģ ���
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
								//�� ���� ������ �浹 �ݰ� 1���� ���� ���鿡�� ����, ������ �� ��
								//���� �� ������ 1�ʰ� ����.
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
					//���̸ʿ����� ���̰� �� �������, �� ��ü ���鿡 �浹�� ���
					if (enemy->height12[ix][iz] >= objects[i]->origin.y)
					{
					// ���� �ݰ� �α��� ���鿡�� ����
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

					//��ü���� �浹���� �ʾ����� ���� ���� ���
					else
					{

						for (int k = 0; k < enemy->objects.size(); ++k)
						{
							XMFLOAT3 pos = objects[i]->GetPosition();
							//������ �Ÿ��� xz��鿡�� 0.6���� �̳��̰�, y��ǥ�� ���� y���� ���� �ִ� ���, �� ���� �΋Hģ ���
							XMFLOAT3 ep = enemy->objects[k]->GetPosition();
							XMFLOAT3 dst = XMFLOAT3(ep.x - pos.x, 0.0f, ep.z - pos.z);

							if (Vector3::Length(dst) <= 0.6f && (pos.y > ep.y && pos.y < ep.y + 1.7f))
							{
								//�� ���� ������ �浹 �ݰ� 1���� ���� ���鿡�� ����, ������ �� ��
								//���� �� ������ 1�ʰ� ����.

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
				//������� ���� �浹���� �ʾҴٴ� ���̹Ƿ� �̵�.

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