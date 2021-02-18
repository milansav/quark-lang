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
    int value;
    char* label;
} variable;

typedef struct assign{
    int leftType;
    union left
    {
        struct variable* _var;
        struct constant* _const;
    };

    int rightType;
    union right
    {
        struct variable* _var;
        struct constant* _const;
    };
} assign;

typedef struct statement{
    int type;
    union node
    {
        struct constant* _const;
        struct variable* _var;
    };
} statement;


#endif