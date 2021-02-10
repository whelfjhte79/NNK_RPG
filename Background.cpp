#include"Background.h"

namespace background {

	void Background::init() {

	}
	void Background::render(sf::RenderTarget* target) {
		this->img.read("images/Background/Background", img::FileExtension::PNG);
		this->img.setPoint(sf::Vector2f(0.0f,0.0f));
		this->img.drawOne(target);
		target->draw(this->img.getSprite());
	}
	void Background::update() {
		
	}
}