#include "Dxlib.h"
#include "Runner.h"

Runner::Runner() {
	imageHandle_ = LoadGraph("./Image/Runner.png");
	GetGraphSize(imageHandle_, &imageSizeX_, &imageSizeY_);

	const int groundPosY = 600;
	imagePosX_ = 0;
	imagePosY_ = groundPosY - imageSizeY_;
	DrawGraph(imagePosX_, imagePosY_, imageHandle_, TRUE);
}
