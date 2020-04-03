#ifndef WindowSizeController_Included
#define WindowSizeController_Included

#include "DxLib.h"

class WindowSizeController {
private:
	

public:
	const int width_ = 1280;
	const int height_ = 720;

	WindowSizeController();

	inline bool isReachedWindowEdge(int xPos, int width) {
		if (xPos == 0) return true;
		if (xPos + width >= width_) return true;

		return false;
	}
};

#endif
