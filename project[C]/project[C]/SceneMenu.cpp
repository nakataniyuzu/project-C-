//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneMenu.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneMenu::CSceneMenu()
{

}

//�f�X�g���N�^
CSceneMenu::~CSceneMenu()
{

}

//�Q�[�����j���[���������\�b�h
void CSceneMenu::InitScene()
{
	CObjMenu* p = new CObjMenu();
	Objs::InsertObj(p, OBJ_TITLE, 1);
}

//�Q�[�����j���[���s�����\�b�h
void CSceneMenu::Scene()
{

}