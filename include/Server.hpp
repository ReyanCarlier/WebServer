#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstdlib> // For exit() and EXIT_FAILURE

/**
 * @brief Server class for the web server. Contains all the information about the server.
 * 
 */
class Server {
	public:
		Server();
		~Server();

		// Getters
		int getPort() const;
		int getMaxConnections() const;
		int getMaxBodySize() const;
		int getSocketFd() const;

		// Setters
		void setPort(int);
		void setMaxConnections(int);
		void setMaxBodySize(int);
		void setSocketFd(int);
		
		// Methods
		void bind(int port);
		void listen();
		void run();
		void send(int socket_fd, std::string response);

	private:
		sockaddr_in _address;
		int _socket_fd;
		int _port;
		int _max_connections;
		int _max_body_size;
};