#ifndef PARSER_H
#define PARSER_H

#include "parser.h"
#include "tree.h"
#include "node.h"
#include "../dynarr/dynarr.h"
#include "../lexer/token.h"

struct AST* parse(struct dynarr* darr);

#endif