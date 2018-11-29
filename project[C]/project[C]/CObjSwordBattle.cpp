//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL\Audio.h"
#include "GameL\WinInputs.h"

#include "GameHead.h"
#include "CObjSwordBattle.h"
#include "ObjHeroBattle.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjSwordBattle::CObjSwordBattle(float x, float y)
{
	m_x = x;
	m_y = y;
}
//イニシャライズ
void CObjSwordBattle::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;

	posture = 0.0f;	//右向き0.0f 左向き1.0f

	//blockとの衝突状態確認
	m_hit_left = false;
	m_hit_right = false;
	m_hit = false;

	//主人公の位向きを取得
	CObjHeroBattle* hero = (CObjHeroBattle*)Objs::GetObj(OBJ_HERO_BATTLE);
	posture = hero->GetPOS();

	m_time = 0;

	m_sword_time = 10;	//剣が消える時間

	//当たり判定用HitBoxを作成
	Hits::SetHitBox(this, m_x + 25, m_y, 35, 50, ELEMENT_ATTACK, OBJ_SWORD_BATTLE, 1);
}

//アクション
void CObjSwordBattle::Action()
{
	if (m_hit_left == true)	//左
		m_hit = true;
	if (m_hit_right == true)//右
		m_hit = true;

	if (posture == 0.0f) {
		m_vx = 4.0f;
		m_x += m_vx;
	}
	if (posture == 1.0f) {
		m_vx = -4.0f;
		m_x += m_vx;
	}

	//HitBox更新用ポインター取得
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

	//敵と接触したら剣削除
	if (hit->CheckObjNameHit(OBJ_ENEMY_BATTLE) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	//壁に当たったら消える処理
	if (m_hit == true) {
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	//一定の時間で消える処理
	if (m_sword_time > 0) {
		m_sword_time--;
		if (m_sword_time <= 0) {
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}
	}

	

}

//ドロー
void CObjSwordBattle::Draw()
{
	//描画カラー情報　R=RED  G=Green  B=Blue A=alpha(透過情報)
	float  c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画先表示位置

	//切り取り位置の設定
	if (posture == 0.0f)
	{
		src.m_top = 11.0f;
		src.m_left = 65.0f;
		src.m_right = 116.0f;
		src.m_bottom = 61.0f;
	}
	if (posture == 1.0f)
	{
		src.m_top = 12.0f;
		src.m_left = 10.0f;
		src.m_right = 61.0f;
		src.m_bottom = 61.0f;
	}

	//表示位置の設定
	dst.m_top    = 0.0f + m_y;
	dst.m_left   = 0.0f + m_x;
	dst.m_right  = ALL_SIZE + m_x;
	dst.m_bottom = ALL_SIZE + m_y;

	Draw::Draw(16, &src, &dst, c, 0.0f);
}