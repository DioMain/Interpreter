#include "stdafx.h"

using namespace std;

namespace In {
	in getin(wchar_t* source_file_path)
	{
		in res = in();
		Error::error_inner nowpos = {0, 0};

		res.code_table = new int[256] IN_CODE_TABLE;

		ifstream file = ifstream(source_file_path);

		if (!file.is_open()) throw ERROR_THROW(110);
		
		string ustr;
		unsigned char uch;
		while (true)
		{
			file >> uch >> noskipws;

			if (file.eof()) break;

			switch (res.code_table[(int)uch])
			{
			case in::T:
				ustr.push_back(uch);

				res.size_of_code++;
				if (uch == IN_CODE_ENDL) res.lines_count++;
				break;
			case in::F:
				throw ERROR_THROW_IN(111, nowpos.line, nowpos.col);
			case in::I:
				res.count_of_ignore++;
				break;
			default:
				if (uch == 192) ustr.push_back('-');

				res.size_of_code++;
				break;
			}

			if (uch == IN_CODE_ENDL) {
				nowpos.col = 0;
				nowpos.line++;
			}
			else nowpos.col++;
		}

		file.close();

		res.source_code = new unsigned char[ustr.size()];
		for (int i = 0; i < ustr.size(); i++)
			res.source_code[i] = (unsigned char)ustr[i];

		res.source_code[ustr.size()] = '\0';

		return res;
	}
}