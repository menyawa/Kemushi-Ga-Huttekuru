#include "BackgroundController.h"

//LoadGraphはDXライブラリの関数なので、DXライブラリ初期化前には使えないことに注意
BackgroundController::BackgroundController() {
	backgroundImageHandle_ = LoadGraph("./Image/Background.png");
	groundImageHandle_ = LoadGraph("./Image/Ground.png");
	highLightImageHandle_ = LoadGraph("./Image/HighLightStartPos.png");
}

void BackgroundController::drawStageBackGround() {
	const int backgroundPos = 0;

	DrawGraph(backgroundPos, backgroundPos, backgroundImageHandle_, TRUE);
	DrawGraph(backgroundPos, groundYPos_, groundImageHandle_, TRUE);
}

void BackgroundController::highLightStartPos() {
	const int xPos = 0;
	const int yPos = groundYPos_ - highLightWidth_;
	DrawGraph(xPos, yPos, highLightImageHandle_, TRUE);
}
