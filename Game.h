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
		std::list<character::Character> npcList;
		background::Background background;
		buildings::Buildings buildings;

		GameState gameState = GameState::End;
		
		//TEST
		/**
		* ���� : cursor �̵� �����ϰ� ����.
		*       Ŀ�� ���� ������ �����ϱ�
		*/
		img::Image cursorImg;
		//TestEnd
		sf::Sprite cursor;
		sf::View fixed;

		void initWindow(std::string windowName);
		void cursorDraw();

	public:
		Game();
		~Game();
		void setGameState(GameState gameState);
		GameState getGameState();
		sf::RenderWindow* getRenderWindow();
		bool getWindowIsOpen();

		void pollEvent();

		void addNPC(character::Character npc);
		void deleteNPC(std::string npcName);

		void init();
		void render();
		void update();
		

	};

}


#endif   //GAME_H