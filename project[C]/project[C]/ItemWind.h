#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//ITEM：ICE
class CObjItemWind : public CObj
{
public:
	CObjItemWind(float x, float y);
	~CObjItemWind() {};
	void Init();		//イニシャライズ
	void Action();		//アクション
	void Draw();		//ドロー

	float GetVY() { return m_vy; }
	float GetVX() { return m_vx; }

private:
	float m_px;			//位置
	float m_py;
	float m_vx;			//移動ベクトル
	float m_vy;

	int m_time;			//表示する時間
	bool m_battle_flag;
};
