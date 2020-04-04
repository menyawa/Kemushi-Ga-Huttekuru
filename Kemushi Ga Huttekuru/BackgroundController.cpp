#include "BackgroundController.h"

//LoadGraph��DX���C�u�����̊֐��Ȃ̂ŁADX���C�u�����������O�ɂ͎g���Ȃ����Ƃɒ���
BackgroundController::BackgroundController() {
	backgroundImageHandle_ = LoadGraph("./File/Image/Background.png");
	groundImageHandle_ = LoadGraph("./File/Image/Ground.png");
	highLightImageHandle_ = LoadGraph("./File/Image/HighLightStartPos.png");
}

void BackgroundController::drawStageBackGround() {
	const int backgroundPos = 0;

	DrawGraph(backgroundPos, backgroundPos, backgroundImageHandle_, TRUE);
	DrawGraph(backgroundPos, groundYPos_, groundImageHandle_, TRUE);
}

//�g��Ȃ��Ȃ������A�ꉞ�Ƃ��Ă���
void BackgroundController::highLightStartPos() {
	const int xPos = 0;
	const int yPos = groundYPos_ - highLightWidth_;
	DrawGraph(xPos, yPos, highLightImageHandle_, TRUE);
}
