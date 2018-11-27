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

	//炎か風の魔法で戦闘に入らないようにするための処理
	if (m_battle_magic == 0 || m_battle_magic == 2)
	{
		m_battle_magic = 1;
	}
	
	m_px = 100.0f;
	m_py = 450.0f;		//位置
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

	//Eキーでメニューを開く
	if (Input::GetVKey('E') == true)
	{
		Scene::SetScene(new CSceneMenu());
	}

	//Aキーで近接(剣)攻撃
	if (Input::GetVKey('A') == true)
	{
		if (m_sword_delay == 0)
		{
			//主人公の向きによって攻撃する向きを設定
			if (m_posture == 0.0f) {
				m_directionx = 7.0f;
				m_directiony = 0.0f;
				m_swordwidth = 50.0f;
			}
			else if (m_posture == 1.0f) {
				m_directionx = -7.0f;
				m_directiony = 0.0f;
				m_swordwidth = -30.0f;
			}

			//剣で攻撃
			CObjSwordBattle* objsb = new CObjSwordBattle(m_px + m_directionx+ m_swordwidth, m_py + m_directiony+35.0f);//剣オブジェクト(戦闘)作成
			Objs::InsertObj(objsb, OBJ_SWORD_BATTLE, 100);		//作った剣オブジェクトをオブジェクトマネージャーに登録
			
			m_sword_delay = 10;
		}
		else if (m_sword_delay > 0)
		{
			m_sword_delay--;
			if (m_sword_delay <= 0)
				m_sword_delay = 0;
		}
	}


	//Xキーで魔法を切り替える
	if (Input::GetVKey('X') == true)
	{
		if (m_mf == true) {	//キー制御用
			m_mf = false;
			m_battle_magic += 2;
		}
		if (m_battle_magic >= 4) {
			m_battle_magic = 1;
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

	//敵と当たっているか確認
	if (hit->CheckObjNameHit(OBJ_ENEMY_BATTLE) != nullptr)
	{
		//主人公が敵とどの角度で当たっているかを確認
		HIT_DATA** hit_data;	//当たった時の細かな情報を入れるための構造体
		hit_data = hit->SearchObjNameHit(OBJ_ENEMY_BATTLE);//hit_dataに主人公と当たっている他全てのHitBoxとの情報を入れる

		for (int i = 0; i < hit->GetCount(); i++)
		{
			//敵の左右に当たったら
			//保留↓
			/*if ()
			{*/

			float r = hit_data[i]->r;

				if ((r < 45 && r >= 0) || r > 315)
				{
					m_vx = -5.0f;//左に移動させる
				}
				if (r > 135 && r < 225)
				{
					m_vx = +5.0f;//右に移動させる
				}
				if (r > 225 && r < 315)
				{
					//敵の移動方向を主人公の位置に加算
					/*m_px += ((CObjEnemy*)hit_data[i]->o)->GetVx();

					CObjBlock* b = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);*/

					//頭に乗せる処理
					if (m_vy < -1.0f)
					{
						//ジャンプしてる場合は下記の影響を出ないようにする
					}
					else
					{
						//主人公が敵の頭に乗っているので、Yvecは0にして落下させない
						//また、地面に当たっている判定にする
						m_vy = 0.0f;
						m_hit_down = true;
					}
				}
			//}
		}
	}

	//位置の更新
	m_px += m_vx;
	m_py += m_vy;

	//HitBoxの位置の変更
	hit->SetPos(m_px, m_py);

	//攻撃を受けたら体力を減らす
	if (hit->CheckObjNameHit(OBJ_ENEMY_BATTLE) != nullptr)
	{
		//ノックバック処理
		if (m_posture == 0.0f)
		{
			m_vy = -15;
			m_vx -= 10;
		}
		else if (m_posture == 1.0f)
		{
			m_vy = -15;
			m_vx += 10;
		}
		m_battle_hp -= 1;
		m_time = 60;		//無敵時間をセット
		hit->SetInvincibility(true);	//無敵オン
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