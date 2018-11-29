//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjBlock.h"


int g_map[27][55];

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjBlock::CObjBlock(int map[27][55])
{
	//�}�b�v�f�[�^���R�s�[
	memcpy(g_map, map, sizeof(int)*(27 * 55));
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
	m_battle_flag = hero->GetBATTLE();
	m_boss_flag = hero->GetBOSSBATTLE();

	if (m_battle_flag == false || m_boss_flag == false)
	{
		return;
	}

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
			if (g_map[i][j] == 2)
			{
				//2�������Heal���o��
				CObjHeal* objheal = new CObjHeal(j*ALL_SIZE, i*ALL_SIZE);
				Objs::InsertObj(objheal, OBJ_HEAL, 111);

				//�o���ꏊ�̒l��0�ɂ���
				g_map[i][j] = 0;
			}
			if (g_map[i][j] == 3)
			{
				//3������ΐ����o��
				CObjWater* objwater = new CObjWater(j*ALL_SIZE, i*ALL_SIZE);
				Objs::InsertObj(objwater, OBJ_WATER, 110);

				//�o���ꏊ�̒l��0�ɂ���
				g_map[i][j] = 0;
			}
			if (g_map[i][j] == 4)
			{
				//4�������Fireblock���o��
				CObjFireblock* objfb = new CObjFireblock(j*ALL_SIZE, i*ALL_SIZE);
				Objs::InsertObj(objfb, OBJ_FIREBLOCK, 111);

				//�o���ꏊ�̒l��0�ɂ���
				g_map[i][j] = 0;
			}
			if (g_map[i][j] == 5)
			{
				//4�������Fireblock���o��
				CObjSister* sister = new CObjSister(j*ALL_SIZE, i*ALL_SIZE);
				Objs::InsertObj(sister, OBJ_SISTER, 111);

				//�o���ꏊ�̒l��0�ɂ���
				g_map[i][j] = 0;
			}

			if (g_map[i][j] == 6)
			{
				//6������ΓG���o��
				CObjEnemyFirst* obje1 = new CObjEnemyFirst(j*ALL_SIZE, i*ALL_SIZE);
				Objs::InsertObj(obje1, OBJ_ENEMY_FIRST, 110);

				//�o���ꏊ�̒l��0�ɂ���
				g_map[i][j] = 0;
			}
			if (g_map[i][j] == 7)
			{
				//7�������Gate���o��
				CObjGate* objgate = new CObjGate(j*ALL_SIZE, i*ALL_SIZE);
				Objs::InsertObj(objgate, OBJ_GATE, 110);

				//�o���ꏊ�̒l��0�ɂ���
				g_map[i][j] = 0;
			}
			if (g_map[i][j] == 9)
			{
				//9�������ItemIce���o��
				CObjItemIce* objice = new CObjItemIce(j*ALL_SIZE, i*ALL_SIZE);
				Objs::InsertObj(objice, ITEM_ICE, 110);

				//�o���ꏊ�̒l��0�ɂ���
				g_map[i][j] = 0;
			}
			if (g_map[i][j] == 10)
			{
				//10�������BOSS�o��
				CObjEnemyboss1* objb1 = new CObjEnemyboss1(j*ALL_SIZE, i*ALL_SIZE);
				Objs::InsertObj(objb1, OBJ_ENEMY, 110);

				//�o���ꏊ��0�ɂ���
				g_map[i][j] = 0;
			}
			if (g_map[i][j] == 11)
			{
				//11�������Key���o��
				CObjKey* objkey = new CObjKey(j*ALL_SIZE, i*ALL_SIZE);
				Objs::InsertObj(objkey, OBJ_KEY, 110);

				//�o���ꏊ�̒l��0�ɂ���
				g_map[i][j] = 0;
			}
			if (g_map[i][j] == 12)
			{
				//12�������Resetblock���o��
				CObjResetblock* objrb = new CObjResetblock(j*ALL_SIZE, i*ALL_SIZE);
				Objs::InsertObj(objrb, OBJ_RESETBLOCK, 110);

				//�o���ꏊ�̒l��0�ɂ���
				g_map[i][j] = 0;
			}
			if (g_map[i][j] == 13)
			{
				//13�������FireGate���o��
				CObjFireGate* objfg = new CObjFireGate(j*ALL_SIZE, i*ALL_SIZE);
				Objs::InsertObj(objfg, OBJ_FIREGATE, 110);

				//�o���ꏊ�̒l��0�ɂ���
				g_map[i][j] = 0;
			}
			if (g_map[i][j] == 16)
			{
				//16�������Switch���o��
				CObjSwitch* objsw = new CObjSwitch(j*ALL_SIZE, i*ALL_SIZE);
				Objs::InsertObj(objsw, OBJ_SWITCH, 111);

				//�o���ꏊ�̒l��0�ɂ���
				g_map[i][j] = 0;
			}
			if (g_map[i][j] == 17)
			{
				//16�������SwitchGate���o��
				CObjSwitchGate* objswg = new CObjSwitchGate(j*ALL_SIZE, i*ALL_SIZE);
				Objs::InsertObj(objswg, OBJ_SWITCHGATE, 111);

				//�o���ꏊ�̒l��0�ɂ���
				g_map[i][j] = 0;
			}
		}
	}
	
	
}

