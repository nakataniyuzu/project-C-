//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "ObjHero.h"
#include "ObjBlock.h"

float g_px = 375.0f;
float g_py = 300.0f;

//使用するネームスペース
using namespace GameL;



//イニシャライズ
void CObjHero::Init()
{
	m_vx = 0.0f;		//移動ベクトル
	m_vy = 0.0f;

	m_speed_power = 0.2f;	//通常速度
	m_posture = 2.0f;
	
	m_max_hp = 10;
	m_max_mp = 5;
	m_hp = 10;	//初期HP
	m_mp = 5;	//初期MP
	m_magic = 0;	//初期魔法
	m_key = 0;

	//フラグの初期化
	m_gate_mf = false;
	m_water_mf = false;
	m_key_mf = false;
	m_ice_mf = false;

	m_battle_flag = true;

	m_ani_time = 0;
	m_ani_frame = 0;	//静止フレームを初期にする
	m_ani_max_time = 8;		//アニメーション間隔幅(増やせば遅い

	m_fire_flag = true;		//火：0
	m_ice_flag = false;		//氷：1
	m_wind_flag = false;	//風：2
	m_thunder_flag = false;	//雷：3

	//blockとの衝突状態確認
	m_hit_up    = false;
	m_hit_down  = false;
	m_hit_left  = false;
	m_hit_right = false;

	m_block_type = 0;		//踏んでいるblockの種類を確認用

	//当たり判定用のHitBoxを作成
	Hits::SetHitBox(this, g_px, g_py, ALL_SIZE, ALL_SIZE, ELEMENT_PLAYER, OBJ_HERO, 1);

}

