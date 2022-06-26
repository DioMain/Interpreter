#include "stdafx.h"

using namespace std;

namespace Log {
	log getlog(wchar_t logpath[])
	{
		log lg = log();

		ofstream* file = new ofstream(logpath);

		if (!file->is_open()) throw ERROR_THROW(112);

		file->clear();

		wcscpy_s(lg.logfile, logpath);
		lg.log_stream = file;

		return lg;
	}

	void WriteLine(log lg, char* str ...)
	{
		char* nowstr = nullptr;

		int n = 0;
		do
		{
			nowstr = *(&str + n);

			*lg.log_stream << nowstr;

			n++;

		} while (strlen(nowstr) != 0);
	}

	void WriteLine(log lg, wchar_t* str ...)
	{
		char* nowstr = nullptr;

		int n = 0;
		do
		{
			size_t len = wcslen(*(&str + n)) + 1;
			nowstr = new char[len];

			wcstombs_s(0, nowstr, len, *(&str + n), len - 1);	// ��������������� wchar_t � char

			*lg.log_stream << nowstr;

			n++;

		} while (strlen(nowstr) != 0);
	}

	void WriteLog(log lg)
	{
		time_t rltime = time(0);		// ��������� �������� ���� � �������

		tm *fdtm = new tm();			// ��������� ������ ��� ��������������� �����

		localtime_s(fdtm, &rltime);		// �������������� � ��������������� �����

		char* buf = new char[200];		// ������

		strftime(buf, 200, " ���� �������� ���������: %c", fdtm);	// ���������� ������� ������� ��������

		*lg.log_stream << "<------------------ �������� ------------------>" << endl;
		*lg.log_stream << buf << endl;
	}

	void WriteParm(log lg, Parm::parm prm)
	{
		char* nowstr = new char[PARM_MAX_SIZE];

		*lg.log_stream << "<------------- ������� ��������� -------------->" << endl;

		wcstombs_s(0, nowstr, PARM_MAX_SIZE, prm.in, PARM_MAX_SIZE);
		*lg.log_stream << " -in: " << nowstr << endl;

		wcstombs_s(0, nowstr, PARM_MAX_SIZE, prm.out, PARM_MAX_SIZE);
		*lg.log_stream << " -out: " << nowstr << endl;

		wcstombs_s(0, nowstr, PARM_MAX_SIZE, prm.log, PARM_MAX_SIZE);
		*lg.log_stream << " -log: " << nowstr << endl;
	}

	void WriteIn(log lg, In::in inner)
	{
		*lg.log_stream << "<-------------- �������� ������ --------------->" << endl;

		*lg.log_stream << " ���-�� ��������: " << inner.size_of_code << endl;
		*lg.log_stream << " ���������������: " << inner.count_of_ignore << endl;
		*lg.log_stream << " ���-�� �����: " << inner.lines_count << endl;
	}

	void WriteError(log lg, Error::error err)
	{
		*lg.log_stream << endl;

		*lg.log_stream << "������ " << err.id << ": " << err.message << endl;
		if (err.inext.col != -1 && err.inext.line != -1)
			*lg.log_stream << "������: " << err.inext.line << " �������: " << err.inext.col << endl;
	}

	void Close(log lg)
	{
		// ���� ����� ���������� � �� ������, �� ������ ����� ��� ����� �������
		if (lg.log_stream != nullptr && lg.log_stream->is_open()) lg.log_stream->close();
	}
}
