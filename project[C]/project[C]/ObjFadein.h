#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�w�i
class CObjFadein : public CObj
{
	public:
		CObjFadein() {};
		~CObjFadein() {};
		void Init();	//�C�j�V�����C�Y
		void Action();	//�A�N�V����
		void Draw();	//�h���[
	private:
		int	m_ani_time;
		int m_ani_frame;

		float m_ani_max_time;	//�A�j���[�V��������Ԋu�ő�l

		bool m_battle_flag;		//�o�g���p�t���O
		bool m_boss_battle_f;	//�{�X��p�t���O

};
