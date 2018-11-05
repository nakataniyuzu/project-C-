//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameHead.h"
#include "GameL\WinInputs.h"


#include "ObjBackground.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjBackground::Init()
{
	m_x1 = 0.0f;
	m_x2 = 800.0f;
	m_x3 = -800.0f;
	m_scroll = 0.0f;
	m_scroll_map = 0.0f;

}

//アクション
void CObjBackground::Action()
{

	//主人公の位置を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	m_scroll_map = hero->GetVX(); //背景に加える

	if (hero->GetVX() >= 0.0f)
	{
		//キャラクターが右に動いたら
		if (hx >350)
		{
			//スクロールライン超えようとしたらスクロール
			m_x1 -= hero->GetVX();
			if (m_x1 < -1600.0f)
				m_x1 = 800;
			m_x2 -= hero->GetVX();
			if (m_x2 < -1600.0f)
				m_x2 = 800;
			m_x3 -= hero->GetVX();
			if (m_x3 < -1600.0f)
				m_x3 = 800;
		}
	}
	else
	{
		//キャラクターが左に動いたら
		if (hx < 100)
		{
			//スクロールライン超えようとしたらスクロール
			m_x1 -= hero->GetVX();
			if (m_x1 > 1600.0f)
				m_x1 = -800;
			m_x2 -= hero->GetVX();
			if (m_x2 > 1600.0f)
				m_x2 = -800;
			m_x3 -= hero->GetVX();
			if (m_x3 > 1600.0f)
				m_x3 = -800;
		}
	}
}

//ドロー
void CObjBackground::Draw()
{
	//描画カラー情報　R=RED  G=Green  B=Blue A=alpha(透過情報)
	float  c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;		//描画元切り取り位置
	RECT_F dst;		//描画先表示位置

	
	//背景切り取り
	src.m_top    = 0.0f;
	src.m_left   = 0.0f;
	src.m_right  = 800.0f;
	src.m_bottom = 600.0f;

	//描画
	dst.m_top    =   0.0f;
	dst.m_left   =   0.0f + m_x1;
	dst.m_right  = 820.0f + m_x1;
	dst.m_bottom = 600.0f;
	Draw::Draw(FLOOR1, &src, &dst, c, 0.0f);

	dst.m_top    =   0.0f;
	dst.m_left   = 820.0f + m_x2;
	dst.m_right  =   0.0f + m_x2;
	dst.m_bottom = 600.0f;
	Draw::Draw(FLOOR1, &src, &dst, c, 0.0f);

	dst.m_top    =   0.0f;
	dst.m_left   = 820.0f + m_x3;
	dst.m_right  =   0.0f + m_x3;
	dst.m_bottom = 600.0f;
	Draw::Draw(FLOOR1, &src, &dst, c, 0.0f);

}

