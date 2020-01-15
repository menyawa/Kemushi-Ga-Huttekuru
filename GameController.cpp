#include "GameController.h"

void GameController::initWindow() {
	ChangeWindowMode(TRUE);
	const int selectColorBit = 32;
	SetGraphMode(windowWidth, windowHeight, selectColorBit);
	SetWindowText("Kemushi Ga Huttekuru");
	SetDrawScreen(DX_SCREEN_BACK);
}

void GameController::drawBackGround() {
	const int backgroundImageHandle = LoadGraph("./Image/Background.png");
	DrawGraph(backGroundPos_, backGroundPos_, backgroundImageHandle, TRUE);
	const int groundImageHandle = LoadGraph("./Image/Ground.png");
	DrawGraph(backGroundPos_, groundPosY_, groundImageHandle, TRUE);
}