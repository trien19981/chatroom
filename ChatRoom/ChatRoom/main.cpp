#include "Server.h"

int main() {
	Server server;
	for (int i = 0; i < 100; i++) {
		server.listenConnection();
	}
	system("pause");
	return 0;

}