
#pragma comment(lib,"ws2_32.lib")
#define _CRT_SECURE_NO_WARNINGS
#include<cstdlib>
#include<WinSock2.h>
#include<WS2tcpip.h>
#include<iostream>
#include<string>

SOCKET connection;
using namespace std;
	

	void initSocket(std::string ip,int port ) {
		WSADATA wsadata;
		WORD DllVersion = MAKEWORD(2, 1);
		if (WSAStartup(DllVersion, &wsadata) != 0) {
			MessageBoxA(NULL, "khoi tao loi", "loi", MB_OK | MB_ICONERROR);
			return;
		}
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
	}
	void taoluong() {
		char buffer[1024];
		ZeroMemory(buffer, sizeof(buffer));
		while (true)
		{
			recv(connection, buffer, sizeof(buffer), 0);
			std::cout << buffer << std::endl;
		}
		ExitThread(0);
	}
	int main() {

		std::cout << "1: tao phong" << std::endl;
		std::cout << "2: vao phong" << std::endl;
		std::cout << "3: thoat phong" << std::endl;
		std::cout << "nhap lua chon:";

		int choice;
		std::cin >> choice;
		while (choice < 0 || choice>3) {
			std:: cerr << "loi moi chon lai" << std::endl;
			std::cin >> choice;
		}
		if (choice == 1) {
			char data[50];
			ZeroMemory(data, sizeof(data));
			std::cout << "Nhap ten:";
			std::cin.ignore();
			std::cin.get(data, 50);
			initSocket("127.0.0.1", 1080);

			system("cls");

			send(connection, data, sizeof(data),0);
			ZeroMemory(data, sizeof(data), 0);
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
		if (choice == 2) {
			std::string ip;
			int cong;
			std::cin.ignore();
			std::cout << "nhap ip" << std::endl;
			getline(std::cin, ip);
			std::cout << "nhap cong" << std::endl;
			std::cin >> cong;
			system("cls");
			initSocket(ip, cong);
			char data[1024];

			ZeroMemory(data, sizeof(data));
			std::cin.ignore();
			std::cout << "nhap ten ban:";
			std::cin.get(data, 1024);
			
			send(connection, data, sizeof(data), 0);
			ZeroMemory(data, sizeof(data));
			recv(connection, data, sizeof(data), 0);

			if (strcmp(data, "ket noi thanh cong") == 0) {
				CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)taoluong, NULL, NULL, NULL);
				while (true) {
					char buffer[1024];

					ZeroMemory(buffer, sizeof(buffer));
					std::cin.getline(buffer, sizeof(buffer));
					if (strcmp(buffer, "") != 0) {
						send(connection, buffer, sizeof(buffer),0);
					}
					else continue;
				}
			}
			else {
				std::cout << data << std::endl;
			}	
		}if (choice == 3) {
			exit(0);
		}
		system("pause");
		return 0;
	}
	
	