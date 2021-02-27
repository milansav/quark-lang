#include "parser.h"
#include "../utils/debug.h"
#include <stdio.h>
#include <string.h>

struct token* parser_get_current_token()
{
    if(parser_token_ptr) return parser_token_ptr;
}

struct token* parser_get_peek_token()
{
    if(parser_token_ptr+1) return parser_token_ptr+1;
}

void next_n()
{
    parser_token_ptr++;
}

AST* parser_parse_code(struct dynarr* _darr)
{
    parser_variables_table = malloc(sizeof(table));
    vartable_construct(parser_variables_table);

    parser_tree = malloc(sizeof(AST));
    parser_dynarr = _darr;
    parser_token_ptr = parser_dynarr->token_arr;
    parser_tree->body = malloc(sizeof(program));
    parser_tree->body->body = malloc(sizeof(sttmntarr));
    sttmntarr_construct(parser_tree->body->body);
    parser_current_scope = parser_tree->body->body;
    //parser_tree->body->head = malloc(sizeof(sttmntarr)); //Malloc parameters
    //sttmntarr_construct(parser_tree->body->head); //Parameters

    for(int i = 0; i < parser_dynarr->count; i++, next_n())
    {

        switch(parser_get_current_token()->type)
        {
            case KEYWORD:
                parse_keyword();
                break;
            default:
                printf(COLOR_RED "Unknown token type" COLOR_RESET "\n");
                break;
        }
    }

    //return tree;
}

void parse_keyword()
{
    if(!strcmp("byte", parser_get_current_token()->label))
    {
        parse_declaration();
    }
}

void parse_declaration() //int a; || int a = 10;
{
    if(debug_mode & OUTPUT_PARSER || debug_mode & OUTPUT_ALL)
    {
        printf("Declaring a byte\n");
    }
    
    struct variable* var = malloc(sizeof(variable));
    var->label = parser_get_current_token()->label;
    vartable_add(var, parser_variables_table);

    

}