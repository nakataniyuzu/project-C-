//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjHeroBattle.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjHeroBattle::Init()
{
	
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	m_battle_hp = hero->GetHP();	//主人公からHPの情報を取得
	m_battle_mp = hero->GetMP();	//主人公からMPの情報を取得
	m_battle_magic = hero->GetMAGIC();	//主人公からMAGICの情報を取得
	
	m_px = 100.0f;
	m_py = 450.0f;		//位置
	m_vx = 0.0f;		//移動ベクトル
	m_vy = 0.0f;
	m_posture = 0.0f;	//右向き0.0f 左向き1.0f

	m_ani_time = 0;
	m_ani_frame = 1;	//静止フレームを初期にする

	m_speed_power = 0.7f;	//通常速度
	m_ani_max_time = 4;		//アニメーション間隔幅


	//当たり判定用のHitBoxを作成
 	Hits::SetHitBox(this, m_px, m_py, 75, 100, ELEMENT_PLAYER, OBJ_HERO_BATTLE, 1);
}

//アクション
void CObjHeroBattle::Action()
{
	//移動ベクトルの破棄
	//m_vy = 0.0f;

	//キーの入力方向 
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_vx += m_speed_power;
		m_posture = 0.0f;
		m_ani_time += 1;
	}
	else if (Input::GetVKey(VK_LEFT) == true)
	{
		m_vx -= m_speed_power;
		m_posture = 1.0f;
		m_ani_time += 1;
	}
	else
	{
		m_ani_frame = 0; //キー入力が無い場合は静止フレームにする
		m_ani_time = 0;
	}
	if (m_ani_time > 8)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}
	if (m_ani_frame == 4)
	{
		m_ani_frame = 0;
	}

	//Spaceキーでジャンプ
	if (m_py + 100 >= 549)
	{
		if (Input::GetVKey(VK_SPACE) == true)
		{
			if (1)
			{
				m_vy = -40;
			}
		}
	}

	//摩擦
	m_vx += -(m_vx * 0.098);
	m_vy += -(m_vy * 0.098);

	//自由落下運動
	m_vy += 15.8 / (16.0f);

	//自身のHitBoxを持ってくる
	CHitBox* hit = Hits::GetHitBox(this);

	//位置の更新
	m_px += m_vx;
	m_py += m_vy;

	//HitBoxの位置の変更
	hit->SetPos(m_px, m_py);

	//敵機オブジェクトと接触したら主人公削除
	/*if (hit->CheckElementHit(ELEMENT_ENEMY) == true)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}*/

	//主人公が領域外に行かないようにする
	if (m_px + 75 >= 800)
	{
		m_px = 800.0 - 75.0f;
		Scene::SetScene(new CSceneMain());
	}
	if (m_px < 0)
	{
		m_px = 0.0f;
	}
	if (m_py + 100 >= 580)
	{
		m_py = 580.0f - 100.0f;
	}
	if (m_py <50)
	{
		m_py = 50.0f;
	}
}

//ドロー
void CObjHeroBattle::Draw()
{
	int AniData[4] =
	{
		0,1,2,3,
	};

	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画先表示位置

	//切り取り位置の設定
	src.m_top    =  0.0f;
	src.m_left   = 60.0f + AniData[m_ani_frame] *60;
	src.m_right  =  0.0f + AniData[m_ani_frame] *60;
	src.m_bottom = 60.0f;

	//表示位置の設定
	dst.m_top    = 0.0f + m_py;
	dst.m_left   = (75.0f * m_posture) + m_px;
	dst.m_right  = (75 - 75.0f * m_posture) + m_px;
	dst.m_bottom = 100.0f + m_py;

	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);

}