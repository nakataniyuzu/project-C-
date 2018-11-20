#pragma once

//オブジェクトネーム------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//オブジェクト名無し(禁止)
	//ゲームで使うオブジェクトの名前
	//OBJ_○○と表記
	OBJ_TITLE,
	OBJ_MENU,
	OBJ_MAIN,
	OBJ_MESSAGE,

	ITEM_ICE,

	OBJ_FIRE,
	OBJ_ICE,
	OBJ_WIND,
	OBJ_THUNDER,
	
	OBJ_FIREBLOCK,
	OBJ_FIREGATE,

	OBJ_HERO,
	OBJ_BLOCK,
	OBJ_TOPBACK,
	OBJ_ENEMY,

	OBJ_HERO_BATTLE,
	OBJ_ENEMY_BATTLE,
	OBJ_BLOCK_BATTLE,
	OBJ_BACKGROUND_BATTLE,
	OBJ_BATTLE_MAIN,

	OBJ_KEY,
	OBJ_GATE,
	OBJ_WATER,
	OBJ_RESETBLOCK,
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
	ELEMENT_ITEM,
	ELEMENT_MAGIC,
	ELEMENT_FIELD,
	
	ELEMENT_RED,
	ELEMENT_GREEN,
	ELEMENT_BLUE,
	ELEMENT_BLACK,
	ELEMENT_WHITE,

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



//------------------------------------------------
//ゲーム内で使用するクラスヘッダ------------------


//------------------------------------------------

//ゲームシーンオブジェクトヘッダ------------------
#include "ObjTitle.h"
#include "ObjHero.h"
#include "ObjMenu.h"
#include "ObjMain.h"

//Item関係
#include "ItemIce.h"


//Magic
#include "CObjFire.h"
#include "CObjIce.h"
#include "CObjWind.h"
#include "CObjThunder.h"

//Magic関係
#include "ObjFireblock.h"
#include "ObjFireGate.h"

#include "ObjEnemy.h"

#include "ObjBlock.h"
#include "ObjTopback.h"

//Battle関係
#include "ObjHeroBattle.h"
#include "ObjEnemyBattle.h"
#include "ObjBlockBattle.h"
#include "ObjBackgroundBattle.h"
#include "ObjBattleMain.h"

//謎解き関係
#include "ObjKey.h"
#include "ObjGate.h"
#include "ObjWater.h"
#include "ObjResetblock.h"

#include "ObjMessage.h"
//------------------------------------------------

//ゲームシーンクラスヘッダ------------------------
#include "SceneTitle.h"
#include "SceneMain.h"
#include "SceneMenu.h"
#include "SceneBattle.h"

//-----------------------------------------------

//シーンスタートクラス---------------------------
//ゲーム開始時のシーンクラス登録
#define SET_GAME_START  CSceneMain
//-----------------------------------------------