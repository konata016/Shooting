#pragma once
#pragma warning ( disable : 4996 )	//fopenで必要

#define マージン 10
#define 背景速度 2

#define 初期座標x 180
#define 初期座標y 400

#define PL_弾数 20
#define PLライフ 5
#define ショット_速度 10

#define 終わる時間 20.0

#define 敵_弾数 40
#define 敵数 20

#define PL_半径 5
#define 敵_半径 10

#define スコア座標x 465

#define アイテム数 5
#define アイテム_半径 5

enum 弾_タイプ {
	テスト,
	小_赤,小_青,小_緑,小_黄,
	大_赤, 大_青, 大_緑, 大_黄
};
enum 敵_タイプ {
	小_妖精,
	大_妖精,
	妖精_青,
	妖精_赤,
	妖精_花
};
enum 行動パターン {
	上下上,
	左右,
	右左,
	上下,
};
enum 弾幕パターン {
	方向_1,
	方向_3,
	方向_8,
	追跡,
	ランダム_,
	波紋,
	渦
};
enum アイテムパターン {
	なし,
	パワー,
	ポイント
};


int g_カウント = 0;
extern char key[256];

//非常用
double x座標入手, y座標入手;

#include "DXkonata.h"

struct ショット {
	XY_小数 座標;
	bool フラグ = false;
	double 角度 = 0.0;

	int パターン;
	int 速度;

	int 画像;
};

struct 敵データ {
	int 敵_種類, 弾_種類;
	int 移動パターン, 弾幕パターン;

	int 出現, 停止, 退出, 発射;

	int x, y;
	int 速度;
	int HP;
	
	int アイテム;
};