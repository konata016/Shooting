#pragma once
#pragma warning ( disable : 4996 )	//fopen�ŕK�v

#define �}�[�W�� 10
#define �w�i���x 2

#define �������Wx 180
#define �������Wy 400

#define PL_�e�� 20
#define PL���C�t 5
#define �V���b�g_���x 10

#define �I��鎞�� 20.0

#define �G_�e�� 40
#define �G�� 20

#define PL_���a 5
#define �G_���a 10

#define �X�R�A���Wx 465

#define �A�C�e���� 5
#define �A�C�e��_���a 5

enum �e_�^�C�v {
	�e�X�g,
	��_��,��_��,��_��,��_��,
	��_��, ��_��, ��_��, ��_��
};
enum �G_�^�C�v {
	��_�d��,
	��_�d��,
	�d��_��,
	�d��_��,
	�d��_��
};
enum �s���p�^�[�� {
	�㉺��,
	���E,
	�E��,
	�㉺,
};
enum �e���p�^�[�� {
	����_1,
	����_3,
	����_8,
	�ǐ�,
	�����_��_,
	�g��,
	�Q
};
enum �A�C�e���p�^�[�� {
	�Ȃ�,
	�p���[,
	�|�C���g
};


int g_�J�E���g = 0;
extern char key[256];

//���p
double x���W����, y���W����;

#include "DXkonata.h"

struct �V���b�g {
	XY_���� ���W;
	bool �t���O = false;
	double �p�x = 0.0;

	int �p�^�[��;
	int ���x;

	int �摜;
};

struct �G�f�[�^ {
	int �G_���, �e_���;
	int �ړ��p�^�[��, �e���p�^�[��;

	int �o��, ��~, �ޏo, ����;

	int x, y;
	int ���x;
	int HP;
	
	int �A�C�e��;
};