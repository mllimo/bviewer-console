#pragma once

#include <bytes/h/byte.h>
#include <vector>

class Bytes {
public:
	using iterator = std::vector<Byte>::iterator;
	using const_iterator = std::vector<Byte>::const_iterator;

	Bytes() = default;
	Bytes(const std::initializer_list<int>& list);
	Bytes(const Bytes&) = default;
	Bytes(Bytes&&) = default;

	size_t Size() const;

	void PushBack(const Byte& byte);
	void PushBack(Byte&& byte);

	const Byte& operator[](size_t index) const;
	Byte& operator[](size_t index);

	iterator begin();
	iterator end();
	const_iterator cbegin();
	const_iterator cend();

	friend std::ostream& operator<<(std::ostream& os, const Bytes& bytes);

	template <class InputIt>
	void Insert(iterator pos, InputIt first, InputIt last) {
		data_.insert(pos, first, last);
	}

private:
	std::vector<Byte> data_;
};