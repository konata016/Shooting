#pragma once
#include "DxLib.h"
#include "DEFINE.h"

enum �X�R�A�f�[�^ {
	�n�C_�X�R�A,
	�X�R�A_�X�R�A,
	���C�t_�X�R�A,
	�p���[_�X�R�A
};

class �X�R�A {
private:
	int �n�C�X�R�A;
	int �X�R�A_;
	int ���C�t;
	int P;

	int �{�[�h[3];
	int �����{�[�h[10];
private:
	void �\��();
public:
	void �Z�b�g_�X�R�A(�X�R�A�f�[�^ �f�[�^, int �|�C���g);
	int �X�R�A�擾(�X�R�A�f�[�^ �f�[�^);
	void �I�[��();
	�X�R�A();
};
�X�R�A::�X�R�A() {
	�n�C�X�R�A = 0;
	�X�R�A_ = 0;
	���C�t = 0;
	P = 0;
}
void �X�R�A::�Z�b�g_�X�R�A(�X�R�A�f�[�^ �f�[�^, int �|�C���g) {
	switch (�f�[�^) {
	case �n�C_�X�R�A:�n�C�X�R�A += �|�C���g; break;
	case �X�R�A_�X�R�A:�X�R�A_ += �|�C���g; break;
	case ���C�t_�X�R�A:���C�t = �|�C���g; break;
	case �p���[_�X�R�A:P += �|�C���g; break;
	default:break;
	}
}
int �X�R�A::�X�R�A�擾(�X�R�A�f�[�^ �f�[�^) {
	switch (�f�[�^) {
	case �n�C_�X�R�A:return �n�C�X�R�A; break;
	case �X�R�A_�X�R�A:return �X�R�A_; break;
	case ���C�t_�X�R�A:return ���C�t; break;
	case �p���[_�X�R�A:return P; break;
	default:break;
	}
	return -1;
}
void �X�R�A::�\��() {
	char ����[100];
	int ����;
	//�X�R�A����
	DrawGraph(�X�R�A���Wx, 10, �{�[�h[0], TRUE);
	DrawGraph(�X�R�A���Wx, 70, �{�[�h[1], TRUE);
	DrawGraph(�X�R�A���Wx, 140, �{�[�h[2], TRUE);

	���� = sprintf(����, "%d", �n�C�X�R�A);	
	DrawString(�X�R�A���Wx, 35, ����, ��);
	���� = sprintf(����, "%d", �X�R�A_);
	DrawString(�X�R�A���Wx, 115, ����, ��);
	���� = sprintf(����, "%d", ���C�t);
	DrawString(�X�R�A���Wx, 255, ����, ��);
	���� = sprintf(����, "%d", P);
	DrawString(�X�R�A���Wx, 335, ����, ��);

	DrawString(�X�R�A���Wx, 5, "�n�C�X�R�A", ��);
	DrawString(�X�R�A���Wx, 85, "�X�R�A", ��);
	DrawString(�X�R�A���Wx, 225, "���C�t", ��);
	DrawString(�X�R�A���Wx, 305, "�p���[", ��);
}
void �X�R�A::�I�[��() {
	�\��();
}