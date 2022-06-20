#include "stdafx.h"

using namespace std;

namespace Parm {

	bool CheckEnd(const wchar_t str[], const wchar_t end[]) {
		wstring data;

		int strlen = wcslen(str);
		int endlen = wcslen(end);

		bool dot = false;

		for (int i = 0; i < strlen; i++)
		{
			if (str[i] == L'.') dot = true;

			if (dot) data.push_back(str[i]);
		}

		return (wcscmp(data.c_str(), end) == 0);
	}

	parm getparm(int argc, _TCHAR* argv[])
	{
		parm pr = parm();

		bool In = false, Out = false, Log = false;

		wchar_t prstr[PARM_MAX_SIZE];
		wstring data;

		// Сканирование параментров
		for (int i = 1; i < argc; i++)
		{
			data.clear();

			wcscpy_s(prstr, argv[i]);		

			for (int j = 0; prstr[j] != L':' && prstr[j] != L'\0'; j++)
			{
				data.push_back(prstr[j]);
			}

			data.push_back(L':');

			if (data == PARM_IN) In = true;
			if (data == PARM_OUT) Out = true;
			if (data == PARM_LOG) Log = true;
		}

		if (!In) throw ERROR_THROW(100);

		// Проверка на размер
		for (int i = 1; i < argc; i++)
		{
			if (wcslen(argv[i]) > PARM_MAX_SIZE) throw ERROR_THROW(104);
		}

		data.clear();

		// Заполнение in
		if (In) {
			for (int i = 1; i < argc; i++)
			{
				wcscpy_s(prstr, argv[i]);

				for (int j = 0; prstr[j] != L':' && prstr[j] != L'\0'; j++)
				{
					data.push_back(prstr[j]);
				}

				data.push_back(L':');

				if (data == PARM_IN) {

					data.clear();

					for (int j = 4; prstr[j] != L'\0'; j++)
					{
						data.push_back(prstr[j]);
					}

					break;
				}
			}
		}

		wcscpy_s(pr.in, data.c_str());

		data.clear();

		// Заполнение out
		if (Out) {
			for (int i = 1; i < argc; i++)
			{
				data.clear();

				wcscpy_s(prstr, argv[i]);

				for (int j = 0; prstr[j] != L':' && prstr[j] != L'\0'; j++)
				{
					data.push_back(prstr[j]);
				}

				data.push_back(L':');

				if (data == PARM_OUT) {

					data.clear();

					for (int j = 5; prstr[j] != L'\0'; j++)
					{
						data.push_back(prstr[j]);
					}

					if (!CheckEnd(data.c_str(), PARM_OUT_DEF_EXT)) data.append(PARM_OUT_DEF_EXT);

					break;
				}
			}
		}

		if (!Out || data.size() == 0) { data.append(L"Result"); data.append(PARM_OUT_DEF_EXT); }

		wcscpy_s(pr.out, data.c_str());

		data.clear();

		// Заполнение log
		if (Log) {
			for (int i = 1; i < argc; i++)
			{
				data.clear();

				wcscpy_s(prstr, argv[i]);

				for (int j = 0; prstr[j] != L':' && prstr[j] != L'\0'; j++)
				{
					data.push_back(prstr[j]);
				}

				data.push_back(L':');

				if (data == PARM_LOG) {

					data.clear();

					for (int j = 5; prstr[j] != L'\0'; j++)
					{
						data.push_back(prstr[j]);
					}

					if (!CheckEnd(data.c_str(), PARM_LOG_DEF_EXT)) data.append(PARM_LOG_DEF_EXT);

					break;
				}
			}
		}

		if (!Log || data.size() == 0) { data.append(L"Log"); data.append(PARM_LOG_DEF_EXT); }

		wcscpy_s(pr.log, data.c_str());

		return pr;
	}
}