#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：主人公
class CObjSister : public CObj
{
public:
	CObjSister(float x, float y);
	~CObjSister() {};
	void Init();		//イニシャライズ
	void Action();		//アクション
	void Draw();		//ドロー

private:
	float m_px;			//位置
	float m_py;
	
	int m_drawt1;	//文字表示時間
	int m_drawt2;
	bool m_change;//画像切り替え用
};
