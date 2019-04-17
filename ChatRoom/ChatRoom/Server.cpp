#include "Server.h"



Server::Server() {
	WSAData wsadata;
	WORD dllVersion = MAKEWORD(2, 1);

	if (WSAStartup(dllVersion, &wsadata) != 0) {
		MessageBox(NULL, "Winsock start failed", "Error", MB_OK | MB_ICONERROR);
		exit(1);
	}
	conf.taiConfigServer();
	addr.sin_addr.s_addr = inet_addr(conf.getIpServer().c_str());  // tao dia chi may chu
	addr.sin_port = htons(conf.getPortServer()); //tao cong ket noi
	addr.sin_family = AF_INET; //dat loai dia chi ip la ipv4

	// tao socket de lang nghe ket noi den
	listening = socket(AF_INET, SOCK_STREAM, NULL);
	//ket noi dia chi toi socket 
	if (bind(listening, (SOCKADDR*)&addr, sizeof(addr)) == SOCKET_ERROR) {
		std::string errorMsg = "Faild to bind the address to listening socket! Winsock error: " + std::to_string(WSAGetLastError());
		MessageBoxA(NULL, errorMsg.c_str(), "Error", MB_OK || MB_ICONERROR);
		exit(1);
	}
	if (listen(listening, SOMAXCONN) == SOCKET_ERROR) {
		std::string errorMsg = "Fail listening on listen socket! Winsock error: " + std::to_string(WSAGetLastError());
		MessageBoxA(NULL, errorMsg.c_str(), "Error", MB_OK || MB_ICONERROR);
		exit(1);
	}

	room.dsMember();
	room.dsBan();
	room.dsFilter();
	room.dsMod();

	std::cout << conf.getIpServer() << ":" << conf.getPortServer() << std::endl;
}
bool Server::listenConnection() {
	std::cout << "Waiting..." << std::endl;
	SOCKET newConnect = accept(listening, (SOCKADDR*)&addr, &addrlen);
	if (newConnect == 0) {
		std::cout << "Fail to accept the client connection. " << std::endl;
		return false;
	}
	else {
		char data[1024];
		ZeroMemory(data, sizeof(data));
		recv(newConnect, data, sizeof(data), 0);
		if (strcmp(data, "2") == 0) {
			ZeroMemory(data, sizeof(data));
			recv(newConnect, data, sizeof(data), 0);
			if (room.checkName(std::string(data))) {
				sess.themketnoi(newConnect, std::string(data));
				std::cout << "Client connected!" << std::endl;
				char sucessMsg[15] = "sucessfully";
				send(newConnect, sucessMsg, sizeof(sucessMsg), 0);
				std::thread t(createHandle, newConnect);
				t.detach();
			}
			else {
				char errMsg[100] = "Check username again!";
				send(newConnect, errMsg, sizeof(errMsg), 0);

			}
		}
	}
	return true;
}


Server::~Server()
{
}

void Server::createHandle(SOCKET s) {
	sess.tinnhanluong(s);
}