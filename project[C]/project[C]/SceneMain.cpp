//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"
#include "GameL\DrawTexture.h"
#include "GameL\UserData.h"


//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneMain.h"
#include "GameHead.h"

//コンストラクタ
CSceneMain::CSceneMain()
{

}

//デストラクタ
CSceneMain::~CSceneMain()
{

}

//ゲームタイトルの初期化メソッド
void CSceneMain::InitScene()
{
	//外部データ読み込み（ステージ情報）
	unique_ptr<wchar_t> p;	//ステージ情報ポインター
	int size;				//ステージ情報の大きさ
	p = Save::ExternalDataOpen(L"map1.csv", &size);//外部データ読み込み

	int map[27][55];
	int count = 1;
	for (int i = 0; i < 27; i++)
	{
		for (int j = 0; j < 55; j++)
		{
			int w = 0;
			swscanf_s(&p.get()[count], L"%d", &w);

			map[i][j] = w;
			count += 2;
		}
	}

	//グラフィック読み込み
	Draw::LoadImageW(L"Hero.png", 0, TEX_SIZE_100);
	Draw::LoadImageW(L"floor1.png", FLOOR1, TEX_SIZE_800_600);
	Draw::LoadImageW(L"Wall.png", 2, TEX_SIZE_100);
	Draw::LoadImageW(L"image.png", 3, TEX_SIZE_100);

	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//blockオブジェクト作成
	CObjBlock* objb = new CObjBlock(map);
	Objs::InsertObj(objb, OBJ_BLOCK, 9);

	CObjBackground* objback = new CObjBackground();
	Objs::InsertObj(objback, OBJ_BACKGROUND, 8);
	
	CObjTopback* objtb = new CObjTopback();
	Objs::InsertObj(objtb, OBJ_TOPBACK, 19);

	CObjMain* objm = new CObjMain();
	Objs::InsertObj(objm, OBJ_MAIN, 20);

}

//ゲームタイトルの実行中メソッド
void CSceneMain::Scene()
{

}
