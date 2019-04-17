#include "phong.h"
#include<ctime>

phong::phong()
{
}

phong::~phong()
{
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
	config.getdsMod();
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
	timeStr = std::string(buffer);
}
void taophong(std::string data) {
	std::string chuphong = data;
	timeCreate();
	
}


bool phong::checkName(std::string username) {
	for (std::vector<std::string>::iterator i = memberds.begin(); i != memberds.end(); i++) {
		if (username.compare(i->data()) == 0)
			return true;
	}
	return false;
}