#include "Server.h"

int main() {
	Server test(1088);
	while (true) {
		test.listenConnection();
	}

}