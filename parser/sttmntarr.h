#ifndef STTMNTARR_H
#define STTMNTARR_H

#include "node.h"

typedef struct sttmntarr {
    int size;
    int count;
    struct statement* statement_arr;
} sttmntarr ;

void construct(struct sttmntarr* sarr);
void add_statement(struct sttmntarr* sarr, struct statement el);

#endif