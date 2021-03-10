#include "lexer.h"
#include "token.h"
#include "../dynarr/dynarr.h"
#include "../utils/keywords.h"
#include "../utils/debug.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

dynarr* lexer_lexify(char* code)
{
    ptr = code;

    dynarr* tokens = (dynarr*)malloc(sizeof(dynarr));
    dynarr_construct(tokens);

    while(!eof(lexer_get_current_char()))
    {
        while(is_space(lexer_get_current_char())) next();

        if(debug_mode & OUTPUT_LEXER || debug_mode & OUTPUT_ALL)
        {
        printf("Curr: %c\n", lexer_get_current_char());
        }

        if(lexer_get_current_char() == '/' && peek() == '/') skip_comment_line();
        if(lexer_get_current_char() == '/' && peek() == '*') skip_comment_block();

        if(is_operator(lexer_get_current_char())) dynarr_add(tokens, operator_literal());
        else
        if(is_number(lexer_get_current_char())) dynarr_add(tokens, number_literal());
        else
        if(is_identifier(lexer_get_current_char())) dynarr_add(tokens, identifier());
        else
        if(lexer_get_current_char() == '\'') dynarr_add(tokens, char_literal());
        else
        if(lexer_get_current_char() == '"') dynarr_add(tokens, string_literal());
        else
        if(is_other(lexer_get_current_char())) dynarr_add(tokens, other());

        next(); //To future me: never ever don't you even think about removing this one... unless you want to wait for a few minutes to reboot your pc ofc
    }

    return tokens;
}

char lexer_get_current_char(){ return *ptr;} 
char peek(){ return *(ptr+1);}
void next(){ ptr++;}

void skip_white_space()
{
    while(is_space(lexer_get_current_char())) next();
}
void skip_comment_line()
{
    while(lexer_get_current_char() != '\n') next();
}
void skip_comment_block()
{
    while(lexer_get_current_char() != '*' && peek() != '/') next();
}

struct token identifier()
{
    struct token t;
    char* start = ptr;
    while(is_identifier(peek())) next();
    char* end = ptr+1;
    t.label = malloc(sizeof(char) * (end-start));
    strncpy(t.label, start, (end-start));
    if(is_keyword(t.label))
    {
        t.type = KEYWORD;
    }
    else
    {
    t.type = IDENTIFIER;
    }
    return t;
}
struct token string_literal()
{
    struct token t;
    next();
    char* start = ptr;
    while(lexer_get_current_char() != '"') next();
    char* end = ptr;
    t.label = malloc(sizeof(char) * (end-start));
    strncpy(t.label, start, (end-start));
    t.type = STRING_LITERAL;
    return t;
}
struct token number_literal()
{
    struct token t;
    char* start = ptr;
    while(is_number(peek())) next();
    char* end = ptr+1;
    t.label = malloc(sizeof(char) * (end-start));
    strncpy(t.label, start, (end-start));
    t.type = NUMBER_LITERAL;
    return t;
}
struct token char_literal()
{
    struct token t;
    next();
    char* start = ptr;
    while(lexer_get_current_char()  != '\'') next();
    char* end = ptr;
    t.label = malloc(sizeof(char) * (end-start));
    strncpy(t.label, start, (end-start));
    t.type = CHAR_LITERAL;
    return t;
}
struct token operator_literal()
{
    struct token t;
    char* start = ptr;
    while(is_operator(lexer_get_current_char())) next();
    char* end = ptr;
    t.label = malloc(sizeof(char) * (end-start));
    strncpy(t.label, start, (end-start));
    t.type = OPERATOR;
    return t;
}
struct token other()
{
    struct token t;
    char* start = ptr;
    switch(lexer_get_current_char())
    {
        case '{':
            t.type = OPEN_CURLY;
        break;
        case '}':
            t.type = CLOSE_CURLY;
        break;
        case '(':
            t.type = OPEN_BRACKET;
        break;
        case ')':
            t.type = CLOSE_BRACKET;
        break;
        case ';':
            t.type = SEMICOLON;
        break;
        case ',':
            t.type = COMMA;
        break;
        case '.':
            t.type = DOT;
        break;
    }
    t.label = malloc(1);
    strncpy(t.label, start, 1);
    return t;
}

bool is_space(char c)
{
    return c == '\n' || c == '\t' || c == ' ' || c == '\r';
}
bool is_number(char c)
{
    return ((c >= '0') && (c <= '9'));
}
bool is_identifier(char c)
{
    return (is_number(c) || ((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')));
}
bool is_keyword(char* c)
{
    for(unsigned int i = 0; i < (sizeof(keywords)/sizeof(char*)); i++)
    {
        if(!strcmp(c, keywords[i])) return true;
    }
    return false;
}
bool is_operator(char c)
{
    return (c == '+') || (c == '-') || (c == '*') || (c == '/') || (c == '%') || (c == '=');
}
bool is_other(char c)
{
    return (c == '{') || (c == '}') || (c == '(') || (c == ')') || (c == ';') || (c == ',') || (c == '.');
}
bool eof(char c)
{
    return c == '\0';
}