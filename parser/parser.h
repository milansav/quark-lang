#ifndef PARSER_H
#define PARSER_H

#include "parser.h"
#include "tree.h"
#include "node.h"
#include "../dynarr/dynarr.h"
#include "../lexer/token.h"
#include <string.h>

struct dynarr* darr;
struct AST* tree;

struct statement_sequence_node* current_scope;

void* ptr;

struct token curr();
struct token peek();
void next();

struct AST* parse_code(struct dynarr* _darr);

void parse();

void keyword();
void function();
void branch();
void _return();
void declare();

#endif