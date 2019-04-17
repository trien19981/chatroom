#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
#include<map>
#include "User.h"


class config
{
public:
	config();
	~config();

	void taiConfigServer();
	void taiFilter();
	void taiBan();
	void taiMod();
	void taiMember();

	std::vector<std::string> getdsMember();
	std::map<std::string, std::string> getdsFilter();
	std::vector<std::string> getdsMod();
	std::vector<std::string> getdsBan();
	std::string getIpServer();
	int getPortServer();

private:
	std::fstream f;

	std::map<std::string, std::string> filterds;
	std::vector<std::string >bands;
	std::vector<std::string> modds;
	std::vector<std::string> memberds;

	std::string ipServer;
	int portServer = 0;
};
static config conf;