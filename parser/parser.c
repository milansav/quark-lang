#include "parser.h"

AST* parse(struct dynarr* _darr)
{
    darr = _darr;

    for(currentToken = 0; currentToken < darr->count; currentToken++)
    {
        switch(darr->token_arr[currentToken].type)
        {
            case KEYWORD:
                keyword();
            break;
        }
    }
}

void keyword()
{
    char* label = darr->token_arr[currentToken].label;
    if(!strcmp(label, "void")) function();
    else
    if(!strcmp(label, "if"));
    else
    if(!strcmp(label, "else"));
    else
    if(!strcmp(label, "return"));
    else
    if(!strcmp(label, "int"));
}