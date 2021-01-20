#ifndef TOKEN_H
#define TOKEN_H

typedef struct token{
    char* label;
    int type;
} token;

enum type{
    IDENTIFIER,
    KEYWORD,
    STRING_LITERAL,
    NUMBER_LITERAL,
    CHAR_LITERAL,
    OPERATOR,
    SEMICOLON,
    COMMA,
    OPEN_BRACKET,
    CLOSE_BRACKET,
    OPEN_CURLY,
    CLOSE_CURLY
};

#endif