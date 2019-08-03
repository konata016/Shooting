#pragma once
#include "DxLib.h"
#include "CONTROL.h"
#include "PL.h"


class 敵 {
	
private:
	double x, y;
	double 角度 = 0;
	int 敵_画像;
	int 爆発[4];

	int HP;
	int アイテム;

	int 出現, 停止, 退出, 発射;

	bool エンド_フラグ = false;
	bool ブレイク_フラグ = false;
	bool ショット_フラグ = false;

	int 敵_種類;
	int 弾_種類;

	int 移動パターン;
	int 弾幕パターン;

	struct ショット ショット[敵_弾数];
	int ショット_カウント;

	//サウンド
	bool se_ショット = false;

	int カウント = 0;

private:
	void 動き();
	void 弾幕();
	void 表示();
	bool 場外判定();
public:
	void セットブレイク_フラグ();
	bool ブレイク_フラグ取得();

	bool サウンド();
	bool オール();
	bool ショット座標取得(int データ, double *x, double *y);
	void セットショット_フラグ(int データ, bool フラグ);

	int 弾種類取得();

	int アイテム取得();

	void 座標取得(double *x, double *y);
	敵(int 敵_種類, int 弾_種類, int 移動パターン, int 弾幕パターン,
		int x, int y,
		int 出現, int 停止, int 退出, int 発射,
		int 弾速度, int HP, int アイテム);

	~敵();
};

敵::敵(int 敵_種類, int 弾_種類, int 移動パターン, int 弾幕パターン,
	int x, int y,
	int 出現, int 停止, int 退出, int 発射,
	int 弾速度, int HP, int アイテム) {
	int 弾_画像 = 0;
	this->HP = HP;
	this->アイテム = アイテム;

	this->x = x;
	this->y = y;

	this->敵_種類 = 敵_種類;
	this->弾_種類 = 弾_種類;

	this->移動パターン = 移動パターン;
	this->弾幕パターン = 弾幕パターン;

	//時間
	this->出現 = 出現;
	this->停止 = 停止;
	this->退出 = 退出;
	this->発射 = 発射;

	//敵画像
	switch (敵_種類) {
	case 小_妖精:敵_画像 = LoadGraph(".\\画像\\小_妖精.png"); break;
	case 大_妖精:敵_画像 = LoadGraph(".\\画像\\大_妖精.png"); break;
	case 妖精_青:敵_画像 = LoadGraph(".\\画像\\妖精_青.png"); break;
	case 妖精_赤:敵_画像 = LoadGraph(".\\画像\\妖精_赤.png"); break;
	case 妖精_花:敵_画像 = LoadGraph(".\\画像\\妖精_花.png"); break;
	default:break;
	}
	//弾画像
	switch (弾_種類) {
	case テスト:弾_画像 = LoadGraph(".\\画像\\ノーマル弾.png"); break;
	case 小_赤:弾_画像 = LoadGraph(".\\画像\\小_赤.png"); break;
	case 小_青:弾_画像 = LoadGraph(".\\画像\\小_青.png"); break;
	case 小_緑:弾_画像 = LoadGraph(".\\画像\\小_緑.png"); break;
	case 小_黄:弾_画像 = LoadGraph(".\\画像\\ノーマル弾.png"); break;
	case 大_赤:弾_画像 = LoadGraph(".\\画像\\大_赤.png"); break;
	case 大_青:弾_画像 = LoadGraph(".\\画像\\大_青.png"); break;
	case 大_緑:弾_画像 = LoadGraph(".\\画像\\大_緑.png"); break;
	case 大_黄:弾_画像 = LoadGraph(".\\画像\\大_黄.png"); break;
	default:
		break;
	}
	//爆発
	int 爆発元;
	int 出力x, 出力y;
		爆発元 = LoadGraph(".\\画像\\爆発.png");
		画像カット(&出力x, &出力y, 爆発元, 4, 1);
		LoadDivGraph(".\\画像\\爆発.png", 4, 4, 1, 出力x, 出力y, 爆発);

	//初期化
	for (int i = 0; i < 敵_弾数; i++) {
		ショット[i].画像 = 弾_画像;
		ショット[i].座標.x = x;
		ショット[i].座標.y = y;
		ショット[i].パターン = 弾幕パターン;
		ショット[i].速度 = 弾速度;
		ショット[i].角度 = 角度演算(90.0);
	}

	ショット_カウント = 0;
	角度 = 0;

	エンド_フラグ = false;
	ブレイク_フラグ = false;
	ショット_フラグ = false;
}
inline 敵::~敵()
{
}
void 敵::動き() {
	
	if (!ブレイク_フラグ) {
		switch (移動パターン) {
		case 上下上:
			if (出現 < g_カウント && g_カウント < 停止)y += 2;
			else if (g_カウント > 退出)y -= 2;
			break;
		case 左右:
			if (出現 < g_カウント && g_カウント < 停止)x += 2;
			else if (g_カウント > 退出)x += 2;
			break;
		case 右左:
			if (出現 < g_カウント && g_カウント < 停止)x -= 2;
			else if (g_カウント > 退出)x -= 2;
			break;
		case 上下:
			if (出現 < g_カウント && g_カウント < 停止)y += 2;
			else if (g_カウント > 退出)y += 2;
			break;
		default:
			break;
		}

		//画面外判定
		if (g_カウント >= 停止) {
			if (場外判定())ブレイク_フラグ = true;
		}
	}
}
bool 敵::場外判定() {
	if (x <= 0 && x > 640 && y <= 0 && y > 480) return true;
	else return false;
}

