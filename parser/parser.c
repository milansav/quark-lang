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

syntax_tree* parse_code(lexeme_dynarr* darr)
{
	lexemes_array = darr->token_arr;
	syntax_tree* st = malloc(sizeof(syntax_tree));
	while(lexeme_is_next())
	{
		if(g_debug_mode & OUTPUT_PARSER)
		{
			printf("%s\n", lexeme_curr()->label);
		}
		lexeme_next();
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