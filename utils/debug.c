#include "debug.h"

void g_error(char * msg)
{
    printf(COLOR_RED "%s" COLOR_RESET, msg);
}

void g_errorln(char * msg)
{
    printf(COLOR_RED "%s\n" COLOR_RESET, msg);
}

void g_log(char * msg)
{
    printf(COLOR_GREEN "%s" COLOR_RESET, msg);
}

void g_logln(char * msg)
{
    printf(COLOR_GREEN "%s\n" COLOR_RESET, msg);
}
