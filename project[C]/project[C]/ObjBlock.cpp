//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjBlock.h"


int g_map[38][65];

//使用するネームスペース
using namespace GameL;

CObjBlock::CObjBlock(int map[38][65])
{
	//マップデータをコピー
	memcpy(g_map, map, sizeof(int)*(38 * 65));
}

//イニシャライズ
void CObjBlock::Init()
{
	m_scrollx = 0.0f;
	m_scrolly = 0.0f;
	m_and = 0.0f;
	m_andf = true;
}

//アクション
void CObjBlock::Action()
{
	if (m_andf == true)
	{
		m_and += 0.01f;
		if (m_and >= 1.0f)
		{
			m_and = 1.0f;
			m_andf = false;
		}
	}

	//主人公の位置を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	if (g_battle_flag == true)
	{
		return;
	}

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
	for (int i = 0; i < 38; i++)
	{
		for (int j = 0; j < 65; j++)
		{

			//列の中からを探す
			if (g_map[i][j] == 2)
			{
				//2があればHealを出現
				CObjHeal* objheal = new CObjHeal(j*ALL_SIZE, i*ALL_SIZE);
				Objs::InsertObj(objheal, OBJ_HEAL, 111);

				//出現場所の値を0にする
				g_map[i][j] = 0;
			}
			if (g_map[i][j] == 3)
			{
				//3があれば水を出現
				CObjWater* objwater = new CObjWater(j*ALL_SIZE, i*ALL_SIZE);
				Objs::InsertObj(objwater, OBJ_WATER, 110);

				//出現場所の値を0にする
				g_map[i][j] = 0;
			}
			if (g_map[i][j] == 4)
			{
				//4があればFireblockを出現
				CObjFireblock* objfb = new CObjFireblock(j*ALL_SIZE, i*ALL_SIZE);
				Objs::InsertObj(objfb, OBJ_FIREBLOCK, 111);

				//出現場所の値を0にする
				g_map[i][j] = 0;
			}
			if (g_map[i][j] == 5)
			{
				//5があればStairsを出現
				CObjStairs* objsta = new CObjStairs(j*ALL_SIZE, i*ALL_SIZE);
				Objs::InsertObj(objsta, OBJ_STAIRS, 111);

				//出現場所の値を0にする
				g_map[i][j] = 0;
			}

			if (g_map[i][j] == 6)
			{
				//6があれば敵を出現
				if (g_map_change == 0) {
					CObjEnemy1* obje1 = new CObjEnemy1(j*ALL_SIZE, i*ALL_SIZE);
					Objs::InsertObj(obje1, OBJ_ENEMY_FIRST, 112);
				}
				else if (g_map_change == 1) {
					CObjEnemy2* obje2 = new CObjEnemy2(j*ALL_SIZE, i*ALL_SIZE);
					Objs::InsertObj(obje2, OBJ_ENEMY_SECOND, 112);
				}
				else if (g_map_change == 2) {
					CObjEnemy3* obje3 = new CObjEnemy3(j*ALL_SIZE, i*ALL_SIZE);
					Objs::InsertObj(obje3, OBJ_ENEMY_THIRD, 112);
				}

				//出現場所の値を0にする
				g_map[i][j] = 0;
			}
			if (g_map[i][j] == 7)
			{
				//7があればGateを出現
				CObjGate* objgate = new CObjGate(j*ALL_SIZE, i*ALL_SIZE);
				Objs::InsertObj(objgate, OBJ_GATE, 110);

				//出現場所の値を0にする
				g_map[i][j] = 0;
			}
			if (g_map[i][j] == 9)
			{
				//9があればItemを出現
				if (g_map_change == 0) {	//1層目は氷アイテムを出現
					CObjItemIce* objice = new CObjItemIce(j*ALL_SIZE, i*ALL_SIZE);
					Objs::InsertObj(objice, ITEM_ICE, 110);
				}
				else if (g_map_change == 1) {//2層目は風アイテムを出現
					CObjItemWind* objwind = new CObjItemWind(j*ALL_SIZE, i*ALL_SIZE);
					Objs::InsertObj(objwind, ITEM_ICE, 110);
				}

				//出現場所の値を0にする
				g_map[i][j] = 0;
			}
			if (g_map[i][j] == 10)
			{
				//10があればBOSS出現
				CObjEnemyboss1* objb1 = new CObjEnemyboss1(j*ALL_SIZE, i*ALL_SIZE);
				Objs::InsertObj(objb1, OBJ_BOSS, 110);
				
				//出現場所を0にする
				g_map[i][j] = 0;
			}
			if (g_map[i][j] == 11)
			{
				//11があればKeyを出現
				CObjKey* objkey = new CObjKey(j*ALL_SIZE, i*ALL_SIZE);
				Objs::InsertObj(objkey, OBJ_KEY, 110);

				//出現場所の値を0にする
				g_map[i][j] = 0;
			}
			if (g_map[i][j] == 12)
			{
				//12があればResetblockを出現
				CObjResetblock* objrb = new CObjResetblock(j*ALL_SIZE, i*ALL_SIZE);
				Objs::InsertObj(objrb, OBJ_RESETBLOCK, 110);

				//出現場所の値を0にする
				g_map[i][j] = 0;
			}
			if (g_map[i][j] == 13)
			{
				//13があればFireGateを出現
				CObjFireGate* objfg = new CObjFireGate(j*ALL_SIZE, i*ALL_SIZE);
				Objs::InsertObj(objfg, OBJ_FIREGATE, 110);

				//出現場所の値を0にする
				g_map[i][j] = 0;
			}
			if (g_map[i][j] == 16)
			{
				//16があればSwitchを出現
				CObjSwitch* objsw = new CObjSwitch(j*ALL_SIZE, i*ALL_SIZE);
				Objs::InsertObj(objsw, OBJ_SWITCH, 111);

				//出現場所の値を0にする
				g_map[i][j] = 0;
			}
			if (g_map[i][j] == 17)
			{
				//17があればSwitchGateを出現
				CObjSwitchGate* objswg = new CObjSwitchGate(j*ALL_SIZE, i*ALL_SIZE);
				Objs::InsertObj(objswg, OBJ_SWITCHGATE, 111);

				//出現場所の値を0にする
				g_map[i][j] = 0;
			}
			if (g_map[i][j] == 18)
			{
				//18があればDummySwitchを出現
				CObjDummySwitch* objds = new CObjDummySwitch(j*ALL_SIZE, i*ALL_SIZE);
				Objs::InsertObj(objds, OBJ_DUMMYSWITCH, 111);
				//出現場所の値を0にする
				g_map[i][j] = 0;
			}
			if (g_map[i][j] == 19)
			{
				//19があればBossSwitchを出現
				CObjBossSwitch* objbs = new CObjBossSwitch(j*ALL_SIZE, i*ALL_SIZE);
				Objs::InsertObj(objbs, OBJ_BOSSSWITCH, 111);
				//出現場所の値を0にする
				g_map[i][j] = 0;
			}
			if (g_map[i][j] == 20)
			{
				//20があればBossGateを出現
				CObjBossGate* objbg = new CObjBossGate(j*ALL_SIZE, i*ALL_SIZE);
				Objs::InsertObj(objbg, OBJ_BOSSGATE, 111);
				//出現場所の値を0にする
				g_map[i][j] = 0;
			}
			if (g_map[i][j] == 21)
			{
				//21があればChangeSwitchを出現
				CObjChangeSwitch* objds = new CObjChangeSwitch(j*ALL_SIZE, i*ALL_SIZE);
				Objs::InsertObj(objds, OBJ_CHANGESWITCH, 111);
				//出現場所の値を0にする
				g_map[i][j] = 0;
			}
			if (g_map[i][j] == 22)
			{
				//22があればChangeGate1を出現
				CObjChangeGate1* objds = new CObjChangeGate1(j*ALL_SIZE, i*ALL_SIZE);
				Objs::InsertObj(objds, OBJ_CHANGEGATE, 111);
				//出現場所の値を0にする
				g_map[i][j] = 0;
			}
			if (g_map[i][j] == 23)
			{
				//23があればChangeGate2を出現
				CObjChangeGate2* objds = new CObjChangeGate2(j*ALL_SIZE, i*ALL_SIZE);
				Objs::InsertObj(objds, OBJ_CHANGEGATE, 111);
				//出現場所の値を0にする
				g_map[i][j] = 0;
			}
			if (g_map[i][j] == 24)
			{
				//24があればWindBlockを出現
				CObjWindBlock* objwb = new CObjWindBlock(j*ALL_SIZE, i*ALL_SIZE);
				Objs::InsertObj(objwb, OBJ_WINDBLOCK, 111);
				//出現場所の値を0にする
				g_map[i][j] = 0;
			}
			if (g_map[i][j] == 25)
			{
				//25があればSisterを出現
				CObjSister* objsis = new CObjSister(j*ALL_SIZE, i*ALL_SIZE);
				Objs::InsertObj(objsis, OBJ_SISTER, 111);
				//出現場所の値を0にする
				g_map[i][j] = 0;
			}
		}
	}
}

