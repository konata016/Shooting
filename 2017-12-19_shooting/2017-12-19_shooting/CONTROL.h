#pragma once


#include "DEFINE.h"
#include "DXkonata.h"
#include "BACK.h"
#include "PL.h"
#include "ENEMY.h"
#include "SCORE.h"
#include "ITEM.h"

class コントロール {
	PL *pl;
	敵 *敵キャラ[敵数];
	背景 *バック;
	スコア *得点;
	アイテム *ドロップ[アイテム数];

	//サウンド
	int sPL_ショット;
	int s敵_ショット;
	bool sPL_フラグ;
	bool s敵_フラグ;
	bool b敵_フラグ;
	bool bPL_フラグ;

	bool seI_フラグ;

private:
	コントロール();
	~コントロール();
	void サウンド();
public:
	bool 円円_判定(double 半径1, double 半径2, double 円x1, double 円x2, double 円y1, double 円y2);
	void 当たり判定();
	void オール();
	void PL座標取得(double *x, double *y);
	void 敵座標取得(int データ, double *x, double *y);

	bool PL_HP();

	static コントロール& 静的変数() {
		static コントロール コンタクト;
		return コンタクト;
	}
};

コントロール::コントロール() {
	pl = new PL;
	バック = new 背景;
	得点 = new スコア;

	int f_オープン;
	struct 敵データ 敵データ[敵数];
	int 列 = 1, 行 = 0;
	int カウント = 0;
	int i;

	int インプット[100];
	char 文字データ[100];

	//データサイズ確保
	memset(文字データ, 0, sizeof(文字データ));
	memset(インプット, 0, sizeof(インプット));
	f_オープン = FileRead_open(".\\データ\\敵データ.csv");

	while (1) {
		カウント = 0;
		while (1) {
			//一文字取得
			文字データ[カウント] = インプット[カウント] = FileRead_getc(f_オープン);
			//カンマor改行でない場合そこまでを文字列として扱う
			if (インプット[カウント] == ',' || インプット[カウント] == '\n') {
				インプット[カウント] = '\0';

				break;
			}
			if (インプット[カウント] == EOF)goto アウト;
			カウント++;
		}
		//エクセル文割り振り
		switch (列) {
			//atoi->文をintへ変換
		case 1:敵データ[行].敵_種類 = atoi(文字データ); break;
		case 2:敵データ[行].弾_種類 = atoi(文字データ); break;
		case 3:敵データ[行].移動パターン = atoi(文字データ); break;
		case 4:敵データ[行].弾幕パターン = atoi(文字データ); break;
		case 5:敵データ[行].x = atoi(文字データ); break;
		case 6:敵データ[行].y = atoi(文字データ); break;
		case 7:敵データ[行].出現 = atoi(文字データ); break;
		case 8:敵データ[行].停止 = atoi(文字データ); break;
		case 9:敵データ[行].退出 = atoi(文字データ); break;
		case 10:敵データ[行].発射 = atoi(文字データ); break;
		case 11:敵データ[行].速度 = atoi(文字データ); break;
		case 12:敵データ[行].HP = atoi(文字データ); break;
		case 13:敵データ[行].アイテム = atoi(文字データ); break;
		default:
			break;
		}
		列++;
		//改行の場合行を増やす
		if (文字データ[カウント] == '\n')列 = 1, 行++;
		//初期化
		memset(文字データ, 0, sizeof(文字データ));
	}
アウト:
	FileRead_close(f_オープン);

	//敵
	for (i = 0; i < 敵数; i++) {
		敵キャラ[i] = new 敵(敵データ[i].敵_種類, 敵データ[i].弾_種類, 敵データ[i].移動パターン, 敵データ[i].弾幕パターン,
			敵データ[i].x, 敵データ[i].y,
			敵データ[i].出現, 敵データ[i].停止, 敵データ[i].退出, 敵データ[i].発射,
			敵データ[i].速度, 敵データ[i].HP, 敵データ[i].アイテム);
	}
	//アイテム
	for (i = 0; i < アイテム数; i++)ドロップ[i] = new アイテム;

	//サウンド読み込み
	sPL_ショット = LoadSoundMem(".\\SE\\PLse.wav");
	s敵_ショット = LoadSoundMem(".\\SE\\敵se.wav");

	sPL_フラグ = false;
	s敵_フラグ = false;
}

void コントロール::敵座標取得(int データ, double *x, double *y) {
	double 敵x, 敵y;

	敵キャラ[データ]->座標取得(&敵x, &敵y);
	*x = 敵x;
	*y = 敵y;
}
void コントロール::PL座標取得(double *x, double *y) {
	double PLx, PLy;

	pl->座標取得(&PLx, &PLy);
	*x = PLx;
	*y = PLy;
}

