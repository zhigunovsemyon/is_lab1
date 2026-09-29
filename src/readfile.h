#pragma once

#include <expected>
#include <string>
#include <string_view>

enum class FileError {
	READ_FAIL,
	OPEN_FAIL,
	EMPTY_FAIL
};

std::expected<std::string, FileError> read_file(std::string_view filename);
