#pragma once
#include "DxLib.h"


class アイテム {
private:
	static int 画像[3];

	int 種類;

	double x, y;
	double 角度;

	bool ドロップ;
	bool フラグ;
private:
	void 動き();
	void 表示();
public:
	アイテム();
	void セット_フラグ(double x, double y, int 種類);
	bool フラグ取得();
	void ブレイク();
	void 座標取得(double *x, double *y);
	int 種類取得();
	void オール();
};

int アイテム::画像[3];

アイテム::アイテム() {
	if (画像[0] == 0) {
		画像[0] = 0;
		画像[1] = LoadGraph(".\\画像\\パワー.png");
		画像[2] = LoadGraph(".\\画像\\ポイント.png");
	}
	x = 0, y = 0;
	角度 = 0;

	ドロップ = false;
	フラグ = false;
}
void アイテム::動き() {

	if (!ドロップ && 画像[0] != 0) フラグ = true;
	else {
		y += 1.5;
	}

	//画面外フラグ処理
	if (y > 500)ブレイク();
}
void アイテム::ブレイク() {
	ドロップ = false;
	フラグ = false;
}
void アイテム::表示() {
	DrawRotaGraph((int)x, (int)y, 1, 0, 画像[種類], TRUE);
}
void アイテム::セット_フラグ(double x, double y, int 種類) {
	this->y = y - 8;
	this->x = x;
	this->種類 = 種類;
	フラグ = true;
}
bool アイテム::フラグ取得() {
	return フラグ;
}
void アイテム::座標取得(double *x, double *y) {
	*x = this->x;
	*y = this->y;
}
int アイテム::種類取得() {
	return 種類;
}
void アイテム::オール() {
	動き();
	表示();
}