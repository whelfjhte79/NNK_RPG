#ifndef CURSOR_H
#define CURSOR_H
#include"Image.h"
#include"NNK_RPG.h"
namespace cursor {
	class Cursor {
	private:
		sf::RenderWindow* renderWindow;
		sf::View fixed;
		img::Image img;
		

	public:
		void render(sf::RenderWindow* renderWindow);
		void update();
		
	};
}





#endif //CURSOR_H