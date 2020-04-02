#ifndef BackgroundController_Included
#define BackgroundController_Included

#include "DxLib.h"

//背景の画像の位置の管理、描画を担当
//C#でいう静的クラスみたいにしようと思ったんだけど…C++はconstの値も変更できる関係で、constメンバ変数を参照するにはインスタンス経由で参照しないといけないらしいので素直にメンバ関数化
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
