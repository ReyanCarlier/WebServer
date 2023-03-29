#include "Server.hpp"

#include <netinet/in.h> // For sockaddr_in
#include <cstdlib> // For exit() and EXIT_FAILURE
#include <iostream> // For cout
#include <unistd.h> // For read

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "Usage: ./server <port>" << std::endl;
		exit(EXIT_FAILURE);
	}

	int port = atoi(argv[1]);
	if (port < 1024 || port > 65535) {
		std::cout << "Port must be between 1024 and 65535." << std::endl;
		exit(EXIT_FAILURE);
	}

	Server server;
	try {
		server.run();
		std::cout << "Socket created successfully." << std::endl;
		server.bind(port);
		std::cout << "Socket binded successfully." << std::endl;
		server.listen();
		std::cout << "Socket listening successfully." << std::endl;

		int new_socket;
		struct sockaddr_in address;
		int addrlen = sizeof(address);
		char buffer[1024] = {0};

		while (true) {
			if ((new_socket = accept(server.getSocketFd(), (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0)
				throw "Failed to accept connection.";
			read(new_socket, buffer, 1024);
			std::cout << buffer << std::endl;
			std::string response = "J'ai recu ton message. \n";
			// Currently, the server only sends a response to the client. It does not handle the request.
			// Compatible with telnet.
			server.send(new_socket, response.c_str());
			close(new_socket);
		}
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		exit(EXIT_FAILURE);
	}
	return 0;
}