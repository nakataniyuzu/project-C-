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
	Draw::LoadImageW(L"Hero.png", 0, TEX_SIZE_100);
	Draw::LoadImageW(L"Battlefloor.png", 1, TEX_SIZE_100);
	//Draw::LoadImageW(L"Wall.png", 2, TEX_SIZE_100);

	//主人公オブジェクト作成
	CObjHeroBattle* obj = new CObjHeroBattle();
	Objs::InsertObj(obj, OBJ_HERO_BATTLE, 10);

	//blockオブジェクト作成
	CObjBlockBattle* objb = new CObjBlockBattle();
	Objs::InsertObj(objb, OBJ_BLOCK_BATTLE, 9);

	//敵(戦闘)オブジェクト作成
	CObjEnemyBattle* obje = new CObjEnemyBattle();
	Objs::InsertObj(obje, OBJ_ENEMY_BATTLE, 10);

	CObjMain* p = new CObjMain();
	Objs::InsertObj(p, OBJ_TITLE, 20);
}

//ゲーム戦闘実行中メソッド
void CSceneBattle::Scene()
{

}