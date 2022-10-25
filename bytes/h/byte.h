#pragma once

#include <iostream>

class Byte {
public:
	Byte();
	Byte(uint8_t data);
	Byte(const Byte& other) = default;
	Byte(Byte&& other) = default;

	operator uint8_t() const;
	Byte& operator=(const Byte& other) = default;
	Byte& operator=(Byte&& other) = default;

	friend std::ostream& operator<<(std::ostream& os, const Byte& byte);
private:
	uint8_t data_;
};