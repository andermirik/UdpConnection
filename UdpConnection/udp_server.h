#pragma once
#include "udp_socket.h"
#include "udp_packet.h"
#include <vector>


namespace net::udp {
	class server {
	public:
		bool listen(int port);

		int accept();
		void send(int handle, void const* data, int size);
		void receive(int handle, void const* data, int size);

		void close();
	private:
		udp_socket sock;
		std::vector<std::vector<packet>> packets;
	};
}