#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

#define TIME_INTERVAL 1000

//オブジェクト：主人公
class CObjEnemy2 : public CObj
{
public:
	CObjEnemy2(float x, float y);
	~CObjEnemy2() {};
	void Init();		//イニシャライズ
	void Action();		//アクション
	void Draw();		//ドロー

	float GetVx() { return m_vx; }
	float GetVy() { return m_vy; }

private:
	float m_px;			//位置
	float m_py;
	float m_vx;			//移動ベクトル
	float m_vy;
	float m_posture;	//姿勢

	float m_move;

	int	  m_ani_time;	//アニメーションフレーム動作間隔
	int   m_ani_frame;	//描画フレーム
	int   m_time;

	float m_speed_power;	//スピードパワー
	float m_ani_max_time;	//アニメーション動作間隔最大値

	bool battle_flag;	//バトル切り替え用

						//blockとの衝突状態確認用
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;
};