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
	int choice;
	int m_time;		//キーの入力時間間隔
	bool m_key_flag;
};