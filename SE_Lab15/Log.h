#pragma once

#include "Error.h"
#include "In.h"
#include "Parm.h"

namespace Log {
	struct log
	{
		wchar_t logfile[PARM_MAX_SIZE];

		std::ofstream* log_stream;
	};

	// Оператор для сравнения log [==]
	static bool operator== (log left, log right) {
		return (wcscmp(left.logfile, right.logfile) == 0 && left.log_stream == right.log_stream);
	}
	// Оператор для сравнения log [!=]
	static bool operator!= (log left, log right) {
		return !(wcscmp(left.logfile, right.logfile) == 0 && left.log_stream == right.log_stream);
	}

	// Начальное состояние log структуры
	static const log initlog { L"", nullptr };

	// Создаёт поток файла log по указаннаму пути
	log getlog(wchar_t logpath[]);

	// Записывает массив строк в log фаил, последняя строка должна быть пустой (char)
	void WriteLine(log lg, char* str ...);
	// Записывает массив строк в log фаил, последняя строка должна быть пустой (wchar_t)
	void WriteLine(log lg, wchar_t* str ...);

	// Записывает в log фаил инфармацию о протоколе
	void WriteLog(log lg);

	// Записывает в log фаил инфармацию о входных параметрах
	void WriteParm(log lg, Parm::parm prm);

	// Записывает в log фаил инфармацию об входных данных
	void WriteIn(log lg, In::in inner);

	// Записывает в log фаил инфармацию об ошибке
	void WriteError(log lg, Error::error err);

	// Закрывает поток log файла
	void Close(log lg);
}
