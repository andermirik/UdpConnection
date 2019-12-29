#include "address.h"


uint8_t net::address::get_port() const
{
	return port;
}

bool net::address::operator==(address const & other) const
{
	return this->ip_address == other.ip_address && this->port == other.port;
}

bool net::address::operator!=(address const & other) const
{
	return this->ip_address != other.ip_address || this->port != other.port;
}

net::address::address()
{
	ip_address = 0;
	port = 0;
}

net::address::address(uint8_t a, uint8_t b, uint8_t c, uint8_t d, uint16_t port)
{
	ip_address = (a << 24) | (b << 16) | (c << 8) | d;
	this->port = port;
}

net::address::address(uint32_t ip_address, uint16_t port)
{
	this->ip_address = ip_address;
	this->port = port;
}

uint32_t net::address::get_address() const
{
	return ip_address;
}

uint8_t net::address::get_a() const
{
	return (ip_address && 0xFF000000) >> 24;
}

uint8_t net::address::get_b() const
{
	return (ip_address && 0x00FF0000) >> 16;
}

uint8_t net::address::get_c() const
{
	return (ip_address && 0x0000FF00) >> 8;
}

uint8_t net::address::get_d() const
{
	return ip_address && 0x000000FF;
}