//�h���[
void CObjBlock::Draw()
{

	if (m_battle_flag == false || m_boss_flag == false)
	{
		return;
	}

	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`���\���ʒu


	for (int i = 0; i < 27; i++)
	{
		for (int j = 0; j < 55; j++)
		{
			if (g_map[i][j] >= 0)
			{

				//�\���ʒu�̐ݒ�
				dst.m_top    = i*ALL_SIZE + m_scrolly;
				dst.m_left   = j*ALL_SIZE + m_scrollx;
				dst.m_right  = dst.m_left + ALL_SIZE;
				dst.m_bottom = dst.m_top  + ALL_SIZE;
				if (g_map[i][j] == 0)
				{
					src.m_top    =   0.0f;
					src.m_left   =   0.0f;
					src.m_right  = 800.0f;
					src.m_bottom = 600.0f;
					//�`��
					Draw::Draw(FLOOR1, &src, &dst, c, 0.0f);
				}
				else if (g_map[i][j] == 1)
				{
					src.m_top    = 0.0f;
					src.m_left   = 0.0f;
					src.m_right  = 50.0f;
					src.m_bottom = 50.0f;
					//�`��
					Draw::Draw(BLOCK1, &src, &dst, c, 0.0f);
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
			if (g_map[i][j] > 0 && g_map[i][j] != 6 && g_map[i][j] != 10)
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
						if ((r < 45 && r >= 0) || r > 315)
						{
							//�E
							*right = true;	//��l���̍��̕������Փ˂��Ă���
							*x = bx + ALL_SIZE + (scrollx);	//�u���b�N�̈ʒu+��l���̕�
							*vx = 0.3f;//-VX*�����W��
						}
						if (r > 45 && r < 135)
						{
							//��
							*down = true;	//��l�����猩�āA���̕������Փ˂��Ă���
							*y = by - ALL_SIZE + (scrolly);	//�u���b�N�̈ʒu-��l���̕�
							*vy = -0.3f;//-VX*�����W��
						}
						if (r > 135 && r < 225)
						{
							//��
							*left = true;	//��l���̉E�̕������Փ˂��Ă���
							*x = bx - ALL_SIZE + (scrollx);	//�u���b�N�̈ʒu-��l���̕�
							*vx = -0.3f;//-VX*�����W��
						}
						if (r > 225 && r < 315)
						{
							//��
							*up = true;		//��l�����猩�āA��̕������Փ˂��Ă���
							*y = by + ALL_SIZE + (scrolly);	//�u���b�N�ʒu+��l���̕�
							*vy = 0.3f;//-VX*�����W��
						}
					}
				}
			}
		}
	}
}

