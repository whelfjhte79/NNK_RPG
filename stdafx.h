#ifndef STDAFX_H
#define STDAFX_H

#ifdef _WIN64


#else


#endif

#ifdef _DEBUG

#pragma comment(lib,"sfml-main-d.lib")
#pragma comment(lib,"sfml-graphics-d.lib")
#pragma comment(lib,"sfml-window-d.lib")
#pragma comment(lib,"sfml-system-d.lib")
#pragma comment(lib,"sfml-audio-d.lib")
#pragma comment(lib,"sfml-network-d.lib")


#else

#pragma comment(lib,"sfml-main.lib")
#pragma comment(lib,"sfml-graphics.lib")
#pragma comment(lib,"sfml-window.lib")
#pragma comment(lib,"sfml-system.lib")
#pragma comment(lib,"sfml-audio.lib")
#pragma comment(lib,"sfml-network.lib")

#endif

#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Network.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/OpenGL.hpp>

#include<string>
#include<vector>
#include<list>




enum class ErrorType {
	Unknown,
	FileNotFound,
	NullptrError,
	IndexOutOfBounds,
	IOException
};
[[noreturn]] void except(ErrorType errorType);


//#define SERVER
#define CLIENT
//#define TEST

#ifdef SERVER 
#include"Server.h"
#elif defined CLIENT 
#include"Client.h"
#elif defined TEST
#include"Test.h"
#include"Server.h"

#endif



#endif//STDAFX_H