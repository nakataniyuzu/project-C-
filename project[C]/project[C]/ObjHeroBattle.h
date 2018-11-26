#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：主人公(戦闘)
class CObjHeroBattle : public CObj
{
public:
	CObjHeroBattle() {};
	~CObjHeroBattle() {};
	void Init();		//イニシャライズ
	void Action();		//アクション
	void Draw();		//ドロー

	float GetX() { return m_px; }		//主人公のX位置を取得
	float GetY() { return m_py; }		//主人公のY位置を取得
	float GetPOS() { return m_posture; }//主人公の向きを取得
	float GetVY() { return m_vy; }		
	float GetVX() { return m_vx; }		
	bool GetBATTLER() { return m_battle_flag; }


	int GetBATTLEHP() { return m_battle_hp; }		//主人公のHPを取得
	int GetBATTLEMP() { return m_battle_mp; }		//主人公のMPを取得
	int GetBATTLEMAGIC() { return m_battle_magic; }	//主人公の設定魔法を取得

	void SetX(float x) { m_px = x; }
	void SetY(float y) { m_py = y; }
	void SetVY(float vy) { m_vy = vy; }
	void SetVX(float vx) { m_vx = vx; }
private:
	float m_px;			//位置
	float m_py;
	float m_vx;			//移動ベクトル
	float m_vy;
	float m_posture;	//姿勢
	float m_directionx; //魔法発射用X方向
	float m_directiony; //魔法発射用Y方向

	int m_battle_hp;	//体力(戦闘)
	int m_battle_mp;	//魔法使用回数(戦闘)
	int m_battle_magic;	//魔法切り替え(戦闘)

	int m_time;		//無敵時間用

	int	  m_ani_time;	//アニメーションフレーム動作間隔
	int   m_ani_frame;	//描画フレーム

	float m_speed_power;	//スピードパワー
	float m_ani_max_time;	//アニメーション動作間隔最大値

	bool  m_f;		//キー（長押し）制御用
	bool  m_mf;		//キー（長押し）制御用

	bool m_battle_flag;	//マップに戻るフラグ
	bool m_hit_down; //敵の頭の判定用

	//テスト用
	float px, py;		//交点
};

