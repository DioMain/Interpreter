#pragma once

#define IN_MAX_LEN_TEXT 1024*1024		// ������������ ������ ��������� ���� 1 mb
#define IN_CODE_ENDL '\n'				// ������ ����� ������

// Fisting is 300 backs
#define IN_CODE_TABLE	{\
						in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::T, in::F, in::F, in::I, in::F, in::F,\
						in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F,\
						in::T, in::T, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F,\
						in::T, in::F, in::T, in::F, in::T, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F,\
						in::F, in::F, in::F, in::F, in::T, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::T,\
						in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::I, in::F, in::F, in::F, in::F, in::F, in::F, in::F,\
						in::F, in::T, in::F, in::T, in::F, in::F, in::F, in::F, in::T, in::T, in::F, in::T, in::T, in::T, in::F, in::F,\
						in::F, in::F, in::F, in::F, in::F, in::T, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F,\
																																	   \
						in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F,\
						in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F,\
						in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F,\
						in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F,\
						  '-', in::F, in::F, in::F, in::T, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::T, in::F,\
						in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F,\
						in::T, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::T, in::F, in::T, in::T, in::T, in::F, in::F, in::F,\
						in::F, in::F, in::F, in::T, in::F, in::F, in::F, in::T, in::F, in::F, in::F, in::F, in::F, in::F, in::F, in::F \
						}

namespace In {
	
	struct in
	{
		in() : size_of_code(0), lines_count(1), count_of_ignore(0), source_code(nullptr), code_table(nullptr) { }

		// T - ���������� ������; F - ������������� ������; I - ������������
		enum { T = 1024, F = 2048, I = 4096 };

		int size_of_code;		// ���-�� ��������
		int lines_count;		// ���-�� �����
		int count_of_ignore;	// ���-�� ����������������� ��������

		unsigned char* source_code;	//�������� ���

		int* code_table;	// �������� ��������: T, F, I	����� ��������
	};

	in getin(wchar_t* source_file_path);
}