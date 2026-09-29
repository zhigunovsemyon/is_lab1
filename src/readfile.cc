#include "readfile.h"
#include <filesystem>
#include <fstream>

using std::expected;
using std::unexpected;
using std::string;
using std::string_view;
using std::ifstream;
using std::filesystem::path;

expected<string, FileError> read_file(string_view filename)
{
	ifstream file_to_read {path{filename}, std::ios::in | std::ios::ate};
	if (!file_to_read) {
		return unexpected{FileError::OPEN_FAIL};
	}

	auto size = file_to_read.tellg();
	if (size < 0) {
		return unexpected{FileError::OPEN_FAIL};
	}
	if (size == 0) {
		return unexpected{FileError::EMPTY_FAIL};
	}

	string buf ((size_t)size, '\0');
	file_to_read.seekg(0);

	bool read_ok = file_to_read.read(&buf[0], size).good();
	if (read_ok) {
		return buf;
	}
	return unexpected{FileError::READ_FAIL};
}
