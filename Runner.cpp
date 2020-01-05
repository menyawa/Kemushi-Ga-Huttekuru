#include "Dxlib.h"
#include "Runner.h"

Runner::Runner(int groundPosY) {
	imageHandle_ = LoadGraph("./Image/Runner.png");
	GetGraphSize(imageHandle_, &imageSizeX_, &imageSizeY_);

	imagePosX_ = 0;
	imagePosY_ = groundPosY - imageSizeY_;
	DrawGraph(imagePosX_, imagePosY_, imageHandle_, TRUE);
}