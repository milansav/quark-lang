#ifndef STRING_H
#define STRING_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "debug.h"

#define DEFAULT_STRING_SIZE 32
#define DEFAULT_SCALE_SIZE 16

typedef struct string
{
  uint32 alloc_size;
  uint32 length;
  char* content;
} string;

void string_construct(string* string_to_make);
void string_construct_v(string* string_to_make, char* value);
void string_deconstruct(string* string_to_remove);
void string_append(string* string_to_append_to, char* value);
char* string_get_value(string* input_string);

#endif
