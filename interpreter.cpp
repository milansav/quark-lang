#include <string>
#include <cstring>
#include <iostream>
#include <iomanip>
#include "tokenizer.h"


int main()
{
	std::string code;
	bool read = 1;
	while(read)
	{
		std::string temp;
		getline(std::cin, temp);
		if(temp != "end;") code += temp;

		if(temp == "end;")
		{
			int char_array_size = code.length();
			char* char_array = new char[code.length() + 1];
			strcpy(char_array, code.c_str());
			
			Lexer lexer(char_array);

			for(auto token = lexer.check(); 
				not token.is_one_of(Token::Type::END, Token::Type::UNEXPECTED);
				token = lexer.check())
			{
				std::cout << std::setw(13) << token_to_string(token.type()) << "|" << token.lexeme() << std::endl;
			}

		}
		else if (temp == "exit")
		{
			return 0;
		}
	}

	return 0;
}
