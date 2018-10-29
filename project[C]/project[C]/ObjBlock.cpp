//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"
#include "GameHead.h"
#include "ObjBlock.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjBlock::Init()
{
}

//アクション
void CObjBlock::Action()
{
	//主人公の位置を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//後方スクロールライン
	/*if (hx < 80)
	{
		hero->SetX(80);				//主人公はラインを超えないようにする
		m_scroll -= hero->GetVX();	//主人公が本来動くべき分の値をm_scrollに加える
	}

	//前方スクロールライン
	if (hx > 300)
	{
		hero->SetX(300);			//主人公はラインを超えないようにする
		m_scroll -= hero->GetVX();	//主人公が本来動くべき分の値をm_scrollに加える
	}*/

}

//ドロー
void CObjBlock::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画先表示位置

	//背景表示
	src.m_top	 =   0.0f;
	src.m_left	 =   0.0f;
	src.m_right	 = 800.0f;
	src.m_bottom = 600.0f;

	dst.m_top    =  50.0f;
	dst.m_left   =   0.0f;
	dst.m_right  = 800.0f;
	dst.m_bottom = 600.0f;

	Draw::Draw(FLOOR1, &src, &dst, c, 0.0f);

}