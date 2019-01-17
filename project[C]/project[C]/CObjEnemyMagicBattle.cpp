//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL\Audio.h"
#include "GameL\WinInputs.h"

#include "GameHead.h"
#include "CObjEnemyMagicBattle.h"
#include "ObjBoss3Battle.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjEnemyMagicBattle::CObjEnemyMagicBattle(float x, float y)
{
	m_x = x;
	m_y = y;


}
//イニシャライズ
void CObjEnemyMagicBattle::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;

	m_bboss3_pos = 0.0f;

	m_damage = 10;

	//blockとの衝突状態確認
	m_hit_left = false;
	m_hit_right = false;
	m_hit = false;

	//ボスのHP情報を持ってくる
	CObjBoss3Battle* boss3h = (CObjBoss3Battle*)Objs::GetObj(OBJ_BOSS_BATTLE_THIRD);
	m_boss_hp = boss3h->GetHP();

	//ボスの位向きを取得
	CObjBoss3Battle* boss3 = (CObjBoss3Battle*)Objs::GetObj(OBJ_BOSS_BATTLE_THIRD);
	m_posture = boss3->GetPOS();

	m_time = 50;	//魔法が消える時間

	//当たり判定用HitBoxを作成
	Hits::SetHitBox(this, m_x, m_y, ALL_SIZE, ALL_SIZE, ELEMENT_MAGIC_BATTLE, OBJ_ENEMY_MAGIC_BATTLE, 1);
}

//アクション
void CObjEnemyMagicBattle::Action()
{
	CObjBoss3Battle* bboss3 = (CObjBoss3Battle*)Objs::GetObj(OBJ_BOSS_BATTLE_THIRD);
	m_bboss3_pos = bboss3 -> GetPOS();

	if (m_hit_left == true)	//左
		m_hit = true;
	if (m_hit_right == true)//右
		m_hit = true;

	if (m_bboss3_pos == 1.0f) {
		m_vx = 5.0f;
		m_x += m_vx + 10.8f;
	}
	if (m_bboss3_pos == 0.0f) {
		m_vx = -5.0f;
		m_x += m_vx - 10.8f;
	}

	//HitBox更新用ポインター取得
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

	//主人公と接触したら削除
	if (hit->CheckObjNameHit(OBJ_HERO_BATTLE) != nullptr)
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

	//HP0で魔法削除
	if (m_boss_hp == 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
}

//ドロー
void CObjEnemyMagicBattle::Draw()
{
	//描画カラー情報　R=RED  G=Green  B=Blue A=alpha(透過情報)
	float  c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	//表示位置の設定
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = ALL_SIZE + m_x;
	dst.m_bottom = ALL_SIZE + m_y;

	Draw::Draw(24, &src, &dst, c, 0.0f);
}