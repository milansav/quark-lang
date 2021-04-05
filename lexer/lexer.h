#ifndef LEXER_H
#define LEXER_H

#include <stdbool.h>

char* ptr;
unsigned int spaces_removed;

struct lexeme_dynarr* lexer_lexify(char* code);

char char_curr();
char char_peek();
void char_next();

void skip_whitespace();
void skip_comment_line();
void skip_comment_block();

struct lexeme identifier();
struct lexeme string_literal();
struct lexeme number_literal();
struct lexeme char_literal();
struct lexeme operator_literal();
struct lexeme other();

bool is_space(char c);
bool is_number(char c);
bool is_identifier(char c);
bool is_keyword(char* c);
bool is_operator(char c);
bool is_other(char c);
bool eof(char c);
#endif