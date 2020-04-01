#include "BackgroundController.h"

int BackgroundController::backgroundImageHandle_;
int BackgroundController::groundImageHandle_;

//LoadGraphはDXライブラリの関数なので、DXライブラリ初期化前には使えないことに注意
void BackgroundController::initImageHandle() {
	backgroundImageHandle_ = LoadGraph("./Image/Background.png");
	groundImageHandle_ = LoadGraph("./Image/Ground.png");
}

void BackgroundController::drawBackGround() {
	const int backgroundPos = 0;

	DrawGraph(backgroundPos, backgroundPos, backgroundImageHandle_, TRUE);
	DrawGraph(backgroundPos, groundPosY_, groundImageHandle_, TRUE);
}
