#include "Session.h"

Session::Session()
{
}


Session::~Session()
{
}


void Session::themketnoi(SOCKET s, std::string username) {
	connections.insert(std::make_pair(s, username));
}

void Session::tinnhanluong(SOCKET s) {
	char buffer[1024];
	std::string username = connections[s];
	char completeMess[1024];

	while (true) {
		ZeroMemory(buffer, sizeof(buffer));
		ZeroMemory(completeMess, sizeof(completeMess));
		if (recv(s, buffer, sizeof(buffer), 0) > 0) {
			std::cout << getTimePrint() << " " << username << " " << buffer << std::endl;
			logger.viettinnhan(std::string(buffer), username, getTimeLog());
			std::vector<std::string> tach = tachtn(buffer);
			std::vector<std::string>::iterator kt = tach.begin();

			if (strcmp(kt->data(), "/info") == 0) {
				strcpy_s(completeMess, phong::getIntance()->getchuphong().c_str());
				strcat_s(completeMess, "\n");
				strcat_s(completeMess, phong::getIntance()->getthoigian().c_str());
				strcat_s(completeMess, "\n");
				strcat_s(completeMess, phong::getIntance()->getluat().c_str());
				send(s, completeMess, sizeof(completeMess), 0);
				ZeroMemory(completeMess, sizeof(completeMess));
			}
			else if (strcmp(kt->data(), "/mods") == 0) {
				strcat_s(completeMess, phong::getIntance()->getchuphong().c_str());
				strcat_s(completeMess, "\n");
				strcat_s(completeMess, "Mods: ");
				std::vector<std::string> temp = phong::getIntance()->getModData();
				for (std::vector<std::string>::iterator i = temp.begin(); i != temp.end(); i++) {
					strcat_s(completeMess, i->c_str());
					strcat_s(completeMess, ",");
				}
				send(s, completeMess, sizeof(completeMess), 0);
				ZeroMemory(completeMess, sizeof(completeMess));
			}
			else if (strcmp(kt->data(), "/filters") == 0) {
				if (username.compare(phong::getIntance()->user())==0) {
					std::map<std::string, std::string > mtemp = phong::getIntance()->getFilter();
					for (std::map<std::string, std::string>::iterator i = mtemp.begin(); i != mtemp.end(); i++) {
						strcat_s(completeMess, i->first.c_str());
						strcat_s(completeMess, "---");
						strcat_s(completeMess, i->second.c_str());
						strcat_s(completeMess, "\n");
					}
					send(s, completeMess, sizeof(completeMess),0);
				}
				else {
					char Erm[30] = "khong duoc phep";
					send(s, Erm, sizeof(Erm), 0);
				}
			}
			else{
				strcat_s(completeMess, username.c_str());
				strcat_s(completeMess, ": ");
				strcat_s(completeMess, buffer);
				cont.themtinnhan(std::string(completeMess));
				for (std::map<SOCKET, std::string>::iterator i = connections.begin(); i != connections.end(); i++) {
					if (i->first != s) {
						char temp[1024];
						ZeroMemory(temp, sizeof(temp));
						strcpy(temp, cont.intinnhan().c_str());
						send(i->first, temp, sizeof(temp), 0);
					}
				}
			
			}


			
		}
		else {
			std::cout << "nguoi dung ngat ket noi!" << std::endl;
			xoaketnoi(s);
			std::cout << "Size of connections: " << connections.size() << std::endl;
			break;
		}
	}
}

void Session::xoaketnoi(SOCKET s) {
	connections.erase(s);
}

void Session::setTime() {
	t = time(0);
	struct tm* time_info = localtime(&t);
	char buffer[80];
	strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", time_info);
	timeStr = std::string(buffer);
	char buffer_1[80];
	strftime(buffer_1, sizeof(buffer_1), "%H:%M", time_info);
	timeStr_1 = std::string(buffer_1);
}

std::string Session::getTimeLog() {
	setTime();
	return timeStr;
}

std::string Session::getTimePrint() {
	setTime();
	return timeStr_1;
}
std::vector<std::string> Session::tachtn(char message[]) {
	char* p;
	char* next_token = NULL;
	std::vector<std::string> ketqua;

	p = strtok_s(message, "., ", &next_token);
	while (p != NULL) {
		ketqua.push_back(std::string(p));
		p = strtok_s(NULL, "., ", &next_token);
	}
	return ketqua ;
}