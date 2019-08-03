#pragma once
#include "DxLib.h"

struct 画像 {
	int 魔法使い;
	int ちくわ;

	int 魔法陣;

	int タイトル;
	int ゲームオーバー;
};
struct BGM {
	int タイトル;
	int ゲーム;
	int ゲームオーバー;
};

void BGM出力(BGM *BGM) {
	BGM->タイトル = LoadSoundMem(".\\BGM\\タイトル.wav");
	BGM->ゲーム = LoadSoundMem(".\\BGM\\ゲーム.wav");
}

void 画像出力(画像 *画像) {
	//立ち絵
	画像->魔法使い = LoadGraph(".\\画像\\魔法使い.png");
	画像->ちくわ = LoadGraph(".\\画像\\ちくわ.png");
	画像->魔法陣 = LoadGraph(".\\画像\\魔法陣.png");

	
	画像->ゲームオーバー = LoadGraph(".\\画像\\GameOver.jpg");
	画像->タイトル= LoadGraph(".\\画像\\タイトル.jpg");

	
}