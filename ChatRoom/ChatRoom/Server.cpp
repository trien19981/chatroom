#include "Server.h"



Server::Server()
{
	WSADATA wsadata;
	WORD dllVersion = MAKEWORD(2, 1);

	if (WSAStartup(dllVersion, &wsadata) != 0) {
		MessageBox(NULL, " khoi tao that bai", "loi", MB_OK | MB_ICONERROR);
		exit(1);
	}
	config.loadConfigServer();


	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(config.getPortServer);
	addr.sin_family = AF_INET;

	listening = socket(AF_INET, SOCK_STREAM, NULL);

	if (bind(listening,(SOCKADDR*)&addr,sizeof(addr))== SOCKET_ERROR)
	{
		std::string error = "khong ket noi duoc voi socket" + std::to_string(WSAGetLastError());
		MessageBoxA(NULL, error.c_str(), "error", MB_OK | MB_ICONERROR);
		exit(1);
	}
	if (listen(listening, 5) == SOCKET_ERROR) {
		std::string error = "khong lang nghe duoc socket" + std::to_string(WSAGetLastError());
		MessageBoxA(NULL, error.c_str(), "error", MB_OK | MB_ICONERROR);
		exit(1);
	}

	std::cout << config.getIpServer() << ":" << config.getPortServer() << std::endl;

}
bool Server::listenConnection() {
	std::cout << "cho ket noi...." << std::endl;
	SOCKET newConnect = accept(listening, (SOCKADDR*)&addr, &addrlen);
	if (newConnect == 0) {
		std::cout << "chap nhan nguoi dung that bai" << std::endl;
		return false;
	}
	else
	{
		char data[1024];
		ZeroMemory(data, sizeof(data));
		recv(newConnect, data, sizeof(data), 0);
		if (strcmp(data,"2")==0) {
			ZeroMemory(data, sizeof(data));
			recv(newConnect, data, sizeof(data), 0);

		}
	}
	return true;
}


Server::~Server()
{
}
