#include "GameController.h"

GameController::GameController() {
	initWindow();
}

void GameController::initWindow() {
	ChangeWindowMode(TRUE);
	const int selectColorBit = 32;
	SetGraphMode(windowWidth, windowHeight, selectColorBit);
	SetWindowText("Kemushi Ga Huttekuru");
	SetDrawScreen(DX_SCREEN_BACK);

	//�����ŏ����������萔������ƁADX���C�u�����̏������O�ɏ��������邱�ƂɂȂ邽�ߕs������̋���A��
	backgroundImageHandle_ = LoadGraph("./Image/Background.png");
	groundImageHandle_ = LoadGraph("./Image/Ground.png");
}

void GameController::drawBackGround() {
	DrawGraph(backGroundPos_, backGroundPos_, backgroundImageHandle_, TRUE);
	DrawGraph(backGroundPos_, groundPosY_, groundImageHandle_, TRUE);
}