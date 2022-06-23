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

		size_t nul = 0;

		int n = 0;

		do
		{
			size_t len = wcslen(*(&str + n)) + 1;
			nowstr = new char[len];

			wcstombs_s(&nul, nowstr, len, *(&str + n), len - 1);

			*lg.log_stream << nowstr;

			n++;

		} while (strlen(nowstr) != 0);
	}

	void WriteLog(log lg)
	{
		time_t* tim = new time_t();

		*tim = time(0);

		tm *realtime = new tm(); 

		localtime_s(realtime, tim);

		char* buf = new char[200];

		strftime(buf, 200, "Дата создания протокола: %c", realtime);

		*lg.log_stream << "<------------------ Протокол ------------------>" << endl;
		*lg.log_stream << buf << endl;
	}

	void WriteParm(log lg, Parm::parm prm)
	{
	}

	void WriteIn(log lg, In::in inner)
	{
	}

	void WriteError(log lg, Error::error err)
	{
	}

	void Close(log lg)
	{
		if (lg.log_stream->is_open()) lg.log_stream->close();
	}
}
