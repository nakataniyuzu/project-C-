//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameHead.h"
#include "GameL\WinInputs.h"

#include "ObjBackgroundBattle.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjBackgroundBattle::Init()
{

}

//アクション
void CObjBackgroundBattle::Action()
{

}

//ドロー
void CObjBackgroundBattle::Draw()
{
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	m_battle_flag = hero->GetBATTLE();

	if (g_battle_flag == false)
	{
		return;
	}

	//描画カラー情報　R=RED  G=Green  B=Blue A=alpha(透過情報)
	float  c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;		//描画元切り取り位置
	RECT_F dst;		//描画先表示位置


	//背景切り取り
	src.m_top    =   0.0f;
	src.m_left   =  400.0f;
	src.m_right  =  500.0f;
	src.m_bottom =  100.0f;

	//描画
	dst.m_top    =  50.0f;
	dst.m_left   =   0.0f;
	dst.m_right  = 800.0f;
	dst.m_bottom = 550.0f;
	Draw::Draw(BLOCK, &src, &dst, c, 0.0f);
}

