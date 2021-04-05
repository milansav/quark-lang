#include "debug.h"

void g_error(const char msg[])
{
    printf(COLOR_RED "%s\n" COLOR_RESET, msg);
}

void g_log(const char msg[])
{
    printf(COLOR_GREEN "%s\n" COLOR_RESET, msg);
}