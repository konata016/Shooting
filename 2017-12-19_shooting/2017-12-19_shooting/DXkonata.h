/****************************************************************

******************************************************************/


#pragma once
#include "DxLib.h"
#include <math.h>
#include <time.h>
#include <string>
#include <vector>

typedef void 空;

//カラー
#define 赤 GetColor(255, 0, 0)
#define オレンジ GetColor(255, 165, 0)
#define 黄色 GetColor(255, 255, 0)
#define 緑 GetColor(0, 255, 0)
#define 青 GetColor(0, 0, 255)
#define 紫 GetColor(128, 0, 128)
#define 白 GetColor(255, 255, 255)
#define 黒 GetColor(0, 0, 0)
#define 灰 GetColor(169,169,169)

#define PI 3.1415926535897932384626
#define PI_int 314
#define PI_to_int 0.01

#define 時間速度変更 1000

enum 中央表示
{
	数, 時, 文,
	モード_end
};
enum 方向
{
	上, 下,
	右, 左,
	end
};
enum 弾_種類
{
	反射, 直進,
};
enum 時間測定 {
	スタート,
	エンド,
	インターバル
};

struct XY {
	int x = 0;
	int y = 0;
};
struct サイズ {
	XY サイズ1;
	XY サイズ2;
};
struct 円 {
	XY 座標;
	int 半径;
	bool フラグ = false;
	double 角度 = 0.0;
};
struct キャラ {
	XY 座標;
	bool フラグ = false;
	double 角度 = 0.0;
};
struct 弾 {
	XY 座標;
	int 速度;
	int 反射位置 = end;
	bool フラグ = false;
	double 角度 = 0.0;
};

struct XY_小数 {
	double x = 0.0;
	double y = 0.0;
};
struct キャラ_小数 {
	XY_小数 座標;
	bool フラグ = false;
	double 角度 = 0.0;
};
struct 弾_小数 {
	XY_小数 座標;
	float 速度 = 0.0;
	int 反射位置 = end;
	bool フラグ = false;
	double 角度 = 0.0;
};

struct 時間 {
	int スタート = 0;
	int エンド = 0;
	int インターバル = 0;

	int セーブ = 0;
};
struct 時速 {
	XY_小数 pl;
	float 弾幕;
};

bool key_check = false;
double 角度演算(double 角度);

