#include "PlayerScore.h"

PlayerScore::PlayerScore() {
	resetScore();
	fontHandle_ = CreateFontToHandle("./File/Font/���_�S�V�b�NX", 30, 5, DX_FONTTYPE_ANTIALIASING);
}

void  PlayerScore::printScore() {
	const int xPos = 1000;
	const int yPos = 25;
	const int color = GetColor(255, 255, 255);
	DrawFormatStringToHandle(xPos, yPos, color, fontHandle_, "�X�R�A�F%d", score_);
}