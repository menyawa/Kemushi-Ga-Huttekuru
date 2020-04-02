#ifndef Runner_Included
#define Runner_Included

class Runner {
private:
	int imageHandle_;
	const int width_ = 100;
	const int height_ = 100;
	int xPos_;
	int yPos_;
	int moveLandingVec_; //���E�A�ǂ���̕����ɑ��邩
	bool turningBackTheWay_; //�����Ԃ��Ă���r����
	int boostPower_;

	inline bool canBoost() {
		return boostPower_ > 0;
	}

	//�X�^�[�g�n�_���甽�Α��̒[�ɓ��B������
	inline bool checkReachOppositeEdge(int windowWidth) {
		return (xPos_ + width_) >= windowWidth;
	}

public:
	Runner(int groundPosY);
	void run(int windowWidth);

	inline int getWidth() {
		return width_;
	}

	inline int getHeight() {
		return height_;
	}
};

#endif