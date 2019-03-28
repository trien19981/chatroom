#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib,"ws2_32.lib")
#include<winsock.h>
#include<string>
#include<iostream>
class Server
{
public:
	Server(int port);
	bool listenConnection();
	~Server();

private:
	SOCKADDR_IN addr;
	int addrlen = sizeof(addr);
	SOCKET listening;
};