#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//マクロ
#define FLOOR1 01
#define BLOCK1 2
#define HEALKEY 5
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
		int i, j;
		bool m_battle_flag;
		bool m_enemy_flag;
		bool m_boss_flag;
		bool m_f;

		int m_time;
};
