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

	if (g_map_change == 0) {
		p = Save::ExternalDataOpen(L"map1.csv", &size);//外部データ読み込み
	}
	else if (g_map_change == 1) {
		p = Save::ExternalDataOpen(L"map2.csv", &size);//外部データ読み込み
	}

	int map[38][65];
	int count = 1;
	for (int i = 0; i < 38; i++)
	{
		for (int j = 0; j < 65; j++)
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

	m_time = 0;

	//グラフィック読み込み
	Draw::LoadImageW(L"Hero.png", 0, TEX_SIZE_256);
	if (g_map_change == 0) {
		Draw::LoadImageW(L"Floor1.png", FLOOR, TEX_SIZE_800_600);		//1層目の床
		Draw::LoadImageW(L"Floor1Block.png", BLOCK, TEX_SIZE_800_600);	//1層目のブロック
		Draw::LoadImageW(L"Floor1_Enemy.png", 7, TEX_SIZE_200_100);		//1層目の敵
		Draw::LoadImageW(L"ENEMYBOSS1.png", 14, TEX_SIZE_800_600);		//1層目の敵
		Draw::LoadImageW(L"Floor1_Enemy_Death.png", 23, TEX_SIZE_100);	//1層目の敵の死亡アニメーション
		Draw::LoadImageW(L"ENEMYBOSS1_DEATH.png", 25, TEX_SIZE_100);	//1層目のボスの死亡アニメーション
	}
	else if (g_map_change == 1) {
		Draw::LoadImageW(L"Floor2.png", FLOOR, TEX_SIZE_800_600);		//2層目の床
		Draw::LoadImageW(L"Floor2Block.png", BLOCK, TEX_SIZE_800_600);	//2層目のブロック
		Draw::LoadImageW(L"Floor2_Enemy.png", 7, TEX_SIZE_200_100);		//2層目の敵
		Draw::LoadImageW(L"ENEMYBOSS2.png", 14, TEX_SIZE_800_600);		//2層目の敵
		Draw::LoadImageW(L"Floor2_Enemy_Death.png", 23, TEX_SIZE_100);	//2層目の敵の死亡アニメーション
		Draw::LoadImageW(L"ENEMYBOSS2_DEATH.png", 25, TEX_SIZE_100);	//2層目のボスの死亡アニメーション

	}
	else if (g_map_change == 2) {
		Draw::LoadImageW(L"Floor3.png", FLOOR, TEX_SIZE_800_600);		//3層目の床
		Draw::LoadImageW(L"Floor3Block.png", BLOCK, TEX_SIZE_800_600);	//3層目のブロック
		Draw::LoadImageW(L"Floor3_Enemy.png", 7, TEX_SIZE_200_100);		//3層目の敵
		Draw::LoadImageW(L"ENEMYBOSS3.png", 14, TEX_SIZE_800_600);		//3層目の敵
		Draw::LoadImageW(L"Floor3_Enemy_Death.png", 23, TEX_SIZE_100);	//3層目の敵の死亡アニメーション
		Draw::LoadImageW(L"ENEMYBOSS3_DEATH.png", 25, TEX_SIZE_100);	//3層目のボスの死亡アニメーション
	}

	Draw::LoadImageW(L"image.png", 3, TEX_SIZE_100);
	Draw::LoadImageW(L"healkey.png", HEALKEY, TEX_SIZE_100);
	Draw::LoadImageW(L"Water.png", 6, TEX_SIZE_200);
	Draw::LoadImageW(L"Magic.png", 8, TEX_SIZE_100);
	Draw::LoadImageW(L"Candle.png", 9, TEX_SIZE_200_100);
	Draw::LoadImageW(L"magicitem.png", ITEM, TEX_SIZE_256);
	Draw::LoadImageW(L"Hero2.png", 11, TEX_SIZE_100);


	Draw::LoadImageW(L"MagicBattle.png", 13, TEX_SIZE_256);
	Draw::LoadImageW(L"sister.png", 15, TEX_SIZE_800_600);
	Draw::LoadImageW(L"Sword.png", 16, TEX_SIZE_800_600);
	Draw::LoadImageW(L"Fadein.png", 17, TEX_SIZE_16000_600);
	Draw::LoadImageW(L"Stairs.png", 18, TEX_SIZE_100);
	Draw::LoadImageW(L"Floor1~2.png", 50, TEX_SIZE_800_600);
	Draw::LoadImageW(L"ENEMYBOSS3_MAGIC.png", 24, TEX_SIZE_100);

	Draw::LoadImageW(L"AllFloorBlock.png", 4, TEX_SIZE_200_100);

	
	//オーディオ読み込み
	Audio::LoadAudio(0, L"ATTACK.WAV", EFFECT);
	Audio::LoadAudio(1, L"BATTLE-START.wav", EFFECT);
	Audio::LoadAudio(2, L"BATTLE-WIN.wav", EFFECT);
	Audio::LoadAudio(3, L"DAMAGE.WAV", EFFECT);
	Audio::LoadAudio(4, L"DOOR-OPEN.wav", EFFECT);
	Audio::LoadAudio(5, L"ENE-MAGIC.wav", EFFECT);
	Audio::LoadAudio(6, L"ENE-RANGE-ATTACK.wav", EFFECT);
	Audio::LoadAudio(7, L"FIRE.WAV", EFFECT);
	Audio::LoadAudio(8, L"ICE.WAV", EFFECT);
	Audio::LoadAudio(9, L"THUNDER.WAV", EFFECT);
	Audio::LoadAudio(10, L"HEAL.WAV", EFFECT);
	Audio::LoadAudio(11, L"ZELDA.WAV", EFFECT);

	Audio::LoadAudio(14, L"ENTER.wav", EFFECT);

	Audio::LoadAudio(12, L"STAGEBGM候補1.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(13, L"BATTLE-BGM.wav", SOUND_TYPE::BACK_MUSIC);

	//BGMスタート
	float Volume = Audio::Volume(1.0,12);//ボリュームさげる
	Audio::Start(12);
	
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

	//雑魚
	if (m_enemy_flag == true)		//フラグがオンの時、敵出現
	{
		Audio::Stop(12);
		Audio::Start(13);
		if (g_map_change == 0) {
			CObjEnemy1Battle* bobje1 = new CObjEnemy1Battle();
			Objs::InsertObj(bobje1, OBJ_ENEMY_BATTLE_FIRST, 10);
		}
		else if (g_map_change == 1) {
			CObjEnemy2Battle* bobje2 = new CObjEnemy2Battle();
			Objs::InsertObj(bobje2, OBJ_ENEMY_BATTLE_SECOND, 10);
		}
		m_enemy_flag = false;
		hero->SetENEMYF(m_enemy_flag);
	}
	//ボス
	if (m_boss_flag == true)		//フラグがオンの時、ボス出現
	{
		if (g_map_change == 0) {
			CObjBoss1Battle* bobjb1 = new CObjBoss1Battle();
			Objs::InsertObj(bobjb1, OBJ_BOSS_BATTLE_FIRST, 10);
		}
		else if (g_map_change == 1) {
			CObjBoss2Battle* bobjb2 = new CObjBoss2Battle();
			Objs::InsertObj(bobjb2, OBJ_BOSS_BATTLE_SECOND, 10);
		}
		m_boss_flag = false;
		hero->SetBOSSF(m_boss_flag);
	}
}
