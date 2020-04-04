#ifndef BackgroundController_Included
#define BackgroundController_Included

#include "DxLib.h"

//背景の画像の位置の管理、描画を担当
//C#でいう静的クラスみたいにしようと思ったんだけど…C++はconstの値も変更できる関係で、constメンバ変数を参照するにはインスタンス経由で参照しないといけないらしいので素直にメンバ関数化
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
