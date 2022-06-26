#include "stdafx.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[]) {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Parm::parm prm;					// ������� ���������
	In::in inner;					// ��������� �������
	Log::log lg = Log::initlog;		// ��������

	try
	{
		prm = Parm::getparm(argc, argv);
		lg = Log::getlog(prm.log);

		Log::WriteLine(lg, (char*)"����: ", (char*)"��� ������ (char)\n", (char*)"");
		Log::WriteLine(lg, (wchar_t*)L"����: ", (wchar_t*)L"��� ������ (wchar_t)\n\n", (wchar_t*)L"");

		Log::WriteLog(lg);

		Log::WriteParm(lg, prm);

		inner = In::getin(prm.in);
		Log::WriteIn(lg, inner);

		In::WriteOut(inner, prm.out); // ���������� ����� ����� �������

		Log::WriteLine(lg, (char*)"\n���������� ��� ������!\n", (char*)"");

		cout << "���������� ��� ������!" << endl;
	}
	catch (Error::error err)
	{
		std::system("cls");

		cout << err.message << endl;
		if (err.inext.col != -1 && err.inext.line != -1)
			cout << "������: " << err.inext.line << " �������: " << err.inext.col << endl;

		cout << endl << "���������� � ��������!" << endl;

		if (lg != Log::initlog) {
			Log::WriteError(lg, err); 
			Log::WriteLine(lg, (char*)"\n���������� � ��������!\n", (char*)"");
		}
	}

	Log::Close(lg);
}  