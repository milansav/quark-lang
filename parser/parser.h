#ifndef PARSER_H
#define PARSER_H

#include "parser.h"
#include "tree.h"
#include "node.h"
#include "../dynarr/dynarr.h"
#include "../lexer/token.h"
#include <string.h>

struct dynarr* darr;
uint currentToken;

struct AST* parse(struct dynarr* _darr);
void keyword();
void function();
void branch();
void _return();
void declare();

#endif