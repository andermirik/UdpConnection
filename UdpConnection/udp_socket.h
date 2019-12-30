#pragma once
#include <iostream>
#include "address.h"
namespace net{
	class udp_socket {
	public:
		udp_socket();
		~udp_socket();

		bool open(uint32_t port);
		bool is_open();
		void close();

		bool send(net::address const& dest, void const* data, uint32_t size);
		int receive(net::address& sender, void* data, uint32_t size);

	private:
		int handle;
		bool _is_open;
	};
}