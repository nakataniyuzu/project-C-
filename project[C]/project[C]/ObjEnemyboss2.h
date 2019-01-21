#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

#define TIME_INTERVAL 1000

//オブジェクト：主人公
class CObjEnemyboss2 : public CObj
{
public:
	CObjEnemyboss2(float x, float y);
	~CObjEnemyboss2() {};
	void Init();		//イニシャライズ
	void Action();		//アクション
	void Draw();		//ドロー

private:
	float m_px;			//位置
	float m_py;

	//blockとの衝突状態確認用
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

	bool battle_flag;		//バトル移行用
	bool hero_posture;		//主人公の向き

	int   m_time;

};
