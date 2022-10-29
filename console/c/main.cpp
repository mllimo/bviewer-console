#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <iomanip>

#include <bytes/h/bytes.h>
#include <console/h/console_view.h>
#include <string>

int main(int argc, const char* argv[]) {
	size_t size = 16;
	
	if (argc == 3) {
		size = stoi(std::string(argv[2]));
	} 

	ConsoleViewer program(size);
	program.Run(argv[1]);
	return 0;
}