//キャラ
void 自機操作(int 速度, int 画像, int *pos_x, int *pos_y) {
	int 画像x, 画像y;

	GetGraphSize(画像, &画像x, &画像y);

	//上入力
	if (key[KEY_INPUT_UP] == 1)
		if (*pos_y > 0)*pos_y -= 1 * 速度;
	//下入力
	if (key[KEY_INPUT_DOWN] == 1)
		if (*pos_y < 480 - 画像y)*pos_y += 1 * 速度;
	//右入力
	if (key[KEY_INPUT_RIGHT] == 1)
		if (*pos_x < 640 - 画像x)*pos_x += 1 * 速度;
	//左入力
	if (key[KEY_INPUT_LEFT] == 1)
		if (*pos_x > 0)*pos_x -= 1 * 速度;

}
void キャラ_ショット初期化(int キャラ_画像, int 弾_画像, int PLx, int PLy, 弾 *弾, int ループ) {

	XY  キャラ_サイズ, 弾_サイズ,
		キャラ_カット, 弾_カット;

	int i;

	//取得
	GetGraphSize(キャラ_画像, &キャラ_サイズ.x, &キャラ_サイズ.y);
	GetGraphSize(弾_画像, &弾_サイズ.x, &弾_サイズ.y);
	キャラ_カット.x = キャラ_サイズ.x / 2;
	キャラ_カット.y = キャラ_サイズ.y / 2;
	弾_カット.x = 弾_サイズ.x / 2;
	弾_カット.y = 弾_サイズ.y / 2;

	for (i = 0; i < ループ; i++) {
		if (弾[i].フラグ == false) {
			弾[i].座標.x = キャラ_カット.x - 弾_カット.x + PLx;
			弾[i].座標.y = キャラ_カット.y - 弾_カット.y + PLy;
		}
	}
}
void ショット(char *key, struct 弾 *pl, int 弾_画像, int 弾数, int 速度, 方向 方向, 弾_種類 弾種) {
	int x, y;
	int i, j;

	GetGraphSize(弾_画像, &x, &y);

	for (i = 0; i < 弾数; i++)pl[i].速度 = 速度;

	//弾発射
	if (key_check == false && key[KEY_INPUT_SPACE] == 1) {
		for (i = 0; i < 弾数; i++) {
			if (pl[i].フラグ == false) {
				pl[i].フラグ = true;
				break;
			}
		}
	}
	key_check = key[KEY_INPUT_SPACE];

	switch (弾種) {
	case 反射:
		for (i = 0; i < 弾数; i++) {
			if (pl[i].フラグ == true) {

				if (pl[i].座標.x >= 0 + x && pl[i].座標.x <= 640 - x &&
					pl[i].座標.y >= 0 + y && pl[i].座標.y <= 480 - y) {

					if (pl[i].反射位置 == end) {
						if (方向 == 上)pl[i].座標.y -= pl[i].速度;
						if (方向 == 下)pl[i].座標.y += pl[i].速度;
						if (方向 == 右)pl[i].座標.x += pl[i].速度;
						if (方向 == 左)pl[i].座標.x -= pl[i].速度;
					}
				}
				else {
					if (pl[i].座標.x < 0 + x)pl[i].反射位置 = 左;
					if (pl[i].座標.x > 640 - x)pl[i].反射位置 = 右;
					if (pl[i].座標.y < 0 + y)pl[i].反射位置 = 上;
					if (pl[i].座標.y > 480 - y)pl[i].反射位置 = 下;
				}
				if (pl[i].反射位置 == 左)pl[i].座標.x += 3, pl[i].座標.y -= 2;
				if (pl[i].反射位置 == 右)pl[i].座標.x -= 3, pl[i].座標.y += 2;
				if (pl[i].反射位置 == 上)pl[i].座標.y += 2, pl[i].座標.x += 3;
				if (pl[i].反射位置 == 下)pl[i].座標.y -= 2, pl[i].座標.x -= 3;

				if (key[KEY_INPUT_X] == 1) {
					for (j = 0; j < 弾数; j++) {
						pl[j].フラグ = false;
						pl[j].反射位置 = end;
					}
				}
			}
		}
		break;
	case 直進:
		for (i = 0; i < 弾数; i++) {
			if (pl[i].フラグ == true) {
				if (pl[i].座標.x >= 0 + x && pl[i].座標.x <= 640 - x &&
					pl[i].座標.y >= 0 + y && pl[i].座標.y <= 480 - y) {

					if (方向 == 上)pl[i].座標.y -= pl[i].速度;
					if (方向 == 下)pl[i].座標.y += pl[i].速度;
					if (方向 == 右)pl[i].座標.x += pl[i].速度;
					if (方向 == 左)pl[i].座標.x -= pl[i].速度;
				}
				else pl[i].フラグ = false;
			}
		}
		break;
	default:
		break;
	}
}

void 自機操作_小数(float 速度x, float 速度y, int 画像, double *pos_x, double *pos_y) {
	int 画像x, 画像y;

	GetGraphSize(画像, &画像x, &画像y);

	//上入力
	if (key[KEY_INPUT_UP] == 1)
		if (*pos_y > 0 + 画像y / 2)*pos_y -= 速度y;
	//下入力
	if (key[KEY_INPUT_DOWN] == 1)
		if (*pos_y < 480 - 画像y / 2)*pos_y += 速度y;
	//右入力
	if (key[KEY_INPUT_RIGHT] == 1)
		if (*pos_x < 640 - 画像x / 2)*pos_x += 速度x;
	//左入力
	if (key[KEY_INPUT_LEFT] == 1)
		if (*pos_x > 0 + 画像x / 2)*pos_x -= 速度x;

}

