#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：敵(戦闘)
class CObjEnemyBattle : public CObj
{
public:
	CObjEnemyBattle() {};
	~CObjEnemyBattle() {};
	void Init();		//イニシャライズ
	void Action();		//アクション
	void Draw();		//ドロー

	float GetX() { return g_enemy_px; }
	float GetY() { return g_enemy_py; }
	float GetVY() { return m_vy; }
	float GetVX() { return m_vx; }
	int GetBT() { return m_block_type; }

	void SetX(float x) { g_enemy_px = x; }
	void SetY(float y) { g_enemy_py = y; }
	void SetVY(float vy) { m_vy = vy; }
	void SetVX(float vx) { m_vx = vx; }
	void SetBT(int t) { m_block_type = t; }

private:
	float g_enemy_px;//位置
	float g_enemy_py;
	float m_vx;			//移動ベクトル
	float m_vy;
	float m_posture;	//姿勢

	int	  m_ani_time;	//アニメーションフレーム動作間隔
	int   m_ani_frame;	//描画フレーム
	int   m_enemy_hp;   //敵の体力

	float m_speed_power;	//スピードパワー
	float m_ani_max_time;	//アニメーション動作間隔最大値

	//踏んでいるblockの種類を確認用
	int m_block_type;

	//テスト用
	float px, py;		//交点

	//移動の向き制御用
	bool m_move;
};
