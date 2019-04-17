#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include "config.h"
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
	void taophong(std::string data);
	void inphong();
	void timeCreate();
private:
	time_t t;
	std::string timeStr;
	std::string timeStr_1;
private:
	
	std::map<std::string, std::string> filterds;
	std::vector<std::string> bands;
	std::vector<std::string> modds;
	std::vector<std::string> memberds;
	std::string chuphong;
	std::string timecre;
	std::string ruler;
};
