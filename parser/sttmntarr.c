#include "sttmntarr.h"
#include <stdlib.h>

void sttmntarr_construct(struct sttmntarr* sarr)
{
    sarr->count = 0;
    sarr->size = 4;
    sarr->statement_arr = malloc(sizeof(statement) * sarr->size);
}

void sttmntarr_add(struct sttmntarr* sarr, struct statement el)
{
    if(sarr->count >= sarr->size)
    {
        sarr->size *= 2;
        sarr->statement_arr = realloc(sarr->statement_arr, sarr->size * sizeof(statement));
    }
    sarr->statement_arr[sarr->count] = el;
    sarr->count++;
}