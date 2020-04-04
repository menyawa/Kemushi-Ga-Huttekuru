#ifndef GameController_Included
#define GaemController_Included

#include "DxLib.h"
#include "WindowSizeController.h"
#include "BackgroundController.h"
#include "Title.h"
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
	Title title;
	Fps fps;
	PlayerScore playerScore;
	Caterpillar::initStaticField();
	Runner runner(backgroundController.groundYPos_);
	GameEnd gameEnd;

	while (ProcessMessage() != error) {
		//タイトル画面をまだ見ていない(ゲーム開始時)・タイトルに戻った際、タイトルを表示
		if (title.canSeenTitle()) {
			title.drawTitle();
		}

		//ここからゲーム画面
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

		//ゲームクリアしたか(スタート地点画面外まで逃げ切ったか)判定
		if (windowSizeController.isReachedEdge(runner.getRight())) {
			if (runner.getLeft() <= 0) {
				gameEnd.drawClearMenu();
				if (gameEnd.selectPlayingNextStage()) {
				} else {
					playerScore.resetScore();
					title.switchHasSeenTitleFlag();
				}
				gameEnd.retryGame(backgroundController.groundYPos_, runner);
				continue;
			}
		}

		//ゲームクリア判定後に行わないと、逃げ切りが行えないので注意
		//画面を更新したあとに判定を行わないと「当たってないのに当たっている」ということになるので注意
		if (Caterpillar::caterpillarHittingRunnerIsExists(runner.getLeft(), runner.getRight(), runner.getTop(), runner.getButtom())) {
			gameEnd.drawGameOverMenu();
			playerScore.resetScore();
			
			if (gameEnd.selectPlayingNextStage()) {

			} else {
				title.switchHasSeenTitleFlag();
			}
			gameEnd.retryGame(backgroundController.groundYPos_, runner);
		}
	}

	WaitKey();
	DxLib_End();

	return 0;
}
