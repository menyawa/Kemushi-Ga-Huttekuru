#ifndef BackgroundController_Included
#define BackgroundController_Included

#include "DxLib.h"

//�w�i�̉摜�̈ʒu�̊Ǘ��A�`���S��
//C#�ł����ÓI�N���X�݂����ɂ��悤�Ǝv�����񂾂��ǁcC++��const�̒l���ύX�ł���֌W�ŁAconst�����o�ϐ����Q�Ƃ���ɂ̓C���X�^���X�o�R�ŎQ�Ƃ��Ȃ��Ƃ����Ȃ��炵���̂őf���Ƀ����o�֐���
class BackgroundController {
private:
	static int backgroundImageHandle_;
	static int groundImageHandle_;

public:
	const int groundPosY_ = 600;
	
	static void initImageHandle();

	void drawBackGround();

	inline bool checkLandingGround(int topPos, int height) const{
		return (topPos + height) >= groundPosY_;
	}
};

#endif