void 回転(char *key, int キャラx, int キャラy, int 画像, double *角度) {

	if (key[KEY_INPUT_UP] == 1)*角度 += 0.1;
	if (key[KEY_INPUT_DOWN] == 1)*角度 -= 0.1;
	//DrawRotaGraph(キャラx, キャラy, 1.0, *角度, 画像, TRUE);
}
void 回転ショット(char *key, 弾 *弾, int 弾_画像, double 角度, int 弾数) {
	int x, y;
	int i;

	GetGraphSize(弾_画像, &x, &y);

	//弾発射
	if (key_check == false && key[KEY_INPUT_SPACE] == 1) {
		for (i = 0; i < 弾数; i++) {
			if (弾[i].フラグ == false) {
				弾[i].角度 = 角度;
				弾[i].フラグ = true;
				break;
			}
		}
	}
	key_check = key[KEY_INPUT_SPACE];

	for (i = 0; i < 弾数; i++) {
		if (弾[i].フラグ == true) {
			if (弾[i].座標.x >= 0 + x && 弾[i].座標.x <= 640 - x &&
				弾[i].座標.y >= 0 + y && 弾[i].座標.y <= 480 - y) {

				弾[i].座標.x += (int)cos(弾[i].角度 - PI / 2) * 弾->速度;
				弾[i].座標.y += (int)sin(弾[i].角度 - PI / 2) * 弾->速度;

			}
			else 弾[i].フラグ = false;
		}
	}
}


//当たり判定
void 当たり判定_円(弾 *弾, int 弾画像, 円 *キャラ, int 弾数, int 円数) {
	XY *円;
	bool ch = false;
	int i, j;
	int 画像x, 画像y;
	int 画像平均;
	int count = 0;

	円 = (XY*)malloc(sizeof(XY)*弾数*円数);
	GetGraphSize(弾画像, &画像x, &画像y);

	//計算
	画像平均 = (画像x + 画像y) / 2;
	for (i = 0; i < 弾数; i++) {
		for (j = 0; j < 円数; j++) {
			円[count].x = 弾[i].座標.x - キャラ[j].座標.x;
			円[count].y = 弾[i].座標.y - キャラ[j].座標.y;
			count++;
		}
	}

	//あたり判定
	for (i = 0; i < 弾数*円数; i++) {
		if (円[i].x * 円[i].x + 円[i].y * 円[i].y >= (キャラ[1].半径 * 画像平均) * 4) {
			DrawString(0, 0, "not接触", GetColor(0, 0, 0));
			キャラ[i].フラグ = true;
		}
		else キャラ[i].フラグ = false;
	}
	if (キャラ[i].フラグ == false) {
		ClearDrawScreen();
		DrawString(0, 0, "接触now", GetColor(0, 0, 0));
	}

	free(円);
}
void 当たり判定ノーマル円(int *攻めx, int *攻めy, int 攻め半径, int 攻め数, int 受けx, int 受けy, int 受け半径, bool *フラグ) {
	int i;
	XY *円;

	円 = (XY*)malloc(sizeof(XY)*攻め数);

	for (i = 0; i < 攻め数; i++) {
		円[i].x = 攻めx[i] - 受けx;
		円[i].y = 攻めy[i] - 受けy;
	}

	for (i = 0; i < 攻め数; i++) {
		if (円[i].x * 円[i].x + 円[i].y * 円[i].y >= (攻め半径 * 受け半径) * 4) {
			DrawString(0, 0, "not接触", GetColor(0, 0, 0));
			*フラグ = false;
		}
		else *フラグ = true;
	}
	if (*フラグ == true) {
		ClearDrawScreen();
		DrawString(0, 0, "接触now", GetColor(0, 0, 0));
	}

	free(円);
}

