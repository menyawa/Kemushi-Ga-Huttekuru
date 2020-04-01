#include "BackgroundController.h"

int BackgroundController::backgroundImageHandle_;
int BackgroundController::groundImageHandle_;

//LoadGraph��DX���C�u�����̊֐��Ȃ̂ŁADX���C�u�����������O�ɂ͎g���Ȃ����Ƃɒ���
void BackgroundController::initImageHandle() {
	backgroundImageHandle_ = LoadGraph("./Image/Background.png");
	groundImageHandle_ = LoadGraph("./Image/Ground.png");
}

void BackgroundController::drawBackGround() {
	const int backgroundPos = 0;

	DrawGraph(backgroundPos, backgroundPos, backgroundImageHandle_, TRUE);
	DrawGraph(backgroundPos, groundPosY_, groundImageHandle_, TRUE);
}
