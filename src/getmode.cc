#include "getmode.h"

using std::string_view;

Mode get_mode(string_view modename)
{
	if (modename.length() != 1) {
		return Mode::INVALID_MODE;
	}

	char modechar = modename[0];
	switch (modechar) {
	case 'd':
	case 'D':
		return Mode::DECRYPT_MODE;
	case 'e':
	case 'E':
		return Mode::ENCRYPT_MODE;
	default:
		return Mode::INVALID_MODE;
	}
}
