#include "DxLib.h"
#include "Caterpillar.h"

vector<Caterpillar*> Caterpillar::caterpillers_;

Caterpillar::Caterpillar() {
	caterpillers_.push_back(this);

	posY_ = 0;
}



//矩形の当たり判定
bool Caterpillar::checkHit(int objectLeft, int objectRight, int objectTop, int objectButtom) {
	int caterpillarSizeX, caterpillerSizeY;
	GetGraphSize(imageHandle_, &caterpillarSizeX, &caterpillerSizeY);
	int caterpillarLeft = posX_;
	int caterpillarRight = posX_ + caterpillarSizeX;
	int caterpillarLeftButtom = posY_ + caterpillerSizeY;

	bool hit = false;
	//オブジェクトの右端が左端より右かつ、オブジェクトの左端が右端より左
	if (objectRight > caterpillarLeft && objectLeft < caterpillarRight) {
		int caterpillarTop = posY_;
		int caterpillarButtom = posY_ + caterpillerSizeY;
		
		//上の判定を上端、下端で同じように行う
		if (caterpillarTop > objectButtom && caterpillarButtom < objectTop) {
			hit = true;
		}
	}

	return hit;
}