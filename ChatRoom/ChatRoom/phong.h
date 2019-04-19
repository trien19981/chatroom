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

	static phong* getIntance();
	void dsFilter();
	void dsBan();
	void dsMod();
	void dsMember();
	bool checkName(std::string username);

	std::vector<std::string> getModData();
	std::map<std::string, std::string> getFilter();
	void taophong(std::string data);

	std::string getchuphong();
	std::string getthoigian();
	std::string getluat();
	std::string user();
	void themBan(std::string username);
	void themMod(std::string username);
	void xoaBan(std::string username);
	void xoaMod(std::string username);

private:
	time_t t;

	std::string chuphong;
	std::string timecre;
	std::string ruler;

	std::map<std::string, std::string> filterds;
	std::vector<std::string> bands;
	std::vector<std::string> modds;
	std::vector<std::string> memberds;

private:
	void LuuBan();
	void LuuMod();
	void timeCreate();
protected:
	static phong* _instance;
};