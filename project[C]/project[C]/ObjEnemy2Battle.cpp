//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjEnemy2Battle.h"

//使用するネームスペース
using namespace GameL;



//イニシャライズ
void CObjEnemy2Battle::Init()
{
	m_px = 600.0f;//位置
	m_py = 450.0f;
	m_vx = 0.0f;		//移動ベクトル
	m_vy = 0.0f;
	m_posture = 1.0f;	//右向き0.0f 左向き1.0f
	m_enemy_hp = 10;     //敵のヒットポイント(最大10)
	m_damage = 2;

	m_ani_time = 0;
	m_ani_frame = 1;	//静止フレームを初期にする

	m_speed_power = 0.5f;	//通常速度
	m_ani_max_time = 4;		//アニメーション間隔幅

	m_move = true;  //true=右 false=左

	m_subtract = 0;		//HEROとの距離
	m_hero_position = 0;//HEROの位置

	m_block_type = 0;		//踏んでいるblockの種類を確認用

	m_time_f = 0;
	m_ani = 0;
	m_ani_time_d = 0;
	m_del = false;
	m_eff_flag = false;
	//当たり判定用のHitBoxを作成
	Hits::SetHitBox(this, m_px, m_py, 75, 100, ELEMENT_ENEMY_BATTLE, OBJ_ENEMY_BATTLE_SECOND, 1);
}

//アクション
void CObjEnemy2Battle::Action()
{
	//OBJ_MAINの情報を持ってくる
	CObjMain* main = (CObjMain*)Objs::GetObj(OBJ_MAIN);
	//主人公の情報を持ってくる
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	m_battle_flag = hero->GetBATTLE();
	m_hero_posture = hero->GetPOS();
	m_boss_flag = hero->GetBOSSF();
	//戦闘時の主人公の情報を持ってくる
	CObjHeroBattle* herob = (CObjHeroBattle*)Objs::GetObj(OBJ_HERO_BATTLE);
	m_hero_position = herob->GetX();

	if (g_battle_flag == false)
	{
		if (m_hero_posture == 0.0f || m_hero_posture == 1.0f)
		{
			m_px = 600.0f;
			m_py = 500.0f;		//出現位置
		}
		else if (m_hero_posture == 2.0f || m_hero_posture == 3.0f)
		{
			m_px = 100.0f;
			m_py = 500.0f;		//出現位置
		}
		m_vx = 0.0f;
		m_vy = 0.0f;
		return;
	}

	//主人公との位置関係
	m_subtract = m_hero_position - m_px;
	if (m_subtract < 0)
	{

		m_move = true;
	}
	else 
	{
		m_move = false;
	}

	/*/画面端衝突で向き変更
	if (m_px + 75 >= 800)
	{
		m_move = true;
	}
	if (m_px <= 0)
	{
		m_move = false;
	}*/

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
			m_vy = -3;
			m_vx -= 10;
		}
		else if (m_posture == 0.0f)
		{
			m_vy = -3;
			m_vx += 10;
		}

		m_enemy_hp -= 1;
	}


	//敵の体力が0になったら消滅処理に移る
	if (m_del == false && m_enemy_hp <= 0)
	{
		hero->SetFADEF(false);	//フェイドフラグをオフ		
		m_del = true;
		main->SetENEMYKILLS(1);
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

	if (m_time_f > 0) {
		m_time_f--;
		if (m_time_f <= 0) {
			CObjFadein* fade = new CObjFadein();	//フェイドインの作成
			Objs::InsertObj(fade, OBJ_FADEIN, 200);
			this->SetStatus(false);		//画像の削除
			Hits::DeleteHitBox(this);	//ヒットボックスの削除
			m_time_f = 0;
		}
	}

	//敵消滅処理------		
	if (m_del == true)
	{
		herob->SetSPEED(0.0f);	//主人公のスピードを０にする
		herob->SetVX(0.0f);		//主人公のベクトルを０にする
		herob->SetVY(0.0f);
		//死亡アニメーションRECT情報
		RECT_F ani_src[3] =
		{
			{ 0,  0, 90,100 },
			{ 0,105,200,100 },
			{ 0,210,318,100 },
		};

		//アニメーションのコマ間隔制御
		if (m_ani_time_d > 5)
		{
			m_ani++;	//アニメーションのコマを1つ進める
			m_ani_time_d = 0;

			m_eff = ani_src[m_ani];//アニメーションのRECT配列からm_ani番目のRECT情報取得
		}
		else
		{
			m_ani_time_d++;
		}

		//死亡アニメーション終了で本当にオブジェクトの破棄
		if (m_ani == 3)
		{
			hit->SetInvincibility(true);	//無敵にする
			m_speed_power = 0.0f;			//動きを止める
			m_eff_flag = true;			//画像切り替え用フラグ
			m_time_f = 20;		//フェイドイン移行用の間隔設定
		}
		return;
	}
}

//ドロー
void CObjEnemy2Battle::Draw()
{
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
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 210.0f;
		src.m_right = 318.0f;
		src.m_bottom = 100.0f;
		if (m_eff_flag == true)
			Draw::Draw(26, &src, &dst, c, 0.0f);
		else
			Draw::Draw(26, &m_eff, &dst, c, 0.0f);//死亡アニメーション描画
	}
	else
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 400.0f;
		src.m_right = 300.0f;
		src.m_bottom = 100.0f;

		//描画
		Draw::Draw(19, &src, &dst, c, 0.0f);
	}
}