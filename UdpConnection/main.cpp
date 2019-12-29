#include <iostream>
#include "udp_socket.h"
#include <string>
int main() {
	int port;
	int port2;
	std::cout << "src port: ";
	std::cin >> port;
	std::cout << "dst port: ";
	std::cin >> port2;

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