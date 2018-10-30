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

}

//アクション
void CObjBlock::Action()
{
	//主人公の位置を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//後方スクロールライン
	/*if (hx < 80)
	{
		hero->SetX(80);				//主人公はラインを超えないようにする
		m_scroll -= hero->GetVX();	//主人公が本来動くべき分の値をm_scrollに加える
	}

	//前方スクロールライン
	if (hx > 300)
	{
		hero->SetX(300);			//主人公はラインを超えないようにする
		m_scroll -= hero->GetVX();	//主人公が本来動くべき分の値をm_scrollに加える
	}*/
	//敵出現ライン
	//主人公の位置+500を敵出現ラインにする
	float line = hx + (-m_scroll) + 500;

	//敵出現ラインを要素番号化
	int ex = ((int)line) / 50;

	//敵出現ラインの列を検索
	for (int i = 0; i < 27; i++)
	{
		//列の中から4を探す
		if (m_map[i][ex] == 4)
		{
			
			//敵出現場所の値を0にする
			m_map[i][ex] = 0;
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

	//背景表示
	src.m_top	 =   0.0f;
	src.m_left	 =   0.0f;
	src.m_right	 = 800.0f;
	src.m_bottom = 600.0f;

	dst.m_top    =  50.0f;
	dst.m_left   =   0.0f;
	dst.m_right  = 800.0f;
	dst.m_bottom = 600.0f;
	Draw::Draw(FLOOR1, &src, &dst, c, 0.0f);

	for (int i = 0; i < 27; i++)
	{
		for (int j = 0; j < 55; j++)
		{
			if (m_map[i][j] >= 0)
			{

				//表示位置の設定
				dst.m_top    = i*50.0f+50.0f;
				dst.m_left   = j*50.0f;
				dst.m_right  = dst.m_left + 50.0f;
				dst.m_bottom = dst.m_top + 50.0f;
				if (m_map[i][j] == 1)
				{
					src.m_top    = 0.0f;
					src.m_left   = 0.0f;
					src.m_right  = src.m_left + 50.0f;
					src.m_bottom = src.m_top + 50.0f;
					//描画
					Draw::Draw(2, &src, &dst, c, 0.0f);

				}

				else
				{
					src.m_top = 0.0f;
					src.m_left = 0.0f;
					src.m_right = src.m_left + 50.0f;
					src.m_bottom = src.m_top + 50.0f;
					//描画
					Draw::Draw(3, &src, &dst, c, 0.0f);
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
	*up = false;
	*down = false;
	*left = false;
	*right = false;

	//踏んでいるblockの種類の初期化
	*bt = 0;

	//m_mapの全要素にアクセス
	for (int i = 0; i < 27; i++)
	{
		for (int j = 0; j < 55; j++)
		{
			if (m_map[i][j] > 0 && m_map[i][j] != 4)
			{
				//要素番号を座標に変更
				float bx = j*50.0f;
				float by = i*50.0f;

				//スクロールの影響
				float scroll = scroll_on ? m_scroll : 0;

				//オブジェクトとブロックの当たり判定
				if ((*x + (-scroll) + 50.0f > bx) && (*x + (-scroll) < bx + 50.0f) && (*y + 50.0f > by) && (*y < by + 50.0f))
				{
					//上下左右判定

					//vectorの作成
					float rvx = (*x + (-scroll)) - bx;
					float rvy = *y - by;

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
						if ((r < 45 && r>0) || r > 315)
						{
							//右
							*right = true;	//主人公の左の部分が衝突している
							*x = bx + 50.0f + (scroll);	//ブロックの位置+主人公の幅
							*vx = -(*vx) * 0.1f;//-VX*反発係数
						}
						if (r > 45 && r < 135)
						{
							//上
							*down = true;	//主人公から見て、下の部分が衝突している
							*y = by - 50.0f;	//ブロックの位置-主人公の幅
												//種類を渡すのスタートとゴールのみ変更する
							if (m_map[i][j] >= 2)
								*bt = m_map[i][j];//ブロックの要素（type）を主人公に渡す
							*vy = 0.0f;
						}
						if (r > 135 && r < 225)
						{
							//左
							*left = true;	//主人公の右の部分が衝突している
							*x = bx - 50.0f + (scroll);	//ブロックの位置-主人公の幅
							*vx = -(*vx) * 0.1f;//-VX*反発係数
						}
						if (r > 225 && r < 315)
						{
							//下
							*up = true;		//主人公から見て、上の部分が衝突している
							*y = by + 50.0f;	//ブロック位置+主人公の幅
							if (*vy < 0)
							{
								*vy = 0.0f;
							}
						}
					}

				}
			}
		}
	}
}

