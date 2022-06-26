#pragma once

#define PARM_IN L"-in:" // Ключ входного файла
#define PARM_OUT L"-out:" // Ключ выходного файла
#define PARM_LOG L"-log:" // Ключ файла журнала 
#define PARM_DEBAG L"-debag" // Отладочный ключ

#define PARM_MAX_SIZE 300 // Максимальный размер аргумента ключа

#define PARM_OUT_DEF_EXT L".out" // Стандартное расширение выходного файла
#define PARM_LOG_DEF_EXT L".log" // Стандартное расширение файла журнала

// Обработка входный данных
namespace Parm {
	// Входные параметры
	struct parm
	{
		wchar_t in[PARM_MAX_SIZE];
		wchar_t out[PARM_MAX_SIZE];
		wchar_t log[PARM_MAX_SIZE];
	};

	// Формирует parm
	parm getparm(int argc, _TCHAR* argv[]);
}
