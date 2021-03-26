#include "parser.h"

token* curr_n()
{
	if(is_next) return lexemes_array;
	else return NULL;
}

token* peek_n()
{
	if(is_next()) return (lexemes_array+1);
	else return NULL;
}

void next_n()
{
	lexemes_array++;
}

bool is_next()
{
	return (lexemes_array+1)->label;
}

syntax_tree* parse_code(dynarr* darr)
{
	lexemes_array = darr->token_arr;
	syntax_tree* st = malloc(sizeof(syntax_tree));
	while(is_next())
	{
		if(debug_mode & OUTPUT_PARSER)
		{
			printf("%s\n", curr_n()->label);
		}
		next_n();
	}
}

node_variable* parse_declaration()
{
	node_variable* variable = malloc(sizeof(node_variable));
}

node_branch* parse_branch()
{
	node_branch* branch = malloc(sizeof(node_branch));
}

node_constant* parse_constant()
{
	node_constant* constant = malloc(sizeof(node_constant));
}

node_return* parse_return()
{
	node_return* _return = malloc(sizeof(node_return));
}