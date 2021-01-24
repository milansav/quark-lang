#include <iostream>
#include <iomanip>
#include <string>
#include "lexer.h"

//THIS LEXER IS A FORK OF 'SIMPLE C++ LEXER' by Arrieta, AFTER THIS I STARTED OPTIMIZING IT AND CHANGING MOST OF C++ STUFF INTO C

using namespace std;


		inline Token::Token(Type type)
		{
			temp_type = type;
		}

		inline Token::Token(Type type, char* start, size_t len)
		{
			temp_type = type;
			temp_lexeme = string_view{ start, len };
		}

		inline Token::Token(Type type, char* _start, char* _end)
		{
			temp_type = type;
			start = _start;
			end = _end;
			temp_lexeme = string_view{ start, (size_t)std::distance(start, end) };
		}

		Token::Type Token::type() const noexcept { return temp_type; }

		string_view Token::lexeme() const noexcept { return temp_lexeme; }

		bool Token::is(Type type) const noexcept { return type == temp_type; }

		bool Token::is_one_of(Type type1, Type type2) const noexcept { return is(type1) || is(type2); }

	bool is_identifier(char c) noexcept
	{
		switch (c) {
		case 'A':
		case 'B':
		case 'C':
		case 'D':
		case 'E':
		case 'F':
		case 'G':
		case 'H':
		case 'I':
		case 'J':
		case 'K':
		case 'L':
		case 'M':
		case 'N':
		case 'O':
		case 'P':
		case 'Q':
		case 'R':
		case 'S':
		case 'T':
		case 'U':
		case 'V':
		case 'W':
		case 'X':
		case 'Y':
		case 'Z':
		case 'a':
		case 'b':
		case 'c':
		case 'd':
		case 'e':
		case 'f':
		case 'g':
		case 'h':
		case 'i':
		case 'j':
		case 'k':
		case 'l':
		case 'm':
		case 'n':
		case 'o':
		case 'p':
		case 'q':
		case 'r':
		case 's':
		case 't':
		case 'u':
		case 'v':
		case 'w':
		case 'x':
		case 'y':
		case 'z':
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		case '_':
		/*case '!':
		case '?':
		case '.':
		case ':':
		case '/':*/
			return true;
		default:
			return false;
		}
	}

	bool is_digit(char c)
	{
		switch (c)
		{
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			return true;
		default:
			return false;
		}
	}

	bool is_space(char c)
	{
		switch (c)
		{
		case '\n':
		case ' ':
		case '\t':
		case '\r':
			return true;
		default:
			return false;
		}
	}


		/*inline*/ Lexer::Lexer(char* code)
		{
			ptr = code;
		}

		char Lexer::next() noexcept { return *ptr++; }
		char Lexer::get() noexcept { return *ptr; }

	Token Lexer::other(Token::Type type) noexcept { return Token(type, ptr++, 1); }

	Token Lexer::check() noexcept
	{
		while (is_space(get())) next();

		switch (get())
		{
		case '\0':
			return Token(Token::Type::END);
		default:
			return Token(Token::Type::UNEXPECTED);
		case 'A':
		case 'B':
		case 'C':
		case 'D':
		case 'E':
		case 'F':
		case 'G':
		case 'H':
		case 'I':
		case 'J':
		case 'K':
		case 'L':
		case 'M':
		case 'N':
		case 'O':
		case 'P':
		case 'Q':
		case 'R':
		case 'S':
		case 'T':
		case 'U':
		case 'V':
		case 'W':
		case 'X':
		case 'Y':
		case 'Z':
		case 'a':
		case 'b':
		case 'c':
		case 'd':
		case 'e':
		case 'f':
		case 'g':
		case 'h':
		case 'i':
		case 'j':
		case 'k':
		case 'l':
		case 'm':
		case 'n':
		case 'o':
		case 'p':
		case 'q':
		case 'r':
		case 's':
		case 't':
		case 'u':
		case 'v':
		case 'w':
		case 'x':
		case 'y':
		case 'z':
			return identifier();
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			return number();
		case ';':
			return other(Token::Type::SEMICOLON);
		case '{':
			return other(Token::Type::LEFT_CURLY);
		case '}':
			return other(Token::Type::RIGHT_CURLY);
		case '(':
			return other(Token::Type::LEFT_BRACKET);
		case ')':
			return other(Token::Type::RIGHT_BRACKET);
		case '<':
			return other(Token::Type::LESS_THAN);
		case '>':
			return other(Token::Type::MORE_THAN);
		case '[':
			return other(Token::Type::LEFT_SQUARE);
		case ']':
			return other(Token::Type::RIGHT_SQUARE);
		case '"':
			return other(Token::Type::QUOTE);
		case '0x27':
			return other(Token::Type::SINGLE_QUOTE);
		case '+':
			return other(Token::Type::PLUS);
		case '-':
			return other(Token::Type::MINUS);
		case '*':
			return other(Token::Type::MULTIPLY);
		case '/':
			return slash_or_comment();
		case '=':
			return other(Token::Type::EQUAL);
		case '.':
			return other(Token::Type::DOT);
		case ',':
			return other(Token::Type::SEPARATOR);
		case '&':
			return other(Token::Type::AMPERSAND);
		case '|':
			return other(Token::Type::WALL);
		}
	}

	Token Lexer::identifier() noexcept
	{
		char* start = ptr;
		next();
		while (is_identifier(get())) next();
		return Token(Token::Type::IDENTIFIER, start, ptr);
	}

	Token Lexer::number() noexcept
	{
		char* start = ptr;
		next();
		while (is_digit(get())) next();
		return Token(Token::Type::NUMBER, start, ptr);
	}

	Token Lexer::slash_or_comment() noexcept
	{
		char* start = ptr;
		if (get() == '/' && next() == '/')
		{
			return Token(Token::Type::COMMENT, start, ptr);
		}
		else if (get() == '/' && next() != '/')
		{
			return Token(Token::Type::SLASH, start, 1);
		}
	}

	string token_to_string(Token::Type token)
	{
		switch (token)
		{
		case Token::Type::END:
			return "End";
		case Token::Type::UNEXPECTED:
			return "Unexpected";
		case Token::Type::IDENTIFIER:
			return "Indentifier";
		case Token::Type::NUMBER:
			return "Identifier";
		case Token::Type::SLASH:
			return "Slash";
		case Token::Type::PLUS:
			return "Plus";
		case Token::Type::MULTIPLY:
			return "Multiplay";
		case Token::Type::MINUS:
			return "Minus";
		case Token::Type::EQUAL:
			return "Equal";
		case Token::Type::MORE_THAN:
			return "More than";
		case Token::Type::LESS_THAN:
			return "Less than";
		case Token::Type::LEFT_BRACKET:
			return "Left bracket";
		case Token::Type::RIGHT_BRACKET:
			return "Right bracket";
		case Token::Type::LEFT_CURLY:
			return "Left curly";
		case Token::Type::RIGHT_CURLY:
			return "Right curly";
		case Token::Type::LEFT_SQUARE:
			return "Left square";
		case Token::Type::RIGHT_SQUARE:
			return "Right square";
		case Token::Type::SEMICOLON:
			return "Semicolon";
		case Token::Type::QUOTE:
			return "Quote";
		case Token::Type::SINGLE_QUOTE:
			return "Single quote";
		case Token::Type::COMMENT:
			return "Comment";
		case Token::Type::DOT:
			return "Dot";
		case Token::Type::SEPARATOR:
			return "Separator";
		case Token::Type::AMPERSAND:
			return "Ampersand";
		case Token::Type::WALL:
			return "Wall";

		}
	}
