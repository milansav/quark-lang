#ifndef VARTABLE_H
#define VARTABLE_H

#include "../parser/node.h"

typedef struct table {
    unsigned int size;
    unsigned int count;
    struct variable* variables;
} table;

void vartable_construct(struct table* tbl);
void vartable_add(struct variable* var, struct table* tbl);
struct variable* vartable_get(char* name, struct table* tbl);

#endif