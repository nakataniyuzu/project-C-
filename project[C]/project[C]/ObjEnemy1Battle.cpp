//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjEnemy1Battle.h"

//使用するネームスペース
using namespace GameL;



//イニシャライズ
void CObjEnemy1Battle::Init()
{
	m_px = 300.0f;
	m_py = 500.0f;		//出現位置
	m_vx = 0.0f;		//移動ベクトル
	m_vy = 0.0f;
	m_enemy_hp = 3;     //敵のヒットポイント(最大3)
	m_damage = 1;

	m_ani_time = 0;
	m_ani_frame = 1;	//静止フレームを初期にする

	m_speed_power = 0.5f;	//通常速度
	m_ani_max_time = 4;		//アニメーション間隔幅

	m_move = true;  //true=右 false=左
	enemy_delete_flag = false;	//敵消滅フラグ
	m_pop_flag = true;	//敵向き用フラグ

	m_block_type = 0;		//踏んでいるblockの種類を確認用

	m_eff.m_top    =  0;
	m_eff.m_left   =  0;
	m_eff.m_right  = 50;
	m_eff.m_bottom = 50;
	m_ani = 0;
	m_ani_time_d = 0;
	m_del = false;
	
	//当たり判定用のHitBoxを作成
	Hits::SetHitBox(this, m_px, m_py, 75, 100, ELEMENT_ENEMY_BATTLE, OBJ_ENEMY_BATTLE_FIRST, 1);
}

//アクション
void CObjEnemy1Battle::Action()
{
	//OBJ_MAINの情報を持ってくる
	CObjMain* main = (CObjMain*)Objs::GetObj(OBJ_MAIN);
	//主人公の情報を持ってくる
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	m_battle_flag = hero->GetBATTLE();
	hero_posture = hero->GetPOS();
	boss_flag = hero->GetBOSSF();

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

	if (enemy_delete_flag == true)
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
			m_px = 700.0f;
			m_py = 500.0f;		//出現位置
			m_move = true;	//向き
		}
		if (hero_posture == 2.0f || hero_posture == 3.0f)
		{
			m_px = 0.0f;
			m_py = 500.0f;		//出現位置
			m_move = false;	//向き
		}
		m_pop_flag = false;	//向き用フラグ
	}
	
	//マップへの移行
	if (m_battle_flag == true)
	{	
		m_vx = 0.0f;
		m_vy = 0.0f;
		m_pop_flag = true;
		return;
	}

	//画面端衝突で向き変更
	if (m_px + 75 >= 800)
	{
		m_move = true;
	}
	if (m_px  <= 0)
	{
		m_move = false;
	}

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

	


	

	//攻撃を受けたら体力を減らす
	//主人公とATTACK系統との当たり判定
	if (hit->CheckElementHit(ELEMENT_ATTACK) == true)
	{/*
		//主人公がブロックとどの角度で当たっているのかを確認
		HIT_DATA** hit_date;							//当たった時の細かな情報を入れるための構造体
		hit_date = hit->SearchElementHit(ELEMENT_ATTACK);	//hit_dateに主人公と当たっている他全てのHitBoxとの情報を入れる

		for (int i = 0; i < hit->GetCount(); i++)
		{
			float r = hit_date[i]->r;
			//角度で上下左右を判定
			if ((r < 45 && r >= 0) || r > 315)
			{
				m_vy = -10;
				m_vx -= 25;
			}
			if (r > 135 && r < 225)
			{
				m_vy = -10;
				m_vx += 25;
			}
			
		}*/
		//ノックバック処理
		if (m_posture == 1.0f)
		{
			m_vy = -10;
			m_vx -= 25;
		}
		else if (m_posture == 0.0f)
		{
			m_vy = -10;
			m_vx += 25;
		}

		m_enemy_hp -= 1;
	}

	
	//敵の体力が0になったら破棄CObjMain
	if (m_enemy_hp <= 0)
	{
		hero->SetFADEF(false);	//フェイドフラグをオフ
		CObjFadein* fade = new CObjFadein();	//フェイドインの作成
		Objs::InsertObj(fade, OBJ_FADEIN, 200);

		main->SetENEMYKILLS(1);
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	//敵が領域外に行かないようにする
	if (m_px + 75 >= 800)
	{
		m_px = 800.0 - 75.0f;
	}
	if (m_px < 0)
	{
		m_px = 0.0f;
	}
	if (m_py + 100 >= 580)
	{
		m_py = 580.0 - 100.0f;
	}
	if (m_py <50)
	{
		m_py = 50.0f;
	}

	//敵消滅処理------
	if (m_enemy_hp <= 0)
	{
		if (m_del == true)
		{
			//死亡アニメーションRECT情報
			RECT_F ani_src[3] =
			{
				{ 0,  0, 50, 50 },
				{ 0, 50,100, 50 },
				{ 0,100,150, 50 },
			};

			//アニメーションのコマ間隔制御
			if (m_ani_time_d > 2)
			{
				m_ani++;	//アニメーションのコマを1つ進める
				m_ani_time_d;

				m_eff = ani_src[m_ani];//アニメーションのRECT配列からm_ani番目のRECT情報取得
			}
			else
			{
				m_ani_time_d++;
			}

			//死亡アニメーション終了で本当にオブジェクトの破棄
			if (m_ani == 4)
			{
				this->SetStatus(false);
				Hits::DeleteHitBox(this);
			}

			return;
		}
	}

	//当たり判定を行うオブジェクト情報部
	int data_base[1] =
	{
		OBJ_SWORD_BATTLE,
	};

	//オブジェクト情報群と当たり判定行い。当たっていれば削除
	for (int i = 0; i < 1; i++)
	{
		if (hit->CheckObjNameHit(data_base[i]) != nullptr)
		{
			m_del = true;
			hit->SetInvincibility(true);
		}
	}
}

//ドロー
void CObjEnemy1Battle::Draw()
{
	//死亡アニメーションRECT情報
	RECT_F ani_src[3] =
	{
		{ 0,  0, 50, 50},
		{ 0, 50,100, 50},
		{ 0,100,150, 50},
	};


	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画先表示位置

	//表示位置の設定
	dst.m_top = 0.0f + m_py;
	dst.m_left = (75.0f * m_posture) + m_px;
	dst.m_right = (75 - 75.0f * m_posture) + m_px;
	dst.m_bottom = 100.0f + m_py;

	//敵の状態で描画を変更
	if (m_del == true)
	{
		//死亡アニメーション描画
		Draw::Draw(23, &m_eff, &dst, c, 0.0f);
	}
	else
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 50.0f;
		src.m_right = 0.0f;
		src.m_bottom = 50.0f;
		//描画
		Draw::Draw(12, &src, &dst, c, 0.0f);
	}
}