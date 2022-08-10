#include "InterfaceShader.h"


InterfaceShader::InterfaceShader(ResourceManager* r) 
{ 
	rm = r; 
}
InterfaceShader::~InterfaceShader() {}

void InterfaceShader::BuildObjects(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList)
{
	CubeMeshOffset* mesh = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 1200.0f/450.0f, 2.0f, 0.01f, 0.0f, 0.0f, false);
	CubeMeshOffset* meshr = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 1200.0f / 450.0f, 2.0f, 0.01f, 0.0f, 0.0f, true);

	CubeMeshOffset* melee = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 30.0f / 450.0f, 30.0f / 450.0f, 0.02f, (50.0f - 600.0f) / 450.0f, -(50.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* meleer = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 30.0f / 450.0f, 30.0f / 450.0f, 0.02f, -(50.0f - 600.0f) / 450.0f, -(50.0f - 450.0f) / 450.0f, true);
	
	CubeMeshOffset* range = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 30.0f / 450.0f, 30.0f / 450.0f, 0.02f, (90.0f - 600.0f) / 450.0f, -(50.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* ranger = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 30.0f / 450.0f, 30.0f / 450.0f, 0.02f, -(90.0f - 600.0f) / 450.0f, -(50.0f - 450.0f) / 450.0f, true);

	CubeMeshOffset* micro = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 30.0f / 450.0f, 30.0f / 450.0f, 0.02f, (130.0f - 600.0f) / 450.0f, -(50.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* micror = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 30.0f / 450.0f, 30.0f / 450.0f, 0.02f, -(130.0f - 600.0f) / 450.0f, -(50.0f - 450.0f) / 450.0f, true);

	CubeMeshOffset* succeed = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 689.0f / 450.0f, 782.0f / 450.0f, 0.02f, -(600.0f - 600.0f) / 450.0f, -(450.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* succeedr = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 689.0f / 450.0f, 782.0f / 450.0f, 0.02f, (600.0f - 600.0f) / 450.0f, -(450.0f - 450.0f) / 450.0f, true);

	CubeMeshOffset* retry = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 130.0f / 450.0f, 65.0f / 450.0f, 0.03f, (714.0f - 600.0f) / 450.0f, -(590.8f - 450.0f) / 450.0f, false);
	CubeMeshOffset* retryr = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 130.0f / 450.0f, 65.0f / 450.0f, 0.03f, -(714.0f - 600.0f) / 450.0f, -(590.8f - 450.0f) / 450.0f, true);

	CubeMeshOffset* back = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 130.0f / 450.0f, 65.0f / 450.0f, 0.03f, (846.6f - 600.0f) / 450.0f, -(590.8f - 450.0f) / 450.0f, false);
	CubeMeshOffset* backr = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 130.0f / 450.0f, 65.0f / 450.0f, 0.03f, -(846.6f - 600.0f) / 450.0f, -(590.8f - 450.0f) / 450.0f, true);

	CubeMeshOffset* exp_melee1 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, (487.0f - 600.0f) / 450.0f, -(416.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* exp_melee2 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, (507.0f - 600.0f) / 450.0f, -(416.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* exp_melee3 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, (527.0f - 600.0f) / 450.0f, -(416.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* exp_melee1r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, -(487.0f - 600.0f) / 450.0f, -(416.0f - 450.0f) / 450.0f, true);
	CubeMeshOffset* exp_melee2r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, -(507.0f - 600.0f) / 450.0f, -(416.0f - 450.0f) / 450.0f, true);
	CubeMeshOffset* exp_melee3r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, -(527.0f - 600.0f) / 450.0f, -(416.0f - 450.0f) / 450.0f, true);

	CubeMeshOffset* exp_ranged1 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, (487.0f - 600.0f) / 450.0f, -(456.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* exp_ranged2 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, (507.0f - 600.0f) / 450.0f, -(456.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* exp_ranged3 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, (527.0f - 600.0f) / 450.0f, -(456.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* exp_ranged1r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, -(487.0f - 600.0f) / 450.0f, -(456.0f - 450.0f) / 450.0f, true);
	CubeMeshOffset* exp_ranged2r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, -(507.0f - 600.0f) / 450.0f, -(456.0f - 450.0f) / 450.0f, true);
	CubeMeshOffset* exp_ranged3r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, -(527.0f - 600.0f) / 450.0f, -(456.0f - 450.0f) / 450.0f, true);

	CubeMeshOffset* exp_radio1 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, (487.0f - 600.0f) / 450.0f, -(496.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* exp_radio2 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, (507.0f - 600.0f) / 450.0f, -(496.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* exp_radio3 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, (527.0f - 600.0f) / 450.0f, -(496.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* exp_radio1r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, -(487.0f - 600.0f) / 450.0f, -(496.0f - 450.0f) / 450.0f, true);
	CubeMeshOffset* exp_radio2r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, -(507.0f - 600.0f) / 450.0f, -(496.0f - 450.0f) / 450.0f, true);
	CubeMeshOffset* exp_radio3r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, -(527.0f - 600.0f) / 450.0f, -(496.0f - 450.0f) / 450.0f, true);

	CubeMeshOffset* gold1 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, (487.0f - 600.0f) / 450.0f, -(536.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* gold2 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, (507.0f - 600.0f) / 450.0f, -(536.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* gold3 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, (527.0f - 600.0f) / 450.0f, -(536.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* gold1r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, -(487.0f - 600.0f) / 450.0f, -(536.0f - 450.0f) / 450.0f, true);
	CubeMeshOffset* gold2r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, -(507.0f - 600.0f) / 450.0f, -(536.0f - 450.0f) / 450.0f, true);
	CubeMeshOffset* gold3r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, -(527.0f - 600.0f) / 450.0f, -(536.0f - 450.0f) / 450.0f, true);

	

	meshes.push_back(mesh);
	revmeshes.push_back(meshr);

	meshes.push_back(melee);
	revmeshes.push_back(meleer);
	meshes.push_back(range);
	revmeshes.push_back(ranger);
	meshes.push_back(micro);
	revmeshes.push_back(micror);





	//플레이어 체력바
	for (float i = 0.0f; i < 20.0f; i += 1.0f)
	{
		float nLength = 15.35f;
		int totalN = 20;
		float ox = 133.0f;
		float oz = 781.7;
		float z = 63.0f;
		CubeMeshOffset* hp = new CubeMeshOffset(pd3dDevice, pd3dCommandList, nLength * (i + 1.0f) / 450.0f, z / 450.0f, 0.02f, ((ox + (nLength / 2.0f) * (totalN - i + 1.0f)) - 600.0f) / 450.0f, -(oz - 450.0f) / 450.0f, false);
		CubeMeshOffset* hpr = new CubeMeshOffset(pd3dDevice, pd3dCommandList, nLength * (i + 1.0f) / 450.0f, z / 450.0f, 0.02f, -((ox + (nLength / 2.0f) * (totalN - i + 1.0f)) - 600.0f) / 450.0f, -(oz - 450.0f) / 450.0f, true);

		meshes.push_back(hp);
		revmeshes.push_back(hpr);
	}

	//근접경험치
	for (float i = 0.0f; i < 100.0f; i += 1.0f)
	{
		float nLength = 12.0f;
		int totalN = 100;
		float ox = 600.0f;
		float oz = 896.0f;
		float z = 10.0f;
		CubeMeshOffset* hp = new CubeMeshOffset(pd3dDevice, pd3dCommandList, nLength * (i + 1.0f) / 450.0f, z / 450.0f, 0.02f, -((ox + (nLength / 2.0f) * (totalN - i + 1.0f)) - 600.0f) / 450.0f, -(oz - 450.0f) / 450.0f, false);
		CubeMeshOffset* hpr = new CubeMeshOffset(pd3dDevice, pd3dCommandList, nLength * (i + 1.0f) / 450.0f, z / 450.0f, 0.02f, ((ox + (nLength / 2.0f) * (totalN - i + 1.0f)) - 600.0f) / 450.0f, -(oz - 450.0f) / 450.0f, true);

		meshes.push_back(hp);
		revmeshes.push_back(hpr);
	}
	//원거리경험치
	for (float i = 0.0f; i < 100.0f; i += 1.0f)
	{
		float nLength = 12.0f;
		int totalN = 100;
		float ox = 600.0f;
		float oz = 886.0f;
		float z = 10.0f;
		CubeMeshOffset* hp = new CubeMeshOffset(pd3dDevice, pd3dCommandList, nLength * (i + 1.0f) / 450.0f, z / 450.0f, 0.02f, -((ox + (nLength / 2.0f) * (totalN - i + 1.0f)) - 600.0f) / 450.0f, -(oz - 450.0f) / 450.0f, false);
		CubeMeshOffset* hpr = new CubeMeshOffset(pd3dDevice, pd3dCommandList, nLength * (i + 1.0f) / 450.0f, z / 450.0f, 0.02f, ((ox + (nLength / 2.0f) * (totalN - i + 1.0f)) - 600.0f) / 450.0f, -(oz - 450.0f) / 450.0f, true);

		meshes.push_back(hp);
		revmeshes.push_back(hpr);
	}
	//전파경험치
	for (float i = 0.0f; i < 100.0f; i += 1.0f)
	{
		float nLength = 12.0f;
		int totalN = 100;
		float ox = 600.0f;
		float oz = 876.0f;
		float z = 10.0f;
		CubeMeshOffset* hp = new CubeMeshOffset(pd3dDevice, pd3dCommandList, nLength * (i + 1.0f) / 450.0f, z / 450.0f, 0.02f, -((ox + (nLength / 2.0f) * (totalN - i + 1.0f)) - 600.0f) / 450.0f, -(oz - 450.0f) / 450.0f, false);
		CubeMeshOffset* hpr = new CubeMeshOffset(pd3dDevice, pd3dCommandList, nLength * (i + 1.0f) / 450.0f, z / 450.0f, 0.02f, ((ox + (nLength / 2.0f) * (totalN - i + 1.0f)) - 600.0f) / 450.0f, -(oz - 450.0f) / 450.0f, true);

		meshes.push_back(hp);
		revmeshes.push_back(hpr);
	}

	//324~338 임무 성공창

	meshes.push_back(succeed);
	meshes.push_back(retry);
	meshes.push_back(back);

	meshes.push_back(exp_melee1);
	meshes.push_back(exp_melee2);
	meshes.push_back(exp_melee3);
	meshes.push_back(exp_ranged1);
	meshes.push_back(exp_ranged2);
	meshes.push_back(exp_ranged3);
	meshes.push_back(exp_radio1);
	meshes.push_back(exp_radio2);
	meshes.push_back(exp_radio3);
	meshes.push_back(gold1);
	meshes.push_back(gold2);
	meshes.push_back(gold3);

	revmeshes.push_back(succeedr);
	revmeshes.push_back(retryr);
	revmeshes.push_back(backr);

	revmeshes.push_back(exp_melee1r);
	revmeshes.push_back(exp_melee2r);
	revmeshes.push_back(exp_melee3r);
	revmeshes.push_back(exp_ranged1r);
	revmeshes.push_back(exp_ranged2r);
	revmeshes.push_back(exp_ranged3r);
	revmeshes.push_back(exp_radio1r);
	revmeshes.push_back(exp_radio2r);
	revmeshes.push_back(exp_radio3r);
	revmeshes.push_back(gold1r);
	revmeshes.push_back(gold2r);
	revmeshes.push_back(gold3r);

	//mission
	CubeMeshOffset* mission = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 500.0f / 450.0f, 210.0f / 450.0f, 0.03f, (600.0f - 600.0f) / 450.0f, -(430.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* missionr = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 500.0f / 450.0f, 210.0f / 450.0f, 0.03f, -(600.0f - 600.0f) / 450.0f, -(430.0f - 450.0f) / 450.0f, true);

	//임무 진척도

	CubeMeshOffset* prog = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 120.0f / 450.0f, 30.0f / 450.0f, 0.03f, (1030.0f - 600.0f) / 450.0f, -(150.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* progr = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 120.0f / 450.0f, 30.0f / 450.0f, 0.03f, -(1030.0f - 600.0f) / 450.0f, -(150.0f - 450.0f) / 450.0f, true);

	//진척도 숫자

	CubeMeshOffset* prog10 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, (1100.0f - 600.0f) / 450.0f, -(150.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* prog10r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, -(1100.0f - 600.0f) / 450.0f, -(150.0f - 450.0f) / 450.0f, true);

	CubeMeshOffset* prog1 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, (1120.0f - 600.0f) / 450.0f, -(150.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* prog1r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, -(1120.0f - 600.0f) / 450.0f, -(150.0f - 450.0f) / 450.0f, true);
	//실패 조건 충족도
	CubeMeshOffset* fprog = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 120.0f / 450.0f, 30.0f / 450.0f, 0.03f, (1030.0f - 600.0f) / 450.0f, -(180.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* fprogr = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 120.0f / 450.0f, 30.0f / 450.0f, 0.03f, -(1030.0f - 600.0f) / 450.0f, -(180.0f - 450.0f) / 450.0f, true);

	CubeMeshOffset* fprog1 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, (1100.0f - 600.0f) / 450.0f, -(180.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* fprog1r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, -(1100.0f - 600.0f) / 450.0f, -(180.0f - 450.0f) / 450.0f, true);

	CubeMeshOffset* time = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 120.0f / 450.0f, 30.0f / 450.0f, 0.03f, (1030.0f - 600.0f) / 450.0f, -(210.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* timer = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 120.0f / 450.0f, 30.0f / 450.0f, 0.03f, -(1030.0f - 600.0f) / 450.0f, -(210.0f - 450.0f) / 450.0f, true);

	CubeMeshOffset* time100 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, (1100.0f - 600.0f) / 450.0f, -(210.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* time100r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, -(1100.0f - 600.0f) / 450.0f, -(210.0f - 450.0f) / 450.0f, true);

	CubeMeshOffset* time10 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, (1120.0f - 600.0f) / 450.0f, -(210.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* time10r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, -(1120.0f - 600.0f) / 450.0f, -(210.0f - 450.0f) / 450.0f, true);

	CubeMeshOffset* time1 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, (1140.0f - 600.0f) / 450.0f, -(210.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* time1r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, -(1140.0f - 600.0f) / 450.0f, -(210.0f - 450.0f) / 450.0f, true);

	CubeMeshOffset* fail = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 1300.0f / 450.0f, 1000.0f / 450.0f, 0.03f, (600.0f - 600.0f) / 450.0f, -(450.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* failr = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 1300.0f / 450.0f, 1000.0f / 450.0f, 0.03f, (600.0f - 600.0f) / 450.0f, -(450.0f - 450.0f) / 450.0f, true);

	CubeMeshOffset* narration = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 600.0f / 450.0f, 150.0f / 450.0f, 0.03f, (465.0f - 600.0f) / 450.0f, -(100.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* narrationr = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 600.0f / 450.0f, 150.0f / 450.0f, 0.03f, -(465.0f - 600.0f) / 450.0f, -(100.0f - 450.0f) / 450.0f, true);


	//339~348끝까지 구역별 미션 관련

	meshes.push_back(mission);
	meshes.push_back(prog);
	meshes.push_back(prog10);
	meshes.push_back(prog1);
	meshes.push_back(fprog);
	meshes.push_back(fprog1);
	meshes.push_back(time);
	meshes.push_back(time100);
	meshes.push_back(time10);
	meshes.push_back(time1);
	meshes.push_back(fail);
	meshes.push_back(narration);

	revmeshes.push_back(missionr);
	revmeshes.push_back(progr);
	revmeshes.push_back(prog10r);
	revmeshes.push_back(prog1r);
	revmeshes.push_back(fprogr);
	revmeshes.push_back(fprog1r);
	revmeshes.push_back(timer);
	revmeshes.push_back(time100r);
	revmeshes.push_back(time10r);
	revmeshes.push_back(time1r);
	revmeshes.push_back(failr);
	revmeshes.push_back(narrationr);

	UIObject* obj = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj2 = new UIObject(1, -1, -1, -1, -1, 263);
	UIObject* obj3 = new UIObject(1, -1, -1, -1, -1, 265);
	UIObject* obj4 = new UIObject(1, -1, -1, -1, -1, 267);
	
	UIObject* obj5 = new UIObject(1, -1, -1, -1, -1, 269);
	UIObject* obj6 = new UIObject(1, -1, -1, -1, -1, 270);
	UIObject* obj7 = new UIObject(1, -1, -1, -1, -1, 271);
	UIObject* obj8 = new UIObject(1, -1, -1, -1, -1, 272);

	UIObject* obj9 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj10 = new UIObject(1, 656, 559, 786, 625, 302);//retry
	UIObject* obj11 = new UIObject(1, 801, 559, 931, 625, 304);//back
	
	//exp melee
	UIObject* obj12 = new UIObject(1, -1, -1, -1, -1, 273);
	UIObject* obj13 = new UIObject(1, -1, -1, -1, -1, 273);
	UIObject* obj14 = new UIObject(1, -1, -1, -1, -1, 273);
	//exp range
	UIObject* obj15 = new UIObject(1, -1, -1, -1, -1, 273);
	UIObject* obj16 = new UIObject(1, -1, -1, -1, -1, 273);
	UIObject* obj17 = new UIObject(1, -1, -1, -1, -1, 273);
	//exp radio
	UIObject* obj18 = new UIObject(1, -1, -1, -1, -1, 273);
	UIObject* obj19 = new UIObject(1, -1, -1, -1, -1, 273);
	UIObject* obj20 = new UIObject(1, -1, -1, -1, -1, 273);
	//gold
	UIObject* obj21 = new UIObject(1, -1, -1, -1, -1, 273);
	UIObject* obj22 = new UIObject(1, -1, -1, -1, -1, 273);
	UIObject* obj23 = new UIObject(1, -1, -1, -1, -1, 273);


	//mission
	UIObject* obj24 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj25 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj26 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj27 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj28 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj29 = new UIObject(1, -1, -1, -1, -1, -1);
	
	UIObject* obj30 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj31 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj32 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj33 = new UIObject(1, -1, -1, -1, -1, -1);

	UIObject* obj34 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj35 = new UIObject(1, -1, -1, -1, -1, -1);


	obj->SetMesh(meshes[0]);
	obj->SetMaterial(0, rm->materials[262]);
	obj->SetPosition(100.0f, 2.0f, 105.0f);

	obj2->SetMesh(meshes[1]);
	obj2->SetMaterial(0, rm->materials[263]);
	obj2->SetPosition(100.0f, 2.0f, 105.0f);

	obj3->SetMesh(meshes[2]);
	obj3->SetMaterial(0, rm->materials[265]);
	obj3->SetPosition(100.0f, 2.0f, 105.0f);

	obj4->SetMesh(meshes[3]);
	obj4->SetMaterial(0, rm->materials[267]);
	obj4->SetPosition(100.0f, 2.0f, 105.0f);

	obj5->SetMesh(meshes[4]);
	obj5->SetMaterial(0, rm->materials[269]);
	obj5->SetPosition(100.0f, 2.0f, 105.0f);

	obj6->SetMesh(meshes[24]);
	obj6->SetMaterial(0, rm->materials[270]);
	obj6->SetPosition(100.0f, 2.0f, 105.0f);

	obj7->SetMesh(meshes[124]);
	obj7->SetMaterial(0, rm->materials[271]);
	obj7->SetPosition(100.0f, 2.0f, 105.0f);

	obj8->SetMesh(meshes[224]);
	obj8->SetMaterial(0, rm->materials[272]);
	obj8->SetPosition(100.0f, 2.0f, 105.0f);


	//success

	obj9->SetMesh(meshes[54]);
	obj9->SetMaterial(0, rm->materials[301]);
	obj9->SetPosition(100.0f, 2.0f, 105.0f);

	obj10->SetMesh(meshes[55]);
	obj10->SetMaterial(0, rm->materials[302]);
	obj10->SetPosition(100.0f, 2.0f, 105.0f);

	obj11->SetMesh(meshes[56]);
	obj11->SetMaterial(0, rm->materials[304]);
	obj11->SetPosition(100.0f, 2.0f, 105.0f);

	//reward

	//melee
	obj12->SetMesh(meshes[57]);
	obj12->SetMaterial(0, rm->materials[273]);
	obj12->SetPosition(100.0f, 2.0f, 105.0f);
	obj13->SetMesh(meshes[58]);
	obj13->SetMaterial(0, rm->materials[273]);
	obj13->SetPosition(100.0f, 2.0f, 105.0f);
	obj14->SetMesh(meshes[59]);
	obj14->SetMaterial(0, rm->materials[273]);
	obj14->SetPosition(100.0f, 2.0f, 105.0f);

	//range
	obj15->SetMesh(meshes[60]);
	obj15->SetMaterial(0, rm->materials[273]);
	obj15->SetPosition(100.0f, 2.0f, 105.0f);
	obj16->SetMesh(meshes[61]);
	obj16->SetMaterial(0, rm->materials[273]);
	obj16->SetPosition(100.0f, 2.0f, 105.0f);
	obj17->SetMesh(meshes[62]);
	obj17->SetMaterial(0, rm->materials[273]);
	obj17->SetPosition(100.0f, 2.0f, 105.0f);
	//radio
	obj18->SetMesh(meshes[63]);
	obj18->SetMaterial(0, rm->materials[273]);
	obj18->SetPosition(100.0f, 2.0f, 105.0f);
	obj19->SetMesh(meshes[64]);
	obj19->SetMaterial(0, rm->materials[273]);
	obj19->SetPosition(100.0f, 2.0f, 105.0f);
	obj20->SetMesh(meshes[65]);
	obj20->SetMaterial(0, rm->materials[273]);
	obj20->SetPosition(100.0f, 2.0f, 105.0f);

	obj21->SetMesh(meshes[66]);
	obj21->SetMaterial(0, rm->materials[273]);
	obj21->SetPosition(100.0f, 2.0f, 105.0f);
	obj22->SetMesh(meshes[67]);
	obj22->SetMaterial(0, rm->materials[273]);
	obj22->SetPosition(100.0f, 2.0f, 105.0f);
	obj23->SetMesh(meshes[68]);
	obj23->SetMaterial(0, rm->materials[273]);
	obj23->SetPosition(100.0f, 2.0f, 105.0f);

	//mission
	obj24->SetMesh(meshes[339]);
	obj24->SetMaterial(0, rm->materials[328]);
	obj24->SetPosition(0.0f, 0.0f, 0.0f);
	obj25->SetMesh(meshes[340]);
	obj25->SetMaterial(0, rm->materials[326]);
	obj25->SetPosition(0.0f, 0.0f, 0.0f);
	obj26->SetMesh(meshes[341]);
	obj26->SetMaterial(0, rm->materials[273]);
	obj26->SetPosition(0.0f, 0.0f, 0.0f);
	obj27->SetMesh(meshes[342]);
	obj27->SetMaterial(0, rm->materials[273]);
	obj27->SetPosition(0.0f, 0.0f, 0.0f);
	obj28->SetMesh(meshes[343]);
	obj28->SetMaterial(0, rm->materials[325]);
	obj28->SetPosition(0.0f, 0.0f, 0.0f);
	obj29->SetMesh(meshes[344]);
	obj29->SetMaterial(0, rm->materials[273]);
	obj29->SetPosition(0.0f, 0.0f, 0.0f);

	obj30->SetMesh(meshes[345]);
	obj30->SetMaterial(0, rm->materials[327]);
	obj30->SetPosition(0.0f, 0.0f, 0.0f);
	obj31->SetMesh(meshes[346]);
	obj31->SetMaterial(0, rm->materials[273]);
	obj31->SetPosition(0.0f, 0.0f, 0.0f);
	obj32->SetMesh(meshes[347]);
	obj32->SetMaterial(0, rm->materials[273]);
	obj32->SetPosition(0.0f, 0.0f, 0.0f);
	obj33->SetMesh(meshes[348]);
	obj33->SetMaterial(0, rm->materials[273]);
	obj33->SetPosition(0.0f, 0.0f, 0.0f);

	obj34->SetMesh(NULL);
	obj34->SetMaterial(0, rm->materials[338]);
	obj34->SetPosition(0.0f, 0.0f, 0.0f);

	obj35->SetMesh(meshes[350]);
	obj35->SetMaterial(0, rm->materials[338]);
	obj35->SetPosition(0.0f, 0.0f, 0.0f);
	objects.push_back(obj);
	objects.push_back(obj2);
	objects.push_back(obj3);
	objects.push_back(obj4);
	objects.push_back(obj5);
	objects.push_back(obj6);
	objects.push_back(obj7);
	objects.push_back(obj8);
	objects.push_back(obj9);

	objects.push_back(obj10);
	objects.push_back(obj11);
	objects.push_back(obj12);
	objects.push_back(obj13);
	objects.push_back(obj14);
	objects.push_back(obj15);
	objects.push_back(obj16);
	objects.push_back(obj17);
	objects.push_back(obj18);
	objects.push_back(obj19);

	objects.push_back(obj20);
	objects.push_back(obj21);
	objects.push_back(obj22);
	objects.push_back(obj23);

	objects.push_back(obj24);
	objects.push_back(obj25);
	objects.push_back(obj26);
	objects.push_back(obj27);
	objects.push_back(obj28);
	objects.push_back(obj29);
	objects.push_back(obj30);
	objects.push_back(obj31);
	objects.push_back(obj32);
	objects.push_back(obj33);
	objects.push_back(obj34);
	objects.push_back(obj35);
}

