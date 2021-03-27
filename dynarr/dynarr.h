#ifndef DYNARR_H
#define DYNARR_H

#include "../lexer/token.h"
#include <stdlib.h>

typedef struct lexeme_dynarr {
    unsigned int size;
    unsigned int count;
    struct lexeme* token_arr;
} lexeme_dynarr;


void dynarr_construct(struct lexeme_dynarr* parser_dynarr);
void dynarr_add(struct lexeme_dynarr* parser_dynarr, struct lexeme token_el);

#endif