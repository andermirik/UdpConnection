#include "udp_socket.h"
#include "platform.h"

#if PLATFORM == PLATFORM_WINDOWS

#include <winsock2.h>
#pragma comment( lib, "wsock32.lib" )

#elif PLATFORM == PLATFORM_MAC || PLATFORM == PLATFORM_UNIX

#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>

#endif

net::udp::udp_socket::udp_socket()
{
#if PLATFORM == PLATFORM_WINDOWS
	WSAData wsadata;
	WSAStartup(MAKEWORD(2, 2), &wsadata);
#endif
}

net::udp::udp_socket::~udp_socket()
{
#if PLATFORM == PLATFORM_WINDOWS 
	WSACleanup();
#endif
}

bool net::udp::udp_socket::open(uint32_t port)
{
	handle = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (handle <= 0) {
		return false;
	}

	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = htons(port);
	if (bind(handle, (const sockaddr*)&addr, sizeof(sockaddr_in)) < 0) {
		return false;
	}

#if PLATFORM == PLATFORM_WINDOWS

	DWORD nonBlocking = 1;
	if (ioctlsocket(handle, FIONBIO, &nonBlocking) != 0)
	{
		return false;
	}

#elif PLATFORM == PLATFORM_MAC || PLATFORM == PLATFORM_UNIX

	int nonBlocking = 1;
	if (fcntl(handle, F_SETFL, O_NONBLOCK, nonBlocking) == -1)
	{
		return false;
	}

#endif

	return true;
}


void net::udp::udp_socket::close()
{
#if PLATFORM == PLATFORM_WINDOWS
	closesocket(handle);
#elif PLATFORM == PLATFORM_MAC || PLATFORM == PLATFORM_UNIX
	close(handle);
#endif
}

bool net::udp::udp_socket::send(net::address const & dest, void const * data, uint32_t packet_size)
{
	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(dest.get_address());
	addr.sin_port = htons(dest.get_port());

	int sent_bytes = sendto(handle, (const char*)data, packet_size, 0, (const sockaddr*)&addr, sizeof(sockaddr_in));
	if (sent_bytes != packet_size) {
		return false;
	}
	return true;
}

int net::udp::udp_socket::receive(net::address & sender, void * data, uint32_t size)
{
	uint8_t packet_data[512];
	uint32_t maximum_packet_size = sizeof(packet_data);

#if PLATFORM == PLATFORM_WINDOWS
	typedef int socklen_t;
#endif

	sockaddr_in from;
	socklen_t fromLength = sizeof(from);

	int received_bytes = recvfrom(handle, (char*)packet_data, maximum_packet_size,
		0, (sockaddr*)&from, &fromLength);

	if (received_bytes <= 0)
		return received_bytes;

	unsigned int from_address = ntohl(from.sin_addr.s_addr);
	unsigned int from_port = ntohs(from.sin_port);

	sender = net::address(from_address, from_port);

	return received_bytes;
}
