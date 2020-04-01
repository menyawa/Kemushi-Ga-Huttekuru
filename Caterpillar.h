#ifndef Caterpillar_Included
#define Caterpillar_Included

#include <vector>
#include <memory>
#include <random>
#include <string>
#include "DxLib.h"

using namespace std;

class Caterpillar {
private:
	int imageHandle_;
	int xPos_;
	int yPos_;
	int moveLandingVec_; //�n�ʂɒ��n������̐i�s�����B�����Ƃ������O������Ǝv��
	bool landing_;

	static vector<unique_ptr<Caterpillar>> caterpillerList_;
	static mt19937_64 mtRand_;
	static int fallingLeftImageHandle_;
	static int fallingRightImageHandle_;
	static int landingLeftImageHandle_;
	static int landingRightImageHandle_;

	Caterpillar(int spawnXPos);

public:
	bool checkHit(int leftTop, int rightTop, int objectTop, int objectButtom);
	void move();

	static void initStaticField();
	static void randomSpawn(int windowWidth);
	static void moveCaterpillars();
};

#endif
