#include "ProfileShader.h"


ProfileShader::ProfileShader(ResourceManager* r)
{
	rm = r;
	
}
ProfileShader::~ProfileShader() {}

void ProfileShader::BuildObjects(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList)
{

	//윈도우 크기 450픽셀당 1.0f로 환산.

	// 메쉬 생성자 인자 : x크기, y크기, z크기, x중점, y중점

	//크기는 픽셀수/450, x중점은 (위치-600)/450, y중점은 크기 -(위치-450)/450

	//UI 개체 생성자 인자 : 1, x1, y1, x2, y2, idx

	// x1, y1, x2, y2는 클릭 영역의 시작점과 끝점 픽셀
	// idx는 버튼의 기본상태 텍스처 번호
	// 버튼이 아닌 객체들은 전부 -1로 설정
	
	CubeMeshOffset* main = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 1200.0f/450.0f, 2.0f, 0.01f, 0.0f, 0.0f, false);
	CubeMeshOffset* mainr = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 1200.0f/450.0f, 2.0f, 0.01f, 0.0f, 0.0f, true);

	CubeMeshOffset* storage = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 203.0f / 450.0f, 46.0f / 450.0f, 0.01f, (202.0f - 600.0f) / 450.0f, -(697.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* storager = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 203.0f / 450.0f, 46.0f / 450.0f, 0.01f, (202.0f - 600.0f) / 450.0f, -(697.0f - 450.0f) / 450.0f, true);

	CubeMeshOffset* back = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 203.0f / 450.0f, 46.0f / 450.0f, 0.01f, (194.0f - 600.0f) / 450.0f, -(157.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* backr = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 203.0f / 450.0f, 46.0f / 450.0f, 0.01f, (194.0f - 600.0f) / 450.0f, -(157.0f - 450.0f) / 450.0f, true);

	//여기서부터 숫자.

	//total level/exp
	CubeMeshOffset* lv_total1 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.01f, (600.0f - 600.0f) / 450.0f, -(159.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* lv_total2 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.01f, (620.0f - 600.0f) / 450.0f, -(159.0f - 450.0f) / 450.0f, false);

	CubeMeshOffset* exp_total1 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 10.0f / 450.0f, 18.0f / 450.0f, 0.01f, (520.0f - 600.0f) / 450.0f, -(210.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* exp_total2 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 10.0f / 450.0f, 18.0f / 450.0f, 0.01f, (535.0f - 600.0f) / 450.0f, -(210.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* exp_total3 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 10.0f / 450.0f, 18.0f / 450.0f, 0.01f, (550.0f - 600.0f) / 450.0f, -(210.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* exp_total4 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 10.0f / 450.0f, 18.0f / 450.0f, 0.01f, (565.0f - 600.0f) / 450.0f, -(210.0f - 450.0f) / 450.0f, false);

	CubeMeshOffset* exp_total5 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 10.0f / 450.0f, 18.0f / 450.0f, 0.01f, (615.0f - 600.0f) / 450.0f, -(210.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* exp_total6 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 10.0f / 450.0f, 18.0f / 450.0f, 0.01f, (630.0f - 600.0f) / 450.0f, -(210.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* exp_total7 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 10.0f / 450.0f, 18.0f / 450.0f, 0.01f, (645.0f - 600.0f) / 450.0f, -(210.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* exp_total8 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 10.0f / 450.0f, 18.0f / 450.0f, 0.01f, (660.0f - 600.0f) / 450.0f, -(210.0f - 450.0f) / 450.0f, false);

	//melee level/exp

	CubeMeshOffset* exp_melee1 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 10.0f / 450.0f, 18.0f / 450.0f, 0.01f, (145.0f - 600.0f) / 450.0f, -(300.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* exp_melee2 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 10.0f / 450.0f, 18.0f / 450.0f, 0.01f, (160.0f - 600.0f) / 450.0f, -(300.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* exp_melee3 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 10.0f / 450.0f, 18.0f / 450.0f, 0.01f, (175.0f - 600.0f) / 450.0f, -(300.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* exp_melee4 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 10.0f / 450.0f, 18.0f / 450.0f, 0.01f, (190.0f - 600.0f) / 450.0f, -(300.0f - 450.0f) / 450.0f, false);

	CubeMeshOffset* exp_melee5 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 10.0f / 450.0f, 18.0f / 450.0f, 0.01f, (230.0f - 600.0f) / 450.0f, -(300.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* exp_melee6 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 10.0f / 450.0f, 18.0f / 450.0f, 0.01f, (245.0f - 600.0f) / 450.0f, -(300.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* exp_melee7 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 10.0f / 450.0f, 18.0f / 450.0f, 0.01f, (260.0f - 600.0f) / 450.0f, -(300.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* exp_melee8 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 10.0f / 450.0f, 18.0f / 450.0f, 0.01f, (275.0f - 600.0f) / 450.0f, -(300.0f - 450.0f) / 450.0f, false);

	CubeMeshOffset* lv_melee1 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.01f, (250.0f - 600.0f) / 450.0f, -(270.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* lv_melee2 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.01f, (270.0f - 600.0f) / 450.0f, -(270.0f - 450.0f) / 450.0f, false);

	//ranged level/exp

	CubeMeshOffset* exp_ranged1 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 10.0f / 450.0f, 18.0f / 450.0f, 0.01f, (145.0f - 600.0f) / 450.0f, -(423.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* exp_ranged2 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 10.0f / 450.0f, 18.0f / 450.0f, 0.01f, (160.0f - 600.0f) / 450.0f, -(423.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* exp_ranged3 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 10.0f / 450.0f, 18.0f / 450.0f, 0.01f, (175.0f - 600.0f) / 450.0f, -(423.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* exp_ranged4 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 10.0f / 450.0f, 18.0f / 450.0f, 0.01f, (190.0f - 600.0f) / 450.0f, -(423.0f - 450.0f) / 450.0f, false);
						
	CubeMeshOffset* exp_ranged5 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 10.0f / 450.0f, 18.0f / 450.0f, 0.01f, (230.0f - 600.0f) / 450.0f, -(423.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* exp_ranged6 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 10.0f / 450.0f, 18.0f / 450.0f, 0.01f, (245.0f - 600.0f) / 450.0f, -(423.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* exp_ranged7 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 10.0f / 450.0f, 18.0f / 450.0f, 0.01f, (260.0f - 600.0f) / 450.0f, -(423.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* exp_ranged8 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 10.0f / 450.0f, 18.0f / 450.0f, 0.01f, (275.0f - 600.0f) / 450.0f, -(423.0f - 450.0f) / 450.0f, false);

	CubeMeshOffset* lv_ranged1 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.01f, (250.0f - 600.0f) / 450.0f, -(393.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* lv_ranged2 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.01f, (270.0f - 600.0f) / 450.0f, -(393.0f - 450.0f) / 450.0f, false);

	// radio level/exp

	CubeMeshOffset* exp_radio1 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 10.0f / 450.0f, 18.0f / 450.0f, 0.01f, (145.0f - 600.0f) / 450.0f, -(547.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* exp_radio2 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 10.0f / 450.0f, 18.0f / 450.0f, 0.01f, (160.0f - 600.0f) / 450.0f, -(547.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* exp_radio3 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 10.0f / 450.0f, 18.0f / 450.0f, 0.01f, (175.0f - 600.0f) / 450.0f, -(547.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* exp_radio4 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 10.0f / 450.0f, 18.0f / 450.0f, 0.01f, (190.0f - 600.0f) / 450.0f, -(547.0f - 450.0f) / 450.0f, false);
						 
	CubeMeshOffset* exp_radio5 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 10.0f / 450.0f, 18.0f / 450.0f, 0.01f, (230.0f - 600.0f) / 450.0f, -(547.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* exp_radio6 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 10.0f / 450.0f, 18.0f / 450.0f, 0.01f, (245.0f - 600.0f) / 450.0f, -(547.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* exp_radio7 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 10.0f / 450.0f, 18.0f / 450.0f, 0.01f, (260.0f - 600.0f) / 450.0f, -(547.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* exp_radio8 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 10.0f / 450.0f, 18.0f / 450.0f, 0.01f, (275.0f - 600.0f) / 450.0f, -(547.0f - 450.0f) / 450.0f, false);

	CubeMeshOffset* lv_radio1 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.01f, (250.0f - 600.0f) / 450.0f, -(518.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* lv_radio2 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.01f, (270.0f - 600.0f) / 450.0f, -(518.0f - 450.0f) / 450.0f, false);

	//gold

	CubeMeshOffset* gold1 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.01f, (910.0f - 600.0f) / 450.0f, -(155.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* gold2 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.01f, (930.0f - 600.0f) / 450.0f, -(155.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* gold3 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.01f, (950.0f - 600.0f) / 450.0f, -(155.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* gold4 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.01f, (970.0f - 600.0f) / 450.0f, -(155.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* gold5 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.01f, (990.0f - 600.0f) / 450.0f, -(155.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* gold6 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.01f, (1010.0f - 600.0f) / 450.0f, -(155.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* gold7 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.01f, (1030.0f - 600.0f) / 450.0f, -(155.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* gold8 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.01f, (1050.0f - 600.0f) / 450.0f, -(155.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* gold9 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.01f, (1070.0f - 600.0f) / 450.0f, -(155.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* gold10 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.01f, (1090.0f - 600.0f) / 450.0f, -(155.0f - 450.0f) / 450.0f, false);

	CubeMeshOffset* cap_stat1 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.01f, (625.0f - 600.0f) / 450.0f, -(382.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* cap_stat2 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.01f, (645.0f - 600.0f) / 450.0f, -(382.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* cap_plus = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 20.0f / 450.0f, 20.0f / 450.0f, 0.01f, (687.0f - 600.0f) / 450.0f, -(382.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* cap_minus = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 20.0f / 450.0f, 20.0f / 450.0f, 0.01f, (714.0f - 600.0f) / 450.0f, -(382.0f - 450.0f) / 450.0f, false);

	CubeMeshOffset* hard_stat1 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.01f, (625.0f - 600.0f) / 450.0f, -(440.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* hard_stat2 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.01f, (645.0f - 600.0f) / 450.0f, -(440.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* hard_plus = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 20.0f / 450.0f, 20.0f / 450.0f, 0.01f, (687.0f - 600.0f) / 450.0f, -(440.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* hard_minus = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 20.0f / 450.0f, 20.0f / 450.0f, 0.01f, (714.0f - 600.0f) / 450.0f, -(440.0f - 450.0f) / 450.0f, false);

	CubeMeshOffset* out_stat1 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.01f, (625.0f - 600.0f) / 450.0f, -(498.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* out_stat2 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.01f, (645.0f - 600.0f) / 450.0f, -(498.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* out_plus = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 20.0f / 450.0f, 20.0f / 450.0f, 0.01f, (687.0f - 600.0f) / 450.0f, -(498.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* out_minus = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 20.0f / 450.0f, 20.0f / 450.0f, 0.01f, (714.0f - 600.0f) / 450.0f, -(498.0f - 450.0f) / 450.0f, false);

	CubeMeshOffset* prec_stat1 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.01f, (625.0f - 600.0f) / 450.0f, -(556.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* prec_stat2 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.01f, (645.0f - 600.0f) / 450.0f, -(556.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* prec_plus = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 20.0f / 450.0f, 20.0f / 450.0f, 0.01f, (687.0f - 600.0f) / 450.0f, -(556.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* prec_minus = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 20.0f / 450.0f, 20.0f / 450.0f, 0.01f, (714.0f - 600.0f) / 450.0f, -(556.0f - 450.0f) / 450.0f, false);

	CubeMeshOffset* ent_stat1 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.01f, (625.0f - 600.0f) / 450.0f, -(614.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* ent_stat2 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.01f, (645.0f - 600.0f) / 450.0f, -(614.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* ent_plus = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 20.0f / 450.0f, 20.0f / 450.0f, 0.01f, (687.0f - 600.0f) / 450.0f, -(614.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* ent_minus = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 20.0f / 450.0f, 20.0f / 450.0f, 0.01f, (714.0f - 600.0f) / 450.0f, -(614.0f - 450.0f) / 450.0f, false);

	CubeMeshOffset* extra1 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.01f, (682.0f - 600.0f) / 450.0f, -(655.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* extra2 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.01f, (702.0f - 600.0f) / 450.0f, -(655.0f - 450.0f) / 450.0f, false);
	

	meshes.push_back(main);
	meshesRev.push_back(mainr);

	meshes.push_back(storage);
	meshesRev.push_back(storager);

	meshes.push_back(back);
	meshesRev.push_back(backr);

	meshes.push_back(lv_total1);
	meshes.push_back(lv_total2);
	meshes.push_back(exp_total1);
	meshes.push_back(exp_total2);
	meshes.push_back(exp_total3);
	meshes.push_back(exp_total4);
	meshes.push_back(exp_total5);
	meshes.push_back(exp_total6);
	meshes.push_back(exp_total7);
	meshes.push_back(exp_total8);

	meshes.push_back(lv_melee1);
	meshes.push_back(lv_melee2);
	meshes.push_back(exp_melee1);
	meshes.push_back(exp_melee2);
	meshes.push_back(exp_melee3);
	meshes.push_back(exp_melee4);
	meshes.push_back(exp_melee5);
	meshes.push_back(exp_melee6);
	meshes.push_back(exp_melee7);
	meshes.push_back(exp_melee8);
	
	meshes.push_back(lv_ranged1);
	meshes.push_back(lv_ranged2);
	meshes.push_back(exp_ranged1);
	meshes.push_back(exp_ranged2);
	meshes.push_back(exp_ranged3);
	meshes.push_back(exp_ranged4);
	meshes.push_back(exp_ranged5);
	meshes.push_back(exp_ranged6);
	meshes.push_back(exp_ranged7);
	meshes.push_back(exp_ranged8);

	meshes.push_back(lv_radio1);
	meshes.push_back(lv_radio2);
	meshes.push_back(exp_radio1);
	meshes.push_back(exp_radio2);
	meshes.push_back(exp_radio3);
	meshes.push_back(exp_radio4);
	meshes.push_back(exp_radio5);
	meshes.push_back(exp_radio6);
	meshes.push_back(exp_radio7);
	meshes.push_back(exp_radio8);

	meshes.push_back(gold1);
	meshes.push_back(gold2);
	meshes.push_back(gold3);
	meshes.push_back(gold4);
	meshes.push_back(gold5);
	meshes.push_back(gold6);
	meshes.push_back(gold7);
	meshes.push_back(gold8);
	meshes.push_back(gold9);
	meshes.push_back(gold10);

	meshes.push_back(cap_stat1);
	meshes.push_back(cap_stat2);
	meshes.push_back(cap_plus);
	meshes.push_back(cap_minus);

	meshes.push_back(hard_stat1);
	meshes.push_back(hard_stat2);
	meshes.push_back(hard_plus);
	meshes.push_back(hard_minus);

	meshes.push_back(out_stat1);
	meshes.push_back(out_stat2);
	meshes.push_back(out_plus);
	meshes.push_back(out_minus);

	meshes.push_back(prec_stat1);
	meshes.push_back(prec_stat2);
	meshes.push_back(prec_plus);
	meshes.push_back(prec_minus);

	meshes.push_back(ent_stat1);
	meshes.push_back(ent_stat2);
	meshes.push_back(ent_plus);
	meshes.push_back(ent_minus);

	meshes.push_back(extra1);
	meshes.push_back(extra2);
	


	meshesRev.push_back(lv_total1);
	meshesRev.push_back(lv_total2);
	meshesRev.push_back(exp_total1);
	meshesRev.push_back(exp_total2);
	meshesRev.push_back(exp_total3);
	meshesRev.push_back(exp_total4);
	meshesRev.push_back(exp_total5);
	meshesRev.push_back(exp_total6);
	meshesRev.push_back(exp_total7);
	meshesRev.push_back(exp_total8);

	meshesRev.push_back(lv_melee1);
	meshesRev.push_back(lv_melee2);
	meshesRev.push_back(exp_melee1);
	meshesRev.push_back(exp_melee2);
	meshesRev.push_back(exp_melee3);
	meshesRev.push_back(exp_melee4);
	meshesRev.push_back(exp_melee5);
	meshesRev.push_back(exp_melee6);
	meshesRev.push_back(exp_melee7);
	meshesRev.push_back(exp_melee8);

	meshesRev.push_back(lv_ranged1);
	meshesRev.push_back(lv_ranged2);
	meshesRev.push_back(exp_ranged1);
	meshesRev.push_back(exp_ranged2);
	meshesRev.push_back(exp_ranged3);
	meshesRev.push_back(exp_ranged4);
	meshesRev.push_back(exp_ranged5);
	meshesRev.push_back(exp_ranged6);
	meshesRev.push_back(exp_ranged7);
	meshesRev.push_back(exp_ranged8);

	meshesRev.push_back(lv_radio1);
	meshesRev.push_back(lv_radio2);
	meshesRev.push_back(exp_radio1);
	meshesRev.push_back(exp_radio2);
	meshesRev.push_back(exp_radio3);
	meshesRev.push_back(exp_radio4);
	meshesRev.push_back(exp_radio5);
	meshesRev.push_back(exp_radio6);
	meshesRev.push_back(exp_radio7);
	meshesRev.push_back(exp_radio8);

	meshesRev.push_back(gold1);
	meshesRev.push_back(gold2);
	meshesRev.push_back(gold3);
	meshesRev.push_back(gold4);
	meshesRev.push_back(gold5);
	meshesRev.push_back(gold6);
	meshesRev.push_back(gold7);
	meshesRev.push_back(gold8);
	meshesRev.push_back(gold9);
	meshesRev.push_back(gold10);

	UIObject* obj = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj2 = new UIObject(1, 100, 674,  304, 720, 228);
	UIObject* obj3 = new UIObject(1, 92, 134, 296, 180, 235);
	
	UIObject* obj4 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj5 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj6 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj7 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj8 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj9 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj10 = new UIObject(1, -1, -1, -1, -1, -1);

	UIObject* obj11 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj12 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj13 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj14 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj15 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj16 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj17 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj18 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj19 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj20 = new UIObject(1, -1, -1, -1, -1, -1);

	UIObject* obj21 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj22 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj23 = new UIObject(1, -1, -1, -1, -1, -1);
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
	UIObject* obj36 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj37 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj38 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj39 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj40 = new UIObject(1, -1, -1, -1, -1, -1);

	UIObject* obj41 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj42 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj43 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj44 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj45 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj46 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj47 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj48 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj49 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj50 = new UIObject(1, -1, -1, -1, -1, -1);

	UIObject* obj51 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj52 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj53 = new UIObject(1, -1, -1, -1, -1, -1);

	//여기서부터 스탯
	//cap
	UIObject* obj54 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj55 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj56 = new UIObject(1, 677, 402, 697, 422, 233);
	UIObject* obj57 = new UIObject(1, 704, 402, 724, 422, 231);
	//hard
	UIObject* obj58 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj59 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj60 = new UIObject(1, 677, 460, 697, 480, 233);
	UIObject* obj61 = new UIObject(1, 704, 460, 724, 480, 231);
	//out
	UIObject* obj62 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj63 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj64 = new UIObject(1, 677, 518, 697, 538, 233);
	UIObject* obj65 = new UIObject(1, 704, 518, 724, 538, 231);

	//prec
	UIObject* obj66 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj67 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj68 = new UIObject(1, 677, 576, 697, 596, 233);
	UIObject* obj69 = new UIObject(1, 704, 576, 724, 596, 231);

	//entrophy
	UIObject* obj70 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj71 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj72 = new UIObject(1, 677, 634, 697, 654, 233);
	UIObject* obj73 = new UIObject(1, 704, 634, 724, 654, 231);

	//extra point
	//out
	UIObject* obj74 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj75 = new UIObject(1, -1, -1, -1, -1, -1);
	

	obj->SetMesh(meshes[0]);
	obj->SetMaterial(0, rm->materials[227]);
	obj->SetPosition(0.0f, 0.0f, 0.0f);

	obj2->SetMesh(meshes[1]);
	obj2->SetMaterial(0, rm->materials[228]);
	obj2->SetPosition(0.0f, 0.0f, 0.0f);

	obj3->SetMesh(meshes[1]);
	obj3->SetMaterial(0, rm->materials[235]);
	obj3->SetPosition(0.0f, 0.0f, 0.0f);

	obj4->SetMesh(meshes[3]);
	obj4->SetMaterial(0, rm->materials[252]);
	obj4->SetPosition(0.0f, 0.0f, 0.0f);

	obj5->SetMesh(meshes[4]);
	obj5->SetMaterial(0, rm->materials[252]);
	obj5->SetPosition(0.0f, 0.0f, 0.0f);

	obj6->SetMesh(meshes[5]);
	obj6->SetMaterial(0, rm->materials[252]);
	obj6->SetPosition(0.0f, 0.0f, 0.0f);

	obj7->SetMesh(meshes[6]);
	obj7->SetMaterial(0, rm->materials[252]);
	obj7->SetPosition(0.0f, 0.0f, 0.0f);

	obj8->SetMesh(meshes[7]);
	obj8->SetMaterial(0, rm->materials[252]);
	obj8->SetPosition(0.0f, 0.0f, 0.0f);

	obj9->SetMesh(meshes[8]);
	obj9->SetMaterial(0, rm->materials[252]);
	obj9->SetPosition(0.0f, 0.0f, 0.0f);

	obj10->SetMesh(meshes[9]);
	obj10->SetMaterial(0, rm->materials[252]);
	obj10->SetPosition(0.0f, 0.0f, 0.0f);

	obj11->SetMesh(meshes[10]);
	obj11->SetMaterial(0, rm->materials[252]);
	obj11->SetPosition(0.0f, 0.0f, 0.0f);
	obj12->SetMesh(meshes[11]);
	obj12->SetMaterial(0, rm->materials[252]);
	obj12->SetPosition(0.0f, 0.0f, 0.0f);
	obj13->SetMesh(meshes[12]);
	obj13->SetMaterial(0, rm->materials[252]);
	obj13->SetPosition(0.0f, 0.0f, 0.0f);
	obj14->SetMesh(meshes[13]);
	obj14->SetMaterial(0, rm->materials[252]);
	obj14->SetPosition(0.0f, 0.0f, 0.0f);
	obj15->SetMesh(meshes[14]);
	obj15->SetMaterial(0, rm->materials[252]);
	obj15->SetPosition(0.0f, 0.0f, 0.0f);
	obj16->SetMesh(meshes[15]);
	obj16->SetMaterial(0, rm->materials[252]);
	obj16->SetPosition(0.0f, 0.0f, 0.0f);
	obj17->SetMesh(meshes[16]);
	obj17->SetMaterial(0, rm->materials[252]);
	obj17->SetPosition(0.0f, 0.0f, 0.0f);
	obj18->SetMesh(meshes[17]);
	obj18->SetMaterial(0, rm->materials[252]);
	obj18->SetPosition(0.0f, 0.0f, 0.0f);
	obj19->SetMesh(meshes[18]);
	obj19->SetMaterial(0, rm->materials[252]);
	obj19->SetPosition(0.0f, 0.0f, 0.0f);
	obj20->SetMesh(meshes[19]);
	obj20->SetMaterial(0, rm->materials[252]);
	obj20->SetPosition(0.0f, 0.0f, 0.0f);

	obj21->SetMesh(meshes[20]);
	obj21->SetMaterial(0, rm->materials[252]);
	obj21->SetPosition(0.0f, 0.0f, 0.0f);
	obj22->SetMesh(meshes[21]);
	obj22->SetMaterial(0, rm->materials[252]);
	obj22->SetPosition(0.0f, 0.0f, 0.0f);
	obj23->SetMesh(meshes[22]);
	obj23->SetMaterial(0, rm->materials[252]);
	obj23->SetPosition(0.0f, 0.0f, 0.0f);
	obj24->SetMesh(meshes[23]);
	obj24->SetMaterial(0, rm->materials[252]);
	obj24->SetPosition(0.0f, 0.0f, 0.0f);
	obj25->SetMesh(meshes[24]);
	obj25->SetMaterial(0, rm->materials[252]);
	obj25->SetPosition(0.0f, 0.0f, 0.0f);
	obj26->SetMesh(meshes[25]);
	obj26->SetMaterial(0, rm->materials[252]);
	obj26->SetPosition(0.0f, 0.0f, 0.0f);
	obj27->SetMesh(meshes[26]);
	obj27->SetMaterial(0, rm->materials[252]);
	obj27->SetPosition(0.0f, 0.0f, 0.0f);
	obj28->SetMesh(meshes[27]);
	obj28->SetMaterial(0, rm->materials[252]);
	obj28->SetPosition(0.0f, 0.0f, 0.0f);
	obj29->SetMesh(meshes[28]);
	obj29->SetMaterial(0, rm->materials[252]);
	obj29->SetPosition(0.0f, 0.0f, 0.0f);
	obj30->SetMesh(meshes[29]);
	obj30->SetMaterial(0, rm->materials[252]);
	obj30->SetPosition(0.0f, 0.0f, 0.0f);

	obj31->SetMesh(meshes[30]);
	obj31->SetMaterial(0, rm->materials[252]);
	obj31->SetPosition(0.0f, 0.0f, 0.0f);
	obj32->SetMesh(meshes[31]);
	obj32->SetMaterial(0, rm->materials[252]);
	obj32->SetPosition(0.0f, 0.0f, 0.0f);
	obj33->SetMesh(meshes[32]);
	obj33->SetMaterial(0, rm->materials[252]);
	obj33->SetPosition(0.0f, 0.0f, 0.0f);
	obj34->SetMesh(meshes[33]);
	obj34->SetMaterial(0, rm->materials[252]);
	obj34->SetPosition(0.0f, 0.0f, 0.0f);
	obj35->SetMesh(meshes[34]);
	obj35->SetMaterial(0, rm->materials[252]);
	obj35->SetPosition(0.0f, 0.0f, 0.0f);
	obj36->SetMesh(meshes[35]);
	obj36->SetMaterial(0, rm->materials[252]);
	obj36->SetPosition(0.0f, 0.0f, 0.0f);
	obj37->SetMesh(meshes[36]);
	obj37->SetMaterial(0, rm->materials[252]);
	obj37->SetPosition(0.0f, 0.0f, 0.0f);
	obj38->SetMesh(meshes[37]);
	obj38->SetMaterial(0, rm->materials[252]);
	obj38->SetPosition(0.0f, 0.0f, 0.0f);
	obj39->SetMesh(meshes[38]);
	obj39->SetMaterial(0, rm->materials[252]);
	obj39->SetPosition(0.0f, 0.0f, 0.0f);
	obj40->SetMesh(meshes[39]);
	obj40->SetMaterial(0, rm->materials[252]);
	obj40->SetPosition(0.0f, 0.0f, 0.0f);

	obj41->SetMesh(meshes[40]);
	obj41->SetMaterial(0, rm->materials[252]);
	obj41->SetPosition(0.0f, 0.0f, 0.0f);
	obj42->SetMesh(meshes[41]);
	obj42->SetMaterial(0, rm->materials[252]);
	obj42->SetPosition(0.0f, 0.0f, 0.0f);
	obj43->SetMesh(meshes[42]);
	obj43->SetMaterial(0, rm->materials[252]);
	obj43->SetPosition(0.0f, 0.0f, 0.0f);
	obj44->SetMesh(meshes[43]);
	obj44->SetMaterial(0, rm->materials[252]);
	obj44->SetPosition(0.0f, 0.0f, 0.0f);
	obj45->SetMesh(meshes[44]);
	obj45->SetMaterial(0, rm->materials[252]);
	obj45->SetPosition(0.0f, 0.0f, 0.0f);
	obj46->SetMesh(meshes[45]);
	obj46->SetMaterial(0, rm->materials[252]);
	obj46->SetPosition(0.0f, 0.0f, 0.0f);
	obj47->SetMesh(meshes[46]);
	obj47->SetMaterial(0, rm->materials[252]);
	obj47->SetPosition(0.0f, 0.0f, 0.0f);
	obj48->SetMesh(meshes[47]);
	obj48->SetMaterial(0, rm->materials[252]);
	obj48->SetPosition(0.0f, 0.0f, 0.0f);
	obj49->SetMesh(meshes[48]);
	obj49->SetMaterial(0, rm->materials[252]);
	obj49->SetPosition(0.0f, 0.0f, 0.0f);
	obj50->SetMesh(meshes[49]);
	obj50->SetMaterial(0, rm->materials[252]);
	obj50->SetPosition(0.0f, 0.0f, 0.0f);

	obj51->SetMesh(meshes[50]);
	obj51->SetMaterial(0, rm->materials[252]);
	obj51->SetPosition(0.0f, 0.0f, 0.0f);
	obj52->SetMesh(meshes[51]);
	obj52->SetMaterial(0, rm->materials[252]);
	obj52->SetPosition(0.0f, 0.0f, 0.0f);
	obj53->SetMesh(meshes[52]);
	obj53->SetMaterial(0, rm->materials[252]);
	obj53->SetPosition(0.0f, 0.0f, 0.0f);

	obj54->SetMesh(meshes[53]);
	obj54->SetMaterial(0, rm->materials[252]);
	obj54->SetPosition(0.0f, 0.0f, 0.0f);
	obj55->SetMesh(meshes[54]);
	obj55->SetMaterial(0, rm->materials[252]);
	obj55->SetPosition(0.0f, 0.0f, 0.0f);
	obj56->SetMesh(meshes[55]);
	obj56->SetMaterial(0, rm->materials[233]);
	obj56->SetPosition(0.0f, 0.0f, 0.0f);
	obj57->SetMesh(meshes[56]);
	obj57->SetMaterial(0, rm->materials[231]);
	obj57->SetPosition(0.0f, 0.0f, 0.0f);


	obj58->SetMesh(meshes[57]);
	obj58->SetMaterial(0, rm->materials[252]);
	obj58->SetPosition(0.0f, 0.0f, 0.0f);
	obj59->SetMesh(meshes[58]);
	obj59->SetMaterial(0, rm->materials[252]);
	obj59->SetPosition(0.0f, 0.0f, 0.0f);
	obj60->SetMesh(meshes[59]);
	obj60->SetMaterial(0, rm->materials[233]);
	obj60->SetPosition(0.0f, 0.0f, 0.0f);
	obj61->SetMesh(meshes[60]);
	obj61->SetMaterial(0, rm->materials[231]);
	obj61->SetPosition(0.0f, 0.0f, 0.0f);

	obj62->SetMesh(meshes[61]);
	obj62->SetMaterial(0, rm->materials[252]);
	obj62->SetPosition(0.0f, 0.0f, 0.0f);
	obj63->SetMesh(meshes[62]);
	obj63->SetMaterial(0, rm->materials[252]);
	obj63->SetPosition(0.0f, 0.0f, 0.0f);
	obj64->SetMesh(meshes[63]);
	obj64->SetMaterial(0, rm->materials[233]);
	obj64->SetPosition(0.0f, 0.0f, 0.0f);
	obj65->SetMesh(meshes[64]);
	obj65->SetMaterial(0, rm->materials[231]);
	obj65->SetPosition(0.0f, 0.0f, 0.0f);

	obj66->SetMesh(meshes[65]);
	obj66->SetMaterial(0, rm->materials[252]);
	obj66->SetPosition(0.0f, 0.0f, 0.0f);
	obj67->SetMesh(meshes[66]);
	obj67->SetMaterial(0, rm->materials[252]);
	obj67->SetPosition(0.0f, 0.0f, 0.0f);
	obj68->SetMesh(meshes[67]);
	obj68->SetMaterial(0, rm->materials[233]);
	obj68->SetPosition(0.0f, 0.0f, 0.0f);
	obj69->SetMesh(meshes[68]);
	obj69->SetMaterial(0, rm->materials[231]);
	obj69->SetPosition(0.0f, 0.0f, 0.0f);

	obj70->SetMesh(meshes[69]);
	obj70->SetMaterial(0, rm->materials[252]);
	obj70->SetPosition(0.0f, 0.0f, 0.0f);
	obj71->SetMesh(meshes[70]);
	obj71->SetMaterial(0, rm->materials[252]);
	obj71->SetPosition(0.0f, 0.0f, 0.0f);
	obj72->SetMesh(meshes[71]);
	obj72->SetMaterial(0, rm->materials[233]);
	obj72->SetPosition(0.0f, 0.0f, 0.0f);
	obj73->SetMesh(meshes[72]);
	obj73->SetMaterial(0, rm->materials[231]);
	obj73->SetPosition(0.0f, 0.0f, 0.0f);

	obj74->SetMesh(meshes[73]);
	obj74->SetMaterial(0, rm->materials[252]);
	obj74->SetPosition(0.0f, 0.0f, 0.0f);
	obj75->SetMesh(meshes[74]);
	obj75->SetMaterial(0, rm->materials[252]);
	obj75->SetPosition(0.0f, 0.0f, 0.0f);

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
	objects.push_back(obj36);
	objects.push_back(obj37);
	objects.push_back(obj38);
	objects.push_back(obj39);

	objects.push_back(obj40);
	objects.push_back(obj41);
	objects.push_back(obj42);
	objects.push_back(obj43);
	objects.push_back(obj44);
	objects.push_back(obj45);
	objects.push_back(obj46);
	objects.push_back(obj47);
	objects.push_back(obj48);
	objects.push_back(obj49);

	objects.push_back(obj50);
	objects.push_back(obj51);
	objects.push_back(obj52);
	objects.push_back(obj53);
	objects.push_back(obj54);
	objects.push_back(obj55);
	objects.push_back(obj56);
	objects.push_back(obj57);
	objects.push_back(obj58);
	objects.push_back(obj59);

	objects.push_back(obj60);
	objects.push_back(obj61);
	objects.push_back(obj62);
	objects.push_back(obj63);
	objects.push_back(obj64);
	objects.push_back(obj65);
	objects.push_back(obj66);
	objects.push_back(obj67);
	objects.push_back(obj68);
	objects.push_back(obj69);

	objects.push_back(obj70);
	objects.push_back(obj71);
	objects.push_back(obj72);
	objects.push_back(obj73);
	objects.push_back(obj74);
	objects.push_back(obj75);
}

void ProfileShader::ReleaseObjects()
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
void ProfileShader::ReleaseUploadBuffers()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->ReleaseUploadBuffers();
		}
	}
}

void ProfileShader::ReleaseShaderVariables()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->ReleaseShaderVariables();
		}
	}
}

void ProfileShader::Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera)
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->Render(pd3dCommandList, pCamera);
		}
	}
}

D3D12_INPUT_LAYOUT_DESC ProfileShader::CreateInputLayout()
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

D3D12_RASTERIZER_DESC ProfileShader::CreateRasterizerState()
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

D3D12_DEPTH_STENCIL_DESC ProfileShader::CreateDepthStencilState()
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

D3D12_SHADER_BYTECODE ProfileShader::CreateVertexShader()
{
	return(CShader::CompileShaderFromFile(L"interface.hlsl", "vsInterface", "vs_5_1", &m_pd3dVertexShaderBlob));
}

D3D12_SHADER_BYTECODE ProfileShader::CreatePixelShader()
{
	return(CShader::CompileShaderFromFile(L"interface.hlsl", "psInterface", "ps_5_1", &m_pd3dPixelShaderBlob));
}

void ProfileShader::Animate(CCamera* cam, PlayerInfoManager* in)
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
		if (cl.z < 0)
		{
			objects[i]->SetMesh(meshesRev[i]);
		}
		else
		{
			objects[i]->SetMesh(meshes[i]);
		}
		
		objects[i]->Rotate(-pitch, yaw, 0.0f);
		objects[i]->SetPosition(cp.x + cl.x, cp.y + cl.y, cp.z + cl.z);
	}

	//종합레벨 숫자 설정
	{
		int t1 = info->growth.total.level / 10;
		int t2 = info->growth.total.level % 10;

		int t3 = info->growth.total.exp / 1000;
		int t4 = (info->growth.total.exp % 1000) / 100;
		int t5 = (info->growth.total.exp % 100) / 10;
		int t6 = info->growth.total.exp % 10;

		int t7 = totalExpNeed[info->growth.total.level - 1] / 1000;
		int t8 = (totalExpNeed[info->growth.total.level - 1] % 1000) / 100;
		int t9 = (totalExpNeed[info->growth.total.level - 1] % 100) / 10;
		int t10 = totalExpNeed[info->growth.total.level - 1] % 10;

		objects[3]->m_ppMaterials[0] = rm->materials[273 + t1];
		objects[4]->m_ppMaterials[0] = rm->materials[273 + t2];
		objects[5]->m_ppMaterials[0] = rm->materials[273 + t3];
		objects[6]->m_ppMaterials[0] = rm->materials[273 + t4];
		objects[7]->m_ppMaterials[0] = rm->materials[273 + t5];
		objects[8]->m_ppMaterials[0] = rm->materials[273 + t6];
		objects[9]->m_ppMaterials[0] = rm->materials[273 + t7];
		objects[10]->m_ppMaterials[0] = rm->materials[273 + t8];
		objects[11]->m_ppMaterials[0] = rm->materials[273 + t9];
		objects[12]->m_ppMaterials[0] = rm->materials[273 + t10];
	}
	//근접 레벨 숫자설정
	{
		int t1 = info->growth.melee.level / 10;
		int t2 = info->growth.melee.level % 10;

		int t3 = info->growth.melee.exp / 1000;
		int t4 = (info->growth.melee.exp % 1000) / 100;
		int t5 = (info->growth.melee.exp % 100) / 10;
		int t6 = info->growth.melee.exp % 10;

		int t7 = expNeed[info->growth.melee.level - 1] / 1000;
		int t8 = (expNeed[info->growth.melee.level - 1] % 1000) / 100;
		int t9 = (expNeed[info->growth.melee.level - 1] % 100) / 10;
		int t10 = expNeed[info->growth.melee.level - 1] % 10;

		objects[13]->m_ppMaterials[0] = rm->materials[273 + t1];
		objects[14]->m_ppMaterials[0] = rm->materials[273 + t2];
		objects[15]->m_ppMaterials[0] = rm->materials[273 + t3];
		objects[16]->m_ppMaterials[0] = rm->materials[273 + t4];
		objects[17]->m_ppMaterials[0] = rm->materials[273 + t5];
		objects[18]->m_ppMaterials[0] = rm->materials[273 + t6];
		objects[19]->m_ppMaterials[0] = rm->materials[273 + t7];
		objects[20]->m_ppMaterials[0] = rm->materials[273 + t8];
		objects[21]->m_ppMaterials[0] = rm->materials[273 + t9];
		objects[22]->m_ppMaterials[0] = rm->materials[273 + t10];

	}
	//원거리 레벨 숫자설정
	{
		int t1 = info->growth.ranged.level / 10;
		int t2 = info->growth.ranged.level % 10;

		int t3 = info->growth.ranged.exp / 1000;
		int t4 = (info->growth.ranged.exp % 1000) / 100;
		int t5 = (info->growth.ranged.exp % 100) / 10;
		int t6 = info->growth.ranged.exp % 10;

		int t7 = expNeed[info->growth.ranged.level - 1] / 1000;
		int t8 = (expNeed[info->growth.ranged.level - 1] % 1000) / 100;
		int t9 = (expNeed[info->growth.ranged.level - 1] % 100) / 10;
		int t10 = expNeed[info->growth.ranged.level - 1] % 10;

		objects[23]->m_ppMaterials[0] = rm->materials[273 + t1];
		objects[24]->m_ppMaterials[0] = rm->materials[273 + t2];
		objects[25]->m_ppMaterials[0] = rm->materials[273 + t3];
		objects[26]->m_ppMaterials[0] = rm->materials[273 + t4];
		objects[27]->m_ppMaterials[0] = rm->materials[273 + t5];
		objects[28]->m_ppMaterials[0] = rm->materials[273 + t6];
		objects[29]->m_ppMaterials[0] = rm->materials[273 + t7];
		objects[30]->m_ppMaterials[0] = rm->materials[273 + t8];
		objects[31]->m_ppMaterials[0] = rm->materials[273 + t9];
		objects[32]->m_ppMaterials[0] = rm->materials[273 + t10];
	}
	//전파레벨 숫자설정
	{
		int t1 = info->growth.radio.level / 10;
		int t2 = info->growth.radio.level % 10;

		int t3 = info->growth.radio.exp / 1000;
		int t4 = (info->growth.radio.exp % 1000) / 100;
		int t5 = (info->growth.radio.exp % 100) / 10;
		int t6 = info->growth.radio.exp % 10;

		int t7 = expNeed[info->growth.radio.level - 1] / 1000;
		int t8 = (expNeed[info->growth.radio.level - 1] % 1000) / 100;
		int t9 = (expNeed[info->growth.radio.level - 1] % 100) / 10;
		int t10 = expNeed[info->growth.radio.level - 1] % 10;

		objects[33]->m_ppMaterials[0] = rm->materials[273 + t1];
		objects[34]->m_ppMaterials[0] = rm->materials[273 + t2];
		objects[35]->m_ppMaterials[0] = rm->materials[273 + t3];
		objects[36]->m_ppMaterials[0] = rm->materials[273 + t4];
		objects[37]->m_ppMaterials[0] = rm->materials[273 + t5];
		objects[38]->m_ppMaterials[0] = rm->materials[273 + t6];
		objects[39]->m_ppMaterials[0] = rm->materials[273 + t7];
		objects[40]->m_ppMaterials[0] = rm->materials[273 + t8];
		objects[41]->m_ppMaterials[0] = rm->materials[273 + t9];
		objects[42]->m_ppMaterials[0] = rm->materials[273 + t10];
	}
	//골드 숫자설정
	{
		int t1 = info->gold / 1000000000;
		int t2 = info->gold / 100000000;
		int t3 = info->gold / 10000000;
		int t4 = info->gold / 1000000;
		int t5 = info->gold / 100000;
		int t6 = info->gold / 10000;
		int t7 = info->gold / 1000;
		int t8 = info->gold / 100;
		int t9 = info->gold / 10;
		int t10 = info->gold % 10;

		objects[43]->m_ppMaterials[0] = rm->materials[273 + t1];
		objects[44]->m_ppMaterials[0] = rm->materials[273 + t2];
		objects[45]->m_ppMaterials[0] = rm->materials[273 + t3];
		objects[46]->m_ppMaterials[0] = rm->materials[273 + t4];
		objects[47]->m_ppMaterials[0] = rm->materials[273 + t5];
		objects[48]->m_ppMaterials[0] = rm->materials[273 + t6];
		objects[49]->m_ppMaterials[0] = rm->materials[273 + t7];
		objects[50]->m_ppMaterials[0] = rm->materials[273 + t8];
		objects[51]->m_ppMaterials[0] = rm->materials[273 + t9];
		objects[52]->m_ppMaterials[0] = rm->materials[273 + t10];
	}

	//능력치창. 여기서부터 숫자는 검은색.
	{
		int t1 = info->getCapacity() / 10;
		int t2 = info->getCapacity() % 10;

		objects[53]->m_ppMaterials[0] = rm->materials[252 + t1];
		objects[54]->m_ppMaterials[0] = rm->materials[252 + t2];
	}
	{
		int t1 = info->getHardness() / 10;
		int t2 = info->getHardness() % 10;

		objects[57]->m_ppMaterials[0] = rm->materials[252 + t1];
		objects[58]->m_ppMaterials[0] = rm->materials[252 + t2];
	}

	{
		int t1 = info->getPower() / 10;
		int t2 = info->getPower() % 10;

		objects[61]->m_ppMaterials[0] = rm->materials[252 + t1];
		objects[62]->m_ppMaterials[0] = rm->materials[252 + t2];
	}
	{
		int t1 = info->getPrecision() / 10;
		int t2 = info->getPrecision() % 10;

		objects[65]->m_ppMaterials[0] = rm->materials[252 + t1];
		objects[66]->m_ppMaterials[0] = rm->materials[252 + t2];
	}
	{
		int t1 = info->getEntrophy() / 10;
		int t2 = info->getEntrophy() % 10;

		objects[69]->m_ppMaterials[0] = rm->materials[252 + t1];
		objects[70]->m_ppMaterials[0] = rm->materials[252 + t2];
	}
	{
		int t1 = info->extraPoint / 10;
		int t2 = info->extraPoint % 10;

		objects[73]->m_ppMaterials[0] = rm->materials[252 + t1];
		objects[74]->m_ppMaterials[0] = rm->materials[252 + t2];
	}

}