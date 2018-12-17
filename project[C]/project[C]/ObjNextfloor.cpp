//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"
#include "GameHead.h"

#include "ObjNextfloor.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjNextfloor::Init()
{
	m_time = 900;
	g_map_change += 1;
	m_and = 0.0f;
	m_andf = true;
}

//�A�N�V����
void CObjNextfloor::Action()
{
	if (m_andf == true)
	{
		m_and += 0.03f;
		if (m_and >= 1.0f)
		{
			m_and = 1.0f;
			m_andf = false;
		}
	}
	else 
	{


		if (m_time > 40) {
			m_time -= 15;
		}

		if (m_time <= 40 && Input::GetVKey(VK_RETURN) == true)
		{
			Scene::SetScene(new CSceneMain());	//�Q�[�����C���V�[���Ɉڍs
		}
	}
}

//�h���[
void CObjNextfloor::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,m_and };

	wchar_t NEXT[128];

	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top    = 0.0f;
	src.m_left   = 0.0f;
	src.m_right  = 800.0f;
	src.m_bottom = 600.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top    = 0.0f;
	dst.m_left   = 0.0f;
	dst.m_right  = 800.0f;
	dst.m_bottom = 600.0f;
	Draw::Draw(0, &src, &dst, c, 0.0f);

	//n�w�ڂւ̈ڍs�p�^�C�g��
	swprintf_s(NEXT, L"%d�w��",g_map_change + 1);		
	Font::StrDraw(NEXT, m_time, 500, 60, c);

}
