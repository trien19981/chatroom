#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include "User.h"
class Database
{
public:
	void loadData();
	void saveData();
	bool checkUsername(std::string username);
	char* getUserInfor(std::string username);
	std::fstream f;
	std::vector<User> usersData;
};
#pragma once
