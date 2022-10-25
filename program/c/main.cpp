#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <iomanip>

#include <bytes/h/bytes.h>

/*
typedef uint8_t Byte;

std::vector<Byte> LoadFileToHeap(std::ifstream& file);
void PrintBytes(const std::vector<Byte>& bytes);
*/
int main(int argc, const char* argv[]) {
	//std::ifstream file(argv[1], std::ios::binary);
	//std::vector<Byte> bytes = LoadFileToHeap(file);
	//file.close();
	//PrintBytes(bytes);
	
	Bytes bytes = {0xa, 0xb, 0xff};
	std::cout << bytes << std::endl;

	return 0;
}

/*
void PrintBytes(const std::vector<Byte>& bytes)
{
	std::vector<uint8_t>::const_iterator it;

	for (it = bytes.begin(); it != bytes.end(); it++) {
		std::cout << std::hex << static_cast<unsigned>(*it) << ' ';
	}
}


std::vector<Byte> LoadFileToHeap(std::ifstream& file) {
	// Stop eating new lines in binary mode!!!
	file.unsetf(std::ios::skipws);

	// get its size:
	std::streampos fileSize;
	file.seekg(0, std::ios::end);
	fileSize = file.tellg();
	file.seekg(0, std::ios::beg);

	// reserve capacity
	std::vector<Byte> vec;
	vec.reserve(fileSize);

	// read the data:
	vec.insert(vec.begin(),
		std::istream_iterator<Byte>(file),
		std::istream_iterator<Byte>());

	return vec;
}
*/