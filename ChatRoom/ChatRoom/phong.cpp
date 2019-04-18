#include "phong.h"
#include<ctime>

phong *phong::_instance = 0;

phong::phong()
{
}

phong::~phong()
{
}

phong* phong::getIntance() {
	if (_instance == NULL) {
		_instance = new phong();
	}
	return _instance;
}


void phong::dsMember() {
	config.taiMember();
	memberds = config.getdsMember();
}

void phong::dsFilter() {
	config.taiFilter();
	filterds = config.getdsFilter();
}

void phong::dsMod() {
	config.taiMod();
	modds = config.getdsMod();
}

void phong::dsBan() {
	config.taiBan();
	bands = config.getdsBan();
}
void phong::timeCreate() {
	t = time(0);
	struct tm* time_info = localtime(&t);
	char buffer[80];
	strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", time_info);
	timecre = std::string(buffer);
}

void phong::taophong(std::string data) {
	chuphong = data;
	timeCreate();

}

std::string phong::getchuphong() {
	std::string res;
	res = "Owner: " + chuphong;
	return res;
}

std::string phong::getthoigian() {
	std::string res;
	res = "Time created: " + timecre;
	return res;
}

std::string phong::getluat() {
	std::string res;
	res = "Rules: " + ruler;
	return res;
}
std::string phong::user(){
	return chuphong;
}

bool phong::checkName(std::string username) {
	for (std::vector<std::string>::iterator i = memberds.begin(); i != memberds.end(); i++) {
		if (username.compare(i->data()) == 0)
			return true;
	}
	return false;
}

std::vector<std::string> phong::getModData() {
	return modds;
}
std::map<std::string, std::string> phong::getFilter() {
	return filterds;
}