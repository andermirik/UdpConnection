#include "udp_client.h"

void net::udp::client::connect(net::address const & dest, int my_port)
{
	sock.open(my_port);
	sock.send(dest, "", 25);
}

void net::udp::client::close()
{
	sock.close();
}