void 円and円(XY *敵, XY *キャラ, int 敵半径, int キャラ半径, int 数, bool *フラグ) {
	XY *円;
	int i;

	円 = (XY*)malloc(sizeof(XY)*数);

	for (i = 0; i < 数; i++) {
		円[i].x = 敵[i].x - キャラ->x;
		円[i].y = 敵[i].y - キャラ->y;
	}

	//あたり判定
	for (i = 0; i < 数; i++) {
		if (円[i].x * 円[i].x + 円[i].y * 円[i].y >= (キャラ半径*敵半径) * 4) {
			*フラグ = true;
		}
		else *フラグ = false;
	}

	free(円);
}
void 四角and四角(XY *敵, XY *キャラ, int 敵幅, int 敵高, int キャラ幅, int キャラ高, int 数, bool *フラグ) {
	サイズ *四角_敵, 四角_キャラ;
	int i;

	四角_敵 = (サイズ*)malloc(sizeof(サイズ) * 数);

	//幅取得
	for (i = 0; i < 数; i++) {
		四角_敵[i].サイズ1.x = 敵[i].x - (敵幅 / 2);
		四角_敵[i].サイズ1.y = 敵[i].y - (敵高 / 2);
		四角_敵[i].サイズ2.x = 敵[i].x + (敵幅 / 2);
		四角_敵[i].サイズ2.y = 敵[i].y + (敵高 / 2);
	}
	四角_キャラ.サイズ1.x = キャラ->x - (キャラ幅 / 2);
	四角_キャラ.サイズ1.y = キャラ->y - (キャラ高 / 2);
	四角_キャラ.サイズ2.x = キャラ->x + (キャラ幅 / 2);
	四角_キャラ.サイズ2.y = キャラ->y + (キャラ高 / 2);

	//当たり判定
	for (i = 0; i < 数; i++) {
		if (四角_キャラ.サイズ2.x >= 四角_敵[i].サイズ1.x &&
			四角_キャラ.サイズ1.x <= 四角_敵[i].サイズ2.x &&
			四角_キャラ.サイズ2.y >= 四角_敵[i].サイズ1.y &&
			四角_キャラ.サイズ1.y <= 四角_敵[i].サイズ2.y) {
			*フラグ = true;
		}
		else *フラグ = false;
	}
	
	free(四角_敵);
}
void 四角and円(XY *四角, XY *円, int 幅, int 高, int 半径, bool *フラグ) {
	サイズ 四角サイズ;
	int 四角1x円x;
	int 四角1y円y;
	int 四角1x四角2x円x;
	int 四角1y四角2y円y;

	四角サイズ.サイズ1.x = 四角->x - (幅 / 2);
	四角サイズ.サイズ1.y = 四角->y - (高 / 2);
	四角サイズ.サイズ2.x = 四角->x + (幅 / 2);
	四角サイズ.サイズ2.y = 四角->y + (高 / 2);

	四角1x円x = 四角サイズ.サイズ1.x - 円->x;
	四角1y円y = 四角サイズ.サイズ1.y - 円->y;
	四角1x四角2x円x = 四角サイズ.サイズ1.x + 四角サイズ.サイズ2.x - 円->x;
	四角1y四角2y円y = 四角サイズ.サイズ1.y + 四角サイズ.サイズ2.y - 円->y;



	if ((四角1x円x*四角1x円x) + (四角1y円y*四角1y円y) < 半径*半径 &&
		(四角1x四角2x円x*四角1x四角2x円x) + (四角1y円y*四角1y円y) < 半径*半径 &&
		(四角1x円x*四角1x円x) + (四角1y四角2y円y*四角1y四角2y円y) < 半径*半径 &&
		(四角1x四角2x円x*四角1x四角2x円x) + (四角1y四角2y円y*四角1y四角2y円y) < 半径*半径) {
		*フラグ = true;
	}
	else *フラグ = false;
}

template <typename 敵_小数, typename キャラ_小数>
void 円and円_小数(敵_小数 *敵, キャラ_小数 *キャラ, int 敵半径, int キャラ半径, int 数, bool *フラグ) {
	XY_小数 *円;
	int i;

	円 = (XY_小数*)malloc(sizeof(XY_小数)*数);

	for (i = 0; i < 数; i++) {
		円[i].x = 敵[i].座標.x - キャラ->座標.x;
		円[i].y = 敵[i].座標.y - キャラ->座標.y;
	}

	//あたり判定
	for (i = 0; i < 数; i++) {
		if (円[i].x * 円[i].x + 円[i].y * 円[i].y > (キャラ半径*敵半径) * 4) {
			*フラグ = false;
		}
		else {
			*フラグ = true;
			break;
		}
	}

	free(円);
}

