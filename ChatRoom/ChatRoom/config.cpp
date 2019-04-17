#include "Config.h"

Config::Config()
{
}


Config::~Config()
{
}

void Config::taiConfigServer() {
	std::string data;
	f.open("configServer.txt", std::ios::in);

	if (f.fail())
		std::cerr << "Mo file loi" << std::endl;
	else {
		int index = 1;
		while (!f.eof()) {
			std::getline(f, data);
			if (index == 1) {
				ipServer = data;
				index++;
				continue;
			}
			if (index == 2) {
				std::stringstream ss(data);
				ss >> portServer;
				index = 1;
			}
		}
		f.close();
	}
}

void Config::taiFilter() {
	std::string data;
	f.open("filterData.txt", std::ios::in);

	if (f.fail())
		std::cout << "Mo file " << std::endl;
	else {
		int index = 1;
		std::string key, value;
		while (!f.eof()) {
			std::getline(f, data);
			if (index == 1) {
				key = data;
				index++;
				continue;
			}
			if (index == 2) {
				value = data;
				index = 1;
				continue;
			}
		}
		f.close();
	}
}
void Config::taiMember() {
	f.open("userData.txt", std::ios::in);

	if (f.fail())
		std::cout << "Opening file fail" << std::endl;
	else {
		std::string line;
		while (!f.eof()) {
			std::getline(f, line);
			memberds.push_back(line);
		}
	}
	f.close();
}

void Config::taiBan() {
	f.open("banData.txt", std::ios::in);

	if (f.fail())
		std::cout << "Opening file fail" << std::endl;
	else {
		std::string line;
		while (!f.eof()) {
			std::getline(f, line);
			bands.push_back(line);
		}
	}
	f.close();
}

void Config::taiMod() {
	f.open("banData.txt", std::ios::in);

	if (f.fail())
		std::cout << "Opening file fail" << std::endl;
	else {
		std::string line;
		while (!f.eof()) {
			std::getline(f, line);
			modds.push_back(line);
		}
	}
	f.close();
}

std::map<std::string, std::string> Config::getdsFilter() {
	return filterds;
}
std::vector<std::string> Config::getdsMember() {
	return memberds;
}

std::vector<std::string> Config::getdsMod() {
	return modds;
}
std::vector<std::string> Config::getdsBan() {
	return bands;
}

std::string Config::getIpServer() {
	return ipServer;
}

int Config::getPortServer() {
	return portServer;
}