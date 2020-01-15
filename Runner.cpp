#include "Dxlib.h"
#include "Runner.h"

Runner::Runner(int groundPosY) {
	imageHandle_ = LoadGraph("./Image/Runner.png");

	xPos_ = 0;
	yPos_ = groundPosY - height_;
	DrawGraph(xPos_, yPos_, imageHandle_, TRUE);
}

void Runner::move(unsigned int backGroundColor) {
	int drawAreaWidth = xPos_ + width_;
	int drawAreaHeight = yPos_ + height_;
	DrawBox(xPos_, yPos_, drawAreaWidth, drawAreaHeight, backGroundColor, TRUE);

	const int moveLength = 1;
	xPos_ += moveLength;

	DrawGraph(xPos_, yPos_, imageHandle_, TRUE);

	ScreenFlip();
}