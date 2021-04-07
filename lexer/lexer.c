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
    lexeme_dynarr_construct(tokens);

    while(!eof(char_curr()))
    {
        while(is_space(char_curr()))
        {
            spaces_removed++;
            char_next();
        }

        if(char_curr() == '/' && char_peek() == '/') skip_comment_line();
        if(char_curr() == '/' && char_peek() == '*') skip_comment_block();

        if(is_operator(char_curr())) lexeme_dynarr_add(tokens, operator_literal());
        else
        if(is_number(char_curr())) lexeme_dynarr_add(tokens, number_literal());
        else
        if(is_identifier(char_curr())) lexeme_dynarr_add(tokens, identifier());
        else
        if(char_curr() == '\'') lexeme_dynarr_add(tokens, char_literal());
        else
        if(char_curr() == '"') lexeme_dynarr_add(tokens, string_literal());
        else
        if(is_other(char_curr())) lexeme_dynarr_add(tokens, other());

        char_next(); //To future me: never ever don't you even think about removing this one... unless you want to wait for a few minutes to reboot your pc ofc
    }

    printf(COLOR_YELLOW "Bytes removed: " COLOR_RESET " %d\n", spaces_removed);

    return tokens;
}

char char_curr(){ return *ptr;} 
char char_peek(){ return *(ptr+1);}
void char_next(){ ptr++;}

void skip_white_space()
{
    while(is_space(char_curr()))
    {
        spaces_removed++;
        char_next();
    }
}
void skip_comment_line()
{
    while(char_curr() != '\n') 
    {
        spaces_removed++;
        char_next();
    }
}
void skip_comment_block()
{
    while(char_curr() != '*' && char_peek() != '/') 
    {
        spaces_removed++;
        char_next();
    }
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

        if(!strcmp(t.label, "if"))
        {
            t.type = ifsym;
        }
        else if(!strcmp(t.label, "else"))
        {
            t.type = elsesym;
        }
        else if(!strcmp(t.label, "return"))
        {
            t.type = returnsym;
        }
        else if(!strcmp(t.label, "function"))
        {
            t.type = funcsym;
        }
        else if(!strcmp(t.label, "while"))
        {
            t.type = whilesym;
        }
        else if(!strcmp(t.label, "byte") || !strcmp(t.label, "int") || !strcmp(t.label, "float"))
        {
            t.type = varsym;
        }
        else if(!strcmp(t.label, "def"))
        {
            t.type = defsym;
        }
        else if(!strcmp(t.label, "struct"))
        {
            t.type = structsym;
        }
        else if(!strcmp(t.label, "const"))
        {
            t.type = constsym;
        }
    }
    else
    {
        t.type = ident;
    }
    return t;
}

lexeme string_literal()
{
    lexeme temp;
    char_next();
    char* start = ptr;
    while(char_curr() != '"') char_next();
    char* end = ptr;
    temp.label = malloc(sizeof(char) * (end-start));
    strncpy(temp.label, start, (end-start));
    temp.type = strnliteral;
    return temp;
}

lexeme number_literal()
{
    lexeme t;
    char* start = ptr;
    while(is_number(char_peek())) char_next();
    char* end = ptr+1;
    t.label = malloc(sizeof(char) * (end-start));
    strncpy(t.label, start, (end-start));
    t.type = number;
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
    t.type = charliteral;
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

    if(!strcmp(t.label, "+"))
    {
        t.type = plus;
    }
    else if(!strcmp(t.label, "-"))
    {
        t.type = minus;
    }
    else if(!strcmp(t.label, "*"))
    {
        t.type = times;
    }
    else if(!strcmp(t.label, "/"))
    {
        t.type = slash;
    }
    else if(!strcmp(t.label, "="))
    {
        t.type = assign;
    }
    else if(!strcmp(t.label, "=="))
    {
        t.type = eql;
    }
    else if(!strcmp(t.label, "!="))
    {
        t.type = neq;
    }
    else if(!strcmp(t.label, ">"))
    {
        t.type = gtr;
    }
    else if(!strcmp(t.label, "<"))
    {
        t.type = lss ;
    }
    else if(!strcmp(t.label, ">="))
    {
        t.type = geq;
    }
    else if(!strcmp(t.label, "<="))
    {
        t.type = leq;
    }

    return t;
}

lexeme other()
{
    lexeme t;
    char* start = ptr;
    switch(char_curr())
    {
        case '{':
            t.type = begin;
        break;
        case '}':
            t.type = end;
        break;
        case '(':
            t.type = lparen;
        break;
        case ')':
            t.type = rparen;
        break;
        case ';':
            t.type = semicolon;
        break;
        case ',':
            t.type = comma;
        break;
        case '.':
            t.type = dot;
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
    for(uint32 i = 0; i < (sizeof(keywords)/sizeof(char*)); i++)
    {
        if(!strcmp(c, keywords[i])) return true;
    }
    return false;
}
bool is_operator(char c)
{
    return (c == '+') || (c == '-') || (c == '*') || (c == '/') || (c == '%') || (c == '=') ||
            (c == '>')|| (c == '<') || (c == '!');
}
bool is_other(char c)
{
    return (c == '{') || (c == '}') || (c == '(') || (c == ')') || (c == ';') || (c == ',') || (c == '.');
}
bool eof(char c)
{
    return c == '\0';
}