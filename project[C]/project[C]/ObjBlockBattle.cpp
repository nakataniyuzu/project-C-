//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjBlockBattle.h"

//使用するネームスペース
using namespace GameL;

CObjBlockBattle::CObjBlockBattle()
{

}

//イニシャライズ
void CObjBlockBattle::Init()
{
	//ブロック情報
	int block_data[12][16]
	{
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },

	};
	//コピー
	memcpy(m_map, block_data, sizeof(int)*(12 * 16));
}

//アクション
void CObjBlockBattle::Action()
{
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	m_battle_flag = hero->GetBATTLE();
	m_boss_battle_f = hero->GetBOSSBATTLE();

	if (m_battle_flag == true || m_boss_battle_f ==true)
	{
		return;
	}
	//主人公の位置を取得
	float hx = hero->GetX();
	float hy = hero->GetY();
}

//ドロー
void CObjBlockBattle::Draw()
{
	if (m_battle_flag == true || m_boss_battle_f == true)
	{
		return;
	}

	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画先表示位置

	//切り取り位置の設定
	src.m_top    =  0.0f;
	src.m_left   =  0.0f;
	src.m_right  = 50.0f;
	src.m_bottom = 50.0f;

	
	//表示位置の設定
	dst.m_top    = 550.0f;
	dst.m_left   =   0.0f;
	dst.m_right  = 800.0f;
	dst.m_bottom = 600.0f;

	//描画
	Draw::Draw(FLOOR1, &src, &dst, c, 0.0f);
		

}