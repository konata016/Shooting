#pragma once
#include "DxLib.h"
#include "DEFINE.h"

class �w�i{
public:

	double x,y;
	int �摜;

private:
	void �\��();
	void ����();
public:
	void �I�[��();
	�w�i();
};

�w�i::�w�i(){
	�摜 = LoadGraph(".\\�摜\\�w�i1.png");

	x = y = �}�[�W��;

}
void �w�i::�\��() {
	DrawGraph((int)x, (int)y, �摜, FALSE);
	DrawGraph((int)x, (int)y - 460, �摜, FALSE);

	if (y == 460 + �}�[�W��)y = 10;
}
void �w�i::����() {
	y += �w�i���x;
}
void �w�i::�I�[��(){
	�\��();
	����();
}