//アクション
void CObjHero::Action()
{
	if (m_battle_flag == false)
	{
		m_vx = 0.0f;
		m_vy = 0.0f;
		return;
	}
	
	//Eキーでメニューを開く
	if (Input::GetVKey('E') == true)
	{
		//Scene::SetScene(new CSceneMenu());
		m_battle_flag = false;
	}

	//Xキーで魔法を切り替える
	if (Input::GetVKey('X') == true)
	{
		if (m_mf == true) {	//キー制御用
			m_mf = false;
			m_magic += 1;
		}
		if (m_magic == 1 && m_ice_flag == false) {	//氷魔法を取得しないと発動させない
			m_magic = 0;
		}
		if (m_magic == 2 && m_wind_flag == false) {	//風魔法を取得しないと発動させない
			m_magic = 0;
		}
		if (m_magic == 3 && m_thunder_flag == false) {//雷魔法を取得しないと発動させない
			m_magic = 0;
		}
		if (m_magic >= 4) {
			m_magic = 0;
		}
	}
	else
	{
		m_mf = true;
	}

	//HPが0以下の時にゲームオーバーにする
	if (m_hp <= 0)
	{
		Scene::SetScene(new CSceneGameover());
	}

	//MPが0以上の時は魔法を放つ
	if (m_mp > 0) {
		if (Input::GetVKey('Z') == true)	//魔法発射
		{
			if (m_f == true) {	//魔法制御用

				//主人公の向きによって発射する向きを設定
				if (m_posture == 0.0f) {
					m_directionx = 0.0f;
					m_directiony = -50.0f;
				}
				else if (m_posture == 1.0f) {
					m_directionx = 50.0f;
					m_directiony = 0.0f;
				}
				else if (m_posture == 2.0f) {
					m_directionx = 0.0f;
					m_directiony = 50.0f;
				}
				else if (m_posture == 3.0f) {
					m_directionx = -50.0f;
					m_directiony = 0.0f;
				}

				if (m_magic == 0)	//火の魔法
				{
					CObjFire* objf = new CObjFire(g_px + m_directionx, g_py + m_directiony);//Fireオブジェクト作成
					Objs::InsertObj(objf, OBJ_FIRE, 120);		//作ったFireオブジェクトをオブジェクトマネージャーに登録
				}
				else if (m_magic == 1)	//氷の魔法
				{
					CObjIce* obji = new CObjIce(g_px + m_directionx, g_py + m_directiony);//Iceオブジェクト作成
					Objs::InsertObj(obji, OBJ_ICE, 120);		//作ったIceオブジェクトをオブジェクトマネージャーに登録
				}
				else if (m_magic == 2)	//風の魔法
				{
					CObjWind* objw = new CObjWind(g_px + m_directionx, g_py + m_directiony);//Windオブジェクト作成
					Objs::InsertObj(objw, OBJ_WIND, 120);		//作ったWindオブジェクトをオブジェクトマネージャーに登録
				}
				else if (m_magic == 3)	//雷の魔法
				{
					CObjThunder* objt = new CObjThunder(g_px + m_directionx, g_py + m_directiony);//Thunderオブジェクト作成
					Objs::InsertObj(objt, OBJ_THUNDER, 120);		//作ったThunderオブジェクトをオブジェクトマネージャーに登録
				}
				m_f = false;
				m_mp -= 1;		//MPを減らす
				m_hp -= 3;		//HPを減らす（デバッグ）
			}
		}
		else
		{
			m_f = true;
		}
	}

	//キーの入力方向
	if (Input::GetVKey(VK_UP) == true)
	{
		m_vy -= m_speed_power;
		m_posture = 0.0f;	//上
		m_ani_time += 1;
	}
	else if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_vx += m_speed_power;
		m_posture = 1.0f;	//右
		m_ani_time += 1;
	}
	else if (Input::GetVKey(VK_DOWN) == true)
	{
		m_vy += m_speed_power;
		m_posture = 2.0f;	//下
		m_ani_time += 1;
	}
	else if (Input::GetVKey(VK_LEFT) == true)
	{
		m_vx -= m_speed_power;
		m_posture = 3.0f;	//左
		m_ani_time += 1;
	}
	else   //アニメーション処理
	{
		m_ani_frame = 0;	//キー入力がない場合は静止フレームにする
		m_ani_time = 0;
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

	CObjBlock* b = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//左のスクロールライン
	{
		g_px = 0;
		b->SetScrollX(b->GetScrollX());
	}
	//右のスクロールライン
	{
		g_px = 400;
		b->SetScrollX(b->GetScrollX());
	}
	//上のスクロールライン
	{
		g_py = 0;
		b->SetScrollY(b->GetScrollY());
	}
	//下のスクロールライン
	{
		g_py = 300;
		b->SetScrollY(b->GetScrollY());
	}

	//自身のHitBoxを持ってくる
	CHitBox* hit = Hits::GetHitBox(this);
	//主人公とMYSTTERY系統との当たり判定
	if (hit->CheckElementHit(ELEMENT_MYSTERY) == true)
	{
		//主人公がブロックとどの角度で当たっているのかを確認
		HIT_DATA** hit_date;							//当たった時の細かな情報を入れるための構造体
		hit_date = hit->SearchElementHit(ELEMENT_MYSTERY);	//hit_dateに主人公と当たっている他全てのHitBoxとの情報を入れる

		for (int i = 0; i < hit->GetCount(); i++)
		{
			float r = hit_date[i]->r;
			//角度で上下左右を判定
			if ((r < 45 && r >= 0) || r > 315)
			{
				m_vx = -0.15f; //右
			}
			if (r > 45 && r < 135)
			{
				m_vy = 0.15f;//上
			}
			if (r > 135 && r < 225)
			{
				m_vx = 0.15f;//左
			}
			if (r > 225 && r < 315)
			{
				m_vy = -0.15f; //下
			}
		}
	}

	//敵を接触したらBATTLESCENEに移行
	if (hit->CheckElementHit(ELEMENT_ENEMY) == true)
	{
		m_battle_flag = false;
		//Scene::SetScene(new CSceneBattle());
	}
	if (hit->CheckObjNameHit(OBJ_KEY) != nullptr)	//キーを取得
	{
		m_key = 1;
		m_key_mf = true;
	}
	if (hit->CheckObjNameHit(OBJ_GATE) != nullptr)
	{
		if (m_key == 1)		//鍵を持っている場合
		{
			m_key = 0;		//鍵を消費する
			m_gate_mf = true;//鍵のフラグをオンにする
		}
	}
	if (hit->CheckObjNameHit(ITEM_ICE) != nullptr)
	{
		m_ice_mf = true;
		m_ice_flag = true;
	}
	if (hit->CheckObjNameHit(OBJ_WATER) != nullptr)
	{
		m_water_mf = true;
	}
	if (hit->CheckObjNameHit(OBJ_HEAL) != nullptr)	//主人公がHEALと当たった場合
	{
		m_hp = m_max_hp;		//HPを最大まで回復
		m_mp = m_max_mp;		//MPを最大まで回復
	}

	//摩擦
	m_vx += -(m_vx * 0.098);
	m_vy += -(m_vy * 0.098);

	//ブロックとの当たり判定実行
	CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pb->BlockHit(&g_px, &g_py, true,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		&m_block_type
	);

	//位置の更新
	g_px += m_vx;
	g_py += m_vy;

	//HitBoxの位置の変更
	hit->SetPos(g_px, g_py);
	
	
}

//ドロー
void CObjHero::Draw()
{
	if (m_battle_flag == false)
	{
		return;
	}

	int AniDate[4] =
	{
		1 , 2 , 1 , 0 ,
	};	

	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画先表示位置

	//切り取り位置の設定
	src.m_top    = 32.0f * m_posture;
	src.m_left   =  0.0f + AniDate[m_ani_frame] * 24;
	src.m_right  = 24.0f + AniDate[m_ani_frame] * 24;
	src.m_bottom = 32.0f + (32.0f * m_posture);

	//表示位置の設定
	dst.m_top    =  0.0f + g_py;
	dst.m_left   =  0.0f + g_px;
	dst.m_right  = ALL_SIZE + g_px;
	dst.m_bottom = ALL_SIZE + g_py;

	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);
	
}