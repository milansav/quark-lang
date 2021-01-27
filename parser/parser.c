#include "parser.h"

struct token curr_n(){ return *(token*)n_ptr; }
struct token peek_n(){ return *(token*)(n_ptr+1);}
void next_n(){n_ptr++;}

AST* parse_code(struct dynarr* _darr)
{
    darr = _darr;
    n_ptr = _darr->token_arr;
    struct AST* ast;
    struct program_node program;
    ast->program = &program;
    current_scope = program.body;

    parse();
}

void parse()
{
    for(uint i = 0; i < darr->count; i++)
    {
        printf("%s", n_ptr->label);
        n_ptr++;
    }
}

void keyword()
{
    char* label = curr_n().label;
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
    function.name = malloc(sizeof(peek_n().label));
    function.name = peek_n().label;
}

void branch()
{

}

void _return()
{

}

void declare()
{

}