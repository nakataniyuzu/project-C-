#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：主人公
class CObjHero : public CObj
{
public:
	CObjHero() {};
	~CObjHero() {};
	void Init();		//イニシャライズ
	void Action();		//アクション
	void Draw();		//ドロー

 	float GetX() { return m_px; }
	float GetY() { return m_py; }
	float GetPOS() { return m_posture; }
	int GetHP() { return m_hp; }
	int GetMP() { return m_mp; }
	int GetMAGIC() { return m_magic; }

	float GetVY() { return m_vy; }
	float GetVX() { return m_vx; }
	int GetBT() { return m_block_type; }

	void SetX(float x) { m_px = x; }
	void SetY(float y) { m_py = y; }
	void SetVY(float vy) { m_vy = vy; }
	void SetVX(float vx) { m_vx = vx; }
	void SetBT(int t) { m_block_type = t; }

	void SetUp(bool b) { m_hit_up = b; }
	void SetDown(bool b) { m_hit_down = b; }
	void SetLeft(bool b) { m_hit_left = b; }
	void SetRight(bool b) { m_hit_right = b; }
private:
	float m_px;			//位置
	float m_py;
	float m_vx;			//移動ベクトル
	float m_vy;
	float m_posture;	//姿勢
	float m_directionx; //魔法発射用X方向
	float m_directiony; //魔法発射用Y方向

	int m_hp;			//体力
	int m_mp;			//魔法使用回数
	int m_magic;		//魔法切り替え


	float m_scrollx;		//左右スクロール用
	float m_scrolly;		//上下スクロール用
	bool  m_f;		//キー（長押し）制御用
	bool  m_mf;		//キー（長押し）制御用


	int   m_time;			//表示する時間
	int	  m_ani_time;	//アニメーションフレーム動作間隔
	int   m_ani_frame;	//描画フレーム

	float m_speed_power;	//スピードパワー
	float m_ani_max_time;	//アニメーション動作間隔最大値

	//blockとの衝突状態確認用
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

	//踏んでいるblockの種類を確認用
	int m_block_type;

};
