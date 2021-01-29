#ifndef NODEARR_H
#define NODEARR_h

#include "node.h"

typedef struct nodearr{
    int size;
    int count;
    struct statement_node* statement_arr;
} nodearr;

void n_arr_construct(struct nodearr* narr);
void n_add_token(struct nodearr* narr, struct statement_node node);

#endif