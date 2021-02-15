#ifndef NODE_H
#define NODE_H

typedef struct variable_node variable_node;
typedef struct constant_node constant_node;
typedef struct bin_op_node bin_op_node;
typedef struct statement_node statement_node;
typedef struct function_node function_node;

enum node_type{
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
typedef struct program_node{
    struct nodearr* body;
    struct nodearr* head;
} program_node;

typedef struct statement_sequence_node{
    int size;
    struct nodearr* nodes;
} statement_sequence_node;

typedef struct statement_node{
    int type;
    union node {
        struct function_node* func;
        struct variable_node* var;
        struct constant_node* con;
        struct condition_node* cond;
        struct loop_node* loop;
        struct return_node* ret;
        struct assign_node* assign;
        struct branch_node* branch;
        struct bin_op_node* bin_op;
        struct no_op_node* no_op;
    } node;
} statement_node;

typedef struct function_node{
    char* name;
    struct statement_sequence_node* body;
    struct variable_node* head;
} function_node;

typedef struct variable_node{
    char* name;
    int value;
} variable_node;

typedef struct constant_node{
    int value;
} constant_node;

typedef struct condition_node{
    struct bin_op_node* op;
    void* condition_a;
    void* condition_b;
} condition_node;

typedef struct loop_node{
    struct condition_node* condition;
    struct statement_sequence_node* body;
} loop_node;

typedef struct return_node{
    void* argument;
} return_node;

typedef struct assign_node{
    void* head;
    void* body;
} assign_node;

typedef struct branch_node {
    struct condition_node* condition;
    struct statement_sequence_node* if_body;
    struct statement_sequence_node* else_body;
} branch_node;

typedef struct bin_op_node{
    int op;
    void* head;
    void* body;
} bin_op_node;

typedef struct no_op_node{
    void* head;
} no_op_node;

#endif