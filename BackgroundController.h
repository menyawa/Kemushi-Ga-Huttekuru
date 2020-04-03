#ifndef BackgroundController_Included
#define BackgroundController_Included

#include "DxLib.h"

//�w�i�̉摜�̈ʒu�̊Ǘ��A�`���S��
//C#�ł����ÓI�N���X�݂����ɂ��悤�Ǝv�����񂾂��ǁcC++��const�̒l���ύX�ł���֌W�ŁAconst�����o�ϐ����Q�Ƃ���ɂ̓C���X�^���X�o�R�ŎQ�Ƃ��Ȃ��Ƃ����Ȃ��炵���̂őf���Ƀ����o�֐���
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

	inline bool isLandingGround(int topPos, int height) const{
		return (topPos + height) >= groundYPos_;
	}
};

#endif
