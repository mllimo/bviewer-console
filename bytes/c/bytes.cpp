#include <bytes/h/bytes.h>

Bytes::Bytes(const std::initializer_list<int>& list) : data_(list.begin(), list.end()) {}

size_t Bytes::Size() const {
	return data_.size();
}

void Bytes::PushBack(const Byte& byte) {
	data_.push_back(byte);
}

void Bytes::PushBack(Byte&& byte) {
	data_.push_back(std::move(byte));
}

const Byte& Bytes::operator[](size_t index) const {
	return data_.at(index);
}

Byte& Bytes::operator[](size_t index) {
	return data_.at(index);
}

Bytes::iterator Bytes::begin() {
	return data_.begin();
}

Bytes::iterator Bytes::end() {
	return data_.end();
}

Bytes::const_iterator Bytes::cbegin() {
	return data_.cbegin();
}

Bytes::const_iterator Bytes::cend() {
	return data_.cend();
}

std::ostream& operator<<(std::ostream& os, const Bytes& bytes) {
	for (const auto& byte : bytes.data_) {
		os << byte << ' ';
	}
	return os;
}
