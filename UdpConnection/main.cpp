#include <iostream>
#include "udp_socket.h"
#include <string>

int read_int(std::string str) {
	int _int;
	std::cout << str;
	std::cin >> _int;
	return _int;
}

int main() {
	int port = read_int("my port: ");
	int port2 = read_int("to port: ");

	net::udp::udp_socket sock;
	sock.open(port);

	std::string s = "hello from " + std::to_string(port) + "\n";

	while (true) {
		net::address sender;
		char data[256] = { 0 };
		sock.send(net::address(127, 0, 0, 1, port2), s.c_str(), s.size());
		if (sock.receive(sender, data, sizeof(data)) != -1) {
			std::cout << sender.get_port() << ": " << std::endl;
			std::cout << data << std::endl;
		}
	}

	return(0);
}