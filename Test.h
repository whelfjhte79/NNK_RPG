#ifndef TEST_H
#define TEST_H
#include"NNK_RPG.h"
class Test {
private:
	sf::RenderWindow* window;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::View fixed;
public:
	void render(){
		this->texture.loadFromFile("images/Cursor.png");
		this->sprite=sf::Sprite(texture);
		fixed = this->window->getView();
	}
	void update(){
		//static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window))
		this->sprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window)));
		window->clear();
		window->setView(fixed);
		window->draw(sprite);
	}

	void setWindow(sf::RenderWindow* window) {
		this->window = window;
	}
	sf::RenderWindow* getWindow() {
		return window;

	}
	sf::View getView() {
		return fixed;
	}
	sf::Sprite getSprite() {
		return sprite;
	}
};

#endif// TEST_H