#ifndef VARTABLE_H
#define VARTABLE_H

#include "../parser/node.h"

typedef struct table {
    int size;
    int count;
    struct variable* variables;
} table;

void construct_table(struct table* tbl);
void add(struct variable* var, struct table* tbl);
struct variable* get(char* name, struct table* tbl);

#endif