bool コントロール::円円_判定(double 半径1, double 半径2, double 円x1, double 円x2, double 円y1, double 円y2) {
	double 半径_判定 = 半径1 + 半径2;
	double x_判定 = 円x1 - 円x2;
	double y_判定 = 円y1 - 円y2;

	if (半径_判定 *半径_判定 >= x_判定*x_判定 + y_判定*y_判定) {
		return true;
	}
	else {
		return false;
	}
}
void コントロール::当たり判定() {
	double PLx, PLy;
	double 敵x, 敵y;
	double Ix, Iy;
	int i, f;
	int カウント;
	bool フラグ = false;

	//PL弾幕判定
	for (i = 0; i < PL_弾数; i++) {
		if (pl->ショット座標取得(i, &PLx, &PLy)) {
			for (f = 0; f < 敵数; f++) {

				if (敵キャラ[f] != NULL && !敵キャラ[f]->ブレイク_フラグ取得()) {

					敵キャラ[f]->座標取得(&敵x, &敵y);

					if (円円_判定(PL_半径, 敵_半径, PLx, 敵x, PLy, 敵y)) {

						敵キャラ[f]->セットブレイク_フラグ();
						pl->セットショット_フラグ(i, false);
						b敵_フラグ = true;		//敵消失音

						//スコア
						if (敵キャラ[f]->ブレイク_フラグ取得()) {
							得点->セット_スコア(スコア_スコア, 100);

							//アイテム
							for (カウント = 0; カウント < アイテム数; カウント++) {
								if (!ドロップ[カウント]->フラグ取得()) {
									ドロップ[カウント]->セット_フラグ(敵x, 敵y, 敵キャラ[f]->アイテム取得());
									break;
								}
							}
						}
					}
				}
			}
		}
	}

	//敵弾幕判定
	if (!pl->ダメージ_フラグ取得()) {
		pl->座標取得(&PLx, &PLy);
		for (i = 0; i < 敵数; i++) {
			if (敵キャラ[i] != NULL) {
				for (f = 0; f < 敵_弾数; f++) {
					if (敵キャラ[i]->ショット座標取得(f, &敵x, &敵y)) {

						if (円円_判定(PL_半径, 敵_半径, PLx, 敵x, PLy, 敵y)) {
							フラグ = true;

							if (フラグ) {
								pl->セットダメージ_フラグ();
								敵キャラ[i]->セットショット_フラグ(f, false);
								bPL_フラグ = true;		//被弾音
								フラグ = false;
							}
						}
					}
				}
			}
		}
	}

	//アイテム当たり判定
	for (i = 0; i < アイテム数; i++) {
		if (ドロップ[i]->フラグ取得()) {
			ドロップ[i]->座標取得(&Ix, &Iy);
			if (円円_判定(PL_半径 + 2, アイテム_半径, PLx, Ix, PLy, Iy)) {
				switch (ドロップ[i]->種類取得()) {
				case パワー:得点->セット_スコア(パワー_スコア, 1); break;
				case ポイント:得点->セット_スコア(スコア_スコア, 300); break;
				default:break;
				}
				ドロップ[i]->ブレイク();
				seI_フラグ = true;
			}
		}
	}

		

	得点->セット_スコア(ライフ_スコア, pl->ライフ取得());
}

bool コントロール::PL_HP() {
	if (pl->ライフ取得() == 0) {
		return true;
	}
	else {
		return false;
	}
}

void コントロール::オール() {
	int i;

	//サウンド初期化
	sPL_フラグ = s敵_フラグ = false;

	バック->オール();
	pl->オール();
	得点->オール();

	if (pl->サウンド())sPL_フラグ = true;

	for (i = 0; i < 敵数; i++) {
		if (敵キャラ[i] != NULL) {

			if (敵キャラ[i]->サウンド())s敵_フラグ = true;

			if (敵キャラ[i]->オール()) {
				delete 敵キャラ[i];
				敵キャラ[i] = NULL;
			}
		}
	}

	//アイテム
	for (i = 0; i < アイテム数; i++) {
		if (ドロップ[i]->フラグ取得())ドロップ[i]->オール();
	}

	当たり判定();

	サウンド();

	g_カウント++;
}
void コントロール::サウンド() {
	if (sPL_フラグ)PlaySoundMem(sPL_ショット, DX_PLAYTYPE_BACK);
	if (s敵_フラグ)PlaySoundMem(s敵_ショット, DX_PLAYTYPE_BACK);
}
コントロール::~コントロール() {
	delete pl;
	delete バック;
	delete 得点;

	for (int i = 0; i < 敵数; i++) {
		if (敵キャラ[i] != NULL)delete 敵キャラ[i];
	}
}