//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"


#include "GameHead.h"
#include "ObjBlock.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjBlock::CObjBlock(int map[27][55])
{
	//�}�b�v�f�[�^���R�s�[
	memcpy(m_map, map, sizeof(int)*(27 * 55));
}

//�C�j�V�����C�Y
void CObjBlock::Init()
{

}

//�A�N�V����
void CObjBlock::Action()
{
	//��l���̈ʒu���擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//����X�N���[�����C��
	/*if (hx < 80)
	{
		hero->SetX(80);				//��l���̓��C���𒴂��Ȃ��悤�ɂ���
		m_scroll -= hero->GetVX();	//��l�����{�������ׂ����̒l��m_scroll�ɉ�����
	}

	//�O���X�N���[�����C��
	if (hx > 300)
	{
		hero->SetX(300);			//��l���̓��C���𒴂��Ȃ��悤�ɂ���
		m_scroll -= hero->GetVX();	//��l�����{�������ׂ����̒l��m_scroll�ɉ�����
	}*/
	//�G�o�����C��
	//��l���̈ʒu+500��G�o�����C���ɂ���
	float line = hx + (-m_scroll) + 500;

	//�G�o�����C����v�f�ԍ���
	int ex = ((int)line) / 50;

	//�G�o�����C���̗������
	for (int i = 0; i < 27; i++)
	{
		//��̒�����4��T��
		if (m_map[i][ex] == 4)
		{
			
			//�G�o���ꏊ�̒l��0�ɂ���
			m_map[i][ex] = 0;
		}
	}
}

//�h���[
void CObjBlock::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`���\���ʒu

	//�w�i�\��
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

				//�\���ʒu�̐ݒ�
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
					//�`��
					Draw::Draw(2, &src, &dst, c, 0.0f);

				}

				else
				{
					src.m_top = 0.0f;
					src.m_left = 0.0f;
					src.m_right = src.m_left + 50.0f;
					src.m_bottom = src.m_top + 50.0f;
					//�`��
					Draw::Draw(3, &src, &dst, c, 0.0f);
				}
			}
		}
	}
}



//BlockHit�֐�
//����1		float*	x			:������s��object��X�ʒu
//����2		float*	y			:������s��object��Y�ʒu
//����3		bool	scroll_on	:������s��object�̓X�N���[���̉e����^���邩�ǂ���(true=�^���� false=�^���Ȃ�)
//����4		bool*	up			:�㉺���E����̏㕔���ɓ������Ă��邩�ǂ�����Ԃ�
//����5		bool*	down		:�㉺���E����̉������ɓ������Ă��邩�ǂ�����Ԃ�
//����6		bool*	left		:�㉺���E����̍������ɓ������Ă��邩�ǂ�����Ԃ�
//����7		bool*	right		:�㉺���E����̉E�����ɓ������Ă��邩�ǂ�����Ԃ�
//����8		float*	vx			:���E���莞�̔����ɂ��ړ������E�͂�ς��ĕԂ�
//����9		float*	vy			:�㉺���莞�ɂ�鎩�R�����^���̈ړ������E�͂�ς��ĕԂ�
//����10	int*	bt			:�������莞�A����ȂԂ�����̃^�C�v��Ԃ�
//������s��object�ƃu���b�N64�~64����ŁA�����蔻��Ə㉺���E������s��
//���̌��ʂ͈���4�`10�ɕԂ�
void CObjBlock::BlockHit(
	float *x, float *y, bool scroll_on,
	bool *up, bool *down, bool *left, bool *right,
	float *vx, float *vy, int *bt
)
{

	//��l���̏Փˏ�Ԋm�F�p�̃t���O�̏�����
	*up = false;
	*down = false;
	*left = false;
	*right = false;

	//����ł���block�̎�ނ̏�����
	*bt = 0;

	//m_map�̑S�v�f�ɃA�N�Z�X
	for (int i = 0; i < 27; i++)
	{
		for (int j = 0; j < 55; j++)
		{
			if (m_map[i][j] > 0 && m_map[i][j] != 4)
			{
				//�v�f�ԍ������W�ɕύX
				float bx = j*50.0f;
				float by = i*50.0f;

				//�X�N���[���̉e��
				float scroll = scroll_on ? m_scroll : 0;

				//�I�u�W�F�N�g�ƃu���b�N�̓����蔻��
				if ((*x + (-scroll) + 50.0f > bx) && (*x + (-scroll) < bx + 50.0f) && (*y + 50.0f > by) && (*y < by + 50.0f))
				{
					//�㉺���E����

					//vector�̍쐬
					float rvx = (*x + (-scroll)) - bx;
					float rvy = *y - by;

					//���������߂�
					float len = sqrt(rvx*rvx + rvy*rvy);

					//�p�x�����߂�
					float r = atan2(rvy, rvx);
					r = r * 180.0f / 3.14;

					if (r <= 0.0f)
						r = abs(r);
					else
						r = 360.0f - abs(r);

					//len��������̒������Z���ꍇ����ɓ���
					if (len < 88.0f)
					{
						//�p�x�ŏ㉺���E�𔻒�
						if ((r < 45 && r>0) || r > 315)
						{
							//�E
							*right = true;	//��l���̍��̕������Փ˂��Ă���
							*x = bx + 50.0f + (scroll);	//�u���b�N�̈ʒu+��l���̕�
							*vx = -(*vx) * 0.1f;//-VX*�����W��
						}
						if (r > 45 && r < 135)
						{
							//��
							*down = true;	//��l�����猩�āA���̕������Փ˂��Ă���
							*y = by - 50.0f;	//�u���b�N�̈ʒu-��l���̕�
												//��ނ�n���̃X�^�[�g�ƃS�[���̂ݕύX����
							if (m_map[i][j] >= 2)
								*bt = m_map[i][j];//�u���b�N�̗v�f�itype�j����l���ɓn��
							*vy = 0.0f;
						}
						if (r > 135 && r < 225)
						{
							//��
							*left = true;	//��l���̉E�̕������Փ˂��Ă���
							*x = bx - 50.0f + (scroll);	//�u���b�N�̈ʒu-��l���̕�
							*vx = -(*vx) * 0.1f;//-VX*�����W��
						}
						if (r > 225 && r < 315)
						{
							//��
							*up = true;		//��l�����猩�āA��̕������Փ˂��Ă���
							*y = by + 50.0f;	//�u���b�N�ʒu+��l���̕�
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

