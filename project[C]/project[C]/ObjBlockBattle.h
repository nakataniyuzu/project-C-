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
};
