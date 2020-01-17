#ifndef Caterpillar_Included
#define Caterpillar_Included

#include <vector>

using namespace std;

class Caterpillar {
private:
	int imageHandle_;
	int xPos_;
	int yPos_;
	int moveLandingVec_; //�n�ʂɒ��n������̐i�s�����B�����Ƃ������O������Ǝv��
	bool landing_;

	static vector<Caterpillar*> caterpillerList_;

public:
	Caterpillar(int maxXLength);
	bool checkHit(int leftTop, int rightTop, int objectTop, int objectButtom);
	void randomSpawn(int maxXLength);
	void move();

	static void moveCaterpillars();
	static void deleteAllInstances();
};

#endif
