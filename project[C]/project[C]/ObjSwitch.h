#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：ブロック＆背景
class CObjSwitch : public CObj
{
	public:
		CObjSwitch(float x, float y);
		~CObjSwitch() {};
		void Init();		//イニシャライズ
		void Action();		//アクション
		void Draw();		//ドロー

	private:
		float m_px;			//位置
		float m_py;
		float m_vx;			//移動ベクトル
		float m_vy;
		float m_posture;	//姿勢

};