//追尾
template <typename 敵>
void 追尾(敵 *敵, int キャラx, int キャラy, int 速度, int 弾数) {
	
	PL位置監視(敵, キャラx, キャラy, 速度, 弾数);
	弾移動(敵, キャラx, キャラy, 速度, 弾数);

}
template <typename 敵>
void PL位置監視(敵 *敵, int キャラx, int キャラy, int 速度, int 弾数) {
	double ax, ay, bx, by;
	int i;

	// bx,by 自分の進んでいる方向 ax,ay 本来進むべき方向 
	for (i = 0; i < 弾数; i++) {
		bx = cos(敵[i].角度);
		by = sin(敵[i].角度);
		ax = キャラx - 敵[i].座標.x + 速度;
		ay = キャラy - 敵[i].座標.y + 速度;
		敵[i].角度 += (ax * by - ay * bx < 0.0) ? +PI / 180 * 8 : -PI / 180 * 8;
	}
}
template <typename 敵>
void 弾移動(敵 *敵, int 速度, int 弾数) {
	int i;
	// 移動する
	for (i = 0; i < 弾数; i++) {
		if (敵[i].座標.x >= 0 && 敵[i].座標.x <= 640 &&
			敵[i].座標.y >= 0 && 敵[i].座標.y <= 480) {

			敵[i].座標.x += (int)(cos(敵[i].角度) * 速度);
			敵[i].座標.y += (int)(sin(敵[i].角度) * 速度);
		}
		else 敵[i].フラグ = false;
	}
}

template <typename 敵_小数>
void PL位置監視_小数(敵_小数 *敵, float キャラx, float キャラy, float 速度, int 弾数) {
	double ax, ay, bx, by;
	int i;

	// bx,by 自分の進んでいる方向 ax,ay 本来進むべき方向 
	for (i = 0; i < 弾数; i++) {
		bx = cos(敵[i].角度);
		by = sin(敵[i].角度);
		ax = キャラx - 敵[i].座標.x + 速度;
		ay = キャラy - 敵[i].座標.y + 速度;
		敵[i].角度 += (ax * by - ay * bx < 0.0) ? +PI / 180 * 8 : -PI / 180 * 8;
	}
}
template <typename 敵_小数>
void 弾移動_小数(敵_小数 *敵,int 弾数) {
	int i;

	// 移動する
	for (i = 0; i < 弾数; i++) {
		if (敵[i].座標.x >= -10.0 && 敵[i].座標.x <= 460 &&
			敵[i].座標.y >= -10.0 && 敵[i].座標.y <= 490.0) {

			敵[i].座標.x += (double)(cos(敵[i].角度) * 敵[i].速度);
			敵[i].座標.y += (double)(sin(敵[i].角度) * 敵[i].速度);
		}
		else 敵[i].フラグ = false;
	}
}


//弾幕種類
void プライベートヴィジョン(弾 *弾, キャラ *キャラ, int 弾画像, int 弾数, int 速度, int 表示距離) {
	int i;

	XY 弾サイズ;

	GetGraphSize(弾画像, &弾サイズ.x, &弾サイズ.y);

	for (i = 0; i < 弾数; i++) {
		if (弾[i].フラグ == false) {
			弾[i].角度 = -rand() % (PI_int)* PI_to_int;

			弾[i].フラグ = true;
			弾[i].座標.x = (int)(cos(弾[i].角度) * 表示距離) + キャラ->座標.x;
			弾[i].座標.y = (int)(sin(弾[i].角度) * 表示距離) + キャラ->座標.y;

		}
	}

	PL位置監視(弾, キャラ->座標.x, キャラ->座標.y, 速度, 弾数);

}
void プライベートヴィジョン小数版(弾_小数 *弾, キャラ_小数 *キャラ, int 弾画像, int 弾数, int 表示距離) {
	int i;

	XY 弾サイズ;

	GetGraphSize(弾画像, &弾サイズ.x, &弾サイズ.y);

	for (i = 0; i < 弾数; i++) {
		if (弾[i].フラグ == false) {
			弾[i].角度 = -rand() % (PI_int)* PI_to_int;

			弾[i].フラグ = true;
			弾[i].座標.x = (float)(cos(弾[i].角度) * 表示距離) + キャラ->座標.x;
			弾[i].座標.y = (float)(sin(弾[i].角度) * 表示距離) + キャラ->座標.y;

		}
	}
}

