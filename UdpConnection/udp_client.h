#pragma once
#include "address.h"
#include "udp_socket.h"

namespace net::udp {
	class client {
	public:
		void connect(net::address const& dest, int my_port);

		void send();
		void receive();

		void close();

	private:
		net::udp_socket sock;
	};
}