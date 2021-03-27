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
    //g_debug_mode += OUTPUT_ALL;
    language_current_mode = LANGUAGE_MODE_COMPILED;
    //End of settings

    FILE *fp;
    fp = fopen(argv[1], "r");
    unsigned int start = ftell(fp);
    fseek(fp, 0, SEEK_END);
    unsigned int end = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    
    if(g_debug_mode & OUTPUT_ALL)
    {
    printf("Size of the file %dbytes\n", (end-start));
    }

    char* code = malloc(end-start);
    fread(code, 1, end-start, fp);
    printf("%s\n", code);

    lexeme_dynarr *arr = lexer_lexify(code);

    if(g_debug_mode & OUTPUT_LEXER || g_debug_mode & OUTPUT_ALL)
    {
        for(unsigned int i = 0; i < arr->count; i++)
        {
            printf("Type: %s. Label: %s\n", type_keyword[arr->token_arr[i].type], arr->token_arr[i].label);
        }
    }

    syntax_tree* tree = parse_code(arr);

    free(code);
    return 0;
}
