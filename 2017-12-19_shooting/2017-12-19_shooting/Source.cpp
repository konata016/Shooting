#include "DxLib.h"
#include "IMAGE.h"
#include "CONTROL.h"
#include <string>

enum スタート画面
{
	開始,
	終了,
	表示数
};
enum キャラクター {
	魔法使い,
	ちくわ
};

struct フラグ {
	int タイトル = 0;
	int キャラ選択 = 0;
};

void キャラ選択(int *キャラ選択, 画像 画像);

char key[256];

int WINAPI WinMain(HINSTANCE hI, HINSTANCE hP, LPSTR lpC, int nC)
{
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1)return -1;
	//srand(time(NULL));
	SetDrawScreen(DX_SCREEN_BACK);	//約束

	//宣言

	struct キャラ ノーマル敵[10];
	struct 弾 *ノーマル弾;
	struct フラグ フラグ;
	struct 画像 画像;
	struct 時間 時間;
	struct BGM BGM;

	コントロール &機能 = コントロール::静的変数();

	ノーマル弾 = (弾*)malloc(sizeof(弾) * 300);

	std::string
		文字[表示数];
	文字[開始] = "スタート";
	文字[終了] = "エンド";

	//バック色
	SetBackgroundColor(255, 255, 255);

	//フォントサイズ
	SetFontSize(30);

	画像出力(&画像);
	BGM出力(&BGM);

	while (ProcessMessage() == 0 && key[KEY_INPUT_ESCAPE] != 1) {
		PlaySoundMem(BGM.タイトル, DX_PLAYTYPE_LOOP);
		GetHitKeyStateAll(key);
		ClearDrawScreen();

		タイトル画面(&フラグ, 文字,画像.タイトル, 表示数);
		ScreenFlip();

		WaitTimer(100);
		switch (フラグ.タイトル) {
		case 0:
			//キャラ選択(&フラグ.キャラ選択, 画像);

			StopSoundMem(BGM.タイトル);
			時間計測(&時間, スタート);
			PlaySoundMem(BGM.ゲーム, DX_PLAYTYPE_LOOP);

			while (ProcessMessage() == 0 && key[KEY_INPUT_ESCAPE] != 1) {
				ClearDrawScreen();
				GetHitKeyStateAll(key);
				時間計測(&時間, エンド);
				時間計測(&時間, インターバル);
				中央表示("", 時間.インターバル/時間速度変更, 数, 黒, 640*2-50, 0);
				if (時間.インターバル / 時間速度変更 == 終わる時間)break;

				機能.オール();

				if (機能.PL_HP() == true)break;

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
		DrawExtendGraph(0, 0, 640, 480, 画像.ゲームオーバー, TRUE);
		ScreenFlip();
		WaitTimer(500);
		WaitKey();
		StopSoundMem(BGM.ゲーム);
		break;
	}
	end:


	//WaitKey();
	ClearDrawScreen();
	//ScreenFlip();

	DxLib_End();
	return 0;
}

void キャラ選択(int *キャラ選択, 画像 画像) {

	bool キーロック_決定 = false;
	bool キーロック_選択 = false;

	while (ProcessMessage() != 1) {
		GetHitKeyStateAll(key);

		//選択
		if (キーロック_選択 == false) {
			if (key[KEY_INPUT_LEFT] == 1 || key[KEY_INPUT_RIGHT] == 1)
				*キャラ選択 = *キャラ選択 ? 0 : 1;
				キーロック_選択 = true;
		}
		if (key[KEY_INPUT_LEFT] == 1 || key[KEY_INPUT_RIGHT] == 1)
			キーロック_選択 = true;
		else キーロック_選択 = false;

		if (キーロック_決定 == false)
			if (key[KEY_INPUT_Z] == 1)break;
		キーロック_決定 = key[KEY_INPUT_Z];

		//画面
		ClearDrawScreen();
		switch (*キャラ選択) {
		case 魔法使い:
			DrawRotaGraph(220, 480 / 2, 0.3, 0, 画像.魔法陣, TRUE);
			DrawRotaGraph(220, 480 / 2, 0.5, 0, 画像.魔法使い, TRUE);

			break;
		case ちくわ:
			DrawRotaGraph(220, 480 / 2, 0.3, 0, 画像.魔法陣, TRUE);
			DrawRotaGraph(220, 480 / 2, 1, 0, 画像.ちくわ, TRUE);

			break;
		default:
			break;
		}
		ScreenFlip();
	}
}

