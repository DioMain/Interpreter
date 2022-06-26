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

	// �������� ��� ��������� log [==]
	static bool operator== (log left, log right) {
		return (wcscmp(left.logfile, right.logfile) == 0 && left.log_stream == right.log_stream);
	}
	// �������� ��� ��������� log [!=]
	static bool operator!= (log left, log right) {
		return !(wcscmp(left.logfile, right.logfile) == 0 && left.log_stream == right.log_stream);
	}

	// ��������� ��������� log ���������
	static const log initlog { L"", nullptr };

	// ������ ����� ����� log �� ���������� ����
	log getlog(wchar_t logpath[]);

	// ���������� ������ ����� � log ����, ��������� ������ ������ ���� ������ (char)
	void WriteLine(log lg, char* str ...);
	// ���������� ������ ����� � log ����, ��������� ������ ������ ���� ������ (wchar_t)
	void WriteLine(log lg, wchar_t* str ...);

	// ���������� � log ���� ���������� � ���������
	void WriteLog(log lg);

	// ���������� � log ���� ���������� � ������� ����������
	void WriteParm(log lg, Parm::parm prm);

	// ���������� � log ���� ���������� �� ������� ������
	void WriteIn(log lg, In::in inner);

	// ���������� � log ���� ���������� �� ������
	void WriteError(log lg, Error::error err);

	// ��������� ����� log �����
	void Close(log lg);
}
