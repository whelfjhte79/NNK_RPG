#include"Cursor.h"

namespace cursor {
	void Cursor::render(sf::RenderWindow* renderWindow) {
		this->renderWindow = renderWindow;	
		this->img.read("images/Cursor",img::FileExtension::PNG);
		this->img.setPoint(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*this->renderWindow)));
		this->img.drawOne(this->renderWindow);
		//this->fixed = this->renderWindow->getView();
		//this->renderWindow->setView(this->fixed);
		this->renderWindow->setMouseCursorVisible(false);
		this->renderWindow->draw(this->img.getSprite());
	}
	void Cursor::update() {
		

	}
}