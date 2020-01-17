#ifndef Fps_Included
#define Fps_Included

#include <math.h>
#include "DxLib.h"

class Fps {
private:
	int startTime_;
	int count_;
	float trueFps_;
	
public:
	Fps();
	void update();
	void wait();
};

#endif
