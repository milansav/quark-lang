#include <stdio.h>
#include <stdlib.h>
#include "dynarr/dynarr.h"
#include "parser/parser.h"
#include "lexer/lexer.h"
#include "utils/debug.h"
#include "utils/keywords.h"

string* main_type_keywords;

int main(int argc, char *argv[])
{
    //Changing language settings
    uint32 g_debug_mode;
    g_debug_mode += OUTPUT_PARSER;
    g_debug_mode += OUTPUT_ALL;
    //End of settings

    main_type_keywords = type_keywords_get();

    FILE *fp;

    if(!argv[1])
    {
        printf(COLOR_RED "Input file can't be null!\n" COLOR_RESET);
        return 2;
    }

    fp = fopen(argv[1], "r");
    uint32 start = ftell(fp);

    fseek(fp, 0, SEEK_END);
    uint32 end = ftell(fp);

    fseek(fp, 0, SEEK_SET);

    uint32 size = (end-start);

    if(g_debug_mode & OUTPUT_ALL)
    {
        printf("Size of the file %dbytes\n", size);
    }

    char* code = malloc(size);
    fread(code, 1, size, fp);
    printf("%s\n", code);

    lexeme_dynarr *arr = lexer_lexify(code);

    if(g_debug_mode & OUTPUT_LEXER || g_debug_mode & OUTPUT_ALL)
    {
        for(uint32 i = 0; i < arr->count; i++)
        {
            printf(COLOR_YELLOW "Type:" COLOR_RESET "%s." COLOR_YELLOW "Label:" COLOR_RESET "%s\n", string_get_value(&main_type_keywords[arr->token_arr[i].type]), arr->token_arr[i].label);
        }
    }

    parser_construct(arr);
    void* tree = parse_code();

    lexeme_dynarr_remove(arr);
    free(code);
    return 0;
}
