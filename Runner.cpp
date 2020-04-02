#include "Dxlib.h"
#include "Runner.h"

Runner::Runner(int groundPosY) {
	imageHandle_ = LoadGraph("./Image/Runner.png");

	xPos_ = 0;
	yPos_ = groundPosY - height_;
	DrawGraph(xPos_, yPos_, imageHandle_, TRUE);
	moveLandingVec_ = 1;
	turningBackTheWay_ = false;
	boostPower_ = 100;
}

void Runner::run(int windowWidth) {
	int movingLength = 1;
	if (CheckHitKey(KEY_INPUT_SPACE) && canBoost()) {
		movingLength *= 3;
		boostPower_--;
	} else if(CheckHitKey(KEY_INPUT_SPACE) == false){ //�L�[�𗣂��Ă��鎞�ɒ��܂�悤�ɂ��Ȃ��ƁA�����Ƀu�[�X�g���ʏ큨�u�[�X�g���ʏ큨�c�ƌJ��Ԃ��Ă��܂�
		boostPower_++;
	}
		
	xPos_ += movingLength * moveLandingVec_;
	
	if (checkReachOppositeEdge(windowWidth)) {
		turningBackTheWay_ = true;
		imageHandle_ = LoadGraph("./Image/TurningBack_TheWay_Runner.png");
		//�u�[�X�g�̊֌W�ŉ�ʒ[����͂ݏo�Ă���\��������̂ŁA�����߂�
		//���̍ہA�������˕Ԃ�悤�ȋ��������邱�Ƃɒ���(�͂ݏo�Ă��镪�X�ɖ߂�̂ŁA��ʒ[�s�b�^���̈ʒu�ɂ͂Ȃ�Ȃ����Ƃ�����)
		int widthOfOutSideFromEdge = width_ - (windowWidth - xPos_);
		xPos_ = windowWidth - width_ - widthOfOutSideFromEdge; 
		moveLandingVec_ *= -1;
	}

	DrawGraph(xPos_, yPos_, imageHandle_, TRUE);
}