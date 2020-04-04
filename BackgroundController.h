#ifndef BackgroundController_Included
#define BackgroundController_Included

#include "DxLib.h"

//�w�i�̉摜�̈ʒu�̊Ǘ��A�`���S��
class BackgroundController {
private:
	int backgroundImageHandle_;
	int groundImageHandle_;
	int highLightImageHandle_;

public:
	const int groundYPos_ = 600;
	const int highLightWidth_ = 100;
	
	BackgroundController();
	void drawStageBackGround();
	void highLightStartPos();

	inline bool isLandingGround(int top, int height) const{
		return (top + height) >= groundYPos_;
	}
};

#endif
