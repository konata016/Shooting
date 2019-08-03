/****************************************************************

******************************************************************/


#pragma once
#include "DxLib.h"
#include <math.h>
#include <time.h>
#include <string>
#include <vector>

typedef void ��;

//�J���[
#define �� GetColor(255, 0, 0)
#define �I�����W GetColor(255, 165, 0)
#define ���F GetColor(255, 255, 0)
#define �� GetColor(0, 255, 0)
#define �� GetColor(0, 0, 255)
#define �� GetColor(128, 0, 128)
#define �� GetColor(255, 255, 255)
#define �� GetColor(0, 0, 0)
#define �D GetColor(169,169,169)

#define PI 3.1415926535897932384626
#define PI_int 314
#define PI_to_int 0.01

#define ���ԑ��x�ύX 1000

enum �����\��
{
	��, ��, ��,
	���[�h_end
};
enum ����
{
	��, ��,
	�E, ��,
	end
};
enum �e_���
{
	����, ���i,
};
enum ���ԑ��� {
	�X�^�[�g,
	�G���h,
	�C���^�[�o��
};

struct XY {
	int x = 0;
	int y = 0;
};
struct �T�C�Y {
	XY �T�C�Y1;
	XY �T�C�Y2;
};
struct �~ {
	XY ���W;
	int ���a;
	bool �t���O = false;
	double �p�x = 0.0;
};
struct �L���� {
	XY ���W;
	bool �t���O = false;
	double �p�x = 0.0;
};
struct �e {
	XY ���W;
	int ���x;
	int ���ˈʒu = end;
	bool �t���O = false;
	double �p�x = 0.0;
};

struct XY_���� {
	double x = 0.0;
	double y = 0.0;
};
struct �L����_���� {
	XY_���� ���W;
	bool �t���O = false;
	double �p�x = 0.0;
};
struct �e_���� {
	XY_���� ���W;
	float ���x = 0.0;
	int ���ˈʒu = end;
	bool �t���O = false;
	double �p�x = 0.0;
};

struct ���� {
	int �X�^�[�g = 0;
	int �G���h = 0;
	int �C���^�[�o�� = 0;

	int �Z�[�u = 0;
};
struct ���� {
	XY_���� pl;
	float �e��;
};

bool key_check = false;
double �p�x���Z(double �p�x);

//�L����
void ���@����(int ���x, int �摜, int *pos_x, int *pos_y) {
	int �摜x, �摜y;

	GetGraphSize(�摜, &�摜x, &�摜y);

	//�����
	if (key[KEY_INPUT_UP] == 1)
		if (*pos_y > 0)*pos_y -= 1 * ���x;
	//������
	if (key[KEY_INPUT_DOWN] == 1)
		if (*pos_y < 480 - �摜y)*pos_y += 1 * ���x;
	//�E����
	if (key[KEY_INPUT_RIGHT] == 1)
		if (*pos_x < 640 - �摜x)*pos_x += 1 * ���x;
	//������
	if (key[KEY_INPUT_LEFT] == 1)
		if (*pos_x > 0)*pos_x -= 1 * ���x;

}
void �L����_�V���b�g������(int �L����_�摜, int �e_�摜, int PLx, int PLy, �e *�e, int ���[�v) {

	XY  �L����_�T�C�Y, �e_�T�C�Y,
		�L����_�J�b�g, �e_�J�b�g;

	int i;

	//�擾
	GetGraphSize(�L����_�摜, &�L����_�T�C�Y.x, &�L����_�T�C�Y.y);
	GetGraphSize(�e_�摜, &�e_�T�C�Y.x, &�e_�T�C�Y.y);
	�L����_�J�b�g.x = �L����_�T�C�Y.x / 2;
	�L����_�J�b�g.y = �L����_�T�C�Y.y / 2;
	�e_�J�b�g.x = �e_�T�C�Y.x / 2;
	�e_�J�b�g.y = �e_�T�C�Y.y / 2;

	for (i = 0; i < ���[�v; i++) {
		if (�e[i].�t���O == false) {
			�e[i].���W.x = �L����_�J�b�g.x - �e_�J�b�g.x + PLx;
			�e[i].���W.y = �L����_�J�b�g.y - �e_�J�b�g.y + PLy;
		}
	}
}
void �V���b�g(char *key, struct �e *pl, int �e_�摜, int �e��, int ���x, ���� ����, �e_��� �e��) {
	int x, y;
	int i, j;

	GetGraphSize(�e_�摜, &x, &y);

	for (i = 0; i < �e��; i++)pl[i].���x = ���x;

	//�e����
	if (key_check == false && key[KEY_INPUT_SPACE] == 1) {
		for (i = 0; i < �e��; i++) {
			if (pl[i].�t���O == false) {
				pl[i].�t���O = true;
				break;
			}
		}
	}
	key_check = key[KEY_INPUT_SPACE];

	switch (�e��) {
	case ����:
		for (i = 0; i < �e��; i++) {
			if (pl[i].�t���O == true) {

				if (pl[i].���W.x >= 0 + x && pl[i].���W.x <= 640 - x &&
					pl[i].���W.y >= 0 + y && pl[i].���W.y <= 480 - y) {

					if (pl[i].���ˈʒu == end) {
						if (���� == ��)pl[i].���W.y -= pl[i].���x;
						if (���� == ��)pl[i].���W.y += pl[i].���x;
						if (���� == �E)pl[i].���W.x += pl[i].���x;
						if (���� == ��)pl[i].���W.x -= pl[i].���x;
					}
				}
				else {
					if (pl[i].���W.x < 0 + x)pl[i].���ˈʒu = ��;
					if (pl[i].���W.x > 640 - x)pl[i].���ˈʒu = �E;
					if (pl[i].���W.y < 0 + y)pl[i].���ˈʒu = ��;
					if (pl[i].���W.y > 480 - y)pl[i].���ˈʒu = ��;
				}
				if (pl[i].���ˈʒu == ��)pl[i].���W.x += 3, pl[i].���W.y -= 2;
				if (pl[i].���ˈʒu == �E)pl[i].���W.x -= 3, pl[i].���W.y += 2;
				if (pl[i].���ˈʒu == ��)pl[i].���W.y += 2, pl[i].���W.x += 3;
				if (pl[i].���ˈʒu == ��)pl[i].���W.y -= 2, pl[i].���W.x -= 3;

				if (key[KEY_INPUT_X] == 1) {
					for (j = 0; j < �e��; j++) {
						pl[j].�t���O = false;
						pl[j].���ˈʒu = end;
					}
				}
			}
		}
		break;
	case ���i:
		for (i = 0; i < �e��; i++) {
			if (pl[i].�t���O == true) {
				if (pl[i].���W.x >= 0 + x && pl[i].���W.x <= 640 - x &&
					pl[i].���W.y >= 0 + y && pl[i].���W.y <= 480 - y) {

					if (���� == ��)pl[i].���W.y -= pl[i].���x;
					if (���� == ��)pl[i].���W.y += pl[i].���x;
					if (���� == �E)pl[i].���W.x += pl[i].���x;
					if (���� == ��)pl[i].���W.x -= pl[i].���x;
				}
				else pl[i].�t���O = false;
			}
		}
		break;
	default:
		break;
	}
}

void ���@����_����(float ���xx, float ���xy, int �摜, double *pos_x, double *pos_y) {
	int �摜x, �摜y;

	GetGraphSize(�摜, &�摜x, &�摜y);

	//�����
	if (key[KEY_INPUT_UP] == 1)
		if (*pos_y > 0 + �摜y / 2)*pos_y -= ���xy;
	//������
	if (key[KEY_INPUT_DOWN] == 1)
		if (*pos_y < 480 - �摜y / 2)*pos_y += ���xy;
	//�E����
	if (key[KEY_INPUT_RIGHT] == 1)
		if (*pos_x < 640 - �摜x / 2)*pos_x += ���xx;
	//������
	if (key[KEY_INPUT_LEFT] == 1)
		if (*pos_x > 0 + �摜x / 2)*pos_x -= ���xx;

}

void ��](char *key, int �L����x, int �L����y, int �摜, double *�p�x) {

	if (key[KEY_INPUT_UP] == 1)*�p�x += 0.1;
	if (key[KEY_INPUT_DOWN] == 1)*�p�x -= 0.1;
	//DrawRotaGraph(�L����x, �L����y, 1.0, *�p�x, �摜, TRUE);
}
void ��]�V���b�g(char *key, �e *�e, int �e_�摜, double �p�x, int �e��) {
	int x, y;
	int i;

	GetGraphSize(�e_�摜, &x, &y);

	//�e����
	if (key_check == false && key[KEY_INPUT_SPACE] == 1) {
		for (i = 0; i < �e��; i++) {
			if (�e[i].�t���O == false) {
				�e[i].�p�x = �p�x;
				�e[i].�t���O = true;
				break;
			}
		}
	}
	key_check = key[KEY_INPUT_SPACE];

	for (i = 0; i < �e��; i++) {
		if (�e[i].�t���O == true) {
			if (�e[i].���W.x >= 0 + x && �e[i].���W.x <= 640 - x &&
				�e[i].���W.y >= 0 + y && �e[i].���W.y <= 480 - y) {

				�e[i].���W.x += (int)cos(�e[i].�p�x - PI / 2) * �e->���x;
				�e[i].���W.y += (int)sin(�e[i].�p�x - PI / 2) * �e->���x;

			}
			else �e[i].�t���O = false;
		}
	}
}


//�����蔻��
void �����蔻��_�~(�e *�e, int �e�摜, �~ *�L����, int �e��, int �~��) {
	XY *�~;
	bool ch = false;
	int i, j;
	int �摜x, �摜y;
	int �摜����;
	int count = 0;

	�~ = (XY*)malloc(sizeof(XY)*�e��*�~��);
	GetGraphSize(�e�摜, &�摜x, &�摜y);

	//�v�Z
	�摜���� = (�摜x + �摜y) / 2;
	for (i = 0; i < �e��; i++) {
		for (j = 0; j < �~��; j++) {
			�~[count].x = �e[i].���W.x - �L����[j].���W.x;
			�~[count].y = �e[i].���W.y - �L����[j].���W.y;
			count++;
		}
	}

	//�����蔻��
	for (i = 0; i < �e��*�~��; i++) {
		if (�~[i].x * �~[i].x + �~[i].y * �~[i].y >= (�L����[1].���a * �摜����) * 4) {
			DrawString(0, 0, "not�ڐG", GetColor(0, 0, 0));
			�L����[i].�t���O = true;
		}
		else �L����[i].�t���O = false;
	}
	if (�L����[i].�t���O == false) {
		ClearDrawScreen();
		DrawString(0, 0, "�ڐGnow", GetColor(0, 0, 0));
	}

	free(�~);
}
void �����蔻��m�[�}���~(int *�U��x, int *�U��y, int �U�ߔ��a, int �U�ߐ�, int ��x, int ��y, int �󂯔��a, bool *�t���O) {
	int i;
	XY *�~;

	�~ = (XY*)malloc(sizeof(XY)*�U�ߐ�);

	for (i = 0; i < �U�ߐ�; i++) {
		�~[i].x = �U��x[i] - ��x;
		�~[i].y = �U��y[i] - ��y;
	}

	for (i = 0; i < �U�ߐ�; i++) {
		if (�~[i].x * �~[i].x + �~[i].y * �~[i].y >= (�U�ߔ��a * �󂯔��a) * 4) {
			DrawString(0, 0, "not�ڐG", GetColor(0, 0, 0));
			*�t���O = false;
		}
		else *�t���O = true;
	}
	if (*�t���O == true) {
		ClearDrawScreen();
		DrawString(0, 0, "�ڐGnow", GetColor(0, 0, 0));
	}

	free(�~);
}

void �~and�~(XY *�G, XY *�L����, int �G���a, int �L�������a, int ��, bool *�t���O) {
	XY *�~;
	int i;

	�~ = (XY*)malloc(sizeof(XY)*��);

	for (i = 0; i < ��; i++) {
		�~[i].x = �G[i].x - �L����->x;
		�~[i].y = �G[i].y - �L����->y;
	}

	//�����蔻��
	for (i = 0; i < ��; i++) {
		if (�~[i].x * �~[i].x + �~[i].y * �~[i].y >= (�L�������a*�G���a) * 4) {
			*�t���O = true;
		}
		else *�t���O = false;
	}

	free(�~);
}
void �l�pand�l�p(XY *�G, XY *�L����, int �G��, int �G��, int �L������, int �L������, int ��, bool *�t���O) {
	�T�C�Y *�l�p_�G, �l�p_�L����;
	int i;

	�l�p_�G = (�T�C�Y*)malloc(sizeof(�T�C�Y) * ��);

	//���擾
	for (i = 0; i < ��; i++) {
		�l�p_�G[i].�T�C�Y1.x = �G[i].x - (�G�� / 2);
		�l�p_�G[i].�T�C�Y1.y = �G[i].y - (�G�� / 2);
		�l�p_�G[i].�T�C�Y2.x = �G[i].x + (�G�� / 2);
		�l�p_�G[i].�T�C�Y2.y = �G[i].y + (�G�� / 2);
	}
	�l�p_�L����.�T�C�Y1.x = �L����->x - (�L������ / 2);
	�l�p_�L����.�T�C�Y1.y = �L����->y - (�L������ / 2);
	�l�p_�L����.�T�C�Y2.x = �L����->x + (�L������ / 2);
	�l�p_�L����.�T�C�Y2.y = �L����->y + (�L������ / 2);

	//�����蔻��
	for (i = 0; i < ��; i++) {
		if (�l�p_�L����.�T�C�Y2.x >= �l�p_�G[i].�T�C�Y1.x &&
			�l�p_�L����.�T�C�Y1.x <= �l�p_�G[i].�T�C�Y2.x &&
			�l�p_�L����.�T�C�Y2.y >= �l�p_�G[i].�T�C�Y1.y &&
			�l�p_�L����.�T�C�Y1.y <= �l�p_�G[i].�T�C�Y2.y) {
			*�t���O = true;
		}
		else *�t���O = false;
	}
	
	free(�l�p_�G);
}
void �l�pand�~(XY *�l�p, XY *�~, int ��, int ��, int ���a, bool *�t���O) {
	�T�C�Y �l�p�T�C�Y;
	int �l�p1x�~x;
	int �l�p1y�~y;
	int �l�p1x�l�p2x�~x;
	int �l�p1y�l�p2y�~y;

	�l�p�T�C�Y.�T�C�Y1.x = �l�p->x - (�� / 2);
	�l�p�T�C�Y.�T�C�Y1.y = �l�p->y - (�� / 2);
	�l�p�T�C�Y.�T�C�Y2.x = �l�p->x + (�� / 2);
	�l�p�T�C�Y.�T�C�Y2.y = �l�p->y + (�� / 2);

	�l�p1x�~x = �l�p�T�C�Y.�T�C�Y1.x - �~->x;
	�l�p1y�~y = �l�p�T�C�Y.�T�C�Y1.y - �~->y;
	�l�p1x�l�p2x�~x = �l�p�T�C�Y.�T�C�Y1.x + �l�p�T�C�Y.�T�C�Y2.x - �~->x;
	�l�p1y�l�p2y�~y = �l�p�T�C�Y.�T�C�Y1.y + �l�p�T�C�Y.�T�C�Y2.y - �~->y;



	if ((�l�p1x�~x*�l�p1x�~x) + (�l�p1y�~y*�l�p1y�~y) < ���a*���a &&
		(�l�p1x�l�p2x�~x*�l�p1x�l�p2x�~x) + (�l�p1y�~y*�l�p1y�~y) < ���a*���a &&
		(�l�p1x�~x*�l�p1x�~x) + (�l�p1y�l�p2y�~y*�l�p1y�l�p2y�~y) < ���a*���a &&
		(�l�p1x�l�p2x�~x*�l�p1x�l�p2x�~x) + (�l�p1y�l�p2y�~y*�l�p1y�l�p2y�~y) < ���a*���a) {
		*�t���O = true;
	}
	else *�t���O = false;
}

template <typename �G_����, typename �L����_����>
void �~and�~_����(�G_���� *�G, �L����_���� *�L����, int �G���a, int �L�������a, int ��, bool *�t���O) {
	XY_���� *�~;
	int i;

	�~ = (XY_����*)malloc(sizeof(XY_����)*��);

	for (i = 0; i < ��; i++) {
		�~[i].x = �G[i].���W.x - �L����->���W.x;
		�~[i].y = �G[i].���W.y - �L����->���W.y;
	}

	//�����蔻��
	for (i = 0; i < ��; i++) {
		if (�~[i].x * �~[i].x + �~[i].y * �~[i].y > (�L�������a*�G���a) * 4) {
			*�t���O = false;
		}
		else {
			*�t���O = true;
			break;
		}
	}

	free(�~);
}

//�ǔ�
template <typename �G>
void �ǔ�(�G *�G, int �L����x, int �L����y, int ���x, int �e��) {
	
	PL�ʒu�Ď�(�G, �L����x, �L����y, ���x, �e��);
	�e�ړ�(�G, �L����x, �L����y, ���x, �e��);

}
template <typename �G>
void PL�ʒu�Ď�(�G *�G, int �L����x, int �L����y, int ���x, int �e��) {
	double ax, ay, bx, by;
	int i;

	// bx,by �����̐i��ł������ ax,ay �{���i�ނׂ����� 
	for (i = 0; i < �e��; i++) {
		bx = cos(�G[i].�p�x);
		by = sin(�G[i].�p�x);
		ax = �L����x - �G[i].���W.x + ���x;
		ay = �L����y - �G[i].���W.y + ���x;
		�G[i].�p�x += (ax * by - ay * bx < 0.0) ? +PI / 180 * 8 : -PI / 180 * 8;
	}
}
template <typename �G>
void �e�ړ�(�G *�G, int ���x, int �e��) {
	int i;
	// �ړ�����
	for (i = 0; i < �e��; i++) {
		if (�G[i].���W.x >= 0 && �G[i].���W.x <= 640 &&
			�G[i].���W.y >= 0 && �G[i].���W.y <= 480) {

			�G[i].���W.x += (int)(cos(�G[i].�p�x) * ���x);
			�G[i].���W.y += (int)(sin(�G[i].�p�x) * ���x);
		}
		else �G[i].�t���O = false;
	}
}

template <typename �G_����>
void PL�ʒu�Ď�_����(�G_���� *�G, float �L����x, float �L����y, float ���x, int �e��) {
	double ax, ay, bx, by;
	int i;

	// bx,by �����̐i��ł������ ax,ay �{���i�ނׂ����� 
	for (i = 0; i < �e��; i++) {
		bx = cos(�G[i].�p�x);
		by = sin(�G[i].�p�x);
		ax = �L����x - �G[i].���W.x + ���x;
		ay = �L����y - �G[i].���W.y + ���x;
		�G[i].�p�x += (ax * by - ay * bx < 0.0) ? +PI / 180 * 8 : -PI / 180 * 8;
	}
}
template <typename �G_����>
void �e�ړ�_����(�G_���� *�G,int �e��) {
	int i;

	// �ړ�����
	for (i = 0; i < �e��; i++) {
		if (�G[i].���W.x >= -10.0 && �G[i].���W.x <= 460 &&
			�G[i].���W.y >= -10.0 && �G[i].���W.y <= 490.0) {

			�G[i].���W.x += (double)(cos(�G[i].�p�x) * �G[i].���x);
			�G[i].���W.y += (double)(sin(�G[i].�p�x) * �G[i].���x);
		}
		else �G[i].�t���O = false;
	}
}


//�e�����
void �v���C�x�[�g���B�W����(�e *�e, �L���� *�L����, int �e�摜, int �e��, int ���x, int �\������) {
	int i;

	XY �e�T�C�Y;

	GetGraphSize(�e�摜, &�e�T�C�Y.x, &�e�T�C�Y.y);

	for (i = 0; i < �e��; i++) {
		if (�e[i].�t���O == false) {
			�e[i].�p�x = -rand() % (PI_int)* PI_to_int;

			�e[i].�t���O = true;
			�e[i].���W.x = (int)(cos(�e[i].�p�x) * �\������) + �L����->���W.x;
			�e[i].���W.y = (int)(sin(�e[i].�p�x) * �\������) + �L����->���W.y;

		}
	}

	PL�ʒu�Ď�(�e, �L����->���W.x, �L����->���W.y, ���x, �e��);

}
void �v���C�x�[�g���B�W����������(�e_���� *�e, �L����_���� *�L����, int �e�摜, int �e��, int �\������) {
	int i;

	XY �e�T�C�Y;

	GetGraphSize(�e�摜, &�e�T�C�Y.x, &�e�T�C�Y.y);

	for (i = 0; i < �e��; i++) {
		if (�e[i].�t���O == false) {
			�e[i].�p�x = -rand() % (PI_int)* PI_to_int;

			�e[i].�t���O = true;
			�e[i].���W.x = (float)(cos(�e[i].�p�x) * �\������) + �L����->���W.x;
			�e[i].���W.y = (float)(sin(�e[i].�p�x) * �\������) + �L����->���W.y;

		}
	}
}

void �e��_8�~(�e *�e, �L���� *�G,int �e��, int �\������) {
	int i = 0, f = 0;

	int �p�x = 45;
	int �J�E���g = 0;

	for (i = 0; i < �e��; i++) {
		if (�e[i].�t���O == false) {
			�e[i].�t���O = true;
			if (�J�E���g == 8)break;
			�e[i].�p�x = 45 * �J�E���g * PI / 4;
			�e[i].���W.x = (int)(cos(�e[i].�p�x) * (�\������)) + �G->���W.x;
			�e[i].���W.y = (int)(sin(�e[i].�p�x) * (�\������)) + �G->���W.y;

			�J�E���g++;
		}
	}
}
void �e��_23�~(�e *�e, �L���� *�G, int �e��, int �\������) {
	int i = 0, f = 0;
	int �J�E���g = 0;

	for (i = 0; i < �e��; i++) {
		if (�e[i].�t���O == false) {
			�e[i].�t���O = true;
			if (�J�E���g == 23)break;
			�e[i].�p�x = 30 * �J�E���g * PI/23;
			�e[i].���W.x = (int)(cos(�e[i].�p�x) * (�\������)) + �G->���W.x;
			�e[i].���W.y = (int)(sin(�e[i].�p�x) * (�\������)) + �G->���W.y;

			�J�E���g++;
		}
	}
}

void �e��_����(�e *�e, �L���� *�G, int �e��,int ���x, int �\������) {
	int i;

	XY �e�T�C�Y;
	�e��_8�~(�e, �G, �e��, �\������);

	for (i = 0; i < �e��; i++) {
		if (�e[i].�t���O == false) {

			�e[i].�t���O = true;
			�e[i].���W.x = (int)(cos(�e[i].�p�x) * �\������) + �G->���W.x;
			�e[i].���W.y = (int)(sin(�e[i].�p�x) * �\������) + �G->���W.y;

		}
	}

	PL�ʒu�Ď�(�e, �G->���W.x, �G->���W.y, ���x, �e��);

}
template <typename �e>
void �e��_3����(�e *�e, double �L����x, double �L����y, int �e��, int ���x, int �\������) {

	int i;
	int �J�E���g = 0;

	for (i = 0; i < �e��; i++) {
		if (�e[i].�t���O == false) {
			�e[i].�t���O = true;
			if (�J�E���g == 3)break;
			if (�J�E���g == 0)�e[i].�p�x = �p�x���Z(60.0);
			if (�J�E���g == 1)�e[i].�p�x = �p�x���Z(90.0);
			if (�J�E���g == 2)�e[i].�p�x = �p�x���Z(120.0);
			�e[i].���W.x = (double)(cos(�e[i].�p�x) * (�\������)) + �L����x;
			�e[i].���W.y = (double)(sin(�e[i].�p�x) * (�\������)) + �L����y;

			�J�E���g++;
		}
	}
}

//����
void ���Ԍv��(���� *����, enum ���ԑ��� ���[�h) {

	switch (���[�h){
	case �X�^�[�g:
		����->�X�^�[�g = GetNowCount();
		break;
	case �G���h:
		����->�G���h = GetNowCount();
		break;
	case �C���^�[�o��:
		����->�C���^�[�o�� = ����->�G���h - ����->�X�^�[�g;
		break;
	default:
		break;
	}
}
void �����v�Z(float ����, float ����, float *����) {
	*���� = (���� / 60) * ����;
}


void �G���W�擾(�L���� *�G,int pos_x, int pos_y) {
	�G->���W.x = pos_x;
	�G->���W.y = pos_y;
}
void �G����(enum ���� ���[�h, �L���� *�G, int ���x) {
	switch (���[�h) {
	case ��:
		�G->���W.y += ���x;
		break;
	case ��:
		�G->���W.y -= ���x;
		break;
	case �E:
		�G->���W.x += ���x;
		break;
	case ��:
		�G->���W.x -= ���x;
		break;
	}
}


//�ėp�n
void �����_��(�~ *�~, int �~��) {
	int i;

	for (i = 0; i < �~��; i++) {
		�~[i].���W.x = rand() % 640;
		�~[i].���W.y = rand() % 480;
	}
}
void �����\��(char *����, int ����, enum �����\�� ���[�h, int �F, int x, int y) {
	char ������[100];

	switch (���[�h) {
	case ��:
		sprintf_s(������, "%d%s", ����, ����);
		break;
	case ��:
		sprintf_s(������, "%.1f%s", ���� / 1000.0, ����);
		break;
	case ��:
		sprintf_s(������, "%s", ����);
		break;
	default:
		break;
	}

	DrawString(x / 2 - GetDrawStringWidth(������, strlen(������)) / 2, y, ������, �F);
}
void �摜�T�C�Y�ύX(int *�摜, int ����, int �T�C�Y, int x, int y) {
	int �摜_1x, �摜_1y;
	int �摜_2x, �摜_2y;

	GetGraphSize(*�摜, &x, &y);

	//�摜�T�C�Y����
	if (�T�C�Y != 0) {
		if (�T�C�Y <= 0)x /= -�T�C�Y, y /= -�T�C�Y;
		if (�T�C�Y > 0)x *= �T�C�Y, y *= �T�C�Y;
	}

	//�摜�z�u
	�摜_1x = (x / 2) - x;
	�摜_2x = (x / 2) + x;
	�摜_1y = (y / 2) - y;
	�摜_2y = (y / 2) + y;

	DrawExtendGraph(�摜_1x, �摜_1y, �摜_2x, �摜_2y, �摜[����], TRUE);
}
void �N���X�ύX_XY(int �摜, XY *XY, int *x, int *y, int ��) {
	XY[��].x = x[��];
	XY[��].y = y[��];
}
void �摜�J�b�g(int *�o��x, int *�o��y, int �摜, int �J�b�gx, int �J�b�gy) {
	int x, y;

	GetGraphSize(�摜, &x, &y);
	*�o��x = x / �J�b�gx;
	*�o��y = y / �J�b�gy;
}

double �p�x���Z(double �p�x) {
	return PI*(�p�x / 180);
}

template <typename �t���O>
void �^�C�g�����(�t���O *�t���O, std::string *����,int �摜, int �\����) {
#define �ő�l 1
#define �Y�� 20
	int �I���ʒu[10] = { 0 };
	int i;

	bool �L�[���b�N_���� = false;
	bool �L�[���b�N_�I�� = false;

	�I���ʒu[�t���O->�^�C�g��] = 10;

	//�L�[����
	while (ProcessMessage() == 0 && key[KEY_INPUT_ESCAPE] != 1) {
		GetHitKeyStateAll(key);
	if (�L�[���b�N_�I�� == false) {
		if (key[KEY_INPUT_UP] == 1) {
			if (�t���O->�^�C�g�� <= �\���� - 1 && �t���O->�^�C�g�� > 0) {
				�t���O->�^�C�g��--;
				�I���ʒu[�t���O->�^�C�g��] = 10;
				�I���ʒu[�t���O->�^�C�g�� + 1] = 0;
			}
		}
		if (key[KEY_INPUT_DOWN] == 1) {
			if (�t���O->�^�C�g�� < �\���� - 1 && �t���O->�^�C�g�� >= 0) {
				�t���O->�^�C�g��++;
				�I���ʒu[�t���O->�^�C�g��] = 10;
				�I���ʒu[�t���O->�^�C�g�� - 1] = 0;
			}
		}
	}
	�L�[���b�N_�I�� = key[KEY_INPUT_UP];
	�L�[���b�N_�I�� = key[KEY_INPUT_DOWN];

	if (�L�[���b�N_���� == false)
		if (key[KEY_INPUT_Z] == 1)break;
	�L�[���b�N_���� = key[KEY_INPUT_Z];

	//�\��
	ClearDrawScreen();
	DrawGraph(0, 0, �摜, TRUE);
	for (i = 0; i < �\����; i++) {
		char str[50];
		sprintf_s(str, ����[i].c_str());
		DrawString(100 + �I���ʒu[i], 200 + (i * 50), str, ��);
	}
	ScreenFlip();
	}
}