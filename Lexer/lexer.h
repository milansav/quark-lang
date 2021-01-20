#ifndef LEXER_H
#define LEXER_H_

#include "token.h"
#include "../util/util.h"
#include <stdbool.h>

struct dynarr darr;

char* ptr;

char curr();
char peek();
void next();

void skip_whitespace();
void skip_comment_line();
void skip_comment_block();

struct token identifier();
struct token keyword();
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
#endif