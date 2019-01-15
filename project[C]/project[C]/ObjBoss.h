#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：主人公
class CObjBoss : public CObj
{
	public:
		CObjBoss(float x, float y);
		~CObjBoss() {};
		void Init();		//イニシャライズ
		void Action();		//アクション
		void Draw();		//ドロー

	private:
		float m_px;			//位置
		float m_py;
		float m_vx;			//移動ベクトル
		float m_vy;
		bool m_battle_flag;	//バトル切り替え用
		bool m_boss_battle_f;	//ボス戦用フラグ

};
