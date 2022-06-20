#include "stdafx.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[]) {
	setlocale(LC_ALL, "RU");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Parm::parm prm;

	try
	{
		prm = Parm::getparm(argc, argv);

		wcout << prm.in << endl;
		wcout << prm.out << endl;
		wcout << prm.log << endl;
	}
	catch (Error::error err)
	{
		cout << err.message << endl;
	}
}  