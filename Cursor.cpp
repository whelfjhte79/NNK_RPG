#include"Cursor.h"

#include<iostream>


namespace cursor {
	void Cursor::render(sf::RenderWindow* renderWindow) {
		this->renderWindow = renderWindow;	
		this->img.read("images/Cursor/Cursor",img::FileExtension::PNG);
		this->img.setPoint(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*this->renderWindow)));
		this->img.setSprite();
		
		this->fixed = this->renderWindow->getView();
		//this->renderWindow->setView(this->fixed);
		this->renderWindow->setMouseCursorVisible(false);
		
		this->img.draw(renderWindow);
	}
	void Cursor::update() {
		

	}
	sf::Vector2f Cursor::getMousePosition() {
		return this->img.getPoint();
	}
}