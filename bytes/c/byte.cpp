#include <bytes/h/byte.h>

Byte::Byte() : data_(0x0) {}

Byte::Byte(uint8_t data) : data_(data) {}

Byte::operator uint8_t() const {
	return data_;
}

std::ostream& operator<<(std::ostream& os, const Byte& byte)
{
	os << std::hex << static_cast<unsigned>(byte.data_);
	return os;
}