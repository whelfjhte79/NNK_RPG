#ifndef BACKGROUND_H
#define BACKGROUND_H

#include"Image.h"
namespace background {
	enum class MapList {

	};

	class Background {
	private:
		img::Image img;

		
	public:
		void init();
		void update();
		void render(sf::RenderTarget* target);
	};

	class Tiles {
	private:

	public:

	};
}

#endif //BACKGROUND_H