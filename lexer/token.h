#ifndef TOKEN_H
#define TOKEN_H

typedef struct lexeme{
    char* label;
    int type;
} lexeme;

enum lexeme_type{
    IDENTIFIER,
    KEYWORD,
    STRING_LITERAL,
    NUMBER_LITERAL,
    CHAR_LITERAL,
    OPERATOR,
    SEMICOLON,
    COMMA,
    DOT,
    OPEN_BRACKET,
    CLOSE_BRACKET,
    OPEN_CURLY,
    CLOSE_CURLY
};
#endif
