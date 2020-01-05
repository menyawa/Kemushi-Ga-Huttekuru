#ifndef Runner_Included
#define Runner_Included

class Runner {
private:
	int imageHandle_;
	int imageSizeX_;
	int imageSizeY_;
	int imagePosX_;
	int imagePosY_;

public:
	Runner(int groundPosY);

	int getImageSizeX() {
		return imageSizeX_;
	}

	int getImageSizeY() {
		return imageSizeY_;
	}
};

#endif