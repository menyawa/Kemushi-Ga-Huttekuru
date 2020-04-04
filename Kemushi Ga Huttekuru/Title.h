#ifndef Title_Included
#define Title_Included

#include "DxLib.h"
#include "AudioController.h"

class Title {
private:
	bool isSeen_;

public:
	Title();

	inline bool canSeenTitle() {
		return !isSeen_;
	}

	inline void switchHasSeenTitleFlag() {
		isSeen_ = !isSeen_;
	}

	void drawTitle();
};

#endif
