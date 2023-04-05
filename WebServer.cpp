#include "Server.hpp"
#include "Color.hpp"

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << yellow << bold << "INFO: " << reset << cyan << "Usage: ./server <port>" << def << std::endl;
		exit(EXIT_FAILURE);
	}

	int port = atoi(argv[1]);
	if (port < 1024 || port > 65535) {
		std::cout << red << "ERROR: " << cyan << "Port must be between 1024 and 65535." << def << std::endl;
		exit(EXIT_FAILURE);
	}

	Server server;
	try {
		server.run();
		std::cout << green << "✅ Socket created successfully." << reset << std::endl;
		server.bind(port);
		std::cout << green << "✅ Socket binded successfully." << reset << std::endl;
		server.listen();
		std::cout << green << "✅ Server listening on 127.0.0.1:" << server.getPort() << "." << reset << std::endl;

		int new_socket;
		struct sockaddr_in address;
		int addrlen = sizeof(address);
		char buffer[1024] = {0};

		while (true) {
			std::cout << blink << "Waiting for new connection..." << reset << std::endl;
			if ((new_socket = accept(server.getSocketFd(), (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0)
				throw "Failed to accept connection.";
			read(new_socket, buffer, 1024);
			std::cout << buffer << std::endl;
			std::string response = "HTTP/1.1 200 OK\n";
			server.send(new_socket, response.c_str());
		}
	}
	catch (const char *e) {
		std::cout << red << e << reset << std::endl;
		server.clear();
		exit(EXIT_FAILURE);
	}
	return 0;
}