#ifndef Caterpillar_Included
#define Caterpillar_Included

#include <vector>
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

	static vector<Caterpillar*>* caterpillerList_;
	static int fallingLeftImageHandle_;
	static int fallingRightImageHandle_;
	static int landingLeftImageHandle_;
	static int landingRightImageHandle_;

public:
	Caterpillar(int spawnXPos);
	bool checkHit(int leftTop, int rightTop, int objectTop, int objectButtom);
	void move();

	static void initStaticField();
	static void randomSpawn(int windowWidth);
	static void moveCaterpillars();
	static void deleteAllInstances();
};

#endif
