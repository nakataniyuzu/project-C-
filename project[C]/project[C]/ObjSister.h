#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

#define TIME_INTERVAL 1000

//オブジェクト：主人公
class CObjSister : public CObj
{
public:
	CObjSister(float x, float y);
	~CObjSister() {};
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

	bool battle_flag;	//バトル切り替え用
	bool boss_battle_flag; //ボス戦切り替え用
};
