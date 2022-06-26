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

	static const log initlog { L"", nullptr};

	log getlog(wchar_t logpath[]);

	// ���������� ������ ����� � log ����, ��������� ������ ������ ���� ������ (char)
	void WriteLine(log lg, char* str ...);
	// ���������� ������ ����� � log ����, ��������� ������ ������ ���� ������ (wchar_t)
	void WriteLine(log lg, wchar_t* str ...);

	void WriteLog(log lg);

	void WriteParm(log lg, Parm::parm prm);

	void WriteIn(log lg, In::in inner);

	void WriteError(log lg, Error::error err);

	void Close(log lg);
}
