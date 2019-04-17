#include "phong.h"

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
bool phong::checkName(std::string username) {
	for (std::vector<std::string>::iterator i = memberds.begin(); i != memberds.end(); i++) {
		if (username.compare(i->data()) == 0)
			return true;
	}
	return false;
}