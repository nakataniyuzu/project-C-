#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：タイトル
class CObjNextfloor :public CObj
{
public:
	CObjNextfloor() {};
	~CObjNextfloor() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー

private:
	int m_floor;		//何層目かを分ける変数
	float m_time;			//n層目の表示アニメーション用
	int m_next_time;	//次へ進むまでの待機時間
	float m_and;		//透明度処理用
	bool m_andf;		//透明度処理用フラグ
	bool m_keyf;		//キー制御フラグ
};