#pragma once

namespace Network {

	class Client {
	protected:
		const int DEFAULT_PORT;
	public:
		//static void connect(int* port);
		static const u_short DEFAULT_PORT = 54000;
	};
}