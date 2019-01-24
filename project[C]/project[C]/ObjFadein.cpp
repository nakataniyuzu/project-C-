//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameHead.h"
#include "GameL\WinInputs.h"
#include "GameL\Audio.h"
#include "ObjFadein.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjFadein::Init()
{
	m_ani_time = 0;
	m_ani_frame = 0;	//静止フレームを初期にする

	m_ani_max_time = 2;		//アニメーション間隔幅

	m_flag = true;			//切り替え用フラグ
	m_fade_flag = true;		//フェイドインの切り替え用フラグ
	//フラグの初期化
	m_next_flag = false;
	m_main_flag = false;
	m_death_flag = false;
	m_clear_flag = false;
}

//アクション
void CObjFadein::Action()
{
	//主人公の情報を持ってくる
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	hero->SetSPEED(0.0f);	//スピードを０にする
	hero->SetVX(0.0f);		//ベクトルを０にする
	hero->SetVY(0.0f);
	m_next_flag = hero->GetNEXTF();	//ネクストフラグを取得
	m_fade_flag = hero->GetFADEF();	//フェイドインかアウトを設定するためのフラグ
	m_death_flag = hero->GetDEATHF();//死亡したか判断するためのフラグを取得
	m_clear_flag = hero->GetCLEAR();//クリアシーンへ移行するためのフラグを取得

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
			if (m_next_flag == true)	//フラグがオンの場合
			{
				Scene::SetScene(new CSceneNextfloor());	//ゲームネクストシーンに移行
			}
			if (m_main_flag == true)	//フラグがオンの場合
			{
				Scene::SetScene(new CSceneMain());	//ゲームメインシーンに移行
			}
			if (m_death_flag == true)	//フラグがオンの場合
			{
				Scene::SetScene(new CSceneGameover());	//ゲームオーバーシーンに移行
			}
			if (m_clear_flag == true)
			{
				Scene::SetScene(new CSceneClear());	//ゲームクリアシーンに移行
			}
			m_flag = false;
			if (m_fade_flag == false) {
				g_xp_flag = true;		//経験値フラグをオンに戻す
				g_battle_flag = false;//マップ画面へ移行
				g_key_flag = false;		//キー入力制御フラグをオフにする
				g_battle_key = true;//マップ画面へ移行
				g_mhit_enemy_flag = false;//敵をうごかす
				Audio::Stop(13);
				Audio::Start(12);	//マップ用BGMを鳴らす
			}
			else {
				g_battle_flag = true;//バトル画面へ移行
				Audio::Stop(12);
				Audio::Start(13);	//マップ用BGMを鳴らす
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
			hero->SetFADEF(false);
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

