#include"NNK_RPG.h"
#include"Game.h"

#include<iostream>
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

int main(void) {
	Game g;

	g.init();
	while (g.getGameState()==GameState::Running && g.getWindowIsOpen()) {
		g.run();
		g.update();
		g.render();



		//g.setGameState(GameState::END);
	}
	return 0;
}