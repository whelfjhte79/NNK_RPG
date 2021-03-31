#include"MainMenu.h"
#include<iostream>
namespace menu {

	void MainMenu::setRenderWindow(sf::RenderWindow* renderWindow) {
		this->renderWindow = renderWindow;
	}
	void MainMenu::pollEvent() {
		sf::Event evt;
		if (this->renderWindow == NULL) {
			std::cout << "render is null";
		}
		while (this->renderWindow->pollEvent(evt)) {
			if (evt.type == sf::Event::MouseButtonPressed) {
				// buttonEndX < mouse X < buttonStartX
				// buttonEndY < mouse Y < buttonStartY
			}
			else if (evt.type == sf::Event::Closed) {
				this->bRunning = false;
				this->renderWindow->close();
			}

		}
	}
	void MainMenu::makeButton() {
		// button »ý¼º
		//
		//img::Image img(;

	}
	void MainMenu::render(sf::RenderTarget* target) {
		this->setLinkName("images/MainMenu/");
		this->setFileName("MainMenu");
		
		this->img = img::ImageFile(this->linkName + this->fileName, img::FileExtension::PNG, 0.0f, 0.0f, target);

	}
	void MainMenu::update() {
		this->pollEvent();
		
	}

	void MainMenu::setLinkName(std::string name) {
		this->linkName = name;
	}
	void MainMenu::setFileName(std::string name) {
		this->fileName = name;
	}
	bool MainMenu::getRunning() {
		return this->bRunning;
	}

	Button::Button() {
		
	}
	void Button::setButtonPoint(sf::Vector2f point) {
		this->img.setPoint(point);
	}
	sf::Vector2u Button::getButtonSize() {
		return this->img.getImgSize();
	}
	void Button::render(sf::RenderTarget* target) {
		this->img = img::ImageFile(this->fileName + "StartButton", img::FileExtension::JPG, this->img.getPoint().x, this->img.getPoint().y, target);
	}
	void Button::update() {

	}
}