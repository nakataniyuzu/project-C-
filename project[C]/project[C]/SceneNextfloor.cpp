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
#include "SceneNextfloor.h"
#include "GameHead.h"

//コンストラクタ
CSceneNextfloor::CSceneNextfloor()
{

}

//デストラクタ
CSceneNextfloor::~CSceneNextfloor()
{

}

//ゲームタイトルの初期化メソッド
void CSceneNextfloor::InitScene()
{
	Draw::LoadImageW(L"Floor1up2.png", 0, TEX_SIZE_800_600);
	Draw::LoadImageW(L"Floor2up3.png", 1, TEX_SIZE_800_600);

	
	CObjNextfloor* p = new CObjNextfloor();
	Objs::InsertObj(p, OBJ_CLEAR, 1);
}

//ゲームタイトルの実行中メソッド
void CSceneNextfloor::Scene()
{

}
