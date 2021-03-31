#ifndef CURSOR_H
#define CURSOR_H
#include"Image.h"
#include"stdafx.h"
namespace cursor {
	class Cursor {
	private:
		sf::RenderWindow* renderWindow;
		sf::View fixed;
		img::ImageFile img;
		

	public:
		void render(sf::RenderWindow* renderWindow);
		void update();
		sf::Vector2f getMousePosition();
	};
}





#endif //CURSOR_H