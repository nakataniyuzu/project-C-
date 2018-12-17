#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"
#include "ObjMessage.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：ブロック＆背景
class CObjFireblock : public CObj
{
public:
	CObjFireblock(float x, float y);
	~CObjFireblock() {};
	void Init();		//イニシャライズ
	void Action();		//アクション
	void Draw();		//ドロー

	float GetVY() { return m_vy; }
	float GetVX() { return m_vx; }
	float GetSWITCH(){ return m_switch; }

private:
	float m_px;			//位置
	float m_py;
	float m_vx;			//移動ベクトル
	float m_vy;
	float m_posture;	//姿勢
	
	int m_time;			//表示する時間
	int m_draw_time;
	//描画切り替え用
	int m_switch;

	bool m_battle_flag;
};


