#include "GameEnd.h"

GameEnd::GameEnd() {
	clearMenuImageHandle_ = LoadGraph("./File/Image/ClearMenu.png");
	bonusScoreImageHandle_ = LoadGraph("./File/Image/ClearMenu_BonusScore.png");
}


//クリアメニューを出し、続けるかどうかを返す
bool GameEnd::selectPlayingNextStage() {
	DrawGraph(0, 0, clearMenuImageHandle_, TRUE);
	WaitKey();

	//続けるか終わる、どちらかを選択するまで待つ
	while (CheckHitKey(KEY_INPUT_R) == false && CheckHitKey(KEY_INPUT_E) == false) WaitKey();

	return CheckHitKey(KEY_INPUT_R);
}