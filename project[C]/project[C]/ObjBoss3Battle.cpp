//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\Audio.h"

#include "GameHead.h"
#include "ObjBoss3Battle.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjBoss3Battle::Init()
{
	m_px = 300.0f;
	m_py = 500.0f;		//出現位置

	m_vx = 0.0f;		//移動ベクトル
	m_vy = 0.0f;
	m_boss_hp = 50;     //敵のヒットポイント(最大50)
	m_damage = 5;
	m_delay = 5;

	m_ani_time = 0;
	m_ani_frame = 1;	//静止フレームを初期にする
	m_posture = 0.0f;	//右向き0.0f 左向き1.0f

	m_speed_power = 1.5f;	//通常速度
	m_ani_max_time = 4;		//アニメーション間隔幅
	m_pop_flag = true;
	m_move = true;  //true=右 false=左

	m_time = 0;

	//当たり判定用のHitBoxを作成
	Hits::SetHitBox(this, m_px, m_py, 75, 100, ELEMENT_BOSS_BATTLE, OBJ_BOSS_BATTLE_THIRD, 1);
}

//アクション
void CObjBoss3Battle::Action()
{
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	m_boss_flag = hero->GetBATTLE();
	hero_posture = hero->GetPOS();
	enemy_flag = hero->GetENEMYF();

	if (boss_delete_flag == true)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		return;
	}
	//マップ上の主人公の向きによってリス位置、向きを設定
	if (m_pop_flag == true)
	{
		if (hero_posture == 0.0f || hero_posture == 1.0f)
		{
			m_px = 600.0f;
			m_py = 500.0f;		//出現位置
			m_move = true;	//向き
		}
		else if (hero_posture == 2.0f || hero_posture == 3.0f)
		{
			m_px = 100.0f;
			m_py = 500.0f;		//出現位置
			m_move = false;	//向き
		}
		m_pop_flag = false;	//向き用フラグ
	}

	if (g_battle_flag == false)
	{
		m_vx = 0.0f;
		m_vy = 0.0f;
		m_pop_flag = true;
		return;
	}

	
	//ボスの向きによって発射する向きを設定
	if (m_posture == 0.0f) {
		m_directionx = 50.0f;
		m_directiony = 0.0f;
	}
	else if (m_posture == 1.0f) {
		m_directionx = -50.0f;
		m_directiony = 0.0f;
	}

	//画面端衝突で向き変更＆魔法発射
	if (m_delay <= 0)
	{
		if (m_px + 75 >= 800)
		{
			m_move = true;
			CObjEnemyMagicBattle* objemb = new CObjEnemyMagicBattle(m_px - m_directionx, m_py + m_directiony);
			Objs::InsertObj(objemb, OBJ_ENEMY_MAGIC_BATTLE, 100);
			m_delay = 2;
			Audio::Start(5);
		}
		else if (m_px <= 0)
		{
			m_move = false;
			CObjEnemyMagicBattle* objemb = new CObjEnemyMagicBattle(m_px + m_directionx, m_py + m_directiony);
			Objs::InsertObj(objemb, OBJ_ENEMY_MAGIC_BATTLE, 100);
			m_delay = 2;
			Audio::Start(5);
		}
	}
	else
	{
		m_delay--;
	}

	/*CObjEnemyMagicBattle* objemb = new CObjEnemyMagicBattle(m_px + m_directionx, m_py + m_directiony);
	Objs::InsertObj(objemb, OBJ_ENEMY_MAGIC_BATTLE, 100);*/	

	//方向
	if (m_move == false)
	{
		m_vx += m_speed_power;
		m_posture = 1.0f;
		m_ani_time += 1;
	}
	else if (m_move == true)
	{
		m_vx -= m_speed_power;
		m_posture = 0.0f;
		m_ani_time += 1;
	}
	if (m_ani_time > m_ani_max_time)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}
	if (m_ani_frame == 4)
	{
		m_ani_frame = 0;
	}

	//摩擦
	m_vx += -(m_vx * 0.098);
	m_vy += -(m_vy * 0.098);

	//自身のHitBoxを持ってくる
	CHitBox* hit = Hits::GetHitBox(this);

	//自由落下運動
	m_vy += 9.8 / (16.0f);

	//位置の更新
	m_px += m_vx;
	m_py += m_vy;

	//HitBoxの位置の変更
	hit->SetPos(m_px, m_py);


	//攻撃を受けたら体力を減らす
	//主人公とATTACK系統との当たり判定
	if (hit->CheckElementHit(ELEMENT_ATTACK) == true)
	{
		//ノックバック処理
		if (m_posture == 1.0f)
		{
			m_vy = -10;
			m_vx -= 5;
		}
		else if (m_posture == 0.0f)
		{
			m_vy = -10;
			m_vx += 5;
		}
		m_time = 80;		//無敵時間をセット
		hit->SetInvincibility(true);	//無敵オン
		m_boss_hp -= 1;
	}
	if (m_time > 0)
	{
		m_time--;
		if (m_time <= 0)
		{
			m_time = 0;
			hit->SetInvincibility(false);	//無敵オフ
		}
	}
	//敵の体力が0になったら破棄
	if (m_boss_hp <= 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	//敵が領域外に行かないようにする
	if (m_px + 75 >= 800)
	{
		m_px = 800.0 - 75.0f;
		m_speed_power = 1.0f;
	}
	if (m_px < 0)
	{
		m_px = 0.0f;
		m_speed_power = 1.0f;
	}
	if (m_py + 100 >= 580)
	{
		m_py = 580.0 - 100.0f;
	}
	if (m_py <50)
	{
		m_py = 50.0f;
	}

	//突進
	/*if (m_time >= 0)
	{
		m_time++;

		if (m_time >= 80)
		{
			m_speed_power = 0.0f;

			if (m_time >= 120)
			{
				m_speed_power = 20.0f;
				m_time = 0;
			}
		}
	}*/
}

//ドロー
void CObjBoss3Battle::Draw()
{
	if (m_boss_flag == true)
	{
		return;
	}

	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float a[4] = { 1.0f,1.0f,1.0f,0.5f };

	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画先表示位置

	//切り取り位置の設定
	if (m_move == true)//左向き
	{
		src.m_top = 0.0f;
		src.m_left = 265.0f;
		src.m_right = 500.0f;
		src.m_bottom = 250.0f;
	}
	if (m_move == false)//右向き
	{
		m_posture = 0.0f;
		src.m_top = 0.0f;
		src.m_left = 770.0f;
		src.m_right = 1000.0f;
		src.m_bottom = 250.0f;
	}

	//表示位置の設定
	dst.m_top = 0.0f + m_py;
	dst.m_left = (75.0f * m_posture) + m_px;
	dst.m_right = (75 - 75.0f * m_posture) + m_px;
	dst.m_bottom = 100.0f + m_py;

	//描画
	if (m_time > 0) {
		Draw::Draw(22, &src, &dst, a, 0.0f);
	}
	else {
		Draw::Draw(22, &src, &dst, c, 0.0f);
	}
}