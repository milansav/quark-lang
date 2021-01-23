#ifndef DYNARR_H
#define DYNARR_H

#include "../lexer/token.h"
#include <stdlib.h>

typedef struct dynarr {
    int size;
    int count;
    struct token* token_arr;
} dynarr;


void arr_construct(struct dynarr* darr);
void add_token(struct dynarr* darr, struct token token_el);

#endif