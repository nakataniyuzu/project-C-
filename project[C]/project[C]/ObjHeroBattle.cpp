//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\Audio.h"

#include "GameHead.h"
#include "ObjHeroBattle.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjHeroBattle::Init()
{
	m_px = 100.0f;
	m_py = 100.0f;
	m_battle_magic = 0;

	m_vx = 0.0f;		//移動ベクトル
	m_vy = 0.0f;
	m_posture = 0.0f;	//右向き0.0f 左向き1.0f

	m_ani_time = 0;
	m_ani_frame = 1;	//静止フレームを初期にする

	m_speed_power = 0.7f;	//通常速度
	m_ani_max_time = 4;		//アニメーション間隔幅

	m_sword_delay = 0;
	m_swordwidth = 0.0f; //ソード幅

	m_inputf = true;	// true = 入力可	false = 入力不可
	m_dtime = 0;
	m_dtime_f = false;
	m_time = 0;
	g_battle_key = true;	//true = 入力可

	//当たり判定用のHitBoxを作成
 	Hits::SetHitBox(this, m_px + 13 , m_py , 50, 90, ELEMENT_PLAYER, OBJ_HERO_BATTLE, 1);
}

//アクション
void CObjHeroBattle::Action()
{
	m_speed_power = 0.7f;	//通常速度

	//敵の情報を持ってくる
	CObjEnemy1Battle* benemy1 = (CObjEnemy1Battle*)Objs::GetObj(OBJ_ENEMY_BATTLE_FIRST);
	CObjEnemy2Battle* benemy2 = (CObjEnemy2Battle*)Objs::GetObj(OBJ_ENEMY_BATTLE_SECOND);
	CObjEnemy3Battle* benemy3 = (CObjEnemy3Battle*)Objs::GetObj(OBJ_ENEMY_BATTLE_THIRD);
	CObjBoss1Battle* bboss1 = (CObjBoss1Battle*)Objs::GetObj(OBJ_BOSS_BATTLE_FIRST);
	CObjBoss2Battle* bboss2 = (CObjBoss2Battle*)Objs::GetObj(OBJ_BOSS_BATTLE_SECOND);
	CObjBoss3Battle* bboss3 = (CObjBoss3Battle*)Objs::GetObj(OBJ_BOSS_BATTLE_THIRD);

	CObjEnemyMagicBattle* emb = (CObjEnemyMagicBattle*)Objs::GetObj(OBJ_ENEMY_MAGIC_BATTLE);

	CObjFadein* fade = (CObjFadein*)Objs::GetObj(OBJ_FADEIN);

	//主人公の情報を持ってくる
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	m_battle_hp = hero->GetHP();	//主人公からHPの情報を取得
	m_battle_mp = hero->GetMP();	//主人公からMPの情報を取得
	m_battle_magic = hero->GetMAGIC();	//主人公からMAGICの情報を取得

	hero_posture = hero->GetPOS();	//マップ上の主人公の向きを取得
	m_delete = hero->GetDELETE();

	m_fire_flag    = hero->GetFIREF();
	m_ice_flag     = hero->GetICEF();
	m_thunder_flag = hero->GetTHUNDERF();
	m_wind_flag    = hero->GetWINDF();

	//自身のHitBoxを持ってくる
	CHitBox* hit = Hits::GetHitBox(this);

	if (g_battle_flag == false)
	{
		if (hero_posture == 0.0f || hero_posture == 1.0f)
		{
			m_px = 100.0f;
			m_py = 500.0f;		//位置
			m_posture = 0.0f;
		}
		else if (hero_posture == 2.0f || hero_posture == 3.0f)
		{
			m_px = 700.0f;
			m_py = 500.0f;		//位置
			m_posture = 1.0f;
		}
		hit->SetInvincibility(true);	//無敵オン
		m_time = 50;		//バトルに入った際の無敵時間設定
		m_inputf = true;	//入力可能に戻す
		m_vx = 0.0f;	
		m_vy = 0.0f;
		return;
	}
	
	if (g_battle_key == true)
	{
		//inputフラグがオンの場合入力を可能にする
		if (m_inputf == true)
		{
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

		//上キーでジャンプ
		if (m_py + 100 >= 549)
		{
			if (Input::GetVKey(VK_UP) == true)
			{
				if (1)
				{
					m_vy = -40;
				}
			}
		}

		//Zキーで近接(剣)攻撃
		if (Input::GetVKey('Z') == true)
		{
			if (m_sword_delay == 0)
			{
				//主人公の向きによって攻撃する向きを設定
				if (m_posture == 0.0f) {
					m_swordwidth = 70.0f;
				}
				else if (m_posture == 1.0f) {
					m_swordwidth = -30.0f;
				}

				//剣で攻撃
				CObjSwordBattle* objsb = new CObjSwordBattle(m_px + m_swordwidth, m_py + 32.0f);//剣オブジェクト(戦闘)作成
				Objs::InsertObj(objsb, OBJ_SWORD_BATTLE, 100);		//作った剣オブジェクトをオブジェクトマネージャーに登録

				//斬撃音
				Audio::Start(0);

				m_sword_delay = 20;
			}
		}
		if (m_sword_delay > 0)
		{
			m_sword_delay--;
			if (m_sword_delay <= 0)
				m_sword_delay = 0;
		}
		//下キーで魔法を切り替える
		if (Input::GetVKey(VK_DOWN) == true)
		{
			if (m_mf == true) {	//キー制御用
				m_mf = false;
				m_battle_magic += 1;
			}
		}
		else
		{
			m_mf = true;
		}
		if (m_battle_magic == 1 && m_ice_flag == false) {	//氷魔法を取得しないと発動させない
			m_battle_magic = 0;
		}
		if (m_battle_magic == 2) {
			m_battle_magic = 0;
		}


		if (m_battle_mp > 0) {
			if (Input::GetVKey('X') == true)	//魔法発射
			{
				if (m_f == true) {	//魔法制御用

					//主人公の向きによって発射する向きを設定
					if (m_posture == 0.0f) {
						m_directionx = 50.0f;
						m_directiony = 0.0f;
					}
					else if (m_posture == 1.0f) {
						m_directionx = -50.0f;
						m_directiony = 0.0f;
					}

					if (m_battle_magic == 0)	//火の魔法
					{
						CObjFireBattle* objfb = new CObjFireBattle(m_px + m_directionx, m_py + m_directiony);//Fireオブジェクト(戦闘)作成
						Objs::InsertObj(objfb, OBJ_FIRE_BATTLE, 100);		//作ったIceオブジェクトをオブジェクトマネージャーに登録
						Audio::Start(7);
					}
					if (m_battle_magic == 1)	//氷の魔法
					{
						CObjIceBattle* objib = new CObjIceBattle(m_px + m_directionx, m_py + m_directiony);//Iceオブジェクト(戦闘)作成
						Objs::InsertObj(objib, OBJ_ICE_BATTLE, 100);		//作ったIceオブジェクトをオブジェクトマネージャーに登録
						Audio::Start(8);
					}
					m_f = false;
					m_battle_mp -= 1;		//MPを減らす
				}
			}
			else
			{
				m_f = true;
			}
		}
	}

	//摩擦
	m_vx += -(m_vx * 0.098f);
	m_vy += -(m_vy * 0.098f);

	//自由落下運動
	m_vy += 15.8f / (16.0f);

	//位置の更新
	m_px += m_vx;
	m_py += m_vy;

	//HitBoxの位置の変更
	hit->SetPos(m_px + 13, m_py);

	//当たり判定を行うオブジェクト情報群
	int data_base[3] =
	{
		ELEMENT_ENEMY_BATTLE,
		ELEMENT_BOSS_BATTLE,
		ELEMENT_MAGIC_BATTLE,
	};
	//オブジェクト情報群と当たり判定行い。当たっていればノックバック
	for (int i = 0; i < 6; i++)
	{
		if (hit->CheckElementHit(data_base[i]) == true)
		{
			HIT_DATA** hit_date;							//当たった時の細かな情報を入れるための構造体
			hit_date = hit->SearchElementHit(data_base[i]);	//hit_dateに主人公と当たっている他全てのHitBoxとの情報を入れる

			float r = 0;
			for (int i = 0; i < 10; i++) {
				if (hit_date[i] != nullptr) {
					r = hit_date[i]->r;
				}
			}
			//角度で上下左右を判定
			//if (r > 135 && r < 225 || r < 135)
			if (r > 90 && r < 270)
			{
				m_vy = -10;		//右
				m_vx += 25;
			}
			//if ((r < 45 && r >= 0) || r > 315 || (r > 45 || r < 90 ))
			else
			{
				m_vy = -10;		//左
				m_vx -= 25;
			}
			m_time = 80;		//無敵時間をセット
			hit->SetInvincibility(true);	//無敵オン

			Audio::Start(3);

			//敵(1層目)
			if (hit->CheckObjNameHit(OBJ_ENEMY_BATTLE_FIRST) != nullptr)
			{
				CObjEnemy1Battle* e1b = (CObjEnemy1Battle*)Objs::GetObj(OBJ_ENEMY_BATTLE_FIRST);
				m_damage = e1b->GetDMG();
				m_battle_hp -= m_damage;
				Audio::Start(3);
			}
			//敵(2層目)
			if (hit->CheckObjNameHit(OBJ_ENEMY_BATTLE_SECOND) != nullptr)
			{
				CObjEnemy2Battle* e2b = (CObjEnemy2Battle*)Objs::GetObj(OBJ_ENEMY_BATTLE_SECOND);
				m_damage = e2b->GetDMG();
				m_battle_hp -= m_damage;
				Audio::Start(3);
			}
			//敵(3層目)
			if (hit->CheckObjNameHit(OBJ_ENEMY_BATTLE_THIRD) != nullptr)
			{
				CObjEnemy3Battle* e3b = (CObjEnemy3Battle*)Objs::GetObj(OBJ_ENEMY_BATTLE_THIRD);
				m_damage = e3b->GetDMG();
				m_battle_hp -= m_damage;
				Audio::Start(3);
			}
			//ボス(1層目)
			if (hit->CheckObjNameHit(OBJ_BOSS_BATTLE_FIRST) != nullptr)
			{
				CObjBoss1Battle* bs1b = (CObjBoss1Battle*)Objs::GetObj(OBJ_BOSS_BATTLE_FIRST);
				m_damage = bs1b->GetDMG();
				m_battle_hp -= m_damage;
				Audio::Start(3);
			}
			//ボス(2層目)
			if (hit->CheckObjNameHit(OBJ_BOSS_BATTLE_SECOND) != nullptr)
			{
				CObjBoss2Battle* bs2b = (CObjBoss2Battle*)Objs::GetObj(OBJ_BOSS_BATTLE_SECOND);
				m_damage = bs2b->GetDMG();
				m_battle_hp -= m_damage;
				Audio::Start(3);
			}
			//ボス(3層目)
			if (hit->CheckObjNameHit(OBJ_BOSS_BATTLE_THIRD) != nullptr)
			{
				CObjBoss3Battle* bs3b = (CObjBoss3Battle*)Objs::GetObj(OBJ_BOSS_BATTLE_THIRD);
				m_damage = bs3b->GetDMG();
				m_battle_hp -= m_damage;
				Audio::Start(3);
			}
			//ボス魔法(3層目)
			if (hit->CheckObjNameHit(OBJ_ENEMY_MAGIC_BATTLE) != nullptr)
			{
				CObjEnemyMagicBattle* emb = (CObjEnemyMagicBattle*)Objs::GetObj(OBJ_ENEMY_MAGIC_BATTLE);
				m_damage = emb->GetDMG();
				m_battle_hp -= m_damage;
				Audio::Start(3);
			}
			//敵の攻撃によってHPが0以下になった場合
			if(m_battle_hp <= 0)
				m_battle_hp = 0;	//HPを0にする
		}
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

	//主人公の体力が0になったらゲームオーバーシーンに移行
	if (m_battle_hp <= 0 && m_inputf == true)
	{
		m_dtime = 70;		//タイムをセット
		m_inputf = false;	//キー入力を制御
		hit->SetInvincibility(true);	//無敵オン
	}
	if (m_dtime > 0)	//m_dtimeに数値が入った場合
	{
		m_dtime--;	//数値を減らす
		if (m_dtime <= 0)
		{
			m_dtime_f = true;	//死亡用フラグをオン
			m_dtime = 0;
		}
	}
	if (m_dtime_f == true) {
		hero->SetDEATHF(true);	//フェイドのデスフラグをオンにして、ゲームオーバーへ移行するようにする
		CObjFadein* fade = new CObjFadein();	//フェイドインの作成
		Objs::InsertObj(fade, OBJ_FADEIN, 200);
	}

	//敵から逃げれないフラグ
	if (g_escape == true)	//オンの場合逃げられる
	{
		//主人公が逃げられるようにする
		if (m_px + 75 >= 800)
		{
			m_px = 800.0 - 75.0f;
			if (hero_posture == 0.0f || hero_posture == 1.0f) {
				m_inputf = false;		//キー入力を不可にする
				hero->SetFADEF(false);	//フェイドフラグをオフ
				CObjFadein* fade = new CObjFadein();	//フェイドインの作成
				Objs::InsertObj(fade, OBJ_FADEIN, 200);
				Audio::Stop(13);		//バトル用BGMを止める
				if (m_delete == true) {
					if (g_map_change == 0) {
						if (benemy1 != nullptr) {
							benemy1->SetENEMYDELETE(true);
						}
					}
					else if (g_map_change == 1) {
						if (benemy2 != nullptr) {
							benemy2->SetENEMYDELETE(true);
						}
					}
					else if (g_map_change == 2) {
						if (benemy3 != nullptr) {
							benemy3->SetENEMYDELETE(true);
						}
					}
				}
			}
		}
		if (m_px < 0)
		{
			m_px = 0.0f;
			if (hero_posture == 2.0f || hero_posture == 3.0f) {
				m_inputf = false;		//キー入力を不可にする
				hero->SetFADEF(false);	//フェイドフラグをオフ
				CObjFadein* fade = new CObjFadein();	//フェイドインの作成
				Objs::InsertObj(fade, OBJ_FADEIN, 200);
				Audio::Stop(13);		//バトル用BGMを止める
				if (m_delete == true) {
					if (g_map_change == 0) {
						if (benemy1 != nullptr) {
							benemy1->SetENEMYDELETE(true);
						}
					}
					else if (g_map_change == 1) {
						if (benemy2 != nullptr) {
							benemy2->SetENEMYDELETE(true);
						}
					}
					else if (g_map_change == 2) {
						if (benemy3 != nullptr) {
							benemy3->SetENEMYDELETE(true);
						}
					}
				}
			}
		}
	}

	//領域外に行かない処理
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
		m_py = 580.0f - 100.0f;
	}
	if (m_py < 50)
	{
		m_py = 50.0f;
	}
	

	hero->SetHP(m_battle_hp);
	hero->SetMP(m_battle_mp);
	hero->SetMAGIC(m_battle_magic);
}

//ドロー
void CObjHeroBattle::Draw()
{
	if (g_battle_flag == false)
	{
		return;
	}

	int AniData[4] =
	{
		0,1,0,2,
	};

	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float a[4] = { 1.0f,1.0f,1.0f,0.5f };
	float r[4] = { 1.0f,0.5f,0.5f,0.5f };

	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画先表示位置

	//切り取り位置の設定
	src.m_top    = 192.0f;
	src.m_left   = 64.0f + AniData[m_ani_frame] * 64.0f;
	src.m_right  =  0.0f + AniData[m_ani_frame] * 64.0f;
	src.m_bottom = 256.0f;

	//表示位置の設定
	dst.m_top    = 0.0f + m_py;
	dst.m_left   = (     75.0f * m_posture) + m_px;
	dst.m_right  = (75 - 75.0f * m_posture) + m_px;
	dst.m_bottom = 100.0f + m_py;

	//描画カラーの設定
	if (m_dtime > 0) {	//死亡時間の場合
		Draw::Draw(0, &src, &dst, r, 0.0f);
	}
	if (m_time > 0){		//無敵時間の場合
		Draw::Draw(0, &src, &dst, a, 0.0f);
	}
	else {	//通常時
		Draw::Draw(0, &src, &dst, c, 0.0f);
	}

}