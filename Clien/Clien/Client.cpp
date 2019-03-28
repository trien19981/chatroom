
#pragma comment(lib,"ws2_32.lib")
#include<cstdlib>
#include<WinSock2.h>
#include<WS2tcpip.h>
#include<iostream>
#include<string>
using namespace std;
	SOCKET connection;
	void main() {
		WSADATA wsadata;
		WORD DllVersion = MAKEWORD(2, 1);
		if (WSAStartup(DllVersion, &wsadata) != 0) {
			MessageBoxA(NULL, "khoi tao loi", "loi", MB_OK | MB_ICONERROR);
			return;
		}
		string ip = "127.0.0.1";
		sockaddr_in addr;
		int addrlen = sizeof(addr);
		inet_pton(AF_INET, ip.c_str(), &addr.sin_addr);
		addr.sin_port = htons(1088);
		addr.sin_family = AF_INET;

		connection = socket(AF_INET, SOCK_STREAM, 0);
		if (connect(connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
			MessageBoxA(NULL, "ket noi loi", "loi", MB_OK | MB_ICONERROR);
			return;
		}
		char data[1024];
		ZeroMemory(data, sizeof(data));
		strcpy_s(data, "Chao");
		send(connection, data, sizeof(data), 0);
		ZeroMemory(data, sizeof(data));
		recv(connection, data, sizeof(data), 0);
	}
	
