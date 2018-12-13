#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;


//オブジェクト：メニュー
class CObjBattleMain :public CObj
{
public:
	CObjBattleMain() {};
	~CObjBattleMain() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
private:
	int hero_hp;
	int hero_mp;
	int magic_type;

};