//ドロー
void CObjBlock::Draw()
{
	if (g_battle_flag == true)
	{
		return;
	}

	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,m_and };

	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画先表示位置


	for (int i = 0; i < 38; i++)
	{
		for (int j = 0; j < 65; j++)
		{
			if (g_map[i][j] >= 0)
			{

				//表示位置の設定
				dst.m_top    = i*ALL_SIZE + m_scrolly;
				dst.m_left   = j*ALL_SIZE + m_scrollx;
				dst.m_right  = dst.m_left + ALL_SIZE;
				dst.m_bottom = dst.m_top  + ALL_SIZE;
				if (g_map[i][j] == 0)
				{
					src.m_top    =   0.0f;
					src.m_left   =   0.0f;
					src.m_right  = 100.0f;
					src.m_bottom = 100.0f;
					//描画
					Draw::Draw(FLOOR, &src, &dst, c, 0.0f);
				}
				else if (g_map[i][j] == 1)
				{
					src.m_top    = 0.0f;
					src.m_left   = 0.0f;
					src.m_right  = 100.0f;
					src.m_bottom = 100.0f;
					//描画
					Draw::Draw(BLOCK, &src, &dst, c, 0.0f);
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
//その結果は引数4〜10に返す
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
	for (int i = 0; i < 38; i++)
	{
		for (int j = 0; j < 65; j++)
		{
			if (g_map[i][j] > 0 && g_map[i][j] != 6 && g_map[i][j] != 10)
			{
				//要素番号を座標に変更
				float bx = j*ALL_SIZE;
				float by = i*ALL_SIZE;

				//スクロールの影響
				float scrollx = scroll_on ? m_scrollx : 0;
				float scrolly = scroll_on ? m_scrolly : 0;

				//オブジェクトとブロックの当たり判定
				if ((*x +(-scrollx) + 42.0f > bx) && (*x + (-scrollx) < bx + 42.0f) 
				 && (*y + (-scrolly) + 48.0f > by) && (*y + (-scrolly) < by + 48.0f))
				{
					//上下左右判定

					//vectorの作成
					float rvx = (*x + (-scrollx)) - bx;
					float rvy = (*y + (-scrolly)) - by;

					//長さを求める
					float len = sqrt(rvx*rvx + rvy*rvy);

					//角度を求める
					float r = atan2(rvy, rvx);
					r = r * 180.0f / 3.14f;

					if (r <= 0.0f)
						r = abs(r);
					else
						r = 360.0f - abs(r);

					//lenがある一定の長さより短い場合判定に入る
					if (len < 88.0f)
					{
						//角度で上下左右を判定
						if ((r < 45 && r >= 0) || r > 315)
						{
							//右
							*right = true;	//主人公の左の部分が衝突している
							*x = bx + 42.0f + (scrollx);	//ブロックの位置+主人公の幅
							*vx = 0.2f;//-VX*反発係数
						}
						if (r > 45 && r < 135)
						{
							//上
							*down = true;	//主人公から見て、下の部分が衝突している
							*y = by - 48.0f + (scrolly);	//ブロックの位置-主人公の幅
							*vy = -0.2f;//-VX*反発係数
						}
						if (r > 135 && r < 225)
						{
							//左
							*left = true;	//主人公の右の部分が衝突している
							*x = bx - 42.0f + (scrollx);	//ブロックの位置-主人公の幅
							*vx = -0.2f;//-VX*反発係数
						}
						if (r > 225 && r < 315)
						{
							//下
							*up = true;		//主人公から見て、上の部分が衝突している
							*y = by + 48.0f + (scrolly);	//ブロック位置+主人公の幅
							*vy = 0.2f;//-VX*反発係数
						}
					}
				}
			}
		}
	}
}

