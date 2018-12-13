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
#include "SceneTitle.h"
#include "GameHead.h"

//コンストラクタ
CSceneTitle::CSceneTitle()
{

}

//デストラクタ
CSceneTitle::~CSceneTitle()
{

}

//ゲームタイトルの初期化メソッド
void CSceneTitle::InitScene()
{
	Draw::LoadImageW(L"Title.png", 0, TEX_SIZE_800_600);

	//オーディオ読み込み
	Audio::LoadAudio(1, L"SERECT.wav", EFFECT);
	Audio::LoadAudio(2, L"ENTER.wav", EFFECT);
	Audio::LoadAudio(100, L"TITLE-BGM.WAV", SOUND_TYPE::BACK_MUSIC);


	CObjTitle* p = new CObjTitle();
	Objs::InsertObj(p, OBJ_TITLE, 1);

}

//ゲームタイトルの実行中メソッド
void CSceneTitle::Scene()
{

}
