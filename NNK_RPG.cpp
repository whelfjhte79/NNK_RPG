#include"NNK_RPG.h"
#include<iostream>
#include"Game.h"
using namespace nnk;


/**
*    Todolist : 
*	 
*	 animation 구현. 유니티처럼 하면 될 듯
*    key input 구현
*    button 및 screen 구현

*/




//#define TEST  // Test 
#ifdef TEST 
#include"Test.h"
#endif


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

	/*
		test.getSprite().setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*test.getWindow())));
		test.getWindow()->clear();
		test.getWindow()->setView(test.getView());
		test.getWindow()->draw(test.getSprite());
		test.getWindow()->display();
	*/


	/*
	    sf::RenderWindow window(sf::VideoMode(800, 600), "Hidden Cursor");
    window.setMouseCursorVisible(false); // Hide cursor
    
    sf::View fixed = window.getView(); // Create a fixed view
    
    // Load image and create sprite
    sf::Texture texture;
    texture.loadFromFile("cursor.png");
    sf::Sprite sprite(texture);
    
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // Set position        
        sprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
        
        window.clear();
        window.setView(fixed);
        window.draw(sprite);
        window.display();
    }
	
	*/
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
#else
	nnk_rpg();
#endif
	return 0;
}