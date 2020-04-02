#include "Caterpillar.h"

vector<unique_ptr<Caterpillar>> Caterpillar::caterpillerList_;
mt19937_64 Caterpillar::mtRand_;
int Caterpillar::fallingImageHandles_[2];
int Caterpillar::landingImageHandles_[2];


Caterpillar::Caterpillar(int spawnXPos, int imageHandleIndex) {
	imageHandle_ = fallingImageHandles_[imageHandleIndex];
	ditectionImageHandleIndex_ = imageHandleIndex;
	xPos_ = spawnXPos;
	yPos_ = 0;
	GetGraphSize(imageHandle_, &width_, &height_);
	DrawGraph(spawnXPos, yPos_, fallingImageHandles_[imageHandleIndex], TRUE);
	moveLandingVec_ = ditectionImageHandleIndex_ == 0 ? -1 : 1; //左向きか右向きかで着地後の移動方向が変わる
	landing_ = false;
}

//矩形の当たり判定でプレイヤーに当たったか確認する
bool Caterpillar::checkHitPlayer(int hitObjectLeft, int hitObjectRight, int hitObjectTop, int hitObjectButtom) {
	int caterpillarLeft = xPos_;
	int caterpillarRight = xPos_ + width_;
	int caterpillarLeftButtom = yPos_ + height_;

	bool hit = false;
	//オブジェクトの右端が左端より右かつ、オブジェクトの左端が右端より左
	if (hitObjectRight > caterpillarLeft && hitObjectLeft < caterpillarRight) {
		int caterpillarTop = yPos_;
		int caterpillarButtom = yPos_ + height_;
		
		//上の判定を上端、下端で同じように行う
		if (caterpillarTop > hitObjectButtom && caterpillarButtom < hitObjectTop) {
			hit = true;
		}
	}

	return hit;
}

void Caterpillar::move(BackgroundController& backgroundController) {
	if (landing_) {
		//左右決められた方向に移動
		xPos_ += moveLandingVec_;
	} else {
		yPos_++;
	}

	//着地した場合、向いていた方向を向いたまま横向きにする
	if (backgroundController.checkLandingGround(yPos_, height_)) {
		landing_ = true;
		imageHandle_ = landingImageHandles_[ditectionImageHandleIndex_];
		swap(width_, height_); //着地するので、横の長さと縦の長さが入れ替わる
		yPos_ = backgroundController.groundPosY_ - height_;
	}

	DrawGraph(xPos_, yPos_, imageHandle_, TRUE);
}

void Caterpillar::initStaticField() {
	//非決定的な乱数生成で初期値を決め、以降は擬似乱数で生成する
	//短い間隔で乱数を生成する可能性があるので、パフォーマンスの関係上乱数生成器をそのたび生成するのではなく、フィールドに保持しておく
	random_device randomDevice;
	mtRand_.seed(randomDevice());

	//コンパイル時値が確定しないため、constでの指定は使えないことに注意
	fallingImageHandles_[0] = LoadGraph("./Image/Caterpillar_Falling_Left.png");
	fallingImageHandles_[1] = LoadGraph("./Image/Caterpillar_Falling_Right.png");
	landingImageHandles_[0] = LoadGraph("./Image/Caterpillar_Landing_Left.png");
	landingImageHandles_[1] = LoadGraph("./Image/Caterpillar_Landing_Right.png");
}

//新しい毛虫をランダムな位置にスポーンさせる
void Caterpillar::randomSpawn(int windowSizeX) {
	int fallingCaterpillarWidth = 66;
	//一様分布乱数生成器を作り、その後それに乱数生成器を渡してスポーン位置を決める
	uniform_int_distribution<> spawnPosRandDistribution(0, windowSizeX - fallingCaterpillarWidth);
	int spawnXPos = spawnPosRandDistribution(mtRand_);
	//同様に、左右どちらを向くかのインデックスを決める
	uniform_int_distribution<> fallingRandDistribution(0, 1);
	caterpillerList_.push_back(unique_ptr<Caterpillar>(new Caterpillar(spawnXPos, fallingRandDistribution(mtRand_))));
}

//毎回BackgroundControllerのインスタンスを生成すると負荷になることが予想されるため、参照で対処
void Caterpillar::moveAllCaterpillars(BackgroundController& backgroundController) {
	for (int index = 0; index < caterpillerList_.size(); index++) {
		caterpillerList_[index]->move(backgroundController);
	}
}
