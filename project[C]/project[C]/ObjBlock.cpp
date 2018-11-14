//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjBlock.h"


//使用するネームスペース
using namespace GameL;

CObjBlock::CObjBlock(int map[27][55])
{
	//マップデータをコピー
	memcpy(m_map, map, sizeof(int)*(27 * 55));
}

//イニシャライズ
void CObjBlock::Init()
{
	m_scrollx = 0.0f;
	m_scrolly = 0.0f;
}

//アクション
void CObjBlock::Action()
{
	//主人公の位置を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//左のスクロールライン
	{
		hero->SetX(0);				//主人公はラインを超えないようにする
		m_scrollx -= hero->GetVX();	//主人公が本来動くべき分の値をm_scrollに加える
	}

	//右のスクロールライン
	{
		hero->SetX(400);			//主人公はラインを超えないようにする
		m_scrollx -= hero->GetVX();	//主人公が本来動くべき分の値をm_scrollに加える
	}

	//上のスクロールライン
	{
		hero->SetY(0);				//主人公はラインを超えないようにする
		m_scrolly -= hero->GetVY();	//主人公が本来動くべき分の値をm_scrollに加える
	}

	//下のスクロールライン
	{
		hero->SetY(300);			//主人公はラインを超えないようにする
		m_scrolly -= hero->GetVY();	//主人公が本来動くべき分の値をm_scrollに加える
	}

	//出現
	for (int i = 0; i < 27; i++)
	{
		for (int j = 0; j < 55; j++)
		{
			//列の中からを探す
			if (m_map[i][j] == 3)
			{
				//3があれば水を出現
				CObjWater* objwater = new CObjWater(j*ALL_SIZE, i*ALL_SIZE);
				Objs::InsertObj(objwater, OBJ_WATER, 10);

				//出現場所の値を0にする
				m_map[i][j] = 0;
			}
			if (m_map[i][j] == 4)
			{
				//4があればFireblockを出現
				CObjFireblock* objfb = new CObjFireblock(j*ALL_SIZE, i*ALL_SIZE);
				Objs::InsertObj(objfb, OBJ_FIREBLOCK, 10);

				//出現場所の値を0にする
				m_map[i][j] = 0;
			}
			if (m_map[i][j] == 6)
			{
				//6があれば敵を出現
				CObjEnemy* obje = new CObjEnemy(j*ALL_SIZE, i*ALL_SIZE);
				Objs::InsertObj(obje, OBJ_ENEMY, 10);

				//出現場所の値を0にする
				m_map[i][j] = 0;
			}
			if (m_map[i][j] == 7)
			{
				//7があればMysteryblockを出現
				CObjMysteryblock* objgate = new CObjMysteryblock(j*ALL_SIZE, i*ALL_SIZE);
				Objs::InsertObj(objgate, OBJ_MYSTERYBLOCK, 10);

				//出現場所の値を0にする
				m_map[i][j] = 0;
			}
			if (m_map[i][j] == 11)
			{
				//11があればMoveblockを出現
				CObjMoveblock* objmb = new CObjMoveblock(j*ALL_SIZE, i*ALL_SIZE);
				Objs::InsertObj(objmb, OBJ_MOVEBLOCK, 10);

				//出現場所の値を0にする
				m_map[i][j] = 0;
			}
		}
	}
	
	
	
	
}

//ドロー
void CObjBlock::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画先表示位置


	for (int i = 0; i < 27; i++)
	{
		for (int j = 0; j < 55; j++)
		{
			if (m_map[i][j] >= 0)
			{

				//表示位置の設定
				dst.m_top    = i*ALL_SIZE + m_scrolly;
				dst.m_left   = j*ALL_SIZE + m_scrollx;
				dst.m_right  = dst.m_left + ALL_SIZE;
				dst.m_bottom = dst.m_top  + ALL_SIZE;
				if (m_map[i][j] == 0)
				{
					src.m_top    =   0.0f;
					src.m_left   =   0.0f;
					src.m_right  = 800.0f;
					src.m_bottom = 600.0f;
					//描画
					Draw::Draw(FLOOR1, &src, &dst, c, 0.0f);
				}
				else if (m_map[i][j] == 1)
				{
					src.m_top    = 0.0f;
					src.m_left   = 0.0f;
					src.m_right  = 50.0f;
					src.m_bottom = 50.0f;
					//描画
					Draw::Draw(2, &src, &dst, c, 0.0f);
				}
				else if (m_map[i][j] == 2)
				{
				}
				else if (m_map[i][j] == 3)
				{
				}
				else if (m_map[i][j] == 4)
				{
				}
				else if (m_map[i][j] == 5)
				{
					;
				}
				else if (m_map[i][j] == 8)
				{
				}
				else if (m_map[i][j] == 9)
				{
				}
				else if (m_map[i][j] == 10)
				{
				}
				else if (m_map[i][j] == 12)
				{
				}			
				else
				{

				}
			}
		}
	}
}



