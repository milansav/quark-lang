#ifndef NODE_H
#define NODE_H

typedef struct variable_node variable_node;

enum Type{
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

typedef struct statement_node{
    int size;
    struct statement_node** nodes;
} statement_node;

typedef struct function_node{
    char* name;
    struct statement_node* body;
    struct variable_node** head;
} function_node;

typedef struct variable_node{
    char* name;
    int value;
} variable_node;

typedef struct constant_node{
    int value;
} constant_node;

typedef struct condition_node{
    struct bin_op_node op;
    void* condition_a;
    void* condition_b;
} condition_node;

typedef struct loop_node{
    struct condition_node condition;
    struct statement_node body;
} loop_node;

typedef struct return_node{
    void* argument;
} return_node;

typedef struct assign_node{
    void* head;
    void* body;
} assign_node;

typedef struct branch_node {
    struct condition_node condition;
    struct statement_node* if_body;
    struct statement_node* else_body;
} branch_node;

typedef struct bin_op_node{

} bin_op_node;

typedef struct no_op_node{

} no_op_node;

#endif