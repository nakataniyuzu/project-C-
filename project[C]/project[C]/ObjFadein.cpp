//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameHead.h"
#include "GameL\WinInputs.h"

#include "ObjFadein.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjFadein::Init()
{
	m_ani_time = 0;
	m_ani_frame = 0;	//静止フレームを初期にする

	m_ani_max_time = 2;		//アニメーション間隔幅
	m_flag = true;		//切り替え用フラグ
}

//アクション
void CObjFadein::Action()
{
	//戦闘時の敵の情報を持ってくる
	CObjEnemy1Battle* benemy = (CObjEnemy1Battle*)Objs::GetObj(OBJ_ENEMY_BATTLE);
	
	//主人公の情報を持ってくる
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	hero->SetSPEED(0.0f);	//スピードを０にする
	hero->SetVX(0.0f);		//ベクトルを０にする
	hero->SetVY(0.0f);
	m_next_flag = hero->GetNEXTF();	//ネクストフラグを取得
	m_fade_flag = hero->GetFADEF();	//フェイドインかアウトを設定するためのフラグ



	if (m_flag == true)
	{
		m_ani_time += 1;

		if (m_ani_time > m_ani_max_time)
		{
			m_ani_frame += 1;
			m_ani_time = 0;
		}
		if (m_ani_frame == 9)
		{
			if (m_next_flag == true)
			{
				Scene::SetScene(new CSceneNextfloor());	//ゲームネクストシーンに移行
			}
			if (m_main_flag == true)
			{
				Scene::SetScene(new CSceneMain());	//ゲームメインシーンに移行
			}
			m_flag = false;
			if (m_fade_flag == false) {
				g_battle_flag = false;
				//hero->SetBATTLE(true);		//マップ画面へ移行
			}
			else {
				g_battle_flag = true;
				//hero->SetBATTLE(false);			//バトル画面へ移行
			}
		}
	}
	else if(m_flag == false)
	{
		m_ani_time += 1;

		if (m_ani_time > m_ani_max_time)
		{
			m_ani_frame -= 1;
			m_ani_time = 0;
		}
		if (m_ani_frame == 0)
		{
			this->SetStatus(false);
		}
	}
}

//ドロー
void CObjFadein::Draw()
{
	//描画カラー情報　R=RED  G=Green  B=Blue A=alpha(透過情報)
	float  c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;		//描画元切り取り位置
	RECT_F dst;		//描画先表示位置

	//背景切り取り
	src.m_top    =   0.0f;
	src.m_left   =   0.0f + (800.0f * m_ani_frame);
	src.m_right  = 800.0f + (800.0f * m_ani_frame);
	src.m_bottom = 600.0f;

	//描画
	dst.m_top    =   0.0f;
	dst.m_left   =   0.0f;
	dst.m_right  = 800.0f;
	dst.m_bottom = 600.0f;
	Draw::Draw(17, &src, &dst, c, 0.0f);
}

