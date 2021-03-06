#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//定数
//描画関係の定数
#define GAME_HP_POS_X     (0)
#define GAME_HP_POS_Y     (0)
#define GAME_HP_FONT_SIZE (25)

#define GAME_MP_POS_X     (0)
#define GAME_MP_POS_Y     (25)
#define GAME_MP_FONT_SIZE (25)

#define GAME_MESSAGE_POS_X     (200)
#define GAME_MESSAGE_POS_Y     (0)
#define GAME_MESSAGE_FONT_SIZE (20)

#define GAME_MESSAGE2_POS_X     (200)
#define GAME_MESSAGE2_POS_Y     (25)
#define GAME_MESSAGE2_FONT_SIZE (20)

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
		int hero_max_hp;	//HP最大値
		int hero_max_mp;	//MP最大値

		int hero_hp;	//HP
		int hero_mp;	//MP
		int magic_type;	//魔法の種類
		int key;		//鍵を所持しているか
		bool battle_flag;	//バトル画面かどうか

		float m_and;		//透明度処理用
		bool m_andf;		//透明度処理用フラグ
};
