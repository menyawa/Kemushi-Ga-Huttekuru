#include "Caterpillar.h"

vector<unique_ptr<Caterpillar>> Caterpillar::caterpillerList_;
mt19937_64 Caterpillar::mtRand_;
int Caterpillar::fallingLeftImageHandle_;
int Caterpillar::fallingRightImageHandle_;
int Caterpillar::landingLeftImageHandle_;
int Caterpillar::landingRightImageHandle_;


Caterpillar::Caterpillar(int spawnXPos) {
	imageHandle_ = fallingLeftImageHandle_;
	xPos_ = spawnXPos;
	yPos_ = 0;
	landing_ = false;
}

//矩形の当たり判定
bool Caterpillar::checkHit(int hitObjectLeft, int hitObjectRight, int hitObjectTop, int hitObjectButtom) {
	int width, height;
	GetGraphSize(imageHandle_, &width, &height);
	int caterpillarLeft = xPos_;
	int caterpillarRight = xPos_ + width;
	int caterpillarLeftButtom = yPos_ + height;

	bool hit = false;
	//オブジェクトの右端が左端より右かつ、オブジェクトの左端が右端より左
	if (hitObjectRight > caterpillarLeft && hitObjectLeft < caterpillarRight) {
		int caterpillarTop = yPos_;
		int caterpillarButtom = yPos_ + height;
		
		//上の判定を上端、下端で同じように行う
		if (caterpillarTop > hitObjectButtom && caterpillarButtom < hitObjectTop) {
			hit = true;
		}
	}

	return hit;
}

void Caterpillar::move() {
	if (landing_) {
		//左右決められた方向に移動
		xPos_ += moveLandingVec_;
	} else {
		yPos_++;
		DrawGraph(xPos_, yPos_, imageHandle_, TRUE);
	}
}


void Caterpillar::initStaticField() {
	//非決定的な乱数生成で初期値を決め、以降は擬似乱数で生成する
	//短い間隔で乱数を生成する可能性があるので、パフォーマンスの関係上乱数生成器をそのたび生成するのではなく、フィールドに保持しておく
	random_device randomDevice;
	mtRand_.seed(randomDevice());

	//コンパイル時値が確定しないため、constでの指定は使えないことに注意
	fallingLeftImageHandle_ = LoadGraph("./Image/Caterpillar_Falling_Left.png");
	fallingRightImageHandle_ = LoadGraph("./Image/Caterpillar_Falling_Right.png");
	landingLeftImageHandle_ = LoadGraph("./Image/Caterpillar_Landing_Left.png");
	landingRightImageHandle_ = LoadGraph("./Image/Caterpillar_Landing_Right.png");
}

//新しい毛虫をランダムな位置にスポーンさせる
void Caterpillar::randomSpawn(int windowSizeX) {
	int width = 66;
	//一様分布乱数生成器を作り、その後それに乱数生成器を渡してスポーン位置を決める
	//TODO:リプレイ機能を付けるため、乱数の初期値を保存しよう
	uniform_int_distribution<> randDistribution(0, windowSizeX - width);
	int spawnXPos = randDistribution(mtRand_);
	int yPos = 0;

	DrawGraph(spawnXPos, yPos, fallingLeftImageHandle_, TRUE);
	caterpillerList_.push_back(unique_ptr<Caterpillar>(new Caterpillar(spawnXPos)));
}

void Caterpillar::moveCaterpillars() {
	for (int index = 0; index < caterpillerList_.size(); index++) {
		caterpillerList_[index]->move();
	}
}
