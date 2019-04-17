#pragma comment(lib,"ws2_32.lib")
#define _CRT_SECURE_NO_WARNINGS
#include <WinSock2.h> 
#include <string> 
#include <iostream> 
#include <WS2tcpip.h>
#include <string>
#include <vector>

SOCKET connection;


void initSocket(std::string ip, int port) {
	WSAData wsaData;
	WORD DllVersion = MAKEWORD(2, 1);
	if (WSAStartup(DllVersion, &wsaData) != 0) {
		MessageBoxA(NULL, "Loi tao winshock", "Error", MB_OK | MB_ICONERROR);
		return;
	}

	sockaddr_in addr; //Address to be binded to our Connection socket
	int sizeofaddr = sizeof(addr); //Need sizeofaddr for the connect function
	inet_pton(AF_INET, ip.c_str(), &addr.sin_addr); //Address = localhost (this pc)
	addr.sin_port = htons(port); //Port = 1111
	addr.sin_family = AF_INET; //IPv4 Socket

	connection = socket(AF_INET, SOCK_STREAM, 0); //Set Connection socket
	if (connect(connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) //If we are unable to connect...
	{
		MessageBoxA(NULL, "Loi ket noi", "Error", MB_OK | MB_ICONERROR);
		return; //Failed to Connect
	}
}

void taoluong() {
	char buffer[1024];
	ZeroMemory(buffer, sizeof(buffer));
	while (true) {
		recv(connection, buffer, sizeof(buffer), 0);
		std::cout << buffer << std::endl;
	}
	ExitThread(0);
}

void sendUserChoise(int choise) {
	char* userChoiseTemp = new char[2];
	_itoa(choise, userChoiseTemp, 10);
	send(connection, userChoiseTemp, sizeof(userChoiseTemp), 0);
	delete userChoiseTemp;
}
int main() {

	std::cout << "1. Create room" << std::endl;
	std::cout << "2. Join room" << std::endl;
	std::cout << "3. Exit" << std::endl;
	std::cout << "Enter your choise: ";

	int userChoise;
	std::cin >> userChoise;
	while (userChoise < 0 || userChoise > 3) {
		std::cerr << "Lua chon khong hop le. nhap lai: " << std::endl;
		std::cin >> userChoise;
	}
	if (userChoise == 1) {
		char data[100];
		ZeroMemory(data, sizeof(data));

		std::cout << "Nhap ten ban: ";
		std::cin.ignore();
		std::cin.get(data, 100);

		initSocket("127.0.0.1", 1080);
		sendUserChoise(userChoise);

		system("cls");

		send(connection, data, sizeof(data), 0);
		ZeroMemory(data, sizeof(data));
		recv(connection, data, sizeof(data), 0);

		if (strcmp(data, "sucessfully") == 0) {
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)taoluong, NULL, NULL, NULL);
			while (true) {
				char buffer[1024];
				ZeroMemory(buffer, sizeof(buffer));
				std::cin.getline(buffer, sizeof(buffer));
				if (strcmp(buffer, "") != 0)
					send(connection, buffer, sizeof(buffer), 0);
				else continue;
			}
		}
		else {
			std::cout << data << std::endl;
		}
	}
	if (userChoise == 2) {
		std::string ip;
		int port;

		std::cin.ignore();
		std::cout << "Nhap IP: ";
		getline(std::cin, ip);
		std::cout << "Nhap Cong: ";
		std::cin >> port;

		initSocket(ip, port);
		sendUserChoise(userChoise);

		char data[1024];
		ZeroMemory(data, sizeof(data));

		std::cin.ignore();
		std::cout << "Nhap Ten: ";
		std::cin.get(data, 1024);
		system("cls");

		send(connection, data, sizeof(data), 0);
		ZeroMemory(data, sizeof(data));
		recv(connection, data, sizeof(data), 0);
		if (strcmp(data, "sucessfully") == 0) {
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)taoluong, NULL, NULL, NULL);
			while (true) {
				char buffer[1024];
				ZeroMemory(buffer, sizeof(buffer));
				std::cin.getline(buffer, sizeof(buffer));
				if (strcmp(buffer, "") != 0)
					send(connection, buffer, sizeof(buffer), 0);
				else continue;
			}
		}
		else {
			std::cout << data << std::endl;
		}

	} if (userChoise == 3) {
		exit(0);
	}
	system("pause");
	return 0;
}