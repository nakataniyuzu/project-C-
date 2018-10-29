//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneMenu.h"
#include "GameHead.h"

//コンストラクタ
CSceneMenu::CSceneMenu()
{

}

//デストラクタ
CSceneMenu::~CSceneMenu()
{

}

//ゲームメニュー初期化メソッド
void CSceneMenu::InitScene()
{
	CObjMenu* p = new CObjMenu();
	Objs::InsertObj(p, OBJ_TITLE, 1);
}

//ゲームメニュー実行中メソッド
void CSceneMenu::Scene()
{

}