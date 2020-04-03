#ifndef Caterpillar_Included
#define Caterpillar_Included

#include <vector>
#include <memory>
#include <random>
#include <string>
#include "DxLib.h"
#include "BackgroundController.h"

using namespace std;

class Caterpillar {
private:
	int imageHandle_;
	int ditectionImageHandleIndex_; //左右どちらを向いているかのインデックスを保存する(着地時にその向きで移動するため)
	int xPos_;
	int yPos_;
	int width_;
	int height_;
	int moveLandingVec_; //地面に着地した後の進行方向。もっといい名前があると思う
	bool landing_;

	static vector<unique_ptr<Caterpillar>> caterpillerList_;
	static mt19937_64 mtRand_;
	static int fallingImageHandles_[2];
	static int landingImageHandles_[2];
	static int spawnCount_; 

	Caterpillar(int spawnXPos, int imageHandleIndex);

	//カウントを用いてスポーンの間隔を制御する
	inline static bool canSpawn() {
		return spawnCount_ % 200 == 0;
	}

public:
	bool isHittingRunner(int leftTop, int rightTop, int objectTop, int objectButtom);
	void move(BackgroundController& backgroundController);

	static void initStaticField();
	static void randomSpawn(int highLightStartPosWidth, int windowWidth);
	static void moveAllCaterpillars(BackgroundController& backgroundController);
	static bool caterpillarHittingRunnerIsExists(int playerLeft, int playerRight, int playerTop, int playerButtom);
};

#endif
