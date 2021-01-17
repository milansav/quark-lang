#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>

class Token
{
	public:
	enum class Type
	{
		END,
		UNEXPECTED,
		IDENTIFIER,
		NUMBER,
		SLASH,
		PLUS,
		MULTIPLY,
		MINUS,
		EQUAL,
		MODULO,
		NOT,
		TERNARY,
		EXPONENT,
		CIRCA,
		MORE_THAN,
		LESS_THAN,
		LEFT_BRACKET,
		RIGHT_BRACKET,
		LEFT_CURLY,
		RIGHT_CURLY,
		LEFT_SQUARE,
		RIGHT_SQUARE,
		SEMICOLON,
		QUOTE,
		SINGLE_QUOTE,
		COMMENT,
		DOT,
		DOUBLE_DOT,
		SEPARATOR,
		AMPERSAND,
		WALL
	};

	Token(Type type);
	Token(Type type, char* start, size_t len);
	Token(Type type, char* _start, char* _end);

	private:
	Type temp_type{};
	char* start = nullptr;
	char* end = nullptr;
	std::string temp_lexeme{};

	public:
	Type type() const noexcept;
	std::string lexeme() const noexcept;
	bool is(Type type) const noexcept;
	bool is_one_of(Type type1, Type type2) const noexcept;
};

bool is_identifier(char c) noexcept;
bool is_digit(char c) noexcept;
bool is_space(char c) noexcept;

class Lexer
{
	char* ptr = nullptr;

	public:
	Lexer(char* code);

	Token check() noexcept;
	Token identifier() noexcept;
	Token number() noexcept;
	Token slash_or_comment() noexcept;
	Token other(Token::Type type) noexcept;

	char next() noexcept;
	char get() noexcept;
};

std::string token_to_string(Token::Type token);

#endif
