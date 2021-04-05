#ifndef TOKEN_H
#define TOKEN_H

typedef enum {
    ident, number,
    strnliteral, charliteral,
    lparen, rparen,
    times, slash,
    plus, minus,
    eql, neq,
    lss, leq,
    gtr, geq,
    funcsym, semicolon,
    ifsym, whilesym,
    constsym, varsym,
    comma, dot,
    begin, end,
    defsym, structsym,
    returnsym, elsesym,
    assign
} Symbol;

typedef struct lexeme{
    char* label;
    Symbol type;
} lexeme;


#endif
