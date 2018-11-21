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
#include "SceneGameover.h"
#include "GameHead.h"

//コンストラクタ
CSceneGameover::CSceneGameover()
{

}

//デストラクタ
CSceneGameover::~CSceneGameover()
{

}

//ゲームタイトルの初期化メソッド
void CSceneGameover::InitScene()
{
	Draw::LoadImageW(L"Title.png", 0, TEX_SIZE_800_600);


	CObjGameover* p = new CObjGameover();
	Objs::InsertObj(p, OBJ_GAMEOVER, 1);

}

//ゲームタイトルの実行中メソッド
void CSceneGameover::Scene()
{

}
