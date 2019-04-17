#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib,"ws2_32.lib")
#include<winsock.h>
#include<map>
#include<string>
#include<ctime>
#include<sstream>
#include"Logger.h"
#include"Control.h"
class Session
{
public:
	Session();
	~Session();
	void themketnoi(SOCKET s, std::string username);
	void tinnhanluong(SOCKET s);
	void xoaketnoi(SOCKET s);

	std::string getTimeLog();
	std::string getTimePrint();

private:
	std::map<SOCKET, std::string> connections;
	time_t t;
	std::string timeStr;
	std::string timeStr_1;

private:
	void setTime();
};
static Session sess;