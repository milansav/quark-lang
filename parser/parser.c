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

}

syntax_tree* parse_code(lexeme_dynarr* darr)
{
	lexemes_array = darr->token_arr;
	syntax_tree* syntax_tree = malloc(sizeof(syntax_tree));

	current_scope = &syntax_tree->program.nodes;

	while(lexeme_is_next())
	{
		if(g_debug_mode & OUTPUT_PARSER && g_debug_mode & OUTPUT_TEST)
		{
			printf("%s\n", lexeme_curr()->label);
		}

		switch(lexeme_curr()->type)
		{
			case KEYWORD:
				node_statement_list_add(current_scope, parse_keyword());
			break;

		}

		lexeme_next();
	}
}

node* parse_keyword()
{
	if(!strcmp("if", lexeme_curr()->label))
	{

	}
}

node_variable* node_create_declaration()
{
	node_variable* variable = malloc(sizeof(node_variable));

	return variable;
}

node_branch* node_create_branch()
{
	node_branch* branch = malloc(sizeof(node_branch));

	return branch;
}

node_constant* node_create_constant()
{
	node_constant* constant = malloc(sizeof(node_constant));

	return constant;
}

node_return* node_create_return()
{
	node_return* _return = malloc(sizeof(node_return));

	return _return;
}