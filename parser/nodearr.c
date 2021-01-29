#include "nodearr.h"
#include <stdlib.h>

void n_arr_construct(struct nodearr* arr)
{
    arr->count = 0;
    arr->size = 8;
    arr->statement_arr = malloc(sizeof(statement_node) * arr->size);
}

void n_add_token(struct nodearr* arr, struct statement_node node)
{
    if(arr->count >= arr->size)
    {
        arr->size *= 2;
        arr->statement_arr = realloc(arr->statement_arr, arr->size * sizeof(statement_node));
    }
    arr->statement_arr[arr->count] = node;
    arr->count++;
}