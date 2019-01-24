//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameHead.h"
#include "GameL\WinInputs.h"
#include "GameL\Audio.h"
#include "ObjFadein.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjFadein::Init()
{
	m_ani_time = 0;
	m_ani_frame = 0;	//�Î~�t���[���������ɂ���

	m_ani_max_time = 2;		//�A�j���[�V�����Ԋu��

	m_flag = true;			//�؂�ւ��p�t���O
	m_fade_flag = true;		//�t�F�C�h�C���̐؂�ւ��p�t���O
	//�t���O�̏�����
	m_next_flag = false;
	m_main_flag = false;
	m_death_flag = false;
	m_clear_flag = false;
}

//�A�N�V����
void CObjFadein::Action()
{
	//��l���̏��������Ă���
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	hero->SetSPEED(0.0f);	//�X�s�[�h���O�ɂ���
	hero->SetVX(0.0f);		//�x�N�g�����O�ɂ���
	hero->SetVY(0.0f);
	m_next_flag = hero->GetNEXTF();	//�l�N�X�g�t���O���擾
	m_fade_flag = hero->GetFADEF();	//�t�F�C�h�C�����A�E�g��ݒ肷�邽�߂̃t���O
	m_death_flag = hero->GetDEATHF();//���S���������f���邽�߂̃t���O���擾
	m_clear_flag = hero->GetCLEAR();//�N���A�V�[���ֈڍs���邽�߂̃t���O���擾

	if (m_flag == true)
	{
		m_ani_time += 1;

		if (m_ani_time > m_ani_max_time)
		{
			m_ani_frame += 1;
			m_ani_time = 0;
		}
		if (m_ani_frame == 9)
		{
			if (m_next_flag == true)	//�t���O���I���̏ꍇ
			{
				Scene::SetScene(new CSceneNextfloor());	//�Q�[���l�N�X�g�V�[���Ɉڍs
			}
			if (m_main_flag == true)	//�t���O���I���̏ꍇ
			{
				Scene::SetScene(new CSceneMain());	//�Q�[�����C���V�[���Ɉڍs
			}
			if (m_death_flag == true)	//�t���O���I���̏ꍇ
			{
				Scene::SetScene(new CSceneGameover());	//�Q�[���I�[�o�[�V�[���Ɉڍs
			}
			if (m_clear_flag == true)
			{
				Scene::SetScene(new CSceneClear());	//�Q�[���N���A�V�[���Ɉڍs
			}
			m_flag = false;
			if (m_fade_flag == false) {
				g_xp_flag = true;		//�o���l�t���O���I���ɖ߂�
				g_battle_flag = false;//�}�b�v��ʂֈڍs
				g_key_flag = false;		//�L�[���͐���t���O���I�t�ɂ���
				g_battle_key = true;//�}�b�v��ʂֈڍs
				g_mhit_enemy_flag = false;//�G����������
				Audio::Stop(13);
				Audio::Start(12);	//�}�b�v�pBGM��炷
			}
			else {
				g_battle_flag = true;//�o�g����ʂֈڍs
				Audio::Stop(12);
				Audio::Start(13);	//�}�b�v�pBGM��炷
			}
		}
	}
	else if(m_flag == false)
	{
		m_ani_time += 1;

		if (m_ani_time > m_ani_max_time)
		{
			m_ani_frame -= 1;
			m_ani_time = 0;
		}
		if (m_ani_frame == 0)
		{
			this->SetStatus(false);
			hero->SetFADEF(false);
		}
	}
}

//�h���[
void CObjFadein::Draw()
{
	//�`��J���[���@R=RED  G=Green  B=Blue A=alpha(���ߏ��)
	float  c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;		//�`�挳�؂���ʒu
	RECT_F dst;		//�`���\���ʒu

	//�w�i�؂���
	src.m_top    =   0.0f;
	src.m_left   =   0.0f + (800.0f * m_ani_frame);
	src.m_right  = 800.0f + (800.0f * m_ani_frame);
	src.m_bottom = 600.0f;

	//�`��
	dst.m_top    =   0.0f;
	dst.m_left   =   0.0f;
	dst.m_right  = 800.0f;
	dst.m_bottom = 600.0f;
	Draw::Draw(17, &src, &dst, c, 0.0f);
}

