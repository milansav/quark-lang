#include "parser.h"

struct token curr(){ return *(token*)ptr; }
struct token peek(){ return *(token*)(ptr+1);}
void next(){ptr++;}

AST* parse_code(struct dynarr* _darr)
{
    darr = _darr;
    ptr = darr->token_arr;

}

void parse()
{
    while((ptr+1) != NULL)
    {
        switch(darr->token_arr[currentToken].type)
        {
            case KEYWORD:
                keyword();
            break;
        }
        next();
    }
}

void keyword()
{
    char* label = darr->token_arr[currentToken].label;
    if(!strcmp(label, "void")) function();
    else
    if(!strcmp(label, "if")) branch();
    //else
    //if(!strcmp(label, "else"));
    else
    if(!strcmp(label, "return")) _return();
    else
    if(!strcmp(label, "int")) declare();
}

void function()
{
    function_node function;
    function.name = malloc(sizeof(peek().label));
    function.name = peek().label;
}