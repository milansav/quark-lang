#ifndef NODE_H
#define NODE_H

enum statement_type
{
    FUNCTION,
    VARIABLE,
    CONSTANT,
    CONDITION,
    LOOP,
    RETURN,
    ASSIGN,
    BRANCH,
    BIN_OP,
    NO_OP
};

typedef struct constant{
    int value;
} constant;

typedef struct variable{
    char* label;
    int value;
} variable;

typedef struct statement{
    int type;

} statement;

#endif