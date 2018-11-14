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
	m_scrollx = 0.0f;
	m_scrolly = 0.0f;
}

//�A�N�V����
void CObjBlock::Action()
{
	//��l���̈ʒu���擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//���̃X�N���[�����C��
	{
		hero->SetX(0);				//��l���̓��C���𒴂��Ȃ��悤�ɂ���
		m_scrollx -= hero->GetVX();	//��l�����{�������ׂ����̒l��m_scroll�ɉ�����
	}

	//�E�̃X�N���[�����C��
	{
		hero->SetX(400);			//��l���̓��C���𒴂��Ȃ��悤�ɂ���
		m_scrollx -= hero->GetVX();	//��l�����{�������ׂ����̒l��m_scroll�ɉ�����
	}

	//��̃X�N���[�����C��
	{
		hero->SetY(0);				//��l���̓��C���𒴂��Ȃ��悤�ɂ���
		m_scrolly -= hero->GetVY();	//��l�����{�������ׂ����̒l��m_scroll�ɉ�����
	}

	//���̃X�N���[�����C��
	{
		hero->SetY(300);			//��l���̓��C���𒴂��Ȃ��悤�ɂ���
		m_scrolly -= hero->GetVY();	//��l�����{�������ׂ����̒l��m_scroll�ɉ�����
	}

	//�o��
	for (int i = 0; i < 27; i++)
	{
		for (int j = 0; j < 55; j++)
		{
			//��̒������T��
			if (m_map[i][j] == 3)
			{
				//3������ΐ����o��
				CObjWater* objwater = new CObjWater(j*ALL_SIZE, i*ALL_SIZE);
				Objs::InsertObj(objwater, OBJ_WATER, 10);

				//�o���ꏊ�̒l��0�ɂ���
				m_map[i][j] = 0;
			}
			if (m_map[i][j] == 4)
			{
				//4�������Fireblock���o��
				CObjFireblock* objfb = new CObjFireblock(j*ALL_SIZE, i*ALL_SIZE);
				Objs::InsertObj(objfb, OBJ_FIREBLOCK, 10);

				//�o���ꏊ�̒l��0�ɂ���
				m_map[i][j] = 0;
			}
			if (m_map[i][j] == 6)
			{
				//6������ΓG���o��
				CObjEnemy* obje = new CObjEnemy(j*ALL_SIZE, i*ALL_SIZE);
				Objs::InsertObj(obje, OBJ_ENEMY, 10);

				//�o���ꏊ�̒l��0�ɂ���
				m_map[i][j] = 0;
			}
			if (m_map[i][j] == 7)
			{
				//7�������Mysteryblock���o��
				CObjMysteryblock* objgate = new CObjMysteryblock(j*ALL_SIZE, i*ALL_SIZE);
				Objs::InsertObj(objgate, OBJ_MYSTERYBLOCK, 10);

				//�o���ꏊ�̒l��0�ɂ���
				m_map[i][j] = 0;
			}
			if (m_map[i][j] == 11)
			{
				//11�������Moveblock���o��
				CObjMoveblock* objmb = new CObjMoveblock(j*ALL_SIZE, i*ALL_SIZE);
				Objs::InsertObj(objmb, OBJ_MOVEBLOCK, 10);

				//�o���ꏊ�̒l��0�ɂ���
				m_map[i][j] = 0;
			}
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


	for (int i = 0; i < 27; i++)
	{
		for (int j = 0; j < 55; j++)
		{
			if (m_map[i][j] >= 0)
			{

				//�\���ʒu�̐ݒ�
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
					//�`��
					Draw::Draw(FLOOR1, &src, &dst, c, 0.0f);
				}
				else if (m_map[i][j] == 1)
				{
					src.m_top    = 0.0f;
					src.m_left   = 0.0f;
					src.m_right  = 50.0f;
					src.m_bottom = 50.0f;
					//�`��
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
	*up    = false;
	*down  = false;
	*left  = false;
	*right = false;

	//m_map�̑S�v�f�ɃA�N�Z�X
	for (int i = 0; i < 27; i++)
	{
		for (int j = 0; j < 55; j++)
		{
			if (m_map[i][j] > 0 && m_map[i][j] != 10)
			{
				//�v�f�ԍ������W�ɕύX
				float bx = j*ALL_SIZE;
				float by = i*ALL_SIZE;

				//�X�N���[���̉e��
				float scrollx = scroll_on ? m_scrollx : 0;
				float scrolly = scroll_on ? m_scrolly : 0;

				//�I�u�W�F�N�g�ƃu���b�N�̓����蔻��
				if ((*x +(-scrollx) + ALL_SIZE > bx) && (*x + (-scrollx) < bx + ALL_SIZE) && (*y + (-scrolly) + ALL_SIZE > by) && (*y + (-scrolly) < by + ALL_SIZE))
				{
					//�㉺���E����

					//vector�̍쐬
					float rvx = (*x + (-scrollx)) - bx;
					float rvy = (*y + (-scrolly)) - by;

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
						if ((r < 45 && r > 0) || r > 315)
						{
							//�E
							*right = true;	//��l���̍��̕������Փ˂��Ă���
							*x = bx + ALL_SIZE + (scrollx);	//�u���b�N�̈ʒu+��l���̕�
							*vx = 0.15f;//-VX*�����W��
						}
						if (r > 45 && r < 135)
						{
							//��
							*down = true;	//��l�����猩�āA���̕������Փ˂��Ă���
							*y = by - ALL_SIZE + (scrolly);	//�u���b�N�̈ʒu-��l���̕�
							*vy = -0.15f;//-VX*�����W��
						}
						if (r > 135 && r < 225)
						{
							//��
							*left = true;	//��l���̉E�̕������Փ˂��Ă���
							*x = bx - ALL_SIZE + (scrollx);	//�u���b�N�̈ʒu-��l���̕�
							*vx = -0.15f;//-VX*�����W��
						}
						if (r > 225 && r < 315)
						{
							//��
							*up = true;		//��l�����猩�āA��̕������Փ˂��Ă���
							*y = by + ALL_SIZE + (scrolly);	//�u���b�N�ʒu+��l���̕�
							*vy = 0.15f;//-VX*�����W��
						}
					}
				}
			}
		}
	}
}

