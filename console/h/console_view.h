#pragma once

#include <fstream>

#include <bytes/h/bytes.h>

class ConsoleViewer {
public:
	ConsoleViewer(size_t row_size);
	void Run(const std::string& path);

private:
	size_t row_size_;
	Bytes LoadFileToHeap(std::ifstream& file);
};