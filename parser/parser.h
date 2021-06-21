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
	uint32 type;
	union data
	{
		/* data */
	};
	
} node;

typedef struct node_statement_list
{
	int size;
	int count;
	node* nodes;
} node_statement_list;

lexeme* lexeme_curr(void);
lexeme* lexeme_peek(void);
void lexeme_next(void);
bool lexeme_is_next(void);

void parser_construct(lexeme_dynarr* darr);
void parser_deconstruct(void);

void node_statement_list_construct(node_statement_list* list);
void node_statement_list_add(node_statement_list* list, node* item);
void node_statement_list_remove(node_statement_list* list);

void* parse_code(void);

void nextsym(void);
int accept(Symbol s);
int expect(Symbol s);
void factor(void);
void term(void);
void expression(void);
void condition(void);
void block();
int statement(void);
void program(void);

#endif
