#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�}�N��
#define FLOOR1 01
#define ITEM 10

//�V�[���F�Q�[���^�C�g��
class CSceneMain :public CScene
{
	public:
		CSceneMain();
		~CSceneMain();
		void InitScene();//�Q�[�����C���̏��������\�b�h
		void Scene();    //�Q�[�����C���̎��s�����\�b�h
	private:
		/*int m_map[10][10];	//�}�b�v���*/
};
