#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�u���b�N���w�i
class CObjBlock : public CObj
{
public:
	CObjBlock(int map[27][55]);
	~CObjBlock() {};
	void Init();		//�C�j�V�����C�Y
	void Action();		//�A�N�V����
	void Draw();		//�h���[

	//�u���b�N�Ƃ̓����蔻��
	void BlockHit(
		float *x, float *y, bool scroll_on,
		bool*up, bool* down, bool* left, bool* right,
		float* vx, float*vy, int* bt
	);

	//��l���ƕǂ̌�������
	bool HeroBlckCrossPoint(
		float x, float y, float vx, float vy,
		float *out_px, float *out_py, float* out_len
	);


private:
	int m_map[27][55];	//�}�b�v���

	float m_scroll;		//���E�X�N���[���p

};