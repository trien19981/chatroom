
#include "Control.h"


Control::Control()
{
}


Control::~Control()
{
}

void Control::themtinnhan(std::string mess) {
	message.push(mess);
}

std::string Control::intinnhan() {
	std::string mess;
	mess = message.front();
	message.pop();
	return mess;
}