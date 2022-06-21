#pragma once

#define IN_MAX_LEN_TEXT 1024*1024		// Максимальный размер исходного кода 1 mb
#define IN_CODE_ENDL '\n'				// Символ конца строки

// Fisting is 300 backs
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

	in getin(wchar_t* source_file_path);
}