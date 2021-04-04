#ifndef TOKEN_H
#define TOKEN_H

typedef struct lexeme{
    char* label;
    int type;
} lexeme;

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
    returnsym, elsesym
} Symbol;

#endif
