#pragma once

#define PARM_IN L"-in:" // ���� �������� �����
#define PARM_OUT L"-out:" // ���� ��������� �����
#define PARM_LOG L"-log:" // ���� ����� ������� 
#define PARM_DEBAG L"-debag" // ���������� ����

#define PARM_MAX_SIZE 300 // ������������ ������ ��������� �����

#define PARM_OUT_DEF_EXT L".out" // ����������� ���������� ��������� �����
#define PARM_LOG_DEF_EXT L".log" // ����������� ���������� ����� �������

// ��������� ������� ������
namespace Parm {
	// ������� ���������
	struct parm
	{
		wchar_t in[PARM_MAX_SIZE];
		wchar_t out[PARM_MAX_SIZE];
		wchar_t log[PARM_MAX_SIZE];
	};

	// ��������� parm
	parm getparm(int argc, _TCHAR* argv[]);
}
