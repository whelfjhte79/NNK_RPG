#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include"stdafx.h"
#include"Image.h"
#include"Cursor.h"
namespace menu {
	
	class Button {
	private:
		img::ImageFile img;
		std::string fileName = "images/MainMenu/Button/";
	public:
		Button();
		void setButtonPoint(sf::Vector2f point);
		sf::Vector2u getButtonSize();

		void update();
		void render(sf::RenderTarget* target);
	};
	class MainMenu {
	private:
		img::ImageFile img;
		std::string linkName;
		std::string fileName;
		sf::RenderWindow* renderWindow;
		cursor::Cursor cursor;
		Button start;
		Button Exit;
		bool bRunning = true;

		void pollEvent();
	public:
		void setLinkName(std::string name);
		void setFileName(std::string name);

		void makeButton();
		void setRenderWindow(sf::RenderWindow* renderWindow);
		void render(sf::RenderTarget* target);
		void update();
		bool getRunning();
	};

}






#endif//MAIN_MENU_H