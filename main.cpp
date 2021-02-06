

/*
#include<iostream>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<SFML/OpenGL.hpp>
#include<SFML/Window/Keyboard.hpp>
#include<SFML/Graphics.hpp>




int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Hello world", sf::Style::Close);
	sf::Vector2i v;
	sf::ContextSettings cs;
	
	sf::Texture texture;

	texture.loadFromFile("images/bullet.png");

	sf::Sprite sprite(texture);

	v.x = 50;
	v.y = 50;
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
	while (window.isOpen()) {
		sf::Event e;
		while (window.pollEvent(e)) {
			if (e.type == sf::Event::Closed)
				window.close();
		}
		glClear(GL_COLOR_BUFFER_BIT);
		//window.clear();
		window.draw(sprite);
		window.display();
	}
}
*/


/*
int main() {
	sf::Window window(sf::VideoMode(800, 600), "Hello world", sf::Style::Close);
	sf::Vector2i v;
	sf::ContextSettings cs;
	
	
	v.x = 50;
	v.y = 50;
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
	while (window.isOpen()) {
		sf::Event e;
		while (window.pollEvent(e)) {
			if (e.type == sf::Event::Closed)
				window.close();
			if (e.type == sf::Event::KeyPressed) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)|| sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
					std::cout << "testLEFT" << std::endl;
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)|| sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
					std::cout << "testRight" << std::endl;
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)|| sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
					std::cout << "testUp"<< std::endl;
				}
				else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)|| sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
					std::cout << "testDown" << std::endl;
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
					std::cout << "프로그램을 종료합니다.";
					window.close();
				}
				
			}
			if (e.type == sf::Event::MouseButtonPressed) {
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					std::cout << "마우스왼쪽";
				}
				else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
					std::cout << "마우스오른쪽";
				}
				else if (sf::Mouse::isButtonPressed(sf::Mouse::Middle)) {
					std::cout << "마우스 휠버튼";
				}
			}
			if (e.type == sf::Event::MouseWheelScrolled) {
					std::cout << "아래휠";	
			}
		}
		glClear(GL_COLOR_BUFFER_BIT);
		
		window.display();
	}
}
*/