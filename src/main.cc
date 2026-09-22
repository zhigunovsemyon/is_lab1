#include <cstdio>
#include <cstdlib>

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

enum class Mode {
	DECRYPT_MODE = 0,
	ENCRYPT_MODE = 1,
	INVALID_MODE = -1
};

static void usage(char const * execname);
static Mode get_mode(char const * modename);

int main(int argc, char const * argv[])
{
	auto execname = argv[0];
	if (argc != 5) {
		usage(execname);
		return EXIT_FAILURE;
	}

	auto modename = argv[1];
	auto mode = get_mode(modename);
	if (mode == Mode::INVALID_MODE) {
		std::fprintf(stderr, "Неверно указан режим работы: %s\n", modename);
		return EXIT_FAILURE;
	}

	[[maybe_unused]] auto input_file = argv[2];
	[[maybe_unused]] auto key_file = argv[3];
	[[maybe_unused]] auto output_file = argv[4];

	std::printf("Hello World!\n");
	return EXIT_SUCCESS;
}

static void usage(char const * execname)
{
	std::fprintf(stderr, "Usage: %s (d|e) input_file key_file output_file\n", execname);
}

static Mode get_mode(char const * modename)
{
	if (nullptr == modename) {
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
