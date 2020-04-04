#ifndef AudioController_Included
#define AudioController_Included

#include "DxLib.h"

class AudioController {
public:
	inline void playBGM() {
		if (CheckSoundFile()) {
			StopSoundFile();
		}
		PlaySoundFile("./File/mp3/8bit.mp3", DX_PLAYTYPE_LOOP);
	}
};

#endif
