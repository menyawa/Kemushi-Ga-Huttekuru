#ifndef GameController_Included
#define GaemController_Included

#include "DxLib.h"
#include "Fps.h"
#include "Runner.h"
#include "Caterpillar.h"

class GameController {
private:
	const int windowWidth = 1280;
	const int windowHeight = 720;
	int backgroundImageHandle_;
	const int backGroundPos_ = 0;
	int groundImageHandle_;
	const int groundPosY_ = 600;

public:
	GameController();

	void initWindow();
	void drawBackGround();

	int getWindowWidth() {
		return windowWidth;
	}
	int getWindowHeight() {
		return windowHeight;
	}
	int getBackGroundPos() {
		return backGroundPos_;
	}
	int getGroundPosY() {
		return groundPosY_;
	}
};

#endif

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	//これ以前にDXライブラリ関連の初期化を行うと正常に実行されないので注意
	const int error = -1;
	if (DxLib_Init() == error) {
		return error;
	}
	GameController gameController;
	Fps fps;
	Caterpillar::initStaticField();
	Runner runner(gameController.getGroundPosY());

	int counter = 0;
	while (ProcessMessage() != error) {
		gameController.drawBackGround();
		runner.move();
		Caterpillar::moveCaterpillars();
		Caterpillar::randomSpawn(gameController.getWindowWidth());

		ScreenFlip();

		//60FPSに動作を合わせている
		fps.update();
		fps.wait();

		if (counter == 1000) {
			break;
		} else {
			counter++;
		}
	}

	WaitKey();

	DxLib_End();

	return 0;
}
