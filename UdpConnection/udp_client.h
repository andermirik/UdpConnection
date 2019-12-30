#pragma once
namespace net::udp {
	class client {
		void connect();

		void send();
		void recive();

		void close();
	};
}