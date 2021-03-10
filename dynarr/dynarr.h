#ifndef DYNARR_H
#define DYNARR_H

#include "../lexer/token.h"
#include <stdlib.h>

typedef struct dynarr {
    unsigned int size;
    unsigned int count;
    struct token* token_arr;
} dynarr;


void dynarr_construct(struct dynarr* parser_dynarr);
void dynarr_add(struct dynarr* parser_dynarr, struct token token_el);

#endif