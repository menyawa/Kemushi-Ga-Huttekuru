#include "Dxlib.h"
#include "Runner.h"

Runner::Runner(int groundPosY) : xPos_(0), yPos_(groundPosY - height_), moveLandingVec_(1), canJump_(true), jumpSpeed_(0), turningBackTheWay_(false), boostRunner_(100) {
	imageHandle_ = LoadGraph("./Image/Runner.png");
	DrawGraph(xPos_, yPos_, imageHandle_, TRUE);
}

void Runner::move(int windowWidth, BackgroundController& backgroundController) {
	run();
	jump(backgroundController.isLandingGround(yPos_, height_), backgroundController.groundYPos_);
	
	//��ʒ[�ň����Ԃ�
	if (isReachedOppositeEdge(windowWidth)) {
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

//����(�������̈ړ�)
void Runner::run() {
	int speed = 1;
	speed = boostRunner_.boostSpeed(speed);
	xPos_ += speed * moveLandingVec_;
}

//�W�����v����(�c�����̈ړ�)
void Runner::jump(bool isLandingGround, int groundPosY) {
	//if (CheckHitKey(KEY_INPUT_SPACE)) {
	//	if (isLandingGround && canJump_) {
	//		canJump_ = false; //�W�����v�ł��邩�ǂ������Ƃ��Ă����Ȃ��ƁA�L�[�������Ȃ��璅�n�����ꍇ���W�����v���Ă��܂�
	//		jumpSpeed_ = 20;
	//	}
	//} else {
	//	if (isLandingGround) canJump_ = true;
	//}

	//if (isLandingGround) yPos_ = groundPosY - height_; //���n���Ă���̂Ȃ�A�߂荞�܂Ȃ��悤�ʒu��␳����
}