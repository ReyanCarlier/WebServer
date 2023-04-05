#include "Server.hpp"

#include <sys/socket.h>

Server::Server() : _socket_fd(0), _port(0), _max_connections(0), _max_body_size(0)
{
}

Server::~Server() {}

// Setters
void Server::setPort(int port) {
	_port = port;
}
void Server::setMaxConnections(int max_connections) {
	_max_connections = max_connections;
}
void Server::setMaxBodySize(int max_body_size) {
	_max_body_size = max_body_size;
}
void Server::setSocketFd(int socket_fd) {
	_socket_fd = socket_fd;
}

// Getters
int Server::getPort() const {
	return _port;
}
int Server::getMaxConnections() const {
	return _max_connections;
}
int Server::getSocketFd() const {
	return _socket_fd;
}
int Server::getMaxBodySize() const {
	return _max_body_size;
}

// Methods
void Server::run() {
	_socket_fd = socket(2, 1, 0);
	if (_socket_fd == -1)
		throw "Failed to create socket.";
}
void Server::bind(int port) {
	_address.sin_family = AF_INET;
	_address.sin_addr.s_addr = INADDR_ANY;
	_address.sin_port = htons(port);
	_port = port;

	if (::bind(_socket_fd, (struct sockaddr *)&_address, sizeof(_address)) < 0)
		throw "Failed to bind socket.";
}
void Server::listen() {
	if (::listen(_socket_fd, _max_connections) < 0)
		throw "Failed to listen on socket.";
}

void Server::send(int socket_fd, std::string response) {
	if (::send(socket_fd, response.c_str(), response.length(), MSG_DONTWAIT) < 0)
		throw "Failed to send response.";
	std::cout << "[SERVER => CLIENT("<< socket_fd << ")] " << response << std::endl;
}

void Server::clear()
{
	if (_socket_fd)
		close(_socket_fd);
	if (_address.sin_addr.s_addr)
		delete &_address;
}
