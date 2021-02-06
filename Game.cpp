#include"Game.h"


namespace nnk {
	Game::Game() {
		this->initWindow("testWindow");

	}
	Game::~Game() {
		delete this->renderWindow;
	}
	void Game::init() {
		this->gameState = GameState::Running;
	}
	void Game::run() {
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		//background
		/**
		* background 안에 buildings.render넣기
		*/


		this->background.render();

		//object-draw
		if (this->character.getDeadFlags()) {

		}
		this->character.render(this->renderWindow);

		
		//poll Event   screen
		this->pollEvent();




		glClear(GL_COLOR_BUFFER_BIT);
		renderWindow->display();
	}
	void Game::render() {
		this->renderWindow->clear();
		this->character.render(this->renderWindow);


		this->renderWindow->display();
	}
	void Game::update() {

	}
	void Game::initWindow(std::string windowName) {
		renderWindow = new sf::RenderWindow(sf::VideoMode(800,600),windowName,sf::Style::Close | sf::Style::Titlebar);

	}
	void Game::setGameState(GameState gameState) {
		this->gameState = gameState;
	}
	GameState Game::getGameState() {
		return this->gameState;
	}
	bool Game::getWindowIsOpen() {
		return this->renderWindow->isOpen();
	}
	void Game::pollEvent() {
		while (this->renderWindow->pollEvent(this->gameEvent)) {
			if (this->gameEvent.type == sf::Event::Closed) {
				// 정말 종료하시겠습니까? 이벤트 넣기
				
				this->renderWindow->close();
			}
			else if (this->gameEvent.type == sf::Event::Resized) {

			}
			else if (this->gameEvent.type == sf::Event::KeyPressed) {
				//if(this->)
			}
			else if (this->gameEvent.type == sf::Event::MouseButtonPressed) {

			}
			else if (this->gameEvent.type == sf::Event::MouseMoved) {

			}
			else if (this->gameEvent.type == sf::Event::MouseWheelScrolled) {

			}
			

		}
	}
}
