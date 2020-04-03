#include "Dxlib.h"
#include "Runner.h"

Runner::Runner(int groundPosY) : xPos_(0), yPos_(groundPosY - height_), moveLandingVec_(1), canJump_(true), jumpSpeed_(0), boostRunner_(100) {
	imageHandle_ = LoadGraph("./Image/Runner.png");
	DrawGraph(xPos_, yPos_, imageHandle_, TRUE);
}

void Runner::move(WindowSizeController& windowSizeController, BackgroundController& backgroundController) {
	run();
	jump(backgroundController.isLandingGround(yPos_, height_), backgroundController.groundYPos_);
	
	//��ʒ[�ɂ��ǂ蒅������
	if (windowSizeController.isReachedWindowEdge(xPos_, width_)) {
		if (xPos_ <= 0) {
			xPos_ = 0;
		} else {
			//�X�^�[�g�n�_���甽�Α��̒[�ň����Ԃ�
			imageHandle_ = LoadGraph("./Image/TurningBack_TheWay_Runner.png");
			//�u�[�X�g�̊֌W�ŉ�ʒ[����͂ݏo�Ă���\��������̂ŁA�����߂�
			//���̍ہA�������˕Ԃ�悤�ȋ��������邱�Ƃɒ���(�͂ݏo�Ă��镪�X�ɖ߂�̂ŁA��ʒ[�s�b�^���̈ʒu�ɂ͂Ȃ�Ȃ����Ƃ�����)
			int widthOfOutSideFromEdge = width_ - (windowSizeController.width_ - xPos_);
			xPos_ = windowSizeController.width_ - width_ - widthOfOutSideFromEdge;
		}
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