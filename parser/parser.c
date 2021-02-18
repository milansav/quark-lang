#include "parser.h"
#include <stdio.h>
#include <string.h>

struct token curr_n()
{
    if(t_ptr != NULL) return *t_ptr;
}

struct token peek_n()
{
    if(t_ptr+1) return *(t_ptr+1);
}

void next_n()
{
    if(t_ptr+1) t_ptr++;
}

AST* parse_code(struct dynarr* _darr)
{
    construct_table(&vars);

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

    return tree;
}

void keyword()
{
    if(!strcmp("byte", curr_n().label))
    {
        declaration();
    }
}

void declaration() //int a; || int a = 10;
{
    printf("Declaring an byte\n");
    struct variable* var = malloc(sizeof(variable));
    next_n(); //a
    char* label = curr_n().label; //This looks ugly but I'm lazy
    var->label = label;
    add(var,&vars);
    next_n(); //; || =
    if(!strcmp(curr_n().label, ";"))
    {}
    else if(!strcmp(curr_n().label, "="))
    {
        struct assign* asgn = malloc(sizeof(assign));
    }
}