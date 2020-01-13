#ifndef Caterpillar_Included
#define Caterpillar_Included

#include <vector>

using namespace std;

class Caterpillar {
private:
	int imageHandle_;
	int posX_;
	int posY_;

	static vector<Caterpillar*> caterpillers_;

public:
	Caterpillar();
	bool checkHit(int leftTop, int rightTop, int objectTop, int objectButtom);
};

#endif
