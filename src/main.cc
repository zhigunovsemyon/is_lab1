#include <cstdlib>
#include <print>

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

static void usage(char const * execname);

int main(int argc, char const * argv[])
{
	if (argc != 5) {
		usage(argv[0]);
		return EXIT_FAILURE;
	}
	std::print("Hello World!\n");
	return EXIT_SUCCESS;
}

void usage(char const * execname)
{
	std::printf("Usage: %s (d|e) input_file key_file output_file\n", execname);
}
