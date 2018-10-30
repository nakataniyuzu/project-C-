//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjHero.h"

float g_px = 50.0f;
float g_py = 100.0f;

//使用するネームスペース
using namespace GameL;



//イニシャライズ
void CObjHero::Init()
{
	m_vx = 0.0f;		//移動ベクトル
	m_vy = 0.0f;

	m_speed_power = 0.3f;	//通常速度

	//blockとの衝突状態確認
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	m_block_type = 0;		//踏んでいるblockの種類を確認用

	//当たり判定用のHitBoxを作成
	Hits::SetHitBox(this, m_px, m_py, 50, 50, ELEMENT_PLAYER, OBJ_HERO, 1);

}

//アクション
void CObjHero::Action()
{

	//Eキーでメニューを開く
	if (Input::GetVKey('E') == true)
	{
		Scene::SetScene(new CSceneMenu());
	}

	//キーの入力方向
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_vx += m_speed_power;
	}
	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_vx -= m_speed_power;
	}

	if (Input::GetVKey(VK_UP) == true)
	{
		m_vy -= m_speed_power;
	}

	if (Input::GetVKey(VK_DOWN) == true)
	{
		m_vy += m_speed_power;
	}


	//摩擦
	m_vx += -(m_vx * 0.098);
	m_vy += -(m_vy * 0.098);

	//ブロックとの当たり判定実行
	CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pb->BlockHit(&m_px, &m_py, true,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		&m_block_type
	);

	//自身のHitBoxを持ってくる
	CHitBox* hit = Hits::GetHitBox(this);

	//位置の更新
	g_px += m_vx;
	g_py += m_vy;
	
	
	//HitBoxの位置の変更
	hit->SetPos(g_px, g_py);

}

//ドロー
void CObjHero::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画先表示位置

	//切り取り位置の設定
	src.m_top    =  0.0f;
	src.m_left   =  0.0f;
	src.m_right  = 100.0f;
	src.m_bottom = 100.0f;

	//表示位置の設定
	dst.m_top    =  0.0f + g_py;
	dst.m_left   =  0.0f + g_px;
	dst.m_right  = 50.0f + g_px;
	dst.m_bottom = 50.0f + g_py;

	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);

}