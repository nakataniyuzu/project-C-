//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\Audio.h"

#include "GameHead.h"
#include "ObjBoss2Battle.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjBoss2Battle::Init()
{
	m_px = 300.0f;
	m_py = 500.0f;		//出現位置

	m_vx = 0.0f;		//移動ベクトル
	m_vy = 0.0f;
	m_boss_hp = 35;     //敵のヒットポイント(最大35)

	m_damage = 3;

	m_ani_time = 0;
	m_ani_frame = 1;	//静止フレームを初期にする

	m_speed_power = 1.0f;	//通常速度
	m_ani_max_time = 4;		//アニメーション間隔幅


	m_eff.m_top = 0;
	m_eff.m_left = 15;
	m_eff.m_right = 100;
	m_eff.m_bottom = 100;

	m_ani = 0;
	m_ani_time_d = 0;
	m_del = false;
	m_eff_flag = false;
	m_ice_time = 0;

	m_pop_flag = true;
	m_move = true;  //true=右 false=左

	m_time = 0;
	m_time_f = 0;
	m_time_d = 0;

	//当たり判定用のHitBoxを作成
	Hits::SetHitBox(this, m_px, m_py, 75, 100, ELEMENT_BOSS_BATTLE, OBJ_BOSS_BATTLE_SECOND, 1);
}

//アクション
void CObjBoss2Battle::Action()
{
	//OBJ_MAINの情報を持ってくる
	CObjMain* main = (CObjMain*)Objs::GetObj(OBJ_MAIN);
	//主人公の情報を持ってくる
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	m_boss_flag = hero->GetBATTLE();
	hero_posture = hero->GetPOS();
	enemy_flag = hero->GetENEMYF();
	//戦闘時の主人公の情報を持ってくる
	CObjHeroBattle* herob = (CObjHeroBattle*)Objs::GetObj(OBJ_HERO_BATTLE);

	//摩擦
	m_vx += -(m_vx * 0.098f);
	m_vy += -(m_vy * 0.098f);

	//自身のHitBoxを持ってくる
	CHitBox* hit = Hits::GetHitBox(this);

	//自由落下運動
	m_vy += 9.8f / (16.0f);

	//位置の更新
	m_px += m_vx;
	m_py += m_vy;

	//HitBoxの位置の変更
	hit->SetPos(m_px, m_py);
	//主人公がマップ画面に移行した場合、元居る敵を削除
	if (boss_delete_flag == true)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		return;
	}
	//バトル時の主人公が死亡した場合、動きを止める
	if (herob->GetINPUTF() == false)
	{
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

	//マップへの移行
	if (g_battle_flag == false)
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
	if (m_px <= 0)
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

	//攻撃を受けたら体力を減らす
	//主人公とATTACK系統との当たり判定
	if (hit->CheckElementHit(ELEMENT_ATTACK) == true)
	{
		//主人公がブロックとどの角度で当たっているのかを確認
		HIT_DATA** hit_date;							//当たった時の細かな情報を入れるための構造体
		hit_date = hit->SearchElementHit(ELEMENT_ATTACK);	//hit_dateに主人公と当たっている他全てのHitBoxとの情報を入れる

		float r = 0;
		for (int i = 0; i < 10; i++) {
			if (hit_date[i] != nullptr) {
				r = hit_date[i]->r;
			}
		}
		//ノックバック処理
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
		m_boss_hp -= 1;
		m_time_d = 30;
	}
	if (hit->CheckObjNameHit(OBJ_ICE_BATTLE) != nullptr)	//魔法（アイス）を当たった場合
	{
		m_ice_time = 50;	//icetimeに時間をセット
	}
	if (m_ice_time > 0)
	{
		m_ice_time--;		//動きを制御
		m_speed_power = 0.0f;
		if (m_ice_time <= 0) {
			m_ice_time = 0;
			m_speed_power = 0.4f;
		}
	}
	if (m_time_d > 0)
	{
		m_time_d--;
		if (m_time_d <= 0)
		{
			m_time_d = 0;
		}
	}

	//敵の体力が0になったら消滅処理に移る
	if (m_del == false && m_boss_hp <= 0)
	{
		hero->SetFADEF(false);	//フェイドフラグをオフ
		g_hero_max_hp_mp += 3;	//敵の撃破時のHP/MP増加
		hero->SetMAXHP(3);		//HP/MPを増やす
		hero->SetMAXMP(3);
		g_xpup_flag = true;	//経験値増加フラグをオンにする
		m_del = true;
		g_boss_kills += 1;
		g_enemy_kills += 1;
		g_battle_key = false;
		m_time = 0;
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
	if (m_time >= 0)
	{
		m_time++;

		if (m_time >= 80)
		{
			m_speed_power = 0.0f;

			if (m_time >= 120)
			{
				m_speed_power = 20.0f;
				m_time = 0;
				Audio::Start(6);
			}
		}
	}

	if (m_time_f > 0) {
		m_time_f--;
		if (m_time_f <= 0) {

			CObjFadein* fade = new CObjFadein();	//フェイドインの作成
			Objs::InsertObj(fade, OBJ_FADEIN, 200);
			m_time_f = 0;
			m_time = 0;
			this->SetStatus(false);		//画像の削除
			Hits::DeleteHitBox(this);	//ヒットボックスの削除
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
			{ 0, 15,100,100 },
			{ 0,109,234,101 },
			{ 0,248,400,101 },
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
			m_time = 0;
		}
		return;
	}
}

//ドロー
void CObjBoss2Battle::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float a[4] = { 10.0f,0.6f,0.6f,1.0f };
	float b[4] = { 0.0f,0.0f,1.0f,1.0f };

	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画先表示位置

	//表示位置の設定
	dst.m_top    = 0.0f + m_py;
	dst.m_left   = (     75.0f * m_posture) + m_px;
	dst.m_right  = (75 - 75.0f * m_posture) + m_px;
	dst.m_bottom = 100.0f + m_py;

	//敵の状態で描画を変更
	if (m_del == true)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 248.0f;
		src.m_right = 400.0f;
		src.m_bottom = 101.0f;
		if (m_eff_flag == true)
			Draw::Draw(25, &src, &dst, c, 0.0f);
		else
			Draw::Draw(25, &m_eff, &dst, c, 0.0f);//死亡アニメーション描画
	}
	else
	{
		//切り取り位置の設定
		if (m_move == true)//左向き
		{
			src.m_top = 0.0f;
			src.m_left = 193.0f;
			src.m_right = 283.0f;
			src.m_bottom = 102.0f;
		}
		else if (m_move == false)//右向き
		{
			m_posture = 0.0f;
			src.m_top = 0.0f;
			src.m_left = 190.0f;
			src.m_right = 100.0f;
			src.m_bottom = 102.0f;
		}
		//描画
		if (m_time_d > 0) {
			Draw::Draw(14, &src, &dst, a, 0.0f);
		}
		else if (m_ice_time > 0) {
			Draw::Draw(14, &src, &dst, b, 0.0f);
		}
		else {
			Draw::Draw(14, &src, &dst, c, 0.0f);
		}
	}
}