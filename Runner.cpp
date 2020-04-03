#include "Dxlib.h"
#include "Runner.h"

Runner::Runner(int groundPosY) {
	startRunning(groundPosY);
}

//�X�^�[�g����
//���N���A������̃��X�^�[�g�����g���񂹂�悤���\�b�h��
void Runner::startRunning(int groundPosY) {
	imageHandle_ = LoadGraph("./File/Image/Runner.png");
	xPos_ = width_ * -1; //��ʊO����X�^�[�g
	yPos_ = groundPosY - height_;
	
	runningVec_ = 1;
	canJump_ = true;
	jumpSpeed_ = 0;
	boostRunner_.resetPower();
}

void Runner::move(WindowSizeController& windowSizeController, BackgroundController& backgroundController) {
	run();
	jump(backgroundController.isLandingGround(yPos_, height_), backgroundController.groundYPos_);
	
	//��ʒ[�ɂ��ǂ蒅������
	if (windowSizeController.isReachedWindowEdge(xPos_ + width_)) {
		if (xPos_ <= 0) {
			xPos_ = 0;
		} else {
			//�X�^�[�g�n�_���甽�Α��̒[�ň����Ԃ�
			imageHandle_ = LoadGraph("./File/Image/TurningBack_TheWay_Runner.png");
			//�u�[�X�g�̊֌W�ŉ�ʒ[����͂ݏo�Ă���\��������̂ŁA�����߂�
			//���̍ہA�������˕Ԃ�悤�ȋ��������邱�Ƃɒ���(�͂ݏo�Ă��镪�X�ɖ߂�̂ŁA��ʒ[�s�b�^���̈ʒu�ɂ͂Ȃ�Ȃ����Ƃ�����)
			int widthOfOutSideFromEdge = width_ - (windowSizeController.width_ - xPos_);
			xPos_ = windowSizeController.width_ - width_ - widthOfOutSideFromEdge;
		}
		runningVec_ *= -1;
	}

	DrawGraph(xPos_, yPos_, imageHandle_, TRUE);
}

//����(�������̈ړ�)
void Runner::run() {
	int speed = 1;
	speed = boostRunner_.boostSpeed(speed);
	xPos_ += speed * runningVec_;
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