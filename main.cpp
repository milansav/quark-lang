#include <string>
#include <cstring>
#include "lexer.h"

int main()
{
	string code;
	bool read = 1;
	while (read)
	{
		string temp;
		getline(cin, temp);
		if(temp != "end;")
		{
		code += temp;
		}
		if (temp == "end;")
		{
			int char_array_size = code.length();

			char* char_array = new char[code.length() + 1];
#pragma warning(suppress : 4996)
			strcpy(char_array, code.c_str());
			Lexer lexer(char_array);

			for (auto token = lexer.check();
				not token.is_one_of(Token::Type::END, Token::Type::UNEXPECTED);
				token = lexer.check())
			{
				cout << setw(13) << token_to_string(token.type()) << "|" << token.lexeme() << endl;
			}

		}
		else if (temp == "exit")
		{
			return 0;
		}
	}
	return 0;
}
