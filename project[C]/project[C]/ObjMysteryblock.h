#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：ブロック＆背景
class CObjMysteryblock : public CObj
{
public:
	CObjMysteryblock(float x, float y);
	~CObjMysteryblock() {};
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
	float m_posture;	//姿勢
	int m_time;			//表示する時間

	int key;	//鍵
	//blockとの衝突状態確認用
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

	//移動の向き制御用
	bool m_move;

};

