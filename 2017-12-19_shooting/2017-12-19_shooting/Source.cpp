#include "DxLib.h"
#include "IMAGE.h"
#include "CONTROL.h"
#include <string>

enum �X�^�[�g���
{
	�J�n,
	�I��,
	�\����
};
enum �L�����N�^�[ {
	���@�g��,
	������
};

struct �t���O {
	int �^�C�g�� = 0;
	int �L�����I�� = 0;
};

void �L�����I��(int *�L�����I��, �摜 �摜);

char key[256];

int WINAPI WinMain(HINSTANCE hI, HINSTANCE hP, LPSTR lpC, int nC)
{
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1)return -1;
	//srand(time(NULL));
	SetDrawScreen(DX_SCREEN_BACK);	//��

	//�錾

	struct �L���� �m�[�}���G[10];
	struct �e *�m�[�}���e;
	struct �t���O �t���O;
	struct �摜 �摜;
	struct ���� ����;
	struct BGM BGM;

	�R���g���[�� &�@�\ = �R���g���[��::�ÓI�ϐ�();

	�m�[�}���e = (�e*)malloc(sizeof(�e) * 300);

	std::string
		����[�\����];
	����[�J�n] = "�X�^�[�g";
	����[�I��] = "�G���h";

	//�o�b�N�F
	SetBackgroundColor(255, 255, 255);

	//�t�H���g�T�C�Y
	SetFontSize(30);

	�摜�o��(&�摜);
	BGM�o��(&BGM);

	while (ProcessMessage() == 0 && key[KEY_INPUT_ESCAPE] != 1) {
		PlaySoundMem(BGM.�^�C�g��, DX_PLAYTYPE_LOOP);
		GetHitKeyStateAll(key);
		ClearDrawScreen();

		�^�C�g�����(&�t���O, ����,�摜.�^�C�g��, �\����);
		ScreenFlip();

		WaitTimer(100);
		switch (�t���O.�^�C�g��) {
		case 0:
			//�L�����I��(&�t���O.�L�����I��, �摜);

			StopSoundMem(BGM.�^�C�g��);
			���Ԍv��(&����, �X�^�[�g);
			PlaySoundMem(BGM.�Q�[��, DX_PLAYTYPE_LOOP);

			while (ProcessMessage() == 0 && key[KEY_INPUT_ESCAPE] != 1) {
				ClearDrawScreen();
				GetHitKeyStateAll(key);
				���Ԍv��(&����, �G���h);
				���Ԍv��(&����, �C���^�[�o��);
				�����\��("", ����.�C���^�[�o��/���ԑ��x�ύX, ��, ��, 640*2-50, 0);
				if (����.�C���^�[�o�� / ���ԑ��x�ύX == �I��鎞��)break;

				�@�\.�I�[��();

				if (�@�\.PL_HP() == true)break;

				ScreenFlip();
			}

			break;
		case 1:
			goto end;
			break;
		default:
			break;
		}
		ClearDrawScreen();
		DrawExtendGraph(0, 0, 640, 480, �摜.�Q�[���I�[�o�[, TRUE);
		ScreenFlip();
		WaitTimer(500);
		WaitKey();
		StopSoundMem(BGM.�Q�[��);
		break;
	}
	end:


	//WaitKey();
	ClearDrawScreen();
	//ScreenFlip();

	DxLib_End();
	return 0;
}

void �L�����I��(int *�L�����I��, �摜 �摜) {

	bool �L�[���b�N_���� = false;
	bool �L�[���b�N_�I�� = false;

	while (ProcessMessage() != 1) {
		GetHitKeyStateAll(key);

		//�I��
		if (�L�[���b�N_�I�� == false) {
			if (key[KEY_INPUT_LEFT] == 1 || key[KEY_INPUT_RIGHT] == 1)
				*�L�����I�� = *�L�����I�� ? 0 : 1;
				�L�[���b�N_�I�� = true;
		}
		if (key[KEY_INPUT_LEFT] == 1 || key[KEY_INPUT_RIGHT] == 1)
			�L�[���b�N_�I�� = true;
		else �L�[���b�N_�I�� = false;

		if (�L�[���b�N_���� == false)
			if (key[KEY_INPUT_Z] == 1)break;
		�L�[���b�N_���� = key[KEY_INPUT_Z];

		//���
		ClearDrawScreen();
		switch (*�L�����I��) {
		case ���@�g��:
			DrawRotaGraph(220, 480 / 2, 0.3, 0, �摜.���@�w, TRUE);
			DrawRotaGraph(220, 480 / 2, 0.5, 0, �摜.���@�g��, TRUE);

			break;
		case ������:
			DrawRotaGraph(220, 480 / 2, 0.3, 0, �摜.���@�w, TRUE);
			DrawRotaGraph(220, 480 / 2, 1, 0, �摜.������, TRUE);

			break;
		default:
			break;
		}
		ScreenFlip();
	}
}

