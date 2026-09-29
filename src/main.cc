#include "readfile.h"

#include <cstdlib>
#include <print>
#include <string_view>

/*
 * Задание:
 * Во всех вариантах необходимо разработать программы для шифрования и
 * расшифрования сообщений двумя указанными методами. Обрабатываемые сообщения,
 * результаты шифрования и ключи должны храниться в текстовых файлах. Числовые
 * ключи могут вводиться с клавиатуры.
 *
 * 1-я ступень: система шифрования Цезаря
 * 2-я ступень: шифрующие таблицы с двойной перестановкой по ключу
 * Алфавит: 35 символов (А…Я, пробел, «.» )
 */

using std::println;
using std::string_view;

enum class Mode {
	DECRYPT_MODE = 0,
	ENCRYPT_MODE = 1,
	INVALID_MODE = -1
};

static void usage(string_view execname);
static void display_file_error(string_view filename, FileError err);
static Mode get_mode(string_view modename);

int main(int argc, char const * argv[])
{
	auto execname = argv[0];
	if (argc != 5) {
		usage(execname);
		return EXIT_FAILURE;
	}

	auto modename = argv[1];
	auto input_file = argv[2];
	[[maybe_unused]] auto key_file = argv[3];
	[[maybe_unused]] auto output_file = argv[4];

	auto mode = get_mode(modename);
	if (mode == Mode::INVALID_MODE) {
		println(stderr, "{} не является действующим режимом", modename);
		usage(execname);
		return EXIT_FAILURE;
	}

	auto read_file_return = read_file(input_file);
	if (!read_file_return) {
		display_file_error(input_file, read_file_return.error());
		return EXIT_FAILURE;
	}
	auto input_file_content = *read_file_return;

	read_file_return = read_file(key_file);
	if (!read_file_return) {
		display_file_error(key_file, read_file_return.error());
		return EXIT_FAILURE;
	}

	auto key_file_content = *read_file_return;

	println("Входной файл:\n{}", input_file_content);
	println("Ключ:\n{}", key_file_content);

	println("Hello World!");
	return EXIT_SUCCESS;
}

static void usage(string_view execname)
{
	println(stderr, "{} (d|e) input_file key_file output_file", execname);
}

static Mode get_mode(string_view modename)
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

static void display_file_error(string_view filename, FileError err)
{
	switch (err) {
	case FileError::EMPTY_FAIL:
		println(stderr, "Файл {} пустой!", filename);
		break;
	case FileError::READ_FAIL:
		println(stderr, "Не удалось прочитать файл {}", filename);
		break;
	case FileError::OPEN_FAIL:
		println(stderr, "Не удалось открыть файл {}", filename);
		break;
	}
}
