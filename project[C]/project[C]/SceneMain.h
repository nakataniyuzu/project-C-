#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//マクロ
#define FLOOR1 01
#define ITEM 10

//シーン：ゲームタイトル
class CSceneMain :public CScene
{
	public:
		CSceneMain();
		~CSceneMain();
		void InitScene();//ゲームメインの初期化メソッド
		void Scene();    //ゲームメインの実行中メソッド
	private:
		/*int m_map[10][10];	//マップ情報*/
};
