#include "dynarr.h"

uint32 g_debug_mode;

void lexeme_dynarr_construct(lexeme_dynarr* dynarr)
{
    dynarr->count = 0;
    dynarr->size = 8;
    dynarr->token_arr = malloc(sizeof(lexeme) * dynarr->size);
}

void lexeme_dynarr_add(lexeme_dynarr* dynarr, lexeme token_el)
{
    if(dynarr->count >= dynarr->size)
    {
        dynarr->size *= 2;
        dynarr->token_arr = realloc(dynarr->token_arr, dynarr->size * sizeof(lexeme));
    }
    dynarr->token_arr[dynarr->count] = token_el;
    dynarr->count++;
}

void lexeme_dynarr_remove(lexeme_dynarr* dynarr)
{
    uint32 bytes_removed = 0;
    
    for(uint32 i = 0; i < dynarr->count; i++)
    {
        char* current = dynarr->token_arr[i].label;
        bytes_removed += strlen(current);
        memset(current, 0, strlen(current));
    }

    bytes_removed += strlen((char*)dynarr->token_arr);
    memset(dynarr->token_arr, 0, strlen((char*)dynarr->token_arr));
    free(dynarr->token_arr);

    if(g_debug_mode & OUTPUT_LEXER || g_debug_mode & OUTPUT_ALL)
    printf(COLOR_YELLOW "Lexeme array removed\nBytes cleared:" COLOR_RESET" %db\n", bytes_removed);
}