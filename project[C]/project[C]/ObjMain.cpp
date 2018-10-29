//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"
#include "GameHead.h"

#include "ObjMain.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjMain::Init()
{

}

//アクション
void CObjMain::Action()
{
	
}

//ドロー
void CObjMain::Draw()
{
	float c[4] = { 1,1,1,1 };

	//画面上部のメニュー画面
	Font::StrDraw(L"LEVEL：", GAME_LEVEL_POS_X, GAME_LEVEL_POS_X, GAME_LEVEL_FONT_SIZE, c);

	Font::StrDraw(L"[NAME]", GAME_NAME_POS_X, GAME_NAME_POS_Y, GAME_NAME_FONT_SIZE, c);

	Font::StrDraw(L"HP", GAME_HP_POS_X, GAME_HP_POS_Y, GAME_HP_FONT_SIZE, c);

	Font::StrDraw(L"魔法/使用可数", GAME_MP_POS_X, GAME_MP_POS_Y, GAME_MP_FONT_SIZE, c);

	Font::StrDraw(L"Inventory   ：Iキー", GAME_INVENTORY_POS_X, GAME_INVENTORY_POS_Y, GAME_INVENTORY_FONT_SIZE, c);

	Font::StrDraw(L"メニュー画面：Eキー", GAME_MENU_POS_X, GAME_MENU_POS_Y, GAME_MENU_FONT_SIZE, c);

	Font::StrDraw(L"敵の撃破数×○", GAME_ENEMY_KILLS_POS_X, GAME_ENEMY_KILLS_POS_Y, GAME_ENEMY_KILLS_FONT_SIZE, c);
}