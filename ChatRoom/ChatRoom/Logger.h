#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<string>
#include<fstream>
#include<iostream>
#include<ctime>
#include "Session.h"
class Logger
{
public:
	Logger();
	~Logger();
	void viettinnhan(std::string message, std::string username, std::string time);
private:
	std::fstream f;
};
static Logger logger;