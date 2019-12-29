#pragma once
#include <iostream>
#include "address.h"
namespace net::udp{
	class udp_socket {
	public:
		udp_socket();
		~udp_socket();

		bool open(uint32_t port);
		void close();

		bool send(net::address const& dest, void const* data, uint32_t size);
		int receive(net::address& sender, void* data, uint32_t size);

	private:
		int handle;
	};
}