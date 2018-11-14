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

	float GetX() { return m_px; }
	float GetY() { return m_py; }
	float GetVY() { return m_vy; }
	float GetVX() { return m_vx; }

	int GetBATTLEHP() { return m_battle_hp; }
	int GetBATTLEMP() { return m_battle_mp; }
	int GetBATTLEMAGIC() { return m_battle_magic; }

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

	int m_battle_hp;
	int m_battle_mp;
	int m_battle_magic;

	int	  m_ani_time;	//アニメーションフレーム動作間隔
	int   m_ani_frame;	//描画フレーム

	float m_speed_power;	//スピードパワー
	float m_ani_max_time;	//アニメーション動作間隔最大値

	//テスト用
	float px, py;		//交点
};

