#pragma once
#include "DxLib.h"


class �A�C�e�� {
private:
	static int �摜[3];

	int ���;

	double x, y;
	double �p�x;

	bool �h���b�v;
	bool �t���O;
private:
	void ����();
	void �\��();
public:
	�A�C�e��();
	void �Z�b�g_�t���O(double x, double y, int ���);
	bool �t���O�擾();
	void �u���C�N();
	void ���W�擾(double *x, double *y);
	int ��ގ擾();
	void �I�[��();
};

int �A�C�e��::�摜[3];

�A�C�e��::�A�C�e��() {
	if (�摜[0] == 0) {
		�摜[0] = 0;
		�摜[1] = LoadGraph(".\\�摜\\�p���[.png");
		�摜[2] = LoadGraph(".\\�摜\\�|�C���g.png");
	}
	x = 0, y = 0;
	�p�x = 0;

	�h���b�v = false;
	�t���O = false;
}
void �A�C�e��::����() {

	if (!�h���b�v && �摜[0] != 0) �t���O = true;
	else {
		y += 1.5;
	}

	//��ʊO�t���O����
	if (y > 500)�u���C�N();
}
void �A�C�e��::�u���C�N() {
	�h���b�v = false;
	�t���O = false;
}
void �A�C�e��::�\��() {
	DrawRotaGraph((int)x, (int)y, 1, 0, �摜[���], TRUE);
}
void �A�C�e��::�Z�b�g_�t���O(double x, double y, int ���) {
	this->y = y - 8;
	this->x = x;
	this->��� = ���;
	�t���O = true;
}
bool �A�C�e��::�t���O�擾() {
	return �t���O;
}
void �A�C�e��::���W�擾(double *x, double *y) {
	*x = this->x;
	*y = this->y;
}
int �A�C�e��::��ގ擾() {
	return ���;
}
void �A�C�e��::�I�[��() {
	����();
	�\��();
}