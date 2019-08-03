#pragma once


#include "DEFINE.h"
#include "DXkonata.h"
#include "BACK.h"
#include "PL.h"
#include "ENEMY.h"
#include "SCORE.h"
#include "ITEM.h"

class �R���g���[�� {
	PL *pl;
	�G *�G�L����[�G��];
	�w�i *�o�b�N;
	�X�R�A *���_;
	�A�C�e�� *�h���b�v[�A�C�e����];

	//�T�E���h
	int sPL_�V���b�g;
	int s�G_�V���b�g;
	bool sPL_�t���O;
	bool s�G_�t���O;
	bool b�G_�t���O;
	bool bPL_�t���O;

	bool seI_�t���O;

private:
	�R���g���[��();
	~�R���g���[��();
	void �T�E���h();
public:
	bool �~�~_����(double ���a1, double ���a2, double �~x1, double �~x2, double �~y1, double �~y2);
	void �����蔻��();
	void �I�[��();
	void PL���W�擾(double *x, double *y);
	void �G���W�擾(int �f�[�^, double *x, double *y);

	bool PL_HP();

	static �R���g���[��& �ÓI�ϐ�() {
		static �R���g���[�� �R���^�N�g;
		return �R���^�N�g;
	}
};

�R���g���[��::�R���g���[��() {
	pl = new PL;
	�o�b�N = new �w�i;
	���_ = new �X�R�A;

	int f_�I�[�v��;
	struct �G�f�[�^ �G�f�[�^[�G��];
	int �� = 1, �s = 0;
	int �J�E���g = 0;
	int i;

	int �C���v�b�g[100];
	char �����f�[�^[100];

	//�f�[�^�T�C�Y�m��
	memset(�����f�[�^, 0, sizeof(�����f�[�^));
	memset(�C���v�b�g, 0, sizeof(�C���v�b�g));
	f_�I�[�v�� = FileRead_open(".\\�f�[�^\\�G�f�[�^.csv");

	while (1) {
		�J�E���g = 0;
		while (1) {
			//�ꕶ���擾
			�����f�[�^[�J�E���g] = �C���v�b�g[�J�E���g] = FileRead_getc(f_�I�[�v��);
			//�J���}or���s�łȂ��ꍇ�����܂ł𕶎���Ƃ��Ĉ���
			if (�C���v�b�g[�J�E���g] == ',' || �C���v�b�g[�J�E���g] == '\n') {
				�C���v�b�g[�J�E���g] = '\0';

				break;
			}
			if (�C���v�b�g[�J�E���g] == EOF)goto �A�E�g;
			�J�E���g++;
		}
		//�G�N�Z��������U��
		switch (��) {
			//atoi->����int�֕ϊ�
		case 1:�G�f�[�^[�s].�G_��� = atoi(�����f�[�^); break;
		case 2:�G�f�[�^[�s].�e_��� = atoi(�����f�[�^); break;
		case 3:�G�f�[�^[�s].�ړ��p�^�[�� = atoi(�����f�[�^); break;
		case 4:�G�f�[�^[�s].�e���p�^�[�� = atoi(�����f�[�^); break;
		case 5:�G�f�[�^[�s].x = atoi(�����f�[�^); break;
		case 6:�G�f�[�^[�s].y = atoi(�����f�[�^); break;
		case 7:�G�f�[�^[�s].�o�� = atoi(�����f�[�^); break;
		case 8:�G�f�[�^[�s].��~ = atoi(�����f�[�^); break;
		case 9:�G�f�[�^[�s].�ޏo = atoi(�����f�[�^); break;
		case 10:�G�f�[�^[�s].���� = atoi(�����f�[�^); break;
		case 11:�G�f�[�^[�s].���x = atoi(�����f�[�^); break;
		case 12:�G�f�[�^[�s].HP = atoi(�����f�[�^); break;
		case 13:�G�f�[�^[�s].�A�C�e�� = atoi(�����f�[�^); break;
		default:
			break;
		}
		��++;
		//���s�̏ꍇ�s�𑝂₷
		if (�����f�[�^[�J�E���g] == '\n')�� = 1, �s++;
		//������
		memset(�����f�[�^, 0, sizeof(�����f�[�^));
	}
�A�E�g:
	FileRead_close(f_�I�[�v��);

	//�G
	for (i = 0; i < �G��; i++) {
		�G�L����[i] = new �G(�G�f�[�^[i].�G_���, �G�f�[�^[i].�e_���, �G�f�[�^[i].�ړ��p�^�[��, �G�f�[�^[i].�e���p�^�[��,
			�G�f�[�^[i].x, �G�f�[�^[i].y,
			�G�f�[�^[i].�o��, �G�f�[�^[i].��~, �G�f�[�^[i].�ޏo, �G�f�[�^[i].����,
			�G�f�[�^[i].���x, �G�f�[�^[i].HP, �G�f�[�^[i].�A�C�e��);
	}
	//�A�C�e��
	for (i = 0; i < �A�C�e����; i++)�h���b�v[i] = new �A�C�e��;

	//�T�E���h�ǂݍ���
	sPL_�V���b�g = LoadSoundMem(".\\SE\\PLse.wav");
	s�G_�V���b�g = LoadSoundMem(".\\SE\\�Gse.wav");

	sPL_�t���O = false;
	s�G_�t���O = false;
}

void �R���g���[��::�G���W�擾(int �f�[�^, double *x, double *y) {
	double �Gx, �Gy;

	�G�L����[�f�[�^]->���W�擾(&�Gx, &�Gy);
	*x = �Gx;
	*y = �Gy;
}
void �R���g���[��::PL���W�擾(double *x, double *y) {
	double PLx, PLy;

	pl->���W�擾(&PLx, &PLy);
	*x = PLx;
	*y = PLy;
}

bool �R���g���[��::�~�~_����(double ���a1, double ���a2, double �~x1, double �~x2, double �~y1, double �~y2) {
	double ���a_���� = ���a1 + ���a2;
	double x_���� = �~x1 - �~x2;
	double y_���� = �~y1 - �~y2;

	if (���a_���� *���a_���� >= x_����*x_���� + y_����*y_����) {
		return true;
	}
	else {
		return false;
	}
}
void �R���g���[��::�����蔻��() {
	double PLx, PLy;
	double �Gx, �Gy;
	double Ix, Iy;
	int i, f;
	int �J�E���g;
	bool �t���O = false;

	//PL�e������
	for (i = 0; i < PL_�e��; i++) {
		if (pl->�V���b�g���W�擾(i, &PLx, &PLy)) {
			for (f = 0; f < �G��; f++) {

				if (�G�L����[f] != NULL && !�G�L����[f]->�u���C�N_�t���O�擾()) {

					�G�L����[f]->���W�擾(&�Gx, &�Gy);

					if (�~�~_����(PL_���a, �G_���a, PLx, �Gx, PLy, �Gy)) {

						�G�L����[f]->�Z�b�g�u���C�N_�t���O();
						pl->�Z�b�g�V���b�g_�t���O(i, false);
						b�G_�t���O = true;		//�G������

						//�X�R�A
						if (�G�L����[f]->�u���C�N_�t���O�擾()) {
							���_->�Z�b�g_�X�R�A(�X�R�A_�X�R�A, 100);

							//�A�C�e��
							for (�J�E���g = 0; �J�E���g < �A�C�e����; �J�E���g++) {
								if (!�h���b�v[�J�E���g]->�t���O�擾()) {
									�h���b�v[�J�E���g]->�Z�b�g_�t���O(�Gx, �Gy, �G�L����[f]->�A�C�e���擾());
									break;
								}
							}
						}
					}
				}
			}
		}
	}

	//�G�e������
	if (!pl->�_���[�W_�t���O�擾()) {
		pl->���W�擾(&PLx, &PLy);
		for (i = 0; i < �G��; i++) {
			if (�G�L����[i] != NULL) {
				for (f = 0; f < �G_�e��; f++) {
					if (�G�L����[i]->�V���b�g���W�擾(f, &�Gx, &�Gy)) {

						if (�~�~_����(PL_���a, �G_���a, PLx, �Gx, PLy, �Gy)) {
							�t���O = true;

							if (�t���O) {
								pl->�Z�b�g�_���[�W_�t���O();
								�G�L����[i]->�Z�b�g�V���b�g_�t���O(f, false);
								bPL_�t���O = true;		//��e��
								�t���O = false;
							}
						}
					}
				}
			}
		}
	}

	//�A�C�e�������蔻��
	for (i = 0; i < �A�C�e����; i++) {
		if (�h���b�v[i]->�t���O�擾()) {
			�h���b�v[i]->���W�擾(&Ix, &Iy);
			if (�~�~_����(PL_���a + 2, �A�C�e��_���a, PLx, Ix, PLy, Iy)) {
				switch (�h���b�v[i]->��ގ擾()) {
				case �p���[:���_->�Z�b�g_�X�R�A(�p���[_�X�R�A, 1); break;
				case �|�C���g:���_->�Z�b�g_�X�R�A(�X�R�A_�X�R�A, 300); break;
				default:break;
				}
				�h���b�v[i]->�u���C�N();
				seI_�t���O = true;
			}
		}
	}

		

	���_->�Z�b�g_�X�R�A(���C�t_�X�R�A, pl->���C�t�擾());
}

bool �R���g���[��::PL_HP() {
	if (pl->���C�t�擾() == 0) {
		return true;
	}
	else {
		return false;
	}
}

void �R���g���[��::�I�[��() {
	int i;

	//�T�E���h������
	sPL_�t���O = s�G_�t���O = false;

	�o�b�N->�I�[��();
	pl->�I�[��();
	���_->�I�[��();

	if (pl->�T�E���h())sPL_�t���O = true;

	for (i = 0; i < �G��; i++) {
		if (�G�L����[i] != NULL) {

			if (�G�L����[i]->�T�E���h())s�G_�t���O = true;

			if (�G�L����[i]->�I�[��()) {
				delete �G�L����[i];
				�G�L����[i] = NULL;
			}
		}
	}

	//�A�C�e��
	for (i = 0; i < �A�C�e����; i++) {
		if (�h���b�v[i]->�t���O�擾())�h���b�v[i]->�I�[��();
	}

	�����蔻��();

	�T�E���h();

	g_�J�E���g++;
}
void �R���g���[��::�T�E���h() {
	if (sPL_�t���O)PlaySoundMem(sPL_�V���b�g, DX_PLAYTYPE_BACK);
	if (s�G_�t���O)PlaySoundMem(s�G_�V���b�g, DX_PLAYTYPE_BACK);
}
�R���g���[��::~�R���g���[��() {
	delete pl;
	delete �o�b�N;
	delete ���_;

	for (int i = 0; i < �G��; i++) {
		if (�G�L����[i] != NULL)delete �G�L����[i];
	}
}