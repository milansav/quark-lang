#include <stdio.h>
#include <malloc.h>
#include "dynarr/dynarr.h"
#include "Lexer/lexer.h"

int main(int argc, char *argv[])
{
    FILE *fp;
    fp = fopen(argv[1], "r");
    int start = ftell(fp);
    fseek(fp, 0, SEEK_END);
    int end = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    printf("Size of the file %dbytes\n", (end-start));
    char* code = malloc(end-start);
    fread(code, 1, end-start, fp);
    printf("%s", code);

    struct dynarr *arr = lexify(code);

    //printf("%d\n", arr->size);

    free(code);
    return 0;
}