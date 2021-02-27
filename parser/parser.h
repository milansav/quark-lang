#ifndef PARSER_H
#define PARSER_H

#include "node.h"
#include "sttmntarr.h"
#include "../lexer/token.h"
#include "../dynarr/dynarr.h"
#include "../utils/vartable.h"
#include "../utils/debug.h"
#include <stdio.h>
#include <string.h>

struct dynarr* parser_dynarr;
struct token* parser_token_ptr;

struct token* parser_get_current_token();
struct token* parser_get_peek_token();
void next_n();

struct table* parser_variables_table;

typedef struct program{
    struct sttmntarr* body;
    struct sttmntarr* head;
} program;


typedef struct AST {
    struct program* body;
} AST;

struct AST* parser_parse_code(struct dynarr* _darr);

//Different statement types
void parse_keyword();
void parse_declaration();
void parse_initialization();
void parse_definition();
void parse_return();
void parse_condition();
void parse_loop();
void parse_expression();

struct AST* parser_tree;
struct sttmntarr* parser_current_scope;

#endif