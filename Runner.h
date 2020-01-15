#ifndef Runner_Included
#define Runner_Included

class Runner {
private:
	int imageHandle_;
	const int width_ = 100;
	const int height_ = 100;
	int xPos_;
	int yPos_;

public:
	Runner(int groundPosY);
	void move(unsigned int backGroundColor);

	int getWidth() {
		return width_;
	}

	int getHeight() {
		return height_;
	}
};

#endif