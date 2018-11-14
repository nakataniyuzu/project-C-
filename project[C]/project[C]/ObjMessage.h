#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：タイトル
class CObjMessage :public CObj
{
	public:
		CObjMessage() {};
		~CObjMessage() {};
		void Init();	//イニシャライズ
		void Action();	//アクション
		void Draw();	//ドロー

	private:

};

