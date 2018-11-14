#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//定数
//描画関係の定数
#define GAME_LEVEL_POS_X     (0)
#define GAME_LEVEL_POS_Y     (0)
#define GAME_LEVEL_FONT_SIZE (25)

#define GAME_NAME_POS_X     (100)
#define GAME_NAME_POS_Y     (0)
#define GAME_NAME_FONT_SIZE (25)

#define GAME_HP_POS_X     (0)
#define GAME_HP_POS_Y     (25)
#define GAME_HP_FONT_SIZE (25)

#define GAME_MP_POS_X     (170)
#define GAME_MP_POS_Y     (25)
#define GAME_MP_FONT_SIZE (25)

#define GAME_INVENTORY_POS_X     (300)
#define GAME_INVENTORY_POS_Y     (0)
#define GAME_INVENTORY_FONT_SIZE (25)

#define GAME_MENU_POS_X     (300)
#define GAME_MENU_POS_Y     (25)
#define GAME_MENU_FONT_SIZE (25)

#define GAME_ENEMY_KILLS_POS_X     (610)
#define GAME_ENEMY_KILLS_POS_Y     (15)
#define GAME_ENEMY_KILLS_FONT_SIZE (25)


//オブジェクト：メニュー
class CObjMain :public CObj
{
	public:
		CObjMain() {};
		~CObjMain() {};
		void Init();	//イニシャライズ
		void Action();	//アクション
		void Draw();	//ドロー
	private:
		int hero_hp;
		int hero_mp;
		int magic_type;

};
