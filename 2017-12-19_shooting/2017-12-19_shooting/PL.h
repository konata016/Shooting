#pragma once
#include "DxLib.h"


#define �ᑬ 0
#define ���� 1

class PL{
public:
	PL();
	double x, y;

	int �摜;

	float ���x[2];

	bool �t���O;

	struct �V���b�g �V���b�g[PL_�e��] = { 0 };
	int N�e�摜;
	int �J�E���g;

	int ���C�t;
	bool �_���[�W_�t���O;
	bool �G���h_�t���O;
	int �_���[�W_�J�E���g = 0;

	//�T�E���h
	bool se_�V���b�g;
private:
	void ����();
	void �\��();
	void �e��();

public:
	bool �V���b�g���W�擾(int �f�[�^, double *x, double *y);
	bool �T�E���h();

	void �Z�b�g�V���b�g_�t���O(int �f�[�^, bool �t���O);
	void ���W�擾(double *x, double *y);
	
	void �Z�b�g�_���[�W_�t���O();
	bool �_���[�W_�t���O�擾();
	int ���C�t�擾();

	void �I�[��();
};

PL::PL(){
	�摜 = LoadGraph(".\\�摜\\PL.png");
	x = �������Wx;
	y = �������Wy;

	���x[�ᑬ] = 1.0f;
	���x[����] = 3.0f;

	���C�t = PL���C�t;
	�t���O = true;

	//�e�֌W
	N�e�摜 = LoadGraph(".\\�摜\\�m�[�}���e.png");
	for (int i = 0; i < PL_�e��; i++) {
		�V���b�g[i].�摜 = N�e�摜;
		�V���b�g[i].���W.x = x;
		�V���b�g[i].���W.y = y;
		�V���b�g[i].���x = �V���b�g_���x;
		�V���b�g[i].�p�x = �p�x���Z(-90.0);
	}
	�J�E���g = 0;
}
void PL::����() {
	int �؂�ւ� = 1;
	int �摜x, �摜y;

	GetGraphSize(�摜, &�摜x, &�摜y);

	//�V�t�g
	if (key[KEY_INPUT_LSHIFT] == 1) {
		�؂�ւ� = �ᑬ;
	}
	else �؂�ւ� = ����;

	//�����
	if (key[KEY_INPUT_UP] == 1) {
		if (y > 0 + �摜y / 2)y -= 1 * ���x[�؂�ւ�];
	}
	//������
	if (key[KEY_INPUT_DOWN] == 1) {
		if (y < 480 - �摜y / 2)y += 1 * ���x[�؂�ւ�];
	}
	//�E����
	if (key[KEY_INPUT_RIGHT] == 1) {
		if (x < 460 - �摜x / 2)x += 1 * ���x[�؂�ւ�];
	}
	//������
	if (key[KEY_INPUT_LEFT] == 1) {
		if (x > 0 + �摜x / 2)x -= 1 * ���x[�؂�ւ�];
	}

}
void PL::�\��() {
	int i;

	//�e
	for (i = 0; i < PL_�e��; i++) {
		if (�V���b�g[i].�t���O) {
			DrawRotaGraph((int)�V���b�g[i].���W.x, (int)�V���b�g[i].���W.y, 1, 0, �V���b�g[i].�摜, TRUE);
		}
	}

	//���C�t������ꍇ�`��
	if (�_���[�W_�t���O) {
		if (�_���[�W_�J�E���g > 20) {
			if (�_���[�W_�J�E���g % 2 == 0) {
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 140);
				DrawRotaGraph(�������Wx, �������Wy + 60 - (�_���[�W_�J�E���g - 20), 1, 0, �摜, TRUE);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);	//�`��̍ۂ̃u�����h���[�h���Z�b�g����
			}
			else {
				DrawRotaGraph(�������Wx, �������Wy + 60 - (�_���[�W_�J�E���g - 20), 1, 0, �摜, TRUE);
			}
		}
		�_���[�W_�J�E���g++;

		if (�_���[�W_�J�E���g == 80) {
			�_���[�W_�t���O = false;
			�_���[�W_�J�E���g = 0;
			x = �������Wx, y = �������Wy;
		}
	}
	else {
		DrawRotaGraph((int)x, (int)y, 1, 0, �摜, TRUE);
	}
}

void PL::�e��() {

	int i;
	se_�V���b�g = false;

	if (!�_���[�W_�t���O) {

		if (key[KEY_INPUT_Z] == 1 && �J�E���g % 5 == 0) {
			for (i = 0; i < PL_�e��; i++) {
				if (�V���b�g[i].�t���O == false) {
					�V���b�g[i].�t���O = true;
					�V���b�g[i].���W.x = x;
					�V���b�g[i].���W.y = y;
					break;
				}
			}
			se_�V���b�g = true;
		}
	}

	�e�ړ�_����(�V���b�g, PL_�e��);
}

bool PL::�T�E���h() {
	return se_�V���b�g;
}

void PL::���W�擾(double *x, double *y) {
	*x = this->x;
	*y = this->y;
	x���W���� = this->x;
	y���W���� = this->y;
}
bool PL::�V���b�g���W�擾(int �f�[�^, double *x, double *y) {
	if (�V���b�g[�f�[�^].�t���O) {
		*x = �V���b�g[�f�[�^].���W.x;
		*y = �V���b�g[�f�[�^].���W.y;
		return true;
	}
	else {
		return false;
	}
}
void PL::�Z�b�g�V���b�g_�t���O(int �f�[�^, bool �t���O) {
	�V���b�g[�f�[�^].�t���O = �t���O;
}

void PL::�Z�b�g�_���[�W_�t���O() {
	�_���[�W_�t���O = true;
	���C�t--;
}
bool PL::�_���[�W_�t���O�擾() {
	return �_���[�W_�t���O;
}
int PL::���C�t�擾() {
	return ���C�t;
}

void PL::�I�[��() {
	if (!�_���[�W_�t���O)����();
	�e��();
	�\��();

	�J�E���g++;
}