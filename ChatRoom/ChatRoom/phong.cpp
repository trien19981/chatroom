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
void phong::themBan(std::string username) {
	bands.push_back(username);
	LuuBan();
}
void phong::LuuBan() {
	std::fstream f;
	f.open("banData.txt", std::ios::out);

	if (f.fail())
		std::cerr << "K mo dk file" << std::endl;
	else {
		for (std::vector<std::string>::iterator i = bands.begin(); i != bands.end(); i++) {
			f << i->data() << std::endl;
		}
	}
	f.close();
}

void phong::themMod(std::string username) {
	modds.push_back(username);
	LuuMod();
}
void phong::LuuMod() {
	std::fstream f;
	f.open("modData.txt", std::ios::out);

	if (f.fail())
		std::cerr << "K mo dk file" << std::endl;
	else {
		for (std::vector<std::string>::iterator i = modds.begin(); i != modds.end(); i++) {
			f << i->data() << std::endl;
		}
	}
	f.close();
}
void phong::xoaBan(std::string username) {
	if (bands.size() == 1) {
		bands.erase(bands.begin());
	}
	else {
		for (std::vector<std::string>::iterator i = bands.begin(); i != bands.end(); i++) {
			if (i->compare(username) == 0)
				bands.erase(i);
		}
	}
	LuuBan();
}
void phong::xoaMod(std::string username) {
	if (modds.size() == 1) {
		modds.erase(modds.begin());
	}
	else {
		for (std::vector<std::string>::iterator i = modds.begin(); i != modds.end(); i++) {
			if (i->compare(username) == 0)
				modds.erase(i);
		}
	}
	LuuMod();
}



