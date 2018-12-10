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
	m_f = true;
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

			if (w >= 10)
			{
				count += 1;
			}
			count += 2;
		}
	}

	//グラフィック読み込み
	Draw::LoadImageW(L"Hero.png", 0, TEX_SIZE_256_128);
	Draw::LoadImageW(L"floor1.png", FLOOR1, TEX_SIZE_800_600);
	Draw::LoadImageW(L"Block.png", BLOCK1, TEX_SIZE_800_600);
	Draw::LoadImageW(L"image.png", 3, TEX_SIZE_100);
	Draw::LoadImageW(L"nazotoki.png", 4, TEX_SIZE_100);
	Draw::LoadImageW(L"healkey.png", HEALKEY, TEX_SIZE_100);
	Draw::LoadImageW(L"Water.png", 6, TEX_SIZE_200);
	Draw::LoadImageW(L"Enemy1.png", 7, TEX_SIZE_200_100);
	Draw::LoadImageW(L"Magic.png", 8, TEX_SIZE_100);
	Draw::LoadImageW(L"Candle.png", 9, TEX_SIZE_200_100);
	Draw::LoadImageW(L"magicitem.png", ITEM, TEX_SIZE_256);
	Draw::LoadImageW(L"Hero2.png", 11, TEX_SIZE_100);
	Draw::LoadImageW(L"Floor1_Enemy.png", 12, TEX_SIZE_100);
	Draw::LoadImageW(L"MagicBattle.png", 13, TEX_SIZE_256);
	Draw::LoadImageW(L"ENEMYBOSS1.png", 14, TEX_SIZE_800_600);
	Draw::LoadImageW(L"sister.png", 15, TEX_SIZE_800_600);
	Draw::LoadImageW(L"Sword.png", 16, TEX_SIZE_800_600);
	Draw::LoadImageW(L"Fadein.png", 17, TEX_SIZE_16000_600);
	Draw::LoadImageW(L"Floor2_Enemy.png", 19, TEX_SIZE_100);
	Draw::LoadImageW(L"Floor3_Enemy.png", 20, TEX_SIZE_100);
	//Draw::LoadImageW(L"ENEMYBOSS3.png", 20, TEX_SIZE_800_600);
	
	
	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 115);

	//blockオブジェクト作成
	CObjBlock* objb = new CObjBlock(map);
	Objs::InsertObj(objb, OBJ_BLOCK, 109);

	CObjTopback* objtb = new CObjTopback();
	Objs::InsertObj(objtb, OBJ_TOPBACK, 119);

	CObjMain* objm = new CObjMain();
	Objs::InsertObj(objm, OBJ_MAIN, 120);

	CObjMessage* objmessa = new CObjMessage();
	Objs::InsertObj(objmessa, OBJ_MESSAGE, 120);

	

	//主人公オブジェクト作成
	CObjHeroBattle* bhero = new CObjHeroBattle();
	Objs::InsertObj(bhero, OBJ_HERO_BATTLE, 10);

	//blockオブジェクト作成
	CObjBlockBattle* bobjb = new CObjBlockBattle();
	Objs::InsertObj(bobjb, OBJ_BLOCK_BATTLE, 9);
	
	
	////敵(1層目)オブジェクト作成
	//CObjEnemy1Battle* bobje1 = new CObjEnemy1Battle();
	//Objs::InsertObj(bobje1, OBJ_ENEMY_BATTLE_FIRST, 10);

	//敵(2層目)オブジェクト作成
	/*CObjEnemy2Battle* bobje2 = new CObjEnemy2Battle();
	Objs::InsertObj(bobje2, OBJ_ENEMY_BATTLE_SECOND, 10);*/

	//敵(3層目)オブジェクト作成
	/*CObjEnemy3Battle* bobje3 = new CObjEnemy3Battle();
	Objs::InsertObj(bobje3, OBJ_ENEMY_BATTLE_THIRD, 10);*/
	
	//背景(戦闘)オブジェクト作成
	CObjBackgroundBattle* bobjbackb = new CObjBackgroundBattle();
	Objs::InsertObj(bobjbackb, OBJ_BACKGROUND_BATTLE,8);
}

//ゲームタイトルの実行中メソッド
void CSceneMain::Scene()
{
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	m_enemy_flag = hero->GetENEMYF();
	m_boss_flag = hero->GetBOSSF();

	if (m_enemy_flag == true)		//フラグがオンの時、敵出現
	{
		CObjEnemy1Battle* bobje = new CObjEnemy1Battle();
		Objs::InsertObj(bobje, OBJ_ENEMY_BATTLE_FIRST, 10);
		m_enemy_flag = false;
		hero->SetENEMYF(m_enemy_flag);
	}
	if (m_boss_flag == true)		//フラグがオンの時、ボス出現
	{
		CObjBoss1Battle* bobjb = new CObjBoss1Battle();
		Objs::InsertObj(bobjb, OBJ_BOSS_BATTLE_FIRST, 10);
		m_boss_flag = false;
		hero->SetBOSSF(m_boss_flag);
	}
}
