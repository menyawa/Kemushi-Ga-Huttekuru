#ifndef GameEnd_Included
#define GameEnd_Included

#include "DxLib.h"
#include "Caterpillar.h"
#include "Title.h"
#include "PlayerScore.h"
#include "Runner.h"

class GameEnd {
private:
	int clearMenuImageHandle_; //逃げ切り時にゲームを続けるかどうかの判断に使われる画像
	int bonusScoreImageHandle_; //クリアメニューに重ね合わせで、スコア２倍チャンスを知らせる画像
	int gameOverImageHandle_; //途中で毛虫に当たってゲームオーバーになってしまった際に使われる画像

public:
	GameEnd();

	void drawClearMenu();
	void drawGameOverMenu();

	bool selectPlayingNextStage();
	void retryGame(int groundPosY, Runner& runner);
};

#endif
