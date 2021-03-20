#include "parser.h"
#include "../utils/debug.h"
#include <stdio.h>
#include <string.h>

struct token* parser_get_current_token()
{
    return parser_token_ptr;
}

struct token* parser_get_peek_token()
{
    return (parser_token_ptr+1);
}

void parser_goto_next_token()
{
    parser_token_ptr++;
}

AST* parser_parse_code(struct dynarr* _darr)
{
    parser_variables_table = malloc(sizeof(table));
    vartable_construct(parser_variables_table);

    //Creates program tree
    parser_tree = malloc(sizeof(AST));

    token_arr_count = _darr->count;
    token_arr_size = _darr->size;

    parser_token_ptr = _darr->token_arr;
    parser_tree->body = malloc(sizeof(program));
    parser_tree->body->body = malloc(sizeof(sttmntarr));
    sttmntarr_construct(parser_tree->body->body);
    parser_current_scope = parser_tree->body->body;
    //parser_tree->body->head = malloc(sizeof(sttmntarr)); //Malloc parameters
    //sttmntarr_construct(parser_tree->body->head); //Parameters

    printf("Amount of tokes: %d\n", token_arr_count);

    //return tree;
}

void parse_declaration() //int a; || int a = 10;
{
    if(debug_mode & OUTPUT_PARSER || debug_mode & OUTPUT_ALL)
    {
        printf("Declaring a byte\n");
    }
    
    parser_goto_next_token();
    struct variable* var = malloc(sizeof(variable));
    var->label = parser_get_current_token()->label;
    vartable_add(var, parser_variables_table);
}