void InterfaceShader::ReleaseObjects()
{

	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->Release();
			objects.erase(objects.begin() + i);
		}
	}
	objects.clear();
}
void InterfaceShader::ReleaseUploadBuffers()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->ReleaseUploadBuffers();
		}
	}
}

void InterfaceShader::ReleaseShaderVariables()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->ReleaseShaderVariables();
		}
	}
}

void InterfaceShader::Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera)
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->Render(pd3dCommandList, pCamera);
		}
	}
}

D3D12_INPUT_LAYOUT_DESC InterfaceShader::CreateInputLayout()
{
	UINT nInputElementDescs = 2;
	D3D12_INPUT_ELEMENT_DESC* pd3dInputElementDescs = new D3D12_INPUT_ELEMENT_DESC[nInputElementDescs];

	pd3dInputElementDescs[0] = { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 };
	pd3dInputElementDescs[1] = { "UV", 0, DXGI_FORMAT_R32G32_FLOAT, 1, 0, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 };
	//pd3dInputElementDescs[2] = { "NORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT, 2, 0, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 };

	D3D12_INPUT_LAYOUT_DESC d3dInputLayoutDesc;
	d3dInputLayoutDesc.pInputElementDescs = pd3dInputElementDescs;
	d3dInputLayoutDesc.NumElements = nInputElementDescs;

	return(d3dInputLayoutDesc);
}

