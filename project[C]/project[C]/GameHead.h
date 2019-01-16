#pragma once

//オブジェクトネーム------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//オブジェクト名無し(禁止)
	//ゲームで使うオブジェクトの名前
	//OBJ_○○と表記
	OBJ_TITLE,
	OBJ_GAMEOVER,
	OBJ_MENU,
	OBJ_MAIN,
	OBJ_CLEAR,
	OBJ_MESSAGE,
	OBJ_NEXT_FLOOR,

	OBJ_SWORD_BATTLE,

	ITEM_ICE,
	ITEM_WIND,

	OBJ_FIRE,
	OBJ_ICE,
	OBJ_WIND,
	OBJ_THUNDER,

	OBJ_FIRE_BATTLE,
	OBJ_ICE_BATTLE,
	OBJ_THUNDER_BATTLE,
	OBJ_ENEMY_MAGIC_BATTLE,

	OBJ_FIREBLOCK,
	OBJ_FIREGATE,

	OBJ_HERO,
	OBJ_SISTER,
	OBJ_BLOCK,
	OBJ_TOPBACK,
	OBJ_ENEMY,
	OBJ_ENEMY_FIRST,
	OBJ_ENEMY_SECOND,
	OBJ_ENEMY_THIRD,

	OBJ_HERO_BATTLE,
	OBJ_BOSS,
	OBJ_BOSS_BATTLE,
	OBJ_BOSS_BATTLE_FIRST,
	OBJ_BOSS_BATTLE_SECOND,
	OBJ_BOSS_BATTLE_THIRD,
	OBJ_BOSS_BATTLE_FINAL,

	OBJ_BLOCK_BATTLE,
	OBJ_BACKGROUND_BATTLE,

	OBJ_BATTLE_MAIN,
	OBJ_ENEMY_BATTLE,
	OBJ_ENEMY_BATTLE_FIRST,
	OBJ_ENEMY_BATTLE_SECOND,
	OBJ_ENEMY_BATTLE_THIRD,

	OBJ_HEAL,
	OBJ_KEY,
	OBJ_GATE,
	OBJ_WATER,
	OBJ_RESETBLOCK,
	OBJ_SWITCH,
	OBJ_SWITCHGATE,
	OBJ_DUMMYSWITCH,
	OBJ_CHANGESWITCH,
	OBJ_CHANGEGATE,
	OBJ_BOSSSWITCH,
	OBJ_BOSSGATE,
	OBJ_STAIRS,

	OBJ_FADEIN,
};
//------------------------------------------------

//当たり判定属性----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//属性無し 全ての属性と当たり判定が実行される
	//以下　同じ属性同士では当たり判定は実行されない
	//属性は追加可能だが、デバック時の色は初期設定分しか無い
	ELEMENT_PLAYER,
	ELEMENT_ENEMY,
	ELEMENT_BOSS,
	ELEMENT_ITEM,
	ELEMENT_MAGIC,
	ELEMENT_FIELD,
	ELEMENT_SWORD,
	ELEMENT_ATTACK,

	ELEMENT_ENEMY_BATTLE,
	ELEMENT_BOSS_BATTLE,
	ELEMENT_MAGIC_BATTLE,


	ELEMENT_RED,
	ELEMENT_GREEN,
	ELEMENT_BLUE,
	ELEMENT_BLACK,
	ELEMENT_WHITE,

	ELEMENT_SISTER,
	ELEMENT_HEAL,
	ELEMENT_MYSTERY,
	ELEMENT_MYSTERY_BLOCK,
	ELEMENT_GATE_BLOCK,
	ELEMENT_WATER,
	ELEMENT_RESET,
};
//------------------------------------------------

//------------------------------------------------
//セーブ＆ロードとシーン間のやり取りするデータ
struct UserData
{
	int mSeveData;	//サンプルセーブデータ
	
};
//------------------------------------------------


//ゲーム内で使用されるグローバル変数・定数・列挙--

#define ALL_SIZE 50.0f		//ブロック等のサイズ
extern int g_map_change;	//マップ変更用変数
extern bool g_battle_flag;	//バトル画面変更用のフラグ
extern bool g_key_flag;		//キー入力制御用フラグ
extern int g_enemy_kills;	//敵の撃破数

//------------------------------------------------
//ゲーム内で使用するクラスヘッダ------------------


//------------------------------------------------

//ゲームシーンオブジェクトヘッダ------------------
#include "ObjTitle.h"
#include "ObjHero.h"
#include "ObjSister.h"
#include "ObjMenu.h"
#include "ObjMain.h"
#include "ObjClear.h"
#include "ObjGameover.h"
#include "ObjNextfloor.h"

//Item関係
#include "ItemIce.h"
#include "ItemWind.h"

#include "ObjHeal.h"

//剣関係
#include "CObjSwordBattle.h"

//Magic
#include "CObjFire.h"
#include "CObjIce.h"
#include "CObjWind.h"
#include "CObjThunder.h"

#include "CObjFireBattle.h"
#include "CObjIceBattle.h"
#include "CObjThunderBattle.h"
#include "CObjEnemyMagicBattle.h"

//Magic関係
#include "ObjFireblock.h"
#include "ObjFireGate.h"

//Enemy関係
#include "ObjBoss.h"
#include "ObjBoss1Battle.h"
#include "ObjBoss2Battle.h"
#include "ObjBoss3Battle.h"
#include "ObjEnemyboss1.h"
#include "ObjEnemy1.h"
#include "ObjEnemy2.h"


#include "ObjBlock.h"
#include "ObjTopback.h"

//Battle関係
#include "ObjHeroBattle.h"
#include "ObjEnemy1Battle.h"
#include "ObjEnemy2Battle.h"
#include "ObjEnemy3Battle.h"
#include "ObjBlockBattle.h"
#include "ObjBackgroundBattle.h"

//謎解き関係
#include "ObjKey.h"
#include "ObjGate.h"
#include "ObjWater.h"
#include "ObjResetblock.h"
#include "ObjSwitch.h"
#include "ObjSwitchGate.h"
#include "ObjStairs.h"
#include "ObjDummySwitch.h"
#include "ObjChangeSwitch.h"
#include "ObjChangeGate1.h"
#include "ObjChangeGate2.h"
#include "ObjBossSwitch.h"
#include "ObjBossGate.h"

#include "ObjMessage.h"
#include "ObjFadein.h"
//------------------------------------------------

//ゲームシーンクラスヘッダ------------------------
#include "SceneTitle.h"
#include "SceneMain.h"
#include "SceneMenu.h"
#include "SceneBattle.h"
#include "SceneGameover.h"
#include "SceneClear.h"
#include "SceneNextfloor.h"

//-----------------------------------------------

//シーンスタートクラス---------------------------
//ゲーム開始時のシーンクラス登録
#define SET_GAME_START  CSceneTitle
//-----------------------------------------------