#include"stdafx.h"
#include<iostream>
#include"Game.h"

using namespace nnk;


[[noreturn]] void except(ErrorType errorType) {
	switch (errorType) {
	case ErrorType::Unknown:
		std::cout << "Unknown Exception";
		break;
	case ErrorType::FileNotFound:
		std::cout << "File Not Found Exception";
		break;
	case ErrorType::NullptrError:
		std::cout << "NullptrError";
		break;
	case ErrorType::IndexOutOfBounds:
		std::cout << "out of bound";
		break;
	case ErrorType::IOException:
		std::cout << "io exception";
		break;
	default:
		break;
	}
}

#ifdef TEST
void test() {
	Test test;
	test.setWindow(new sf::RenderWindow(sf::VideoMode(800, 600), "Hidden Cursor"));
	test.render();
	
	//sf::RenderWindow window(sf::VideoMode(800, 600), "Hidden Cursor");
	test.getWindow()->setMouseCursorVisible(false); // Hide cursor

	
	while (test.getWindow()->isOpen())
	{
		sf::Event event;
		while (test.getWindow()->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				test.getWindow()->close();
			}
		}
		test.update();

		test.getWindow()->display();
	}

}
void test2() {
	sf::Texture text;
	const std::string filename = "C:\\Users\\¿ÃªÛπŒ\\source\\repos\\Game_OpenGL\\Game_OpenGL\\images\\MainMenu\\MainMenu.png";
	text.loadFromFile(filename);
}
#else
void nnk_rpg() {
	Game g;
	g.init();
	while (g.getGameState() == GameState::Running && g.getWindowIsOpen()) {
		g.render();
		g.update();
	}
}
#endif
int main(void) {
	
#ifdef TEST
	test();
	//server::server();
	//test2();
#else
	nnk_rpg();
#endif
	return 0;
}