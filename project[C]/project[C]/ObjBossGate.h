#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：ブロック＆背景
class CObjBossGate : public CObj
{
public:
	CObjBossGate(float x, float y);
	~CObjBossGate() {};
	void Init();		//イニシャライズ
	void Action();		//アクション
	void Draw();		//ドロー

private:
	float m_px;			//位置
	float m_py;
	float m_vx;			//移動ベクトル
	float m_vy;

	int m_time;	//メッセージ時間管理
	bool m_change;	//スイッチのオンオフ
};
