#pragma once
#include "DxLib.h"
#include "DEFINE.h"

class ”wŒi{
public:

	double x,y;
	int ‰æ‘œ;

private:
	void •\¦();
	void “®‚«();
public:
	void ƒI[ƒ‹();
	”wŒi();
};

”wŒi::”wŒi(){
	‰æ‘œ = LoadGraph(".\\‰æ‘œ\\”wŒi1.png");

	x = y = ƒ}[ƒWƒ“;

}
void ”wŒi::•\¦() {
	DrawGraph((int)x, (int)y, ‰æ‘œ, FALSE);
	DrawGraph((int)x, (int)y - 460, ‰æ‘œ, FALSE);

	if (y == 460 + ƒ}[ƒWƒ“)y = 10;
}
void ”wŒi::“®‚«() {
	y += ”wŒi‘¬“x;
}
void ”wŒi::ƒI[ƒ‹(){
	•\¦();
	“®‚«();
}
