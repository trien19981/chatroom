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

	void dsFilter();
	void dsBan();
	void dsMod();
	void dsMember();
	bool checkName(std::string username);

private:

	std::map<std::string, std::string> filterds;
	std::vector<std::string> bands;
	std::vector<std::string> modds;
	std::vector<std::string> memberds;

};
