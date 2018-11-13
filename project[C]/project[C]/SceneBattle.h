#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//マクロ
#define FLOOR1_WALL 02

//シーン：戦闘
class CSceneBattle :public CScene
{
public:
	CSceneBattle();
	~CSceneBattle();
	void InitScene();//ゲームタイトルの初期化メソッド
	void Scene();	 //ゲームタイトルの実行中メソッド
private:
	
};
