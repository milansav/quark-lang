#include "parser.h"

struct token curr_n(){ return *(token*)n_ptr; }
struct token peek_n(){ return *(token*)(n_ptr+1);}
void next_n(){n_ptr++;}

AST* parse_code(struct dynarr* _darr)
{
    darr = _darr;
    n_ptr = _darr->token_arr;
    struct program_node program;
    tree.program = &program;
    n_arr_construct(program.body);
    n_arr_construct(program.head);

    //parse();
    //return &tree;
}

void parse()
{
    for(uint i = 0; i < darr->count; i++)
    {
        printf("%s", n_ptr->label);
        /*if(n_ptr->type == KEYWORD)
        {
            //keyword();
        }*/
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
    struct function_node function;
    n_ptr++;
    function.name = malloc(strlen(n_ptr->label));
    function.name = n_ptr->label;
    n_arr_construct(function.body->nodes);
    n_ptr++;
    
    while(n_ptr->type != CLOSE_BRACKET)
    {
        if(n_ptr->type == KEYWORD && !strcmp("int", n_ptr->label))
        {
            size_t size = sizeof(function.head)+sizeof(variable_node);
            function.head = realloc(function.head, size);
        }

        n_ptr++;
    }
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