#include "lexer.h"
#include "token.h"
#include "../dynarr/dynarr.h"
#include "../utils/keywords.h"
#include "../utils/debug.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

lexeme_dynarr* lexer_lexify(char* code)
{
    ptr = code;

    lexeme_dynarr* tokens = (lexeme_dynarr*)malloc(sizeof(lexeme_dynarr));
    dynarr_construct(tokens);

    while(!eof(char_curr()))
    {
        while(is_space(char_curr())) char_next();

        if(g_debug_mode & OUTPUT_LEXER || g_debug_mode & OUTPUT_ALL)
        {
        printf("Curr: %c\n", char_curr());
        }

        if(char_curr() == '/' && char_peek() == '/') skip_comment_line();
        if(char_curr() == '/' && char_peek() == '*') skip_comment_block();

        if(is_operator(char_curr())) dynarr_add(tokens, operator_literal());
        else
        if(is_number(char_curr())) dynarr_add(tokens, number_literal());
        else
        if(is_identifier(char_curr())) dynarr_add(tokens, identifier());
        else
        if(char_curr() == '\'') dynarr_add(tokens, char_literal());
        else
        if(char_curr() == '"') dynarr_add(tokens, string_literal());
        else
        if(is_other(char_curr())) dynarr_add(tokens, other());

        char_next(); //To future me: never ever don't you even think about removing this one... unless you want to wait for a few minutes to reboot your pc ofc
    }

    return tokens;
}

char char_curr(){ return *ptr;} 
char char_peek(){ return *(ptr+1);}
void char_next(){ ptr++;}

void skip_white_space()
{
    while(is_space(char_curr())) char_next();
}
void skip_comment_line()
{
    while(char_curr() != '\n') char_next();
}
void skip_comment_block()
{
    while(char_curr() != '*' && char_peek() != '/') char_next();
}

lexeme identifier()
{
    lexeme t;
    char* start = ptr;
    while(is_identifier(char_peek())) char_next();
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

lexeme string_literal()
{
    lexeme t;
    char_next();
    char* start = ptr;
    while(char_curr() != '"') char_next();
    char* end = ptr;
    t.label = malloc(sizeof(char) * (end-start));
    strncpy(t.label, start, (end-start));
    t.type = STRING_LITERAL;
    return t;
}

lexeme number_literal()
{
    lexeme t;
    char* start = ptr;
    while(is_number(char_peek())) char_next();
    char* end = ptr+1;
    t.label = malloc(sizeof(char) * (end-start));
    strncpy(t.label, start, (end-start));
    t.type = NUMBER_LITERAL;
    return t;
}

lexeme char_literal()
{
    lexeme t;
    char_next();
    char* start = ptr;
    while(char_curr()  != '\'') char_next();
    char* end = ptr;
    t.label = malloc(sizeof(char) * (end-start));
    strncpy(t.label, start, (end-start));
    t.type = CHAR_LITERAL;
    return t;
}

lexeme operator_literal()
{
    lexeme t;
    char* start = ptr;
    while(is_operator(char_curr())) char_next();
    char* end = ptr;
    t.label = malloc(sizeof(char) * (end-start));
    strncpy(t.label, start, (end-start));
    t.type = OPERATOR;
    return t;
}

lexeme other()
{
    lexeme t;
    char* start = ptr;
    switch(char_curr())
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