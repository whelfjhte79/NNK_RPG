#ifndef SERVER_H
#define SERVER_H

#include"stdafx.h"
#include<iostream>
namespace server {

	class Server {
	private:
		sf::IpAddress ip = sf::IpAddress::getLocalAddress();
		sf::TcpSocket socket;
		std::string text = "Connected: ";
		char connectionType;
		char buffer[2000];
		std::size_t received;
	public:
		void listen(int portNo);

		std::string getText();
		std::size_t getReceived();
		char* getBuffer();

		void send();
		void receive();
	
	};



#ifdef TEST
	void server();
#endif
}



#endif//