D3D12_RASTERIZER_DESC InterfaceShader::CreateRasterizerState()
{
	D3D12_RASTERIZER_DESC d3dRasterizerDesc;
	::ZeroMemory(&d3dRasterizerDesc, sizeof(D3D12_RASTERIZER_DESC));
	d3dRasterizerDesc.FillMode = D3D12_FILL_MODE_SOLID;
	d3dRasterizerDesc.CullMode = D3D12_CULL_MODE_NONE;
#ifdef _WITH_LEFT_HAND_COORDINATES
	d3dRasterizerDesc.FrontCounterClockwise = FALSE;
#else
	d3dRasterizerDesc.FrontCounterClockwise = TRUE;
#endif
	d3dRasterizerDesc.DepthBias = 0;
	d3dRasterizerDesc.DepthBiasClamp = 0.0f;
	d3dRasterizerDesc.SlopeScaledDepthBias = 0.0f;
	d3dRasterizerDesc.DepthClipEnable = TRUE;
	d3dRasterizerDesc.MultisampleEnable = FALSE;
	d3dRasterizerDesc.AntialiasedLineEnable = FALSE;
	d3dRasterizerDesc.ForcedSampleCount = 0;
	d3dRasterizerDesc.ConservativeRaster = D3D12_CONSERVATIVE_RASTERIZATION_MODE_OFF;

	return(d3dRasterizerDesc);
}

