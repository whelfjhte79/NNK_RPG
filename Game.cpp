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
	void Game::render() {
		this->renderWindow->clear(sf::Color::Green);

		//glClearColor(1.0f, 1.0f, 0.0f, 0.0f);
	    this->background.render(this->renderWindow);
		this->character.render(this->renderWindow);
		this->cursor.render(this->renderWindow);

		
		//glClear(GL_COLOR_BUFFER_BIT);
		this->renderWindow->display();
	}
	void Game::update() {

		if (this->gameState != GameState::End) {

			this->pollEvent();
			this->cursor.update();
			this->background.update();
			this->character.update();
			
			// if ESC setGameState(GameState::END);
		
		}
	}
	void Game::initWindow(std::string windowName) {
		renderWindow = new sf::RenderWindow(sf::VideoMode(1000, 800), windowName, sf::Style::Close | sf::Style::Titlebar);

		/*
		init page
		init button
		*/

	}
	void Game::setGameState(GameState gameState) {
		this->gameState = gameState;
	}
	GameState Game::getGameState() {
		return this->gameState;
	}
	sf::RenderWindow* Game::getRenderWindow() {
		return this->renderWindow;
	}
	bool Game::getWindowIsOpen() {
		return this->renderWindow->isOpen();
	}

	void Game::pollEvent() {
		bool bLShiftPressed = false;
		float step=0.0f;
		while (this->renderWindow->pollEvent(this->gameEvent)) {
			if (this->gameEvent.type == sf::Event::Closed) {
				// 정말 종료하시겠습니까? 이벤트 넣기
				
				this->renderWindow->close();
			}
			else if (this->gameEvent.type == sf::Event::Resized) {

			}
			else if (this->gameEvent.type == sf::Event::KeyPressed) {

				//keyboard WASD
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
					
					this->character.move(-this->character.getStep(), 0.0f);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
					this->character.move(this->character.getStep(), 0.0f);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
					this->character.move(0.0f, this->character.getStep());
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
					this->character.move(0.0f, -this->character.getStep());
				}
				//ctrl + key
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
						//Game Save
					}
				}
				
			}
			else if (this->gameEvent.type == sf::Event::MouseButtonPressed) {

			}
			else if (this->gameEvent.type == sf::Event::MouseMoved) {

			}
			else if (this->gameEvent.type == sf::Event::MouseWheelScrolled) {

			}
			
		


		}
	}
	
	//attribute
	void Game::addNPC(character::Character npc){
		this->npcList.push_back(npc);
	}
	void Game::deleteNPC(std::string npcName) {
		for (std::list<character::Character>::iterator itr = this->npcList.begin(); itr != this->npcList.end(); ++itr) {
			if ((*itr).getName() == npcName) {
				this->npcList.erase(itr);
			}
		}
	}

}
