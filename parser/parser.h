#ifndef PARSER_H
#define PARSER_H

#include "node.h"
#include "sttmntarr.h"
#include "../lexer/token.h"
#include "../dynarr/dynarr.h"
#include "../utils/vartable.h"

struct dynarr* darr;
struct token* t_ptr;

struct token curr_n();
struct token peek_n();
void next_n();

struct table vars;

int debug_mode;

typedef struct program{
    struct sttmntarr* body;
    struct sttmntarr* head;
} program;


typedef struct AST {
    struct program* body;
} AST;

struct AST* parse_code(struct dynarr* _darr, int _debug_mode);

//Different statement types
void keyword();
void declaration();
void initialization();
void definition();
void _return();
void conditional();
void loop();
void expression();

struct AST* tree;
struct sttmntarr* current_scope;

#endif