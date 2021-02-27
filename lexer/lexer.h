#ifndef LEXER_H
#define LEXER_H

#include <stdbool.h>

char* ptr;

struct dynarr* lexer_lexify(char* code);

char lexer_get_current_char();
char peek();
void next();

void skip_whitespace();
void skip_comment_line();
void skip_comment_block();

struct token identifier();
struct token string_literal();
struct token number_literal();
struct token char_literal();
struct token operator_literal();
struct token other();

bool is_space(char c);
bool is_number(char c);
bool is_identifier(char c);
bool is_keyword(char* c);
bool is_operator(char c);
bool is_other(char c);
bool eof(char c);
#endif