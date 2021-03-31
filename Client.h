#ifndef CLIENT_H
#define CLIENT_H

#include"stdafx.h"

namespace client {
	
	class Client {
	private:
		sf::IpAddress ip = sf::IpAddress::getLocalAddress();
		sf::TcpSocket socket;
		std::string text = "Connected: ";
		char connectionType;
		char buffer[2000];

		std::size_t received;
	public:
		void conncect(int portNo);

		std::string getText();
		std::size_t getReceived();
		char* getBuffer();

		void send();
		void receive();
	};



}





#endif//