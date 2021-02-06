#ifndef GAME_H
#define GAME_H

#include"NNK_RPG.h"
#include"Character.h"
#include"Background.h"
#include"Buildings.h"

namespace nnk {
	enum class GameState{ End, Running};
	class Game {
	private:
		sf::RenderWindow* renderWindow;
		sf::Event gameEvent;
		
		character::Character character;
		background::Background background;
		buildings::Buildings buildings;

		GameState gameState = GameState::End;

		void initWindow(std::string windowName);
		

	public:
		Game();
		~Game();
		void setGameState(GameState gameState);
		GameState getGameState();
		bool getWindowIsOpen();

		void pollEvent();

		void init();
		void run();
		void update();
		void render();

	};

}


#endif   //GAME_H