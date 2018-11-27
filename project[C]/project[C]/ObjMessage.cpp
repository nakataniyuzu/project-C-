//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"
#include "GameHead.h"

#include "ObjMessage.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjMessage::Init()
{

}

//�A�N�V����
void CObjMessage::Action()
{
	
}

//�h���[
void CObjMessage::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float b[4] = { 0.0f,0.0f,1.0f,1.0f };
	float y[4] = { 1.0f,1.0f,0.0f,1.0f };


	RECT_F src;		//�`�挳�؂���ʒu
	RECT_F dst;		//�`���\���ʒu


	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	water_flag = hero->GetWATERF();
	key_flag = hero->GetKEYF();
	gate_flag = hero->GetGATEF();
	ice_flag = hero->GetMICE();
	switch_flag = hero->GetSGATE();

	if (water_flag == true)	//��l����WATER�u���b�N�Ɠ��������ꍇ�Am_time�Ɏ��Ԃ��Z�b�g
	{
		m_water_time = 100;
	}
	if (m_water_time > 0) {
		m_water_time--;
		water_flag = false;		//�t���O���I�t
		hero->SetWATERF(water_flag);
		Font::StrDraw(L"���点��Γn��邩...�H", 180, 230, 20, b);//���Ԃ�0�ɂȂ�ƕ\�����I��
		if (m_water_time <= 0) {
			m_water_time = 0;
		}
	}
	if (key_flag == true)	//��l����KEY�u���b�N�Ɠ��������ꍇ�Am_time�Ɏ��Ԃ��Z�b�g
	{
		m_key_time = 100;
	}
	if (m_key_time > 0) {
		m_key_time--;
		key_flag = false;		//�t���O���I�t
		hero->SetKEYF(key_flag);
		Font::StrDraw(L"������ɓ��ꂽ", 200, 200, 20, y);//���Ԃ�0�ɂȂ�ƕ\�����I��
		if (m_key_time <= 0) {
			m_key_time = 0;
		}
	}

	if (gate_flag == true)		//���̃t���O���I���ɂȂ����玞�Ԃ��Z�b�g
	{
		m_gate_time = 100;
	}
	if (m_gate_time > 0) {
		m_gate_time--;
		gate_flag = false;		//�t���O���I�t
		hero->SetGATEF(gate_flag);
		Font::StrDraw(L"�����J����", 210, 170, 20, y);//���Ԃ�0�ɂȂ�ƕ\�����I��
		if (m_gate_time <= 0) {
			m_gate_time = 0;
		}
	}

	if (ice_flag == true)		//���̃t���O���I���ɂȂ����玞�Ԃ��Z�b�g
	{
		m_ice_time = 100;
	}
	if (m_ice_time > 0) {
		m_ice_time--;
		ice_flag = false;		//�t���O���I�t
		hero->SetMICE(ice_flag);
		Font::StrDraw(L"�X���@���o�����I", 200, 200, 20, b);//���Ԃ�0�ɂȂ�ƕ\�����I��
		if (m_ice_time <= 0) {
			m_ice_time = 0;
		}
	}

	if (switch_flag == true)
	{
		m_switch_time = 100;
	}
	if (m_switch_time > 0) {
		m_switch_time--;
		switch_flag = false;
		hero->SetSGATE(switch_flag);
		Font::StrDraw(L"�J���Ȃ�...", 200, 200, 20, c);//���Ԃ�0�ɂȂ�ƕ\�����I��		
		if (m_switch_time <= 0) {
			m_switch_time = 0;
		}
	}

}
