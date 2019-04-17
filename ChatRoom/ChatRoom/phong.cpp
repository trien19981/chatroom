#include "phong.h"

phong::phong()
{
}

phong::~phong()
{
}
void phong::dsMember() {
	conf.taiMember();
	memberds = conf.getdsMember();
}

void phong::dsFilter() {
	conf.taiFilter();
	filterds = conf.getdsFilter();
}

void phong::dsMod() {
	conf.getdsMod();
	modds = conf.getdsMod();
}

void phong::dsBan() {
	conf.taiBan();
	bands = conf.getdsBan();
}
bool phong::checkName(std::string username) {
	for (std::vector<std::string>::iterator i = memberds.begin(); i != memberds.end(); i++) {
		if (username.compare(i->data()) == 0)
			return true;
	}
	return false;
}