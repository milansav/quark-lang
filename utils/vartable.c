#include "vartable.h"
#include "../utils/debug.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void construct_table(struct table* tbl)
{
    tbl->count = 0;
    tbl->size = 8;
    tbl->variables = malloc(tbl->size*sizeof(variable));
}

void add(struct variable* var, struct table* tbl)
{

    if(get(var->label, tbl) != NULL)
    {
        if(debug_mode == 0 || debug_mode & OUTPUT_ALL || debug_mode & OUTPUT_PARSER)
        {
        printf(COLOR_YELLOW "Warning!!" COLOR_RESET " Variable with this name " COLOR_YELLOW "(\"%s\")" COLOR_RESET " already declared!\n", var->label);
        }
    }

    if(debug_mode & OUTPUT_PARSER || debug_mode & OUTPUT_ALL)
    {
    printf(COLOR_CYAN "Adding to vartable\n" COLOR_RESET);
    }
    
	if(tbl->count >= tbl->size)
	{
		tbl->size *= 2;
		tbl->variables = realloc(tbl->variables, tbl->size*sizeof(variable));
	}	
	tbl->variables[tbl->count] = *var;
	tbl->count++;
}

struct variable* get(char* name, struct table* tbl)
{
	for(int i = 0; i < tbl->count; i++)
    {
        if(!strcmp(tbl->variables[i].label, name))
        {
            return &tbl->variables[i];
        }
    }
}
