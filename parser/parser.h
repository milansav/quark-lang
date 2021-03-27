#ifndef PARSER_H
#define PARSER_H

#include "../lexer/lexer.h"
#include "../lexer/token.h"
#include "../dynarr/dynarr.h"
#include "../utils/debug.h"
#include <string.h>

#include <stdio.h>

typedef struct node node;

lexeme* lexeme_curr();
lexeme* lexeme_peek();
void lexeme_next();
bool lexeme_is_next();

lexeme* lexemes_array;

typedef struct node_statement_list
{
	int size;
	int count;
	node* nodes;
} node_statement_list;

void node_statement_list_construct(node_statement_list* list);
void node_statement_list_add(node_statement_list* list, node* item);
void node_statement_list_remove(node_statement_list* list);

typedef struct node_program
{
    node_statement_list nodes;
} node_program;

typedef struct node_variable
{
    char* name;
    int value;
} node_variable;
typedef struct node_constant
{
    int value;
} node_constant;

typedef struct node_return
{
    int type;
    union
    {
        node_variable variable;
        node_constant constant;
    };
} node_return;

typedef struct node_branch
{
	node_statement_list condition_true;
	node_statement_list condition_false;
} node_branch;

typedef struct node 
{
	int type;
	union
	{
		node_statement_list statement_list_node;
		node_variable variable_node;
		node_constant constant_node;
		node_return return_node;
		node_branch branch_node;
	};
} node;

typedef struct syntax_tree
{
    node_program program;
} syntax_tree;

node_statement_list* current_scope;

syntax_tree* parse_code(lexeme_dynarr* darr);

node* parse_keyword();

node_variable* node_create_declaration();
node_branch* node_create_branch();
node_constant* node_create_constant();
node_return* node_create_return();

#endif
