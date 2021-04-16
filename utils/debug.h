#ifndef DEBUG_H
#define DEBUG_H

#include <stdio.h>

typedef unsigned int uint32;
typedef unsigned char ubyte;

extern uint32 g_debug_mode;

#define OUTPUT_DEBUG            0   //Warnings, errors etc.. from parser, compiler etc..
#define NO_OUTPUT               1   //Output absolutely nothing
#define OUTPUT_ALL              2   //Output everything
#define OUTPUT_COMPILER         4   //Output from compiler
#define OUTPUT_LEXER            8   //Output from lexer
#define OUTPUT_PARSER           16  //Output from parser
#define OUTPUT_PREPROCESSOR     32  //Output from preprocessor
#define OUTPUT_LINKER           64  //Output from linker
#define OUTPUT_TEST             0x8000  //Testing purposes

#define COLOR_RED     "\e[31m"
#define COLOR_GREEN   "\e[32m"
#define COLOR_YELLOW  "\e[33m"
#define COLOR_BLUE    "\e[34m"
#define COLOR_MAGENTA "\e[35m"
#define COLOR_CYAN    "\e[36m"
#define COLOR_RESET   "\e[0m"

void g_error(const char **msg);
void g_errorln(const char **msg);
void g_log(const char **msg);
void g_logln(const char **msg);

#endif
