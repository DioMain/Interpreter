#include "stdafx.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[]) {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Parm::parm prm;
	In::in inner;
	Log::log lg = Log::initlog;

	try
	{
		prm = Parm::getparm(argc, argv);
		inner = In::getin(prm.in);

		In::WriteOut(inner, prm.out);

		lg = Log::getlog(prm.log);

		Log::WriteLine(lg, (wchar_t*)L"Ora", (wchar_t*)L" Ора\n", (wchar_t*)L"");
		Log::WriteLog(lg);
	}
	catch (Error::error err)
	{
		std::system("cls");

		cout << err.message << endl;
		if (err.inext.col != -1 && err.inext.line != -1)
			cout << "Строка: " << err.inext.line << " Позиция: " << err.inext.col << endl;
	}

	Log::Close(lg);
}  