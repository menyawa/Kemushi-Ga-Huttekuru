#ifndef GameController_Included
#define GaemController_Included

#include "DxLib.h"
#include "Runner.h"

class GameController {
private:
	unsigned int backGroundColor_;
	int backGroundPos_ = 0;
	unsigned int groundColor_;
	const int groundPosY_ = 600;

public:
	void initWindow();
	void drawBackGround();

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
	}

	WaitKey();

	DxLib_End();

	return 0;
}
