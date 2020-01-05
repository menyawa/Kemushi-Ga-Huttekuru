#include "Dxlib.h"
#include "Runner.h"

Runner::Runner(int groundPosY) {
	imageHandle_ = LoadGraph("./Image/Runner.png");
	GetGraphSize(imageHandle_, &imageSizeX_, &imageSizeY_);

	imagePosX_ = 0;
	imagePosY_ = groundPosY - imageSizeY_;
	DrawGraph(imagePosX_, imagePosY_, imageHandle_, TRUE);
}

void Runner::move(unsigned int backGroundColor) {
	int drawAreaX = imagePosX_ + imageSizeX_;
	int drawAreaY = imagePosY_ + imageSizeY_;
	DrawBox(imagePosX_, imagePosY_, drawAreaX, drawAreaY, backGroundColor, TRUE);

	const int moveLength = 1;
	imagePosX_ += moveLength;

	DrawGraph(imagePosX_, imagePosY_, imageHandle_, TRUE);

	ScreenFlip();
}