#include"Server.h"



namespace server {
	void Server::listen(int portNo) {
		sf::TcpListener listener;
		listener.listen(portNo);
		listener.accept(socket);
	}

	std::string Server::getText() {
		return this->text;
	}
	std::size_t Server::getReceived() {
		return this->received;
	}
	char* Server::getBuffer() {
		return this->buffer;
	}

	void Server::send() {
		socket.send(text.c_str(), text.length() + 1);
	}
	void Server::receive() {
		socket.receive(buffer, sizeof(buffer), received);
	}


#ifdef TEST
	void server() {
		sf::IpAddress ip = sf::IpAddress::getLocalAddress();
		sf::TcpSocket socket;
		char connectionType, mode;
		char buffer[2000];
		std::size_t received;

		std::string text = "Connected to: ";

		std::cout << "Enter (s) for sever, Enter (c) for client:" << std::endl;

		std::cin >> connectionType;

		if (connectionType == 's') {
			sf::TcpListener listener;
			listener.listen(2000);  // port ¹øÈ£
			listener.accept(socket);

			text += "Server";
			mode = 's';
		}
		else if (connectionType == 'c') {
			socket.connect(ip, 2000);
			text += "Client";
			mode = 'r';
		}
		socket.send(text.c_str(), text.length() + 1);

		socket.receive(buffer, sizeof(buffer), received);

		std::cout << buffer << std::endl;

		bool done = false;

		while (!done) {
			if (mode == 's') {
				std::getline(std::cin, text);
				socket.send(text.c_str(), text.length() + 1);
				mode = 'r';
			}
			else if (mode == 'r') {
				socket.receive(buffer, sizeof(buffer), received);

				if (received > 0) {
					std::cout << "Received: " << buffer << std::endl;
					mode = 's';
				}
			}
		}
	}
#endif

}