D3D12_DEPTH_STENCIL_DESC InterfaceShader::CreateDepthStencilState()
{
	D3D12_DEPTH_STENCIL_DESC d3dDepthStencilDesc;
	::ZeroMemory(&d3dDepthStencilDesc, sizeof(D3D12_DEPTH_STENCIL_DESC));
	d3dDepthStencilDesc.DepthEnable = TRUE;
	d3dDepthStencilDesc.DepthWriteMask = D3D12_DEPTH_WRITE_MASK_ALL;
	d3dDepthStencilDesc.DepthFunc = D3D12_COMPARISON_FUNC_ALWAYS;
	d3dDepthStencilDesc.StencilEnable = FALSE;
	d3dDepthStencilDesc.StencilReadMask = 0x00;
	d3dDepthStencilDesc.StencilWriteMask = 0x00;
	d3dDepthStencilDesc.FrontFace.StencilFailOp = D3D12_STENCIL_OP_KEEP;
	d3dDepthStencilDesc.FrontFace.StencilDepthFailOp = D3D12_STENCIL_OP_KEEP;
	d3dDepthStencilDesc.FrontFace.StencilPassOp = D3D12_STENCIL_OP_KEEP;
	d3dDepthStencilDesc.FrontFace.StencilFunc = D3D12_COMPARISON_FUNC_NEVER;
	d3dDepthStencilDesc.BackFace.StencilFailOp = D3D12_STENCIL_OP_KEEP;
	d3dDepthStencilDesc.BackFace.StencilDepthFailOp = D3D12_STENCIL_OP_KEEP;
	d3dDepthStencilDesc.BackFace.StencilPassOp = D3D12_STENCIL_OP_KEEP;
	d3dDepthStencilDesc.BackFace.StencilFunc = D3D12_COMPARISON_FUNC_NEVER;

	return(d3dDepthStencilDesc);
}

