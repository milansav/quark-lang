#include "parser.h"
#include <stdio.h>
#include <string.h>

struct token curr_n()
{
    if(t_ptr != NULL)
    {
        return *t_ptr;
    }
}

struct token peek_n()
{
    if(t_ptr+1)
    {
        return *(t_ptr+1);
    }
}

void next_n()
{
    if(t_ptr+1)
    {
        t_ptr++;
    }
}

AST* parse_code(struct dynarr* _darr)
{
    tree = malloc(sizeof(AST));
    darr = _darr;
    t_ptr = darr->token_arr;
    tree->body = malloc(sizeof(program));
    tree->body->body = malloc(sizeof(sttmntarr));
    construct(tree->body->body);
    current_scope = tree->body->body;
    //tree->body->head = malloc(sizeof(sttmntarr)); //Malloc parameters
    //construct(tree->body->head); //Parameters

    for(int i = 0; i < darr->count; i++, next_n())
    {
        switch(darr->token_arr[i].type)
        {
            case KEYWORD:
                keyword();
            break;
        }
        printf("%s\n", darr->token_arr[i].label);
    }
}

void keyword()
{
    if(!strcmp("void", curr_n().label))
    {
        function();
    }
    else
    if(!strcmp("int", curr_n().label))
    {
        declare();
    }
}

void function()
{

}

void declare()
{
    printf("Declaring a variable\n");
    struct variable* var = malloc(sizeof(variable));
}