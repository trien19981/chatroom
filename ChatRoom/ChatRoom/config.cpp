#include "Config.h"

config::config()
{
}


config::~config()
{
}

void config::taiConfigServer() {
	std::string data;
	f.open("configServer.txt", std::ios::in);

	if (f.fail())
		std::cerr << "Mo file loi roi" << std::endl;
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

void config::taiFilter() {
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
void config::taiMember() {
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

void config::taiBan() {
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

void config::taiMod() {
	f.open("modData.txt", std::ios::in);

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

std::map<std::string, std::string> config::getdsFilter() {
	return filterds;
}
std::vector<std::string> config::getdsMember() {
	return memberds;
}

std::vector<std::string> config::getdsMod() {
	return modds;
}
std::vector<std::string> config::getdsBan() {
	return bands;
}
std::string config::getIpServer() {
	return ipServer;
}

int config::getPortServer() {
	return portServer;
}