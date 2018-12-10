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

	//当たり判定用のHitBoxを作成
 	Hits::SetHitBox(this, m_px , m_py , 60, 100, ELEMENT_PLAYER, OBJ_HERO_BATTLE, 1);
}

//アクション
void CObjHeroBattle::Action()
{
	//敵の情報を持ってくる
	CObjEnemy1Battle* benemy1 = (CObjEnemy1Battle*)Objs::GetObj(OBJ_ENEMY_BATTLE_FIRST);
	CObjEnemy2Battle* benemy2 = (CObjEnemy2Battle*)Objs::GetObj(OBJ_ENEMY_BATTLE_SECOND);
	CObjBoss1Battle* bboss1 = (CObjBoss1Battle*)Objs::GetObj(OBJ_BOSS_BATTLE_FIRST);

	//主人公の情報を持ってくる
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	m_battle_hp = hero->GetHP();	//主人公からHPの情報を取得
	m_battle_mp = hero->GetMP();	//主人公からMPの情報を取得
	m_battle_magic = hero->GetMAGIC();	//主人公からMAGICの情報を取得

	m_battle_flag = hero->GetBATTLE();
	m_boss_battle_f = hero->GetBOSSBATTLE();
	hero_posture = hero->GetPOS();	//マップ上の主人公の向きを取得
	m_delete = hero->GetDELETE();

	m_fire_flag    = hero->GetFIREF();
	m_ice_flag     = hero->GetICEF();
	m_thunder_flag = hero->GetTHUNDERF();
	m_wind_flag    = hero->GetWINDF();


	if (m_battle_flag == true)
	{
		if (hero_posture == 0.0f || hero_posture == 1.0f)
		{
			m_px = 100.0f;
			m_py = 500.0f;		//位置
			m_posture = 0.0f;
		}
		else if (hero_posture == 2.0f || hero_posture == 3.0f)
		{
			m_px = 600.0f;
			m_py = 500.0f;		//位置
			m_posture = 1.0f;
		}

		m_vx = 0.0f;
		m_vy = 0.0f;
		return;
	}

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

	//Eキーでメニューを開く
	if (Input::GetVKey('E') == true)
	{
		//Scene::SetScene(new CSceneMenu());
		
	}

	//Aキーで近接(剣)攻撃
	if (Input::GetVKey('A') == true)
	{
		if (m_sword_delay == 0)
		{
			//主人公の向きによって攻撃する向きを設定
			if (m_posture == 0.0f) {
				m_swordwidth = 55.0f;
			}
			else if (m_posture == 1.0f) {
				m_swordwidth = -55.0f;
			}

			//剣で攻撃
			CObjSwordBattle* objsb = new CObjSwordBattle(m_px + m_swordwidth, m_py + 32.0f);//剣オブジェクト(戦闘)作成
			Objs::InsertObj(objsb, OBJ_SWORD_BATTLE, 100);		//作った剣オブジェクトをオブジェクトマネージャーに登録
			
			m_sword_delay = 10;
		}	
	}
	if (m_sword_delay > 0)
	{
		m_sword_delay--;
		if (m_sword_delay <= 0)
			m_sword_delay = 0;
	}
	//Xキーで魔法を切り替える
	if (Input::GetVKey('X') == true)
	{
		if (m_mf == true) {	//キー制御用
			m_mf = false;
			m_battle_magic += 2;
		}
		if (m_battle_magic == 1 && m_ice_flag == false) {	//氷魔法を取得しないと発動させない
			m_battle_magic = 0;
		}
		if (m_battle_magic == 2 && m_wind_flag == false) {	//風魔法を取得しないと発動させない
			m_battle_magic = 0;
		}
		if (m_battle_magic == 3 && m_thunder_flag == false) {//雷魔法を取得しないと発動させない
			m_battle_magic = 0;
		}
		if (m_battle_magic >= 4) {
			m_battle_magic = 0;
		}
	}
	else
	{
		m_mf = true;
	}
	if (m_battle_mp > 0) {
		if (Input::GetVKey('Z') == true)	//魔法発射
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
					CObjFireBattle* objfb = new CObjFireBattle(m_px + m_directionx, m_py + m_directiony);//Iceオブジェクト(戦闘)作成
					Objs::InsertObj(objfb, OBJ_FIRE_BATTLE, 100);		//作ったIceオブジェクトをオブジェクトマネージャーに登録
				}
				if (m_battle_magic == 1)	//氷の魔法
				{
					CObjIceBattle* objib = new CObjIceBattle(m_px + m_directionx, m_py + m_directiony);//Iceオブジェクト(戦闘)作成
					Objs::InsertObj(objib, OBJ_ICE_BATTLE, 100);		//作ったIceオブジェクトをオブジェクトマネージャーに登録
				}
				else if (m_battle_magic == 3)	//雷の魔法
				{
					CObjThunderBattle* objtb = new CObjThunderBattle(m_px + m_directionx, m_py + m_directiony);//Thunderオブジェクト(戦闘)作成
					Objs::InsertObj(objtb, OBJ_THUNDER_BATTLE, 100);		//作ったThunderオブジェクトをオブジェクトマネージャーに登録
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

	//攻撃を受けたら体力を減らす
	if (hit->CheckElementHit(ELEMENT_ENEMY_BATTLE) == true
		|| hit->CheckElementHit(ELEMENT_BOSS_BATTLE) == true)
	{
		//ノックバック処理
		if (m_posture == 0.0f)
		{
			m_vy = -15;
			m_vx -= 20;
		}
		else if (m_posture == 1.0f)
		{
			m_vy = -15;
			m_vx += 20;
		}
		m_time = 80;		//無敵時間をセット
		hit->SetInvincibility(true);	//無敵オン

		//敵(1層目)
		if (hit->CheckObjNameHit(OBJ_ENEMY_BATTLE_FIRST) != nullptr)
		{
			CObjEnemy1Battle* e1b = (CObjEnemy1Battle*)Objs::GetObj(OBJ_ENEMY_BATTLE_FIRST);
			m_damage = e1b ->GetDMG();
			m_battle_hp -= m_damage;
		}
		//敵(2層目)
		if (hit->CheckObjNameHit(OBJ_ENEMY_BATTLE_SECOND) != nullptr)
		{
			CObjEnemy2Battle* e2b = (CObjEnemy2Battle*)Objs::GetObj(OBJ_ENEMY_BATTLE_SECOND);
			m_damage = e2b ->GetDMG();
			m_battle_hp -= m_damage;
		}
		//ボス(1層目)
		if (hit->CheckObjNameHit(OBJ_BOSS_BATTLE_FIRST) != nullptr)
		{
			CObjBoss1Battle* bs1b = (CObjBoss1Battle*)Objs::GetObj(OBJ_BOSS_BATTLE_FIRST);
			m_damage = bs1b ->GetDMG();
			m_battle_hp -= m_damage;
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
	if (m_battle_hp <= 0)
	{
		Scene::SetScene(new CSceneGameover());
	}

	//主人公が領域外に行かないようにする
	if (m_px + 75 >= 800)
	{
		m_px = 800.0 - 75.0f;
		if (hero_posture == 0.0f || hero_posture == 1.0f) {

			hero->SetFADEF(false);	//フェイドフラグをオフ
			CObjFadein* fade = new CObjFadein();	//フェイドインの作成
			Objs::InsertObj(fade, OBJ_FADEIN, 200);

			if (m_delete == true){
				if (benemy1 != nullptr) {
					benemy1->SetENEMYDELETE(true);
				}
			}
			else {
				if (benemy1 != nullptr) {
					bboss1->SetBOSSDELETE(true);
				}
			}

		}
	}
	if (m_px < 0)
	{
		m_px = 0.0f;
		if (hero_posture == 2.0f || hero_posture == 3.0f) {

			hero->SetFADEF(false);	//フェイドフラグをオフ
			CObjFadein* fade = new CObjFadein();	//フェイドインの作成
			Objs::InsertObj(fade, OBJ_FADEIN, 200);

			if (m_delete == true) {
				if (benemy1 != nullptr) {
					benemy1->SetENEMYDELETE(true);
				}
			}
			else {
				if (benemy1 != nullptr) {
					bboss1->SetBOSSDELETE(true);
				}
			}
		}
	}
	if (m_py + 100 >= 580)
	{
		m_py = 580.0f - 100.0f;
	}
	if (m_py <50)
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
	if (m_battle_flag == true)
	{
		return;
	}

	int AniData[4] =
	{
		0,1,2,3,
	};

	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float a[4] = { 1.0f,1.0f,1.0f,0.5f };

	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画先表示位置

	//切り取り位置の設定
	src.m_top    =  0.0f;
	src.m_left   = 60.0f + AniData[m_ani_frame] *60;
	src.m_right  =  0.0f + AniData[m_ani_frame] *60;
	src.m_bottom = 60.0f;

	//表示位置の設定
	dst.m_top    = 0.0f + m_py;
	dst.m_left   = (     75.0f * m_posture) + m_px;
	dst.m_right  = (75 - 75.0f * m_posture) + m_px;
	dst.m_bottom = 100.0f + m_py;

	//描画
	if (m_time > 0){
		Draw::Draw(11, &src, &dst, a, 0.0f);
	}
	else {
		Draw::Draw(11, &src, &dst, c, 0.0f);
	}

}