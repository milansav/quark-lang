#include "tokenizer.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <cctype>

Token::Token(Token::Type type)
{
	temp_type = type;
}

Token::Token(Token::Type type, char* start, size_t len)
{
	temp_type = type;
	temp_lexeme = std::string(start, len);
}

Token::Token(Token::Type type, char* start, char* end)
{
	temp_type = type;
	temp_lexeme = std::string(start, (size_t)(end-start));
}

Token::Type Token::type() const noexcept { return temp_type; }

std::string Token::lexeme() const noexcept { return temp_lexeme; }

bool Token::is(Token::Type type) const noexcept { return type == temp_type; }

bool Token::is_one_of(Token::Type type1, Token::Type type2) const noexcept { return Token::is(type1) || Token::is(type2); }

bool is_identifier(char c) noexcept
{
	return std::isalpha(c) || c == '_';
}

bool is_digit(char c) noexcept
{
	return std::isdigit(c);
}

bool is_space(char c) noexcept
{
	return std::isspace(c);
}

Lexer::Lexer(char* code)
{
	ptr = code;
}

char Lexer::next() noexcept { return *ptr++; }
char Lexer::get() noexcept { return *ptr; }

Token Lexer::other(Token::Type type) noexcept { return Token(type, ptr++, 1); }

Token Lexer::check() noexcept
{
	while(is_space(get())) next();

	switch(get())
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
		case '0x7E':
			return other(Token::Type::CIRCA);
		case '0x5E':
			return other(Token::Type::EXPONENT);
		case '%':
			return other(Token::Type::MODULO);
		case '?':
			return other(Token::Type::TERNARY);
		case ':':
			return other(Token::Type::DOUBLE_DOT);
		case '!':
			return other(Token::Type::NOT);
	}
}

Token Lexer::identifier() noexcept
{
	char* start = ptr;
	next();
	while(is_identifier(get())) next();
	return Token(Token::Type::IDENTIFIER, start, ptr);
}

Token Lexer::number() noexcept
{
	char* start = ptr;
	next();
	while(is_digit(get())) next();
	return Token(Token::Type::NUMBER, start, ptr);
}

Token Lexer::slash_or_comment() noexcept
{
	char* start = ptr;
	if(get() == '/' && next() == '/')
	{
		return Token(Token::Type::COMMENT, start, ptr);

	}

	return Token(Token::Type::SLASH, start, 1);
}

std::string token_to_string(Token::Type token)
{
	const char* tokens[] = {"END", "UNEXPECTED", "IDENTIFIER", "NUMBER", "SLASH", "PLUS", "MULTIPLY", "MINUS", "EQUAL", "EQUAL", "MODULO", "NOT", "TERNARY", "EXPONENT", "CIRCA", "MORE_THAN", "LESS_THAN", "LEFT_BRACKET", "RIGHT_BRACKET", "LEFT_CURLY", "RIGHT_CURLY", "LEFT_SQUARE", "RIGHT_SQUARE", "SEMICOLON", "QUOTE", "SINGLE_QUOTE", "COMMENT", "DOT", "DOUBLE_DOT", "SEPARATOR", "AMPERSAND", "WALL"};

	union Union
	{
		Token::Type tt;
		int i;
	};

	Union tokenUN;
	tokenUN.tt = token;

	std::string to_return = tokens[tokenUN.i];
	return to_return;
}
