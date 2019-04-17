#pragma once
#include<queue>
class Control
{
public:
	Control();
	~Control();

	void themtinnhan(std::string message);
	std::string intinnhan();

private:
	std::queue<std::string> message;
};

static Control cont;
