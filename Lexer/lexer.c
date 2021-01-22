#include "../dynarr/dynarr.h"
#include "lexer.h"
#include <stdlib.h>
#include <string.h>

dynarr* lexify(char* code)
{
    ptr = code;

    dynarr* tokens = (dynarr*)malloc(sizeof(dynarr));
    arr_construct(tokens);

    while(curr() != '\0')
    {
        while(is_space(curr())) next();

        if(curr() == '/' && peek() == '/') skip_comment_line();
        if(curr() == '/' && peek() == '*') skip_comment_block();

        if(is_operator(curr())) add_token(tokens, operator_literal());
        else
        if(is_number(curr())) add_token(tokens, number_literal());
        else
        if(is_identifier(curr())) add_token(tokens, identifier());
        else
        if(curr() == '\'') add_token(tokens, char_literal());
        else
        if(curr() == '"') add_token(tokens, string_literal());
        else other();

        next();
    }

    return tokens;
}

char curr(){ return *ptr;} 
char peek(){ return *ptr+1;}
void next(){ ptr++;}

void skip_white_space()
{
    while(is_space(curr())) next();
}
void skip_comment_line()
{
    while(curr() != '\n') next();
}
void skip_comment_block()
{
    while(curr() != '*' && peek() != '/') next();
}

struct token identifier()
{
    struct token t;
    char* start = ptr;
    while(is_identifier(curr())) next();
    char* end = ptr;
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
    while(curr() != '"') next();
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
    while(is_number(curr())) next();
    char* end = ptr;
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
    while(curr()  != '\'') next();
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
    while(is_operator(curr())) next();
    char* end = ptr;
}
struct token other()
{

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
    return (!strcmp(c, "if") || !strcmp(c, "else"));
}
bool is_operator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '=';
}