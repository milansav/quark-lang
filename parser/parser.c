#include "parser.h"

const char* type_keyword[];

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

void parser_construct(lexeme_dynarr* darr)
{
	lexemes_array = darr->token_arr;
	sym = lexemes_array->type;
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
		g_error(__FILE__ ": Node statement list: Input item can't be null\n");
		return;
	}

	if(!list)
	{
		g_error(__FILE__": Node statement list: Input list can't be null\n");
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
		
	}
}

void* parse_code(void)
{
	/*lexeme* start = lexemes_array;
	while(lexemes_array->label)
	{
		printf("%s %s\n", type_keyword[sym], lexemes_array->label);
		nextsym();
	}
	lexemes_array = start;
	sym = lexemes_array->type;*/
	program();
}

void nextsym()
{
	lexemes_array++;
	sym = lexemes_array->type;
}

int accept(Symbol s)
{
	if(sym == s)
	{
		g_log(__FILE__ ": accept: accepted");
		printf("Type: %s Label: %s\n", type_keyword[sym], lexemes_array->label);
		nextsym();
		return 1;
	}
	return 0;
}

int expect(Symbol s)
{
	if(accept(s)) return 1;
	g_error(__FILE__ ": expect: unexpected symbol");
	printf("Type: %s Label: %s\n", type_keyword[sym], lexemes_array->label);
	return 0;
}

void factor()
{
	g_log(__FILE__ ": factor");
	printf("Type: %s Label: %s\n", type_keyword[sym], lexemes_array->label);
	if(accept(ident))
	{
		;
	}
	else if(accept(number))
	{
		;
	}
	else if(accept(lparen))
	{
		expression();
		expect(rparen);
	}
	else
	{
		g_error(__FILE__ ": factor: syntax error\n");
		printf("Type: %s Label: %s\n", type_keyword[sym], lexemes_array->label);
		nextsym();
	}
}

void term()
{
	g_log(__FILE__ ": term");
	printf("Type: %s Label: %s\n", type_keyword[sym], lexemes_array->label);
	factor();
	while(sym == times || sym == slash)
	{
		nextsym();
		factor();
	}
}

void expression()
{
	g_log(__FILE__ ": expression");
	printf("Type: %s Label: %s\n", type_keyword[sym], lexemes_array->label);
	if(sym == plus || sym == minus) nextsym();
	term();
	while(sym == plus || sym == minus)
	{
		nextsym();
		term();
	}
}

void condition()
{
	g_log(__FILE__ ": condition");
	printf("Type: %s Label: %s\n", type_keyword[sym], lexemes_array->label);
	bool equal = sym == eql;
	bool nequal = sym == neq;
	bool less = sym == lss;
	bool lequal = sym == leq;
	bool greater = sym == gtr;
	bool gequal = sym == geq;
	expression();
	if(equal || nequal || less || lequal || greater || gequal)
	{
		nextsym();
		expression();
	}
	else
	{
		g_error(__FILE__ ": condition: invalid operator\n");
	}
}

void statement()
{
	g_log(__FILE__ ": statement");
	printf("Type: %s Label: %s\n", type_keyword[sym], lexemes_array->label);
	if(accept(ident))
	{
		if(accept(assign))
		{
			expression();
		}
		else if(accept(lparen))
		{
			do
			{
				expect(ident);
			} while (accept(comma));
			expect(rparen);
		}
	}
	else if(accept(varsym))
	{
		do
		{
			expect(ident);
		} while (accept(comma));
		expect(semicolon);
	}
	else if(accept(ifsym))
	{
		condition();
		expect(begin);
		statement();
	}
	else if(accept(whilesym))
	{
		condition();
		expect(begin);
		statement();
	}
	else if(accept(funcsym))
	{
		expect(ident);
		expect(lparen);
		do
		{
			expect(varsym);
			expect(ident);
		} while (accept(comma));
		expect(rparen);
		statement();
	}
	else if(accept(begin))
	{
		do
		{
			statement();
		} while (accept(semicolon));
		expect(end);
	}
	else
	{
		g_error(__FILE__ ": statement: syntax error");
		printf("Type: %s Label: %s\n", type_keyword[sym], lexemes_array->label);
		nextsym();
	}
}

//TODO: update grammar
void block()
{
	g_log(__FILE__ ": block");
	printf("Type: %s Label: %s\n", type_keyword[sym], lexemes_array->label);
	if(accept(constsym))
	{
		do {
			expect(ident);
			expect(assign);
			expect(number);
		} while(accept(comma));
		expect(semicolon);
	}
	if(accept(varsym))
	{
		do
		{
			expect(ident);
		} while (accept(comma));
		expect(semicolon);
	}
	statement();
}

void program()
{
	g_log(__FILE__ ": program");
	printf("Type: %s Label: %s\n", type_keyword[sym], lexemes_array->label);
	block();
}