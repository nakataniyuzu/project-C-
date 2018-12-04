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

	OBJ_SWORD_BATTLE,

	ITEM_ICE,

	OBJ_FIRE,
	OBJ_ICE,
	OBJ_WIND,
	OBJ_THUNDER,

	OBJ_FIRE_BATTLE,
	OBJ_ICE_BATTLE,
	OBJ_THUNDER_BATTLE,
	
	OBJ_FIREBLOCK,
	OBJ_FIREGATE,

	OBJ_HERO,
	OBJ_SISTER,
	OBJ_BLOCK,
	OBJ_TOPBACK,
	OBJ_ENEMY,
	OBJ_ENEMY_FIRST,

	OBJ_HERO_BATTLE,
	OBJ_ENEMY_BATTLE,
	OBJ_BOSS,
	OBJ_BOSS_BATTLE,
	OBJ_BLOCK_BATTLE,
	OBJ_BACKGROUND_BATTLE,
	OBJ_BATTLE_MAIN,

	OBJ_HEAL,
	OBJ_KEY,
	OBJ_GATE,
	OBJ_WATER,
	OBJ_RESETBLOCK,
	OBJ_SWITCH,
	OBJ_SWITCHGATE,

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

#define ALL_SIZE 50.0f



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

//Item関係
#include "ItemIce.h"

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

//Magic関係
#include "ObjFireblock.h"
#include "ObjFireGate.h"

//Enemy関係
#include "ObjBoss.h"
#include "ObjBossBattle.h"
#include "ObjEnemyboss1.h"
#include "ObjEnemy1.h"
#include "ObjEnemyFirst.h"


#include "ObjBlock.h"
#include "ObjTopback.h"

//Battle関係
#include "ObjHeroBattle.h"
#include "ObjEnemyBattle.h"
#include "ObjBlockBattle.h"
#include "ObjBackgroundBattle.h"

//謎解き関係
#include "ObjKey.h"
#include "ObjGate.h"
#include "ObjWater.h"
#include "ObjResetblock.h"
#include "ObjSwitch.h"
#include "ObjSwitchGate.h"

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

//-----------------------------------------------

//シーンスタートクラス---------------------------
//ゲーム開始時のシーンクラス登録
#define SET_GAME_START  CSceneMain
//-----------------------------------------------