void 敵::弾幕() {
	int i, c = 0;
	int 弾フラグ_カウント = 0;
	double PLx, PLy;
	double ax, ay, bx, by;

	if (発射 == g_カウント) ショット_フラグ = true;
	PLx = x座標入手, PLy = y座標入手;

	if (ショット_フラグ) {
		se_ショット = false;
		if (!ブレイク_フラグ) {
			//PL位置監視
			if (ショット_カウント == 10 && 弾幕パターン==追跡) {
				for (i = 0; i < 敵_弾数; i++) {
					bx = cos(ショット[i].角度);
					by = sin(ショット[i].角度);
					ax = PLx - ショット[i].座標.x;
					ay = PLy - ショット[i].座標.y;
					ショット[i].角度 += (ax * by - ay * bx < 0.0) ? +PI / 180 * 8 : -PI / 180 * 8;
				}
			}
			switch (弾幕パターン) {
			case 方向_1:
				if (ショット_カウント % 10 == 0 && ショット_カウント <= 敵_弾数) {
					for (i = 0; i < 敵_弾数; i++) {
						if (ショット[i].フラグ == false) {
							ショット[i].フラグ = true;
							ショット[i].座標.x = x;
							ショット[i].座標.y = y;
							break;
						}
					}
					se_ショット = true;
				}
				break;
			case 方向_3:
				if (ショット_カウント % 10 == 0 && ショット_カウント <= 敵_弾数) {
					for (i = 0; i < 敵_弾数; i++) {
						if (ショット[i].フラグ == false) {
							ショット[i].フラグ = true;
							if (c == 0)ショット[i].角度 = 角度演算(60.0);
							if (c == 1)ショット[i].角度 = 角度演算(90.0);
							if (c == 2)ショット[i].角度 = 角度演算(120.0);
							ショット[i].座標.x = (double)(cos(ショット[i].角度) * (30)) + x;
							ショット[i].座標.y = (double)(sin(ショット[i].角度) * (30)) + y;
							c++;
							if (c == 3) {
								c = 0;
								break;
							}
						}
					}
					se_ショット = true;
				}
				break;
			case 方向_8:
				if (ショット_カウント % 10 == 0 && ショット_カウント <= 敵_弾数) {
					for (i = 0; i < 敵_弾数; i++) {
						if (ショット[i].フラグ == false) {
							ショット[i].フラグ = true;
							if (c == 0)ショット[i].角度 = 角度演算(0.0);
							if (c == 1)ショット[i].角度 = 角度演算(45.0);
							if (c == 2)ショット[i].角度 = 角度演算(90.0);
							if (c == 3)ショット[i].角度 = 角度演算(135.0);
							if (c == 4)ショット[i].角度 = 角度演算(180.0);
							if (c == 5)ショット[i].角度 = 角度演算(225.0);
							if (c == 6)ショット[i].角度 = 角度演算(270.0);
							if (c == 7)ショット[i].角度 = 角度演算(315.0);
							ショット[i].座標.x = (double)(cos(ショット[i].角度) * (30)) + x;
							ショット[i].座標.y = (double)(sin(ショット[i].角度) * (30)) + y;
							c++;
							if (c == 8) {
								c = 0;
								break;
							}
						}
					}
					se_ショット = true;
				}
				break;
			case 追跡:
				if (ショット_カウント % 10 == 0 && ショット_カウント <= 敵_弾数) {
					for (i = 0; i < 敵_弾数; i++) {
						if (ショット[i].フラグ == false) {
							ショット[i].フラグ = true;
							ショット[i].座標.x = (double)(cos(ショット[i].角度) * (30)) + x;
							ショット[i].座標.y = (double)(sin(ショット[i].角度) * (30)) + y;
							break;
						}
						se_ショット = true;
					}
				}
				break;
			default:
				break;
			}

			//移動
			弾移動_小数(ショット, 敵_弾数);
			for (i = 0; i < 敵_弾数; i++) {
				if (ショット[i].フラグ) 弾フラグ_カウント++;
			}
		}

		//敵退出条件
		if (弾フラグ_カウント == 0 && ブレイク_フラグ) エンド_フラグ = true;
		ショット_カウント++;
	}
}

void 敵::表示() {
	int アニメ = 0;

	//弾
	for (int i = 0; i < 敵_弾数; i++) {
		if (ショット[i].フラグ) {
			DrawRotaGraph((int)ショット[i].座標.x, (int)ショット[i].座標.y, 1,
				ショット[i].角度, ショット[i].画像, TRUE);
		}
	}

	//敵
	if (!エンド_フラグ) {
		DrawRotaGraph((int)x, (int)y, 1, 0, 敵_画像, TRUE);
	}
	//爆発
	if (エンド_フラグ&&アニメ != 4) {
		アニメ = カウント % 40 / 10;
		DrawRotaGraph((int)x, (int)y, 1, 0, 爆発[アニメ], TRUE);
	}
}

bool 敵::サウンド(){
	return se_ショット;
}
void 敵::座標取得(double *x, double *y) {
	*x = this->x;
	*y = this->y;
}
bool 敵::ショット座標取得(int データ, double *x, double *y) {
	if (ショット[データ].フラグ) {
		*x = ショット[データ].座標.x;
		*y = ショット[データ].座標.y;
		return true;
	}
	else {
		return false;
	}
}
void 敵::セットショット_フラグ(int データ, bool フラグ) {
	ショット[データ].フラグ = フラグ;
}

int 敵::弾種類取得() {
	return 弾_種類;
}

void 敵::セットブレイク_フラグ() {
	if (HP == 0)ブレイク_フラグ = true;
	HP--;
}
bool 敵::ブレイク_フラグ取得() {
	return ブレイク_フラグ;
}

int 敵::アイテム取得() {
	return アイテム;
}

bool 敵::オール() {
	動き();
	弾幕();
	表示();

	カウント++;

	return エンド_フラグ;
}