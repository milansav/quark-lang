#pragma once
#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
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
			SEPARATOR,
			AMPERSAND,
			WALL
		};

		inline Token(Type type);

		inline Token(Type type, char* start, size_t len);

		inline Token(Type type, char* _start, char* _end);

	private:
		Type temp_type{};
		char* start = nullptr;
		char* end = nullptr;
		string_view temp_lexeme{};
	public:
		Type type() const noexcept;

		string_view lexeme() const noexcept;

		bool  is(Type type) const noexcept;

		bool is_one_of(Type type1, Type type2) const noexcept;
	};

	bool is_identifier(char c) noexcept;

	bool is_digit(char c);

	bool is_space(char c);

	class Lexer
	{
		char* ptr = nullptr;
	public:
		/*inline */Lexer(char* code);

		Token check() noexcept;
		Token identifier() noexcept;
		Token number() noexcept;
		Token slash_or_comment() noexcept;
		Token other(Token::Type type) noexcept;

		char next() noexcept;
		char get() noexcept;
	};

	string token_to_string(Token::Type token);

#endif // !LEXER_H
