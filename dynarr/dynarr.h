#ifndef DYNARR_H
#define DYNARR_H

#include "../lexer/token.h"
#include "../utils/debug.h"
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

extern uint32 g_debug_mode;

typedef struct lexeme_dynarr {
    unsigned int size;
    unsigned int count;
    lexeme* token_arr;
} lexeme_dynarr;


void lexeme_dynarr_construct(lexeme_dynarr* dynarr);
void lexeme_dynarr_add(lexeme_dynarr* dynarr, lexeme token_el);
void lexeme_dynarr_remove(lexeme_dynarr* dynarr);

#endif