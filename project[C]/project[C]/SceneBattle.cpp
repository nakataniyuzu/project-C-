//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"
#include "GameL\DrawTexture.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneBattle.h"
#include "GameHead.h"

//コンストラクタ
CSceneBattle::CSceneBattle()
{

}

//デストラクタ
CSceneBattle::~CSceneBattle()
{

}

//ゲーム戦闘初期化メソッド
void CSceneBattle::InitScene()
{
	//グラフィック読み込み
	Draw::LoadImageW(L"Hero2.png", 0, TEX_SIZE_100);
	Draw::LoadImageW(L"Battlefloor.png", 1, TEX_SIZE_100);
	Draw::LoadImageW(L"Wall.png", FLOOR1_WALL,TEX_SIZE_100);
	Draw::LoadImageW(L"Floor1_Enemy.png", 3, TEX_SIZE_100);
	Draw::LoadImageW(L"MagicBattle.png", 4, TEX_SIZE_100);
	Draw::LoadImageW(L"magicitem.png", 10, TEX_SIZE_256);

	//主人公オブジェクト作成
	CObjHeroBattle* obj = new CObjHeroBattle();
	Objs::InsertObj(obj, OBJ_HERO_BATTLE, 10);

	//blockオブジェクト作成
	CObjBlockBattle* objb = new CObjBlockBattle();
	Objs::InsertObj(objb, OBJ_BLOCK_BATTLE, 9);

	//敵(戦闘)オブジェクト作成
	CObjEnemyBattle* obje = new CObjEnemyBattle();
	Objs::InsertObj(obje, OBJ_ENEMY_BATTLE, 10);

	//背景(戦闘)オブジェクト作成
	CObjBackgroundBattle* objbackb = new CObjBackgroundBattle();
	Objs::InsertObj(objbackb, OBJ_BACKGROUND_BATTLE, 8);

	CObjBattleMain* p = new CObjBattleMain();
	Objs::InsertObj(p, OBJ_MAIN, 20);
}

//ゲーム戦闘実行中メソッド
void CSceneBattle::Scene()
{

}