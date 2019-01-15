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
#include "SceneClear.h"
#include "GameHead.h"

//コンストラクタ
CSceneClear::CSceneClear()
{

}

//デストラクタ
CSceneClear::~CSceneClear()
{

}

//ゲームタイトルの初期化メソッド
void CSceneClear::InitScene()
{
	Draw::LoadImageW(L"題.png", 0, TEX_SIZE_800_600);


	CObjClear* p = new CObjClear();
	Objs::InsertObj(p, OBJ_CLEAR, 1);

}

//ゲームタイトルの実行中メソッド
void CSceneClear::Scene()
{

}
