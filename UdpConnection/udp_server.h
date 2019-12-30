#pragma once
#include "udp_socket.h"

namespace net::udp {
	class server {
		bool start(int port);

		net::address accept();
		void send();
		void recive();

		void close();
	};
}