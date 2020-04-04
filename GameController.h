#ifndef GameController_Included
#define GaemController_Included

#include "DxLib.h"
#include "WindowSizeController.h"
#include "BackgroundController.h"
#include "Fps.h"
#include "PlayerScore.h"
#include "Runner.h"
#include "Caterpillar.h"
#include "GameEnd.h"

class GameController {

};

#endif

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	//これ以前にDXライブラリ関連の初期化を行うと正常に実行されないので注意
	const int error = -1;
	if (DxLib_Init() == error) {
		return error;
	}
	WindowSizeController windowSizeController;
	BackgroundController backgroundController;
	Fps fps;
	PlayerScore playerScore;
	Caterpillar::initStaticField();
	Runner runner(backgroundController.groundYPos_);
	PlaySoundFile("./File/mp3/8bit.mp3", DX_PLAYTYPE_LOOP);

	int counter = 0;
	while (ProcessMessage() != error) {
		backgroundController.drawStageBackGround();
		runner.move(windowSizeController, backgroundController);
		Caterpillar::moveAllCaterpillars(backgroundController);
		Caterpillar::randomSpawn(windowSizeController.width_);

		//この位置で表示しないと、表示順の関係上毛虫で隠れてしまう
		playerScore.plusScore();
		playerScore.printScore();
		runner.boostRunner_.displayGauge(); 

		ScreenFlip();

		//60FPSに動作を合わせている
		fps.update();
		fps.wait();

		if (windowSizeController.isReachedWindowEdge(runner.getXPos() + runner.width_)) {
			if (runner.getXPos() <= 0) {
				GameEnd gameEnd;
				if (gameEnd.selectPlayingNextStage()) {
					Caterpillar::resetCaterpillarsList();	
					runner.startRunning(backgroundController.groundYPos_);
					continue;
				} else {
					break;
				}
			}
		}

		//ゲームクリア判定後に行わないと、逃げ切りが行えないので注意
		//画面を更新したあとに判定を行わないと「当たってないのに当たっている」ということになるので注意
		int runnerRight = runner.getXPos() + runner.width_;
		int runnerButtom = runner.getYPos() + runner.height_;
		if (Caterpillar::caterpillarHittingRunnerIsExists(runner.getXPos(), runnerRight, runner.getYPos(), runnerButtom)) break;

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
