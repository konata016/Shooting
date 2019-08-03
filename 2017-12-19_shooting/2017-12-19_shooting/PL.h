#pragma once
#include "DxLib.h"


#define 低速 0
#define 高速 1

class PL{
public:
	PL();
	double x, y;

	int 画像;

	float 速度[2];

	bool フラグ;

	struct ショット ショット[PL_弾数] = { 0 };
	int N弾画像;
	int カウント;

	int ライフ;
	bool ダメージ_フラグ;
	bool エンド_フラグ;
	int ダメージ_カウント = 0;

	//サウンド
	bool se_ショット;
private:
	void 動き();
	void 表示();
	void 弾幕();

public:
	bool ショット座標取得(int データ, double *x, double *y);
	bool サウンド();

	void セットショット_フラグ(int データ, bool フラグ);
	void 座標取得(double *x, double *y);
	
	void セットダメージ_フラグ();
	bool ダメージ_フラグ取得();
	int ライフ取得();

	void オール();
};

PL::PL(){
	画像 = LoadGraph(".\\画像\\PL.png");
	x = 初期座標x;
	y = 初期座標y;

	速度[低速] = 1.0f;
	速度[高速] = 3.0f;

	ライフ = PLライフ;
	フラグ = true;

	//弾関係
	N弾画像 = LoadGraph(".\\画像\\ノーマル弾.png");
	for (int i = 0; i < PL_弾数; i++) {
		ショット[i].画像 = N弾画像;
		ショット[i].座標.x = x;
		ショット[i].座標.y = y;
		ショット[i].速度 = ショット_速度;
		ショット[i].角度 = 角度演算(-90.0);
	}
	カウント = 0;
}
void PL::動き() {
	int 切り替え = 1;
	int 画像x, 画像y;

	GetGraphSize(画像, &画像x, &画像y);

	//シフト
	if (key[KEY_INPUT_LSHIFT] == 1) {
		切り替え = 低速;
	}
	else 切り替え = 高速;

	//上入力
	if (key[KEY_INPUT_UP] == 1) {
		if (y > 0 + 画像y / 2)y -= 1 * 速度[切り替え];
	}
	//下入力
	if (key[KEY_INPUT_DOWN] == 1) {
		if (y < 480 - 画像y / 2)y += 1 * 速度[切り替え];
	}
	//右入力
	if (key[KEY_INPUT_RIGHT] == 1) {
		if (x < 460 - 画像x / 2)x += 1 * 速度[切り替え];
	}
	//左入力
	if (key[KEY_INPUT_LEFT] == 1) {
		if (x > 0 + 画像x / 2)x -= 1 * 速度[切り替え];
	}

}
void PL::表示() {
	int i;

	//弾
	for (i = 0; i < PL_弾数; i++) {
		if (ショット[i].フラグ) {
			DrawRotaGraph((int)ショット[i].座標.x, (int)ショット[i].座標.y, 1, 0, ショット[i].画像, TRUE);
		}
	}

	//ライフがある場合描写
	if (ダメージ_フラグ) {
		if (ダメージ_カウント > 20) {
			if (ダメージ_カウント % 2 == 0) {
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 140);
				DrawRotaGraph(初期座標x, 初期座標y + 60 - (ダメージ_カウント - 20), 1, 0, 画像, TRUE);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);	//描画の際のブレンドモードをセットする
			}
			else {
				DrawRotaGraph(初期座標x, 初期座標y + 60 - (ダメージ_カウント - 20), 1, 0, 画像, TRUE);
			}
		}
		ダメージ_カウント++;

		if (ダメージ_カウント == 80) {
			ダメージ_フラグ = false;
			ダメージ_カウント = 0;
			x = 初期座標x, y = 初期座標y;
		}
	}
	else {
		DrawRotaGraph((int)x, (int)y, 1, 0, 画像, TRUE);
	}
}

void PL::弾幕() {

	int i;
	se_ショット = false;

	if (!ダメージ_フラグ) {

		if (key[KEY_INPUT_Z] == 1 && カウント % 5 == 0) {
			for (i = 0; i < PL_弾数; i++) {
				if (ショット[i].フラグ == false) {
					ショット[i].フラグ = true;
					ショット[i].座標.x = x;
					ショット[i].座標.y = y;
					break;
				}
			}
			se_ショット = true;
		}
	}

	弾移動_小数(ショット, PL_弾数);
}

bool PL::サウンド() {
	return se_ショット;
}

void PL::座標取得(double *x, double *y) {
	*x = this->x;
	*y = this->y;
	x座標入手 = this->x;
	y座標入手 = this->y;
}
bool PL::ショット座標取得(int データ, double *x, double *y) {
	if (ショット[データ].フラグ) {
		*x = ショット[データ].座標.x;
		*y = ショット[データ].座標.y;
		return true;
	}
	else {
		return false;
	}
}
void PL::セットショット_フラグ(int データ, bool フラグ) {
	ショット[データ].フラグ = フラグ;
}

void PL::セットダメージ_フラグ() {
	ダメージ_フラグ = true;
	ライフ--;
}
bool PL::ダメージ_フラグ取得() {
	return ダメージ_フラグ;
}
int PL::ライフ取得() {
	return ライフ;
}

void PL::オール() {
	if (!ダメージ_フラグ)動き();
	弾幕();
	表示();

	カウント++;
}