//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL\Audio.h"
#include "GameL\WinInputs.h"

#include "GameHead.h"
#include "CObjWind.h"
#include "ObjHero.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjWind::CObjWind(float x, float y)
{
	m_x = x;
	m_y = y;

}
//イニシャライズ
void CObjWind::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;

	//blockとの衝突状態確認
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;
	m_hit = false;

	//主人公の位向きを取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	m_posture = hero->GetPOS();

	m_time = 50;	//魔法が消える時間

					//当たり判定用HitBoxを作成
	Hits::SetHitBox(this, m_x, m_y, ALL_SIZE, ALL_SIZE, ELEMENT_MAGIC, OBJ_WIND, 1);
}

//アクション
void CObjWind::Action()
{
	if (m_hit_up == true)	//上
		m_hit = true;
	if (m_hit_down == true)	//下
		m_hit = true;
	if (m_hit_left == true)	//左
		m_hit = true;
	if (m_hit_right == true)//右
		m_hit = true;

	if (m_posture == 0.0f) {
		m_vy = -5.0f;
		m_y += m_vy;
	}
	if (m_posture == 1.0f) {
		m_vx = 5.0f;
		m_x += m_vx;
	}
	if (m_posture == 2.0f) {
		m_vy = 5.0f;
		m_y += m_vy;
	}
	if (m_posture == 3.0f) {
		m_vx = -5.0f;
		m_x += m_vx;
	}

	//HitBox更新用ポインター取得
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

	//ブロックタイプ検知用の変数がないためのダミー
	int d;

	//ブロックとの当たり判定実行
	CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pb->BlockHit(&m_x, &m_y, true,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		&d
	);

	//MYSTERY属性、ENEMY属性と衝突したら消滅させる
	if (hit->CheckElementHit(ELEMENT_MYSTERY) == true
		|| hit->CheckElementHit(ELEMENT_ENEMY) == true
		|| hit->CheckObjNameHit(OBJ_BOSS) != nullptr)
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
	if (m_time > 0) {
		m_time--;
		if (m_time <= 0) {
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}
	}
}


//ドロー
void CObjWind::Draw()
{
	//描画カラー情報　R=RED  G=Green  B=Blue A=alpha(透過情報)
	float  c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画先表示位置

	//切り取り位置の設定
	src.m_top    =   0.0f;
	src.m_left   = 150.0f;
	src.m_right  = 200.0f;
	src.m_bottom =  52.0f;

	//表示位置の設定
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = ALL_SIZE + m_x;
	dst.m_bottom = ALL_SIZE + m_y;

	Draw::Draw(13, &src, &dst, c, 0.0f);
}