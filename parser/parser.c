#include "parser.h"
#include "../utils/debug.h"
#include <stdio.h>
#include <string.h>

struct token* curr_n()
{
    if(t_ptr) return t_ptr;
}

struct token* peek_n()
{
    if(t_ptr+1) return t_ptr+1;
}

void next_n()
{
    t_ptr++;
}

AST* parse_code(struct dynarr* _darr)
{
    vars = malloc(sizeof(table));
    construct_table(vars);

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
        if(debug_mode & OUTPUT_ALL || debug_mode & OUTPUT_TEST)
        {
            //printf("%s\n", curr_n()->label);
        }

        switch(curr_n()->type)
        {
            case KEYWORD:
                keyword();
                break;
            default:
                printf(COLOR_RED "Unknown token type" COLOR_RESET "\n");
                break;
        }
    }

    //return tree;
}

void keyword()
{
    if(!strcmp("byte", curr_n()->label))
    {
        declaration();
    }
}

void declaration() //int a; || int a = 10;
{
    if(debug_mode & OUTPUT_PARSER || debug_mode & OUTPUT_ALL)
    {
        printf("Declaring a byte\n");
    }
    
    struct variable* var = malloc(sizeof(variable));
    var->label = curr_n()->label;
    add(var, vars);

    

}