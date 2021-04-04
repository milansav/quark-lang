#include "parser.h"

lexeme* lexeme_curr()
{
	if(lexeme_is_next) return lexemes_array;
	else return NULL;
}

lexeme* lexeme_peek()
{
	if(lexeme_is_next()) return (lexemes_array+1);
	else return NULL;
}

void lexeme_next()
{
	lexemes_array++;
}

bool lexeme_is_next()
{
	return (lexemes_array+1)->label;
}

void node_statement_list_construct(node_statement_list* list)
{
	if(list)
	{
		list->count = 0;
		list->size = 8;
		list->nodes = malloc(sizeof(node) * list->size);
	}
}

void node_statement_list_add(node_statement_list* list, node* item)
{

	if(!item)
	{
		printf(COLOR_RED "Node statement list: Input item can't be null\n" COLOR_RESET);
		return;
	}

	if(!list)
	{
		printf(COLOR_RED "Node statement list: Input list can't be null\n" COLOR_RESET);
		return;
	}

	if(list->count >= list->size)
	{
		list->size += 4;
		list->nodes = realloc(list->nodes, sizeof(node) * list->size);
		list->nodes[list->count] = *item;
		list->count++;
	}
}

void node_statement_list_remove(node_statement_list* list)
{
	uint32 bytes_removed = 0;

	for(uint32 i = 0; i < list->count; i++)
	{
		switch(list->nodes[i].type)
		{

		}
	}
}

syntax_tree* parse_code(lexeme_dynarr* darr)
{
	lexemes_array = darr->token_arr;
	syntax_tree* syntax_tree = malloc(sizeof(syntax_tree));

	current_scope = syntax_tree->functions;

	node_statement_list_construct(syntax_tree->functions);



	return syntax_tree;
}