//BlockHit関数
//引数1		float*	x			:判定を行うobjectのX位置
//引数2		float*	y			:判定を行うobjectのY位置
//引数3		bool	scroll_on	:判定を行うobjectはスクロールの影響を与えるかどうか(true=与える false=与えない)
//引数4		bool*	up			:上下左右判定の上部分に当たっているかどうかを返す
//引数5		bool*	down		:上下左右判定の下部分に当たっているかどうかを返す
//引数6		bool*	left		:上下左右判定の左部分に当たっているかどうかを返す
//引数7		bool*	right		:上下左右判定の右部分に当たっているかどうかを返す
//引数8		float*	vx			:左右判定時の反発による移動方向・力を変えて返す
//引数9		float*	vy			:上下判定時による自由落下運動の移動方向・力を変えて返す
//引数10	int*	bt			:下部判定時、特殊なぶろっくのタイプを返す
//判定を行うobjectとブロック64×64限定で、当たり判定と上下左右判定を行う
//その結果は引数4～10に返す
void CObjBlock::BlockHit(
	float *x, float *y, bool scroll_on,
	bool *up, bool *down, bool *left, bool *right,
	float *vx, float *vy, int *bt
)
{

	//主人公の衝突状態確認用のフラグの初期化
	*up    = false;
	*down  = false;
	*left  = false;
	*right = false;

	//m_mapの全要素にアクセス
	for (int i = 0; i < 27; i++)
	{
		for (int j = 0; j < 55; j++)
		{
			if (m_map[i][j] > 0 && m_map[i][j] != 10)
			{
				//要素番号を座標に変更
				float bx = j*ALL_SIZE;
				float by = i*ALL_SIZE;

				//スクロールの影響
				float scrollx = scroll_on ? m_scrollx : 0;
				float scrolly = scroll_on ? m_scrolly : 0;

				//オブジェクトとブロックの当たり判定
				if ((*x +(-scrollx) + ALL_SIZE > bx) && (*x + (-scrollx) < bx + ALL_SIZE) && (*y + (-scrolly) + ALL_SIZE > by) && (*y + (-scrolly) < by + ALL_SIZE))
				{
					//上下左右判定

					//vectorの作成
					float rvx = (*x + (-scrollx)) - bx;
					float rvy = (*y + (-scrolly)) - by;

					//長さを求める
					float len = sqrt(rvx*rvx + rvy*rvy);

					//角度を求める
					float r = atan2(rvy, rvx);
					r = r * 180.0f / 3.14;

					if (r <= 0.0f)
						r = abs(r);
					else
						r = 360.0f - abs(r);

					//lenがある一定の長さより短い場合判定に入る
					if (len < 88.0f)
					{
						//角度で上下左右を判定
						if ((r < 45 && r > 0) || r > 315)
						{
							//右
							*right = true;	//主人公の左の部分が衝突している
							*x = bx + ALL_SIZE + (scrollx);	//ブロックの位置+主人公の幅
							*vx = 0.15f;//-VX*反発係数
						}
						if (r > 45 && r < 135)
						{
							//上
							*down = true;	//主人公から見て、下の部分が衝突している
							*y = by - ALL_SIZE + (scrolly);	//ブロックの位置-主人公の幅
							*vy = -0.15f;//-VX*反発係数
						}
						if (r > 135 && r < 225)
						{
							//左
							*left = true;	//主人公の右の部分が衝突している
							*x = bx - ALL_SIZE + (scrollx);	//ブロックの位置-主人公の幅
							*vx = -0.15f;//-VX*反発係数
						}
						if (r > 225 && r < 315)
						{
							//下
							*up = true;		//主人公から見て、上の部分が衝突している
							*y = by + ALL_SIZE + (scrolly);	//ブロック位置+主人公の幅
							*vy = 0.15f;//-VX*反発係数
						}
					}
				}
			}
		}
	}
}

