#include"Client.h"

namespace client {
	void Client::conncect(int portNo) {
		this->socket.connect(ip,portNo);
	}

	std::string Client::getText() {
		return this->text;
	}
	std::size_t Client::getReceived() {
		return this->received;
	}
	char* Client::getBuffer() {
		return this->buffer;
	}
	void Client::send() {
		this->socket.send(text.c_str(), text.length() + 1);
	}
	void Client::receive() {
		this->socket.receive(buffer, sizeof(buffer), received);
	}

}