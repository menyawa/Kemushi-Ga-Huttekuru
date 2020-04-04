#include "Dxlib.h"
#include "Runner.h"

Runner::Runner(int groundPosY) {
	startRunning(groundPosY);
}

//�X�^�[�g����
//���N���A������̃��X�^�[�g�����g���񂹂�悤���\�b�h��
void Runner::startRunning(int groundPosY) {
	imageHandle_ = LoadGraph("./File/Image/Runner.png");
	xPos_ = width_ * -1 - margin_; //��ʊO����X�^�[�g
	yPos_ = groundPosY - height_ - margin_;
	
	runningVec_ = 1;
	canJump_ = true;
	jumpSpeed_ = 0;
	boostRunner_.resetPower();
}

void Runner::move(WindowSizeController& windowSizeController, BackgroundController& backgroundController) {
	run();
	jump(backgroundController, backgroundController.groundYPos_);
	
	//��ʒ[�ɂ��ǂ蒅������
	if (windowSizeController.isReachedEdge(getRight())) {
		if (xPos_ > 0) {
			//�X�^�[�g�n�_���甽�Α��̒[�ň����Ԃ�
			imageHandle_ = LoadGraph("./File/Image/TurningBack_TheWay_Runner.png");
			//�u�[�X�g�̊֌W�ŉ�ʒ[����͂ݏo�Ă���\��������̂ŁA�����߂�
			//���̍ہA�������˕Ԃ�悤�ȋ��������邱�Ƃɒ���(�͂ݏo�Ă��镪�X�ɖ߂�̂ŁA��ʒ[�s�b�^���̈ʒu�ɂ͂Ȃ�Ȃ����Ƃ�����)
			int widthOfOutSideFromEdge = getRight() - windowSizeController.width_;
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
void Runner::jump(BackgroundController& backgroundController, int groundPosY) {
	bool isLandingGround = backgroundController.isLandingGround(getTop(), height_);
	int acc = 0; 
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		if (isLandingGround && canJump_) {
			canJump_ = false; 
			jumpSpeed_ = -25;
		} else {
			acc--; //�󒆂ŉ����Ă���Ԃ͏�ɉ����x�������邱�ƂŁA�����Ă��钷���ō����̒������ł���悤�ɂ���
			//TODO:�󒆂ŗ��������Ƃ܂�������������x���������Ă��܂��̂Œ���
		}
	} else {
		if (isLandingGround) canJump_ = true; //�W�����v�ł��邩�ǂ������Ƃ��Ă����Ȃ��ƁA�L�[�������Ȃ��璅�n�����ꍇ���W�����v���Ă��܂�
	}

	const int g = 2;
	jumpSpeed_ += acc + g;
	yPos_ += jumpSpeed_;

	isLandingGround = backgroundController.isLandingGround(getTop(), height_);
	//�X�V��̍��W�Œ��n���Ă��邩���Ȃ��ƁA�X�V�O�̒i�K�Œn�ʂɐݒu���Ă�����W�����v�ł��Ȃ��Ȃ�
	if (isLandingGround) {
		yPos_ = groundPosY - height_ - margin_; //���n���Ă���̂Ȃ�A�߂荞�܂Ȃ��悤�ʒu��␳����
	}
}