#include "lexer.h"
#include "../util/util.h"
#include <stdlib.h>
#include <string.h>

dynarr* lexifyy(char* code)
{
    ptr = code;

    while(curr() != '\0')
    {
        if(curr() == '/' && peek() == '/') skip_comment_line();
        if(curr() == '/' && peek() == '*') skip_comment_block();
    }
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


bool is_space(char c)
{
    return (!strcmp(c, '\n') || !strcmp(c, '\t') || !strcmp(c, ' ') || !strcmp(c, '\r'));
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
    return (true);
}