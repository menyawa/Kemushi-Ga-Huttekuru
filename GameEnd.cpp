#include "GameEnd.h"

GameEnd::GameEnd() {
	clearMenuImageHandle_ = LoadGraph("./File/Image/ClearMenu.png");
	bonusScoreImageHandle_ = LoadGraph("./File/Image/ClearMenu_BonusScore.png");
}


//�N���A���j���[���o���A�����邩�ǂ�����Ԃ�
bool GameEnd::selectPlayingNextStage() {
	DrawGraph(0, 0, clearMenuImageHandle_, TRUE);
	WaitKey();

	//�����邩�I���A�ǂ��炩��I������܂ő҂�
	while (CheckHitKey(KEY_INPUT_R) == false && CheckHitKey(KEY_INPUT_E) == false) WaitKey();

	return CheckHitKey(KEY_INPUT_R);
}