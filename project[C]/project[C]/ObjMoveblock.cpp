//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjMoveblock.h"


//使用するネームスペース
using namespace GameL;


CObjMoveblock::CObjMoveblock(float x, float y)
{
	m_px = x;		//位置
	m_py = y;
}

//イニシャライズ
void CObjMoveblock::Init()
{
	m_vx = 0.0f;		//移動ベクトル
	m_vy = 0.0f;
	m_posture = 1.0f;	//右向き0.0f 左向き1.0f

	m_speed_power = 0.5f;	//通常速度

	m_move = true;			//true=右 false=左

	//blockとの衝突状態確認
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	//当たり判定用のHitBoxを作成
	Hits::SetHitBox(this, m_px, m_py, ALL_SIZE, ALL_SIZE, ELEMENT_FIELD, OBJ_MOVEBLOCK, 1);

}

//アクション
void CObjMoveblock::Action()
{
	//主人公の位置を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//自身のHitBoxを持ってくる
	CHitBox* hit = Hits::GetHitBox(this);

	//敵と当たっているか確認
	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
	{
		//主人公が敵とどの角度で当たっているのかを確認
		HIT_DATA** hit_date;							//当たった時の細かな情報を入れるための構造体
		hit_date = hit->SearchObjNameHit(OBJ_HERO);	//hit_dateに主人公と当たっている他全てのHitBoxとの情報を入れる

		for (int i = 0; i < hit->GetCount(); i++)
		{
			//ブロックの上下左右に当たったら

			float r = hit_date[i]->r;
			if ((r < 45 && r >= 0) || r > 315)
			{
				//右
				m_vx = -5.0f;//左に移動させる
			}
			if (r > 45 && r < 135)
			{
				//上
				m_vy = +5.0f;
			}
			if (r > 135 && r < 225)
			{
				//左
				m_vx = +5.0f;//右に移動させる
			}
			if (r > 225 && r < 315)
			{
				//下
				m_vy = -5.0f;
			}
			m_px += ((CObjHero*)hit_date[i]->o)->GetVX();
			m_py += ((CObjHero*)hit_date[i]->o)->GetVY();

		}
	}

	if (hit->CheckObjNameHit(OBJ_MYSTERYBLOCK) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	//摩擦
	m_vx += -(m_vx * 0.098);
	m_vy += -(m_vy * 0.098);



	//ブロックタイプ検知用の変数がないためのダミー
	int d;

	//ブロックとの当たり判定実行
	CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pb->BlockHit(&m_px, &m_py, false,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		&d
	);

	//位置の更新
	m_px += m_vx;
	m_py += m_vy;

	//ブロック情報を持ってくる
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//HitBoxの位置の変更
	hit->SetPos(m_px + block->GetScrollX(), m_py + block->GetScrollY());

}

//ドロー
void CObjMoveblock::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画先表示位置

	//切り取り位置の設定
	src.m_top	 =   0.0f;
	src.m_left	 =   0.0f;
	src.m_right  = 100.0f;
	src.m_bottom = 100.0f;
	
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//表示位置の設定
	dst.m_top    =  0.0f + m_py + block->GetScrollY();	//描画に対してスクロールの影響を加える
	dst.m_left   =  0.0f + m_px + block->GetScrollX();
	dst.m_right  = ALL_SIZE + m_px + block->GetScrollX();
	dst.m_bottom = ALL_SIZE + m_py + block->GetScrollY();

	//描画
	Draw::Draw(4, &src, &dst, c, 0.0f);
}