void 弾幕_8円(弾 *弾, キャラ *敵,int 弾数, int 表示距離) {
	int i = 0, f = 0;

	int 角度 = 45;
	int カウント = 0;

	for (i = 0; i < 弾数; i++) {
		if (弾[i].フラグ == false) {
			弾[i].フラグ = true;
			if (カウント == 8)break;
			弾[i].角度 = 45 * カウント * PI / 4;
			弾[i].座標.x = (int)(cos(弾[i].角度) * (表示距離)) + 敵->座標.x;
			弾[i].座標.y = (int)(sin(弾[i].角度) * (表示距離)) + 敵->座標.y;

			カウント++;
		}
	}
}
void 弾幕_23円(弾 *弾, キャラ *敵, int 弾数, int 表示距離) {
	int i = 0, f = 0;
	int カウント = 0;

	for (i = 0; i < 弾数; i++) {
		if (弾[i].フラグ == false) {
			弾[i].フラグ = true;
			if (カウント == 23)break;
			弾[i].角度 = 30 * カウント * PI/23;
			弾[i].座標.x = (int)(cos(弾[i].角度) * (表示距離)) + 敵->座標.x;
			弾[i].座標.y = (int)(sin(弾[i].角度) * (表示距離)) + 敵->座標.y;

			カウント++;
		}
	}
}

void 弾幕_竜巻(弾 *弾, キャラ *敵, int 弾数,int 速度, int 表示距離) {
	int i;

	XY 弾サイズ;
	弾幕_8円(弾, 敵, 弾数, 表示距離);

	for (i = 0; i < 弾数; i++) {
		if (弾[i].フラグ == false) {

			弾[i].フラグ = true;
			弾[i].座標.x = (int)(cos(弾[i].角度) * 表示距離) + 敵->座標.x;
			弾[i].座標.y = (int)(sin(弾[i].角度) * 表示距離) + 敵->座標.y;

		}
	}

	PL位置監視(弾, 敵->座標.x, 敵->座標.y, 速度, 弾数);

}
template <typename 弾>
void 弾幕_3方向(弾 *弾, double キャラx, double キャラy, int 弾数, int 速度, int 表示距離) {

	int i;
	int カウント = 0;

	for (i = 0; i < 弾数; i++) {
		if (弾[i].フラグ == false) {
			弾[i].フラグ = true;
			if (カウント == 3)break;
			if (カウント == 0)弾[i].角度 = 角度演算(60.0);
			if (カウント == 1)弾[i].角度 = 角度演算(90.0);
			if (カウント == 2)弾[i].角度 = 角度演算(120.0);
			弾[i].座標.x = (double)(cos(弾[i].角度) * (表示距離)) + キャラx;
			弾[i].座標.y = (double)(sin(弾[i].角度) * (表示距離)) + キャラy;

			カウント++;
		}
	}
}

//時間
void 時間計測(時間 *時間, enum 時間測定 モード) {

	switch (モード){
	case スタート:
		時間->スタート = GetNowCount();
		break;
	case エンド:
		時間->エンド = GetNowCount();
		break;
	case インターバル:
		時間->インターバル = 時間->エンド - 時間->スタート;
		break;
	default:
		break;
	}
}
void 時速計算(float 時間, float 距離, float *時速) {
	*時速 = (時間 / 60) * 距離;
}


void 敵座標取得(キャラ *敵,int pos_x, int pos_y) {
	敵->座標.x = pos_x;
	敵->座標.y = pos_y;
}
void 敵動き(enum 方向 モード, キャラ *敵, int 速度) {
	switch (モード) {
	case 下:
		敵->座標.y += 速度;
		break;
	case 上:
		敵->座標.y -= 速度;
		break;
	case 右:
		敵->座標.x += 速度;
		break;
	case 左:
		敵->座標.x -= 速度;
		break;
	}
}


