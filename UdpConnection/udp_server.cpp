#include "udp_server.h"

bool net::udp::server::listen(int port)
{
	bool is_open = sock.open(port);

	if (is_open == false)
		return false;

	return true;
}

int net::udp::server::accept()
{
	return 0;
}

void net::udp::server::close()
{
	sock.close();
}
