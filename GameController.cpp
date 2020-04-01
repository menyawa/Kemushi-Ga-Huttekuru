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
}