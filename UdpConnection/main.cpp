#include <iostream>
#include "udp_socket.h"

int main() {

	net::udp::udp_socket sock2;
	sock2.open(27002);

	net::udp::udp_socket sock;
	sock.open(27001);


	sock.send(net::address(127, 0, 0, 1, 27002), "hello from 27001", strlen("hello from 27001"));
	sock2.send(net::address(127, 0, 0, 1, 27001), "hello from 27002", strlen("hello from 27002"));

	net::address sender;
	char data[512];
	sock2.receive(sender, data, sizeof(data));



	return(0);
}