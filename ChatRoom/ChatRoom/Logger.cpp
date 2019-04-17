
#include "Logger.h"



Logger::Logger()
{
}


Logger::~Logger()
{
}

void Logger::viettinnhan(std::string message, std::string username, std::string time) {
	f.open("chat.log", std::ios::app);
	if (f.fail())
		std::cerr << "Loi mo file!" << std::endl;
	else
		f << time << " " << username << " " << message << std::endl;
	f.close();
}