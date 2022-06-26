#include "stdafx.h"

using namespace std;

namespace Parm {		
	parm getparm(int argc, _TCHAR* argv[])
	{
		parm result;

		bool parm_1 = false;
		bool parm_2 = false;
		bool parm_3 = false;

		// ���������� ���������
		for (int i = 0; i < argc; i++) {
			// ��� In
			if (wcsstr(argv[i], PARM_IN)) {
				if (wcslen(argv[i]) > PARM_MAX_SIZE) throw ERROR_THROW(104);

				parm_1 = true;

				wcscpy_s(result.in, argv[i] + 4);
			}
			// ��� Out
			else if (wcsstr(argv[i], PARM_OUT)) {
				if (wcslen(argv[i]) > PARM_MAX_SIZE) throw ERROR_THROW(104);

				parm_2 = true;

				wcscpy_s(result.out, argv[i] + 5);
			}
			// ��� Log
			else if (wcsstr(argv[i], PARM_LOG)) {
				if (wcslen(argv[i]) > PARM_MAX_SIZE) throw ERROR_THROW(104);

				parm_3 = true;

				wcscpy_s(result.log, argv[i] + 5);
			}
		}

		// ���� ��� In �� ������
		if (parm_1 == false) throw ERROR_THROW(100);

		// ���� ��� Out �� ������� �� ���������
		if (parm_2 == false) {
			wcscpy_s(result.out, L"Result");
			wcsncat_s(result.out, PARM_OUT_DEF_EXT, 4);
		}
		// ���� � out ����� �� ������� ����������
		else if (!wcsstr(result.out, L"."))
			wcsncat_s(result.out, PARM_OUT_DEF_EXT, 4);

		// ���� ��� Log �� ������� �� ���������
		if (parm_3 == false) {
			wcscpy_s(result.log, L"Log");
			wcsncat_s(result.log, PARM_LOG_DEF_EXT, 4);
		}
		// ���� � log ����� �� ������� ����������
		else if (!wcsstr(result.log, L"."))
			wcsncat_s(result.log, PARM_LOG_DEF_EXT, 4);

		return result;
	}
}