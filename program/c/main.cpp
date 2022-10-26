#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <iomanip>

#include <bytes/h/bytes.h>
#include <program/h/console_view.h>

int main(int argc, const char* argv[]) {
	ConsoleViewer program(16);
	program.Run(argv[1]);
	return 0;
}