//汎用系
void ランダム(円 *円, int 円数) {
	int i;

	for (i = 0; i < 円数; i++) {
		円[i].座標.x = rand() % 640;
		円[i].座標.y = rand() % 480;
	}
}
void 中央表示(char *文字, int 数字, enum 中央表示 モード, int 色, int x, int y) {
	char 文字列[100];

	switch (モード) {
	case 数:
		sprintf_s(文字列, "%d%s", 数字, 文字);
		break;
	case 時:
		sprintf_s(文字列, "%.1f%s", 数字 / 1000.0, 文字);
		break;
	case 文:
		sprintf_s(文字列, "%s", 文字);
		break;
	default:
		break;
	}

	DrawString(x / 2 - GetDrawStringWidth(文字列, strlen(文字列)) / 2, y, 文字列, 色);
}
void 画像サイズ変更(int *画像, int 数字, int サイズ, int x, int y) {
	int 画像_1x, 画像_1y;
	int 画像_2x, 画像_2y;

	GetGraphSize(*画像, &x, &y);

	//画像サイズ調整
	if (サイズ != 0) {
		if (サイズ <= 0)x /= -サイズ, y /= -サイズ;
		if (サイズ > 0)x *= サイズ, y *= サイズ;
	}

	//画像配置
	画像_1x = (x / 2) - x;
	画像_2x = (x / 2) + x;
	画像_1y = (y / 2) - y;
	画像_2y = (y / 2) + y;

	DrawExtendGraph(画像_1x, 画像_1y, 画像_2x, 画像_2y, 画像[数字], TRUE);
}
void クラス変更_XY(int 画像, XY *XY, int *x, int *y, int 数) {
	XY[数].x = x[数];
	XY[数].y = y[数];
}
void 画像カット(int *出力x, int *出力y, int 画像, int カットx, int カットy) {
	int x, y;

	GetGraphSize(画像, &x, &y);
	*出力x = x / カットx;
	*出力y = y / カットy;
}

double 角度演算(double 角度) {
	return PI*(角度 / 180);
}

template <typename フラグ>
void タイトル画面(フラグ *フラグ, std::string *文字,int 画像, int 表示数) {
#define 最大値 1
#define ズレ 20
	int 選択位置[10] = { 0 };
	int i;

	bool キーロック_決定 = false;
	bool キーロック_選択 = false;

	選択位置[フラグ->タイトル] = 10;

	//キー入力
	while (ProcessMessage() == 0 && key[KEY_INPUT_ESCAPE] != 1) {
		GetHitKeyStateAll(key);
	if (キーロック_選択 == false) {
		if (key[KEY_INPUT_UP] == 1) {
			if (フラグ->タイトル <= 表示数 - 1 && フラグ->タイトル > 0) {
				フラグ->タイトル--;
				選択位置[フラグ->タイトル] = 10;
				選択位置[フラグ->タイトル + 1] = 0;
			}
		}
		if (key[KEY_INPUT_DOWN] == 1) {
			if (フラグ->タイトル < 表示数 - 1 && フラグ->タイトル >= 0) {
				フラグ->タイトル++;
				選択位置[フラグ->タイトル] = 10;
				選択位置[フラグ->タイトル - 1] = 0;
			}
		}
	}
	キーロック_選択 = key[KEY_INPUT_UP];
	キーロック_選択 = key[KEY_INPUT_DOWN];

	if (キーロック_決定 == false)
		if (key[KEY_INPUT_Z] == 1)break;
	キーロック_決定 = key[KEY_INPUT_Z];

	//表示
	ClearDrawScreen();
	DrawGraph(0, 0, 画像, TRUE);
	for (i = 0; i < 表示数; i++) {
		char str[50];
		sprintf_s(str, 文字[i].c_str());
		DrawString(100 + 選択位置[i], 200 + (i * 50), str, 赤);
	}
	ScreenFlip();
	}
}