#include "GameController.h"

void GameController::initWindow() {
	ChangeWindowMode(TRUE);
	const int selectColorBit = 32;
	SetGraphMode(windowSizeX, windowSizeY, selectColorBit);
	SetWindowText("Kemushi Ga Huttekuru");
	SetDrawScreen(DX_SCREEN_BACK);
}

void GameController::drawBackGround() {
	const int backGroundImageHandle = LoadGraph("./Image/Background.png");
	DrawGraph(backGroundPos_, backGroundPos_, backGroundImageHandle, TRUE);
	backGroundColor_ = GetColor(0, 180, 255);
	const int groundImageHandle = LoadGraph("./Image/Ground.png");
	DrawGraph(backGroundPos_, groundPosY_, groundImageHandle, TRUE);
	groundColor_ = GetColor(168, 104, 0);
}