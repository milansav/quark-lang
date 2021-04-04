#ifndef PARSER_H
#define PARSER_H

#include "../lexer/lexer.h"
#include "../lexer/token.h"
#include "../dynarr/dynarr.h"
#include "../utils/debug.h"
#include <string.h>

#include <stdio.h>

typedef struct node
{
	
} node;

lexeme* lexeme_curr();
lexeme* lexeme_peek();
void lexeme_next();
bool lexeme_is_next();

lexeme* lexemes_array;

void parser_construct(lexeme_dynarr* darr);
void parser_deconstruct();

typedef struct node_statement_list
{
	int size;
	int count;
	node* nodes;
} node_statement_list;

void node_statement_list_construct(node_statement_list* list);
void node_statement_list_add(node_statement_list* list, node* item);
void node_statement_list_remove(node_statement_list* list);

typedef struct syntax_tree
{

} syntax_tree;

node_statement_list* current_scope;

syntax_tree* parse_code();

#endif
