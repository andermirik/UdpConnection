#pragma once
#include <iostream>
namespace net {
	class address {
	public:
		address();
		address(uint8_t a, uint8_t b, uint8_t c, uint8_t d, uint16_t port);
		address(uint32_t ip_address, uint16_t port);

		uint32_t get_address() const;
		uint8_t get_a() const;
		uint8_t get_b() const;
		uint8_t get_c() const;
		uint8_t get_d() const;
		uint16_t get_port() const;

		bool operator==(address const& other) const;
		bool operator!=(address const& other) const;

	private:
		uint16_t port;
		uint32_t ip_address;
	};
}