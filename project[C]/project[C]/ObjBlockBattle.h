#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�u���b�N(�퓬)
class CObjBlockBattle : public CObj
{
public:
	CObjBlockBattle();
	~CObjBlockBattle() {};
	void Init();		//�C�j�V�����C�Y
	void Action();		//�A�N�V����
	void Draw();		//�h���[

private:
	int m_map[12][16]; //�u���b�N���
};