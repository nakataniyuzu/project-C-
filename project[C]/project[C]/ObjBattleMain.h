#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;


//�I�u�W�F�N�g�F���j���[
class CObjBattleMain :public CObj
{
public:
	CObjBattleMain() {};
	~CObjBattleMain() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[
private:
	int hero_hp;
	int hero_mp;
	int magic_type;

};
