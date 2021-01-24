#include "parser.h"

AST* parse(struct dynarr* darr)
{
    for(uint i = 0; i < darr->count; i++)
    {
        struct token _t = darr->token_arr[i];
        switch(_t.type)
        {
            case KEYWORD:
        }
    }
}