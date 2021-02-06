#ifndef NNK_RPG_H
#define NNK_RPG_H

#ifdef _WIN64


#else


#endif


#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Network.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/OpenGL.hpp>

#include<string>
#include<vector>


enum class ErrorType {
	Unknown,
	FileNotFound,
	NullptrError,
	IndexOutOfBounds,
	IOException
};
[[noreturn]] void except(ErrorType errorType);






#endif//NNK_RPG_H