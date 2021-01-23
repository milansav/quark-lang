#include "dynarr.h"
#include "../lexer/token.h"
#include <stdlib.h>

void arr_construct(struct dynarr* darr)
{
    darr->count = 0;
    darr->size = 8;
    darr->token_arr = malloc(sizeof(token) * darr->size);
}

void add_token(struct dynarr* darr, struct token token_el)
{
    if(darr->count >= darr->size)
    {
        darr->size *= 2;
        darr->token_arr = realloc(darr->token_arr, darr->size * sizeof(token));
    }
    darr->token_arr[darr->count] = token_el;
    darr->count++;
}