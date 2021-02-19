#ifndef DEBUG_H
#define DEBUG_H

int debug_mode;

#define OUTPUT_DEBUG            0   //Warnings, errors etc.. from parser, compiler etc..
#define NO_OUTPUT               1   //Output absolutely nothing
#define OUTPUT_ALL              2   //Output everything
#define OUTPUT_COMPILER         4   //Output from compiler
#define OUTPUT_LEXER            8   //Output from lexer
#define OUTPUT_PARSER           16  //Output from parser
#define OUTPUT_PREPROCESSOR     32  //Output from preprocessor
#define OUTPUT_LINKER           64  //Output from linker

#endif