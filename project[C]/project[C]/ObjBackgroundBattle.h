#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：背景
class CObjBackgroundBattle : public CObj
{
public:
	CObjBackgroundBattle() {};
	~CObjBackgroundBattle() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
private:

};

