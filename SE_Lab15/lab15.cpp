#include "stdafx.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[]) {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Parm::parm prm;
	In::in inner;

	try
	{
		prm = Parm::getparm(argc, argv);

		wcout << prm.in << endl;
		wcout << prm.out << endl;
		wcout << prm.log << endl << endl;

		inner = In::getin(prm.in);

		cout << inner.source_code << endl << endl;

		cout << "Кол-во символов: " << inner.size_of_code << endl;
		cout << "Кол-во строк: " << inner.lines_count << endl;
		cout << "Кол-во пропущенных: " << inner.count_of_ignore << endl;
	}
	catch (Error::error err)
	{
		std::system("cls");

		cout << err.message << endl;
		if (err.inext.col != -1 && err.inext.line != -1)
			cout << "Строка: " << err.inext.line << " Позиция: " << err.inext.col << endl;
	}
}  