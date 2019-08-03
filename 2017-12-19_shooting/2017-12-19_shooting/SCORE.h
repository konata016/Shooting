#pragma once
#include "DxLib.h"
#include "DEFINE.h"

enum スコアデータ {
	ハイ_スコア,
	スコア_スコア,
	ライフ_スコア,
	パワー_スコア
};

class スコア {
private:
	int ハイスコア;
	int スコア_;
	int ライフ;
	int P;

	int ボード[3];
	int 数字ボード[10];
private:
	void 表示();
public:
	void セット_スコア(スコアデータ データ, int ポイント);
	int スコア取得(スコアデータ データ);
	void オール();
	スコア();
};
スコア::スコア() {
	ハイスコア = 0;
	スコア_ = 0;
	ライフ = 0;
	P = 0;
}
void スコア::セット_スコア(スコアデータ データ, int ポイント) {
	switch (データ) {
	case ハイ_スコア:ハイスコア += ポイント; break;
	case スコア_スコア:スコア_ += ポイント; break;
	case ライフ_スコア:ライフ = ポイント; break;
	case パワー_スコア:P += ポイント; break;
	default:break;
	}
}
int スコア::スコア取得(スコアデータ データ) {
	switch (データ) {
	case ハイ_スコア:return ハイスコア; break;
	case スコア_スコア:return スコア_; break;
	case ライフ_スコア:return ライフ; break;
	case パワー_スコア:return P; break;
	default:break;
	}
	return -1;
}
void スコア::表示() {
	char 文字[100];
	int 数字;
	//スコア文字
	DrawGraph(スコア座標x, 10, ボード[0], TRUE);
	DrawGraph(スコア座標x, 70, ボード[1], TRUE);
	DrawGraph(スコア座標x, 140, ボード[2], TRUE);

	数字 = sprintf(文字, "%d", ハイスコア);	
	DrawString(スコア座標x, 35, 文字, 黒);
	数字 = sprintf(文字, "%d", スコア_);
	DrawString(スコア座標x, 115, 文字, 黒);
	数字 = sprintf(文字, "%d", ライフ);
	DrawString(スコア座標x, 255, 文字, 黒);
	数字 = sprintf(文字, "%d", P);
	DrawString(スコア座標x, 335, 文字, 黒);

	DrawString(スコア座標x, 5, "ハイスコア", 黒);
	DrawString(スコア座標x, 85, "スコア", 黒);
	DrawString(スコア座標x, 225, "ライフ", 黒);
	DrawString(スコア座標x, 305, "パワー", 黒);
}
void スコア::オール() {
	表示();
}