D3D12_SHADER_BYTECODE InterfaceShader::CreateVertexShader()
{
	return(CShader::CompileShaderFromFile(L"interface.hlsl", "vsInterface", "vs_5_1", &m_pd3dVertexShaderBlob));
}

D3D12_SHADER_BYTECODE InterfaceShader::CreatePixelShader()
{
	return(CShader::CompileShaderFromFile(L"interface.hlsl", "psInterface", "ps_5_1", &m_pd3dPixelShaderBlob));
}

void InterfaceShader::Animate(CCamera* cam, PlayerInfoManager* in)
{
	info = in;

	XMFLOAT3 cp = cam->getPosition();
	XMFLOAT3 cl = cam->getLook();
	XMFLOAT3 cr = cam->getRight();
	XMFLOAT3 cu = cam->getUp();
	float pitch = XMConvertToDegrees(atan(cl.y / sqrt(cl.x * cl.x + cl.z * cl.z)));

	float yaw = XMConvertToDegrees(atan(cl.x / cl.z));
	float roll = XMConvertToDegrees(atan(cl.x / cl.y));

	if (cl.z < 0)
	{
		pitch = -pitch;

	}




	for (int i = 0; i < objects.size(); ++i)
	{
		//수치 막대가 아닌 경우
		if (i < 4)
		{
			if (cl.z < 0.0f)
			{
				objects[i]->SetMesh(revmeshes[i]);
			}
			else
			{
				objects[i]->SetMesh(meshes[i]);
			}
		}
		else if (i >= 4 && i < 8)
		{
			int cap = (info->stats.capacity * 100 / info->stats.maxhp - 2) / 5; //백분율로 나타낸 뒤 5로 나눔. 20분율

			int melee = (info->growth.melee.exp * 100 / expNeed[info->growth.melee.level - 1]); // 최대량 대비 현재량을 100분율로
			int ranged = (info->growth.ranged.exp * 100 / expNeed[info->growth.ranged.level - 1]); // 최대량 대비 현재량을 100분율로
			int radio = (info->growth.radio.exp * 100 / expNeed[info->growth.radio.level - 1]); // 최대량 대비 현재량을 100분율로

			if (cap < 0)
				cap = 0;

			if (melee < 0)
				melee = 0;

			if (ranged < 0)
				ranged = 0;

			if (radio < 0)
				radio = 0;

			if (i == 4)
			{
				if (cl.z < 0.0f)
				{
					objects[i]->SetMesh(revmeshes[4 + cap]);
				}
				else
				{
					objects[i]->SetMesh(meshes[4 + cap]);
				}
			}
			else if (i == 5)
			{
				if (cl.z < 0.0f)
				{
					objects[i]->SetMesh(revmeshes[24 + melee]);
				}
				else
				{
					objects[i]->SetMesh(meshes[24 + melee]);
				}
			}
			else if (i == 6)
			{
				if (cl.z < 0.0f)
				{
					objects[i]->SetMesh(revmeshes[124 + ranged]);
				}
				else
				{
					objects[i]->SetMesh(meshes[124 + ranged]);
				}
			}
			else if (i == 7)
			{
				if (cl.z < 0.0f)
				{
					objects[i]->SetMesh(revmeshes[224 + radio]);
				}
				else
				{
					objects[i]->SetMesh(meshes[224 + radio]);
				}
			}
		}
		objects[i]->Rotate(-pitch, yaw, 0.0f);
		objects[i]->SetPosition(cp.x + cl.x, cp.y + cl.y, cp.z + cl.z);
	}

	if (stageClear == false)
	{
		for (int i = 8; i < 23; ++i)
		{
			objects[i]->m_pMesh = NULL;
		}


		if (missionShow == false)
		{
			objects[23]->SetMesh(NULL);
		}

		else

		{
			if (cl.z < 0.0f)
			{
				objects[23]->SetMesh(revmeshes[339]);
				objects[23]->m_ppMaterials[0] = rm->materials[mission + 327];
			}
			else
			{
				objects[23]->SetMesh(meshes[339]);
				objects[23]->m_ppMaterials[0] = rm->materials[mission + 327];
			}
		}

		if (cl.z < 0.0f)
		{
			objects[24]->SetMesh(revmeshes[340]);
			objects[25]->SetMesh(revmeshes[341]);
			objects[26]->SetMesh(revmeshes[342]);
		}
		else
		{
			objects[24]->SetMesh(meshes[340]);
			objects[25]->SetMesh(meshes[341]);
			objects[26]->SetMesh(meshes[342]);
		}

		if (mission == 1)
		{
			int n = (m1_kill %100)/ 10;
			//진척도
			objects[25]->m_ppMaterials[0] = rm->materials[273 + n];
			n = m1_kill % 10;
			objects[26]->m_ppMaterials[0] = rm->materials[273 + n];

			//실패조건
			objects[27]->SetMesh(NULL);
			objects[28]->SetMesh(NULL);

			//제한시간 관련
			objects[29]->SetMesh(NULL);
			objects[30]->SetMesh(NULL);
			objects[31]->SetMesh(NULL);
			objects[32]->SetMesh(NULL);
		}
		else if (mission==2)
		{
			int n = (m2_stun % 100) / 10;
			//진척도
			objects[25]->m_ppMaterials[0] = rm->materials[273 + n];
			n = m2_stun % 10;
			objects[26]->m_ppMaterials[0] = rm->materials[273 + n];

			//실패조건
			objects[27]->SetMesh(NULL);
			objects[28]->SetMesh(NULL);

			//제한시간 관련
			objects[29]->SetMesh(NULL);
			objects[30]->SetMesh(NULL);
			objects[31]->SetMesh(NULL);
			objects[32]->SetMesh(NULL);
		}
		else if (mission == 3)
		{
			int n = (m3_bother % 100) / 10;
			//진척도
			objects[25]->m_ppMaterials[0] = rm->materials[273 + n];
			n = m3_bother % 10;
			objects[26]->m_ppMaterials[0] = rm->materials[273 + n];

			//실패조건
			objects[27]->SetMesh(NULL);
			objects[28]->SetMesh(NULL);

			//제한시간 관련
			objects[29]->SetMesh(NULL);
			objects[30]->SetMesh(NULL);
			objects[31]->SetMesh(NULL);
			objects[32]->SetMesh(NULL);
		}
		else if (mission == 4)
		{
			int n = (m4_kill % 100) / 10;
			//진척도
			objects[25]->m_ppMaterials[0] = rm->materials[273 + n];
			n = m4_kill % 10;
			objects[26]->m_ppMaterials[0] = rm->materials[273 + n];

			//실패조건
			objects[27]->SetMesh(NULL);
			objects[28]->SetMesh(NULL);

			//제한시간 관련
			chrono::time_point<chrono::system_clock> mm = chrono::system_clock::now();
			chrono::seconds s = chrono::duration_cast<chrono::seconds>(mm - missionChangedTime);
			n = ((100 - s.count()) % 1000) / 100;
			if (n < 0)
				n = 0;
			objects[30]->m_ppMaterials[0] = rm->materials[273 + n];
			n = ((100 - s.count()) % 100) / 10;
			if (n < 0)
				n = 0;
			objects[31]->m_ppMaterials[0] = rm->materials[273 + n];
			n = (100 - s.count()) % 10;
			if (n < 0)
				n = 0;
			objects[32]->m_ppMaterials[0] = rm->materials[273 + n];
			
			if (cl.z < 0.0f)
			{
				objects[29]->SetMesh(revmeshes[345]);
				objects[30]->SetMesh(revmeshes[346]);
				objects[31]->SetMesh(revmeshes[347]);
				objects[32]->SetMesh(revmeshes[348]);
			}
			else
			{
				objects[29]->SetMesh(meshes[345]);
				objects[30]->SetMesh(meshes[346]);
				objects[31]->SetMesh(meshes[347]);
				objects[32]->SetMesh(meshes[348]);
			}
		}
		else if (mission == 5)
		{
			int n = (m5_broken % 100) / 10;
			//진척도
			objects[25]->m_ppMaterials[0] = rm->materials[273 + n];
			n = m5_broken % 10;
			objects[26]->m_ppMaterials[0] = rm->materials[273 + n];

			//실패조건
			objects[27]->SetMesh(NULL);
			objects[28]->SetMesh(NULL);

			//제한시간 관련
			chrono::time_point<chrono::system_clock> mm = chrono::system_clock::now();
			chrono::seconds s = chrono::duration_cast<chrono::seconds>(mm - missionChangedTime);
			n = ((25-s.count()) % 1000) / 100;
			if (n < 0)
				n = 0;
			objects[30]->m_ppMaterials[0] = rm->materials[273 + n];
			n = ((25 - s.count()) % 100) / 10;
			if (n < 0)
				n = 0;
			objects[31]->m_ppMaterials[0] = rm->materials[273 + n];
			n = (25 - s.count()) % 10;
			if (n < 0)
				n = 0;
			objects[32]->m_ppMaterials[0] = rm->materials[273 + n];

			if (cl.z < 0.0f)
			{
				objects[29]->SetMesh(revmeshes[345]);
				objects[30]->SetMesh(revmeshes[346]);
				objects[31]->SetMesh(revmeshes[347]);
				objects[32]->SetMesh(revmeshes[348]);
			}
			else
			{
				objects[29]->SetMesh(meshes[345]);
				objects[30]->SetMesh(meshes[346]);
				objects[31]->SetMesh(meshes[347]);
				objects[32]->SetMesh(meshes[348]);
			}
		}
		else if (mission == 6)
		{
		int n = (m6_broken % 100) / 10;
		//진척도
		objects[25]->m_ppMaterials[0] = rm->materials[273 + n];
		n = m6_broken % 10;
		objects[26]->m_ppMaterials[0] = rm->materials[273 + n];

		//실패조건
		objects[27]->SetMesh(NULL);
		objects[28]->SetMesh(NULL);

		//제한시간 관련
		chrono::time_point<chrono::system_clock> mm = chrono::system_clock::now();
		chrono::seconds s = chrono::duration_cast<chrono::seconds>(mm - missionChangedTime);
		n = ((25 - s.count()) % 1000) / 100;

		if (n < 0)
			n = 0;
		objects[30]->m_ppMaterials[0] = rm->materials[273 + n];
		n = ((25 - s.count()) % 100) / 10;
		if (n < 0)
			n = 0;
		objects[31]->m_ppMaterials[0] = rm->materials[273 + n];
		n = (25-s.count()) % 10;
		if (n < 0)
			n = 0;
		objects[32]->m_ppMaterials[0] = rm->materials[273 + n];


		if (cl.z < 0.0f)
		{
			objects[29]->SetMesh(revmeshes[345]);
			objects[30]->SetMesh(revmeshes[346]);
			objects[31]->SetMesh(revmeshes[347]);
			objects[32]->SetMesh(revmeshes[348]);
		}
		else
		{
			objects[29]->SetMesh(meshes[345]);
			objects[30]->SetMesh(meshes[346]);
			objects[31]->SetMesh(meshes[347]);
			objects[32]->SetMesh(meshes[348]);
		}
		}
		else if (mission == 7)
		{
		int n = (m7_kill % 100) / 10;
		//진척도
		objects[25]->m_ppMaterials[0] = rm->materials[273 + n];
		n = m7_kill % 10;
		objects[26]->m_ppMaterials[0] = rm->materials[273 + n];

		//실패조건
		objects[27]->SetMesh(NULL);
		objects[28]->SetMesh(NULL);

		//제한시간 관련
		chrono::time_point<chrono::system_clock> mm = chrono::system_clock::now();
		chrono::seconds s = chrono::duration_cast<chrono::seconds>(mm - missionChangedTime);
		n = ((80 - s.count()) % 1000) / 100;
		if (n < 0)
			n = 0;
		objects[30]->m_ppMaterials[0] = rm->materials[273 + n];
		n = ((80 - s.count()) % 100) / 10;
		if (n < 0)
			n = 0;
		objects[31]->m_ppMaterials[0] = rm->materials[273 + n];
		n = (80-s.count()) % 10;
		if (n < 0)
			n = 0;
		objects[32]->m_ppMaterials[0] = rm->materials[273 + n];


		if (cl.z < 0.0f)
		{
			objects[29]->SetMesh(revmeshes[345]);
			objects[30]->SetMesh(revmeshes[346]);
			objects[31]->SetMesh(revmeshes[347]);
			objects[32]->SetMesh(revmeshes[348]);
		}
		else
		{
			objects[29]->SetMesh(meshes[345]);
			objects[30]->SetMesh(meshes[346]);
			objects[31]->SetMesh(meshes[347]);
			objects[32]->SetMesh(meshes[348]);
		}
		}

		else if (mission == 8)
		{
		
		
		//진척도
		objects[25]->m_ppMaterials[0] = rm->materials[273];
		
		objects[26]->m_ppMaterials[0] = rm->materials[273];
		

		
		//실패조건

		if (cl.z < 0.0f)
		{
			objects[27]->SetMesh(revmeshes[343]);
			objects[28]->SetMesh(revmeshes[344]);
		}
		else
		{
			objects[27]->SetMesh(meshes[343]);
			objects[28]->SetMesh(meshes[344]);
		}
		objects[28]->m_ppMaterials[0] = rm->materials[273 + m8_kill];

		//제한시간 관련
		chrono::time_point<chrono::system_clock> mm = chrono::system_clock::now();
		chrono::seconds s = chrono::duration_cast<chrono::seconds>(mm - missionChangedTime);
		int n = ((60 - s.count()) % 1000) / 100;
		if (n < 0)
			n = 0;
		objects[30]->m_ppMaterials[0] = rm->materials[273 + n];
		n = ((60 - s.count()) % 100) / 10;
		if (n < 0)
			n = 0;
		objects[31]->m_ppMaterials[0] = rm->materials[273 + n];
		n = (60-s.count()) % 10;
		if (n < 0)
			n = 0;
		objects[32]->m_ppMaterials[0] = rm->materials[273 + n];


		if (cl.z < 0.0f)
		{
			objects[29]->SetMesh(revmeshes[345]);
			objects[30]->SetMesh(revmeshes[346]);
			objects[31]->SetMesh(revmeshes[347]);
			objects[32]->SetMesh(revmeshes[348]);
		}
		else
		{
			objects[29]->SetMesh(meshes[345]);
			objects[30]->SetMesh(meshes[346]);
			objects[31]->SetMesh(meshes[347]);
			objects[32]->SetMesh(meshes[348]);
		}
		}

		else if (mission == 9)
		{
		int n = (m9_search % 100) / 10;
		//진척도
		objects[25]->m_ppMaterials[0] = rm->materials[273 + n];
		n = m9_search % 10;
		objects[26]->m_ppMaterials[0] = rm->materials[273 + n];

		//실패조건

		if (cl.z < 0.0f)
		{
			objects[27]->SetMesh(revmeshes[343]);
			objects[28]->SetMesh(revmeshes[344]);
		}
		else
		{
			objects[27]->SetMesh(meshes[343]);
			objects[28]->SetMesh(meshes[344]);
		}
		objects[28]->m_ppMaterials[0] = rm->materials[273 + m9_stun];


		//제한시간 관련
		objects[29]->SetMesh(NULL);
		objects[30]->SetMesh(NULL);
		objects[31]->SetMesh(NULL);
		objects[32]->SetMesh(NULL);
		}

		else if (mission == 10)
		{
		int n = (m10_gain % 100) / 10;
		//진척도
		objects[25]->m_ppMaterials[0] = rm->materials[273 + n];
		n = m10_gain % 10;
		objects[26]->m_ppMaterials[0] = rm->materials[273 + n];

		//실패조건
		objects[27]->SetMesh(NULL);
		objects[28]->SetMesh(NULL);

		//제한시간 관련
		chrono::time_point<chrono::system_clock> mm = chrono::system_clock::now();
		chrono::seconds s = chrono::duration_cast<chrono::seconds>(mm - missionChangedTime);
		n = ((30-s.count()) % 1000) / 100;
		if (n < 0)
			n = 0;
		objects[30]->m_ppMaterials[0] = rm->materials[273 + n];
		n = ((30 - s.count()) % 100) / 10;
		if (n < 0)
			n = 0;
		objects[31]->m_ppMaterials[0] = rm->materials[273 + n];
		n = (30-s.count()) % 10;
		if (n < 0)
			n = 0;
		objects[32]->m_ppMaterials[0] = rm->materials[273 + n];


		if (cl.z < 0.0f)
		{
			objects[29]->SetMesh(revmeshes[345]);
			objects[30]->SetMesh(revmeshes[346]);
			objects[31]->SetMesh(revmeshes[347]);
			objects[32]->SetMesh(revmeshes[348]);
		}
		else
		{
			objects[29]->SetMesh(meshes[345]);
			objects[30]->SetMesh(meshes[346]);
			objects[31]->SetMesh(meshes[347]);
			objects[32]->SetMesh(meshes[348]);
		}
		}
	}
	else
	{
		for (int i = 8; i < 23; ++i)
		{
			if (cl.z < 0.0f)
			{
				objects[i]->SetMesh(revmeshes[316 + i]);
			}
			else
			{
				objects[i]->SetMesh(meshes[316 + i]);
			}
		}
	}
	
	if (missionFail == false)
	{
		objects[33]->SetMesh(NULL);
	}
	else
	{
		objects[33]->m_ppMaterials[0] = rm->materials[338];
		if (cl.z < 0.0f)
		{
			objects[33]->SetMesh(revmeshes[349]);
		}
		else
		{
			objects[33]->SetMesh(meshes[349]);
		}

	}

	chrono::time_point<chrono::system_clock> mmt = chrono::system_clock::now();

	chrono::duration<double> ddt = mmt - lastNarrated;
	if (ddt.count() > nDuration)
	{
		narrationShow = false;
	}

	if (narrationShow == true)
	{
		if (cl.z < 0.0f)
		{
			objects[34]->SetMesh(revmeshes[350]);

		}
		else
		{
			objects[34]->SetMesh(meshes[350]);
		}
	}
	else
	{
		objects[34]->SetMesh(NULL);
	}
}

void InterfaceShader::ShowNarration(int idx, double dur)
{
	nDuration = dur;
	lastNarrated = chrono::system_clock::now();
	narrationShow = true;
	objects[34]->m_ppMaterials[0] = rm->materials[idx];
	
}