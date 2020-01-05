#include "GameController.h"

void GameController::initWindow() {
	ChangeWindowMode(TRUE);
	const int windowSizeX = 1280;
	const int windowSizeY = 720;
	const int selectColorBit = 32;
	SetGraphMode(windowSizeX, windowSizeY, selectColorBit);
	SetWindowText("Kemushi Ga Huttekuru");
}

void GameController::initBackGroundImage() {
	const int backGroundImageHandle = LoadGraph("./Image/Background.png");
	DrawGraph(backGroundPos_, backGroundPos_, backGroundImageHandle, TRUE);
	backGroundColor_ = GetColor(0, 180, 255);
	const int groundImageHandle = LoadGraph("./Image/Ground.png");
	DrawGraph(backGroundPos_, groundPosY_, groundImageHandle, TRUE);
	groundColor_ = GetColor(168, 104, 0);
}