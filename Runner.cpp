#include "Dxlib.h"
#include "Runner.h"

Runner::Runner(int groundPosY) {
	imageHandle_ = LoadGraph("./Image/Runner.png");

	xPos_ = 0;
	yPos_ = groundPosY - height_;
	DrawGraph(xPos_, yPos_, imageHandle_, TRUE);
	movingVec_ = 1;
	boostPower_ = 100;
}

void Runner::run() {
	int drawAreaWidth = xPos_ + width_;
	int drawAreaHeight = yPos_ + height_;

	if (checkReachEdge()) {

	}

	int movingLength = 1;
	if (CheckHitKey(KEY_INPUT_SPACE) && canBoost()) {
		movingLength *= 3;
		boostPower_--;
	} else if(CheckHitKey(KEY_INPUT_SPACE) == false){ //�L�[�𗣂��Ă��鎞�ɒ��܂�悤�ɂ��Ȃ��ƁA�����Ƀu�[�X�g���ʏ큨�u�[�X�g���ʏ큨�c�ƌJ��Ԃ��Ă��܂�
		boostPower_++;
	}
		
	xPos_ += movingLength * movingVec_;

	DrawGraph(xPos_, yPos_, imageHandle_, TRUE);
}

bool Runner::checkReachEdge() {
	return false;
}