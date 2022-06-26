#include "stdafx.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[]) {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Parm::parm prm;					// Входные параметры
	In::in inner;					// Результат анализа
	Log::log lg = Log::initlog;		// Протокол

	try
	{
		prm = Parm::getparm(argc, argv);
		lg = Log::getlog(prm.log);

		Log::WriteLine(lg, (char*)"Тест: ", (char*)"без ошибок (char)\n", (char*)"");
		Log::WriteLine(lg, (wchar_t*)L"Тест: ", (wchar_t*)L"без ошибок (wchar_t)\n\n", (wchar_t*)L"");

		Log::WriteLog(lg);

		Log::WriteParm(lg, prm);

		inner = In::getin(prm.in);
		Log::WriteIn(lg, inner);

		In::WriteOut(inner, prm.out); // Отладочный вывод файла анализа

		Log::WriteLine(lg, (char*)"\nЗаверешено без ошибок!\n", (char*)"");

		cout << "Заверешено без ошибок!" << endl;
	}
	catch (Error::error err)
	{
		std::system("cls");

		cout << err.message << endl;
		if (err.inext.col != -1 && err.inext.line != -1)
			cout << "Строка: " << err.inext.line << " Позиция: " << err.inext.col << endl;

		cout << endl << "Заверешено с ошибками!" << endl;

		if (lg != Log::initlog) {
			Log::WriteError(lg, err); 
			Log::WriteLine(lg, (char*)"\nЗаверешено с ошибками!\n", (char*)"");
		}
	}

	Log::Close(lg);
}  