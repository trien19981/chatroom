#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include "Config.h"
class phong
{
public:
	phong();
	~phong();

	void getFilterList();
	void getBanList();
	void getModList();
	void getMemberList();

	bool checkUsername(std::string username);

private:

	std::map<std::string, std::string> filterData;
	std::vector<std::string> banData;
	std::vector<std::string> modData;
	std::vector<std::string> memberData;

};
