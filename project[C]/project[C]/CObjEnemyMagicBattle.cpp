//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL\Audio.h"
#include "GameL\WinInputs.h"

#include "GameHead.h"
#include "CObjEnemyMagicBattle.h"
#include "ObjBoss3Battle.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjEnemyMagicBattle::CObjEnemyMagicBattle(float x, float y)
{
	m_x = x;
	m_y = y;


}
//�C�j�V�����C�Y
void CObjEnemyMagicBattle::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;

	m_bboss3_pos = 0.0f;

	m_damage = 10;

	//block�Ƃ̏Փˏ�Ԋm�F
	m_hit_left = false;
	m_hit_right = false;
	m_hit = false;

	//�{�X��HP���������Ă���
	CObjBoss3Battle* boss3h = (CObjBoss3Battle*)Objs::GetObj(OBJ_BOSS_BATTLE_THIRD);
	m_boss_hp = boss3h->GetHP();

	//�{�X�̈ʌ������擾
	CObjBoss3Battle* boss3 = (CObjBoss3Battle*)Objs::GetObj(OBJ_BOSS_BATTLE_THIRD);
	m_posture = boss3->GetPOS();

	m_time = 50;	//���@�������鎞��

	//�����蔻��pHitBox���쐬
	Hits::SetHitBox(this, m_x, m_y, ALL_SIZE, ALL_SIZE, ELEMENT_MAGIC_BATTLE, OBJ_ENEMY_MAGIC_BATTLE, 1);
}

//�A�N�V����
void CObjEnemyMagicBattle::Action()
{
	CObjBoss3Battle* bboss3 = (CObjBoss3Battle*)Objs::GetObj(OBJ_BOSS_BATTLE_THIRD);
	m_bboss3_pos = bboss3 -> GetPOS();

	if (m_hit_left == true)	//��
		m_hit = true;
	if (m_hit_right == true)//�E
		m_hit = true;

	if (m_bboss3_pos == 1.0f) {
		m_vx = 5.0f;
		m_x += m_vx + 10.8f;
	}
	if (m_bboss3_pos == 0.0f) {
		m_vx = -5.0f;
		m_x += m_vx - 10.8f;
	}

	//HitBox�X�V�p�|�C���^�[�擾
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

	//��l���ƐڐG������폜
	if (hit->CheckObjNameHit(OBJ_HERO_BATTLE) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	//�ǂɓ�������������鏈��
	if (m_hit == true) {
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	//���̎��Ԃŏ����鏈��
	if (m_time > 0) {
		m_time--;
		if (m_time <= 0) {
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}
	}

	//HP0�Ŗ��@�폜
	if (m_boss_hp == 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
}

//�h���[
void CObjEnemyMagicBattle::Draw()
{
	//�`��J���[���@R=RED  G=Green  B=Blue A=alpha(���ߏ��)
	float  c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = ALL_SIZE + m_x;
	dst.m_bottom = ALL_SIZE + m_y;

	Draw::Draw(24, &src, &dst, c, 0.0f);
}