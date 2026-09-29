#pragma once
#include <string_view>

enum class Mode {
	DECRYPT_MODE = 0,
	ENCRYPT_MODE = 1,
	INVALID_MODE = -1
};

Mode get_mode(std::string_view modename);
