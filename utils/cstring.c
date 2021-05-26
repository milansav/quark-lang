#include "cstring.h"

void string_construct(string* string_to_make)
{
  if(string_to_make)
  {
    string_to_make->alloc_size = DEFAULT_STRING_SIZE;
    string_to_make->length = 0;
    string_to_make->content = malloc(string_to_make->alloc_size);
  }
  else
  {
    g_errorln(__FILE__ " : string_to_make cannot be NULL");
  }
}

void string_construct_v(string* string_to_make, char* value)
{
  if(string_to_make)
  {
    if(!value)
    {
      g_errorln(__FILE__ " : value cannot be NULL");
    }

    string_to_make->alloc_size = strlen(value) + DEFAULT_SCALE_SIZE;
    string_to_make->length = strlen(value);
    string_to_make->content = malloc(string_to_make->alloc_size);
    strcpy(string_to_make->content, value);
  }
  else
  {
    g_errorln(__FILE__ " : string_to_make cannot be NULL");
  }
}

void string_deconstruct(string* string_to_remove)
{
  if(!string_to_remove)
  {
    g_errorln(__FILE__ " : string_to_remove cannot be NULL");
    return;
  }

  free(string_to_remove->content);

  free(string_to_remove);
}

void string_append(string* string_to_append_to, char* value)
{

  if(!string_to_append_to)
  {
    g_errorln(__FILE__ " : string_to_append_to cannot be NULL");
    return;
  }

  uint32 free_space = string_to_append_to->alloc_size -
                      string_to_append_to->length;

  if(strlen(value) >= free_space)
  {
    uint32 required_size = string_to_append_to->alloc_size +
    (strlen(value) - free_space) + DEFAULT_SCALE_SIZE;

    string_to_append_to->alloc_size = required_size;

    string_to_append_to->content = realloc(string_to_append_to->content, required_size);
  }

  strcat(string_to_append_to->content, value);
  string_to_append_to->length += strlen(value);
}

char* string_get_value(string* input_string)
{
  if(!input_string)
  {
    g_errorln(__FILE__ " : input_string cannot be NULL");
    return "NULL";
  }

  if(!input_string->content)
  {
    g_errorln(__FILE__ " : input_string content cannot be NULL");
    return "NULL";
  }

  return input_string->content;

}
