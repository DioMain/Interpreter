#pragma once

#define IN_MAX_LEN_TEXT 1024*1024		// Максимальный размер исходного кода 1 mb
#define IN_CODE_ENDL '\n'				// Символ конца строки

// Таблица разрешённых, запрещённых, заменяемых и игнорируемых символов
// Таблица Windows-1251
// F - запрещённый, T - разрешённый, I - игнорирование, '{символ}' - замена на {символ}.
#define IN_CODE_TABLE	{\
						in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::T, in::F, in::F, in::I, in::F, in::F,\
						in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F,\
						in::T, in::T, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F,\
						in::T, in::F, in::T, in::F, in::T, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F,\
						in::F, in::F, in::F, in::F, in::T, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::T,\
						in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::I, in::F, in::F, in::F, in::F, in::F, in::F, in::F,\
						in::F, in::T, in::F, in::T, in::F, in::F, in::F, in::F, in::T, in::T, in::F, in::T, in::T, in::T, in::F, in::F,\
						in::F, in::F, in::F, in::F, in::F, in::T, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F,\
																																	   \
						in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F,\
						in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F,\
						in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F,\
						in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F,\
						  '-', in::F, in::F, in::F, in::T, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::T, in::F,\
						in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F,\
						in::T, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::T, in::F, in::T, in::T, in::T, in::F, in::F, in::F,\
						in::F, in::F, in::F, in::T, in::F, in::F, in::F, in::T, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F \
						}

namespace In {
	// Структура хранящая результат трансляции
	struct in
	{
		in() : size_of_code(0), lines_count(1), count_of_ignore(0), source_code(nullptr), code_table(nullptr) { }

		// T - Допустимый символ; F - Недопоустимый символ; I - игнорировать
		enum { T = 1024, F = 2048, I = 4096 };

		int size_of_code;		// Кол-во символов
		int lines_count;		// Кол-во строк
		int count_of_ignore;	// Кол-во проигнорированных символов

		unsigned char* source_code;	//Исходный код

		int* code_table;	// Табилица проверки: T, F, I	новое значение
	};

	// Функция для трансляции 
	in getin(wchar_t* source_file_path);

	// Функция для вывода результата прансляции в файл
	void WriteOut(in inner, wchar_t outpath[]);
}