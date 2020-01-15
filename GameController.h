#ifndef GameController_Included
#define GaemController_Included

#include "DxLib.h"
#include "Runner.h"
#include "Caterpillar.h"

class GameController {
private:
	const int windowWidth = 1280;
	const int windowHeight = 720;
	const unsigned int backGroundColor_ = GetColor(0, 180, 255);
	const int backGroundPos_ = 0;
	const unsigned int groundColor_ = GetColor(168, 104, 0);
	const int groundPosY_ = 600;

public:
	void initWindow();
	void drawBackGround();

	int getWindowWidth() {
		return windowWidth;
	}

	int getWindowHeight() {
		return windowHeight;
	}

	unsigned int getBackGroundColor() {
		return backGroundColor_;
	}

	int getBackGroundPos() {
		return backGroundPos_;
	}

	unsigned int getGroundColor() {
		return groundColor_;
	}

	int getGroundPosY() {
		return groundPosY_;
	}
};

#endif

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	GameController gameController;
	gameController.initWindow();
	const int error = -1;
	if (DxLib_Init() == error) {
		return error;
	}

	Runner runner(gameController.getGroundPosY());

	while (ProcessMessage() != error) {
		gameController.drawBackGround();
		runner.move(gameController.getBackGroundColor());

		Caterpillar* caterpillar = new Caterpillar(gameController.getWindowWidth());
		break;
	}
	Caterpillar::deleteAllInstances();

	WaitKey();

	DxLib_End();

	return 0;
}
