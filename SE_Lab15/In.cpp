#include "stdafx.h"

using namespace std;

namespace In {
	in getin(wchar_t* source_file_path)
	{
		in result = in();							// Результат
		Error::error_inner nowpos = {0, 0};			// Текущая позиция считывания
		ifstream file = ifstream(source_file_path);	// Поток

		if (!file.is_open()) throw ERROR_THROW(110);

		result.code_table = new int[256] IN_CODE_TABLE;
		
		string str;				// Строка хронящая текстовый результат
		unsigned char uchar;	// Текущий анализируемый символ (беззнаковый)
		while (true)
		{
			file >> uchar >> noskipws;

			if (file.eof()) break;

			switch (result.code_table[(int)uchar])
			{
			case in::T:
				str.push_back(uchar);
				result.size_of_code++;
				if (uchar == IN_CODE_ENDL) result.lines_count++;
				break;

			case in::F:
				throw ERROR_THROW_IN(111, nowpos.line, nowpos.col);

			case in::I:
				result.count_of_ignore++;
				break;

			default:
				if (uchar == 192) str.push_back('-');
				result.size_of_code++;
				break;
			}

			if (uchar == IN_CODE_ENDL) {
				nowpos.col = 0;
				nowpos.line++;
			}
			else nowpos.col++;
		}

		file.close();

		result.source_code = new unsigned char[str.size() + 1];

		// Копирование сиволов из знаковой строки в беззнаковую
		for (int i = 0; i < str.size(); i++)
			result.source_code[i] = (unsigned char)str[i];

		result.source_code[str.size()] = '\0';

		return result;
	}

	void WriteOut(in inner, wchar_t outpath[]) {

		ofstream file(outpath);

		if (!file.is_open()) throw ERROR_THROW(113);

		file.clear();

		file << inner.source_code;

		file.close();
	}
}