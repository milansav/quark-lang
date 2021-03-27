#include <stdio.h>
#include <malloc.h>
#include "dynarr/dynarr.h"
#include "parser/parser.h"
#include "lexer/lexer.h"
#include "utils/debug.h"
#include "utils/language.h"

const char* type_keyword[] = 
{"IDENTIFIER",
"KEYWORD",
"STRING_LITERAL",
"NUMBER_LITERAL",
"CHAR_LITERAL",
"OPERATOR", 
"SEMICOLON", 
"COMMA", 
"DOT", 
"OPEN_BRACKET", 
"CLOSE_BRACKET", 
"OPEN_CURLY", 
"CLOSE_CURLY"};

int main(int argc, char *argv[])
{
    //Changing language settings
    g_debug_mode += OUTPUT_PARSER;
    g_debug_mode += OUTPUT_ALL;
    language_current_mode = LANGUAGE_MODE_COMPILED;
    //End of settings

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
            printf(COLOR_YELLOW "Type:" COLOR_RESET "%s." COLOR_YELLOW "Label:" COLOR_RESET "%s\n", type_keyword[arr->token_arr[i].type], arr->token_arr[i].label);
        }
    }

    syntax_tree* tree = parse_code(arr);

    lexeme_dynarr_remove(arr);
    free(code);
    return 0;
}
