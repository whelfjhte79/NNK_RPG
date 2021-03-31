#include"Animation.h"

namespace animation {
	Animation::Animation(float deltaTime, float totalTime, float switchTime) {
	}
	Animation::~Animation() {}

	void Animation::setImg(img::ImageFile dynamicImg) {
		this->dynamicImg = dynamicImg;
	}
	void Animation::update(float deltaTime) {
		this->totalTime += deltaTime;
		if (this->switchTime >= totalTime) {
			this->totalTime = 0.0f;
		}
	}
	
}

