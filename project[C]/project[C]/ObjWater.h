#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：ブロック＆背景
class CObjWater : public CObj
{
public:
	CObjWater(float x, float y);
	~CObjWater() {};
	void Init();		//イニシャライズ
	void Action();		//アクション
	void Draw();		//ドロー

	float GetVY() { return m_vy; }
	float GetVX() { return m_vx; }

private:
	int m_map[27][55];	//マップ情報

	float m_px;			//位置
	float m_py;
	float m_vx;			//移動ベクトル
	float m_vy;
	float m_posture;	//姿勢

	int	m_ani_time;
	int m_ani_frame;
	float m_switch;	//画像切り替え用

	float m_ani_max_time;	//アニメーション動作間隔最大値

	bool m_battle_flag;

	//blockとの衝突状態確認用
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

	//移動の向き制御用
	bool m_move;

	int m_block_type;

};

