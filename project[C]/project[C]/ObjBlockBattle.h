#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：ブロック(戦闘)
class CObjBlockBattle : public CObj
{
public:
	CObjBlockBattle();
	~CObjBlockBattle() {};
	void Init();		//イニシャライズ
	void Action();		//アクション
	void Draw();		//ドロー

private:
	bool m_battle_flag;
	int m_map[12][16]; //ブロック情報
};
