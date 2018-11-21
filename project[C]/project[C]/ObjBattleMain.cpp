//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"
#include "GameHead.h"

#include "ObjBattleMain.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjBattleMain::Init()
{

}

//アクション
void CObjBattleMain::Action()
{

}

//ドロー
void CObjBattleMain::Draw()
{
	CObjHeroBattle* hero = (CObjHeroBattle*)Objs::GetObj(OBJ_HERO_BATTLE);
	hero_hp = hero->GetBATTLEHP();	//主人公からHPの情報を取得
	hero_mp = hero->GetBATTLEMP();	//主人公からMPの情報を取得
	magic_type = hero->GetBATTLEMAGIC();	//主人公からMAGICの情報を取得


	float c[4] = { 1,1,1,1 };

	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画先表示位置

	wchar_t HP[128];
	wchar_t MP[128];

	//画面上部のメニュー画面
	Font::StrDraw(L"LEVEL：", GAME_LEVEL_POS_X, GAME_LEVEL_POS_X, GAME_LEVEL_FONT_SIZE, c);

	Font::StrDraw(L"[NAME]", GAME_NAME_POS_X, GAME_NAME_POS_Y, GAME_NAME_FONT_SIZE, c);

	swprintf_s(HP, L"HP %d/%d", hero_hp, 15);
	Font::StrDraw(HP, GAME_HP_POS_X, GAME_HP_POS_Y, GAME_HP_FONT_SIZE, c);//HPを表示


	 //切り取り位置の設定
	src.m_top    =  0.0f;
	src.m_left   =  0.0f + (50.0f * magic_type);
	src.m_right  = 50.0f + (50.0f * magic_type);
	src.m_bottom = 50.0f;

	//表示位置の設定
	dst.m_top    =  20.0f;
	dst.m_left   = 130.0f;
	dst.m_right  = 160.0f;
	dst.m_bottom =  50.0f;
	Draw::Draw(10, &src, &dst, c, 0.0f);

	swprintf_s(MP, L"%d/%d", hero_mp, 5);
	Font::StrDraw(MP, GAME_MP_POS_X, GAME_MP_POS_Y, GAME_MP_FONT_SIZE, c);

	//Font::StrDraw(L"Inventory   ：Iキー", GAME_INVENTORY_POS_X, GAME_INVENTORY_POS_Y, GAME_INVENTORY_FONT_SIZE, c);

	Font::StrDraw(L"メニュー画面：Eキー", GAME_MENU_POS_X, GAME_MENU_POS_Y, GAME_MENU_FONT_SIZE, c);

	Font::StrDraw(L"敵の撃破数×○", GAME_ENEMY_KILLS_POS_X, GAME_ENEMY_KILLS_POS_Y, GAME_ENEMY_KILLS_FONT_SIZE, c);
}