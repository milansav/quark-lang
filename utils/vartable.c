#include "vartable.h"
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
    printf("Adding to vartable\n");
    for(int i = 0; i < tbl->count; i++)
    {
        if(!strcmp(tbl->variables[i].label, var->label))
        {
            printf("Warning!! Conflicting variable names %s", var->label); //Temp. solution
        }
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
