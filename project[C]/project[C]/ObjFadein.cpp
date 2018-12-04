//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameHead.h"
#include "GameL\WinInputs.h"

#include "ObjFadein.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjFadein::Init()
{
	m_ani_time = 0;
	m_ani_frame = 0;	//静止フレームを初期にする

	m_ani_max_time = 2;		//アニメーション間隔幅
	m_flag = true;		//切り替え用フラグ
}

//アクション
void CObjFadein::Action()
{
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	hero->SetSPEED(0.0f);
	hero->SetVX(0.0f);
	hero->SetVY(0.0f);
	m_fadein_flag = hero->GetFADEF();

	if (m_fadein_flag == true) {
		m_fadeout_flag = false;
	}
	else {
		m_fadeout_flag = true;
	}

	if (m_flag == true)
	{
		m_ani_time += 1;

		if (m_ani_time > m_ani_max_time)
		{
			m_ani_frame += 1;
			m_ani_time = 0;
		}
		if (m_ani_frame == 9)
		{
			m_flag = false;
		}
	}
	else 
	{
		m_ani_time = 10;
		m_ani_time -= 1;

		if (m_ani_time > m_ani_max_time)
		{
			m_ani_frame -= 1;
			//m_ani_time = 10;
		}
		if (m_ani_frame == 0)
		{
			hero->SetBATTLE(m_fadeout_flag);		//バトル画面への移行

			this->SetStatus(false);
		}
	}
}

//ドロー
void CObjFadein::Draw()
{
	//描画カラー情報　R=RED  G=Green  B=Blue A=alpha(透過情報)
	float  c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;		//描画元切り取り位置
	RECT_F dst;		//描画先表示位置

	//背景切り取り
	src.m_top    =   0.0f;
	src.m_left   =   0.0f + (800.0f * m_ani_frame);
	src.m_right  = 800.0f + (800.0f * m_ani_frame);
	src.m_bottom = 600.0f;

	//描画
	dst.m_top    =  50.0f;
	dst.m_left   =   0.0f;
	dst.m_right  = 800.0f;
	dst.m_bottom = 600.0f;
	Draw::Draw(17, &src, &dst, c, 0.0f);
}

