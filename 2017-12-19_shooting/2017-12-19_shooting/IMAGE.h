#pragma once
#include "DxLib.h"

struct �摜 {
	int ���@�g��;
	int ������;

	int ���@�w;

	int �^�C�g��;
	int �Q�[���I�[�o�[;
};
struct BGM {
	int �^�C�g��;
	int �Q�[��;
	int �Q�[���I�[�o�[;
};

void BGM�o��(BGM *BGM) {
	BGM->�^�C�g�� = LoadSoundMem(".\\BGM\\�^�C�g��.wav");
	BGM->�Q�[�� = LoadSoundMem(".\\BGM\\�Q�[��.wav");
}

void �摜�o��(�摜 *�摜) {
	//�����G
	�摜->���@�g�� = LoadGraph(".\\�摜\\���@�g��.png");
	�摜->������ = LoadGraph(".\\�摜\\������.png");
	�摜->���@�w = LoadGraph(".\\�摜\\���@�w.png");

	
	�摜->�Q�[���I�[�o�[ = LoadGraph(".\\�摜\\GameOver.jpg");
	�摜->�^�C�g��= LoadGraph(".\\�摜\\�^�C�g��.jpg");

	
}