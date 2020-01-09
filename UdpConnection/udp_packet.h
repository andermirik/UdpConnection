#pragma once
namespace net::udp {
	struct packet {
		unsigned int proto_id;
		unsigned int seq_number;
		unsigned int flag;
		unsigned int ack;
		unsigned int ack_bitmap;
		char data[512];
	};
}