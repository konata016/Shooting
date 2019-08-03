#pragma once
#include "DxLib.h"
#include "CONTROL.h"
#include "PL.h"


class �G {
	
private:
	double x, y;
	double �p�x = 0;
	int �G_�摜;
	int ����[4];

	int HP;
	int �A�C�e��;

	int �o��, ��~, �ޏo, ����;

	bool �G���h_�t���O = false;
	bool �u���C�N_�t���O = false;
	bool �V���b�g_�t���O = false;

	int �G_���;
	int �e_���;

	int �ړ��p�^�[��;
	int �e���p�^�[��;

	struct �V���b�g �V���b�g[�G_�e��];
	int �V���b�g_�J�E���g;

	//�T�E���h
	bool se_�V���b�g = false;

	int �J�E���g = 0;

private:
	void ����();
	void �e��();
	void �\��();
	bool ��O����();
public:
	void �Z�b�g�u���C�N_�t���O();
	bool �u���C�N_�t���O�擾();

	bool �T�E���h();
	bool �I�[��();
	bool �V���b�g���W�擾(int �f�[�^, double *x, double *y);
	void �Z�b�g�V���b�g_�t���O(int �f�[�^, bool �t���O);

	int �e��ގ擾();

	int �A�C�e���擾();

	void ���W�擾(double *x, double *y);
	�G(int �G_���, int �e_���, int �ړ��p�^�[��, int �e���p�^�[��,
		int x, int y,
		int �o��, int ��~, int �ޏo, int ����,
		int �e���x, int HP, int �A�C�e��);

	~�G();
};

�G::�G(int �G_���, int �e_���, int �ړ��p�^�[��, int �e���p�^�[��,
	int x, int y,
	int �o��, int ��~, int �ޏo, int ����,
	int �e���x, int HP, int �A�C�e��) {
	int �e_�摜 = 0;
	this->HP = HP;
	this->�A�C�e�� = �A�C�e��;

	this->x = x;
	this->y = y;

	this->�G_��� = �G_���;
	this->�e_��� = �e_���;

	this->�ړ��p�^�[�� = �ړ��p�^�[��;
	this->�e���p�^�[�� = �e���p�^�[��;

	//����
	this->�o�� = �o��;
	this->��~ = ��~;
	this->�ޏo = �ޏo;
	this->���� = ����;

	//�G�摜
	switch (�G_���) {
	case ��_�d��:�G_�摜 = LoadGraph(".\\�摜\\��_�d��.png"); break;
	case ��_�d��:�G_�摜 = LoadGraph(".\\�摜\\��_�d��.png"); break;
	case �d��_��:�G_�摜 = LoadGraph(".\\�摜\\�d��_��.png"); break;
	case �d��_��:�G_�摜 = LoadGraph(".\\�摜\\�d��_��.png"); break;
	case �d��_��:�G_�摜 = LoadGraph(".\\�摜\\�d��_��.png"); break;
	default:break;
	}
	//�e�摜
	switch (�e_���) {
	case �e�X�g:�e_�摜 = LoadGraph(".\\�摜\\�m�[�}���e.png"); break;
	case ��_��:�e_�摜 = LoadGraph(".\\�摜\\��_��.png"); break;
	case ��_��:�e_�摜 = LoadGraph(".\\�摜\\��_��.png"); break;
	case ��_��:�e_�摜 = LoadGraph(".\\�摜\\��_��.png"); break;
	case ��_��:�e_�摜 = LoadGraph(".\\�摜\\�m�[�}���e.png"); break;
	case ��_��:�e_�摜 = LoadGraph(".\\�摜\\��_��.png"); break;
	case ��_��:�e_�摜 = LoadGraph(".\\�摜\\��_��.png"); break;
	case ��_��:�e_�摜 = LoadGraph(".\\�摜\\��_��.png"); break;
	case ��_��:�e_�摜 = LoadGraph(".\\�摜\\��_��.png"); break;
	default:
		break;
	}
	//����
	int ������;
	int �o��x, �o��y;
		������ = LoadGraph(".\\�摜\\����.png");
		�摜�J�b�g(&�o��x, &�o��y, ������, 4, 1);
		LoadDivGraph(".\\�摜\\����.png", 4, 4, 1, �o��x, �o��y, ����);

	//������
	for (int i = 0; i < �G_�e��; i++) {
		�V���b�g[i].�摜 = �e_�摜;
		�V���b�g[i].���W.x = x;
		�V���b�g[i].���W.y = y;
		�V���b�g[i].�p�^�[�� = �e���p�^�[��;
		�V���b�g[i].���x = �e���x;
		�V���b�g[i].�p�x = �p�x���Z(90.0);
	}

	�V���b�g_�J�E���g = 0;
	�p�x = 0;

	�G���h_�t���O = false;
	�u���C�N_�t���O = false;
	�V���b�g_�t���O = false;
}
inline �G::~�G()
{
}
void �G::����() {
	
	if (!�u���C�N_�t���O) {
		switch (�ړ��p�^�[��) {
		case �㉺��:
			if (�o�� < g_�J�E���g && g_�J�E���g < ��~)y += 2;
			else if (g_�J�E���g > �ޏo)y -= 2;
			break;
		case ���E:
			if (�o�� < g_�J�E���g && g_�J�E���g < ��~)x += 2;
			else if (g_�J�E���g > �ޏo)x += 2;
			break;
		case �E��:
			if (�o�� < g_�J�E���g && g_�J�E���g < ��~)x -= 2;
			else if (g_�J�E���g > �ޏo)x -= 2;
			break;
		case �㉺:
			if (�o�� < g_�J�E���g && g_�J�E���g < ��~)y += 2;
			else if (g_�J�E���g > �ޏo)y += 2;
			break;
		default:
			break;
		}

		//��ʊO����
		if (g_�J�E���g >= ��~) {
			if (��O����())�u���C�N_�t���O = true;
		}
	}
}
bool �G::��O����() {
	if (x <= 0 && x > 640 && y <= 0 && y > 480) return true;
	else return false;
}

void �G::�e��() {
	int i, c = 0;
	int �e�t���O_�J�E���g = 0;
	double PLx, PLy;
	double ax, ay, bx, by;

	if (���� == g_�J�E���g) �V���b�g_�t���O = true;
	PLx = x���W����, PLy = y���W����;

	if (�V���b�g_�t���O) {
		se_�V���b�g = false;
		if (!�u���C�N_�t���O) {
			//PL�ʒu�Ď�
			if (�V���b�g_�J�E���g == 10 && �e���p�^�[��==�ǐ�) {
				for (i = 0; i < �G_�e��; i++) {
					bx = cos(�V���b�g[i].�p�x);
					by = sin(�V���b�g[i].�p�x);
					ax = PLx - �V���b�g[i].���W.x;
					ay = PLy - �V���b�g[i].���W.y;
					�V���b�g[i].�p�x += (ax * by - ay * bx < 0.0) ? +PI / 180 * 8 : -PI / 180 * 8;
				}
			}
			switch (�e���p�^�[��) {
			case ����_1:
				if (�V���b�g_�J�E���g % 10 == 0 && �V���b�g_�J�E���g <= �G_�e��) {
					for (i = 0; i < �G_�e��; i++) {
						if (�V���b�g[i].�t���O == false) {
							�V���b�g[i].�t���O = true;
							�V���b�g[i].���W.x = x;
							�V���b�g[i].���W.y = y;
							break;
						}
					}
					se_�V���b�g = true;
				}
				break;
			case ����_3:
				if (�V���b�g_�J�E���g % 10 == 0 && �V���b�g_�J�E���g <= �G_�e��) {
					for (i = 0; i < �G_�e��; i++) {
						if (�V���b�g[i].�t���O == false) {
							�V���b�g[i].�t���O = true;
							if (c == 0)�V���b�g[i].�p�x = �p�x���Z(60.0);
							if (c == 1)�V���b�g[i].�p�x = �p�x���Z(90.0);
							if (c == 2)�V���b�g[i].�p�x = �p�x���Z(120.0);
							�V���b�g[i].���W.x = (double)(cos(�V���b�g[i].�p�x) * (30)) + x;
							�V���b�g[i].���W.y = (double)(sin(�V���b�g[i].�p�x) * (30)) + y;
							c++;
							if (c == 3) {
								c = 0;
								break;
							}
						}
					}
					se_�V���b�g = true;
				}
				break;
			case ����_8:
				if (�V���b�g_�J�E���g % 10 == 0 && �V���b�g_�J�E���g <= �G_�e��) {
					for (i = 0; i < �G_�e��; i++) {
						if (�V���b�g[i].�t���O == false) {
							�V���b�g[i].�t���O = true;
							if (c == 0)�V���b�g[i].�p�x = �p�x���Z(0.0);
							if (c == 1)�V���b�g[i].�p�x = �p�x���Z(45.0);
							if (c == 2)�V���b�g[i].�p�x = �p�x���Z(90.0);
							if (c == 3)�V���b�g[i].�p�x = �p�x���Z(135.0);
							if (c == 4)�V���b�g[i].�p�x = �p�x���Z(180.0);
							if (c == 5)�V���b�g[i].�p�x = �p�x���Z(225.0);
							if (c == 6)�V���b�g[i].�p�x = �p�x���Z(270.0);
							if (c == 7)�V���b�g[i].�p�x = �p�x���Z(315.0);
							�V���b�g[i].���W.x = (double)(cos(�V���b�g[i].�p�x) * (30)) + x;
							�V���b�g[i].���W.y = (double)(sin(�V���b�g[i].�p�x) * (30)) + y;
							c++;
							if (c == 8) {
								c = 0;
								break;
							}
						}
					}
					se_�V���b�g = true;
				}
				break;
			case �ǐ�:
				if (�V���b�g_�J�E���g % 10 == 0 && �V���b�g_�J�E���g <= �G_�e��) {
					for (i = 0; i < �G_�e��; i++) {
						if (�V���b�g[i].�t���O == false) {
							�V���b�g[i].�t���O = true;
							�V���b�g[i].���W.x = (double)(cos(�V���b�g[i].�p�x) * (30)) + x;
							�V���b�g[i].���W.y = (double)(sin(�V���b�g[i].�p�x) * (30)) + y;
							break;
						}
						se_�V���b�g = true;
					}
				}
				break;
			default:
				break;
			}

			//�ړ�
			�e�ړ�_����(�V���b�g, �G_�e��);
			for (i = 0; i < �G_�e��; i++) {
				if (�V���b�g[i].�t���O) �e�t���O_�J�E���g++;
			}
		}

		//�G�ޏo����
		if (�e�t���O_�J�E���g == 0 && �u���C�N_�t���O) �G���h_�t���O = true;
		�V���b�g_�J�E���g++;
	}
}

void �G::�\��() {
	int �A�j�� = 0;

	//�e
	for (int i = 0; i < �G_�e��; i++) {
		if (�V���b�g[i].�t���O) {
			DrawRotaGraph((int)�V���b�g[i].���W.x, (int)�V���b�g[i].���W.y, 1,
				�V���b�g[i].�p�x, �V���b�g[i].�摜, TRUE);
		}
	}

	//�G
	if (!�G���h_�t���O) {
		DrawRotaGraph((int)x, (int)y, 1, 0, �G_�摜, TRUE);
	}
	//����
	if (�G���h_�t���O&&�A�j�� != 4) {
		�A�j�� = �J�E���g % 40 / 10;
		DrawRotaGraph((int)x, (int)y, 1, 0, ����[�A�j��], TRUE);
	}
}

bool �G::�T�E���h(){
	return se_�V���b�g;
}
void �G::���W�擾(double *x, double *y) {
	*x = this->x;
	*y = this->y;
}
bool �G::�V���b�g���W�擾(int �f�[�^, double *x, double *y) {
	if (�V���b�g[�f�[�^].�t���O) {
		*x = �V���b�g[�f�[�^].���W.x;
		*y = �V���b�g[�f�[�^].���W.y;
		return true;
	}
	else {
		return false;
	}
}
void �G::�Z�b�g�V���b�g_�t���O(int �f�[�^, bool �t���O) {
	�V���b�g[�f�[�^].�t���O = �t���O;
}

int �G::�e��ގ擾() {
	return �e_���;
}

void �G::�Z�b�g�u���C�N_�t���O() {
	if (HP == 0)�u���C�N_�t���O = true;
	HP--;
}
bool �G::�u���C�N_�t���O�擾() {
	return �u���C�N_�t���O;
}

int �G::�A�C�e���擾() {
	return �A�C�e��;
}

bool �G::�I�[��() {
	����();
	�e��();
	�\��();

	�J�E���g++;

	return �G���h_�t���O;
}