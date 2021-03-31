#ifndef GAME_H
#define GAME_H

#include"stdafx.h"
#include"Character.h"
#include"Buildings.h"
#include"Cursor.h"
#include"MainMenu.h"
#include"Screen.h"

//Test
#include<iostream>

namespace nnk {
	enum class GameState{ End, Running};
	enum class CommunicationMode { Receive, Send };
	class Game {
	private:
		sf::RenderWindow* renderWindow;
		sf::Event gameEvent;
		// 캐릭터 좌표 저장해서 view에 넣기.
		sf::View view;
		
		cursor::Cursor cursor;
		sf::Vector2f cursorLocation;
		menu::MainMenu menu;
		character::Character character;
		std::list<character::Character> npcList;
		buildings::Buildings buildings;
		screen::Screen screen;

		GameState gameState = GameState::End;

		// server & client
		const int PORT_NO = 2000;
		CommunicationMode communicationMode;
#ifdef SERVER
		server::Server server;
#elif defined CLIENT
		client::Client client;
#else
#endif

		void initWindow(std::string windowName);
		void setView();
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
		
		//server & client
		void initCommunication();
		void communication();

	};

}


#endif   //GAME_H