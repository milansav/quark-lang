#ifndef NODEARR_H
#define NODEARR_h

#include "node.h"

typedef struct nodearr{
    int size;
    int count;
    struct statement_node* statement_arr;
} nodearr;

void arr_construct(struct nodearr* narr);
void add_token(struct nodearr* narr, struct statement_node node);

#endif