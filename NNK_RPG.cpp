#include"NNK_RPG.h"
#include<iostream>
#include"Game.h"
using namespace nnk;

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

}
#else
void nnk_rpg() {
	Game g;
	g.init();
	while (g.getGameState() == GameState::Running && g.getWindowIsOpen()) {
		g.getRenderWindow()->clear();
		g.render();
		g.update();

		g.getRenderWindow()->display();
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