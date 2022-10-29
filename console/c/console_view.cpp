#include <console/h/console_view.h>

#include <iomanip>
#include <iterator>

ConsoleViewer::ConsoleViewer(size_t row_size) : row_size_(row_size) {}

void ConsoleViewer::Run(const std::string& path) {
	std::ifstream file(path, std::ios::binary);
	Bytes bytes = LoadFileToHeap(file);
	file.close();

	// init_byte_pos   __ __ __ __ n_bytes   ...TEXT...
	size_t current_pos = 0x0;
	while (current_pos < bytes.Size()) {
		// init_byte_pos
		std::cout << std::setfill('0') << std::setw(7) << std::hex << current_pos;
		std::cout << "   ";
		size_t i;
		size_t printed = 0;

		// __ __ __ __ n_bytes
		for (i = current_pos; i < bytes.Size() && i < current_pos + row_size_; ++i) {
			std::cout << std::setfill('0') << std::setw(2) << bytes[i] << (i != current_pos + row_size_ - 1 ? " " : "");
			printed += 1;
		}

		if (i >= bytes.Size()) {
			size_t to_print = row_size_ - printed;
			for (i = 0; i < to_print; ++i) {
				std::cout << "00" << (i != to_print - 1 ? " " : "");
			}
		}

		// ...TEXT...
		std::cout << "   ";
		for (i = current_pos; i < bytes.Size() && i < current_pos + row_size_; ++i) {
			std::cout << (!isprint((char)bytes[i]) || ispunct((char)bytes[i]) || isblank((char)bytes[i]) ? '.' : (char)bytes[i]);
		}
		std::cout << '\n';
		current_pos += row_size_;
	}
}

Bytes ConsoleViewer::LoadFileToHeap(std::ifstream& file) {

	// get its size:
	std::streampos fileSize;
	file.seekg(0, std::ios::end);
	fileSize = file.tellg();
	file.seekg(0, std::ios::beg);

	// reserve capacity
	Bytes vec;

	// read the data:
	vec.Insert(vec.begin(),
		std::istreambuf_iterator<char>(file),
		std::istreambuf_iterator<char>());

	return vec;
}