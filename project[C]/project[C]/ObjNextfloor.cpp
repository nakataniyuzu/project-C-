//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"
#include "GameHead.h"

#include "ObjNextfloor.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjNextfloor::Init()
{
	m_next_time = 200;
	m_time = 900;
	g_map_change += 1;
	m_and = 0.0f;
	m_andf = true;
	m_keyf = true;
}

//アクション
void CObjNextfloor::Action()
{
	if (m_andf == true)
	{
		m_and += 0.03f;
		if (m_and >= 1.0f)
		{
			m_and = 1.0f;
			m_andf = false;
		}
	}
	else 
	{
		if (m_time > 40) {		//文字を左へスライドさせる
			m_time -= 15;
		}
		else {
			m_next_time--;	//次へ進むための時間を減らす
			if (m_next_time >= 0) {
				m_next_time = 0;
			}
		}
		if (m_time <= 40 && Input::GetVKey(VK_RETURN) == true 
		 || m_time <= 40 && Input::GetVKey('Z') == true
		 || m_next_time == 0)
		{
			Scene::SetScene(new CSceneMain());	//ゲームメインシーンに移行
		}
	}
}

//ドロー
void CObjNextfloor::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,m_and };

	wchar_t NEXT[128];

	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画先表示位置

	//切り取り位置の設定
	src.m_top    = 0.0f;
	src.m_left   = 0.0f;
	src.m_right  = 800.0f;
	src.m_bottom = 600.0f;

	//表示位置の設定
	dst.m_top    = 0.0f;
	dst.m_left   = 0.0f;
	dst.m_right  = 800.0f;
	dst.m_bottom = 600.0f;
	if (g_map_change == 1) {
		Draw::Draw(0, &src, &dst, c, 0.0f);
	}
	else if (g_map_change == 2) {
		Draw::Draw(1, &src, &dst, c, 0.0f);
	}
	//n層目への移行用タイトル
	swprintf_s(NEXT, L"%d層目",g_map_change + 1);		
	Font::StrDraw(NEXT, m_time, 500, 60, c);

}
