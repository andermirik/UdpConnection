#pragma once
namespace udp {
	struct packet {
		unsigned int proto_id;
		unsigned int seq_number;
		unsigned int ack;
		unsigned int ack_bitmap;
		char data[512];
	};
}