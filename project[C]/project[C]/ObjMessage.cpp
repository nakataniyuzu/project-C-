//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"
#include "GameHead.h"

#include "ObjMessage.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjMessage::Init()
{

}

//アクション
void CObjMessage::Action()
{
	
}

//ドロー
void CObjMessage::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float b[4] = { 0.0f,0.0f,1.0f,1.0f };
	float y[4] = { 1.0f,1.0f,0.0f,1.0f };


	RECT_F src;		//描画元切り取り位置
	RECT_F dst;		//描画先表示位置


	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	water_flag = hero->GetWATERF();
	key_flag = hero->GetKEYF();
	gate_flag = hero->GetGATEF();
	ice_flag = hero->GetMICE();
	switch_flag = hero->GetSGATE();

	if (water_flag == true)	//主人公がWATERブロックと当たった場合、m_timeに時間をセット
	{
		m_water_time = 100;
	}
	if (m_water_time > 0) {
		m_water_time--;
		water_flag = false;		//フラグをオフ
		hero->SetWATERF(water_flag);
		Font::StrDraw(L"凍らせれば渡れるか...？", 180, 230, 20, b);//時間が0になると表示を終了
		if (m_water_time <= 0) {
			m_water_time = 0;
		}
	}
	if (key_flag == true)	//主人公がKEYブロックと当たった場合、m_timeに時間をセット
	{
		m_key_time = 100;
	}
	if (m_key_time > 0) {
		m_key_time--;
		key_flag = false;		//フラグをオフ
		hero->SetKEYF(key_flag);
		Font::StrDraw(L"鍵を手に入れた", 200, 200, 20, y);//時間が0になると表示を終了
		if (m_key_time <= 0) {
			m_key_time = 0;
		}
	}

	if (gate_flag == true)		//鍵のフラグがオンになったら時間をセット
	{
		m_gate_time = 100;
	}
	if (m_gate_time > 0) {
		m_gate_time--;
		gate_flag = false;		//フラグをオフ
		hero->SetGATEF(gate_flag);
		Font::StrDraw(L"鍵を開けた", 210, 170, 20, y);//時間が0になると表示を終了
		if (m_gate_time <= 0) {
			m_gate_time = 0;
		}
	}

	if (ice_flag == true)		//鍵のフラグがオンになったら時間をセット
	{
		m_ice_time = 100;
	}
	if (m_ice_time > 0) {
		m_ice_time--;
		ice_flag = false;		//フラグをオフ
		hero->SetMICE(ice_flag);
		Font::StrDraw(L"氷魔法を覚えた！", 200, 200, 20, b);//時間が0になると表示を終了
		if (m_ice_time <= 0) {
			m_ice_time = 0;
		}
	}

	if (switch_flag == true)
	{
		m_switch_time = 100;
	}
	if (m_switch_time > 0) {
		m_switch_time--;
		switch_flag = false;
		hero->SetSGATE(switch_flag);
		Font::StrDraw(L"開かない...", 200, 200, 20, c);//時間が0になると表示を終了		
		if (m_switch_time <= 0) {
			m_switch_time = 0;
		}
	}

}
