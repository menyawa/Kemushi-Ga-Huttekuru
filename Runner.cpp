#include "Dxlib.h"
#include "Runner.h"

Runner::Runner() {
	imageHandle_ = LoadGraph("./Image/Runner.png");
	GetGraphSize(imageHandle_, &imageSizeX_, &imageSizeY_);
	imageSizeX_ /= 2;
	imageSizeY_ /= 2;

	const int groundPosY = 600;
	imagePosX_ = 0;
	imagePosY_ = groundPosY - imageSizeY_;
	//DrawGraph(imagePosX_, imagePosY_, imageHandle_, TRUE);
	DrawExtendGraph(imagePosX_, imagePosY_, imageSizeX_, imageSizeY_, imageHandle_, TRUE);
}