#ifndef GameEnd_Included
#define GameEnd_Included

#include "DxLib.h"
#include "Caterpillar.h"
#include "Title.h"
#include "PlayerScore.h"
#include "Runner.h"

class GameEnd {
private:
	int clearMenuImageHandle_; //�����؂莞�ɃQ�[���𑱂��邩�ǂ����̔��f�Ɏg����摜
	int bonusScoreImageHandle_; //�N���A���j���[�ɏd�ˍ��킹�ŁA�X�R�A�Q�{�`�����X��m�点��摜
	int gameOverImageHandle_; //�r���Ŗђ��ɓ������ăQ�[���I�[�o�[�ɂȂ��Ă��܂����ۂɎg����摜

public:
	GameEnd();

	void drawClearMenu();
	void drawGameOverMenu();

	bool selectPlayingNextStage();
	void retryGame(int groundPosY, Runner& runner);
};

#endif
