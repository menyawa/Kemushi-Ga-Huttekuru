#ifndef Runner_Included
#define Runner_Included

#include "WindowSizeController.h"
#include "BackgroundController.h"
#include "BoostRunner.h"

class Runner {
private:
	int imageHandle_;
	int xPos_;
	int yPos_;
	const int margin_ = 10;
	int runningVec_; //���E�A�ǂ���̕����ɑ��邩
	bool canJump_;
	int jumpSpeed_;

	void run();
	void jump(bool isLandingGround, int groundPosY);

public:
	//�摜�T�C�Y���̂܂܂��ƁA�]���̕������蔻�肪�L�����Ă��܂��̂Œ���
	const int width_ = 90;
	const int height_ = 90;
	BoostRunner boostRunner_;

	Runner(int groundPosY);
	void startRunning(int groundPosY);
	void move(WindowSizeController& windowSizeController, BackgroundController& backgroundController);

	//�����蔻��ƍ��W���]��������֌W�ňႤ�̂ŁA���E�E�㉺�̓����蔻��J�n�ʒu���擾���郁�\�b�h��p��
	inline int getLeft() {
		return xPos_ + margin_;
	}

	inline int getRight() {
		return getLeft() + width_;
	}

	inline int getTop() {
		return yPos_ + margin_;
	}

	inline int getButtom() {
		return getTop() + height_;
	}
};

#endif