#include "dynarr.h"
#include "../lexer/token.h"
#include <stdlib.h>

void dynarr_construct(struct lexeme_dynarr* parser_dynarr)
{
    parser_dynarr->count = 0;
    parser_dynarr->size = 8;
    parser_dynarr->token_arr = malloc(sizeof(lexeme) * parser_dynarr->size);
}

void dynarr_add(struct lexeme_dynarr* parser_dynarr, struct lexeme token_el)
{
    if(parser_dynarr->count >= parser_dynarr->size)
    {
        parser_dynarr->size *= 2;
        parser_dynarr->token_arr = realloc(parser_dynarr->token_arr, parser_dynarr->size * sizeof(lexeme));
    }
    parser_dynarr->token_arr[parser_dynarr->count] = token_el;
    parser_dynarr->count++;
}